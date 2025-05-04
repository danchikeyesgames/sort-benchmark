#ifndef __CALLBACK_HPP__
#define __CALLBACK_HPP__

#include <type_traits>
#include <utility>

namespace cppsort
{

namespace detail
{

constexpr std::size_t cMaxInPlaceCallbackByteSize = 32*sizeof(char);

template <class T>
struct is_in_place {
    static constexpr bool value = sizeof(T) <= cMaxInPlaceCallbackByteSize;
};

}   // ns: detail


struct callback_storage {
    union cb_obj {
        void* m_heapPointer;
        char  m_memoryInPlace[detail::cMaxInPlaceCallbackByteSize];
    } m_data;

    void (*m_callback_destructor)(callback_storage&);
    void (*m_call)();

    template <typename ... Args>
    void call(Args ... args) {
        if (m_call)
            reinterpret_cast<void(*)(callback_storage&, Args ...)>(m_call)(*this, args ...);
    }

    callback_storage() : m_callback_destructor(nullptr), m_call(nullptr)  {}
    ~callback_storage() {
        if (m_callback_destructor)
            m_callback_destructor(*this);
    };
};


namespace detail
{

template <bool>
struct callback_storage_ops {
    template<class T, typename ... Args>
    static void pack_cb(callback_storage& _cb_storage, T&& _cb) {
        using decay_t = typename std::decay<T>::type;
        _cb_storage.m_data.m_heapPointer = new decay_t(std::forward<T>(_cb));
        _cb_storage.m_callback_destructor = callback_destructor<decay_t>;
        _cb_storage.m_call = reinterpret_cast<void(*)()>(call<decay_t, Args...>);
    }

    template <typename T>
    static void callback_destructor(callback_storage& _cb_storage) {
        delete (reinterpret_cast<T*>(_cb_storage.m_data.m_heapPointer));
    }

    template <typename T, typename ... Args>
    static void call(callback_storage& _cb_storage, Args ... args) {
        T* cb = reinterpret_cast<T*>(_cb_storage.m_data.m_heapPointer);
        (*cb)(args ...);
    }
};

template <>
struct callback_storage_ops<true> {
    template<class T, typename ... Args>
    static void pack_cb(callback_storage& _cb_storage, T&& _cb) {
        using decay_t = typename std::decay<T>::type;
        new (_cb_storage.m_data.m_memoryInPlace) decay_t(std::forward<T>(_cb));
        _cb_storage.m_callback_destructor = callback_destructor<decay_t>;
        _cb_storage.m_call = reinterpret_cast<void(*)()>(call<decay_t, Args...>);
    }

    template <typename T>
    static void callback_destructor(callback_storage& _cb_storage) {
        (reinterpret_cast<T*>(_cb_storage.m_data.m_memoryInPlace))->~T();
    }

    template <typename T, typename ... Args>
    static void call(callback_storage& _cb_storage, Args ... args) {
        T* cb = reinterpret_cast<T*>(_cb_storage.m_data.m_memoryInPlace);
        (*cb)(args ...);
    }
};


}   // ns: detail

template <class T, typename ... Args>
void init_callback_storage(callback_storage& _cb_storage, T&& _cb) {
    detail::callback_storage_ops<detail::is_in_place<T>::value>::template pack_cb<T, Args...>(_cb_storage, std::forward<T>(_cb));
}

}   // ns: cppsort




#endif  // __CALLBACK_HPP__

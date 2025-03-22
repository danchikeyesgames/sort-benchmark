#ifndef __CALLBACK_HPP__
#define __CALLBACK_HPP__

#include <type_traits>
#include <utility>

#include <cstdint>

namespace cpp_algosort_benchmark
{

namespace common
{

constexpr std::size_t cMaxInPlaceCallbackByteSize = 32*sizeof(char);

struct callback_storage {
    union cb_obj {
        void* m_heapPointer;
        char  m_memoryInPlace[cMaxInPlaceCallbackByteSize];
    } m_data;

    void (*m_callback_destructor)(callback_storage&);
    void (*m_call)();

    template <typename ... Args>
    void call(Args ... args) {
        reinterpret_cast<void(*)(callback_storage&, Args ...)>(m_call)(*this, args ...);
    }

    callback_storage() : m_callback_destructor(nullptr) {}
    ~callback_storage() {
        if (m_callback_destructor)
            m_callback_destructor(*this);
    };
};

template <typename T>
struct is_in_place {
    static constexpr bool m_value = sizeof(T) <= cMaxInPlaceCallbackByteSize;
};

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




}

}




#endif  // __CALLBACK_HPP__
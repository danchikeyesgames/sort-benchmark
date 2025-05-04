#ifndef __DEBUG_HPP__ 
#define __DEBUG_HPP__

#include "callback_storage.hpp"

namespace cppsort
{

namespace debug
{

namespace detail
{

class debug_log {

    cppsort::callback_storage m_callback;

    debug_log() = default;
    debug_log(debug_log&&) = default;
    debug_log(debug_log&) = delete;
    debug_log& operator=(debug_log&) = delete;

public:
 
    static debug_log* instance() {
        static debug_log instance_;
        return &instance_;
    }

    template <typename CallBack, typename ... Args>
    void init_callback(CallBack&& cb) {
        cppsort::init_callback_storage<CallBack, const char*, Args...>(m_callback, std::forward<CallBack>(cb));
    }

    template <typename ... Args>
    void call(const char* format, Args ... args) {
        m_callback.call(format, args ...);
    }
};

}   // ns: detail

template <typename CallBack, typename ... Args>
void update_callback(CallBack&& cb) {
    detail::debug_log::instance()->init_callback<CallBack, Args ...>(std::forward<CallBack>(cb));
}

template <typename ... Args>
void call(Args ... args) {
    detail::debug_log::instance()->call(args ...);
}

}   // ns: debug

}   // ns: cppsort

#endif  // __DEBUG_HPP__

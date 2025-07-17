#ifndef __CORE_VIRTUAL_ITERATOR_HPP__
#define __CORE_VIRTUAL_ITERATOR_HPP__

#include "callback_storage.hpp"

#include "algorithm_context_base.hpp"

#include <any>

#include <iostream>

namespace cppsort
{


class virtual_iterator {
    std::any m_iter_storage;
    bool is_eq_;

    callback_storage m_increment_cb;
    callback_storage m_eq_cb;
    callback_storage m_swap_cb;


public:

    template <typename Iter>
    void init(Iter _iter) {
        m_iter_storage = _iter;
        is_eq_ = 0;

        std::cout << "pointer iterator init: " << (int *) &(*_iter) << "\n";

        auto labmda_inc = [](std::any& _iter_storage) -> auto {
            Iter it = std::any_cast<Iter>(_iter_storage);
            std::cout << "inc: " << *it;
            ++it;
            std::cout << " inc: " << *it << "\n";
            _iter_storage = it;
        };

        auto labmda_eq = [](std::any _lhs, std::any _rhs, bool& _eq) -> auto {
            Iter it_lhs = std::any_cast<Iter>(_lhs);
            Iter it_rhs = std::any_cast<Iter>(_rhs);

            std::cout << "eq: " << "lhs: " << *it_lhs << " rhs: " << *it_rhs << "\n";
            std::cout << "eq_ptr: " << "lhs: " << (int *) &(*it_lhs) << " rhs: " << (int *) &(*it_rhs) << "\n";

            _eq_ =  (it_lhs == it_rhs);
            std::cout << "eq: " << _eq << (int*) &_eq << "\n";
        };

        auto labmda_swap = [](std::any& _lhs, std::any& _rhs) -> auto {
            Iter it_lhs = std::any_cast<Iter>(_lhs);
            Iter it_rhs = std::any_cast<Iter>(_rhs);

            std::cout << "sw: " << "lhs: " << *it_lhs << " rhs: " << *it_rhs << "\n";

            auto tmp = *it_lhs;
            *it_lhs = *it_rhs;
            *it_rhs = tmp;
        };

        init_callback_storage<decltype(labmda_inc)&&, std::any&>(m_increment_cb, std::move(labmda_inc));
        init_callback_storage<decltype(labmda_eq)&&, std::any, std::any, bool&>(m_eq_cb, std::move(labmda_eq));
        init_callback_storage<decltype(labmda_swap)&&, std::any&, std::any&>(m_swap_cb, std::move(labmda_swap));
    }


    virtual_iterator& operator++() {
        m_increment_cb.call(m_iter_storage);
        return *this;
    }

    bool operator==(const virtual_iterator& _rhs) {
        m_eq_cb.call(_rhs.m_iter_storage);
        std::cout << "eq: == " << is_eq_ << "\n";
        return is_eq_;
    }

    bool operator!=(const virtual_iterator& _rhs) {
        m_eq_cb.call(_rhs.m_iter_storage);
        std::cout << "eq: != " << is_eq_ << (int*) &is_eq_ << "\n";
        return !is_eq_;
    }

    void swap(virtual_iterator& _rhs) {
        m_swap_cb.call(_rhs.m_iter_storage);
    }

    std::any get_normal_iter() {return m_iter_storage;}

};



}






#endif  // __CORE_VIRTUAL_ITERATOR_HPP__
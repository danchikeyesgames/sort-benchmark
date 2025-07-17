#ifndef __ALGORITHM_CONTEXT_BASE_HPP__
#define __ALGORITHM_CONTEXT_BASE_HPP__

#include "algo_types.hpp"

#include "callback_storage.hpp"

#include "virtual_iterator.hpp"

namespace cppsort
{

class algorithm_context_base {
    callback_storage m_cb_storage;

protected:
    template <class IStrategy>
    void init(IStrategy&& _strategyImpl) {
        init_callback_storage<IStrategy, virtual_iterator, virtual_iterator, comparator_t<virtual_iterator>>(m_cb_storage, std::forward<IStrategy>(_strategyImpl));
    }

    template <class RandomIter>
    void call_algorithm(RandomIter _begin, RandomIter _end, comparator_t<RandomIter> _comparator) {
        auto lambda_wrapper = [_comparator](virtual_iterator& _lhs, virtual_iterator& _rhs) -> int {
                                    RandomIter lhs = std::any_cast<RandomIter>(_lhs.get_normal_iter());
                                    RandomIter rhs = std::any_cast<RandomIter>(_rhs.get_normal_iter());

                                    return _comparator(lhs, rhs);
                                };

        virtual_iterator vi_begin;
        virtual_iterator vi_end;

        vi_begin.init(_begin);
        vi_end.init(_end);

        m_cb_storage.call(vi_begin, vi_end, lambda_wrapper);
    }
};

}   // ns: cppsort




#endif  // __ALGORITHM_CONTEXT_BASE_HPP__

#ifndef __ALGORITHM_CONTEXT_BASE_HPP__
#define __ALGORITHM_CONTEXT_BASE_HPP__

#include "algo_types.hpp"

#include "callback_storage.hpp"

namespace cppsort 
{

class algorithm_context_base {
    callback_storage m_cb_storage;

protected:
    template <class IStrategy, class RandomIter>
    void init(IStrategy&& _strategyImpl) {
        init_callback_storage<IStrategy, RandomIter, RandomIter, comparator_t<RandomIter>>(m_cb_storage, std::forward<IStrategy>(_strategyImpl));
    }

    template <class RandomIter>
    void call_algorithm(RandomIter _begin, RandomIter _end, comparator_t<RandomIter> _comparator) {
        m_cb_storage.call(_begin, _end, _comparator);
    }
};

}   // ns: cppsort




#endif  // __ALGORITHM_CONTEXT_BASE_HPP__

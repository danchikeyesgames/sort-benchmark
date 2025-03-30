#ifndef __SORT_ALGO_CONTEXT_BASE_HPP__
#define __SORT_ALGO_CONTEXT_BASE_HPP__

#include "callback_storage.hpp"

#include "i_strategy.hpp"

namespace cpp_algosort_benchmark
{

class sort_algo_context_base {
    callback_storage m_cb_storage;

protected:
    template <class IStrategy, class RandomIter>
    void init(IStrategy&& _strategyImpl) {
        init_callback_storage<IStrategy, RandomIter, RandomIter, int(*)(RandomIter&, RandomIter&)>(m_cb_storage, std::forward<IStrategy>(_strategyImpl));
    }

    template <class RandomIter>
    void call_algorithm(RandomIter _begin, RandomIter _end, int(*_comparator)(RandomIter&, RandomIter&)) {
        m_cb_storage.call(_begin, _end, _comparator);
    }
};

}




#endif  // __SORT_ALGO_CONTEXT_BASE_HPP__
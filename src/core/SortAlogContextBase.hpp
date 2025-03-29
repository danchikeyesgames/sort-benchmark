#ifndef __SORT_ALGO_CONTEXT_BASE_HPP__
#define __SORT_ALGO_CONTEXT_BASE_HPP__

#include "callback_storage.hpp"

#include "error.hpp"

#include "common/IStrategy.hpp"

namespace cpp_algosort_benchmark
{

class SortAlgoContextBase {
    callback_storage m_cb_storage;

protected:
    template <class IStrategy, class RandomIter>
    error_t InitCallbackStorage(IStrategy&& _strategyImpl) {
        init_callback_storage<IStrategy, RandomIter, RandomIter, int(*)(RandomIter&, RandomIter&)>(m_cb_storage, std::forward<IStrategy>(_strategyImpl));

        return error_t::OPERATION_SUCCESS;
    }

    template <class RandomIter>
    error_t CallSortAlgo(RandomIter _begin, RandomIter _end, int(*_comparator)(RandomIter&, RandomIter&)) {
        m_cb_storage.call(_begin, _end, _comparator);

        return error_t::OPERATION_SUCCESS;
    }
};

}




#endif  // __SORT_ALGO_CONTEXT_BASE_HPP__
#ifndef __SORT_ALGO_CONTEXT_HPP__
#define __SORT_ALGO_CONTEXT_HPP__

#include "error.hpp"

#include "core/SortAlogContextBase.hpp"

#include "common/IStrategy.hpp"


namespace cpp_algosort_benchmark
{

template <class RandomIter>
class SortAlgoContext : public SortAlgoContextBase {

public:
    template <class T>
    error_t SetupAlgorithm(common::IStrategy<T>* _strategyImpl) {
        SortAlgoContextBase::InitCallbackStorage<common::IStrategy<T>&, RandomIter>(*_strategyImpl);

        return error_t::OPERATION_SUCCESS;
    }

    error_t operator()(RandomIter _begin, RandomIter _end, int(*_comparator)(RandomIter&, RandomIter&)) {
        SortAlgoContextBase::CallSortAlgo(_begin, _end, _comparator);

        return error_t::OPERATION_SUCCESS;
    }
};

}

#endif  // __SORT_ALGO_CONTEXT_HPP__
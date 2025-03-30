#ifndef __SORT_ALGO_CONTEXT_HPP__
#define __SORT_ALGO_CONTEXT_HPP__

#include "core/result.hpp"

#include "core/sort_algo_context_base.hpp"

#include "core/i_strategy.hpp"


namespace cpp_algosort_benchmark
{

template <class RandomIter>
class sort_algorithm_context : public sort_algo_context_base {

public:
    template <class T>
    result_t setup_algorithm(i_strategy<T>* _strategyImpl) {
        sort_algo_context_base::init<i_strategy<T>&, RandomIter>(*_strategyImpl);

        return result_t::OPERATION_SUCCESS;
    }

    result_t operator()(RandomIter _begin, RandomIter _end, int(*_comparator)(RandomIter&, RandomIter&)) {
        sort_algo_context_base::call_algorithm(_begin, _end, _comparator);

        return result_t::OPERATION_SUCCESS;
    }
};

}

#endif  // __SORT_ALGO_CONTEXT_HPP__
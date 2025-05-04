#ifndef __ALGORITHM_CONTEXT_HPP__
#define __ALGORITHM_CONTEXT_HPP__

#include "core/algorithm_context_base.hpp"

#include "core/i_strategy.hpp"


namespace cppsort
{

template <class RandomIter>
class algorithm_context : public algorithm_context_base {

public:
    template <class T>
    result_t setup_algorithm(i_strategy<T>* _strategyImpl) {
        algorithm_context_base::init<i_strategy<T>&, RandomIter>(*_strategyImpl);

        return result_t::OPERATION_SUCCESS;
    }

    result_t operator()(RandomIter _begin, RandomIter _end, comparator_t<RandomIter> _comparator) {
        algorithm_context_base::call_algorithm(_begin, _end, _comparator);

        return result_t::OPERATION_SUCCESS;
    }
};

}   // ns: cppsort

#endif  // __ALGORITHM_CONTEXT_HPP__

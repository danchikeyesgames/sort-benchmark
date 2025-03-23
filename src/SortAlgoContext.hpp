#ifndef __SORT_ALGO_CONTEXT_HPP__
#define __SORT_ALGO_CONTEXT_HPP__

#include "core/callback_storage.hpp"

#include "error.hpp"

#include "common/IStrategy.hpp"


#include <vector>


namespace cpp_algosort_benchmark
{

class SortAlgoContext {
    callback_storage m_cb_storage;

public:
    template <class T, typename Type>
    error_t SetupAlgorithm(common::IStrategy<T>* _strategyImpl) {
        init_callback_storage<common::IStrategy<T>&, typename std::vector<Type>::iterator, typename std::vector<Type>::iterator, int(*)(Type&, Type&)>(m_cb_storage, *_strategyImpl);

        return error_t::OPERATION_SUCCESS;
    }

    template <class T>
    error_t operator()(typename std::vector<T>::iterator _begin, typename std::vector<T>::iterator _end, int(*_comparator)(T&, T&)) {
        m_cb_storage.call(_begin, _end, _comparator);

        return error_t::OPERATION_SUCCESS;
    }
};

}

#endif  // __SORT_ALGO_CONTEXT_HPP__
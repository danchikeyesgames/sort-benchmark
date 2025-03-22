#ifndef __SORT_ALGO_CONTEXT_HPP__
#define __SORT_ALGO_CONTEXT_HPP__

#include "common/IStrategy.hpp"
#include "common/callback.hpp"
#include "common/error.hpp"

#include <vector>


namespace cpp_algosort_benchmark
{

using namespace common;

class SortAlgoContext {
    callback_storage m_cb_storage;

public:
    template <class T, typename Type>
    error_t SetupAlgorithm(IStrategy<T>* _strategyImpl) {
        callback_storage_ops<is_in_place<T>::m_value>::template pack_cb<IStrategy<T>&, typename std::vector<Type>::iterator, typename std::vector<Type>::iterator, int(*)(Type&, Type&)>(m_cb_storage, *_strategyImpl);

        return OPERATION_SUCCESS;
    }

    template <class T>
    error_t operator()(typename std::vector<T>::iterator _begin, typename std::vector<T>::iterator _end, int(*_comparator)(T&, T&)) {
        m_cb_storage.call(_begin, _end, _comparator);

        return OPERATION_SUCCESS;
    }
};

}

#endif  // __SORT_ALGO_CONTEXT_HPP__
#ifndef __ISTRATEGY_HPP__
#define __ISTRATEGY_HPP__

#include "error.hpp"

#include <vector>

namespace cpp_algosort_benchmark
{

namespace common
{

template <class T>
class IStrategy {

public:
    IStrategy() {}
    ~IStrategy() = default;

    template <class RandomIter>
    void operator()(RandomIter _begin, RandomIter _end, int(*_comparator)(RandomIter&, RandomIter&)) {
        static_cast<T*>(this)->Sort(_begin, _end, _comparator);
    }

};

}

}

#endif  // __ISTRATEGY_HPP__
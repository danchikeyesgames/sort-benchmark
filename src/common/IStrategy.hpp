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

    template <class Type>
    void operator()(typename std::vector<Type>::iterator _begin, typename std::vector<Type>::iterator _end, int(*_comparator)(Type&, Type&)) {
        static_cast<T*>(this)->Sort(_begin, _end, _comparator);
    }

};

}

}

#endif  // __ISTRATEGY_HPP__
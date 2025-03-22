#ifndef __COUNTING_SORT_HPP__
#define __COUNTING_SORT_HPP__

#include "common/IStrategy.hpp"

#include <vector>
#include <iostream>

namespace cpp_algosort_benchmark
{

class CountingSort : public common::IStrategy<CountingSort> {
public:
    template <typename Type>
    void Sort(typename std::vector<Type>::iterator _begin, typename std::vector<Type>::iterator _end, int(*_comparator)(Type&, Type&)) {
        std::cout << "Hello, World\n";
    }
};

}

#endif  // __COUNTING_SORT_HPP__
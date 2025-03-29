#ifndef __COUNTING_SORT_HPP__
#define __COUNTING_SORT_HPP__

#include "common/IStrategy.hpp"

#include <vector>
#include <iostream>

namespace cpp_algosort_benchmark
{

class CountingSort : public common::IStrategy<CountingSort> {
public:
    template <typename RandomIter>
    void Sort(RandomIter _begin, RandomIter _end, int(*_comparator)(RandomIter&, RandomIter&)) {
        std::cout << "Hello, World\n";
        std::cout << *_begin << " " << *(_begin+1) << "\n";
    }
};

}

#endif  // __COUNTING_SORT_HPP__
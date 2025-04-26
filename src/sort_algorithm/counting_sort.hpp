#ifndef __COUNTING_SORT_HPP__
#define __COUNTING_SORT_HPP__

#include "core/i_strategy.hpp"

#include <iostream>

namespace cpp_algosort_benchmark
{

class counting_sort : public i_strategy<counting_sort> {
public:
    template <typename RandomIter>
    void Sort(RandomIter _begin, RandomIter _end, int(*_comparator)(RandomIter&, RandomIter&)) {
        std::cout << "Hello, World\n";
        std::cout << *_begin << " " << *(_begin+1) << "\n";
    }
};

}

#endif  // __COUNTING_SORT_HPP__

#ifndef __BUBBLE_SORT_HPP__
#define __BUBBLE_SORT_HPP__

#include "core/i_strategy.hpp"

#include <iostream>

namespace cpp_algosort_benchmark
{

class bubble_sort : public i_strategy<bubble_sort> {
public:
    template <typename RandomIter>
    void Sort(RandomIter _begin, RandomIter _end, int(*_comparator)(RandomIter&, RandomIter&)) {
        std::cout << "Bubble sort begin\n";
        for (auto i = _begin; i != _end; ++i) {
            for (auto j = i; j != _end; ++j) {
                int value = _comparator(i, j);

                if (value == 0) continue;
                else if (value < 0) continue;
                else if (value > 0) {
                    auto tmp = *i;
                    *i = *j;
                    *j = tmp;
                }
            }
        }
        std::cout << "Bubble sort finish [OK]\n";
    }
};

}


#endif  // __BUBBLE_SORT_HPP__


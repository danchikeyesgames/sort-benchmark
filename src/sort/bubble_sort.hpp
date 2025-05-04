#ifndef __BUBBLE_SORT_HPP__
#define __BUBBLE_SORT_HPP__

#include "core/algo_types.hpp"

#include "core/i_strategy.hpp"

#include "core/debug.hpp"

namespace cppsort
{

class bubble_sort : public i_strategy<bubble_sort> {
public:
    template <typename RandomIter>
    void Sort(RandomIter _begin, RandomIter _end, comparator_t<RandomIter> _comparator) {
        debug::call("Bubble sort start");

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
 
        debug::call("Bubble sort has finished successfull");
    }
};

}   // ns: cppsort


#endif  // __BUBBLE_SORT_HPP__


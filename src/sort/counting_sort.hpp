#ifndef __COUNTING_SORT_HPP__
#define __COUNTING_SORT_HPP__

#include "core/i_strategy.hpp"

#include "core/debug.hpp"

namespace cppsort
{

class counting_sort : public i_strategy<counting_sort> {
public:
    template <typename RandomIter>
    void Sort(RandomIter _begin, RandomIter _end, int(*_comparator)(RandomIter&, RandomIter&)) {
        debug::call("call counting_sort");
    }
};

}

#endif  // __COUNTING_SORT_HPP__

#ifndef __ALGO_TYPES_HPP__
#define __ALGO_TYPES_HPP__

#include "result.hpp"

namespace cppsort
{

template <typename RandomIter>
using comparator_t = int (*)(RandomIter&, RandomIter&);

}   // ns: cppsort

#endif  // __ALGO_TYPRS_HPP__



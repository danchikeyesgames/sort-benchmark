#ifndef __ISTRATEGY_HPP__
#define __ISTRATEGY_HPP__

#include "virtual_iterator.hpp"

namespace cppsort
{

template <class T>
class i_strategy {

public:
    i_strategy() {}
    ~i_strategy() = default;

    void operator()(virtual_iterator _begin, virtual_iterator _end, int(*_comparator)(virtual_iterator&, virtual_iterator&)) {
        static_cast<T*>(this)->Sort(_begin, _end, _comparator);
    }
};

}   // ns: cppsort

#endif  // __ISTRATEGY_HPP__

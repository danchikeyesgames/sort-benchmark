#ifndef __ISTRATEGY_HPP__
#define __ISTRATEGY_HPP__

namespace cpp_algosort_benchmark
{

template <class T>
class i_strategy {

public:
    i_strategy() {}
    ~i_strategy() = default;

    template <class RandomIter>
    void operator()(RandomIter _begin, RandomIter _end, int(*_comparator)(RandomIter&, RandomIter&)) {
        static_cast<T*>(this)->Sort(_begin, _end, _comparator);
    }

};

}

#endif  // __ISTRATEGY_HPP__
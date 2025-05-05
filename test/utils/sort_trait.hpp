#ifndef __SORT_TRAIT_HPP__
#define __SORT_TRAIT_HPP__

namespace cppsort
{

namespace util
{

namespace trait

{

namespace detail
{

template<class ForwardIter, class Compare>
inline ForwardIter is_sorted_util(ForwardIter _first, ForwardIter _last, Compare _comp) {
    while (_first != _last) {
        auto next = ++_first;

        if (!_comp(_first, next))
            return next;

        _first = next;
    }

    return _first;
}

}

template <typename T>
struct less {
    inline bool operator()(const T& _lv, const T& _rv) {
        return *_lv <= *_rv;
    }
};

template <typename T>
struct greater {
    inline bool operator()(const T& _lv, const T& _rv) {
        return *_lv >= *_rv;
    }
};


template <class ForwardIter, class Compare = less<ForwardIter>>
inline bool is_sorted(ForwardIter _first, ForwardIter _last, Compare _comp = {}) {
    return detail::is_sorted_util(_first, _last, _comp) == _last ? 1 : 0;
}



}   // ns: trait

}   // ns: util

}   // ns: cppsort

#endif  // __SORT_TRAIT_HPP__

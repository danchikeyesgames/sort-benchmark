#ifndef __BUBBLE_SORT_TEST_HPP__
#define __BUBBLE_SORT_TEST_HPP__

#include "algorithm_context.hpp"
#include "sort/bubble_sort.hpp"

#include "utils/SortTestAbstract.hpp"
#include "utils/sort_trait.hpp"

#include <vector>
#include <iostream>

namespace cppsort
{

namespace test
{

class BubbleSortTest1 : public SortTestAbstract<BubbleSortTest1> {
    std::vector<int> ds; 
    algorithm_context<std::vector<int>::iterator> ac;
    bubble_sort bs;

public:
    void Init() {
        ds.push_back(20);
        ds.push_back(10);
        ds.push_back(100);
        ds.push_back(125);
        ds.push_back(6);
        ds.push_back(310);
        ds.push_back(110);
        ds.push_back(67);

        ac.setup_algorithm(&bs);
    }

    void Run() {
        ac(ds.begin(), ds.end(), [](std::vector<int>::iterator& lv, std::vector<int>::iterator& rv) -> int { return *lv > *rv; });
    }

    int Check() {
        for (auto value : ds) {
            std::cout << " " << value;
        }
        std::cout << "\n";

        return util::trait::is_sorted(ds.begin(), ds.end());
    }
};

}   // ns: test

}   // ns: cppsort

#endif  // __BUBBLE_SORT_TEST_HPP__

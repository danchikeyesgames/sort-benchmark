#ifndef __BUBBLE_SORT_TEST_HPP__
#define __BUBBLE_SORT_TEST_HPP__

#include "algorithm_context.hpp"
#include "sort/bubble_sort.hpp"

#include "utils/sort_test.hpp"
#include "utils/sort_trait.hpp"

#include <vector>
#include <iostream>

namespace cppsort
{

namespace test
{


SORT_TEST(bubble_sort, test_1) {
    std::vector<int> ds;
    algorithm_context ac;
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
        ac.sort<std::vector<int>::iterator>(ds.begin(), ds.end(), [](std::vector<int>::iterator& lv, std::vector<int>::iterator& rv) -> int { return *lv > *rv; });
    }

    int Check() {
        return util::trait::is_sorted(ds.begin(), ds.end());
    }
};

SORT_TEST(bubble_sort, test_2) {
    std::vector<int> ds;
    algorithm_context ac;
    bubble_sort bs;

public:
    void Init() {
        ds.push_back(20);
        ds.push_back(310);
        ds.push_back(100);
        ds.push_back(9999999);
        ds.push_back(6);
        ds.push_back(110);
        ds.push_back(512);
        ds.push_back(67);
        ds.push_back(12490125);
        ds.push_back(10);
        ds.push_back(125);
        ds.push_back(671);
        ds.push_back(67222);
        ds.push_back(6709);
        ds.push_back(6778);
        ds.push_back(66867);
        ds.push_back(6007);
        ds.push_back(670000000);

        ac.setup_algorithm(&bs);
    }

    void Run() {
        ac.sort<std::vector<int>::iterator>(ds.begin(), ds.end(), [](std::vector<int>::iterator& lv, std::vector<int>::iterator& rv) -> int { return *lv > *rv; });
    }

    int Check() {
        return util::trait::is_sorted(ds.begin(), ds.end());
    }
};

SORT_TEST(bubble_sort, test_3) {
    std::vector<int> ds;
    algorithm_context ac;
    bubble_sort bs;

public:
    void Init() {
        ds.push_back(3);
        ds.push_back(1);
        ds.push_back(2);
        ds.push_back(4);
        ds.push_back(5);

        ac.setup_algorithm(&bs);
    }

    void Run() {
        ac.sort<std::vector<int>::iterator>(ds.begin(), ds.end(), [](std::vector<int>::iterator& lv, std::vector<int>::iterator& rv) -> int { return *lv > *rv; });
    }

    int Check() {
        return util::trait::is_sorted(ds.begin(), ds.end());
    }
};



}   // ns: test

}   // ns: cppsort

#endif  // __BUBBLE_SORT_TEST_HPP__

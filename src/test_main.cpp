#include "core/debug.hpp"
#include "sort/counting_sort.hpp"
#include "sort/bubble_sort.hpp"

#include "algorithm_context.hpp"

#include <vector>

#include <iostream>

int cmp(std::vector<int>::iterator& lv, std::vector<int>::iterator& rv) {
    return 0;
}

int main() {
    std::vector<int> i;
    std::vector<double> id;

    cppsort::algorithm_context<std::vector<int>::iterator> context;
    cppsort::algorithm_context<std::vector<double>::iterator> context2;
    cppsort::counting_sort cs;
    cppsort::bubble_sort bs;

    cppsort::debug::update_callback([](const char* _format) {std::cout << _format << "\n";});

    i.push_back(200);
    i.push_back(300);
    i.push_back(15);
    i.push_back(934);
    i.push_back(63);

    context.setup_algorithm(&cs);
    context(i.begin(), i.end(), cmp);


    id.push_back(200.);
    id.push_back(300.);

    context2.setup_algorithm(&cs);
    context2(id.begin(), id.end(), [](std::vector<double>::iterator& lv, std::vector<double>::iterator& rv) { return 0;});

    std::vector<int> vec = {10, 35, 56, 1, 5, 16, 11, 1025, 567, 92, 79};

    cppsort::algorithm_context<std::vector<int>::iterator> context_bs;

    context_bs.setup_algorithm(&bs);

    context_bs(vec.begin(), vec.end(), [](std::vector<int>::iterator& lv, std::vector<int>::iterator& rv) -> int {
        return *lv > *rv;
    });

    for (auto i = vec.begin(); i != vec.end(); ++i) {
        std::cout << " " << *i;
    }
    std::cout << std::endl;

    return 0;
}

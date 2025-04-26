#include "sort_algorithm/counting_sort.hpp"
#include "sort_algorithm/bubble_sort.hpp"

#include "sort_algo_context.hpp"

#include <vector>

int cmp(std::vector<int>::iterator& lv, std::vector<int>::iterator& rv) {
    return 0;
}

int main() {
    std::vector<int> i;
    std::vector<double> id;

    cpp_algosort_benchmark::sort_algorithm_context<std::vector<int>::iterator> context;
    cpp_algosort_benchmark::sort_algorithm_context<std::vector<double>::iterator> context2;
    cpp_algosort_benchmark::counting_sort cs;
    cpp_algosort_benchmark::bubble_sort bs;

    i.push_back(200);
    i.push_back(300);

    context.setup_algorithm(&cs);
    context(i.begin(), i.end(), cmp);


    id.push_back(200.);
    id.push_back(300.);

    context2.setup_algorithm(&cs);
    context2(id.begin(), id.end(), [](std::vector<double>::iterator& lv, std::vector<double>::iterator& rv) { return 0;});

    std::vector<int> vec = {10, 35, 56, 1, 5, 16, 11, 1025, 567, 92, 79};

    cpp_algosort_benchmark::sort_algorithm_context<std::vector<int>::iterator> context_bs;

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

#include "counting_sort/CountingSort.hpp"

#include "SortAlgoContext.hpp"

int cmp(std::vector<int>::iterator& lv, std::vector<int>::iterator& rv) {
    return 0;
}

int main() {
    std::vector<int> i;
    std::vector<double> id;

    cpp_algosort_benchmark::SortAlgoContext<std::vector<int>::iterator> context;
    cpp_algosort_benchmark::SortAlgoContext<std::vector<double>::iterator> context2;
    cpp_algosort_benchmark::CountingSort cs;

    i.push_back(200);
    i.push_back(300);

    context.SetupAlgorithm(&cs);
    context(i.begin(), i.end(), cmp);


    id.push_back(200.);
    id.push_back(300.);

    context2.SetupAlgorithm(&cs);
    context2(id.begin(), id.end(), [](std::vector<double>::iterator& lv, std::vector<double>::iterator& rv) { return 0;});

    return 0;
}
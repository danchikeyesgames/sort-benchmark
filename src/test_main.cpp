#include "counting_sort/CountingSort.hpp"

#include "SortAlgoContext.hpp"

int cmp(std::vector<int>::iterator& lv, std::vector<int>::iterator& rv) {
    return 0;
}

int main() {
    std::vector<int> i;

    cpp_algosort_benchmark::SortAlgoContext<std::vector<int>::iterator> context;
    cpp_algosort_benchmark::CountingSort cs;

    i.push_back(200);
    i.push_back(300);

    context.SetupAlgorithm(&cs);
    context(i.begin(), i.end(), cmp);

    return 0;
}
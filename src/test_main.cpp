#include "counting_sort/CountingSort.hpp"

#include "SortAlgoContext.hpp"

int cmp(int& lv, int& rv) {
    return 0;
}

int main() {
    cpp_algosort_benchmark::SortAlgoContext context;
    cpp_algosort_benchmark::CountingSort cs;

    std::vector<int> i;

    context.SetupAlgorithm<cpp_algosort_benchmark::CountingSort, int>(reinterpret_cast<cpp_algosort_benchmark::common::IStrategy<cpp_algosort_benchmark::CountingSort>*>(&cs));
    context(i.begin(), i.end(), cmp);

    return 0;
}
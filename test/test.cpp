#include "BubleSortTest.hpp"

#include <iostream>



int main() {
    cppsort::test::BubbleSortTest1 bst1;

    std::cout << "Start BubbleSortTest1\n";
    bst1.RunTest();
    std::cout << "BubbleSortTest1 passed successfully\n";

    return 0;
}

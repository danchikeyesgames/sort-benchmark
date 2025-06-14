#include "unit/bubble_sort_test.hpp"

#include <iostream>


namespace cppsort
{

namespace test
{

void init_test() {
    SORT_REGISTER_TEST(bubble_sort, test_1);

}

}

}

int main() {
    cppsort::test::init_test();

    cppsort::test::sort_test_db::run();
}
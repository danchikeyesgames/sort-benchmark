#ifndef __SORT_TEST_ABSTRACT_HPP__
#define __SORT_TEST_ABSTRACT_HPP__

#include <cassert>

namespace cppsort
{

namespace test
{

template <typename T>
class SortTestAbstract {
public:
    void RunTest() {
        T* instance_ = reinterpret_cast<T*>(this);

        instance_->Init();
        instance_->Run();

        assert(instance_->Check());
    }
};

}

}

#endif  // __SORT_TEST_ABSTRACT_HPP__

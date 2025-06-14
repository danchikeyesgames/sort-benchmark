#ifndef __SORT_TEST_HPP__
#define __SORT_TEST_HPP__

#include <map>
#include <vector>
#include <string>

#include <utility>

#include <type_traits>

#include <cstdio>
#include <cassert>

namespace cppsort
{

#define CPPSORT_CONCAT(first, second) first ## second
#define CPPSORT_CONCAT_X2(first, second) CPPSORT_CONCAT(first, second)

namespace test
{


#define SORT_TEST(category, name)   \
    class CPPSORT_CONCAT_X2(category, CPPSORT_CONCAT(_, name)) : public sort_test<CPPSORT_CONCAT_X2(category, CPPSORT_CONCAT(_, name))>

#define SORT_REGISTER_TEST(category, name)                                  \
    do {                                                                    \
        CPPSORT_CONCAT_X2(category, CPPSORT_CONCAT(_, name)) instance_{};   \
        sort_test_db::register_test(#category, #name, instance_);           \
    } while(0)




template <typename T>
class sort_test {
public:
    void RunTest() {
        T* instance_ = reinterpret_cast<T*>(this);

        instance_->Init();
        instance_->Run();

        assert(instance_->Check());
    }
};





struct sort_test_db {
    struct sort_test_node {
        char  m_stack_memory[128];
        void (*m_call_ptr)();


        template <typename T>
        static sort_test_node create_node(T&& _sort_test) {
            using decay_t = typename std::decay<T>::type;

            sort_test_node node_;

            new (node_.m_stack_memory) decay_t(std::forward<T>(_sort_test));
            node_.m_call_ptr = reinterpret_cast<void(*)()>(call_ptr<decay_t>);

            return node_;
        }

        void call() {
            reinterpret_cast<void(*)(sort_test_node*)>(m_call_ptr)(this);
            std::printf("Pass\n");
        }

        private:

        template <typename T>
        static void call_ptr(sort_test_node* _instance) {
            T* instance_ = reinterpret_cast<T*>(_instance->m_stack_memory);
            instance_->RunTest();
        }
    };

    template <typename T>
    static void register_test(const std::string& _category, const std::string& _name, sort_test<T>& _sort_test) {
        sort_test_node node_ = sort_test_node::create_node(_sort_test);

        std::vector<std::pair<std::string, sort_test_node>>& category = sort_test_map[_category];
        category.push_back(std::pair<std::string, sort_test_node>{_name, node_});
    }

    static void run() {
        for (auto iter = sort_test_map.begin(); iter != sort_test_map.end(); ++iter) {
            std::printf("[%s] run category:\n", iter->first.c_str());
            for (auto iter_test = iter->second.begin(); iter_test != iter->second.end(); ++iter_test) {
                std::printf("Test run %s: ", iter_test->first.c_str());
                iter_test->second.call();
            }
        }
    }

private:

    static std::map<std::string, std::vector<std::pair<std::string, sort_test_node>>> sort_test_map;
};

std::map<std::string, std::vector<std::pair<std::string, sort_test_db::sort_test_node>>> sort_test_db::sort_test_map;

}

}

#endif  // __SORT_TEST_HPP__

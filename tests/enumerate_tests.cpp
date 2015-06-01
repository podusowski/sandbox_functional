#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "expressive/enumerate.hpp"

struct loop_action_mock
{
    MOCK_METHOD2(call, void(int, int));
};

template<class container_type>
auto expect_vector_to_be_enumerated(container_type vector)
{
    loop_action_mock mock;

    EXPECT_CALL(mock, call(0, 1));
    EXPECT_CALL(mock, call(1, 2));
    EXPECT_CALL(mock, call(2, 3));

    for (auto elem : expressive::enumerate(vector))
    {
        mock.call(elem.first, elem.second);
    }
}

TEST(enumerate_tests, mutable_vector_can_be_enumerated)
{
    std::vector<int> numbers{1, 2, 3};
    expect_vector_to_be_enumerated<std::vector<int> &>(numbers);
}

TEST(enumerate_tests, value_elem_dont_mutate_elements)
{
    // this is also a std::map behavior

    std::vector<int> numbers{1};

    for (auto elem : expressive::enumerate(numbers))
        elem.first = 2;

    EXPECT_EQ(1, numbers[0]);
}

TEST(enumerate_tests, immutable_vector_can_be_enumerated)
{
    const std::vector<int> numbers{1, 2, 3};
    expect_vector_to_be_enumerated<const std::vector<int> &>(numbers);
}

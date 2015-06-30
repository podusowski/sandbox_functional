#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "expressive/element.hpp"

namespace
{

const auto map_of_numbers = std::map<int, std::string>{{1, "one"}, {2, "two"}};

} // namespace

template<class T>
struct action_mock
{
    MOCK_METHOD1_T(call, void(T));
};

TEST(element_tests, action_called_when_element_is_found_on_const_map)
{
    action_mock<std::string> action;

    EXPECT_CALL(action, call("one"));

    expressive::element(map_of_numbers, 1, [&](auto s)
    {
        action.call(s);
    });
}
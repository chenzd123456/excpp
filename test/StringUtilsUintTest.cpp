#include <string>

#include <gtest/gtest.h>

#include "utils/StringUtils.h"

TEST(formatStringTest, HandlesEmptyFormatString) {
    std::string result = excpp::StringUtils::format("");
    EXPECT_EQ(result, "");
}

TEST(formatStringTest, HandlesValidFormatStringWithArgs) {
    std::string result =
        excpp::StringUtils::format("%d %s %c", 10, "test", 'A');
    EXPECT_EQ(result, "10 test A");
}

TEST(formatStringTest, HandlesValidFormatStringWithoutArgs) {
    std::string result = excpp::StringUtils::format("Test string without args");
    EXPECT_EQ(result, "Test string without args");
}

#include "gtest/gtest.h"
#include "container/Any.h"

TEST(AnyTest, testGetTypeUInt8) {
    Any a((uint8_t)10);
    EXPECT_EQ(Any::Type::UINT8, a.getType());
}

TEST(AnyTest, testGetTypeUInt16) {
    Any a((uint16_t)1);
    EXPECT_EQ(Any::Type::UINT16, a.getType());
}

TEST(AnyTest, testGetTypeUInt32) {
    Any a((uint32_t)1);
    EXPECT_EQ(Any::Type::UINT32, a.getType());
}

TEST(AnyTest, testGetTypeUInt64) {
    Any a((uint64_t)1);
    EXPECT_EQ(Any::Type::UINT64, a.getType());
}

TEST(AnyTest, testGetTypeInt8) {
    Any a((int8_t)1);
    EXPECT_EQ(Any::Type::INT8, a.getType());
}

TEST(AnyTest, testGetTypeInt16) {
    Any a((int16_t)1);
    EXPECT_EQ(Any::Type::INT16, a.getType());
}

TEST(AnyTest, testGetTypeInt32) {
    Any a((int32_t)1);
    EXPECT_EQ(Any::Type::INT32, a.getType());
}

TEST(AnyTest, testGetTypeInt64) {
    Any a((int64_t)1);
    EXPECT_EQ(Any::Type::INT64, a.getType());
}

TEST(AnyTest, testGetTypeFloat) {
    Any a(1.0f);
    EXPECT_EQ(Any::Type::FLOAT, a.getType());
}

TEST(AnyTest, testGetTypeDouble) {
    Any a(1.0);
    EXPECT_EQ(Any::Type::DOUBLE, a.getType());
}

TEST(AnyTest, testGetTypeChar) {
    Any a('a');
    EXPECT_EQ(Any::Type::CHAR, a.getType());
}

TEST(AnyTest, testGetTypeString) {
    Any a(std::string("hello"));
    EXPECT_EQ(Any::Type::STRING, a.getType());
}

TEST(AnyTest, testGetTypeBuffer) {
    std::vector<char> buffer{1, 2, 3};
    Any a(buffer);
    EXPECT_EQ(Any::Type::BUFFER, a.getType());
}

TEST(AnyTest, testGetTypePointer) {
    int value = 1;
    Any a(nullptr);
    EXPECT_EQ(Any::Type::POINTER, a.getType());
}

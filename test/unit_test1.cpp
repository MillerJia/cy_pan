#include "gtest/gtest.h"
#include "nlohmann/json.hpp"

TEST(TESTCASE, test0)
{
    EXPECT_EQ(1, 1);
}

TEST(TESTCASE, test1)
{
    EXPECT_EQ(1, 0);
}

TEST(JSONTEST, test0)
{
    using json = nlohmann::json;
    json obj;
    obj["zz"] = 1;
    std::cout << obj.dump() << std::endl;
    std::string s = std::string("{\"zz\":1}");
    EXPECT_STREQ(obj.dump().c_str(), s.c_str());
}

TEST(HTTPTEST, test0)
{
  
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
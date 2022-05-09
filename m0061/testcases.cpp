#include "strlib.h"
#include "..\\catch.hpp"

//test cases


//for the cstring compare without pointers
TEST_CASE("recCStrCmp-v1 - checking two of the same word")
{
    char str1[6] = "hello";
    char strCmp[6] = "hello";
    int index = 0;

    REQUIRE(recCStrCmp(str1, strCmp, index) == 0);
}

TEST_CASE("recCStrCmp-v1 - checking two of different word")
{
    char str[6] = "obama";
    char strCmp[7] = "barack";
    int index = 0; 

    REQUIRE(recCStrCmp(str, strCmp, index) > 0);
}

TEST_CASE("recCStrCmp-v1 - checking two of different word with different cases")
{
    char str[6] = "ObaMa";
    char strCmp[7] = "BaRaCk";
    int index = 0;

    REQUIRE(recCStrCmp(str, strCmp, index) > 0);
}

TEST_CASE("recCStrCmp-v1 - checking two of same word with different cases")
{
    char str[6] = "ObaMa";
    char strCmp[7] = "obAmA";
    int index = 0;

    REQUIRE(recCStrCmp(str, strCmp, index) == 0);
}

TEST_CASE("recCStrCmp-v1 - checking two of same word with one letter difference")
{
    char str[6] = "obama";
    char strCmp[7] = "obam";
    int index = 0;

    REQUIRE(recCStrCmp(str, strCmp, index) > 0);
}

//testcases for the function using pointers
TEST_CASE("recCStrCmp-v2 - checking two of the same word")
{
    char str1[6] = "hello";
    char strCmp[6] = "hello";

    REQUIRE(recCStrCmp(str1, strCmp) == 0);
}

TEST_CASE("recCStrCmp-v2 - checking two of a different word")
{
    char str1[6] = "yasas";
    char strCmp[7] = "gingus";

    REQUIRE(recCStrCmp(str1, strCmp) > 0);
}

TEST_CASE("recCStrCmp-v2 - checking two of same word with one letter difference")
{
    char str[6] = "obama";
    char strCmp[7] = "obam";

    REQUIRE(recCStrCmp(str, strCmp) > 0);
}

TEST_CASE("recCStrCmp-v2 - checking two of a different word with different cases")
{
    char str1[6] = "yasAs";
    char strCmp[7] = "YasaS";

    REQUIRE(recCStrCmp(str1, strCmp) == 0);
}
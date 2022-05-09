#include "..\catch.hpp"
#include "bitpacking.h"

//packThree testing
TEST_CASE("packThree - testing three given lowercase letters")
{
    short int myCodes;
    char high = 'a';
    char middle = 'b';
    char low = 'c';
    short int correctRes = 1091;

    myCodes = packThree(high, middle, low);

    REQUIRE(myCodes == correctRes);
}

TEST_CASE("packThree - testing three given UPPERCASE letters")
{
    short int myCodes;
    char high = 'A';
    char middle = 'B';
    char low = 'C';
    short int correctRes = 1091;

    myCodes = packThree(high, middle, low);

    REQUIRE(myCodes == correctRes);
}

TEST_CASE("packThree - testing three given UPPERCASE and LOWERCASE letters")
{
    short int myCodes;
    char high = 'A';
    char middle = 'b';
    char low = 'c';
    short int correctRes = 1091;

    myCodes = packThree(high, middle, low);

    REQUIRE(myCodes == correctRes);
}

TEST_CASE("packThree - testing three different LOWERCASE letters")
{
    short int myCodes;
    char high = 'b';
    char middle = 'x';
    char low = 'z';
    short int correctRes = 2842;

    myCodes = packThree(high, middle, low);

    REQUIRE(myCodes == correctRes);
}

TEST_CASE("packThree - testing three different UPPERCASE letters")
{
    short int myCodes;
    char high = 'B';
    char middle = 'X';
    char low = 'Z';
    short int correctRes = 2842;

    myCodes = packThree(high, middle, low);

    REQUIRE(myCodes == correctRes);
}

TEST_CASE("packThree - testing three different UPPERCASE and LOWERCASE letters")
{
    short int myCodes;
    char high = 'b';
    char middle = 'x';
    char low = 'Z';
    short int correctRes = 2842;

    myCodes = packThree(high, middle, low);

    REQUIRE(myCodes == correctRes);
}

//unpackThree testing
TEST_CASE("unpackThree - lowercase a, b, c")
{
    short int packedVal = 1091;
    char upper, middle, lower;

    unpackThree(packedVal, upper, middle, lower, LOWERCASE);

    CHECK(upper == 'a');
    CHECK(middle == 'b');
    CHECK(lower == 'c');
}

TEST_CASE("unpackThree - uppercase A, B, C")
{
    short int packedVal = 1091;
    char upper, middle, lower;

    unpackThree(packedVal, upper, middle, lower, UPPERCASE);

    CHECK(upper == 'A');
    CHECK(middle == 'B');
    CHECK(lower == 'C');
}


TEST_CASE("unpackThree - lowercase b, x, z")
{
    short int packedVal = 2842;
    char upper, middle, lower;

    unpackThree(packedVal, upper, middle, lower, LOWERCASE);

    CHECK(upper == 'b');
    CHECK(middle == 'x');
    CHECK(lower == 'z');
}

TEST_CASE("unpackThree - uppercase B, X, Z")
{
    short int packedVal = 2842;
    char upper, middle, lower;

    unpackThree(packedVal, upper, middle, lower, UPPERCASE);

    CHECK(upper == 'B');
    CHECK(middle == 'X');
    CHECK(lower == 'Z');
}
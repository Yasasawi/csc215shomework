#include "..\catch.hpp"
#include "strLib.h"

// given testcases here
TEST_CASE("replaceAllCString ? single substitution, same size")
{
    char array[100] = "This is a simple sentence.";
    char answer[100] = "This is a sample sentence.";
    char searchStr[20] = "simple";
    char replaceStr[20] = "sample";

    replaceAllCString(array, searchStr, replaceStr);
    REQUIRE(strcmp(answer, array) == 0);
}
TEST_CASE("replaceAllCString ? single substitution, smaller replacement")
{
    char array[100] = "This is a simple sentence.";
    char answer[100] = "This is a silly sentence.";
    char searchStr[20] = "simple";
    char replaceStr[20] = "silly";

    replaceAllCString(array, searchStr, replaceStr);
    REQUIRE(strcmp(answer, array) == 0);
}
TEST_CASE("replaceAllCString ? single substitution, larger replacement")
{
    char array[100] = "This is a silly sentence.";
    char answer[100] = "This is a really simple sentence.";
    char searchStr[20] = "silly";
    char replaceStr[20] = "really simple";

    replaceAllCString(array, searchStr, replaceStr);
    REQUIRE(strcmp(answer, array) == 0);
}
TEST_CASE("replaceAllString ? single substitution, same size")
{
    string array = "This is a simple sentence.";
    string answer = "This is a sample sentence.";
    string searchStr = "simple";
    string replaceStr = "sample";

    replaceAllString(array, searchStr, replaceStr);
    REQUIRE(answer == array);
}
TEST_CASE("replaceAllString ? single substitution, smaller replacement")
{
    string array = "This is a simple sentence.";
    string answer = "This is a silly sentence.";
    string searchStr = "simple";
    string replaceStr = "silly";

    replaceAllString(array, searchStr, replaceStr);
    REQUIRE(answer == array);
}
TEST_CASE("replaceAllString ? single substitution, larger replacement")
{
    string array = "This is a silly sentence.";
    string answer = "This is a really simple sentence.";
    string searchStr = "silly";
    string replaceStr = "really simple";

    replaceAllString(array, searchStr, replaceStr);
    REQUIRE(answer == array);
}

//my testing
TEST_CASE("replaceAllString - testing one replace")
{
    string str = "yasas Wijesekara";
    string replace = "aravinda";
    string look = "yasas";

    replaceAllString(str, look, replace); 
    REQUIRE(str == "aravinda Wijesekara");
}


TEST_CASE("replaceAllString - testing two replace")
{
    string str = "yasas yasas Wijesekara";
    string replace = "aravinda";
    string look = "yasas";

    replaceAllString(str, look, replace);
    REQUIRE(str == "aravinda aravinda Wijesekara");
}

TEST_CASE("replaceAllString - testing three replace")
{
    string str = "yasas yasas Wijesekara yasas";
    string replace = "aravinda";
    string look = "yasas";

    replaceAllString(str, look, replace);
    REQUIRE(str == "aravinda aravinda Wijesekara aravinda");
}

//replaceAllCString testing

TEST_CASE("replaceAllCString - single substitution")
{
    char array[100] = "yasas Wijesekara";
    char answer[100] = "aravinda Wijesekara";
    char searchStr[20] = "yasas";
    char replaceStr[20] = "aravinda";

    replaceAllCString(array, searchStr, replaceStr);

    REQUIRE(strcmp(answer, array) == 0);
}

TEST_CASE("replaceAllCString - double substitution")
{
    char array[100] = "yasas Wijesekara yasas";
    char answer[100] = "aravinda Wijesekara aravinda";
    char searchStr[20] = "yasas";
    char replaceStr[20] = "aravinda";
    replaceAllCString(array, searchStr, replaceStr); 
    REQUIRE(strcmp(answer, array) == 0);
}

TEST_CASE("replaceAllCString - replacing some letters in a paragraph")
{
    char array[300] = "of of of of of of of";
    char answer[300] = "fo fo fo fo fo fo fo";
    char searchStr[20] = "of";
    char replaceStr[20] = "fo";

    replaceAllCString(array, searchStr, replaceStr); 
    REQUIRE(strcmp(answer, array) == 0);
}

TEST_CASE("FO TO OF")
{
    char array[300] = "blah of hi I love minecraft of pain";
    char answer[300] = "blah fo hi I love minecraft fo pain";
    char searchStr[20] = "of";
    char replaceStr[20] = "fo";

    replaceAllCString(array, searchStr, replaceStr);

    REQUIRE(strcmp(answer, array) == 0);
}

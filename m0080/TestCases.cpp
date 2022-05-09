#include "sortedSingle.h"
#include "..\catch.hpp"
#include <sstream>
#include <iostream>

using namespace std;

//Sorted singles A tests
TEST_CASE("Constructor")
{
    sortedSingle list;
    REQUIRE(list.empty() == true);
    REQUIRE(list.size() == 0);
}

TEST_CASE("empty")
{
    sortedSingle list;
    REQUIRE(list.empty() == true);
    REQUIRE(list.insert(30));
    REQUIRE(list.insert(40));
    REQUIRE(list.insert(50));
    REQUIRE(list.empty() == false);
}

TEST_CASE("Find")
{
    sortedSingle list;

    REQUIRE(list.insert(30) == true);
    REQUIRE(list.insert(120) == true);
    REQUIRE(list.insert(50) == true);

    REQUIRE(list.find(30) == true);
    REQUIRE(list.find(120) == true);
    REQUIRE(list.find(50) == true);
    REQUIRE(list.find(300) == false);
}

TEST_CASE("Retrieve position")
{
    sortedSingle list;

    REQUIRE(list.insert(30) == true);
    REQUIRE(list.insert(120) == true);
    REQUIRE(list.insert(50) == true);
    REQUIRE(list.insert(40) == true);
    REQUIRE(list.insert(70) == true);
    REQUIRE(list.insert(80) == true);
    CHECK(list.insert(10) == true);

    CHECK(list.retrievePosition(30) == 2);
    CHECK(list.retrievePosition(120) == 7);
    CHECK(list.retrievePosition(50) == 4);
    CHECK(list.retrievePosition(40) == 3);
    CHECK(list.retrievePosition(70) == 5);
    CHECK(list.retrievePosition(80) == 6);
}

TEST_CASE("Size")
{
    sortedSingle list;

    REQUIRE(list.insert(30) == true);
    REQUIRE(list.insert(120) == true);

    REQUIRE(list.size() == 2);

    REQUIRE(list.insert(30) == true);
    REQUIRE(list.insert(120) == true);
    REQUIRE(list.insert(50) == true);

    REQUIRE(list.size() == 5);
}

//Sorted singles B tests
TEST_CASE("insert")
{
    sortedSingle list;
    
    REQUIRE(list.insert(20) == true);
    REQUIRE(list.insert(40) == true);
    REQUIRE(list.insert(100) == true);

    list.print(cout);
    cout << endl;
}

TEST_CASE("print")
{
    sortedSingle list;

    REQUIRE(list.insert(40) == true);
    REQUIRE(list.insert(60) == true);
    REQUIRE(list.insert(5) == true);

    list.print(cout);
    cout << endl;
}

//Sorted singles C tests


TEST_CASE("remove")
{
    {
        sortedSingle list;

        REQUIRE(list.insert(30) == true);
        REQUIRE(list.insert(150) == true);
        REQUIRE(list.insert(40) == true);
        REQUIRE(list.insert(120) == true);
        REQUIRE(list.insert(50) == true);

        SECTION("remove - start")
        {
            list.print(cout);
            cout << endl;
            CHECK(list.remove(30) == true);
            list.print(cout);
            cout << endl;
        }
        SECTION("remove - middle")
        {
            list.print(cout);
            cout << endl;
            CHECK(list.remove(50) == true);
            list.print(cout);
            cout << endl;
        }
        SECTION("remove - end")
        {
            list.print(cout);
            cout << endl;
            CHECK(list.remove(150) == true);
            list.print(cout);
            cout << endl;
        }
    }
}

TEST_CASE("clear")
{
    sortedSingle list;

    REQUIRE(list.insert(30) == true);
    REQUIRE(list.insert(150) == true);
    REQUIRE(list.insert(40) == true);
    REQUIRE(list.insert(120) == true);
    REQUIRE(list.insert(50) == true);

    REQUIRE(list.size() == 5);

    list.clear();

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty() == true);

}

TEST_CASE("copy - list of 5")
{
    sortedSingle list;

    REQUIRE(list.insert(30) == true);
    REQUIRE(list.insert(150) == true);
    REQUIRE(list.insert(40) == true);
    REQUIRE(list.insert(120) == true);
    REQUIRE(list.insert(50) == true);

    REQUIRE(list.size() == 5);

    sortedSingle copyList(list);

    REQUIRE(copyList.size() == 5);
}

TEST_CASE("copy - list of 1")
{
    sortedSingle list;

    REQUIRE(list.insert(30) == true);

    REQUIRE(list.size() == 1);

    sortedSingle copyList(list);

    REQUIRE(copyList.size() == 1);
}

TEST_CASE("copy - list of 0")
{
    sortedSingle list;

    REQUIRE(list.size() == 0);

    sortedSingle copyList(list);

    REQUIRE(copyList.size() == 0);
}
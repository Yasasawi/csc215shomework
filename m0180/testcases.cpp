#include "sortedSingle.h"
#include "..\catch.hpp"
#include <sstream>
#include <iostream>

using namespace std;

//Sorted singles A tests
TEST_CASE("Constructor")
{
    sortedSingle<int> list;
    REQUIRE(list.empty() == true);
    REQUIRE(list.size() == 0);
}

TEST_CASE("empty")
{
    sortedSingle<int> list;
    REQUIRE(list.empty() == true);
    REQUIRE(list.insert(30));
    REQUIRE(list.insert(40));
    REQUIRE(list.insert(50));
    REQUIRE(list.empty() == false);
}

TEST_CASE("Find")
{
    sortedSingle<int> list;

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
    sortedSingle<int> list;

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
    sortedSingle<int> list;

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
    sortedSingle<int> list;
    
    REQUIRE(list.insert(20) == true);
    REQUIRE(list.insert(40) == true);
    REQUIRE(list.insert(100) == true);

    list.print(cout);
    cout << endl;
}

TEST_CASE("print")
{
    sortedSingle<int> list;

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
        sortedSingle<int> list;

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
    sortedSingle<int> list;

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
    sortedSingle<int> list;

    REQUIRE(list.insert(30) == true);
    REQUIRE(list.insert(150) == true);
    REQUIRE(list.insert(40) == true);
    REQUIRE(list.insert(120) == true);
    REQUIRE(list.insert(50) == true);

    REQUIRE(list.size() == 5);

    sortedSingle<int> copyList(list);

    REQUIRE(copyList.size() == 5);
}

TEST_CASE("copy - list of 1")
{
    sortedSingle<int> list;

    REQUIRE(list.insert(30) == true);

    REQUIRE(list.size() == 1);

    sortedSingle<int> copyList(list);

    REQUIRE(copyList.size() == 1);
}

TEST_CASE("copy - list of 0")
{
    sortedSingle<int> list;

    REQUIRE(list.size() == 0);

    sortedSingle<int> copyList(list);

    REQUIRE(copyList.size() == 0);
}

//new template function test cases
TEST_CASE("<< - outputting some random numbers")
{
    sortedSingle<char> list;

    REQUIRE(list.insert('w') == true);
    REQUIRE(list.insert('a') == true);
    REQUIRE(list.insert('b') == true);
    REQUIRE(list.insert('z') == true);
    REQUIRE(list.insert('q') == true);

    cout << list;
    cout << endl;
}

TEST_CASE("Swap")
{
    sortedSingle<int> list;
    sortedSingle<int> swapList;

    REQUIRE(list.insert(30) == true);
    REQUIRE(list.insert(120) == true);
    REQUIRE(list.insert(30) == true);
    REQUIRE(list.insert(120) == true);
    REQUIRE(list.insert(50) == true);

    list.print(cout);
    cout << endl;

    REQUIRE(swapList.insert(10) == true);
    REQUIRE(swapList.insert(30) == true);
    REQUIRE(swapList.insert(40) == true);
    REQUIRE(swapList.insert(50) == true);
    REQUIRE(swapList.insert(20) == true);
    
    swapList.print(cout);
    cout << endl;

    swapList.swap(list);

    list.print(cout);
    cout << endl;

    swapList.print(cout);
    cout << endl;


}

TEST_CASE("assignment operator")
{
    sortedSingle<int> list;
    sortedSingle<int> swapList;
    REQUIRE(list.insert(300) == true);
    REQUIRE(list.insert(600) == true);
    REQUIRE(list.insert(400) == true);
    REQUIRE(list.insert(700) == true);
    REQUIRE(list.insert(100) == true);

    swapList = list; 

    cout << "first list" << endl;
    list.print(cout);
    cout << endl;

    cout << "second list" << endl; 
    swapList.print(cout);
    cout << endl;



}

TEST_CASE("equals operator - same lists")
{
    bool same = false;
    sortedSingle<int> list;
    sortedSingle<int> swapList;
    REQUIRE(list.insert(300) == true);
    REQUIRE(list.insert(600) == true);
    REQUIRE(list.insert(400) == true);
    REQUIRE(list.insert(700) == true);
    REQUIRE(list.insert(100) == true);

    REQUIRE(swapList.insert(300) == true);
    REQUIRE(swapList.insert(600) == true);
    REQUIRE(swapList.insert(400) == true);
    REQUIRE(swapList.insert(700) == true);
    REQUIRE(swapList.insert(100) == true);

    if (swapList == list)
    {
        same = true;
    }
    else
    {
        same = false;
    }

    REQUIRE(same == true);

}

TEST_CASE("equals operator - different lists")
{
    bool same = false;
    sortedSingle<int> list;
    sortedSingle<int> swapList;
    REQUIRE(list.insert(300) == true);
    REQUIRE(list.insert(600) == true);
    REQUIRE(list.insert(400) == true);
    REQUIRE(list.insert(700) == true);

    REQUIRE(swapList.insert(300) == true);
    REQUIRE(swapList.insert(600) == true);
    REQUIRE(swapList.insert(400) == true);
    REQUIRE(swapList.insert(700) == true);
    REQUIRE(swapList.insert(100) == true);

    if (swapList == list)
    {
        same = true;
    }
    else
    {
        same = false;
    }

    REQUIRE(same == false);

}

TEST_CASE("equals operator - same numbers different sizes")
{
    bool same = false;
    sortedSingle<int> list;
    sortedSingle<int> swapList;
    REQUIRE(list.insert(400) == true);
    REQUIRE(list.insert(400) == true);
    REQUIRE(list.insert(400) == true);
    REQUIRE(list.insert(400) == true);

    REQUIRE(swapList.insert(400) == true);
    REQUIRE(swapList.insert(400) == true);
    REQUIRE(swapList.insert(400) == true);
    REQUIRE(swapList.insert(400) == true);
    REQUIRE(swapList.insert(400) == true);

    if (swapList == list)
    {
        same = true;
    }
    else
    {
        same = false;
    }

    REQUIRE(same == false);

}

TEST_CASE("not equals operator - the same list")
{
    bool notSame = false;
    sortedSingle<int> list;
    sortedSingle<int> swapList;
    REQUIRE(list.insert(300) == true);
    REQUIRE(list.insert(600) == true);
    REQUIRE(list.insert(400) == true);
    REQUIRE(list.insert(700) == true);
    REQUIRE(list.insert(100) == true);

    REQUIRE(swapList.insert(300) == true);
    REQUIRE(swapList.insert(600) == true);
    REQUIRE(swapList.insert(400) == true);
    REQUIRE(swapList.insert(700) == true);
    REQUIRE(swapList.insert(100) == true);

    if (swapList != list)
    {
        notSame = true;
    }
    else
    {
        notSame = false;
    }

    REQUIRE(notSame == false);

}

TEST_CASE("not equals operator - different list")
{
    bool notSame = false;
    sortedSingle<int> list;
    sortedSingle<int> swapList;
    REQUIRE(list.insert(300) == true);
    REQUIRE(list.insert(600) == true);
    REQUIRE(list.insert(200) == true);
    REQUIRE(list.insert(400) == true);
    REQUIRE(list.insert(100) == true);

    REQUIRE(swapList.insert(300) == true);
    REQUIRE(swapList.insert(600) == true);
    REQUIRE(swapList.insert(400) == true);
    REQUIRE(swapList.insert(100) == true);
    REQUIRE(swapList.insert(1000) == true);


    if (swapList != list)
    {
        notSame = true;
    }
    else
    {
        notSame = false;
    }

    REQUIRE(notSame == true);

}

TEST_CASE("not equals operator - same numbers different sizes")
{
    bool same = false;
    sortedSingle<int> list;
    sortedSingle<int> swapList;
    REQUIRE(list.insert(400) == true);
    REQUIRE(list.insert(400) == true);
    REQUIRE(list.insert(400) == true);
    REQUIRE(list.insert(400) == true);

    REQUIRE(swapList.insert(400) == true);
    REQUIRE(swapList.insert(400) == true);
    REQUIRE(swapList.insert(400) == true);
    REQUIRE(swapList.insert(400) == true);
    REQUIRE(swapList.insert(400) == true);

    if (swapList != list)
    {
        same = true;
    }
    else
    {
        same = false;
    }

    REQUIRE(same == true);

}
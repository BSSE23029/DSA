#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h" 
#include <iostream>
#include <sstream>
using namespace std;

TEST_CASE("Bubble Sort test", "[bubble]") {
    List myList;
    myList.append(5);
    myList.append(3);
    myList.append(7);
    myList.append(1);
    myList.append(4);

    myList.bubbleSort();
    REQUIRE(myList.getIndexData(0)==1);
    REQUIRE(myList.getIndexData(1)==3);
    REQUIRE(myList.getIndexData(2)==4);
    REQUIRE(myList.getIndexData(3)==5);
    REQUIRE(myList.getIndexData(4)==7);
}

TEST_CASE("Merge Sort test", "[merge]") {
    List *myList = new List;
    myList->append(5);
    myList->append(3);
    myList->append(7);
    myList->append(1);
    myList->append(4);

    myList->mergeSort();
    REQUIRE(myList->getIndexData(0)==1);
    REQUIRE(myList->getIndexData(1)==3);
    REQUIRE(myList->getIndexData(2)==4);
    REQUIRE(myList->getIndexData(3)==5);
    REQUIRE(myList->getIndexData(4)==7);

    delete myList;
}


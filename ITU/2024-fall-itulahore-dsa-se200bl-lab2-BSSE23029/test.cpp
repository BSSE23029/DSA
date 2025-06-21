#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h" 
#include <iostream>
#include <sstream>
using namespace std;


TEST_CASE("Array initialization test", "[initialization]") {
    MyArray<int> arr;

    REQUIRE(arr.getArray() != nullptr);
    REQUIRE(arr.getRowSize() == 5);
    for (int i = 0; i < arr.getRowSize(); i++) {
        REQUIRE(arr.getColSize(i) == 0);
    }
}

TEST_CASE("Append function test", "[append]") {
    MyArray<int> arr;
    arr.append(20, 0);
    arr.append(10, 0);

    REQUIRE(arr.getColSize(0) == 2);
    REQUIRE(arr.getArray()[0][0] == 20);
    REQUIRE(arr.getArray()[0][1] == 10);
}

TEST_CASE("Prepend function test", "[prepend]") {
    MyArray<int> arr;
    arr.prepend(30, 1);
    arr.prepend(25, 1);

    REQUIRE(arr.getColSize(1) == 2);
    REQUIRE(arr.getArray()[1][0] == 25);
    REQUIRE(arr.getArray()[1][1] == 30);
}

TEST_CASE("Delete from last function test", "[delete_from_last]") {
    MyArray<int> arr;
    arr.prepend(30, 1);
    arr.prepend(25, 1);

    REQUIRE(arr.getColSize(1) == 2);
    REQUIRE(arr.getArray()[1][0] == 25);
    REQUIRE(arr.getArray()[1][1] == 30);

    arr.delete_from_last(1);
    REQUIRE(arr.getColSize(1) == 1);
    REQUIRE(arr.getArray()[1][0] == 25);
}

TEST_CASE("Delete from start function test", "[delete_from_start]") {
    MyArray<int> arr;
    arr.prepend(30, 1);
    arr.prepend(25, 1);

    REQUIRE(arr.getColSize(1) == 2);
    REQUIRE(arr.getArray()[1][0] == 25);
    REQUIRE(arr.getArray()[1][1] == 30);

    arr.delete_from_start(1);
    REQUIRE(arr.getColSize(1) == 1);
    REQUIRE(arr.getArray()[1][0] == 30);
}

TEST_CASE("Bubble Sort function test", "[bubbleSort]") {
    MyArray<int> arr;
    arr.append(30, 1);
    arr.append(10, 1);
    arr.append(20, 1);
    arr.bubbleSort(1);

    REQUIRE(arr.getArray()[1][0] == 10);
    REQUIRE(arr.getArray()[1][1] == 20);
    REQUIRE(arr.getArray()[1][2] == 30);
}

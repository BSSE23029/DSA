#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h" 
#include <iostream>
#include <sstream>
using namespace std;

TEST_CASE("Array initialization test", "[initialization]") {
    MyArray <int> arr;

    // Check if the array is not null
    REQUIRE(arr.get_array() != nullptr);
    REQUIRE(arr.get_size() == 0);
}

TEST_CASE("Append function test", "[append]") {
    MyArray <int> arr;

    arr.append(1);
    arr.append(2);
    arr.append(3);

    REQUIRE(arr.get_size() == 3);
    REQUIRE(arr.get_array()[0] == 1);
    REQUIRE(arr.get_array()[1] == 2);
    REQUIRE(arr.get_array()[2] == 3);
}

TEST_CASE("Prepend function test", "[prepend]") {
    MyArray <int> arr;

    arr.append(1);
    arr.append(2);
    arr.prepend(0);

    REQUIRE(arr.get_size() == 3);
    REQUIRE(arr.get_array()[0] == 0);
    REQUIRE(arr.get_array()[1] == 1);
    REQUIRE(arr.get_array()[2] == 2);
}

TEST_CASE("Delete from end test", "[delete_end]") {
    MyArray <int> arr;

    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.delete_at_End();

    REQUIRE(arr.get_size() == 2);
    REQUIRE(arr.get_array()[0] == 1);
    REQUIRE(arr.get_array()[1] == 2);
}

TEST_CASE("Delete from start test", "[delete_start]") {
    MyArray <int> arr;

    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.delete_at_Start();

    REQUIRE(arr.get_size() == 2);
    REQUIRE(arr.get_array()[0] == 2);
    REQUIRE(arr.get_array()[1] == 3);
}



#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h" 
#include <iostream>
#include <sstream>
using namespace std;


TEST_CASE("Array element set and get test", "[initialization]") {
    MyArray<int> array(3, 2, 2); // 3 columns, 2 rows, 2 layers

    array.setElement(2, 0, 0, 0);
    array.setElement(1, 1, 0, 0);
    array.setElement(5, 2, 0, 0);

    array.setElement(3, 0, 1, 0);
    array.setElement(4, 1, 1, 0);
    array.setElement(1, 2, 1, 0);

    array.setElement(5, 0, 0, 1);
    array.setElement(8, 1, 0, 1);
    array.setElement(2, 2, 0, 1);

    array.setElement(6, 0, 1, 1);
    array.setElement(7, 1, 1, 1);
    array.setElement(5, 2, 1, 1);

    REQUIRE(array.getElement(0, 0, 0) == 2);
    REQUIRE(array.getElement(1, 0, 0) == 1);
    REQUIRE(array.getElement(2, 0, 0) == 5);

    REQUIRE(array.getElement(0, 1, 0) == 3);
    REQUIRE(array.getElement(1, 1, 0) == 4);
    REQUIRE(array.getElement(2, 1, 0) == 1);

    REQUIRE(array.getElement(0, 0, 1) == 5);
    REQUIRE(array.getElement(1, 0, 1) == 8);
    REQUIRE(array.getElement(2, 0, 1) == 2);

    REQUIRE(array.getElement(0, 1, 1) == 6);
    REQUIRE(array.getElement(1, 1, 1) == 7);
    REQUIRE(array.getElement(2, 1, 1) == 5);
    
}

TEST_CASE("Count sort test", "[Count_sort]") {
    MyArray<int> array(3, 2, 2); // 3 columns, 2 rows, 2 layers

    array.setElement(2, 0, 0, 0);
    array.setElement(1, 1, 0, 0);
    array.setElement(5, 2, 0, 0);

    array.setElement(3, 0, 1, 0);
    array.setElement(4, 1, 1, 0);
    array.setElement(1, 2, 1, 0);

    array.setElement(5, 0, 0, 1);
    array.setElement(8, 1, 0, 1);
    array.setElement(2, 2, 0, 1);

    array.setElement(6, 0, 1, 1);
    array.setElement(7, 1, 1, 1);
    array.setElement(5, 2, 1, 1);

    array.countSort3D();

    int* arr = array.getRow3D(0, 0); //row , layer
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 2);
    REQUIRE(arr[2] == 5);

    arr = array.getRow3D(1, 0); //row , layer
    REQUIRE(arr[0] == 1);
    REQUIRE(arr[1] == 3);
    REQUIRE(arr[2] == 4);

    arr = array.getRow3D(0, 1); //row , layer
    REQUIRE(arr[0] == 2);
    REQUIRE(arr[1] == 5);
    REQUIRE(arr[2] == 8);

    arr = array.getRow3D(1, 1); //row , layer
    REQUIRE(arr[0] == 5);
    REQUIRE(arr[1] == 6);
    REQUIRE(arr[2] == 7);
    
}

TEST_CASE("radix sort test", "[Radix_sort]") {
    MyArray<int> array(3, 2, 2); // 3 columns, 2 rows, 2 layers

    array.setElement(22, 0, 0, 0);
    array.setElement(14, 1, 0, 0);
    array.setElement(57, 2, 0, 0);

    array.setElement(39, 0, 1, 0);
    array.setElement(423, 1, 1, 0);
    array.setElement(103, 2, 1, 0);

    array.setElement(55, 0, 0, 1);
    array.setElement(867, 1, 0, 1);
    array.setElement(22, 2, 0, 1);

    array.setElement(631, 0, 1, 1);
    array.setElement(70, 1, 1, 1);
    array.setElement(534, 2, 1, 1);

    array.radixSort3D();

    int* arr = array.getRow3D(0, 0); //row , layer
    REQUIRE(arr[0] == 14);
    REQUIRE(arr[1] == 22);
    REQUIRE(arr[2] == 57);

    arr = array.getRow3D(1, 0); //row , layer
    REQUIRE(arr[0] == 39);
    REQUIRE(arr[1] == 103);
    REQUIRE(arr[2] == 423);

    arr = array.getRow3D(0, 1); //row , layer
    REQUIRE(arr[0] == 22);
    REQUIRE(arr[1] == 55);
    REQUIRE(arr[2] == 867);

    arr = array.getRow3D(1, 1); //row , layer
    REQUIRE(arr[0] == 70);
    REQUIRE(arr[1] == 534);
    REQUIRE(arr[2] == 631);
    
}
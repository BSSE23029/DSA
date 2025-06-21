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

TEST_CASE("Insertion sort test", "[Insertion_sort]") {
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

    array.insertionSort3D();

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

TEST_CASE("Selection sort test", "[Selection_sort]") {
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

    array.selectionSort3D();

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

TEST_CASE("Merge sort test", "[Merge_sort]") {
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

    array.mergeSort3D();

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



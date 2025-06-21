#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h"
#include <iostream>
#include <sstream>
using namespace std;


TEST_CASE("Heap Sort basic functionality test", "[HeapSort][sort]") {
    MyArray myArray(5);
    
    myArray.setAtIndex(0,34);
    myArray.setAtIndex(1,7);
    myArray.setAtIndex(2,23);
    myArray.setAtIndex(3,32);
    myArray.setAtIndex(4,5);
    
    myArray.heapSort(); // Perform heap sort

    // Check if the array is sorted using getAtIndex
    REQUIRE(myArray.getAtIndex(0) == 5);
    REQUIRE(myArray.getAtIndex(1) == 7);
    REQUIRE(myArray.getAtIndex(2) == 23);
    REQUIRE(myArray.getAtIndex(3) == 32);
    REQUIRE(myArray.getAtIndex(4) == 34);
}


TEST_CASE("Heap Sort with reverse sorted array", "[HeapSort][sort]") {
    MyArray myArray(5);
    
    myArray.setAtIndex(0,5);
    myArray.setAtIndex(1,4);
    myArray.setAtIndex(2,3);
    myArray.setAtIndex(3,2);
    myArray.setAtIndex(4,1);

    myArray.heapSort(); // Perform heap sort

    // Verify the array is sorted
    REQUIRE(myArray.getAtIndex(0) == 1);
    REQUIRE(myArray.getAtIndex(1) == 2);
    REQUIRE(myArray.getAtIndex(2) == 3);
    REQUIRE(myArray.getAtIndex(3) == 4);
    REQUIRE(myArray.getAtIndex(4) == 5);
}

TEST_CASE("Heap Sort with duplicate values", "[HeapSort][sort]") {
    MyArray myArray(6);
    
    myArray.setAtIndex(0,4);
    myArray.setAtIndex(1,3);
    myArray.setAtIndex(2,2);
    myArray.setAtIndex(3,1);
    myArray.setAtIndex(4,4);
    myArray.setAtIndex(5,1);

    myArray.heapSort(); // Perform heap sort

    // Verify the array is sorted
    REQUIRE(myArray.getAtIndex(0) == 1);
    REQUIRE(myArray.getAtIndex(1) == 1);
    REQUIRE(myArray.getAtIndex(2) == 2);
    REQUIRE(myArray.getAtIndex(3) == 3);
    REQUIRE(myArray.getAtIndex(4) == 4);
    REQUIRE(myArray.getAtIndex(5) == 4);
}

TEST_CASE("Heap Sort with single element", "[HeapSort][sort]") {
    MyArray myArray(1);
    
    myArray.setAtIndex(0,42);

    myArray.heapSort(); // Perform heap sort

    // Verify the array remains the same
    REQUIRE(myArray.getAtIndex(0) == 42);
}

TEST_CASE("Heap Sort with empty array", "[HeapSort][sort]") {
    MyArray myArray(0); // Create an empty array

    myArray.heapSort(); // Perform heap sort on empty array

    // Verify the array remains empty
    REQUIRE(myArray.getSize() == 0);
}


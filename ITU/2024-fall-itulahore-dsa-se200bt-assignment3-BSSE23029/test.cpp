#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions.h"
#include <iostream>
using namespace std;

TEST_CASE("Determinant of 2D Array", "det 2D") {
    MyArray<int>* array = MyArray<int>::create(4, 4);

    array->setElement(7, 0, 0);
    array->setElement(2, 0, 1);
    array->setElement(4, 0, 2);
    array->setElement(8, 0, 3);
    array->setElement(11, 1, 0);
    array->setElement(0, 1, 1);
    array->setElement(21, 1, 2);
    array->setElement(5, 1, 3);
    array->setElement(3, 2, 0);
    array->setElement(3, 2, 1);
    array->setElement(9, 2, 2);
    array->setElement(6, 2, 3);
    array->setElement(6, 3, 0);
    array->setElement(7, 3, 1);
    array->setElement(1, 3, 2);
    array->setElement(8, 3, 3);

    int* result = array->getDeterminant();

    REQUIRE(*result == 3144);

    delete array;
}

TEST_CASE("Inverse of 2D Array", "inv 2D") {
    MyArray<int>* array = MyArray<int>::create(3, 3);

    array->setElement(1, 0, 0);
    array->setElement(2, 0, 1);
    array->setElement(3, 0, 2);
    array->setElement(0, 1, 0);
    array->setElement(1, 1, 1);
    array->setElement(4, 1, 2);
    array->setElement(5, 2, 0);
    array->setElement(6, 2, 1);
    array->setElement(0, 2, 2);

    MyArray<int>* result = array->getInverse();

    REQUIRE(result->getElement(0,0) == -24);
    REQUIRE(result->getElement(0,1) == 18);
    REQUIRE(result->getElement(0,2) == 5);

    REQUIRE(result->getElement(1,0) == 20);
    REQUIRE(result->getElement(1,1) == -15);
    REQUIRE(result->getElement(1,2) == -4);

    REQUIRE(result->getElement(2,0) == -5);
    REQUIRE(result->getElement(2,1) == 4);
    REQUIRE(result->getElement(2,2) == 1);
    delete array;
    delete result;
}

TEST_CASE("Quick Sort 1D", "[quick sort1D]") {
    MyArray<int>* array1 = MyArray<int>::create(5);

    array1->setElement(5, 0);
    array1->setElement(1, 1);
    array1->setElement(-7, 2);
    array1->setElement(10, 3);
    array1->setElement(2, 4);


    array1->quickSort('x');

    REQUIRE(array1->getElement(0) == -7);
    REQUIRE(array1->getElement(1) == 1);
    REQUIRE(array1->getElement(2) == 2);
    REQUIRE(array1->getElement(3) == 5);
    REQUIRE(array1->getElement(4) == 10);

    delete array1;
}
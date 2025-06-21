#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions.h"
#include <iostream>
using namespace std;


TEST_CASE("Set and Get elements for 1D array", "[set][get]") {
    MyArray<int>* array = MyArray<int>::create(3);

    array->setElement(10, 0);
    array->setElement(20, 1);
    array->setElement(30, 2);

    REQUIRE(array->getElement(0) == 10);
    REQUIRE(array->getElement(1) == 20);
    REQUIRE(array->getElement(2) == 30);

    delete array;
}

TEST_CASE("Set and Get elements for 2D array", "[set][get]") {
    MyArray<int>* array = MyArray<int>::create(2, 2);

    array->setElement(1, 0, 0);
    array->setElement(2, 0, 1);
    array->setElement(3, 1, 0);
    array->setElement(4, 1, 1);

    REQUIRE(array->getElement(0, 0) == 1);
    REQUIRE(array->getElement(0, 1) == 2);
    REQUIRE(array->getElement(1, 0) == 3);
    REQUIRE(array->getElement(1, 1) == 4);

    delete array;
}

TEST_CASE("Set and Get elements for 3D array", "[set][get]") {
    MyArray<int>* array = MyArray<int>::create(2, 2, 2);

    array->setElement(1, 0, 0, 0);
    array->setElement(2, 0, 1, 0);
    array->setElement(3, 1, 0, 0);
    array->setElement(4, 1, 1, 0);
    array->setElement(5, 0, 0, 1);
    array->setElement(6, 0, 1, 1);
    array->setElement(7, 1, 0, 1);
    array->setElement(8, 1, 1, 1);

    REQUIRE(array->getElement(0, 0, 0) == 1);
    REQUIRE(array->getElement(0, 1, 0) == 2);
    REQUIRE(array->getElement(1, 0, 0) == 3);
    REQUIRE(array->getElement(1, 1, 0) == 4);
    REQUIRE(array->getElement(0, 0, 1) == 5);
    REQUIRE(array->getElement(0, 1, 1) == 6);
    REQUIRE(array->getElement(1, 0, 1) == 7);
    REQUIRE(array->getElement(1, 1, 1) == 8);
    REQUIRE(array->getElement(1, 2, 1) == int{});

    delete array;
}


TEST_CASE("Sum of elements for different arrays", "[sumElements]") {
    MyArray<int>* array1 = MyArray<int>::create(3);
    array1->setElement(1, 0);
    array1->setElement(2, 1);
    array1->setElement(3, 2);

    MyArray<int>* array2 = MyArray<int>::create(2, 2);
    array2->setElement(1, 0, 0);
    array2->setElement(2, 0, 1);
    array2->setElement(3, 1, 0);
    array2->setElement(4, 1, 1);

    REQUIRE(array1->sumElements() == 6);
    REQUIRE(array2->sumElements() == 10);

    delete array1;
    delete array2;
}

TEST_CASE("Add two arrays", "[sum]") {
    MyArray<int>* array1 = MyArray<int>::create(2, 2);
    MyArray<int>* array2 = MyArray<int>::create(2, 2);

    array1->setElement(1, 0, 0);
    array1->setElement(2, 0, 1);
    array1->setElement(3, 1, 0);
    array1->setElement(4, 1, 1);

    array2->setElement(5, 0, 0);
    array2->setElement(6, 0, 1);
    array2->setElement(7, 1, 0);
    array2->setElement(8, 1, 1);

    MyArray<int>* result = array1->sum(*array2);

    REQUIRE(result->getElement(0, 0) == 6);
    REQUIRE(result->getElement(0, 1) == 8);
    REQUIRE(result->getElement(1, 0) == 10);
    REQUIRE(result->getElement(1, 1) == 12);

    delete array1;
    delete array2;
    delete result;
}

TEST_CASE("Transpose of 2D array", "[transpose]") {
    MyArray<int>* array = MyArray<int>::create(2, 3);

    array->setElement(1, 0, 0);
    array->setElement(2, 0, 1);
    array->setElement(3, 0, 2);
    array->setElement(4, 1, 0);
    array->setElement(5, 1, 1);
    array->setElement(6, 1, 2);

    MyArray<int>* transposed = array->getTranspose();

    REQUIRE(transposed->getElement(0, 0) == 1);
    REQUIRE(transposed->getElement(0, 1) == 4);
    REQUIRE(transposed->getElement(1, 0) == 2);
    REQUIRE(transposed->getElement(1, 1) == 5);
    REQUIRE(transposed->getElement(2, 0) == 3);
    REQUIRE(transposed->getElement(2, 1) == 6);

    delete array;
    delete transposed;
}

TEST_CASE("Multiply 1D arrays (dot product)", "[multiply]") {
    MyArray<int>* array1 = MyArray<int>::create(3);
    MyArray<int>* array2 = MyArray<int>::create(3);

    array1->setElement(1, 0);
    array1->setElement(2, 1);
    array1->setElement(3, 2);

    array2->setElement(4, 0);
    array2->setElement(5, 1);
    array2->setElement(6, 2);

    MyArray<int>* result = array1->multiply(*array2);

    REQUIRE(result->getElement(0) == 32);  // 1*4 + 2*5 + 3*6

    delete array1;
    delete array2;
    delete result;
}

TEST_CASE("Multiply 2D arrays (matrix multiplication)", "[multiply]") {
    MyArray<int>* array1 = MyArray<int>::create(2, 3);
    MyArray<int>* array2 = MyArray<int>::create(3, 2);

    array1->setElement(1, 0, 0);
    array1->setElement(2, 0, 1);
    array1->setElement(3, 0, 2);
    array1->setElement(4, 1, 0);
    array1->setElement(5, 1, 1);
    array1->setElement(6, 1, 2);

    array2->setElement(7, 0, 0);
    array2->setElement(8, 0, 1);
    array2->setElement(9, 1, 0);
    array2->setElement(10, 1, 1);
    array2->setElement(11, 2, 0);
    array2->setElement(12, 2, 1);

    MyArray<int>* result = array1->multiply(*array2);

    REQUIRE(result->getElement(0, 0) == 58);
    REQUIRE(result->getElement(0, 1) == 64);
    REQUIRE(result->getElement(1, 0) == 139);
    REQUIRE(result->getElement(1, 1) == 154);

    delete array1;
    delete array2;
    delete result;
}
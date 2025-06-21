#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "MyArray.h"
using namespace std;

TEST_CASE("Task 1: Insert At Index") {
    MyArray<int> array(5);  

    array.insertAtIndex(10, 0);
    array.insertAtIndex(5, 1);
    array.insertAtIndex(1, 2);
    array.insertAtIndex(7, 3);
    array.insertAtIndex(9, 4);
    array.insertAtIndex(4, 2);

    REQUIRE(array[0] == 10);
    REQUIRE(array[1] == 5);
    REQUIRE(array[2] == 4);
    REQUIRE(array[3] == 1);
    REQUIRE(array[4] == 7);
    REQUIRE(array[5] == 9);
}

TEST_CASE("Task 2: Remove At Index") {
    MyArray<int> array(5);
    array.insertAtIndex(10, 0);
    array.insertAtIndex(5, 1);
    array.insertAtIndex(1, 2);
    array.insertAtIndex(7, 3);
    array.insertAtIndex(9, 4);

    array.removeAtIndex(2);  

    REQUIRE(array[0] == 10);
    REQUIRE(array[1] == 5);
    REQUIRE(array[2] == 7);
    REQUIRE(array[3] == 9);
}

TEST_CASE("Task 3: Sort Array") {
    MyArray<int> array(5);
    array.insertAtIndex(10, 0);
    array.insertAtIndex(5, 1);
    array.insertAtIndex(7, 2);
    array.insertAtIndex(9, 3);
    array.insertAtIndex(1, 4);

    array.sortArray(true); // ascending order
    REQUIRE(array[0] == 1);
    REQUIRE(array[1] == 5);
    REQUIRE(array[2] == 7);
    REQUIRE(array[3] == 9);
    REQUIRE(array[4] == 10);

    array.sortArray(false); // descending order
    REQUIRE(array[0] == 10);
    REQUIRE(array[1] == 9);
    REQUIRE(array[2] == 7);
    REQUIRE(array[3] == 5);
    REQUIRE(array[4] == 1);
}

TEST_CASE("Task 4: Display Array") {
    MyArray<int> array(5);
    array.insertAtIndex(10, 0);
    array.insertAtIndex(5, 1);
    array.insertAtIndex(7, 2);
    array.insertAtIndex(9, 3);
    array.insertAtIndex(1, 4);

    stringstream ss;
    streambuf* oldCoutBuffer = cout.rdbuf(ss.rdbuf()); // Redirect cout to stringstream
    array.display();
    cout.rdbuf(oldCoutBuffer); // Restore cout

    string output = ss.str();
    REQUIRE(output == "10 5 7 9 1 \n"); // Expected output format
}

TEST_CASE("Task 5: Unique Elements") {
    MyArray<int> array(8);
    array.insertAtIndex(10, 0);
    array.insertAtIndex(5, 1);
    array.insertAtIndex(7, 2);
    array.insertAtIndex(5, 3);
    array.insertAtIndex(1, 4);
    array.insertAtIndex(7, 5);
    array.insertAtIndex(9, 6);
    array.insertAtIndex(10, 7);

    array.uniqueElements();

    REQUIRE(array.get_size() == 5);
    REQUIRE(array[0] == 10);
    REQUIRE(array[1] == 5);
    REQUIRE(array[2] == 7);
    REQUIRE(array[3] == 1);
    REQUIRE(array[4] == 9);
}

TEST_CASE("Task 6: Menu Operations") {
    MyArray<int> array(5);

    array.insertAtIndex(10, 0);
    array.insertAtIndex(5, 1);
    array.insertAtIndex(1, 2);

    REQUIRE(array[0] == 10);
    REQUIRE(array[1] == 5);
    REQUIRE(array[2] == 1);

    array.removeAtIndex(1);
    REQUIRE(array[0] == 10);
    REQUIRE(array[1] == 1);

    array.sortArray(true);
    REQUIRE(array[0] == 1);
    REQUIRE(array[1] == 10);

    array.uniqueElements();
    REQUIRE(array[0] == 1);
    REQUIRE(array[1] == 10);
}

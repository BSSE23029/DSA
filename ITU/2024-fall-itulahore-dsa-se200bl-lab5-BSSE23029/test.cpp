#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h" 
#include <iostream>
#include <sstream>
using namespace std;

TEST_CASE("Test if list is initially empty", "[isEmpty]") {
    List myList;

    // Check if the list is empty on initialization
    REQUIRE(myList.isEmpty() == true);
}

TEST_CASE("Append function test", "[append]") {
    List myList;

    // Append elements to the list
    myList.append(10);
    myList.append(20);
    myList.append(30);

    // Ensure the list is not empty
    REQUIRE(myList.isEmpty() == false);

    // Check head and tail data
    REQUIRE(myList.getHead()->getData() == 10);  // Head should be 10
    REQUIRE(myList.getTail()->getData() == 30);  // Tail should be 30
}

TEST_CASE("Prepend function test", "[prepend]") {
    List myList;

    // Prepend elements to the list
    myList.prepend(10);
    myList.prepend(20);
    myList.prepend(30);

    // Ensure the list is not empty
    REQUIRE(myList.isEmpty() == false);

    // Check head and tail data
    REQUIRE(myList.getHead()->getData() == 30);  // Head should be 30
    REQUIRE(myList.getTail()->getData() == 10);  // Tail should be 10
}

TEST_CASE("Insert at Index function test", "[insertAtIndex]") {
    List myList;

    // Append elements to have a base list
    myList.append(10);
    myList.append(30);
    myList.append(50);

    // Insert 20 at index 1
    myList.insertAtIndex(20, 1);

    // Insert 40 at index 3
    myList.insertAtIndex(40, 3);

    // Check the head and tail after the insertions
    REQUIRE(myList.getHead()->getData() == 10);
    REQUIRE(myList.getTail()->getData() == 50);

    // Traverse and check data at specific indices
    Node* current = myList.getHead();
    REQUIRE(current->getData() == 10);  // Index 0
    current = current->getNext();
    REQUIRE(current->getData() == 20);  // Index 1
    current = current->getNext();
    REQUIRE(current->getData() == 30);  // Index 2
    current = current->getNext();
    REQUIRE(current->getData() == 40);  // Index 3
    current = current->getNext();
    REQUIRE(current->getData() == 50);  // Index 4
}

TEST_CASE("Delete from End test", "[deleteFromEnd]") {
    List myList;

    // Append elements to the list
    myList.append(10);
    myList.append(20);
    myList.append(30);

    // Delete the last element
    myList.deleteFromEnd();
    REQUIRE(myList.getTail()->getData() == 20);  // Tail should now be 20

    // Delete the last element again
    myList.deleteFromEnd();
    REQUIRE(myList.getTail()->getData() == 10);  // Tail should now be 10

    // Delete the last remaining element
    myList.deleteFromEnd();
    REQUIRE(myList.isEmpty() == true);  // The list should now be empty
}

TEST_CASE("Delete from Start test", "[deleteFromStart]") {
    List myList;

    // Append elements to the list
    myList.append(10);
    myList.append(20);
    myList.append(30);

    // Delete the first element
    myList.deleteFromStart();
    REQUIRE(myList.getHead()->getData() == 20);  // Head should now be 20

    // Delete the first element again
    myList.deleteFromStart();
    REQUIRE(myList.getHead()->getData() == 30);  // Head should now be 30

    // Delete the last remaining element
    myList.deleteFromStart();
    REQUIRE(myList.isEmpty() == true);  // The list should now be empty
}

TEST_CASE("Delete from Index function test", "[deleteFromIndex]") {
    List myList;

    // Append elements to the list
    myList.append(10);
    myList.append(20);
    myList.append(30);
    myList.append(40);
    myList.append(50);

    // Delete element at index 2 (which is 30)
    myList.deleteFromIndex(2);
    REQUIRE(myList.getHead()->getNext()->getNext()->getData() == 40);  // The 3rd element should now be 40

    // Delete element at index 0 (head)
    myList.deleteFromIndex(0);
    REQUIRE(myList.getHead()->getData() == 20);  // The head should now be 20

    // Delete element at index 2 (tail)
    myList.deleteFromIndex(2);
    REQUIRE(myList.getTail()->getData() == 40);  // The tail should now be 40
}

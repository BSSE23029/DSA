#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h"
#include <iostream>
#include <sstream>
using namespace std;

TEST_CASE("Test if stack is initially empty", "[isEmpty]") {
    Stack myStack;

    // Check if the stack is empty on initialization
    REQUIRE(myStack.isEmpty() == true);
}

TEST_CASE("Push function test", "[push]") {
    Stack myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Ensure the stack is not empty
    REQUIRE(myStack.isEmpty() == false);

    // Check the top data
    REQUIRE(myStack.peek() == 30);  // Top should be 30
}

TEST_CASE("Pop function test", "[pop]") {
    Stack myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Pop the top element
    myStack.pop();
    REQUIRE(myStack.peek() == 20);  // Top should now be 20
    REQUIRE(myStack.size() == 2);   // Size should be 2

    // Pop the next element
    myStack.pop();
    REQUIRE(myStack.peek() == 10);  // Top should now be 10
    REQUIRE(myStack.size() == 1);   // Size should be 1

    // Pop the last element
    myStack.pop();
    REQUIRE(myStack.isEmpty() == true);  // Stack should now be empty
}

TEST_CASE("Peek function test", "[peek]") {
    Stack myStack;

    // Push elements onto the stack
    myStack.push(10);

    // Peek at the top element
    REQUIRE(myStack.peek() == 10);

    // Push another element
    myStack.push(20);
    REQUIRE(myStack.peek() == 20);  // Top should now be 20

    // Pop the top element
    myStack.pop();
    REQUIRE(myStack.peek() == 10);  // Top should now be 10
}

TEST_CASE("Size function test", "[size]") {
    Stack myStack;

    // Initially size should be 0
    REQUIRE(myStack.size() == 0);

    // Push elements onto the stack
    myStack.push(10);
    REQUIRE(myStack.size() == 1);

    myStack.push(20);
    REQUIRE(myStack.size() == 2);

    myStack.push(30);
    REQUIRE(myStack.size() == 3);

    // Pop an element
    myStack.pop();
    REQUIRE(myStack.size() == 2);

    // Clear the stack
    myStack.clear();
    REQUIRE(myStack.size() == 0);
}

TEST_CASE("Clear function test", "[clear]") {
    Stack myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Clear the stack
    myStack.clear();

    // Ensure the stack is empty
    REQUIRE(myStack.isEmpty() == true);
    REQUIRE(myStack.size() == 0);
}

TEST_CASE("Pop from empty stack test", "[pop]") {
    Stack myStack;

    // Attempt to pop from an empty stack
    myStack.pop(); // Should handle underflow gracefully

    // Ensure the stack is still empty
    REQUIRE(myStack.isEmpty() == true);
}

TEST_CASE("Peek from empty stack test", "[peek]") {
    Stack myStack;

    // Attempt to peek at an empty stack
    int topValue = myStack.peek();

    // Since peek returns -1 when the stack is empty
    REQUIRE(topValue == -1);
}



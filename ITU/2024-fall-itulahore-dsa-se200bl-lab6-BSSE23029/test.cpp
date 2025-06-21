#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h"
#include <iostream>
#include <sstream>
using namespace std;

TEST_CASE("Test if stack is initially empty", "[Stack][isEmpty]") {
    Stack myStack;

    // Check if the stack is empty on initialization
    REQUIRE(myStack.isEmpty() == true);
}

TEST_CASE("Stack push function test", "[Stack][push]") {
    Stack myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Ensure the stack is not empty
    REQUIRE(myStack.isEmpty() == false);

    // Check the size of the stack
    REQUIRE(myStack.getSize() == 3);

    // Get the stack array
    int* stackArray = myStack.getStack();

    // Expected stack content: 30, 20, 10
    REQUIRE(stackArray[0] == 30);
    REQUIRE(stackArray[1] == 20);
    REQUIRE(stackArray[2] == 10);
}

TEST_CASE("Stack pop function test", "[Stack][pop]") {
    Stack myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);

    // Pop an element
    myStack.pop();

    // Check the size of the stack
    REQUIRE(myStack.getSize() == 1);

    // Get the stack array
    int* stackArray = myStack.getStack();

    // Expected stack content: 10
    REQUIRE(stackArray[0] == 10);
}

TEST_CASE("Test if queue is initially empty", "[Queue][isEmpty]") {
    Queue myQueue;

    // Check if the queue is empty on initialization
    REQUIRE(myQueue.isEmpty() == true);
}

TEST_CASE("Queue enqueue function test", "[Queue][enqueue]") {
    Queue myQueue;

    // Enqueue elements into the queue
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    // Ensure the queue is not empty
    REQUIRE(myQueue.isEmpty() == false);

    // Check the size of the queue
    REQUIRE(myQueue.getSize() == 3);

    // Get the queue array
    int* queueArray = myQueue.getQueue();

    // Expected queue content: 10, 20, 30
    REQUIRE(queueArray[0] == 10);
    REQUIRE(queueArray[1] == 20);
    REQUIRE(queueArray[2] == 30);
}

TEST_CASE("Queue dequeue function test", "[Queue][dequeue]") {
    Queue myQueue;

    // Enqueue elements into the queue
    myQueue.enqueue(10);
    myQueue.enqueue(20);

    // Dequeue an element
    myQueue.dequeue();

    // Check the size of the queue
    REQUIRE(myQueue.getSize() == 1);

    // Get the queue array
    int* queueArray = myQueue.getQueue();

    // Expected queue content: 20
    REQUIRE(queueArray[0] == 20);
}

TEST_CASE("Stack clear function test", "[Stack][clear]") {
    Stack myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);

    // Clear the stack
    myStack.clear();

    // Check if the stack is empty
    REQUIRE(myStack.isEmpty() == true);
    REQUIRE(myStack.getSize() == 0);
}

TEST_CASE("Stack underflow test", "[Stack][pop]") {
    Stack myStack;

    // Attempt to pop from an empty stack
    myStack.pop();

    // Check if the stack is still empty
    REQUIRE(myStack.isEmpty() == true);
}

TEST_CASE("Queue underflow test", "[Queue][dequeue]") {
    Queue myQueue;

    // Attempt to dequeue from an empty queue
    myQueue.dequeue();

    // Check if the queue is still empty
    REQUIRE(myQueue.isEmpty() == true);
}

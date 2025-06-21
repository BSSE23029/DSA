#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions.h"

TEST_CASE("Basic Insertion and Extraction", "[FibonacciHeap]") {
    FibonacciHeap heap;

    // Insert nodes with different keys
    heap.insert(10);
    heap.insert(5);
    heap.insert(15);

    // Check minimum extraction
    REQUIRE(heap.extractMin()->getKey() == 5);
    REQUIRE(heap.extractMin()->getKey() == 10);
    REQUIRE(heap.extractMin()->getKey() == 15);
    REQUIRE(heap.findMin() == nullptr); // Empty heap
}

TEST_CASE("Decrease Key Operation", "[FibonacciHeap]") {
    FibonacciHeap heap;

    heap.insert(10);
    FibonacciNode* node = heap.insert(20);
    heap.insert(5);

    // Decrease key and check heap property
    heap.decreaseKey(node, 2);
    REQUIRE(heap.findMin()->getKey() == 2);
    REQUIRE(heap.extractMin()->getKey() == 2);
    REQUIRE(heap.extractMin()->getKey() == 5);
    REQUIRE(heap.extractMin()->getKey() == 10);
}

TEST_CASE("Delete Node Operation", "[FibonacciHeap]") {
    FibonacciHeap heap;

    heap.insert(10);
    FibonacciNode* node = heap.insert(20);
    heap.insert(5);

    // Delete a node and check remaining elements
    heap.deleteNode(node);
    REQUIRE(heap.findMin()->getKey() == 5);
    REQUIRE(heap.extractMin()->getKey() == 5);
    REQUIRE(heap.extractMin()->getKey() == 10);
    REQUIRE(heap.extractMin() == nullptr); // Empty heap
}

TEST_CASE("Union Heap Operation", "[FibonacciHeap]") {
    FibonacciHeap heap1, heap2;

    heap1.insert(10);
    heap1.insert(15);
    heap2.insert(5);
    heap2.insert(20);

    // Merge two heaps and check minimum
    heap1.unionHeap(&heap2);
    REQUIRE(heap1.findMin()->getKey() == 5);
    REQUIRE(heap1.extractMin()->getKey() == 5);
    REQUIRE(heap1.extractMin()->getKey() == 10);
}

TEST_CASE("Edge Case: Empty Heap", "[FibonacciHeap]") {
    FibonacciHeap heap;

    // Operations on empty heap
    REQUIRE(heap.extractMin() == nullptr);
    REQUIRE(heap.findMin() == nullptr);      // Delete null node
}

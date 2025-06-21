#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h"
#include <iostream>
using namespace std;

TEST_CASE("Tree insert function test", "[Tree][insert]") {
    Tree<int> tree;

    // Insert nodes
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    
    // Check the root node
    REQUIRE(tree.getData() == 10);

    // Check first child
    Tree<int>* child1 = tree.getChild(10, 0);
    REQUIRE(child1 != nullptr);
    REQUIRE(child1->getData() == 20);

    // Check second child
    Tree<int>* child2 = tree.getChild(10, 1);
    REQUIRE(child2 != nullptr);
    REQUIRE(child2->getData() == 30);

    // Check third child
    Tree<int>* child3 = tree.getChild(10, 2);
    REQUIRE(child3 != nullptr);
    REQUIRE(child3->getData() == 40);
}

TEST_CASE("Tree height function test", "[Tree][height]") {
    Tree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    
    // Check height
    REQUIRE(tree.height() == 1); // Height should be 1, root and its children

    tree.insert(50);
    REQUIRE(tree.height() == 2); // Height remains the same
}

TEST_CASE("Tree degree function test", "[Tree][degreeofTree]") {
    Tree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    
    // Check degree of root
    REQUIRE(tree.degreeofTree() == 2); // Root has 2 children

    tree.insert(40);
    REQUIRE(tree.degreeofTree() == 3); // Root now has 3 children
}


TEST_CASE("Tree getChild function test", "[Tree][getChild]") {
    Tree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    
    // Get first child
    Tree<int>* childNode1 = tree.getChild(10, 0);
    REQUIRE(childNode1 != nullptr);
    REQUIRE(childNode1->getData() == 20);

    // Get second child
    Tree<int>* childNode2 = tree.getChild(10, 1);
    REQUIRE(childNode2 != nullptr);
    REQUIRE(childNode2->getData() == 30);

    // Get child that does not exist
    Tree<int>* childNode3 = tree.getChild(10, 2);
    REQUIRE(childNode3 == nullptr);
}

TEST_CASE("Tree searchInTree function test", "[Tree][searchInTree]") {
    Tree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);

    // Search for existing value
    Tree<int>* foundNode = tree.searchInTree(20);
    REQUIRE(foundNode != nullptr);
    REQUIRE(foundNode->getData() == 20);

    // Search for non-existing value
    Tree<int>* notFoundNode = tree.searchInTree(99);
    REQUIRE(notFoundNode == nullptr);
}

TEST_CASE("Tree update function test", "[Tree][update]") {
    Tree<int> tree;
    tree.insert(10);
    tree.insert(20);

    // Update root value
    tree.update(10,30);
    REQUIRE(tree.getData() != 10); // The value should be updated
}

TEST_CASE("Tree treeSize function test", "[Tree][treeSize]") {
    Tree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);

    // Check the size of the tree
    REQUIRE(tree.treeSize() == 3); // Should be 3 nodes
}

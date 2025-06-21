#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h"
#include <iostream>
#include <sstream>
using namespace std;


TEST_CASE("Tree insertNode function test", "[Tree][insertNode]") {
    Tree tree;
    
    // Insert some nodes
    tree.insertNode(10);
    tree.insertNode(5);
    tree.insertNode(20);

    TreeNode* root = tree.getRoot();
    
    // Test root node
    REQUIRE(root->getData() == 10);

    // Test left and right children
    REQUIRE(root->getLeftChild()->getData() == 5);
    REQUIRE(root->getRightChild()->getData() == 20);
}

TEST_CASE("Tree getTreeHeight function test", "[Tree][getTreeHeight]") {
    Tree tree;

    // Insert nodes
    tree.insertNode(10);
    tree.insertNode(5);
    tree.insertNode(20);
    tree.insertNode(3);
    tree.insertNode(7);

    // Test tree height
    REQUIRE(tree.getTreeHeight() == 2); // Root -> Level 1 -> Level 2
}

TEST_CASE("Tree getDegree function test", "[Tree][getDegree]") {
    Tree tree;

    // Insert nodes
    tree.insertNode(10);
    tree.insertNode(5);
    tree.insertNode(20);

    // Test degree of root (should be 2 children)
    REQUIRE(tree.getDegree(10) == 2);

    // Test degree of left child (should be 0 children)
    REQUIRE(tree.getDegree(5) == 0);

    // Test degree of right child (should be 0 children)
    REQUIRE(tree.getDegree(20) == 0);

    // Test degree of a non-existent node (should be -1)
    REQUIRE(tree.getDegree(50) == -1);
}

TEST_CASE("Tree deleteNode function test", "[Tree][deleteNode]") {
    Tree tree;

    // Insert nodes
    tree.insertNode(10);
    tree.insertNode(5);
    tree.insertNode(20);
    tree.insertNode(3);

    // Delete node with value 5
    tree.deleteNode(5);

    TreeNode* root = tree.getRoot();

    // Test if the deleted node was 5 and verify tree structure after deletion
    REQUIRE(root->getLeftChild()->getData() == 3); // 3 replaces 5 (or the deepest node)
    REQUIRE(root->getRightChild()->getData() == 20); // 20 is still present

    // Ensure no node with value 5 exists anymore
    REQUIRE(tree.findNode(5) == nullptr);

    // Tree should still have the root node and right child
    REQUIRE(root->getData() == 10);
    REQUIRE(root->getRightChild()->getData() == 20);
}


TEST_CASE("Tree getHeight of a node test", "[Tree][getHeight]") {
    Tree tree;

    // Insert nodes
    tree.insertNode(10);
    tree.insertNode(5);
    tree.insertNode(20);
    tree.insertNode(3);
    tree.insertNode(7);

    // Test height of root (should be 2)
    REQUIRE(tree.getHeight(10) == 2);

    // Test height of left child of root (should be 1)
    REQUIRE(tree.getHeight(5) == 1);

    // Test height of a leaf node (should be 0)
    REQUIRE(tree.getHeight(7) == 0);

    // Test height of a non-existent node (should be -1)
    REQUIRE(tree.getHeight(50) == -1);
}

TEST_CASE("Tree display functions test", "[Tree][display]") {
    Tree tree;

    // Insert nodes
    tree.insertNode(10);
    tree.insertNode(5);
    tree.insertNode(20);
    tree.insertNode(3);
    tree.insertNode(7);

    // Capture output of in-order traversal
    std::ostringstream inStream;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(inStream.rdbuf());
    tree.display_in(tree.getRoot());
    std::cout.rdbuf(oldCoutBuffer);
    REQUIRE(inStream.str() == "3 5 7 10 20 ");

    // Capture output of pre-order traversal
    std::ostringstream preStream;
    std::cout.rdbuf(preStream.rdbuf());
    tree.display_pre(tree.getRoot());
    std::cout.rdbuf(oldCoutBuffer);
    REQUIRE(preStream.str() == "10 5 3 7 20 ");

    // Capture output of post-order traversal
    std::ostringstream postStream;
    std::cout.rdbuf(postStream.rdbuf());
    tree.display_post(tree.getRoot());
    std::cout.rdbuf(oldCoutBuffer);
    REQUIRE(postStream.str() == "3 7 5 20 10 ");

    // Capture output of level-order traversal
    std::ostringstream levelStream;
    std::cout.rdbuf(levelStream.rdbuf());
    tree.display_level();
    std::cout.rdbuf(oldCoutBuffer);
    REQUIRE(levelStream.str() == "10 5 20 3 7 ");
}

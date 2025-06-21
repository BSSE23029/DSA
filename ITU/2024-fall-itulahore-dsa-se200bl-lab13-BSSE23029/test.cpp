#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions.h"
#include <iostream>
#include <sstream>
using namespace std;

TEST_CASE("Complex Insertions in Red-Black Tree", "[RBT][complex]") {
    RedBlackTree tree;

    // Insert multiple nodes requiring rotations and recoloring
    tree.insert(50);
    tree.insert(40);
    tree.insert(60);
    tree.insert(30);
    tree.insert(45);
    tree.insert(55);
    tree.insert(70);

    Node* root = tree.search(50);
    REQUIRE(root != nullptr);
    REQUIRE(root->getColor() == false); // Root remains black

    REQUIRE(tree.search(30)->getColor() == true); // Red node
    REQUIRE(tree.search(45)->getColor() == true); // Red node
    REQUIRE(tree.search(40)->getColor() == false); // Black node
}

TEST_CASE("Edge Case: Duplicate Keys", "[RBT][duplicates]") {
    RedBlackTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(10); // Duplicate key

    REQUIRE(tree.search(10) != nullptr); // 10 should still be present
    REQUIRE(tree.search(20) != nullptr);
    REQUIRE(tree.search(15) == nullptr); // Key not inserted
}

TEST_CASE("Edge Case: Single Node Tree", "[RBT][single]") {
    RedBlackTree tree;
    tree.insert(100);

    Node* root = tree.search(100);
    REQUIRE(root != nullptr);
    REQUIRE(root->getColor() == false); // Single node is black (root)
    REQUIRE(root->getLeft() == nullptr);
    REQUIRE(root->getRight() == nullptr);
}

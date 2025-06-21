#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "functions.h"
#include <iostream>
#include <sstream>
using namespace std;

TEST_CASE("AVL Tree Root After Insertions", "[AVLTree][insert][root]") {
    AVLTree tree;

    tree.insert(10);  
    tree.insert(20); 
    tree.insert(5);  
    tree.insert(15); 
    tree.insert(30);  

    REQUIRE(tree.getRoot()->getKey() == 10);  
}

TEST_CASE("AVL Tree Left and Right Children After Insertions", "[AVLTree][insert][children]") {
    AVLTree tree;

    tree.insert(10);   
    tree.insert(20); 
    tree.insert(5);   
    tree.insert(15); 
    tree.insert(30);  


    REQUIRE(tree.getRoot()->getLeft()->getKey() == 5); 
    REQUIRE(tree.getRoot()->getRight()->getKey() == 20);

    REQUIRE(tree.getRoot()->getRight()->getLeft()->getKey() == 15); 
    REQUIRE(tree.getRoot()->getRight()->getRight()->getKey() == 30);
}

TEST_CASE("AVL Tree Balance After Insertions", "[AVLTree][insert][balance]") {
    AVLTree tree;

    tree.insert(10); 
    tree.insert(20); 
    tree.insert(30);

    REQUIRE(tree.getRoot()->getKey() == 20); 

    REQUIRE(tree.getRoot()->getLeft()->getKey() == 10); 
    REQUIRE(tree.getRoot()->getRight()->getKey() == 30);
}

TEST_CASE("AVL Tree Left-Right Rotation After Insertions", "[AVLTree][insert][leftRightRotate]") {
    AVLTree tree;

    tree.insert(30); 
    tree.insert(10); 
    tree.insert(20);  

   
    REQUIRE(tree.getRoot()->getKey() == 20); 

    REQUIRE(tree.getRoot()->getLeft()->getKey() == 10);
    REQUIRE(tree.getRoot()->getRight()->getKey() == 30); 
}

TEST_CASE("AVL Tree Right-Left Rotation After Insertions", "[AVLTree][insert][rightLeftRotate]") {
    AVLTree tree;

    tree.insert(10);  
    tree.insert(30); 
    tree.insert(20); 

  
    REQUIRE(tree.getRoot()->getKey() == 20); 

    REQUIRE(tree.getRoot()->getLeft()->getKey() == 10);
    REQUIRE(tree.getRoot()->getRight()->getKey() == 30);
}

TEST_CASE("AVL Tree Search Functionality", "[AVLTree][search]") {
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(15);

    Node* node10 = tree.search(10);
    Node* node5 = tree.search(5);
    Node* node20 = tree.search(20);
    Node* node15 = tree.search(15);
    Node* node50 = tree.search(50);  

    REQUIRE(node10 != nullptr);
    REQUIRE(node5 != nullptr); 
    REQUIRE(node20 != nullptr);
    REQUIRE(node15 != nullptr);
    REQUIRE(node50 == nullptr);  
}

TEST_CASE("AVL Tree Rebalancing after Insertions", "[AVLTree][rebalance]") {
    AVLTree tree;

    tree.insert(10); 
    tree.insert(20);  
    tree.insert(30); 
    tree.insert(25);  

    REQUIRE(tree.getRoot()->getKey() == 20);

    REQUIRE(tree.getRoot()->getLeft()->getKey() == 10); 
    REQUIRE(tree.getRoot()->getRight()->getKey() == 30); 
    REQUIRE(tree.getRoot()->getRight()->getLeft()->getKey() == 25); 
}

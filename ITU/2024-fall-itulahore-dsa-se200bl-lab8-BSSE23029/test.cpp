#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h"
#include <iostream>
using namespace std;

TEST_CASE("HashTable insert and search functionality test", "[HashTable][insert]") {
    HashTable hashTable(10);
    
    hashTable.insert(10);
    hashTable.insert(20);
    hashTable.insert(30);

    REQUIRE(hashTable.search(10) == true);
    REQUIRE(hashTable.search(20) == true);
    REQUIRE(hashTable.search(30) == true);
    
    // Test searching for a non-existing value
    REQUIRE(hashTable.search(40) == false);
}

TEST_CASE("HashTable remove functionality test", "[HashTable][remove]") {
    HashTable hashTable(10);
    
    hashTable.insert(10);
    hashTable.insert(20);
    hashTable.insert(30);

    REQUIRE(hashTable.remove(20) == true); 
    REQUIRE(hashTable.search(20) == false);
    
    // Test removing a non-existing value
    REQUIRE(hashTable.remove(40) == false); 
}

TEST_CASE("HashTable getSize functionality test", "[HashTable][getSize]") {
    HashTable hashTable(5);

    hashTable.insert(1);
    hashTable.insert(2);
    hashTable.insert(3);

    REQUIRE(hashTable.getSize() == 3);

    hashTable.remove(2);
    
    // Test size after removal
    REQUIRE(hashTable.getSize() == 2);
}

TEST_CASE("HashTable test cases for edge value handling", "[HashTable]") {
    HashTable hashTable(10); 

    hashTable.insert(-10);
    hashTable.insert(0);
    hashTable.insert(10);

    REQUIRE(hashTable.search(-10) == true);
    REQUIRE(hashTable.search(0) == true);
    REQUIRE(hashTable.search(10) == true);
    
    // Test searching for a value not inserted
    REQUIRE(hashTable.search(100) == false);
}
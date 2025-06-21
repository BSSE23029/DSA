#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h"
#include <iostream>
#include <sstream>
using namespace std;


TEST_CASE("Basic Insert and Search Operations", "[Trie][insert][search]") {
    Trie trie;
    
    trie.insert("apple");
    trie.insert("App");
    trie.insert("Banana");
    trie.insert("cat");
    
    REQUIRE(trie.search("apple") == true);
    REQUIRE(trie.search("App") == true);
    REQUIRE(trie.search("banana") == false); // Case-sensitive check
    REQUIRE(trie.search("cat") == true);
    REQUIRE(trie.search("Cat") == false); // Case-sensitive check
}

TEST_CASE("Prefix Search", "[Trie][startsWith]") {
    Trie trie;
    
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    trie.insert("ball");
    
    REQUIRE(trie.startsWith("app") == true);
    REQUIRE(trie.startsWith("ba") == true);
    REQUIRE(trie.startsWith("bat") == true);
    REQUIRE(trie.startsWith("bal") == true);
    REQUIRE(trie.startsWith("b") == true);
    REQUIRE(trie.startsWith("c") == false);
}

TEST_CASE("Delete Words", "[Trie][deleteWord]") {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    
    // Check if words exist before deletion
    REQUIRE(trie.search("apple") == true);
    REQUIRE(trie.search("app") == true);
    REQUIRE(trie.search("bat") == true);

    // Delete a word
    trie.deleteWord("app");
    REQUIRE(trie.search("app") == false);
    REQUIRE(trie.search("apple") == true); // apple should still exist
    REQUIRE(trie.search("bat") == true);
    
    // Delete another word
    trie.deleteWord("apple");
    REQUIRE(trie.search("apple") == false);
    REQUIRE(trie.search("bat") == true); // bat should still exist
}

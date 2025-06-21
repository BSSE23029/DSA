#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>

using namespace std;

class TrieNode {

public:

  bool isEndOfWord;
  TrieNode *children[52];

  TrieNode();

};

class Trie {

  TrieNode *root;

public:

  Trie();

  void insert(const string &word);

  bool search(const string &word);

  bool startsWith(const string &prefix);

  bool deleteWordHelper(TrieNode *root, const string &word, int depth);

  bool deleteWord(const string &word);

  void displayHelper(TrieNode *root, const string &x);

  void displayTrie();
  
};

#endif

#include "functions.h"
#include <iostream>

using namespace std;

TrieNode::TrieNode() {
  isEndOfWord = false;
  for (int i = 0; i < 52; i++) {
    children[i] = nullptr;
  }
}

Trie::Trie() { root = new TrieNode(); }

void Trie::insert(const string &word) {
  TrieNode *currentNode = root;
  for (int i = 0; i < word.length(); i++) {
    int index =
        (word[i] >= 'a' && word[i] <= 'z') ? word[i] - 'a' : word[i] - 'A' + 26;
    if (!currentNode->children[index]) {
      currentNode->children[index] = new TrieNode();
    }
    currentNode = currentNode->children[index];
  }
  currentNode->isEndOfWord = true;
}

bool Trie::search(const string &word) {
  TrieNode *currentNode = root;
  for (int i = 0; i < word.length(); i++) {
    int index =
        (word[i] >= 'a' && word[i] <= 'z') ? word[i] - 'a' : word[i] - 'A' + 26;
    if (!currentNode->children[index]) {
      return false;
    }
    currentNode = currentNode->children[index];
  }
  return currentNode->isEndOfWord;
}

bool Trie::startsWith(const string &prefix) {
  TrieNode *currentNode = root;
  for (int i = 0; i < prefix.length(); i++) {
    int index = (prefix[i] >= 'a' && prefix[i] <= 'z') ? prefix[i] - 'a'
                                                       : prefix[i] - 'A' + 26;
    if (!currentNode->children[index]) {
      return false;
    }
    currentNode = currentNode->children[index];
  }
  return true;
}

bool Trie::deleteWordHelper(TrieNode *root, const string &word, int depth) {
  // Base case: if we've reached the end of the word
  if (depth == word.size()) {
    if (!root->isEndOfWord) {
      return false; // Word not found
    }
    root->isEndOfWord = false; // Unmark end of word

    // Check if the current node has no children
    for (int i = 0; i < 52; i++) {
      if (root->children[i] != nullptr) {
        return false; // Node cannot be deleted as it has children
      }
    }
    return true; // Node can be deleted
  }

  // Find the index of the current character
  int index = (word[depth] >= 'a' && word[depth] <= 'z')
                  ? word[depth] - 'a'
                  : word[depth] - 'A' + 26;
  TrieNode *childNode = root->children[index];

  // If the child node doesn't exist, the word is not in the Trie
  if (!childNode) {
    return false;
  }

  // Recursively call deleteWordHelper on the next character
  bool shouldDeleteChild = deleteWordHelper(childNode, word, depth + 1);

  // If the child node can be deleted, delete the pointer and set it to
  // nullptr
  if (shouldDeleteChild) {
    delete root->children[index];
    root->children[index] = nullptr;

    // Check if the current node can now be deleted (no other children and not
    // an end of another word)
    if (!root->isEndOfWord) {
      for (int i = 0; i < 52; i++) {
        if (root->children[i] != nullptr) {
          return false; // Node cannot be deleted as it has other children
        }
      }
      return true; // Node can be deleted
    }
  }
  return false;
}

bool Trie::deleteWord(const string &word) {
  return deleteWordHelper(root, word, 0);
}

void Trie::displayHelper(TrieNode *root, const string &x) {
  if (root == nullptr) {
    return;
  }
  for (int i = 0; i < 52; i++) {
    if (root->children[i]) {
      char c = (i < 26) ? 'a' + i : 'A' + i - 26;
      displayHelper(root->children[i], x + c);
    }
  }
  if (root->isEndOfWord) {
    cout << x << " ";
  }
}

void Trie::displayTrie() { displayHelper(root, ""); }

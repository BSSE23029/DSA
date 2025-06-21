#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#pragma once

#include <iostream>

using namespace std;

// Class Definitions:

// 1. FibonacciNode
// This class represents a single node in the Fibonacci Heap.
// Attributes
// •	int key: The key value stored in the node.
// •	int degree: The number of children this node currently has.
// •	FibonacciNode* parent: Pointer to the parent node (if any).
// •	FibonacciNode* child: Pointer to one of the children of this node (if
// any). •	FibonacciNode* left: Pointer to the left sibling in the circular
// doubly-linked list. •	FibonacciNode* right: Pointer to the right
// sibling in the circular doubly-linked list. •	bool mark: Indicates
// whether this node has lost a child (true = lost, false = not lost). •
// char C: Temporary marker for node search.

// Methods
// •	FibonacciNode(int key): Constructor to initialize a FibonacciNode with
// the given key. •	void link(FibonacciNode* child): Links a child node to
// the current node, updating degrees. •	int getKey(): Returns the key
// value

// 2. FibonacciHeap
// This class represents the Fibonacci Heap, which is a collection of
// FibonacciNodes. Attributes •	FibonacciNode* minNode: Pointer to the node with
// the minimum key in the heap. •	int nodeCount: The total number of nodes
// in the heap. •	FibonacciNode* rootList: Pointer to the circular
// doubly-linked list containing the heap’s root nodes.

// Methods
// •	FibonacciHeap(): Constructor to initialize an empty Fibonacci Heap.
// •	FibonacciNode* insert(int key): Inserts a new node with the given key
// into the heap and returns a pointer to it. •	FibonacciNode* findMin():
// Returns a pointer to the node with the minimum key in the heap. •
// FibonacciNode* extractMin(): Removes and returns a pointer to the node with
// the minimum key. •	void decreaseKey(FibonacciNode* node, int newKey):
// Decreases the key value of a node and ensures the heap property is
// maintained. •	void deleteNode(FibonacciNode* node): Deletes a node
// from the heap. •	void unionHeap(FibonacciHeap* otherHeap): Merges the
// current heap with another Fibonacci Heap. •	void consolidate(): Combines
// trees in the root list to ensure each tree has a unique degree. •	void
// cut(FibonacciNode* node, FibonacciNode* parent): Cuts a node from its parent
// and adds it to the root list. •	void cascadingCut(FibonacciNode* node):
// Performs cascading cuts to restore the heap property after a decrease_key
// operation.

class FibonacciNode {
private:
  int key;
  int degree;
  FibonacciNode *parent;
  FibonacciNode *child;
  FibonacciNode *left;
  FibonacciNode *right;
  bool mark;
  char C;

public:
  FibonacciNode(int key);

  void link(FibonacciNode *child);

  FibonacciNode() {
    key = 0;
    degree = 0;
    parent = nullptr;
    child = nullptr;
    left = nullptr;
    right = nullptr;
    mark = false;
    C = 'N';
  }

  ~FibonacciNode() {}

  int getKey() const { return key; }
  void setKey(int key) { this->key = key; }

  int getDegree() const { return degree; }
  void setDegree(int degree) { this->degree = degree; }

  void decrementDegree() {
    degree--;
    if (degree == 0) {
      setMark(false);
    }
  }

  void incrementDegree() {
    degree++;
    if (degree == 0) {
      setMark(false);
    }
  }

  FibonacciNode *getParent() const { return parent; }
  void setParent(FibonacciNode *parent) { this->parent = parent; }

  FibonacciNode *getChild() const { return child; }
  void setChild(FibonacciNode *child) { this->child = child; }

  FibonacciNode *getLeft() const { return left; }
  void setLeft(FibonacciNode *left) { this->left = left; }

  FibonacciNode *getRight() const { return right; }
  void setRight(FibonacciNode *right) { this->right = right; }

  bool getMark() const { return mark; }
  void setMark(bool mark) { this->mark = mark; }

  char getC() const { return C; }
  void setC(char C) { this->C = C; }
};

class FibonacciHeap {

  FibonacciNode *minNode;
  int nodeCount;
  FibonacciNode *rootList;

public:
  FibonacciHeap();
  FibonacciNode *insert(int key);
  FibonacciNode *findMin() const;
  FibonacciNode *extractMin();
  void decreaseKey(FibonacciNode *node, int newKey);
  void deleteNode(FibonacciNode *node);
  void unionHeap(FibonacciHeap *otherHeap);
  void cut(FibonacciNode *node, FibonacciNode *parent);
  void cascadingCut(FibonacciNode *node);
  void consolidate();

  int getNodeCount();
};

#endif
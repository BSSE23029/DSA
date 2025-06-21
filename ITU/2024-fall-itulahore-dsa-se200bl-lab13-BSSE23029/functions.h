#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Class: Node
// Data Members
// 1.	int key: The value stored in the node.
// 2.	bool color: Represents the color of the node (true for red, false for
// black). 3.	Node* left: Pointer to the left child node. 4.	Node* right:
// Pointer to the right child node. 5.	Node* parent: Pointer to the parent
// node. Member Functions 1.	Constructor: ○	Node(int key, bool color):
// Initializes the node with the given key and color, and sets child and parent
// pointers to nullptr. 2.	Getters and Setters: ○	int getKey(): Returns
// the key of the node. 	○	bool getColor(): Returns the color of the node.
// 	○	void setColor(bool color): Sets the color of the node.
// 	○	Node* getLeft(): Returns the pointer to the left child.
// 	○	Node* getRight(): Returns the pointer to the right child.
// 	○	Node* getParent(): Returns the pointer to the parent.
// 	○	void setLeft(Node* leftChild): Sets the left child pointer.
// 	○	void setRight(Node* rightChild): Sets the right child pointer.
// 	○	void setParent(Node* parentNode): Sets the parent pointer.
// Class: RedBlackTree
// Data Members
// 1. Node* root: Pointer to the root of the Red-Black Tree.
// Member Functions
// 1.	Constructor:
// ○	RedBlackTree(): Initializes the tree with root as nullptr.
// 2.	Insertion:
// ○	void insert(int key): Inserts a new key into the tree while maintaining
// Red-Black Tree properties. 	○	void balanceInsert(Node* node): Helper function
// to fix violations after insertion. 3.	Search: ○	Node* search(int
// key): Searches for a node with the given key and returns a pointer to it. 4.
// Rotation: ○	void leftRotate(Node* node): Performs a left rotation around the
// given node. 	○	void rightRotate(Node* node): Performs a right rotation
// around the given node. 5.	Utility Functions: ○	void printTree(): Prints
// the Red-Black Tree in an in-order traversal.

#include <iostream>

using namespace std;

class Node {

private:

  int key;
  bool color;
  Node *left;
  Node *right;
  Node *parent;

public:
  
  Node(int key, bool color);
  
  int getKey();
  
  bool getColor();
  
  void setColor(bool color);
  
  Node *getLeft();
  
  Node *getRight();
  
  Node *getParent();
  
  void setLeft(Node *leftChild);
  
  void setRight(Node *rightChild);
  
  void setParent(Node *parentNode);

};

class RedBlackTree {

private:

  Node *root;

public:
  
  RedBlackTree();
  
  void insert(int key);
  
  void balanceInsert(Node *node);

  void fixViolation(Node *node);
  
  Node *search(int key);
  
  void leftRotate(Node *node);
  
  void rightRotate(Node *node);
  
  void printTree();

  void printHelper(Node *root, string indent, bool last);

};

#endif

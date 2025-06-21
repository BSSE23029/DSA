#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

using namespace std;

class TreeNode {

private:
  int data;
  TreeNode *left;
  TreeNode *right;

public:
  TreeNode(int value);

  ~TreeNode();

  TreeNode *getLeftChild();

  TreeNode *getRightChild();

  int getData();

  void setData(int value);

  void addLeftChild(TreeNode *node);

  void addRightChild(TreeNode *node);
};

class Tree {

private:
  
  TreeNode *root;

public:
  
  Tree(); // Constructor to initialize the tree.
  
  void insertNode(int value); // Inserts a node into the tree using level order traversal.
  
  void  deleteNode(int value); // deletes the node with the given value by replacing
                         // it with the last leaf node and then deleting it.
  void printTree();      // Prints the tree in an in-order traversal.
  
  int getTreeHeight();   // Returns the height of the tree.
  
  int getDegree(int data); // Returns the degree of a given node (number of children).
  
  int getHeight(int data);      // Returns the height of a given node.
  
  TreeNode *findNode(int data); // Finds and returns the node with the data
  
  // otherwise return nullptr
  TreeNode *getRoot(); // Returns the root node of the tree.



  int getHeightHelper(TreeNode* node); //for recursion

  TreeNode* findNodeHelper(TreeNode* node, int data); //for recursion

  TreeNode* DeepestLeafNode();

  TreeNode * findParent(TreeNode * node);


};

template <typename Type>
class Queue {

    struct Node {
        Type data;
        Node* next;
    };

    Node* front;
    Node* rear;

    public:
    Queue();

    ~Queue();

    void enqueue(Type value);

    Type dequeue();

    bool isEmpty();
};


#endif

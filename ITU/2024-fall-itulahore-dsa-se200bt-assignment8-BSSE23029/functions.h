#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

template <typename Type> class Node {
  Type data;
  Node *next;
  Node *previous;

public:
  Node(Type value = Type());

  void setData(Type value);

  Type getData();

  void setNext(Node *n);

  Node *getNext();

  void setPrevious(Node *p);

  Node *getPrevious();

};

template <typename Type> class Queue {
  Node<Type> *head;
  Node<Type> *tail;
  int count;

public:
  Queue();

  ~Queue();

  bool isEmpty();

  void enqueue(Type value);

  Type dequeue();

  void print();

};

class TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;

public:
  TreeNode(int value = 0);

  TreeNode *getLeftChild();

  TreeNode *getRightChild();

  int getData();

  void setData(int val);

  void addLeftChild(TreeNode *node);

  void addRightChild(TreeNode *node);

};

class Tree {
  TreeNode *root;

public:
  Tree();

  void insertNode(int value);

  void deleteNode(int value);

  void printTree();

  int getTreeHeight();

  int getDegree(int data);

  int getHeight(TreeNode *node);

  int getHeight(int data);

  TreeNode *findNode(int data);

  TreeNode *getRoot();

  void display_in(TreeNode *root);

  void display_pre(TreeNode *root);

  void display_post(TreeNode *root);

  void display_level();

  void printTreeVisual(TreeNode* node, int space = 0, int height = 10);

  void visualDisplay(){
    printTreeVisual(root, 2);
  }

};

#endif // FUNCTIONS_H

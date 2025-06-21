#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#pragma once

#include <iostream>
#include <queue>

using namespace std;

class Node {
private:
  int key;
  Node *left;
  Node *right;
  Node *parent;
  int height;

public:
  Node(int key);
  ~Node();

  int getKey();
  Node *getLeft();
  Node *getRight();
  Node *getParent();
  void setLeft(Node *leftChild);
  void setRight(Node *rightChild);
  void setParent(Node *parentNode);
  int getHeight();
  void setHeight(int height);
};

class AVLTree {
private:
  Node *root;

public:
  AVLTree();
  Node *getRoot();
  void insert(int key);
  void balanceInsert(Node *node);
  Node *search(int key);
  int getBalanceFactor(Node *node);
  void leftRotate(Node *node);
  void rightRotate(Node *node);
  void leftRightRotate(Node *node);
  void rightLeftRotate(Node *node);
  int getHeight(Node *node);
  void updateHeight(Node *node);
  void printTree();
  void printTree(Node *node);
};

#endif
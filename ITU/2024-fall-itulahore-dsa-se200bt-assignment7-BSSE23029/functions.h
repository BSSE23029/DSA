#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cstddef>
#pragma once

#include <iostream>

using namespace std;

#define MaxChild 3

template <typename T> class Queue {

private:
  T *data;
  int capacity;
  int count;
  int first;
  int last;

public:
  Queue(int capacity = 8);

  ~Queue();
  bool isEmpty() const;

  // Check if the queue is full
  bool isFull() const;

  void GrowQueue();

  void enqueue(T value);

  T dequeue();

  T peek();

  int getSize();
};

/*
Data Members:
●	T data: The value stored in the node. (Template variable)
●	Tree* parent : Parent Node
●	Tree* children[MaxChild]: Array to store child objects of the same class
Member Functions to Implement:
●	Tree(T value): Constructor to initialize the node with a given value.
●	void insert(T value): Insert value in tree using level order traversal
●	int getData(): Returns the data stored in the node.
●	Tree<T>* getChild(int data, int childNumber) : Returns the childNumber
Tree address ●	Tree<T>** delete(T value): Delete value from tree ●	int
height(): Returns height of tree ●	int degreeOfTree(): Returns degree of
tree ●	void update (T oldValue, T newValue): Update old value of node with new
value ●	Tree<T>*searchInTree(T value): Search using level order traversal ●
int treecapacity(): Returns the total number of nodes in a tree
*/

template <typename T> class Tree {
private:
  T data;
  Tree<T> *parent;
  Tree<T> *children[MaxChild];

  bool hasData;

public:
  Tree();

  Tree(T value);

  ~Tree();

  bool empty();

  bool NoChild();

  void insert(T value);

  int getData();

  Tree<T> *getChild(int data, int childNumber);


  Tree<T> *deleteNode(T value){
    return nullptr;
  }

  int height();

  int degreeofTree();

  void update(T oldValue, T newValue);

  Tree<T> *searchInTree(T value);

  int treeSize();

};

#endif
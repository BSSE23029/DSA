#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

using namespace std;

class Node {
  int data;
  Node *next;

public:
  Node();

  ~Node();

  Node(int data);

  void setNext(Node *val);

  Node *getNext();

  int getData();

  void setData(int data);

};

class List {
  Node *head;
  Node *tail;

public:
  List();

  ~List();

  bool isEmpty();

  void append(int data);

  void prepend(int data);

  void insertAtIndex(int data, int index);

  void deleteFromEnd();

  void deleteFromStart();

  void deleteFromIndex(int index);

  Node *getHead();

  Node *getTail();

  void printList();
};

#endif

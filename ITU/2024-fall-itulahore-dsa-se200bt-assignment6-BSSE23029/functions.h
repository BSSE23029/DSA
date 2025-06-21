#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#pragma once

#include <iostream>

using namespace std;

class Node {
  int data;
  Node *next;

public:
  Node();

  ~Node();

  Node(int data);

  void setNext(Node* nextNode);

  Node *getNext();

  int getData();

  void setData(int dataValue);

};

class Stack {

  Node* top;
  int count;

public:
  Stack();

  ~Stack();

  bool isEmpty();

  void push(int data);

  void pop();

  int peek();

  int size();

  void clear();

  void printStack();

};

class Queue {
  Node* top;
  Node* base;
  int count;

public:
  Queue();

  ~Queue();

  bool isEmpty();

  void enqueue(int data);

  void dequeue();

  int size();

  void printQueue();

  void clear();

};


#endif
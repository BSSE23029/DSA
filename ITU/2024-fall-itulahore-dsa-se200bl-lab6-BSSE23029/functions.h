#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

using namespace std;

class Stack {

  int *array;
  int size;
  int capacity;

public:
  Stack();

  Stack(int cap);

  ~Stack();

  bool isEmpty();

  void growArray();

  void push(int data);

  void pop();

  int getSize();

  int getCap();

  void clear();

  void printStack();

  int *getStack();

};

class Queue {
  int *array;
  int size;
  int capacity;

public:
  Queue();

  Queue(int cap);

  ~Queue();

  bool isEmpty();

  void growArray();

  void enqueue(int data);

  void dequeue();

  int getSize();

  void printQueue();

  int *getQueue();

  void clear();

};

#endif

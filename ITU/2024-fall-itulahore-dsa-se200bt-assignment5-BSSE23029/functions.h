#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>

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

  Node* getPrevious(Node* node);

  int getIndexData(int index);

  void swapNodes(Node *node1, Node *node2);

  int getLength();

  void bubbleSort();

  Node* findMin(Node *start);

  void selectionSort();

  void insertionSort();

  void merge(Node*& headRef, Node* left, Node* right);

  void mergeSort();

  void mergeSortRecursion(Node*& headRef);

  int partition(List *list, int low, int high);

  void quickSort(int low, int high);

  void quickSort();

  Node *getNodeAtIndex(int index);

  void countSort();

  int findMaxValue();

  int findMinValue();

  void clearList();

  void countingSort(int exp);

  void radixSort();

  // Lab-5

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

//   void swapNodes(Node* prevNode1, Node* node1, Node* prevNode2, Node* node2);

//   void bubbleSort();

//   void selectionSort();

//   void insertionSort();

//   Node* merge(Node* left, Node* right);

//   Node* mergeSort(Node* node);

//   Node* getMiddle(Node* node);

//   void mergeSort();

//   Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd);

//   Node* quickSort(Node* head, Node* end);

//   void quickSort();
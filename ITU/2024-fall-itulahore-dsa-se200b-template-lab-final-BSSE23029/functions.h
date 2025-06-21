#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#pragma once

#include <iostream>

using namespace std;

#define MaxChild 100

// template <typename Type> class Node {
//   Type data;
//   Node *next;
//   Node *previous;

// public:
//   Node(Type value = Type());

//   void setData(Type value);

//   Type getData();

//   void setNext(Node *n);

//   Node *getNext();

//   void setPrevious(Node *p);

//   Node *getPrevious();

// };

// template <typename Type> class Queue {
//   Node<Type> *head;
//   Node<Type> *tail;
//   int count;

// public:
//   Queue();

//   ~Queue();

//   bool isEmpty();

//   void enqueue(Type value);

//   Type dequeue();

//   void print();

// };

// class TreeNode {
//   int data;
//   TreeNode *left;
//   TreeNode *right;

// public:
//   TreeNode(int value = 0);

//   TreeNode *getLeftChild();

//   TreeNode *getRightChild();

//   int getData();

//   void setData(int val);

//   void addLeftChild(TreeNode *node);

//   void addRightChild(TreeNode *node);

// };

// class Tree {
//   TreeNode *root;

// public:
//   Tree();

//   void insertNode(int value);

//   void deleteNode(int value);

//   void printTree();

//   int getTreeHeight();

//   int getDegree(int data);

//   int getHeight(TreeNode *node);

//   int getHeight(int data);

//   TreeNode *findNode(int data);

//   TreeNode *getRoot();

//   void display_in(TreeNode *root);

//   void display_pre(TreeNode *root);

//   void display_post(TreeNode *root);

//   void display_level();

//   void printTreeVisual(TreeNode* node, int space = 0, int height = 10);

//   void visualDisplay(){
//     printTreeVisual(root, 2);
//   }

// };

// class Node {
//   int data;
//   Node *next;

// public:
//   Node();

//   ~Node();

//   Node(int data);

//   void setNext(Node *val);

//   Node *getNext();

//   int getData();

//   void setData(int data);

// };

// class List {
//   Node *head;
//   Node *tail;

// public:
//   List();

//   ~List();

//   bool isEmpty();

//   void append(int data);

//   void prepend(int data);

//   void insertAtIndex(int data, int index);

//   void deleteFromEnd();

//   void deleteFromStart();

//   void deleteFromIndex(int index);

//   Node *getHead();

//   Node *getTail();

//   void printList();
// };

struct Designation {
  int level;
  string salaryRange;
  int scale;
  // TreeNode* parent;

  Designation(Designation &d) {
    this->level = d.level;
    this->salaryRange = d.salaryRange;
    this->scale = d.scale;
  }

  Designation() {
    this->level = 0;
    this->salaryRange = "0-100";
    this->scale = 0;
  }
};

struct Alumni {
  int period;
  int desgination;
};

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

struct Resource {
  string firstName;
  string lastName;
  string date_of_birth;
  string CNIC;
  string phoneNumber;
  string address;
  int period;

  Designation designation;

  Resource(string firstName,  string lastName,  string date_of_birth,  string CNIC,  string phoneNumber,  string address) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->date_of_birth = date_of_birth;
    this->CNIC = CNIC;
    this->phoneNumber = phoneNumber;
    this->address = address;
    period = 0;
  }

  Resource(Resource &r, Designation d) {
    this->firstName = r.firstName;
    this->lastName = r.lastName;
    this->date_of_birth = r.date_of_birth;
    this->CNIC = r.CNIC;
    this->phoneNumber = r.phoneNumber;
    this->address = r.address;
    period = 0;
  }
};

class Tree {

public:
  string firstName;
  string lastName;
  string date_of_birth;
  string CNIC;
  string phoneNumber;
  string address;
  
  int period;

  Designation designation;

  bool ApplyLeave;

  //   Resource(Resource& r, Designation d) {
  //     this->firstName = r.firstName;
  //     this->lastName = r.lastName;
  //     this->date_of_birth = r.date_of_birth;
  //     this->CNIC = r.CNIC;
  //     this->phoneNumber = r.phoneNumber;
  //     this->address = r.address;
  //   }



  Tree *parent;
  Tree *children[MaxChild];

  bool hasData;


  Tree(Resource &r);


  bool isEmpty();

  bool NoChild();

  void insert(Resource &r);

  void makeVacant(Resource &r);

  void updatePeriod(Resource &r, int period);

  bool compareResource(Resource &r);

  void display();

  void applyLeave(Resource &r);

  bool hasChildAppliedLeave(Resource &r);

  //   int getData();

  //   Tree *getChild(int data, int childNumber);

  //   Tree *deleteNode(Resource value) { return nullptr; }

  //   int height();

  //   int degreeofTree();

  //   void update(Resource oldValue, T newValue);

  //   Tree<T> *searchInTree(T value);

  //   int treeSize();
};

class Organization {
  Tree resources;
};

#endif
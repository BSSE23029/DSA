#include <iostream>
#include "functions.h"
using namespace std;

Node::Node() { next = nullptr; }

  Node::~Node() { // delete next;
  }

  Node::Node(int data) {
    this->data = data;
    next = nullptr;
  }

  void Node::setNext(Node *val) { next = val; }

  Node * Node::getNext() { return next; }

  int Node::getData() { return data; }

  void Node::setData(int data) { this->data = data; }































  List::List() {
    head = nullptr;
    tail = nullptr;
  }
  List::~List() {
    delete head;
    delete tail;
  }

  bool List::isEmpty() {
    if (head == nullptr && tail == nullptr)
      return true;
    return false;
  }

  void List::append(int data) {

    Node *newNode = new Node(data);

    if (isEmpty()) {
      head = newNode;
      tail = newNode;
    }

    else {
      tail->setNext(newNode);
      tail = newNode;
    }
  }

  void List::prepend(int data) {

    Node *newNode = new Node(data);

    if (isEmpty()) {
      head = newNode;
      tail = newNode;
    }

    else {

      newNode->setNext(head);
      head = newNode;

    }
  }

  void List::insertAtIndex(int data, int index) {

    Node *newNode = new Node();

    if (isEmpty()) {
      head = newNode;
      tail = newNode;
    }

    else {

      if (index == 0) {
        prepend(data);
        return;
      }

      Node *temp = head;

      for (int i = 0; i < index - 1; i++) {
        temp = temp->getNext();
      }

      newNode->setNext(temp->getNext());
      newNode->setData(data);

      temp->setNext(newNode);
    }
  }

  void List::deleteFromEnd() {
    if (isEmpty()) {
      // List is empty Cannot delete from end
      return;
    }

    Node *temp = head;

    if (temp->getNext() == nullptr) {
      head = nullptr;
      tail = nullptr;
      delete temp;
      return;
    }

    while (temp->getNext() != tail) {
      temp = temp->getNext();
    }

    temp->setNext(nullptr);
    delete tail;
    tail = temp;
  }

  void List::deleteFromStart() {

    if (isEmpty()) {
      // List is empty Cannot delete from start
      return;
    }

    Node *temp = head;

    if (temp->getNext() == nullptr) {
      head = nullptr;
      tail = nullptr;
      delete temp;
      return;
    }

    head = temp->getNext();
    delete temp;
  }

  void List::deleteFromIndex(int index) {

    if (isEmpty()) {
      return;
    }

    Node *temp = head;

    Node *max = head;
    int maxIndex = -1;

    while (max != nullptr) {
      maxIndex++;
      max = max->getNext();
    }

    if (index == 0) {
      deleteFromStart();
      return;
    }

    if (index == maxIndex) {
      deleteFromEnd();
      return;
    }

    for (int i = 0; i < index - 1; i++) {
      temp = temp->getNext();
    }

    Node *temp2 = temp->getNext();

    temp->setNext(temp2->getNext());

    // No need to update tail here

    delete temp2;
  }

  Node * List::getHead() { return head; }

  Node * List::getTail() { return tail; }

  void List::printList() {

    Node *temp = head;

    while (temp != nullptr) {
      cout << temp->getData() << " ";
      temp = temp->getNext();
    }
  }


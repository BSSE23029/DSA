#include "functions.h"

Node::Node() {
  data = 0;
  next = nullptr;
}

Node::~Node() {}

Node::Node(int data) {
  this->data = data;
  next = nullptr;
}

void Node::setNext(Node *nextNode) { next = nextNode; }

Node *Node::getNext() { return next; }

int Node::getData() { return data; }

void Node::setData(int dataValue) { data = dataValue; }

Stack::Stack() {
  top = nullptr;
  count = 0;
}

Stack::~Stack() {
  Node *temp = new Node();
  temp = top;

  while (temp != nullptr) {
    top = top->getNext();
    delete temp;
    temp = top;
  }
}

bool Stack::isEmpty() { return count == 0; }

void Stack::push(int data) {
  Node *newNode = new Node(data);
  newNode->setNext(top);
  top = newNode;
  count++;
}

void Stack::pop() {
  if (count == 0) {
    return;
  }

  count--;

  Node *temp = new Node();
  temp = top;

  if (temp->getNext() == nullptr) {
    delete temp;
    top = nullptr;
    return;
  }

  top = top->getNext();
  delete temp;
  
}

int Stack::peek() {
  if (top == nullptr) {
    return -1;
  }
  return top->getData();
}

int Stack::size() { return count; }

void Stack::clear() {
  Node *temp = new Node();
  temp = top;

  while (temp != nullptr) {
    top = top->getNext();
    delete temp;
    temp = top;
  }

  count = 0;
}

void Stack::printStack() {
  Node *temp = new Node();
  temp = top;

  while (temp != nullptr) {
    cout << temp->getData();
    if (temp->getNext() != nullptr) {
      cout << " , ";
    }
    temp = temp->getNext();
  }

  cout << endl;
}

Queue::Queue() {
  top = nullptr;
  base = nullptr;
  count = 0;
}

Queue::~Queue() {
  Node *temp = new Node();
  temp = top;

  while (temp != nullptr) {
    top = top->getNext();
    delete temp;
    temp = top;
  }
}

bool Queue::isEmpty() { return count == 0; }

void Queue::enqueue(int data) {
  Node *newNode = new Node(data);
  if (isEmpty()) {
    top = newNode;
    base = newNode;
  } else {
    base->setNext(newNode);
    base = newNode;
  }
  count++;
}

void Queue::dequeue() {
  if (count == 0) {
    return;
  }

  count--;

  Node *temp = new Node();  
  temp = top;

  if (temp->getNext() == nullptr) {
    delete temp;
    top = nullptr;
    base = nullptr; 
    return;
  }

  top = top->getNext();
  delete temp;

}

int Queue::size() { return count; }

void Queue::printQueue() {
  Node *temp = new Node();
  temp = top;

  while (temp != nullptr) {
    cout << temp->getData();
    if (temp->getNext() != nullptr) {
      cout << " , ";
    }
    temp = temp->getNext();
  }
}

void Queue::clear() {
  Node *temp = new Node();
  temp = top;

  while (temp != nullptr) {
    top = top->getNext();
    delete temp;
    temp = top;
  }

  count = 0;
}
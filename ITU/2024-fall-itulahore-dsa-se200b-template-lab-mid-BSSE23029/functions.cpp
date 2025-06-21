#include "functions.h"

Node::Node(Student s) {
  this->student = s;
  this->next = nullptr;
}

Node::~Node() {}

void Node::setNext(Node *next) { this->next = next; }

Node *Node::getNext() { return next; }

void Node::setStudent(Student student) { this->student = student; }

void Node::display() {
    student.display();
}

Student Node::getStudent() { return student; }

Queue::Queue() {
  this->head = nullptr;
  this->tail = nullptr;
  this->count = 0;
}

Queue::~Queue() {
  while (!isEmpty()) {
    dequeue();
  }
}

bool Queue::isEmpty() { return head == nullptr; }

void Queue::enqueue(Student student) {
  Node *newNode = new Node(student);
  if (isEmpty()) {
    head = newNode;
    tail = newNode;
    return;
  } else {
    tail->setNext(newNode);
    tail = newNode;
  }
  count++;
}

Node* Queue::dequeue(){
    Node* ret = new Node(head->getStudent()); 
    pop();
    return ret;
}

void Queue::pop() {
  if (isEmpty()) {
    return;
  } else {
    Node *temp = head;
    delete temp;
    head = head->getNext();
  }
  count--;
}

void Queue::display() {
  if (isEmpty()) {
    cout << "Queue is empty.\n";
    return;
  }

  Node *temp = head;
  while (temp != nullptr) {
    temp->display();
    temp = temp->getNext();
  }
  cout << "nullptr\n";
}


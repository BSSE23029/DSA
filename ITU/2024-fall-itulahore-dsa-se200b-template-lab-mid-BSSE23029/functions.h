#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#pragma once

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
  string name;
  int Class;
  bool isJunior;
  bool isSenior;

public:
  Student() {}
  Student(string n, int c) {

    name = n;
    Class = c;

    isJunior = false;
    isSenior = false;

    if (c >= 1 && c <= 5) {
      isJunior = true;
    }

    if (c >= 6 && c <= 10) {
      isSenior = true;
    }
  }

  string getName() { return name; }

  int getClass() { return Class; }

  void setName(string n) { name = n; }

  void setClass(int c) { name = c; }

  void setJuniorTrue() {
    isJunior = true;
    isSenior = false;
  }

  void setSeniorTrue() {
    isSenior = true;
    isJunior = false;
  }

  bool Junior() { return isJunior; }

  bool Senior() { return isSenior; }

  void display() {

    string section;
    if (Junior()) {
      section = "Junior";
    }

    if (Senior()) {
      section = "Senior";
    }

    cout << "\nName: " << name << "\tClass: " << Class
         << "\tSection: " << section;
  }
};



class Node {
private:
  Student student;
  Node *next;

public:
  Node(Student s);

  ~Node();

  Node* getNext();

  void setNext(Node* next);

  void setStudent(Student student);

  Student getStudent();

  void display();
};

class Queue {
    Node* head;
    Node* tail;
    int count;

    public:

    Queue();
    ~Queue();

    bool isEmpty();
    void enqueue(Student student);
    
    Node* dequeue();

    void pop();
    
    void display();
};


class EntryGate {
private:
  Queue queue;
  int PeakTimeStart = 0715;
  int PeakTimeEnd = 0730;

public:
  void enqueue(Student s) { queue.enqueue(s); }

  void dequeue() { queue.dequeue(); }

  void display() {
    queue.display();
  }

  void Sort(){
    Queue junior;
    Queue senior;

    while(!queue.isEmpty()){

        Node* current = queue.dequeue();

        if(current->getStudent().Junior()){
            junior.enqueue(current->getStudent());
        }

        if(current->getStudent().Senior()){
            senior.enqueue(current->getStudent());
        }

    }
  }
};

#endif
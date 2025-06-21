#include <iostream>
#include "functions.h"
using namespace std;

Stack::Stack() : array(new int[1]), size(0), capacity(1) {}

  Stack::Stack(int cap) : array(new int[cap]), size(0), capacity(cap) {}

  Stack::~Stack() { delete[] array; }

  bool Stack::isEmpty() { return size == 0; }

  void Stack::growArray() {

    capacity *= 2;
    int *temp = new int[capacity];

    for (int i = 0; i < size; i++) {
      temp[i] = array[i];
    }

    // Delete the original array to prevent a memory leak.
    delete[] array;

    // Assign the new array to the array data member.
    array = temp;
  }

  void Stack::push(int data) {
    if (size == capacity) {
      growArray();
    }

    array[size++] = data;
  }

  void Stack::pop() {
    if (size == 0) {
      return;
    }

    size--;
  }

  int Stack::getSize() { return size; }

  int Stack::getCap() { return capacity; }

  void Stack::clear() { size = 0; }

  void Stack::printStack() {
    for (int i = 0; i < size; i++) {
      cout << array[i] << endl;
    }
  }

  int* Stack::getStack() {
    int *temp = new int[capacity];
    // We need to copy the elements in reverse order, so we start
    // from the top element of the stack (at index size-1) and
    // copy it to the first position of the array (at index 0).
    for (int i = size - 1; i >= 0; i--) {
      temp[size - i - 1] = array[i];
    }
    return temp;
  }








Queue::Queue() : array(new int[1]), size(0), capacity(1) {}

  Queue::Queue(int cap) : array(new int[cap]), size(0), capacity(cap) {}

  Queue::~Queue() { delete[] array; }

  bool Queue::isEmpty() { return size == 0; }

  
  void Queue::growArray() {

    // Double the capacity of the array
    capacity *= 2;

    // Create a temporary array with double the capacity
    int *temp = new int[capacity];

    // Copy all the elements from the current array to the new array
    for (int i = 0; i < capacity; i++) {
      temp[i] = array[i];
    }

    // Delete the current array
    delete[] array;

    // Assign the new array to the current array
    array = temp;
  }

  void Queue::enqueue(int data) {

    if (size == capacity) {
      growArray();
    }

    array[size++] = data;
  }

  void Queue::dequeue() {

    if (size == 0) {
      // If the queue is empty, there is nothing to dequeue, so we just
      // return.
      return;
    }

    int *temp = new int[capacity];  // new temporary array

    // Copy all the elements to the temporary array, but starting from the
    // second element of the original array.
    for (int i = 0; i < size - 1; i++) {
      temp[i] = array[i + 1];
    }

    // Delete the original array.
    delete[] array;

    // Assign the temporary array to the array data member.
    array = temp;

    // Decrement the size of the queue since we've removed one element.
    size--;
  }

  int Queue::getSize() { return size; }

  void Queue::clear() { size = 0; }

  void Queue::printQueue() {
    for (int i = 0; i < size; i++) {
      cout << array[i] << endl;
    }
  }

  int* Queue::getQueue() { return array; }


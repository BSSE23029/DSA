#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

using namespace std;

// Design a class named MyArray to keep a list of similar data in the form of an
// array, the data type of the array will be taken from templates. Data Members:
// ●	data: A dynamically allocated array to store the data.
// ●	size: An integer to track the number of elements in the list.
// ●	capacity: An integer to track the maximum number of elements the array
// can hold before resizing.

template <typename T> class MyArray {
  T *data;
  int size;
  int capacity;

public:
  // Member Functions:
  // // Add a constructor that Initializes an empty array with a default
  // capacity MyArray () {
  // }

  MyArray();

  // // Add a destructor that frees the dynamically allocated memory used by the
  // array. ~MyArray () {
  // }

  ~MyArray();

  // // Add function to add an element at the last index of the array
  // void append (T) {
  // }

  void append(T x);

  // // Add function to add an element at the start index of the array
  // void prepend (T) {
  // }

  void prepend(T x);
  // // Add function to contract an array by deleting a value from the last
  // index void deleteFromEnd () {
  // }

  void delete_at_End();

  // // Add function to contract an array by deleting a value from the first
  // index void deleteFromStart () {
  // }

  void delete_at_Start();

  // // Add function to display the elements of the array
  // void display () {
  // }

  void display();

  // // Also add functions to get size, capacity, and array
  // int get_size () {
  // }

  int get_size();

  // int get_capacity () {
  // }

  int get_capacity();

  // T* get_array () {
  // }

  T *get_array();

  void menu();
  
};

#endif

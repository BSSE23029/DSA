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

  T **array;
  int *col_size;
  int row_size;

  bool d;

public:
  MyArray();

  MyArray(bool D);

  MyArray(int capacity);

  ~MyArray();

  void expand(int row_num);

  void append(T value, int row_num = 0);

  void prepend(T value, int row_num = 0);

  void delete_from_last(int row_num = 0);

  void delete_from_start(int row_num = 0);

  // // Add function to display the elements of the array
  // void display () {
  // }

  void display();

  // // Also add functions to get size, capacity, and array
  // int get_size () {
  // }

  void bubbleSort(int row_num);

  int get_size();

  // int get_capacity () {
  // }

  int get_capacity();

  // T* get_array () {
  // }

  T *get_array();

  int getRowSize();

  int getColSize(int row);

  T **getArray();

  void menu1D();
  
  void menu2D();

};

#endif

#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>

using namespace std;

// Implement the MyArray class with dynamic array handling, this task is in
// continuation to your Lab1 task. Ensure the array resizes when needed (when
// inserting beyond capacity). Also implement error handling for invalid
// indices. Use the menu-driven approach to interact with the user and call the
// appropriate methods.  This implementation will also be using templates. Class
// Attributes:
// ●	data ●	size ●	capacity 
// Class Methods:
// ● insertAtIndex ●	removeAtIndex ●	sortArray ●	display ● uniqueElements ●	Menu

template <typename T> class MyArray {
  T *data;
  int size;
  int capacity;

public:
  MyArray();

  MyArray(int capacity);

  ~MyArray();

  void append(T x);

  void prepend(T x);

  void delete_at_End();

  void delete_at_Start();

  int get_size();

  int get_capacity();

  T *get_array();

  bool checkBounds(int index);

  T &operator[](int index);

  void insertAtIndex(T value, int index);

  void removeAtIndex(int index);

  void sortArray(bool order);

  void uniqueElements();

  void menuDisplay();

  void display();

  void menu();
};

#endif

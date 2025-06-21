#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

class MyArray {
private:
  int size; // Size of the array
  int *arr; // Pointer to the integer array

public:
  // Constructor: initializes array with a given size and populates it with
  // random integers
  MyArray(int s);

  // Destructor: deallocates memory
  ~MyArray();

  // Getter for the array pointer
  int *getArr() const;

  // Setter for the array and updates the size
  void setArr(int *newArr, int newSize);

  // Getter for the size of the array
  int getSize() const;

  // Retrieve value at a specific index
  int getAtIndex(int index) const;

  // Set value at a specific index
  void setAtIndex(int index, int value);

  // Helper function to "heapify" a subtree rooted at index i
  void heapify(int n, int i);

  // Perform heap sort on the array
  void heapSort();

  // Display the contents of the array
  void display() const;
};

#endif // FUNCTIONS_H

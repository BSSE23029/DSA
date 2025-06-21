#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

template <typename T> class MyArray {

  T *arr1D;
  T **arr2D;
  T ***arr3D;

  int d0; // The first dimension(columns)
  int d1; // The second dimension(rows)
  int d2; // The third dimension(layers)

public:
  // Constructor
  MyArray(int d0, int d1 = 0, int d2 = 0);

  MyArray(const MyArray &other);

  // Destructor
  ~MyArray();

  void countSort(T *arr, int n, T exp = 1);

  void radix_sort(T *array, size_t n);

  void radixSort1D(T *&array);

  void radixSort2D();

  void radixSort3D();

  void countSort1D(T *&array);

  void countSort2D();

  void countSort3D();

  T *getRow3D(int row, int layer);

  // Assignment-3

  void swapElements(int i, int j);

  int compareElements(T a, T b, char axis);

  int partition(int low, int high, char axis);

  void quickSortHelper(int low, int high, char axis = '\0');

  void quickSort(char axis);

  T getCofactor(int row, int col);

  MyArray<T> *getAdjoint();

  MyArray<T> *getInverse();

  MyArray<T> *transpose(MyArray<T> *matrix);

  T *getDeterminant();

  MyArray<T> *getMinor(int row, int col);

  // Set element in the array
  void setElement(T value, int index0, int index1 = -1, int index2 = -1);

  // Get element from the array
  T getElement(int index0, int index1 = -1, int index2 = -1) const;

  // Display functions
  void display() const;

  int getDimensions() const;

  static MyArray *create(int d0, int d1 = 0, int d2 = 0);

  // Assignment-2

  MyArray *sum(const MyArray &other);

  MyArray *getTranspose();

  T sumElements() const;

  MyArray *multiply(const MyArray &other) const;
};

#endif

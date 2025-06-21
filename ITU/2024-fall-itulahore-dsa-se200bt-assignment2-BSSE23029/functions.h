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

  int d0; // The first dimension
  int d1; // The second dimension
  int d2; // The third dimension

  MyArray(int d0, int d1 = 0, int d2 = 0);

public:
  ~MyArray();

  MyArray(const MyArray &other);

  int getDimensions() const;

  void setElement(double value, int index0, int index1 = 0, int index2 = 0);

  T getElement(int index0, int index1 = 0, int index2 = 0) const;

  void display() const;

  MyArray *sum(const MyArray &other);

  T sumElements() const;
  
  MyArray *multiply(const MyArray &other) const;

  MyArray *getTranspose();

  static MyArray *create(int d0, int d1 = 0, int d2 = 0);
};

#endif

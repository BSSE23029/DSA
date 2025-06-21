#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iomanip> //setw
#include <iostream>

using namespace std;

// 1st colum, 2nd row, 3rd layer

template <typename T> class MyArray {

  T *arr1D;
  T **arr2D;
  T ***arr3D;

  int d0; // The first dimension
  int d1; // The second dimension
  int d2; // The third dimension

public:
  MyArray(int d0, int d1 = 0, int d2 = 0);

  ~MyArray();

  MyArray(const MyArray &other);

  // Insertion Sort for 1D array
    void insertionSort1D(T*& array);

    // Insertion Sort for 2D array
    void insertionSort2D();
    
    // Insertion Sort for 3D array
    void insertionSort3D();

   // Selection Sort for 1D array
    void selectionSort1D(T*& array);

    // Selection Sort for 2D array
    void selectionSort2D();

    // Selection Sort for 3D array
    void selectionSort3D();

    void merge(T*& array, int left, int mid, int right);

    void mergeSortRecursion(T*& array, int left, int right);

    // Merge Sort for 1D array
    void mergeSort1D(T*& array);
    
    // Merge Sort for 2D array
    void mergeSort2D();    

    // Merge Sort for 3D array
    void mergeSort3D();

    // Get row function for 3D array
    T* getRow3D(int row, int layer);

    // Get row function for 2D array
    T* getRow2D(int row);

    // Set Element function
    void setElement(T value, int index1, int index2 = -1, int index3 = -1);

    // Get Element function
    T getElement(int index1, int index2 = -1, int index3 = -1);

  // Assignment-2

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

#include "functions.h"
#include <iostream>

using namespace std;


template <typename T> MyArray<T>::MyArray() {

  // Set the number of rows in the array to 5. (default)
  row_size = 5;

  // Dynamically allocate memory for an array of integers
  col_size = new int[row_size];

  // Dynamically allocate memory for an array of pointers to T
  array = new T *[row_size];

  // Set the boolean variable 'd' to false. (default)
  d = false;

  // Initialize each element of the col_size to 0.
  for (int i = 0; i < row_size; ++i) {

    col_size[i] = 0;

    // Set each element of the array to nullptr.
    array[i] = nullptr;
  }
}


template <typename T> MyArray<T>::MyArray(bool D) {

  // Set the boolean variable 'd' to the value of the parameter 'D'.
  d = D;

  // If 'D' is true, this means we are creating a 1D array.
  if (D) {

    // Initialize the size of the array to 0.
    size = 0;

    // Initialize the capacity of the array to 1.
    capacity = 1;

    // Dynamically allocate memory for an array of capacity
    data = new T[capacity];

  } else { // If 'D' is false, this means we are creating a 2D array.

    // Set the number of rows in the array to 5.
    row_size = 5;

    // Dynamically allocate memory for an array of integers
    col_size = new int[row_size];

    // Dynamically allocate memory for an array of pointers to T
    array = new T *[row_size];

    // Initialize each element of the 'col_size' array to 0.
    for (int i = 0; i < row_size; ++i) {

      col_size[i] = 0;

      // Set each element of the array to nullptr.
      array[i] = nullptr;
    }
  }
} 


template <typename T> MyArray<T>::MyArray(int capacity) {

  // Set the boolean data member 'd' to true, indicating that we are creating a 1D array.
  d = true;

  // Initialize the size of the array to 0.
  size = 0;

  // Set the capacity of the array
  this->capacity = capacity;

  // Dynamically allocate memory for an array of 'capacity' number of elements.
  data = new T[this->capacity];
}

template <typename T> MyArray<T>::~MyArray() {

  // Check if the boolean data member 'd' is true, indicating that we are working with a 1D array.
  if (d) {

    // delete the dynamically allocated memory for the array data
    delete[] data;

  } else {

    // With a 2D array, iterate over each row and delete the dynamically allocated memory for column data of each row.
    for (int i = 0; i < row_size; ++i) {

      // Delete the dynamically allocated memory for the current row.
      delete[] array[i];
    }

    // Delete the dynamically allocated memory for the col_size
    delete[] col_size;

    // Delete the dynamically allocated memory for array
    delete[] array;
  }
}

template <typename T> void MyArray<T>::expand(int row_num) {

  // Check if the 'row_num' parameter is a valid index for the 'row_size' array.
  if (row_num >= 0 && row_num < row_size) {

    // Increment the number of columns in the current row by 1.
    ++col_size[row_num];

    // Dynamically allocate memory for an array of 'col_size[row_num]' number of elements. This represents the new column data for the current row.
    T *temp = new T[col_size[row_num]];

    // Check if the 'array[row_num]' pointer is not null.
    if (array[row_num] != nullptr) {

      // Iterate over the existing column data of the current row.
      for (int i = 0; i < col_size[row_num] - 1; ++i) {

        // Copy the value of the existing column data to new column data.
        temp[i] = array[row_num][i];
      }

      // Delete the dynamically allocated memory for the existing column data of the current row.
      delete[] array[row_num];
    }

    // Assign the pointer to the new column data to the array[row_num] pointer.
    array[row_num] = temp;
  }
}

template <typename T> void MyArray<T>::append(T value, int row_num) {

  if (d) {

    if (size == capacity) {

      capacity *= 2; // double the capacity

      T *temp = new T[capacity]; // create a new teemp array

      for (int i = 0; i < size; i++) { // iterate till size

        temp[i] = data[i]; // copy data
      }

      delete[] data; // delete original data

      data = temp; // transfer temp data to original array
    }

    data[size] = value; // at index = size-1 i.e. starts from zero
    size++;
  } // increase the size by insertion

  else {
    if (row_num >= 0 && row_num < row_size) {
      expand(row_num); // Expand the row if necessary
      array[row_num][col_size[row_num] - 1] = value; // Append the value
    }
  }
}

template <typename T> void MyArray<T>::prepend(T value, int row_num) {

  if (d) {

    if (size == capacity) {

      capacity *= 2; // double the capacity
    }

    T *temp = new T[capacity]; // create a new teemp array

    for (int i = 0; i < size; i++) { // iterate till size

      temp[i + 1] = data[i]; // copy data to index+
    }

    delete[] data; // delete original data

    data = temp; // transfer temp data to original array

    data[0] = value; // add at first index

    size++; // increase the size by insertion
  }

  else {

    if (row_num >= 0 && row_num < row_size) {

      expand(row_num); // Expand the row if necessary

      for (int i = col_size[row_num]; i > 0; --i) {

        array[row_num][i] = array[row_num][i - 1];
      }

      array[row_num][0] = value; // Insert the value at the start
    }
    else {
      cout << "Row number is not valid" << endl;
    }
  }
}

template <typename T> void MyArray<T>::delete_from_last(int row_num) {

  // If the array is 1D (d flag is true)
  if (d) {

    // Decrease the size of the array by 1
    size--;
  } else {

    // If the row number is valid
    if (row_num >= 0 && row_num < row_size) {

      // Create a new temporary array to hold the elements of the current row minus the last element
      T *temp = new T[col_size[row_num - 1]];

      // If the current row has already been expanded
      if (array[row_num] != nullptr) {

        // Copy all the elements of the current row to the temporary array except for the last element
        for (int i = 0; i < col_size[row_num] - 1; ++i) {
          temp[i] = array[row_num][i];
        }

        // Delete the dynamically allocated memory for the current row
        delete[] array[row_num];
      }

      // Assign the pointer to the temporary array to the current row
      array[row_num] = temp;

      // Decrease the size of the current row by 1
      --col_size[row_num];
    }

    // If the row number is not valid
    else {
      cout << "Row number is not valid" << endl;
    }
  }
}

template <typename T> void MyArray<T>::delete_from_start(int row_num) {

  if (d) { // delete the first element

    for (int i = 1; i < size; i++) {

      data[i - 1] = data[i];
    }

    size--;

  } else {

    // Check if the row number is valid
    if (row_num >= 0 && row_num < row_size) {

      // Check if the current row has elements
      if (col_size[row_num] > 0) {

        // Shift all elements in the current row to the left by one position
        for (int i = 1; i < col_size[row_num]; ++i) {

          array[row_num][i - 1] = array[row_num][i];
        }

        // Decrease the size of the current row by 1
        --col_size[row_num];

        // Check if the current row is empty after deleting the first element
        if (col_size[row_num] == 0) {

          // Delete the dynamically allocated memory for the current row
          delete[] array[row_num];

          // Set the pointer to the current row to null
          array[row_num] = nullptr;
        }
      }
    }
    else {
      cout << "Row number is not valid" << endl;
    }
  }
}

template <typename T> void MyArray<T>::display() {
  if (d) {
    cout << "Size: " << size << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
      cout << data[i];
      if (i < size - 1)
        cout << ", ";
    }
    cout << endl;
  }
  else {
    for (int i = 0; i < row_size; ++i) {
      bool isEmpty = true;
      cout << "Array index " << i + 1 << " :";
      for (int j = 0; j < col_size[i]; ++j) {
        cout << array[i][j] << " ";
        isEmpty = false;
      }
      if (isEmpty) {
        cout << "[]" << endl;
      } else {
        cout << endl;
      }
    }
  }
}

template <typename T> void MyArray<T>::bubbleSort(int row_num) {

  // Check if the given row number is within the valid range
  if (row_num >= 0 && row_num < row_size) {

    // Get the number of elements in the current row
    int n = col_size[row_num];

    // Perform the bubble sort algorithm on the current row
    for (int i = 0; i < n - 1; ++i) {

      // Compare each pair of adjacent elements in the current row
      for (int j = 0; j < n - i - 1; ++j) {

        // If the current element is greater than the next element
        if (array[row_num][j] > array[row_num][j + 1]) {

          // Swap the elements

          // Create a temporary variable to hold the value of the current element
          T temp = array[row_num][j];

          // Assign the value of the next element to the current element
          array[row_num][j] = array[row_num][j + 1];

          // Assign the value of the temporary variable to the next element
          array[row_num][j + 1] = temp;
        }
      }
    }
  }
  else {
      cout << "Row number is not valid" << endl;
    }
}

template <typename T> int MyArray<T>::get_size() { return size; }

template <typename T> int MyArray<T>::get_capacity() { return capacity; }

template <typename T> T *MyArray<T>::get_array() { return data; }

template <typename T> int MyArray<T>::getRowSize() { return row_size; }

template <typename T> int MyArray<T>::getColSize(int row) {
  return col_size[row];
}

template <typename T> T **MyArray<T>::getArray() { return array; }

// functions end here

template <typename T> void MyArray<T>::menu1D() {

  // uses perimeters and functions for calling 1D array operations

  int choice;
  do {
    cout << "Array List Operations" << endl;
    cout << "1. Append" << endl;
    cout << "2. Prepend" << endl;
    cout << "3. Delete from start" << endl;
    cout << "4. Delete from end" << endl;
    cout << "5. Display" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice;

    switch (choice) {
    case 1: {

      cout << endl << "Enter data: ";
      T x;
      cin >> x;
      append(x);
      cout << endl;

      break;
    }

    case 2: {

      cout << endl << "Enter data: ";
      T x;
      cin >> x;
      prepend(x);
      cout << endl;

      break;
    }

    case 3: {

      delete_from_start();
      cout << endl;

      break;
    }

    case 4: {

      delete_from_last();
      cout << endl;

      break;
    }

    case 5: {

      display();
      cout << endl;

      break;
    }
    }
  } while (choice != 0);
}

template <typename T> void MyArray<T>::menu2D() {

  // uses perimeters and functions for calling 2D array operations

  int choice;
  do {

    cout << "Array List Operations" << endl;
    cout << "1. Append" << endl;
    cout << "2. Prepend" << endl;
    cout << "3. Delete from start" << endl;
    cout << "4. Delete from end" << endl;
    cout << "5. Bubble sort" << endl;
    cout << "6. Display" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice;

    switch (choice) {
    case 1: {

      cout << endl << "Enter row(0,1,2,3,4): ";
      int x;
      cin >> x;
      cout << endl << "Enter data: ";
      T r;
      cin >> r;
      append(r, x);
      cout << endl;

      break;
    }

    case 2: {

      cout << endl << "Enter row(0,1,2,3,4): ";
      int x;
      cin >> x;
      cout << endl << "Enter data: ";
      T r;
      cin >> r;
      prepend(r, x);
      cout << endl;

      break;
    }

    case 3: {

      cout << endl << "Enter row(0,1,2,3,4): ";
      int x;
      cin >> x;

      delete_from_start(x);
      cout << endl;

      break;
    }

    case 4: {

      cout << endl << "Enter row(0,1,2,3,4): ";
      int x;
      cin >> x;

      delete_from_last(x);
      cout << endl;

      break;
    }

    case 5: {

      cout << endl << "Enter row(0,1,2,3,4): ";
      int x;
      cin >> x;

      bubbleSort(x);

      cout << "\nRow " << x << " is bubble sorted!\n";

      break;
    }

    case 6: {

      cout << endl;
      cout << endl;
      display();
      cout << endl;
      cout << endl;

      break;
    }
    }
  } while (choice != 0);
}

void tempor() {

  MyArray<int> arrwea(true);
  MyArray<float> arrrsd(true);
  MyArray<double> arrd(true);
  MyArray<string> arrrd(true);

  MyArray<int> arr;

  arr.expand(2);
  arr.append(2);
  arr.prepend(2);
  arr.delete_from_last();
  arr.delete_from_start();
  arr.display();
  arr.bubbleSort(1);
  arr.get_size();
  arr.get_capacity();
  arr.get_array();
  arr.getRowSize();
  arr.getColSize(2);
  arr.getArray();
  arr.menu1D();
  arr.menu2D();

  MyArray<double> darr;

  darr.expand(2);
  darr.append(2);
  darr.prepend(2);
  darr.delete_from_last();
  darr.delete_from_start();
  darr.display();
  darr.bubbleSort(1);
  darr.get_size();
  darr.get_capacity();
  darr.get_array();
  darr.getRowSize();
  darr.getColSize(2);
  darr.getArray();
  darr.menu1D();
  darr.menu2D();

  MyArray<float> farr;

  farr.expand(2);
  farr.append(2);
  farr.prepend(2);
  farr.delete_from_last();
  farr.delete_from_start();
  farr.display();
  farr.bubbleSort(1);
  farr.get_size();
  farr.get_capacity();
  farr.get_array();
  farr.getRowSize();
  farr.getColSize(2);
  farr.getArray();
  farr.menu1D();
  farr.menu2D();

  MyArray<string> sarr;

  sarr.expand(2);
  sarr.append("A");
  sarr.prepend("A");
  sarr.delete_from_last();
  sarr.delete_from_start();
  sarr.display();
  sarr.bubbleSort(1);
  sarr.get_size();
  sarr.get_capacity();
  sarr.get_array();
  sarr.getRowSize();
  sarr.getColSize(2);
  sarr.getArray();
  sarr.menu1D();
  sarr.menu2D();
}
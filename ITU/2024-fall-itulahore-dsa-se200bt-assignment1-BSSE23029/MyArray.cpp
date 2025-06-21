#include "MyArray.h"
#include <iostream>

using namespace std;

template <typename T> MyArray<T>::MyArray() {
  size = 0;
  capacity = 1;
  data = new T[capacity];
}

template <typename T> MyArray<T>::MyArray(int capacity) {
  size = 0;
  this->capacity = capacity;
  data = new T[this->capacity];
}

template <typename T> MyArray<T>::~MyArray() { delete[] data; }

template <typename T> void MyArray<T>::append(T x) {
  if (size == capacity) {
    capacity *= 2; // double the capacity

    T *temp = new T[capacity];       // create a new teemp array
    for (int i = 0; i < size; i++) { // iterate till size
      temp[i] = data[i];             // copy data
    }

    delete[] data; // delete original data
    data = temp;   // transfer temp data to original array
  }

  data[size] = x; // at index = size-1 i.e. starts from zero, ai [size] the
                  // array is empty, add ne data
  size++;         // increase the size by insertion
}

template <typename T> void MyArray<T>::prepend(T x) {
  if (size == capacity) {
    capacity *= 2; // double the capacity
  }

  T *temp = new T[capacity];       // create a new teemp array
  for (int i = 0; i < size; i++) { // iterate till size
    temp[i + 1] = data[i];         // copy data to index+
  }

  delete[] data; // delete original data
  data = temp;   // transfer temp data to original array
  data[0] = x;   // add at first index
  size++;        // increase the size by insertion
}

template <typename T> void MyArray<T>::delete_at_End() { size--; }

template <typename T> void MyArray<T>::delete_at_Start() {
  // delete the first element
  for (int i = 1; i < size; i++) {
    data[i - 1] = data[i];
  }
  size--;
}

template <typename T> int MyArray<T>::get_size() { return size; }

template <typename T> int MyArray<T>::get_capacity() { return capacity; }

template <typename T> T *MyArray<T>::get_array() { return data; }

template <typename T> bool MyArray<T>::checkBounds(int index) {

  // bounds checking
  if ((index > size) || (index < 0)) { // is index is out of possible bounds
    return false;
  }
  return true;
}

template <typename T> T &MyArray<T>::operator[](int index) {
  try {
    // bounds checking

    if (!checkBounds(index)) {

      // If the index is out of bounds, throw an exception to handle the error.
      throw out_of_range("Index out of bounds");
    }

    return data[index];
  }

  catch (const out_of_range &e) {

    cerr << "Error: " << e.what() << endl;
    exit(EXIT_FAILURE); // terminate the program normally and informs the
                        // operating system that the program was unsuccessful
  }
}

// Task 1: Insert At Index
// Inserts an element at a specific index in the array. If the index is out of
// bounds, display an error message. Resize the array if necessary. Example:
// 		Input: Enter element to insert: 4
//  Input: Enter index to insert at: 2
// Output: Array [10, 5, 4, 1, 7, 9, 0, 2]

template <typename T> void MyArray<T>::insertAtIndex(T value, int index) {
  try {

    // bounds checking
    if (!checkBounds(index)) {
      // If the index is out of bounds, throw an exception to handle the error.
      throw out_of_range("Index out of bounds");

    } else {
      // If the index is within bounds, try to insert the value at the given
      // index.
      if (size == capacity) {
        // If the array is at capacity, double the capacity.
        capacity *= 2;
        // Create a temporary array of the new capacity.
        T *temp = new T[capacity];
        // Copy all the elements from the original array to the new array.
        for (int i = 0; i < size; i++) {
          temp[i] = data[i];
        }
        // Delete the original array.
        delete[] data;
        // Set the data pointer to the new array.
        data = temp;
      }

      // Shift all the elements after the given index one position to the right.
      for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
      }

      // Insert the value at the given index.
      data[index] = value;
      // Increment the size of the array because we just inserted an element.
      size++;
    }
  }

  catch (const out_of_range &oor) {
    // If the index was out of bounds, print an error message to the console.
    cerr << oor.what() << endl;
  }
}

// Task 2: Remove At Index:
// Removes an element from a specific index in the array. If the index is out of
// bounds, display an error message. Adjust the array size accordingly. Example:
//   Input: Enter index to remove from: 2
//  Output: Array [10, 5, 1, 7, 9, 0, 2]

template <typename T> void MyArray<T>::removeAtIndex(int index) {

  try {
    // Bounds checking invalid index.
    if (!checkBounds(index)) {

      // If the index is out of bounds, throw an exception to handle the error.
      throw out_of_range("Index out of bounds");
      return; // If the index is out of bounds, return from the function.

    } else {

      // all of the elements after the index one position to the left in the
      // array.
      for (int i = index; i < size - 1; i++) {

        // Copy the element at the next index into the current index.
        data[i] = data[i + 1];
      }

      // Decrement the size of the array because we just removed an element.
      size--;
    }
  } catch (const out_of_range &oor) {

    // If the index was out of bounds, print an error message to the console.
    cerr << oor.what() << endl;
  }
}

// Task 3: sortArray:
// Sorts the array in ascending order or descending order based on boolean
// parameter if true - ascending else descending Example:
//  Output: Array [0, 1, 2, 5, 7, 9, 10]

template <typename T> void MyArray<T>::sortArray(bool order) {

  if (order) {                           // ascending
    for (int i = 0; i < size - 1; i++) { // itterating the array
      for (int j = 0; j < size - i - 1;
           j++) { // itterating the array till previously iterated indexes
        if (data[j] >
            data[j + 1]) {  // if current found is greater then the next one
          T temp = data[j]; // swap
          data[j] = data[j + 1]; // swap
          data[j + 1] = temp;    // swap
        }
      }
    }
  }

  else { // descending
    for (int i = 0; i < size - 1; i++) {
      for (int j = 0; j < size - i - 1; j++) {
        if (data[j] <
            data[j + 1]) { // if current found is less then the next one
          T temp = data[j];
          data[j] = data[j + 1];
          data[j + 1] = temp;
        }
      }
    }
  }

  cout << "\nArray is Sorted\n";
}

// Task 4: display:
// Displays the current elements of the array.

template <typename T> void MyArray<T>::display() {
  for (int i = 0; i < size; i++) {
    cout << data[i] << " ";
  }
  cout << endl;
}

template <typename T> void MyArray<T>::menuDisplay() {
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

// Task 5: uniqueElements:
// This function will ensure that any repeated element in the array would be
// removed.

template <typename T> void MyArray<T>::uniqueElements() {

  for (int i = 0; i < size - 1; i++) { // run from first till last element
    for (int j = i + 1; j < size;
         j++) { // run the remaining elements except the first one

      if (data[i] == data[j]) { // if same element is found
        for (int k = j; k < size - 1;
             k++) { // run the loop from index where the copy is found till end
          data[k] = data[k + 1]; // push back the elements, over-writting the
                                 // copy index with next one
        }

        size--; // reduce the size of array with 1
        j--;    // since k depends on j & size, it is also modified the same
      }
    }
  }

  cout << "\nUnique Elements Removed\n";
}

// Task 6: menu:
// Displays a menu with the following options:
//  Enter 1 to insert at a given index
//  Enter 2 to remove from a given index
//  Enter 3 to sort the array
// Enter 4 to display the array
// Enter 5 to remove duplicates
// Enter 0 to Exit

template <typename T> void MyArray<T>::menu() {
  int choice;
  do {
    cout << "Array List Operations" << endl;
    cout << "1. Insert at index" << endl;
    cout << "2. Remove from index" << endl;
    cout << "3. Sort" << endl;
    cout << "4. Display" << endl;
    cout << "5. Remove duplicates" << endl;
    cout << "6. Append" << endl;
    cout << "7. Prepend" << endl;
    cout << "8. Delete from start" << endl;
    cout << "9. Delete from end" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice;

    switch (choice) {
    case 1: {
      int index;
      cout << "Enter index: ";
      cin >> index;
      cout << "Enter data: ";
      T x;
      cin >> x;
      insertAtIndex(x, index);
      cout << endl;

      break;
    }

    case 2: {
      int index;
      cout << "Enter index: ";
      cin >> index;
      removeAtIndex(index);
      cout << endl;

      break;
    }

    case 3: {
      bool order;
      cout << "Enter 1 for ascending or 0 for descending: ";
      cin >> order;
      sortArray(order);
      cout << endl;

      break;
    }

    case 4: {
      menuDisplay();
      cout << endl;

      break;
    }

    case 5: {
      uniqueElements();
      cout << endl;

      break;
    }

    case 6: {
      cout << endl << "Enter data: ";
      T x;
      cin >> x;
      append(x);
      cout << endl;

      break;
    }

    case 7: {
      cout << endl << "Enter data: ";
      T x;
      cin >> x;
      prepend(x);
      cout << endl;

      break;
    }

    case 8: {
      delete_at_Start();
      cout << endl;

      break;
    }

    case 9: {
      delete_at_End();
      cout << endl;

      break;
    }
    }
  } while (choice != 0);
}

void tempor() {
  MyArray<int> arr;

  MyArray<int> a(1);

  a[1];

  arr.append(1);
  arr.prepend(0);
  arr.delete_at_Start();
  arr.delete_at_End();
  arr.display();
  arr.get_size();
  arr.get_capacity();
  arr.get_array();
  arr.menu();
  arr.checkBounds(1);
  arr.insertAtIndex(1, 1);
  arr.removeAtIndex(1);
  arr.sortArray(true);
  arr.uniqueElements();
  arr.menuDisplay();

  MyArray<double> darr;

  MyArray<double> b(1);

  b[1];

  darr.append(1);
  darr.prepend(0);
  darr.delete_at_Start();
  darr.delete_at_End();
  darr.display();
  darr.get_size();
  darr.get_capacity();
  darr.get_array();
  darr.menu();
  darr.checkBounds(1);
  darr.insertAtIndex(1, 1);
  darr.removeAtIndex(1);
  darr.sortArray(true);
  darr.uniqueElements();
  darr.menuDisplay();

  MyArray<float> farr;

  MyArray<float> c(1);

  c[1];

  farr.append(1);
  farr.prepend(0);
  farr.delete_at_Start();
  farr.delete_at_End();
  farr.display();
  farr.get_size();
  farr.get_capacity();
  farr.get_array();
  farr.menu();
  farr.checkBounds(1);
  farr.insertAtIndex(1, 1);
  farr.removeAtIndex(1);
  farr.sortArray(true);
  farr.uniqueElements();
  farr.menuDisplay();

  MyArray<string> sarr;

  MyArray<string> d(1);
  d[1];

  sarr.append("zxcvb");
  sarr.prepend("fvrtyb");
  sarr.delete_at_Start();
  sarr.delete_at_End();
  sarr.display();
  sarr.get_size();
  sarr.get_capacity();
  sarr.get_array();
  sarr.menu();
  sarr.checkBounds(1);
  sarr.insertAtIndex("fvryw", 1);
  sarr.removeAtIndex(1);
  sarr.sortArray(true);
  sarr.uniqueElements();
  sarr.menuDisplay();
}
#include "functions.h"
#include <iostream>

using namespace std;

template <typename T> MyArray<T>::MyArray() {
  size = 0;
  capacity = 1;
  data = new T[capacity];
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
  for (int i = 1; i < size; i++) {
    data[i - 1] = data[i];
  }
  size--;
}

template <typename T> void MyArray<T>::display() {
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

template <typename T> int MyArray<T>::get_size() { return size; }

template <typename T> int MyArray<T>::get_capacity() { return capacity; }

template <typename T> T *MyArray<T>::get_array() { return data; }

template <typename T> void MyArray<T>::menu() {
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
      delete_at_Start();
      cout << endl;

      break;
    }

    case 4: {
      delete_at_End();
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

void tempor() {
  MyArray<int> arr;

  arr.append(1);
  arr.append(2);
  arr.append(3);

  arr.prepend(0);

  arr.delete_at_Start();

  arr.delete_at_End();

  arr.display();

  arr.get_size();

  arr.get_capacity();

  arr.get_array();
  arr.menu();

  MyArray<double> darr;

  darr.append(1);
  darr.append(2);
  darr.append(3);

  darr.prepend(0);

  darr.delete_at_Start();

  darr.delete_at_End();

  darr.display();

  darr.get_size();

  darr.get_capacity();

  darr.get_array();
  darr.menu();

  MyArray<float> farr;

  farr.append(1);
  farr.append(2);
  farr.append(3);

  farr.prepend(0);

  farr.delete_at_Start();

  farr.delete_at_End();

  farr.display();

  farr.get_size();

  farr.get_capacity();

  farr.get_array();
  farr.menu();

  MyArray<string> sarr;

  sarr.append("sdfg");
  sarr.append("qwert");
  sarr.append("zxcvb");

  sarr.prepend("fvrtyb");

  sarr.delete_at_Start();

  sarr.delete_at_End();

  sarr.display();

  sarr.get_size();

  sarr.get_capacity();

  sarr.get_array();
  sarr.menu();
}
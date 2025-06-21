#include "functions.h"

// Constructor: initializes array with a given size and populates it with random
// integers
MyArray::MyArray(int s) : size(s) {
  arr = new int[size];
  srand(time(0));
  for (int i = 0; i < size; ++i) {
    arr[i] = rand() % 100; // Populate with random integers
  }
}

// Destructor: deallocates memory
MyArray::~MyArray() { delete[] arr; }

// Getter for the array pointer
int *MyArray::getArr() const { return arr; }

// Setter for the array and updates the size
void MyArray::setArr(int *newArr, int newSize) {
  delete[] arr; // Free the old array memory
  arr = newArr;
  size = newSize;
}

// Getter for the size of the array
int MyArray::getSize() const { return size; }

// Retrieve value at a specific index
int MyArray::getAtIndex(int index) const {
  if (index >= 0 && index < size) {
    return arr[index];
  }
  throw out_of_range("Index out of range");
}

// Set value at a specific index
void MyArray::setAtIndex(int index, int value) {
  if (index >= 0 && index < size) {
    arr[index] = value;
  }
}

// Helper function to "heapify" a subtree rooted at index i
void MyArray::heapify(int n, int i) {
  int largest = i; // Initialize largest as root
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  // If left child is larger than root
  if (left < n && arr[left] > arr[largest])
    largest = left;

  // If right child is larger than largest so far
  if (right < n && arr[right] > arr[largest])
    largest = right;

  // If largest is not root
  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(n, largest);
  }
}

// Perform heap sort on the array
void MyArray::heapSort() {
  // Build max heap
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(size, i);
  }

  // Extract elements from heap one by one
  for (int i = size - 1; i > 0; i--) {
    swap(arr[0], arr[i]); // Move current root to end
    heapify(i, 0);        // Call max heapify on the reduced heap
  }
}

// Display the contents of the array
void MyArray::display() const {
  for (int i = 0; i < size; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
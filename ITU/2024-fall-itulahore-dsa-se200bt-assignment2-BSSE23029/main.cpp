#include "functions.h"
#include <iostream>

using namespace std;

// there is no need for commenting brcause there is only function calling here,
// the structure has to be understood in the header files

void displayMenu() {
  cout << "\n--- Simple MyArray Menu ---\n";
  cout << "1. Create and Display Array\n";
  cout << "2. Set Element Value\n";
  cout << "3. Get Element Value\n";
  cout << "4. Sum Elements\n";
  cout << "5. Sum an 2nd Array\n";
  cout << "6. Multiply(Dot Product) an 2nd Array\n";
  cout << "7. Transpose Array\n";
  cout << "0. Exit\n";
}

MyArray<int> *createUserInputArray() {
  int size;
  cout << "Enter array size: ";
  cin >> size;

  MyArray<int> *array = MyArray<int>::create(size);

  cout << "Enter values for the array:\n";
  for (int i = 0; i < size; ++i) {
    int value;
    cout << "Element [" << i << "]: ";
    cin >> value;
    array->setElement(value, i);
  }

  cout << "\nCreated Array:\n";
  array->display();

  return array;
}

void setElement(MyArray<int> *array) {
  int index, value;
  cout << "Enter index and value to set:\n";
  cout << "Index: ";
  cin >> index;
  cout << "Value: ";
  cin >> value;
  array->setElement(value, index);
  cout << "\nUpdated Array:\n";
  array->display();
}

void getElement(MyArray<int> *array) {
  int index;
  cout << "Enter index to get element:\n";
  cout << "Index: ";
  cin >> index;
  int value = array->getElement(index);
  cout << "\nElement at index [" << index << "] is: " << value << endl;
}

void sumElements(MyArray<int> *array) {
  int sum = array->sumElements();
  cout << "\nSum of all elements in the array: " << sum << endl;
}

void sum2nD(MyArray<int> *array) {
  MyArray<int> *array2 = createUserInputArray();
  MyArray<int> *result = array->sum(*array2);
  result->display();
}

void multiply2nD(MyArray<int> *array) {
  MyArray<int> *array2 = createUserInputArray();
  MyArray<int> *result = array->multiply(*array2);
  result->display();
}

void Transpose(MyArray<int> *array) {
  MyArray<int> *result = array->getTranspose();
  result->display();
}

int main() {

  MyArray<int> *array = nullptr;
  char choice;

  do {
    displayMenu();
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case '1': {
      array = createUserInputArray();
      break;
    }
    case '2': {
      if (!array) {
        cout << "No array exists. Please create one first." << endl;
      } else {
        setElement(array);
      }
      break;
    }
    case '3': {
      if (!array) {
        cout << "No array exists. Please create one first." << endl;
      } else {
        getElement(array);
      }
      break;
    }
    case '4': {
      if (!array) {
        cout << "No array exists. Please create one first." << endl;
      } else {
        sumElements(array);
      }
      break;
    }
    case '5': {
      if (!array) {
        cout << "No array exists. Please create one first." << endl;
      } else {
        sum2nD(array);
      }
      break;
    }
    case '6': {
      if (!array) {
        cout << "No array exists. Please create one first." << endl;
      } else {
        multiply2nD(array);
      }
      break;
    }
    case '7': {
      if (!array) {
        cout << "No array exists. Please create one first." << endl;
      } else {
        Transpose(array);
      }
      break;
    }
    case '0':
      cout << "Exiting program. Goodbye!" << endl;
      break;
    default:
      cout << "Invalid choice. Please try again." << endl;
    }

    if (choice != '0') {
      cout << "\nPress Enter to continue...";
      cin.ignore();
      cin.get();
    }
  } while (choice != '0');

  delete array;
  return 0;
}

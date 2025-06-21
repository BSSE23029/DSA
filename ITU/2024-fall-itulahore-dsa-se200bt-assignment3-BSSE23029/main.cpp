#include "functions.h"

// Main menu function
void menu() {
  int choice;

  // Loop until the user chooses to exit
  do {
    // Display menu options
    cout << "1. Determinant of 2D array" << endl;
    cout << "2. Inverse of 2D array" << endl;
    cout << "3. Quick Sort 1D array" << endl;
    cout << "0. Exit" << endl;
    
    // Read user input
    cin >> choice;

    // Switch based on user choice
    switch (choice) {
    case 1: {
      // Create a 4x4 integer array
      MyArray<int> *array = MyArray<int>::create(4, 4);

      // Prompt user to enter elements of 2D array
      cout << "Enter elements of 2D array: " << endl;
      for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
          int a;
          cout << "Index[" << i << "]"
               << "[" << j << "]: ";
          cin >> a;
          array->setElement(a, i, j);
        }
      }

      // Display original array
      cout << "\n------------------------------Original-----------------------------------\n";
      array->display();

      // Calculate and display determinant
      int *result = array->getDeterminant();
        cout << "\n------------------------------Result-----------------------------------\n";
        cout << "Determinant of 2D array: " << *result << endl << endl;

      // Clean up memory
      delete array;
      break;
    }

    case 2: {
      // Create a 3x3 integer array
      MyArray<int> *array = MyArray<int>::create(3, 3);

      // Prompt user to enter elements of 2D array
      cout << "Enter elements of 2D array: " << endl;
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          int a, b;
          cout << "Index[" << i << "]" << "[" << j << "]: ";
          cin >> a;
          array->setElement(a, i, j);
        }
      }

      // Display original array
      cout << "\n------------------------------Original-----------------------------------\n";
        array->display();

      // Calculate inverse and display result
        MyArray<int>* result = array->getInverse();
        cout << "\n------------------------------Result-----------------------------------\n";
        result->display();

      // Clean up memory
      delete result;
      break;
    }

    case 3: {
      // Create a 1D integer array
      MyArray<int> *array = MyArray<int>::create(5);

      // Prompt user to enter elements of 1D array
      for (int i = 0; i < 5; ++i) {
        int a, b;
        cout << "Index[" << i << "]: ";
        cin >> a;
        array->setElement(a, i);
      }

      // Display original array
      cout << "\n------------------------------Original-----------------------------------\n";
      array->display();

      // Perform quick sort along x-axis
      array->quickSort('x');

      // Display sorted array
      cout << "\n------------------------------Result-----------------------------------\n";
      array->display();

      // Clean up memory
      delete array;
      break;
    }

    case 0: {
      // Exit message
      cout << "\n\nExiting......" << endl;
    }
    }

  } while (choice != 0);
}


int main() {

  menu();

  return 0;
}
#include "functions.h"

int main() {

  cout << endl << endl << endl;

  MyArray *myArray = nullptr;
  int choice;
  int size, index, value;

  do {
    cout << "\nMenu:\n";
    cout << "1. Create Array\n";
    cout << "2. Display Array\n";
    cout << "3. Set Value at Index\n";
    cout << "4. Get Value at Index\n";
    cout << "5. Heap Sort\n";
    cout << "0. Exit\n";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: // Create Array
      cout << "\nEnter the size of the array: ";
      cin >> size;
      if (myArray != nullptr) {
        delete myArray;
      }
      myArray = new MyArray(size);
      cout << "\nArray created with random values.\n";
      myArray->display();
      break;

    case 2: // Display Array
      if (myArray != nullptr) {
        cout << "\nArray contents: ";
        myArray->display();
      } else {
        cout << "\nArray not created. Please create an array first.\n";
      }
      break;

    case 3: // Set Value at Index
      if (myArray != nullptr) {
        cout << "Enter index to set value: ";
        cin >> index;
        cout << "\nEnter value to set at index " << index << ": ";
        cin >> value;
        myArray->setAtIndex(index, value);
        cout << "\nValue set successfully.\n";
      } else {
        cout << "\nArray not created. Please create an array first.\n";
      }
      break;

    case 4: // Get Value at Index
      if (myArray != nullptr) {
        cout << "\nEnter index to get value: ";
        cin >> index;
        try {
          value = myArray->getAtIndex(index);
          cout << "\nValue at index " << index << ": " << value << endl;
        } catch (const out_of_range &e) {
          cout << "\nError: " << e.what() << endl;
        }
      } else {
        cout << "\nArray not created. Please create an array first.\n";
      }
      break;

    case 5: // Heap Sort
      if (myArray != nullptr) {
        cout << "\nSorting array using Heap Sort...\n";
        myArray->heapSort();
        cout << "\nArray sorted.\n";
        myArray->display();
      } else {
        cout << "\nArray not created. Please create an array first.\n";
      }
      break;

    case 0: // Exit
      cout << "\nExiting program.\n";
      break;

    default:
      cout << "\nInvalid choice. Please try again.\n";
      break;
    }
  } while (choice != 0);

  // Clean up the dynamically allocated array
  delete myArray;

  cout << endl << endl << endl;

  return 0;
}
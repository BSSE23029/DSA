#include "functions.h"
#include <iostream>

using namespace std;

void menu() {
  int d0, d1, d2;
  cout << "\nEnter dimensions (columns, rows, layers): ";
  cout << "\nColumns: ";
  cin >> d0;
  cout << "\nRows: ";
  cin >> d1;
  cout << "\nLayers: ";
  cin >> d2;

  MyArray<int> array(d0, d1, d2);

  int choice;
  do {
    cout << "\nMenu:\n";
    cout << "1. Set Element\n";
    cout << "2. Get Element\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Selection Sort\n";
    cout << "5. Merge Sort (3D Array)\n";
    cout << "6. Display Array\n";
    cout << "0. Exit\n";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
      int value, index1, index2, index3;
      cout << "\nEnter value: ";
      cin >> value;
      cout << "\nColumn: ";
      cin >> index1;
      cout << "\nRow: ";
      cin >> index2;
      cout << "\nLayer: ";
      cin >> index3;
      array.setElement(value, index1, index2, index3);
      break;
    }
    case 2: {
      int index1, index2, index3;
      cout << "\nColumn: ";
      cin >> index1;
      cout << "\nRow: ";
      cin >> index2;
      cout << "\nLayer: ";
      cin >> index3;
      int value = array.getElement(index1, index2, index3);
      cout << "Element at (" << index1 << ", " << index2 << ", " << index3
           << ") is: " << value << endl;
      break;
    }
    case 3: {
      cout << "Performing Insertion Sort on 3D array...\n";
      array.insertionSort3D();
      cout << "Sorting complete.\n";
      break;
    }
    case 4: {
      cout << "Performing Selection Sort on 3D array...\n";
      array.selectionSort3D();
      cout << "Sorting complete.\n";
      break;
    }
    case 5: {
      cout << "Performing Merge Sort on 3D array...\n";
      array.mergeSort3D();
      cout << "Sorting complete.\n";
      break;
    }
    case 6: {
      array.display();
      break;
    }
    case 0: {
      cout << "Exiting program.\n";
      break;
    }
    default: {
      cout << "Invalid choice. Please try again.\n";
      break;
    }
    }
  } while (choice != 0);
}

int main() {

  MyArray<int> array(3, 2, 2); // 3 columns, 2 rows, 2 layers

    array.setElement(2, 0, 0, 0);
    array.setElement(1, 1, 0, 0);
    array.setElement(5, 2, 0, 0);

    array.setElement(3, 0, 1, 0);
    array.setElement(4, 1, 1, 0);
    array.setElement(1, 2, 1, 0);

    array.setElement(5, 0, 0, 1);
    array.setElement(8, 1, 0, 1);
    array.setElement(2, 2, 0, 1);

    array.setElement(6, 0, 1, 1);
    array.setElement(7, 1, 1, 1);
    array.setElement(5, 2, 1, 1);


    array.display();

    array.selectionSort3D();

    cout << "\n\n\n\n\n---------------------------------Sorted Array-------------------------------------\n\n\n\n\nss";

    array.display();


  //menu();
  
  return 0;
}

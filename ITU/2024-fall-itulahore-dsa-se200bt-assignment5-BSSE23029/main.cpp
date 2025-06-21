#include "functions.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void displayMenu() {
  cout << "Sorting Algorithms Menu" << endl;
  cout << "------------------------" << endl;
  cout << "1. Bubble Sort" << endl;
  cout << "2. Selection Sort" << endl;
  cout << "3. Insertion Sort" << endl;
  cout << "4. Merge Sort" << endl;
  cout << "5. Quick Sort" << endl;
  cout << "6. Count Sort" << endl;
  cout << "7. Radix Sort" << endl;
  cout << "0. Exit" << endl;
  cout << "Enter your choice: ";
}

void generateRandomList(List &myList) {
  for (int i = 0; i < 10; i++) {
    myList.append(rand() % 100000);
  }
}

void runSortingAlgorithm(int choice, List &myList) {
  switch (choice) {
  case 1:
    cout << "\nBubble Sort:" << endl;
    break;
  case 2:
    cout << "\nSelection Sort:" << endl;
    break;
  case 3:
    cout << "\nInsertion Sort:" << endl;
    break;
  case 4:
    cout << "\nMerge Sort:" << endl;
    break;
  case 5:
    cout << "\nQuick Sort:" << endl;
    break;
  case 6:
    cout << "\nCount Sort:" << endl;
    break;
  case 7:
    cout << "\nRadix Sort:" << endl;
    break;
  default:
    return;
  }

  generateRandomList(myList);
  cout << "List to Sort:" << endl;
  myList.printList();
  cout << endl;

  switch (choice) {
  case 1:
    myList.bubbleSort();
    break;
  case 2:
    myList.selectionSort();
    break;
  case 3:
    myList.insertionSort();
    break;
  case 4:
    myList.mergeSort();
    break;
  case 5:
    myList.quickSort();
    break;
  case 6:
    myList.countSort();
    break;
  case 7:
    myList.radixSort();
    break;
  default:
    return;
  }

  cout << "\nSorted List:" << endl;
  myList.printList();
  cout << endl << endl;

  myList.clearList();
}

void menu() {

  srand(time(0)); // Seed for random number generation
  List myList;

  int choice;
  do {
    cout << endl;
    displayMenu();
    cin >> choice;

    if (choice >= 1 && choice <= 7) {
      runSortingAlgorithm(choice, myList);
    } else if (choice != 0) {
      cout << "Invalid choice. Please try again." << endl;
    }

  } while (choice != 0);
}

int main() {

  menu();

  // List myList;
  //   myList.append(5);
  //   myList.append(3);
  //   myList.append(7);
  //   myList.append(1);
  //   myList.append(4);

  //   cout << "Before sort:" << endl;
  //   myList.printList();

  //   cout << "\n\nAfter sort:" << endl;
  //   myList.insertionSort();
  //   myList.printList();


  return 0;
}

// void bubbleSort();
// void selectionSort();
// void quickSort();
// void radixSort();
// void insertionSort();
// void countSort();
// void mergeSort();

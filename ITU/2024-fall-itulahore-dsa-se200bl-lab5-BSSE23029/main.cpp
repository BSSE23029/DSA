#include "functions.h"
#include <iostream>

using namespace std;

int main() {

  List myList;

  while (true) {
    cout << "\nMenu:\n";
    cout << "1. Test if list is initially empty\n";
    cout << "2. Append elements to the list\n";
    cout << "3. Prepend elements to the list\n";
    cout << "4. Insert element at index\n";
    cout << "5. Delete element from end\n";
    cout << "6. Delete element from start\n";
    cout << "7. Delete element from index\n";
    cout << "8. Print list contents\n";
    cout << "9. Exit\n";

    int choice;
    cout << "Enter your choice (1-9): ";
    cin >> choice;

    switch (choice) {

    case 1: {
      if (myList.isEmpty()) {
        cout << "The list is indeed initially empty.\n";
      } else {
        cout << "The list is not empty.\n";
      }
      break;
    }

    case 2: {
      cout << "\nData:";
      int data;
      cin >> data;
      myList.append(data);
      cout << "Elements appended successfully.\n";
      break;
    }

    case 3: {
      cout << "\nData:";
      int data;
      cin >> data;
      myList.prepend(data);
      cout << "Elements prepended successfully.\n";
      break;
    }

    case 4: {
      cout << "\nData:";
      int data;
      cin >> data;
      cout << "\nIntex:";
      int i;
      cin >> i;
      myList.insertAtIndex(data, i);
      cout << "Element inserted at index 2 successfully.\n";
      break;
    }

    case 5: {
      myList.deleteFromEnd();
      cout << "Last element deleted.\n";
      break;
    }

    case 6: {
      myList.deleteFromStart();
      cout << "First element deleted.\n";
      break;
    }

    case 7: {
      myList.deleteFromIndex(2);
      cout << "Element at index 2 deleted.\n";
      break;
    }

    case 8: {
      myList.printList();
      break;
    }

    case 9: {
      cout << "Exiting the program.\n";
      return 0;
    }

    default: {
      cout << "Invalid choice. Please try again.\n";
    }
    }
  }

  return 0;
}

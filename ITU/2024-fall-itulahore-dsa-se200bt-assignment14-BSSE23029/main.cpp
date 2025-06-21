#include "functions.h"

int main() {
  AVLTree avlTree;
  int choice, key;

  while (choice != 0) {
    cout << "\nAVL Tree Menu:\n";
    cout << "1. Insert a key\n";
    cout << "2. Search for a key\n";
    cout << "3. Print the AVL Tree (In-order)\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
    cin >> choice;

    switch (choice) {
    case 1: {
      cout << "Enter key to insert: ";
      cin >> key;
      avlTree.insert(key);
      cout << "Key " << key << " inserted successfully.\n";
      break;
    }

    case 2: {
      cout << "Enter key to search: ";
      cin >> key;
      if (avlTree.search(key)) {
        cout << "Key " << key << " found in the AVL Tree.\n";
      } else {
        cout << "Key " << key << " not found in the AVL Tree.\n";
      }
      break;
    }

    case 3: {
      cout << "AVL Tree (In-order): ";
      avlTree.printTree();
      cout << endl;
      break;
    }

    case 0: {
      cout << "Exiting program.\n";
      break;
    }

    default: {
      cout << "Invalid choice. Please try again.\n";
    }
    }
  }

  return 0;
}
#include "functions.h"

int main() {
  RedBlackTree rbTree;
  int choice, key;
  Node *result;

  while (choice != 0) {
    cout << endl << endl;
    cout << "\n=== Red-Black Tree Menu ===\n";
    cout << "1. Insert a key\n";
    cout << "2. Search for a key\n";
    cout << "3. Print the tree\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
      cout << "Enter key to insert: ";
      cin >> key;
      rbTree.insert(key);
      cout << "Key inserted successfully.\n";
      break;
    }

    case 2: {
      cout << "Enter key to search: ";
      cin >> key;
      result = rbTree.search(key);
      if (result) {
        cout << "Key " << key << " found in the tree.\n";
      } else {
        cout << "Key " << key << " not found in the tree.\n";
      }
      break;
    }

    case 3: {
      cout << "Tree structure:\n";
      rbTree.printTree();
      break;
    }

    case 0: {
      cout << "Exiting program. Goodbye!\n";
      break;
    }

    default: {
      cout << "Invalid choice. Please try again.\n";
    }
    }
  }
  cout << endl << endl;
}

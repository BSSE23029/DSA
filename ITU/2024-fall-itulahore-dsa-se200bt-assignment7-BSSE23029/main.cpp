#include "functions.h"

// does not work for string as getdata() should return template type

void displayMenu() {
  cout << "\n----- Menu -----\n";
  cout << "1. Insert a node\n";
  cout << "2. Get data of the root\n";
  cout << "3. Get a child of a node\n";
  cout << "4. Get tree height\n";
  cout << "5. Get degree of tree\n";
  cout << "6. Search for a node\n";
  cout << "7. Update a node value\n";
  cout << "8. Get size of the tree\n";
  cout << "0. Exit\n";
  cout << "----------------\n";
  cout << "Enter your choice: ";
}

void menu() {

  Tree<int> tree;
  int choice, value, parentValue, childNumber, newValue;
  Tree<int> *childNode;

  while (true) {
    displayMenu();
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter value to insert: ";
      cin >> value;
      tree.insert(value);
      cout << "Node inserted.\n";
      break;

    case 2:
      cout << "Root data: " << tree.getData() << endl;
      break;

    case 3:
      cout << "Enter parent node value: ";
      cin >> parentValue;
      cout << "Enter child number (0 to " << MaxChild - 1 << "): ";
      cin >> childNumber;
      childNode = tree.getChild(parentValue, childNumber);
      if (childNode) {
        cout << "Child data: " << childNode->getData() << endl;
      } else {
        cout << "Child not found.\n";
      }
      break;

    case 4:
      cout << "Tree height: " << tree.height() << endl;
      break;

    case 5:
      cout << "Tree degree: " << tree.degreeofTree() << endl;
      break;

    case 6:
      cout << "Enter value to search: ";
      cin >> value;
      childNode = tree.searchInTree(value);
      if (childNode) {
        cout << "Node found with data: " << childNode->getData() << endl;
      } else {
        cout << "Node not found.\n";
      }
      break;

    case 7:
      cout << "Enter old value to update: ";
      cin >> value;
      cout << "Enter new value: ";
      cin >> newValue;
      tree.update(value, newValue);
      cout << "Value updated.\n";
      break;

    case 8:
      cout << "Tree size: " << tree.treeSize() << endl;
      break;

    case 0:
      cout << "Exiting...\n";
      return;

    default:
      cout << "Invalid choice! Try again.\n";
    }
  }
}

int main() {

   menu();

//   Tree<int> tree;

//   tree.insert(10);

//   int value = 10;

//   Tree<int> *childNode;
//   Tree<int> *childNode2;

//   Tree<int> *temp;

//   childNode = tree.searchInTree(value);
//   if (childNode) {
//     cout << "Node found with data: " << childNode->getData() << endl;
//   } else {
//     cout << "Node not found.\n";
//   }

//   temp = tree.deleteNode(10);

//   if (temp) {
//     childNode2 = temp->searchInTree(value);
//     if (childNode2 != nullptr) {
//       cout << "Node found with data: " << childNode2->getData()
//            << endl; // Use childNode2 instead of childNode
//     } else {
//       cout << "Node not found.\n";
//     }
//   } else {
//     cout << "The tree is now empty after deletion.\n";
//   }

  return 0;
}
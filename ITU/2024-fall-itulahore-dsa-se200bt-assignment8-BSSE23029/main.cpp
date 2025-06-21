#include "functions.h"

int main() {
  cout << endl << endl << endl;
  Tree tree;
  int choice, value;

  do {
    cout << "\n------ Binary Tree Menu ------\n";
    cout << "1. Insert Node\n";
    cout << "2. Delete Node\n";
    cout << "3. Display In-order\n";
    cout << "4. Display Pre-order\n";
    cout << "5. Display Post-order\n";
    cout << "6. Display Level-order\n";
    cout << "7. Get Height of a Node\n";
    cout << "8. Get Degree of a Node\n";
    cout << "9. Print Tree\n";
    cout << "10. Visualize\n";
    cout << "0. Exit\n";
    cout << "------------------------------\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      // Insert Node
      cout << "Enter value to insert: ";
      cin >> value;
      tree.insertNode(value);
      cout << "Node inserted!\n";
      break;

    case 2:
      // Delete Node
      cout << "Enter value to delete: ";
      cin >> value;
      tree.deleteNode(value);
      cout << "Node deleted if found!\n";
      break;

    case 3:
      // Display In-order
      cout << "In-order Traversal: ";
      tree.display_in(tree.getRoot());
      cout << endl;
      break;

    case 4:
      // Display Pre-order
      cout << "Pre-order Traversal: ";
      tree.display_pre(tree.getRoot());
      cout << endl;
      break;

    case 5:
      // Display Post-order
      cout << "Post-order Traversal: ";
      tree.display_post(tree.getRoot());
      cout << endl;
      break;

    case 6:
      // Display Level-order
      cout << "Level-order Traversal: ";
      tree.display_level();
      cout << endl;
      break;

    case 7:
      // Get Height of a Node
      cout << "Enter value to find height: ";
      cin >> value;
      cout << "Height of node with value " << value
           << " is: " << tree.getHeight(value) << endl;
      break;

    case 8:
      // Get Degree of a Node
      cout << "Enter value to find degree: ";
      cin >> value;
      cout << "Degree of node with value " << value
           << " is: " << tree.getDegree(value) << endl;
      break;

    case 9:
      // Print Entire Tree (Level-order)
      cout << "Tree (Level-order): ";
      tree.printTree();
      cout << endl;
      break;

    case 0:
      // Exit
      cout << "Exiting...\n";
      break;

    default:
      cout << "Invalid choice. Please select again.\n";
    }
  } while (choice != 0);

  cout << endl << endl << endl;

  return 0;
}
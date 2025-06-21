#include "functions.h"

#include <vector>

int main() {

    cout << endl << endl << endl;


  FibonacciHeap heap;
  vector<FibonacciNode *> nodes; // Store inserted nodes for reference in
                                 // decrease and delete operations

  int choice;
  do {

    cout << endl << endl;

    cout << "\nFibonacci Heap Operations:" << endl;
    cout << "1. Insert a key" << endl;
    cout << "2. Find minimum key" << endl;
    cout << "3. Extract minimum key" << endl;
    cout << "4. Decrease a key" << endl;
    cout << "5. Delete a key" << endl;
    cout << "6. Display node count" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << endl << endl;

    switch (choice) {
    case 1: { // Insert a key
      int key;
      cout << "Enter the key to insert: ";
      cin >> key;
      FibonacciNode *node = heap.insert(key);
      nodes.push_back(node); // Save the pointer for later operations
      cout << "Inserted key " << key << " into the heap." << endl;
      break;
    }
    case 2: { // Find minimum key
      FibonacciNode *minNode = heap.findMin();
      if (minNode) {
        cout << "Minimum key: " << minNode->getKey() << endl;
      } else {
        cout << "Heap is empty." << endl;
      }
      break;
    }
    case 3: { // Extract minimum key
      FibonacciNode *minNode = heap.extractMin();
      if (minNode) {
        cout << "Extracted minimum key: " << minNode->getKey() << endl;
        delete minNode; // Clean up extracted node
      } else {
        cout << "Heap is empty. No minimum to extract." << endl;
      }
      break;
    }
    case 4: { // Decrease a key
      int index, newKey;
      cout << "Enter the index of the node to decrease (starting from 0): ";
      cin >> index;
      if (index < 0 || index >= nodes.size() || !nodes[index]) {
        cout << "Invalid index or node already deleted." << endl;
        break;
      }
      cout << "Enter the new key (should be smaller than current key): ";
      cin >> newKey;
      heap.decreaseKey(nodes[index], newKey);
      cout << "Decreased key at index " << index << " to " << newKey << "."
           << endl;
      break;
    }
    case 5: { // Delete a key
      int index;
      cout << "Enter the index of the node to delete (starting from 0): ";
      cin >> index;
      if (index < 0 || index >= nodes.size() || !nodes[index]) {
        cout << "Invalid index or node already deleted." << endl;
        break;
      }
      heap.deleteNode(nodes[index]);
      cout << "Deleted node at index " << index << "." << endl;
      nodes[index] = nullptr; // Mark the node as deleted
      break;
    }
    case 6: { // Display node count
      cout << "Number of nodes in the heap: " << heap.getNodeCount() << endl;
      break;
    }
    case 0: { // Exit
      cout << "Exiting program. Goodbye!" << endl;
      break;
    }
    default:
      cout << "Invalid choice. Please try again." << endl;
    }
  } while (choice != 0);

  // Cleanup: Delete all remaining nodes in the heap
  while (heap.getNodeCount() > 0) {
    FibonacciNode *minNode = heap.extractMin();
    delete minNode;
  }

  cout << endl << endl << endl;

  return 0;
}
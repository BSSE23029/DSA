#include "functions.h"
#include <iostream>

using namespace std;

int main() {

  cout << endl << endl << endl;

  int tableSize;
  cout << "Enter the size of the hash table: ";
  cin >> tableSize;

  HashTable hashTable(
      tableSize); // Create the hash table with user-defined size
  int choice, value;

  while (choice != 0) {
    cout << endl << endl;
    cout << "\n--- Hash Table Operations Menu ---" << endl;
    cout << "1. Insert a value" << endl;
    cout << "2. Remove a value" << endl;
    cout << "3. Search for a value" << endl;
    cout << "4. Display the hash table" << endl;
    cout << "5. Get the size of the hash table" << endl;
    cout << "0. Exit" << endl;
    cout << "\nChoose an option: ";
    cin >> choice;

    cout << endl << endl;

    switch (choice) {
    case 1: // Insert a value
      cout << "Enter the value to insert: ";
      cin >> value;
      hashTable.insert(value);
      cout << "Value inserted successfully." << endl;
      break;

    case 2: // Remove a value
      cout << "Enter the value to remove: ";
      cin >> value;
      if (hashTable.remove(value)) {
        cout << "Value removed successfully." << endl;
      } else {
        cout << "Value not found in the hash table." << endl;
      }
      break;

    case 3: // Search for a value
      cout << "Enter the value to search for: ";
      cin >> value;
      if (hashTable.search(value)) {
        cout << "Value found in the hash table." << endl;
      } else {
        cout << "Value not found." << endl;
      }
      break;

    case 4: // Display the hash table
      cout << "Hash Table Contents:" << endl;
      hashTable.display();
      break;

    case 5: // Get the size of the hash table
      cout << "Current size of the hash table: " << hashTable.getSize() << endl;
      break;

    case 0: // Exit
      cout << "Exiting the program. Goodbye!" << endl;
      break;

    default: // Invalid option
      cout << "Invalid choice. Please try again." << endl;
      break;
    }
  }

  cout << endl << endl << endl;

  return 0;
}

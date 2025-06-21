#include "functions.h"

/*




Node




*/
// Constructor
Node::Node(int v) : value(v), next(nullptr) {}

// Destructor
Node::~Node() {}

// Getters and Setters
int Node::getValue() { return value; }
Node *Node::getNext() { return next; }
void Node::setNext(Node *nextNode) { next = nextNode; }
/*




List




*/
// Constructor
List::List() : head(nullptr), size(0) {}

// Destructor to clean up all nodes
List::~List() {
  Node *current = head;
  while (current != nullptr) {
    Node *nextNode = current->getNext();
    delete current;
    current = nextNode;
  }
}

void List::append(int value) {
  // Create a new node with the given value
  Node *newNode = new Node(value);

  // If the list is empty, set the head of the list to the new node
  if (head == nullptr) {
    head = newNode;
  } else {
    // Traverse the list to find the last node
    Node *current = head;
    while (current->getNext() != nullptr) {
      // Move to the next node in the list
      current = current->getNext();
    }
    // Set the next pointer of the last node to the new node
    current->setNext(newNode);
  }
  // Increment the size of the list
  size++;
}

// Remove the first node with the specified value
bool List::remove(int value) {
  // If the list is empty, return false since there's nothing to remove
  if (head == nullptr)
    return false;

  // Check if the head node contains the value to be removed
  if (head->getValue() == value) {
    // Store the current head node in a temporary variable
    Node *temp = head;
    // Move the head pointer to the next node
    head = head->getNext();
    // Delete the old head node
    delete temp;
    // Decrement the size of the list
    size--;
    // Return true to indicate successful removal
    return true;
  }

  // Initialize a pointer to traverse the list starting from the head
  Node *current = head;
  // Traverse the list until the end is reached
  while (current->getNext() != nullptr) {
    // Check if the next node contains the value to be removed
    if (current->getNext()->getValue() == value) {
      // Store the node to be removed in a temporary variable
      Node *temp = current->getNext();
      // Link the current node to the node after the one to be removed
      current->setNext(temp->getNext());
      // Delete the node to be removed
      delete temp;
      // Decrement the size of the list
      size--;
      // Return true to indicate successful removal
      return true;
    }
    // Move to the next node in the list
    current = current->getNext();
  }
  // Return false if the value was not found in the list
  return false;
}

// Search for a value in the list
bool List::search(int value) {
  Node *current = head;
  while (current != nullptr) {
    if (current->getValue() == value)
      return true;
    current = current->getNext();
  }
  return false;
}

// Get the size of the list
int List::getSize() { return size; }

// Display the list contents
void List::display() {
  Node *current = head;
  while (current != nullptr) {
    cout << current->getValue() << " -> ";
    current = current->getNext();
  }
  cout << "nullptr" << endl;
}
/*




HashTable




*/
// Constructor to initialize the hash table with a given size
HashTable::HashTable(int size) : tableSize(size), elementCount(0) {
  table = new List[tableSize];
}

// Destructor to deallocate all lists
HashTable::~HashTable() { delete[] table; }

// Hash function to determine the index for a key
int HashTable::hashFunction(int value) { return value % tableSize; }

// Insert a value into the hash table
void HashTable::insert(int value) {
    //generate key
  int index = hashFunction(value);
  table[index].append(value);
  elementCount++;
}

bool HashTable::remove(int value) {
  int index = hashFunction(value);
  // Get the index of the bucket this value
  // should be removed from
  if (table[index].remove(value)) {
    // If the value is removed from the bucket
    // decrement the element count
    elementCount--;
    // Return true to indicate that the value
    // was removed
    return true;
  }
  // Return false to indicate that the value
  // was not found
  return false;
}

// Search for a value in the hash table
bool HashTable::search(int value) {
  int index = hashFunction(value);
  return table[index].search(value);
}


// Get the number of elements in the hash table
int HashTable::getSize() { return elementCount; }

// Display the contents of the hash table
void HashTable::display() {
  for (int i = 0; i < tableSize; i++) {
    cout << "Bucket " << i << ": ";
    table[i].display();
  }
}
#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <iostream>

using namespace std;

class Node {
private:
    int value;
    Node* next;

public:
    // Constructor
    Node(int v);

    // Destructor
    ~Node();

    // Getters and Setters
    int getValue();

    Node* getNext();

    void setNext(Node* nextNode);

};

// List class definition
class List {
private:
    Node* head;
    int size;

public:
    // Constructor
    List();

    // Destructor to clean up all nodes
    ~List();

    // Append a value to the end of the list
    void append(int value);

    // Remove the first node with the specified value
    bool remove(int value);

    // Search for a value in the list
    bool search(int value);

    // Get the size of the list
    int getSize();

    // Display the list contents
    void display();

};

class HashTable {
private:
    List* table;      // Array of lists (buckets)
    int tableSize;    // Number of buckets
    int elementCount; // Number of elements currently stored

public:

    // Constructor to initialize the hash table with a given size
    HashTable(int size);

    // Destructor to deallocate all lists
    ~HashTable();

    // Hash function to determine the index for a key
    int hashFunction(int value);

    // Insert a value into the hash table
    void insert(int value);

    // Remove a value from the hash table
    bool remove(int value);

    // Search for a value in the hash table
    bool search(int value);

    // Get the number of elements in the hash table
    int getSize();

    // Display the contents of the hash table
    void display();

};

#endif

// Implement the Stack Class Using Dynamic Arrays Data Members:
// ●	int* array: Pointer to the dynamic array storing the stack elements.
// ●	int size: The current size of the stack.
// ●	int capacity: The current capacity of stack.
// Member Functions to Implement:
// 1.	Constructor: Initializes the stack with an initial capacity 10, allocates the dynamic array with the initial capacity, sets size to 0.
// 2.	Destructor: Deallocates the dynamic array to prevent memory leaks.
// 3.	bool isEmpty(): Returns true if the stack is empty; otherwise, false.
// 4.	void push(int data): If the array is full, resizes it by doubling its capacity. Updates top and size accordingly.
// 5.	void pop(): Removes the top element of the stack and resize it. If the stack is empty, handle the error appropriately.
// 6.	int getSize(): Returns the number of elements in the stack.
// 7.	void clear(): Removes all elements from the stack.
// 8.	void printStack(): Prints all the elements in the stack from top to bottom.
// Task 2:
// Implement the Queue Class Using Dynamic Arrays Data Members:
// ●	int* array: Pointer to the dynamic array storing the queue elements.
// ●	int size: The current size of the queue.
// ●	int capacity: The current capacity of the queue.
// Member Functions to Implement:
// 1.	Constructor: Initializes the stack with an initial capacity 10, allocates the dynamic array with the initial capacity, sets size to 0 and front and rear to 0.
// 2.	Destructor: Deallocates the dynamic array to prevent memory leaks.
// 3.	bool isEmpty(): Returns true if the queue is empty; otherwise, false.
// 4.	void enqueue(int data): Adds an element to the rear of the queue. If the array is full, resize it by doubling its capacity.
// 5.	void dequeue(): Removes the front element of the queue. If the queue is empty, handle the error appropriately.
// 6.	int getSize(): Returns the number of elements in the queue.
// 7.	void printQueue(): Prints all the elements in the queue from front to rear.


#include "functions.h"
#include <iostream>

using namespace std;

void stackMenu();
void queueMenu();

/**
 * Main function of the program. It displays the main menu and
 * controls the flow of the program based on the user's choice.
 */
int main() {
    int choice;

    do {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Stack Operations\n";
        cout << "2. Queue Operations\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Call the stack menu function to control the stack operations
            stackMenu();
            break;
        case 2:
            // Call the queue menu function to control the queue operations
            queueMenu();
            break;
        case 0:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

/**
 * Stack menu function. It displays the stack menu and controls the flow
 * of the program based on the user's choice.
 */
void stackMenu() {
    Stack myStack;
    int choice, element;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push Element\n";
        cout << "2. Pop Element\n";
        cout << "3. Display Stack\n";
        cout << "4. Clear Stack\n";
        cout << "0. Go Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Push an element to the stack
            cout << "Enter element to push: ";
            cin >> element;
            myStack.push(element);
            cout << element << " pushed to the stack.\n";
            break;
        case 2:
            // Pop an element from the stack
            myStack.pop();
            cout << "Top element popped from the stack.\n";
            break;
        case 3:
            // Display the stack contents
            if (myStack.isEmpty()) {
                cout << "Stack is empty.\n";
            } else {
                int* stackArray = myStack.getStack();
                int size = myStack.getSize();
                cout << "Stack contents (top to bottom): ";
                for (int i = size - 1; i >= 0; i--) {
                    cout << stackArray[i] << " ";
                }
                cout << "\n";
            }
            break;
        case 4:
            // Clear the stack
            myStack.clear();
            cout << "Stack cleared.\n";
            break;
        case 0:
            cout << "Returning to main menu.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

/**
 * Queue menu function. It displays the queue menu and controls the flow
 * of the program based on the user's choice.
 */
void queueMenu() {
    Queue myQueue;
    int choice, element;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue Element\n";
        cout << "2. Dequeue Element\n";
        cout << "3. Display Queue\n";
        cout << "4. Clear Queue\n";
        cout << "0. Go Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Enqueue an element to the queue
            cout << "Enter element to enqueue: ";
            cin >> element;
            myQueue.enqueue(element);
            cout << element << " enqueued to the queue.\n";
            break;
        case 2:
            // Dequeue an element from the queue
            myQueue.dequeue();
            cout << "Front element dequeued from the queue.\n";
            break;
        case 3:
            // Display the queue contents
            if (myQueue.isEmpty()) {
                cout << "Queue is empty.\n";
            } else {
                int* queueArray = myQueue.getQueue();
                int size = myQueue.getSize();
                cout << "Queue contents (front to rear): ";
                for (int i = 0; i < size; i++) {
                    cout << queueArray[i] << " ";
                }
                cout << "\n";
            }
            break;
        case 4:
            // Clear the queue
            myQueue.clear();
            cout << "Queue cleared.\n";
            break;
        case 0:
            cout << "Returning to main menu.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}


#include "functions.h"


#include "functions.h"

void displayMenu() {
    cout << "========== Main Menu ==========" << endl;
    cout << "1. Stack Operations" << endl;
    cout << "2. Queue Operations" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

void stackMenu(Stack& stack) {
    int choice, data;

    while (true) {
        cout << "\n===== Stack Menu =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Print Stack" << endl;
        cout << "5. Clear Stack" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to push: ";
                cin >> data;
                stack.push(data);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                if (!stack.isEmpty()) {
                    cout << "Top element: " << stack.peek() << endl;
                } else {
                    cout << "Stack is empty." << endl;
                }
                break;
            case 4:
                stack.printStack();
                break;
            case 5:
                stack.clear();
                cout << "Stack cleared." << endl;
                break;
            case 0:
                return; // Back to Main Menu
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void queueMenu(Queue& queue) {
    int choice, data;

    while (true) {
        cout << "\n===== Queue Menu =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Print Queue" << endl;
        cout << "4. Clear Queue" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to enqueue: ";
                cin >> data;
                queue.enqueue(data);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.printQueue();
                break;
            case 4:
                queue.clear();
                cout << "Queue cleared." << endl;
                break;
            case 0:
                return; // Back to Main Menu
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main() {
    Stack stack;
    Queue queue;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                stackMenu(stack);
                break;
            case 2:
                queueMenu(queue);
                break;
            case 0:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
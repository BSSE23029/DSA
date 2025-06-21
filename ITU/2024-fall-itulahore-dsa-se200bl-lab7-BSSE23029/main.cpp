#include <iostream>
#include "functions.h"
using namespace std;


// Function to perform insertion
void performInsertion(Tree& tree) {
    int value;
    cout << "Enter value to insert (-1 to exit): ";
    cin >> value;
    
    if (value == -1) return;
    
    tree.insertNode(value);
}

// Function to perform deletion
void performDeletion(Tree& tree) {
    int value;
    cout << "Enter value to delete (-1 to exit): ";
    cin >> value;
    
    if (value == -1) return; //returns void
    
    tree.deleteNode(value);
}

// Function to get tree height
int getTreeHeight(Tree& tree) {
    return tree.getTreeHeight();
}

// Function to get degree of a node
int getNodeDegree(Tree& tree, int value) {
    return tree.getDegree(value);
}

// Function to get height of a node
int getNodeHeight(Tree& tree, int value) {
    return tree.getHeight(value);
}

// Main function to drive the program
int main() {
    Tree tree;

    while (true) {
        cout << "\n--- Tree Operations ---";
        cout << "\n1. Insert Node";
        cout << "\n2. Delete Node";
        cout << "\n3. Get Tree Height";
        cout << "\n4. Get Degree of a Node";
        cout << "\n5. Get Height of a Node";
        cout << "\n6. Print Tree";
        cout << "\n0. Exit";

        int choice;
        cout << "\nEnter your choice (1-6): ";
        cin >> choice;

        //calling functions from cpp file

        switch (choice) {
            case 1:
                performInsertion(tree);
                break;
            case 2:
                performDeletion(tree);
                break;
            case 3:
                cout << "Tree height: " << getTreeHeight(tree) << endl;
                break;
            case 4:
                int value;
                cout << "Enter node value: ";
                cin >> value;
                cout << "Degree of node " << value << ": " << getNodeDegree(tree, value) << endl;
                break;
            case 5:
                cout << "Enter node value: ";
                cin >> value;
                cout << "Height of node " << value << ": " << getNodeHeight(tree, value) << endl;
                break;
            case 6:
                tree.printTree();
                break;
            case 0:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    // Tree tree;

    // tree.insertNode(10);
    // tree.insertNode(5);
    // tree.insertNode(20);
    // tree.insertNode(3);

    // tree.printTree();

    // // Delete node with value 5
    // tree.deleteNode(5);

    // tree.printTree();

    //TreeNode* root = tree.getRoot();

    // REQUIRE(root->getLeftChild()->getData() == 3); // 3 replaces 5 (or the deepest node)
    // REQUIRE(root->getRightChild()->getData() == 20); // 20 is still present

    // // Ensure no node with value 5 exists anymore
    // REQUIRE(tree.findNode(5) == nullptr);

    // // Tree should still have the root node and right child
    // REQUIRE(root->getData() == 10);
    // REQUIRE(root->getRightChild()->getData() == 20);
    

    // cout << endl << root->getLeftChild()->getData() << endl;
    // cout << endl << root->getRightChild()->getData() << endl;
    // cout << endl << (tree.findNode(5) == nullptr) << endl;
    // cout << endl << root->getData() << endl;
    // cout << endl << root->getRightChild()->getData() << endl;




    // cout << endl << tree.getHeight(10) << endl;
    // cout << endl << tree.getHeight(5) << endl;
    // cout << endl << tree.getHeight(7) << endl;
    // cout << endl << tree.getHeight(50) << endl;

    // cout << endl << tree.DeepestLeafNode()->getData() << endl;

    return 0;
}




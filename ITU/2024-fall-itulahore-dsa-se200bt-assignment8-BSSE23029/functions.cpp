#include "functions.h"

template <typename Type> Node<Type>::Node(Type value) {

  data = value;
  next = nullptr;
  previous = nullptr;
}

template <typename Type> void Node<Type>::setData(Type value) { data = value; }

template <typename Type> Type Node<Type>::getData() { return data; }

template <typename Type> void Node<Type>::setNext(Node *n) { next = n; }

template <typename Type> Node<Type> *Node<Type>::getNext() { return next; }

template <typename Type> void Node<Type>::setPrevious(Node *p) { previous = p; }

template <typename Type> Node<Type> *Node<Type>::Node::getPrevious() {
  return previous;
}

template <typename Type> Queue<Type>::Queue() {
  head = nullptr;
  tail = nullptr;
  count = 0;
}

template <typename Type> Queue<Type>::~Queue() {}

template <typename Type> bool Queue<Type>::isEmpty() { return count == 0; }

template <typename Type> void Queue<Type>::enqueue(Type value) {

  if (isEmpty()) {

    head = new Node<Type>(value);
    tail = head;
  }

  else {

    Node<Type> *temp = new Node<Type>(value);

    temp->setPrevious(tail);
    tail->setNext(temp);

    tail = temp;
  }
  count++;
}

template <typename Type> Type Queue<Type>::dequeue() {

  if (isEmpty()) {
    cout << "Queue is empty" << endl;
    throw runtime_error("Queue is empty");
  }

  Type value = head->getData();

  Node<Type> *temp = head;

  if (head->getNext() != nullptr) {
    head->getNext()->setPrevious(nullptr);
  }

  head = head->getNext();

  delete temp;

  count--;

  return value;
}

template <typename Type> void Queue<Type>::print() {

  if (isEmpty()) {

    cout << "Queue is empty" << endl;
    return;
  }

  Node<Type> *temp = head;

  while (temp != nullptr) {

    cout << temp->getData() << " ";

    temp = temp->getNext();
  }
}

TreeNode::TreeNode(int value) {

  data = value;
  left = nullptr;
  right = nullptr;
}

TreeNode *TreeNode::getLeftChild() { return left; }

TreeNode *TreeNode::getRightChild() { return right; }

int TreeNode::getData() { return data; }

void TreeNode::setData(int val) { data = val; };

void TreeNode::addLeftChild(TreeNode *node) { left = node; }

void TreeNode::addRightChild(TreeNode *node) { right = node; }

Tree::Tree() { root = nullptr; }

void Tree::insertNode(int value) {

  TreeNode *newNode = new TreeNode(value);

  if (root == nullptr) {

    // If the tree is empty, set the root to the new node
    root = newNode;
  }

  else {

    Queue<TreeNode *> queue;

    // Start at the root
    queue.enqueue(root);

    while (!queue.isEmpty()) {

      TreeNode *temp = queue.dequeue();

      // If the left subtree is empty, add the new node there
      if (temp->getLeftChild() == nullptr) {

        temp->addLeftChild(newNode);

        return;
      }

      else {

        // Otherwise, add the left subtree to the queue
        queue.enqueue(temp->getLeftChild());
      }

      // If the right subtree is empty, add the new node there
      if (temp->getRightChild() == nullptr) {

        temp->addRightChild(newNode);

        return;
      }

      else {

        // Otherwise, add the right subtree to the queue
        queue.enqueue(temp->getRightChild());
      }
    }
  }
}

// TreeNode *newNode = new TreeNode(value);

// if (root == nullptr) {
//     // If the tree is empty, set the root to the new node
//     root = newNode;
// } else {
//     TreeNode *current = root;
//     TreeNode *parent = nullptr;

//     // Traverse the tree to find the appropriate position for the new
//     node while (current != nullptr) {
//         parent = current;

//         if (value < current->getData()) {
//             // Move to the left if the value is smaller
//             current = current->getLeftChild();
//         } else {
//             // Move to the right if the value is larger
//             current = current->getRightChild();
//         }
//     }

//     // Insert the new node in the correct position
//     if (value < parent->getData()) {
//         parent->addLeftChild(newNode);
//     } else {
//         parent->addRightChild(newNode);
//     }
// }

void Tree::deleteNode(int value) {
  if (root == nullptr) {
    cout << "Tree is empty" << endl;
    return;
  }

  Queue<TreeNode *> queue;
  queue.enqueue(root);

  TreeNode *targetNode = nullptr;       // Node to be deleted
  TreeNode *lastNode = nullptr;         // Deepest node in the tree
  TreeNode *parentOfLastNode = nullptr; // Parent of the deepest node

  while (!queue.isEmpty()) {
    TreeNode *temp = queue.dequeue();

    // Find the node to be deleted
    if (temp->getData() == value) {
      targetNode = temp;
    }

    // Keep track of the last node and its parent
    if (temp->getLeftChild()) {
      parentOfLastNode = temp;
      queue.enqueue(temp->getLeftChild());
    }
    if (temp->getRightChild()) {
      parentOfLastNode = temp;
      queue.enqueue(temp->getRightChild());
    }

    lastNode = temp; // Keep updating to the last visited node
  }

  if (targetNode == nullptr) {
    cout << "Node with value " << value << " not found" << endl;
    return;
  }

  // Replace target node's data with the last node's data
  targetNode->setData(lastNode->getData());

  // Remove the last node
  if (parentOfLastNode->getRightChild() == lastNode) {
    parentOfLastNode->addRightChild(nullptr);
  } else {
    parentOfLastNode->addLeftChild(nullptr);
  }

  delete lastNode;
}

/**
 * Prints the tree in a level-order traversal.
 * If the tree is empty, print a message and return.
 */
void Tree::printTree() {

  if (root == nullptr) {

    cout << "Tree is empty" << endl;

    return;
  }

  Queue<TreeNode *> queue;

  queue.enqueue(root);

  while (!queue.isEmpty()) {

    TreeNode *temp = queue.dequeue();

    cout << temp->getData() << " ";

    if (temp->getLeftChild() != nullptr) {

      queue.enqueue(temp->getLeftChild());
    }

    if (temp->getRightChild() != nullptr) {

      queue.enqueue(temp->getRightChild());
    }
  }
}

int Tree::getTreeHeight() { return getHeight(root); }

/**
 * Returns the degree of the node with given data.
 * If the node does not exist, return -1.
 */
int Tree::getDegree(int data) {
  TreeNode *node = findNode(data);

  if (node == nullptr) {
    cout << "Node not found" << endl;
    return -1;
  }

  int degree = 0;

  if (node->getLeftChild()) {
    degree++; // Left child exists
  }

  if (node->getRightChild()) {
    degree++; // Right child exists
  }

  return degree;
}

int Tree::getHeight(TreeNode *node) {
  if (node == nullptr) {
    return -1; // Return 0 for null nodes (leaf's child level)
  }

  // Recursively find the height of left and right subtrees
  int leftHeight = getHeight(node->getLeftChild());
  int rightHeight = getHeight(node->getRightChild());

  // Return the greater height of the two subtrees plus one for the current
  // node
  return max(leftHeight, rightHeight) + 1;
}

int Tree::getHeight(int data) {
  TreeNode *node = findNode(data);

  if (node == nullptr) {
    return -1; // If node is not found, return 0
  }

  // Now call the helper getHeight(TreeNode* node) function
  return getHeight(node);
}

TreeNode *Tree::findNode(int data) {
  if (root == nullptr) {
    // If tree is empty, return nullptr
    return nullptr;
  }

  Queue<TreeNode *> queue;
  queue.enqueue(root);

  while (!queue.isEmpty()) {
    TreeNode *temp = queue.dequeue();

    // Check if the current node is the target node
    if (temp->getData() == data) {
      return temp;
    }

    // Enqueue left and right children of the current node
    if (temp->getLeftChild()) {
      queue.enqueue(temp->getLeftChild());
    }

    if (temp->getRightChild()) {
      queue.enqueue(temp->getRightChild());
    }
  }

  // If target node is not found, return nullptr
  return nullptr;
}

TreeNode *Tree::getRoot() { return root; }

void Tree::display_in(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  // Traverse the left subtree
  display_in(root->getLeftChild());

  // Visit the root node
  cout << root->getData() << " ";

  // Traverse the right subtree
  display_in(root->getRightChild());
}

void Tree::display_pre(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  // Visit the root node
  cout << root->getData() << " ";

  // Traverse the left subtree
  display_pre(root->getLeftChild());

  // Traverse the right subtree
  display_pre(root->getRightChild());
}

void Tree::display_post(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  // Traverse the left subtree
  display_post(root->getLeftChild());

  // Traverse the right subtree
  display_post(root->getRightChild());

  // Visit the root node
  cout << root->getData() << " ";
}

void Tree::display_level() {
  if (root == nullptr) {
    cout << "Tree is empty" << endl;
    return;
  }

  Queue<TreeNode *> queue;
  queue.enqueue(root);

  while (!queue.isEmpty()) {
    TreeNode *temp = queue.dequeue();

    // Visit the current node
    cout << temp->getData() << " ";

    // Enqueue left child if exists
    if (temp->getLeftChild() != nullptr) {
      queue.enqueue(temp->getLeftChild());
    }

    // Enqueue right child if exists
    if (temp->getRightChild() != nullptr) {
      queue.enqueue(temp->getRightChild());
    }
  }
}

void Tree::printTreeVisual(TreeNode* node, int space, int height) {
    // Base case
    if (root == nullptr) {
        return;
    }

    // Increase distance between levels
    space += height;

    // Process right child first
    printTreeVisual(root->getRightChild(), space);

    // Print current node after space count
    cout << endl;
    for (int i = height; i < space; i++) {
        cout << " ";
    }
    cout << root->getData() << "\n";

    // Print connecting lines for children
    if (root->getRightChild() != nullptr) {
        for (int i = height; i < space - height / 2; i++) {
            cout << " ";
        }
        cout << "  /\n";  // Connection to the right child
    }
    if (root->getLeftChild() != nullptr) {
        for (int i = height; i < space - height / 2; i++) {
            cout << " ";
        }
        cout << "  \\\n";  // Connection to the left child
    }

    // Process left child
    printTreeVisual(root->getLeftChild(), space);
}


class Queue<int> queuei;
class Queue<double> queued;
class Queue<float> queuef;
class Queue<char> queuec;
class Queue<string> queues;

class Node<int> i;
class Node<double> d;
class Node<float> f;
class Node<char> c;
class Node<string> s;
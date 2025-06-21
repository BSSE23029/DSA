#include "functions.h"

Node::Node(int key, bool color) : key(key), color(color) {
  left = nullptr;
  right = nullptr;
  parent = nullptr;
}

int Node::getKey() { return key; }

bool Node::getColor() { return color; }

void Node::setColor(bool color) { this->color = color; }

Node *Node::getLeft() { return left; }

Node *Node::getRight() { return right; }

Node *Node::getParent() { return parent; }

void Node::setLeft(Node *leftChild) { left = leftChild; }

void Node::setRight(Node *rightChild) { right = rightChild; }

void Node::setParent(Node *parentNode) { parent = parentNode; }

RedBlackTree::RedBlackTree() { root = nullptr; }

void RedBlackTree::insert(int key) {
  Node *newNode = new Node(key, true); // New node is red
  if (root == nullptr) {
    root = newNode;
    root->setColor(false); // Root is black
  } else {
    balanceInsert(newNode);
  }
}

void RedBlackTree::balanceInsert(Node *node) {
  // Find the correct parent for the new node. If the tree is empty, the parent
  // is nullptr.
  Node *parent = nullptr;
  Node *current = root;

  // We loop until we find the correct parent (i.e. the node that the new node
  // should be inserted under)
  while (current != nullptr) {
    parent = current;

    // If the new node's key is less than the current node's key, we move to the
    // left subtree
    if (node->getKey() < current->getKey()) {
      current = current->getLeft();
    }
    // Otherwise, we move to the right subtree
    else {
      current = current->getRight();
    }
  }

  // Set the parent of the new node to the correct parent
  node->setParent(parent);

  // If the parent is nullptr, then the new node is the root of the tree
  if (parent == nullptr) {
    root = node;
  }
  // If the new node's key is less than the parent's key, then the new node
  // should be the left child of the parent
  else if (node->getKey() < parent->getKey()) {
    parent->setLeft(node);
  }
  // Otherwise, the new node should be the right child of the parent
  else {
    parent->setRight(node);
  }

  // Now that the new node is inserted, we need to fix the Red-Black Tree
  // properties
  fixViolation(node);
}

void RedBlackTree::fixViolation(Node *node) {

  while (node != root && node->getParent()->getColor() == true) {
    Node *parent = node->getParent();
    Node *grandparent = parent->getParent();

    if (parent == grandparent->getLeft()) {
      Node *uncle = grandparent->getRight();

      // Case 1: Uncle is red. Set the parent and uncle to black. Set the
      // grandparent to red. Move up to the grandparent.

      if (uncle != nullptr && uncle->getColor() == true) {
        parent->setColor(false);
        uncle->setColor(false);
        grandparent->setColor(true);
        node = grandparent;
      } else {

        // Case 2: Node is right child. Perform a left rotation on the parent.
        // Move up to the parent.

        if (node == parent->getRight()) {
          leftRotate(parent);
          node = parent;
          parent = node->getParent();
        }

        // Case 3: Node is left child. Perform a right rotation on the
        // grandparent. Swap the colors of the parent and grandparent. Move up
        // to the parent.

        rightRotate(grandparent);
        bool tempColor = parent->getColor();
        parent->setColor(false);
        grandparent->setColor(tempColor);
        node = parent;
      }
    } else {

      // If the parent is the right child of the grandparent, we need to handle
      // the left subtree.

      Node *uncle = grandparent->getLeft();

      // Case 1: Uncle is red. Set the parent and uncle to black. Set the
      // grandparent to red. Move up to the grandparent.

      if (uncle != nullptr && uncle->getColor() == true) {
        parent->setColor(false);
        uncle->setColor(false);
        grandparent->setColor(true);
        node = grandparent;
      } else {

        // Case 2: Node is left child. Perform a right rotation on the parent.
        // Move up to the parent.

        if (node == parent->getLeft()) {
          rightRotate(parent);
          node = parent;
          parent = node->getParent();
        }

        // Case 3: Node is right child. Perform a left rotation on the
        // grandparent. Swap the colors of the parent and grandparent. Move up
        // to the parent.

        leftRotate(grandparent);
        bool tempColor = parent->getColor();
        parent->setColor(false);
        grandparent->setColor(tempColor);
        node = parent;
      }
    }
  }

  // Ensure the root of the tree is always black.

  root->setColor(false);
}

void RedBlackTree::leftRotate(Node *node) {
  // Store the right child of the node
  Node *rightChild = node->getRight();

  // Set the right child of the node to be the left child of rightChild
  node->setRight(rightChild->getLeft());

  // If rightChild's left child is not null, set its parent to be the node
  if (rightChild->getLeft() != nullptr) {
    rightChild->getLeft()->setParent(node);
  }

  // Set the parent of rightChild to be the parent of node
  rightChild->setParent(node->getParent());

  // If the parent of node is null, then rightChild is the new root
  if (node->getParent() == nullptr) {
    root = rightChild;
  } else if (node == node->getParent()->getLeft()) {
    // If the node is the left child of its parent, then rightChild is the new
    // left child
    node->getParent()->setLeft(rightChild);
  } else {
    // If the node is the right child of its parent, then rightChild is the new
    // right child
    node->getParent()->setRight(rightChild);
  }

  // Set the left child of rightChild to be the node
  rightChild->setLeft(node);

  // Set the parent of the node to be the rightChild
  node->setParent(rightChild);
}

void RedBlackTree::rightRotate(Node *node) {
  // Store the left child of the node
  Node *leftChild = node->getLeft();

  // Set the left child of the node to be the right child of leftChild
  node->setLeft(leftChild->getRight());

  // If leftChild's right child is not null, set its parent to be the node
  if (leftChild->getRight() != nullptr) {
    leftChild->getRight()->setParent(node);
  }

  // Set the parent of leftChild to be the parent of the node
  leftChild->setParent(node->getParent());

  // If the node is the root of the tree, update the root to be leftChild
  if (node->getParent() == nullptr) {
    root = leftChild;
  }
  // Otherwise, if the node is a right child, update the parent's right child to
  // be leftChild
  else if (node == node->getParent()->getRight()) {
    node->getParent()->setRight(leftChild);
  }
  // Otherwise, update the parent's left child to be leftChild
  else {
    node->getParent()->setLeft(leftChild);
  }

  // Set the right child of leftChild to be the node
  leftChild->setRight(node);

  // Set the parent of the node to be leftChild
  node->setParent(leftChild);
}

Node *RedBlackTree::search(int key) {
  // Start at the root of the tree
  Node *current = root;

  // Continue looping until we find the node with the given key or we reach a
  // leaf node
  while (current != nullptr && current->getKey() != key) {
    // If the key is less than the current node's key, go to the left subtree
    if (key < current->getKey()) {
      current = current->getLeft();
    }
    // If the key is greater than the current node's key, go to the right
    // subtree
    else {
      current = current->getRight();
    }
  }

  // Return a pointer to the node with the given key, or nullptr if not found
  return current;
}

void RedBlackTree::printTree() { printHelper(root, "", true); }

void RedBlackTree::printHelper(Node *root, string indent, bool last) {
  if (root != nullptr) {
    cout << indent;
    if (last) {
      cout << "R----";
      indent += "   ";
    } else {
      cout << "L----";
      indent += "|  ";
    }
    cout << root->getKey() << (root->getColor() ? " (R)" : " (B)") << endl;
    printHelper(root->getLeft(), indent, false);
    printHelper(root->getRight(), indent, true);
  }
}

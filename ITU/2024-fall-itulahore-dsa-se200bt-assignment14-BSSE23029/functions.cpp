#include "functions.h"

/*







NODE









*/
Node::Node(int key)
    : key(key), left(nullptr), right(nullptr), parent(nullptr), height(0) {}

Node::~Node() {}

int Node::getKey() { return key; }
Node *Node::getLeft() { return left; }
Node *Node::getRight() { return right; }
Node *Node::getParent() { return parent; }
void Node::setLeft(Node *leftChild) { left = leftChild; }
void Node::setRight(Node *rightChild) { right = rightChild; }
void Node::setParent(Node *parentNode) { parent = parentNode; }
int Node::getHeight() { return height; }
void Node::setHeight(int height) { this->height = height; }

/*









AVLTREE











*/
AVLTree::AVLTree() : root(nullptr) {}

Node *AVLTree::getRoot() { return root; }

void AVLTree::insert(int key) {
  // Create the new node
  Node *node = new Node(key);

  // If the tree is empty, set the root to the new node
  if (!root) {
    root = node;
    return;
  }

  // Find the correct location in the tree to insert the new node
  Node *current = root;
  Node *parent = nullptr; // The parent of the current node

  while (current) {
    parent = current;

    // Move to the left if the key is less than the current node's key
    if (node->getKey() < current->getKey()) {
      current = current->getLeft();
    } 
    // Move to the right if the key is greater than the current node's key
    else {
      current = current->getRight();
    }
  }

  // Set the parent of the new node to the parent we just found
  node->setParent(parent);

  // Set the left or right child of the parent node to the new node based on
  // whether the key is less than or greater than the parent node's key
  if (node->getKey() < parent->getKey()) {
    parent->setLeft(node);
  } else {
    parent->setRight(node);
  }

  // Rebalance the tree if necessary
  balanceInsert(node);
}

Node *AVLTree::search(int key) {
  Node *current = root;
  while (current) {
    if (key == current->getKey()) {
      return current;
    } else if (key < current->getKey()) {
      current = current->getLeft();
    } else {
      current = current->getRight();
    }
  }
  return nullptr;
}

void AVLTree::balanceInsert(Node *node) {
  while (node) {
    updateHeight(node);
    int balance = getBalanceFactor(node);

    // Left Left Case
    if (balance > 1 && getBalanceFactor(node->getLeft()) >= 0) {
      rightRotate(node);
    }
    // Right Right Case
    if (balance < -1 && getBalanceFactor(node->getRight()) <= 0) {
      leftRotate(node);
    }
    // Left Right Case
    if (balance > 1 && getBalanceFactor(node->getLeft()) < 0) {
      leftRotate(node->getLeft());
      rightRotate(node);
    }
    // Right Left Case
    if (balance < -1 && getBalanceFactor(node->getRight()) > 0) {
      rightRotate(node->getRight());
      leftRotate(node);
    }

    node = node->getParent();
  }
}

int AVLTree::getBalanceFactor(Node *node) {
  if (!node)
    return 0;
  return getHeight(node->getLeft()) - getHeight(node->getRight());
}

void AVLTree::leftRotate(Node *node) {
  // We're rotating the tree so that the right child of node becomes its parent
  Node *rightChild = node->getRight();

  // Update the right child of node to be the left child of its current right child
  node->setRight(rightChild->getLeft());
  // If the left child of rightChild is not null, set its parent to node
  if (rightChild->getLeft())
    rightChild->getLeft()->setParent(node);

  // Update the parent of rightChild to be the parent of node
  rightChild->setParent(node->getParent());
  if (!node->getParent()) {
    // If node was the root of the tree, update root to be rightChild
    root = rightChild;
  } else if (node == node->getParent()->getLeft()) {
    // If node was the left child of its parent, update the left child of its parent to be rightChild
    node->getParent()->setLeft(rightChild);
  } else {
    // If node was the right child of its parent, update the right child of its parent to be rightChild
    node->getParent()->setRight(rightChild);
  }
  // Update the left child of rightChild to be node
  rightChild->setLeft(node);
  // Update the parent of node to be rightChild
  node->setParent(rightChild);

  // Update the heights of node and rightChild
  updateHeight(node);
  updateHeight(rightChild);
}

void AVLTree::rightRotate(Node *node) {
  // We're rotating the tree so that the left child of node becomes its parent
  Node *leftChild = node->getLeft();

  // Update the left child of node to be the right child of its current left child
  node->setLeft(leftChild->getRight());
  // If the right child of leftChild is not null, set its parent to node
  if (leftChild->getRight())
    leftChild->getRight()->setParent(node);

  // Update the parent of leftChild to be the parent of node
  leftChild->setParent(node->getParent());
  if (!node->getParent()) {
    // If node was the root of the tree, update root to be leftChild
    root = leftChild;
  } else if (node == node->getParent()->getLeft()) {
    // If node was the left child of its parent, update the left child of its parent to be leftChild
    node->getParent()->setLeft(leftChild);
  } else {
    // If node was the right child of its parent, update the right child of its parent to be leftChild
    node->getParent()->setRight(leftChild);
  }
  // Update the right child of leftChild to be node
  leftChild->setRight(node);
  // Update the parent of node to be leftChild
  node->setParent(leftChild);

  // Update the heights of node and leftChild
  updateHeight(node);
  updateHeight(leftChild);
}

int AVLTree::getHeight(Node *node) { return node ? node->getHeight() : 0; }

void AVLTree::updateHeight(Node *node) {
  if (node) {
    int leftHeight = getHeight(node->getLeft());
    int rightHeight = getHeight(node->getRight());
    node->setHeight(max(leftHeight, rightHeight) + 1);
  }
}

void AVLTree::printTree() { printTree(root); }

void AVLTree::printTree(Node *node) {
  if (node) {
    printTree(node->getLeft());
    cout << node->getKey() << " ";
    printTree(node->getRight());
  }
}
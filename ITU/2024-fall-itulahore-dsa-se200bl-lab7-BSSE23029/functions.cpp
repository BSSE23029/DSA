#include "functions.h"

template <typename Type> Queue<Type>::Queue() : front(nullptr), rear(nullptr) {}

template <typename Type> Queue<Type>::~Queue() {
  while (front != nullptr) {
    Node *temp = front;
    front = front->next;
    delete temp;
  }
}

template <typename Type> void Queue<Type>::enqueue(Type value) {
  // Create a new node to store the given value.
  Node *newNode = new Node();

  // Store the given value in the new node.
  newNode->data = value;

  // Set the next pointer of the new node to nullptr, indicating that it is
  // the last node in the queue.
  newNode->next = nullptr;

  // If the queue is empty (i.e., the front is nullptr), then set the front
  // and rear of the queue to the new node.
  if (rear == nullptr) {
    front = rear = newNode;

  // If the queue is not empty, then add the new node to the end of the
  // queue. To do this, set the next pointer of the current rear node to
  // the new node, and set the rear pointer to the new node.
  } else {
    rear->next = newNode;
    rear = newNode;
  }
}

template <typename Type> Type Queue<Type>::dequeue() {
  // Check if the queue is empty.
  if (isEmpty()) {
    // If the queue is empty, throw an exception.
    throw runtime_error("Queue is empty");
  }

  // Get the value of the front node.
  Type value = front->data;

  // Store the front node temporarily.
  Node *temp = front;

  // Move the front pointer to the next node.
  front = front->next;

  // If the front pointer is now nullptr, then the rear pointer must also be
  // nullptr because the queue is now empty.
  if (front == nullptr) {
    rear = nullptr;
  }

  // Delete the node that was stored in the temp pointer.
  delete temp;

  // Return the value of the front node.
  return value;
}

template <typename Type> bool Queue<Type>::isEmpty() {
  return front == nullptr;
}

template class Queue<TreeNode *>;

TreeNode::TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}

TreeNode::~TreeNode() {

  // If the left child is not null, then we need to delete it.
  if (this->left != nullptr) {

    // delete will call the destructor of the left child
    delete this->left;
  }

  // If the right child is not null, then we need to delete it.
  if (this->right != nullptr) {

    // delete will call the destructor of the right child
    delete this->right;
  }
}


TreeNode *TreeNode::getLeftChild() {
  // cout << "returned left\n";
  return this->left;
}

TreeNode *TreeNode::getRightChild() {
  // cout << "returned left\n";
  return this->right;
}

int TreeNode::getData() {
  // cout << "fetched data " << this->data << endl;
  return this->data;
}

void TreeNode::setData(int value) {
  // cout << "fetched data " << this->data << endl;
  this->data = value;
}

void TreeNode::addLeftChild(TreeNode *node) { this->left = node; }

void TreeNode::addRightChild(TreeNode *node) { this->right = node; }

Tree::Tree() : root(nullptr) {}

void Tree::insertNode(int value) {

  // Create a new TreeNode with the given value
  TreeNode *newNode = new TreeNode(value);

  // If the tree is empty, set the root to the new node
  if (root == nullptr) {
    root = newNode;

    // No need to do anything else
    return;
  }

  // Create a queue to store the nodes to be processed
  Queue<TreeNode *> queue;

  // Enqueue the root node to be processed first
  queue.enqueue(root);

  // Process the nodes in the queue until it is empty
  while (!queue.isEmpty()) {

    // Dequeue the next node to process
    TreeNode *currentNode = queue.dequeue();

    // If the value is less than the value of the current node,
    // then the value must be in the left subtree
    if (value < currentNode->getData()) {

      // If the left child of the current node is null,
      // then the value must go there
      if (currentNode->getLeftChild() == nullptr) {

        // Add the new node as the left child of the current node
        currentNode->addLeftChild(newNode);

        // No need to do anything else
        break;
      } else {

        // If the left child of the current node is not null,
        // then enqueue it to be processed next
        queue.enqueue(currentNode->getLeftChild());
      }
    } else { // value >= currentNode->getData()
      // If the value is greater than or equal to the value of the current node,
      // then the value must be in the right subtree
      if (currentNode->getRightChild() == nullptr) {

        // Add the new node as the right child of the current node
        currentNode->addRightChild(newNode);

        // No need to do anything else
        break;
      } else {

        // If the right child of the current node is not null,
        // then enqueue it to be processed next
        queue.enqueue(currentNode->getRightChild());
      }
    }
  }
}


TreeNode *Tree::findParent(TreeNode *node) {

  if(node == root){
    return nullptr;
  }

  Queue<TreeNode *> queue;

  queue.enqueue(root);

  while (!queue.isEmpty()) {

    TreeNode *currentNode = queue.dequeue();

    // If the left or right child of the current node is the given node,
    // return the current node as the parent.
    if (currentNode->getLeftChild() == node || currentNode->getRightChild() == node) {

      return currentNode;

    } else {

      // If the left child of the current node is not nullptr, add it to the queue.
      if (currentNode->getLeftChild() != nullptr) {
        queue.enqueue(currentNode->getLeftChild());
      }

      // If the right child of the current node is not nullptr, add it to the queue.
      if (currentNode->getRightChild() != nullptr) {
        queue.enqueue(currentNode->getRightChild());
      }
    }
  }

  // If the queue is empty, it means the given node does not exist in the tree.
  // So return nullptr.
  return nullptr;
}

// Deletes a node with the given value from the tree.
// The node to be deleted is found by matching the value.
// The node to be deleted is replaced with the deepest leaf node in the tree.
// The deepest leaf node is then removed.
void Tree::deleteNode(int value) {

  // Find the node with the given value to be deleted.
  TreeNode *ToDelete = findNode(value);

  // Find the deepest leaf node in the tree.
  TreeNode *DeepestLeaf = DeepestLeafNode();

  // ToDelete->setData(DeepestLeaf->getData());
  // delete DeepestLeaf;

  // DeepestLeaf = nullptr;

  // If the node to be deleted is the same as the deepest leaf node, then
  // just delete the node and set the root to nullptr.
  if (ToDelete == DeepestLeaf) {

    delete ToDelete;

    root = nullptr; // If the root is the deepest leaf, set the root to nullptr

  } else {

    // Replace the node to be deleted with the deepest leaf node's value.
    ToDelete->setData(DeepestLeaf->getData());

    // Find the parent of the deepest leaf node.
    TreeNode *parent = findParent(DeepestLeaf);

    // Set the left or right child of the parent to nullptr depending on whether
    // the deepest leaf node is a left or right child of the parent.
    if (parent->getLeftChild() == DeepestLeaf) {

      parent->addLeftChild(nullptr);

    } else {

      parent->addRightChild(nullptr);

    }

    // Delete the deepest leaf node.
    delete DeepestLeaf;

  }

  // TreeNode *temp = new TreeNode(DeepestLeaf->getData());
  // temp->addLeftChild(DeepestLeaf->getLeftChild());
  // temp->addRightChild(DeepestLeaf->getRightChild());

  // delete DeepestLeaf;
  // delete ToDelete;

  // // ToDelete = DeepestLeaf;

  // ToDelete->setData(temp->getData());
  // ToDelete->addLeftChild(temp->getLeftChild());
  // ToDelete->addRightChild(temp->getRightChild());

}

void Tree::printTree() {
  if (root == nullptr)
    return;

  // Create a queue to store the nodes to be processed.
  Queue<TreeNode *> queue;

  // Enqueue the root node to be processed first.
  queue.enqueue(root);

  // Process the nodes in the queue until it is empty.
  while (!queue.isEmpty()) {

    // Dequeue the next node to process.
    TreeNode *currentNode = queue.dequeue();

    // Print the data of the current node.
    cout << currentNode->getData() << " ";

    // If the current node has a left child, enqueue it to be processed later.
    if (currentNode->getLeftChild() != nullptr)
      queue.enqueue(currentNode->getLeftChild());

    // If the current node has a right child, enqueue it to be processed later.
    if (currentNode->getRightChild() != nullptr)
      queue.enqueue(currentNode->getRightChild());
  }

  // Print a newline at the end of the tree.
  cout << endl;
}

// with recursion
int Tree::getTreeHeight() {
  return getHeightHelper(root) - 1; // total levels - 1
}

int Tree::getHeightHelper(TreeNode *node) { // for recursion
  if (node == nullptr) {
    // If the node is null, then the height of this subtree is 0.
    return 0;
  }

  // Calculate the height of the left and right subtrees
  int leftHeight = getHeightHelper(node->getLeftChild());
  int rightHeight = getHeightHelper(node->getRightChild());

  // The height of this subtree is 1 more than the maximum of the left and right
  // subtree heights
  return 1 + max(leftHeight, rightHeight);
}

int Tree::getDegree(int data) {

  // Find the node with the given value
  TreeNode *node = findNode(data);

  // If the node is not found, return -1
  if (node == nullptr)
    return -1;

  // Calculate the degree of the node by checking how many children it has
  // For each child that exists, add 1 to the degree
  int degree = 0;
  if (node->getLeftChild() != nullptr)
    degree++;
  if (node->getRightChild() != nullptr)
    degree++;

  return degree;
}

int Tree::getHeight(int data) {
  // Find the node with the given value
  TreeNode *node = findNode(data);

  // If the node is not found, return -1
  if (node == nullptr)
    return -1;

  // Calculate the height of the node using the getHeightHelper function
  // subtract 1 because the root is level 0
  return getHeightHelper(node) - 1;
}

TreeNode *Tree::findNode(int data) { return findNodeHelper(root, data); }

TreeNode *Tree::findNodeHelper(TreeNode *node, int data) { // for recursion

  if (node == nullptr) {
    return nullptr;
  }

  if (node->getData() == data) {
    return node;
  }
  /*
   * If the value we are searching for is less than the value of the current
   * node, then the value must be in the left subtree. Recursively call
   * findNodeHelper on the  child of the current node.
   */

  if (data < node->getData()) {

    return findNodeHelper(node->getLeftChild(), data);
  } else {
    return findNodeHelper(node->getRightChild(), data);
  }
}

TreeNode *Tree::getRoot() { return root; }

TreeNode *Tree::DeepestLeafNode() {
  TreeNode *temp = root; // Start at the root
  Queue<TreeNode *> queue;
  queue.enqueue(temp); // Enqueue the root

  TreeNode *deepestLeaf = nullptr; // Keep track of the deepest leaf we've seen

  while (!queue.isEmpty()) { // While we haven't processed all nodes
    temp = queue.dequeue();  // Get the next node to process

    if (temp->getLeftChild() == nullptr && temp->getRightChild() == nullptr) {
      // If this node is a leaf node, then it is the deepest leaf node we've
      // seen so far
      deepestLeaf = temp;
    } else {
      // If this node is not a leaf node, then enqueue its children to be
      // processed next
      if (temp->getLeftChild() != nullptr) {
        queue.enqueue(temp->getLeftChild());
      }
      if (temp->getRightChild() != nullptr) {
        queue.enqueue(temp->getRightChild());
      }
    }
  }
  return deepestLeaf; // Return the deepest leaf node
}

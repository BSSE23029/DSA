#include "functions.h"

#include <cmath>
#include <limits>

FibonacciNode::FibonacciNode(int key)
    : key(key), degree(0), parent(nullptr), child(nullptr), left(this),
      right(this), mark(false) {}

void FibonacciNode::link(FibonacciNode *child) {
  child->left = this;
  child->right = this->right;
  this->right->left = child;
  this->right = child;
  child->parent = this;
  this->degree++;
}

FibonacciHeap::FibonacciHeap()
    : minNode(nullptr), nodeCount(0), rootList(nullptr) {}

FibonacciNode *FibonacciHeap::insert(int key) {
  FibonacciNode *newNode = new FibonacciNode(key);
  if (!minNode) {
    minNode = newNode;
    rootList = newNode;
  } else {
    // Insert newNode into the circular doubly linked root list
    rootList->getLeft()->setRight(newNode);
    newNode->setLeft(rootList->getLeft());
    rootList->setLeft(newNode);
    newNode->setRight(rootList);

    if (key < minNode->getKey()) {
      minNode = newNode;
    }
  }
  nodeCount++;
  cout << "Inserted node with key " << key
       << ", current min: " << minNode->getKey() << endl;
  return newNode;
}

FibonacciNode *FibonacciHeap::findMin() const { return minNode; }

FibonacciNode *FibonacciHeap::extractMin() {
  FibonacciNode *min = minNode;
  if (min) {
    cout << "Extracting min node with key: " << min->getKey() << endl;

    // If min has children, add them to the root list
    if (min->getChild()) {
      FibonacciNode *child = min->getChild();
      do {
        FibonacciNode *nextChild = child->getRight();

        cout << "Adding child node with key " << child->getKey()
             << " to root list." << endl;

        // Remove child from its sibling list and add it to the root list
        child->setParent(nullptr);
        child->getLeft()->setRight(child->getRight());
        child->getRight()->setLeft(child->getLeft());

        // Insert the child into the root list
        child->setLeft(rootList->getLeft());
        child->setRight(rootList);
        rootList->getLeft()->setRight(child);
        rootList->setLeft(child);

        child = nextChild;
      } while (child != min->getChild());
    }

    // Remove min from the root list
    cout << "Removing min node with key " << min->getKey()
         << " from the root list." << endl;
    min->getLeft()->setRight(min->getRight());
    min->getRight()->setLeft(min->getLeft());

    // If min was the only node in the list, reset minNode and rootList
    if (min == min->getRight()) {
      cout << "Heap is now empty after removing min node." << endl;
      minNode = nullptr;
      rootList = nullptr;
    } else {
      minNode = min->getRight();
      cout << "New tentative min node is: " << minNode->getKey()
           << ". Consolidating heap." << endl;
      consolidate();
    }
    nodeCount--;
  } else {
    cerr << "Error: Attempted to extract from an empty heap." << endl;
  }

  if (min) {
    cout << "Successfully extracted min node with key " << min->getKey()
         << endl;
  } else {
    cout << "No node was extracted (heap may have been empty)." << endl;
  }

  return min;
}

void FibonacciHeap::decreaseKey(FibonacciNode *node, int newKey) {
  if (newKey > node->getKey())
    return; // Invalid operation
  node->setKey(newKey);
  FibonacciNode *parent = node->getParent();
  if (parent && newKey < parent->getKey()) {
    cut(node, parent);
    cascadingCut(parent);
  }
  if (newKey < minNode->getKey()) {
    minNode = node;
  }
  cout << "Decreased key to " << newKey
       << ", current min: " << minNode->getKey() << endl;
}

void FibonacciHeap::deleteNode(FibonacciNode *node) {
  if (node == nullptr) {
    return; // Check for null pointer
  }

  // Decrease the key of the node to be deleted to negative infinity
  decreaseKey(node, numeric_limits<int>::min());

  // Now extract the minimum node, which is the node we want to delete
  FibonacciNode *minNode = extractMin();
  if (minNode != node) {
    cerr << "Error: Extracted node is not the intended node to delete." << endl;
  }
}

void FibonacciHeap::cut(FibonacciNode *node, FibonacciNode *parent) {
  // Update parent's child pointer if necessary
  if (node == parent->getChild()) {
    parent->setChild(node->getRight());
  }
  parent->decrementDegree();

  // Remove node from the child list of its parent
  node->getLeft()->setRight(node->getRight());
  node->getRight()->setLeft(node->getLeft());

  // Add node to the root list
  node->setLeft(rootList->getLeft());
  node->setRight(rootList);
  rootList->getLeft()->setRight(node);
  rootList->setLeft(node);
  node->setParent(nullptr);
  node->setMark(false);

  // check
  cout << "Cut node with key " << node->getKey() << " from parent with key "
       << parent->getKey() << endl;
}

void FibonacciHeap::cascadingCut(FibonacciNode *node) {
  FibonacciNode *parent = node->getParent();
  if (parent) {
    if (!node->getMark()) {
      node->setMark(true);
    } else {
      cut(node, parent);
      cascadingCut(parent);
    }
  }
}

void FibonacciHeap::unionHeap(FibonacciHeap *otherHeap) {
  if (!otherHeap->minNode)
    return;
  if (!minNode) {
    minNode = otherHeap->minNode;
    rootList = otherHeap->rootList;
  } else {
    // Merge the two root lists
    FibonacciNode *temp = minNode->getRight();
    minNode->setRight(otherHeap->minNode->getRight());
    otherHeap->minNode->getRight()->setLeft(minNode);
    otherHeap->minNode->setRight(temp);
    temp->setLeft(otherHeap->minNode);

    // Update the minimum node if necessary
    if (otherHeap->minNode->getKey() < minNode->getKey()) {
      minNode = otherHeap->minNode;
    }
  }
  nodeCount += otherHeap->nodeCount;
  otherHeap->minNode = nullptr;
  otherHeap->nodeCount = 0;

  cout << "Union with another heap, new min key: " << minNode->getKey() << endl;
}

void FibonacciHeap::consolidate() {
  if (!rootList) {
    cerr << "Consolidate called on an empty root list." << endl;
    return;
  }

  int maxDegree =
      log2(nodeCount) + 2; // Add a margin to avoid out-of-bounds access
  FibonacciNode **trees = new FibonacciNode *[maxDegree];
  for (int i = 0; i < maxDegree; i++) {
    trees[i] = nullptr;
  }

  cout << "Starting consolidation. Node count: " << nodeCount
       << ", max degree: " << maxDegree << endl;

  FibonacciNode *current = rootList;
  FibonacciNode *start = rootList;
  do {
    FibonacciNode *next =
        current->getRight(); // Save next node before modifications
    int degree = current->getDegree();
    cout << "Processing node with key: " << current->getKey()
         << ", degree: " << degree << endl;

    while (trees[degree] != nullptr) {
      FibonacciNode *other = trees[degree];
      cout << "Conflict at degree " << degree << " between nodes with keys "
           << current->getKey() << " and " << other->getKey() << endl;

      // Ensure `current` is the smaller root
      if (current->getKey() > other->getKey()) {
        swap(current, other);
      }

      // Check to prevent self-linking
      if (current == other) {
        cerr << "Error: Attempted to link a node with itself." << endl;
        delete[] trees;
        return;
      }

      // Link other as a child of current
      current->link(other);
      cout << "Linked node with key " << other->getKey()
           << " under node with key " << current->getKey() << endl;

      trees[degree] = nullptr;
      degree++;
    }

    trees[degree] = current;
    current = next; // Move to the next node
  } while (current != start);

  // Rebuild the root list and find the new minNode
  minNode = nullptr;
  for (int i = 0; i < maxDegree; i++) {
    if (trees[i]) {
      cout << "Root at degree " << i << " with key " << trees[i]->getKey()
           << endl;
      if (!minNode || trees[i]->getKey() < minNode->getKey()) {
        minNode = trees[i];
      }
    }
  }

  cout << "Consolidation complete. New min key: "
       << (minNode ? minNode->getKey() : -1) << endl;

  delete[] trees;
}

int FibonacciHeap::getNodeCount() { return nodeCount; }

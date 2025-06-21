#include "functions.h"

template <typename T> Queue<T>::Queue(int capacity) {

  if (capacity <= 0) {
    throw invalid_argument("Capacity must be greater than 0");
  }

  // Create a new Queue with the given capacity.
  // The data is stored in an array of type T, with the given capacity.
  // The first index is initialized to 0, last index is initialized to -1,
  // and the count of elements is initialized to 0.
  data = new T[capacity];
  first = 0;
  last = -1;
  count = 0;
  this->capacity = capacity;
}

template <typename T> Queue<T>::~Queue() {
  // Destructor for the Queue class.
  // This deletes the dynamically allocated array of type T.
  delete[] data;
}

template <typename T> bool Queue<T>::isEmpty() const {
  // Returns true if the queue is empty, false otherwise.
  return count == 0;
}

template <typename T> bool Queue<T>::isFull() const {

  // determined by checking if the count of elements is equal to the
  // capacity of the queue.
  return count == capacity;
}

template <typename T> void Queue<T>::GrowQueue() {
  if (capacity <= 0) {
    throw runtime_error("Capacity must be positive.");
  }
  // Grows the queue by doubling the capacity and copying all the elements
  // from the old array to the new array.
  T *newData = new T[capacity * 2];
  for (int i = 0; i < count; i++) {
    // Copy all the elements from the old array to the new array.
    // This is done by using the modulo operator to wrap around the array.
    newData[i] = data[(first + i) % capacity];
  }
  delete[] data;    // Delete the old array.
  data = newData;   // Set the new array as the data member.
  first = 0;        // Reset the first index to 0.
  last = count - 1; // Reset the last index to the last element in the queue.
  capacity *= 2;    // Double the capacity of the queue.
}

template <typename T> void Queue<T>::enqueue(T value) {
  // Enqueues the given value into the queue.
  // If the queue is full, it grows the queue by doubling the capacity.
  // It then moves the rear index and adds the value to the queue.
  if (isFull()) {
    GrowQueue();
  }
  last = (last + 1) % capacity; // Move the rear index.
  data[last] = value;           // Add the value to the queue.
  count++;                      // Increment the count of elements.
}

template <typename T> T Queue<T>::dequeue() {
  // Dequeues the front element from the queue.
  // If the queue is empty, it throws an out_of_range exception.
  // It then moves the front index and returns the dequeued element.
  if (isEmpty()) {
    throw out_of_range("Queue underflow");
  }
  T value = data[first];          // Store the front element in a variable.
  first = (first + 1) % capacity; // Move the front index.
  count--;                        // Decrement the count of elements.
  return value;                   // Return the dequeued element.
}

template <typename T> T Queue<T>::peek() {
  // Returns the front element of the queue without dequeueing it.
  // If the queue is empty, it throws an out_of_range exception.
  if (isEmpty()) {
    throw out_of_range("Queue is empty");
  }
  return data[first]; // Return the front element.
}

template <typename T> int Queue<T>::getSize() {
  // Returns the count of elements in the queue.
  // This is the number of elements that are currently in the queue.
  return count;
}

template <typename T> Tree<T>::Tree() {
  // The default constructor for the Tree class, this creates an empty tree.
  // The data member is initialized to the default value of type T.
  data = T();

  // The array of children is initialized to nullptr.
  // This means that the tree does not have any children.
  for (int i = 0; i < MaxChild; i++) {
    children[i] = nullptr;
  }

  // The parent pointer is initialized to nullptr.
  // This indicates that the tree does not have a parent.
  parent = nullptr;

  // The hasData flag is set to false, indicating that the tree is empty.
  hasData = false;
}

template <typename T> Tree<T>::Tree(T value) {

  // The root node's data is set to the given value.
  data = value;

  // The parent pointer is set to nullptr, indicating that the tree does not
  // have a parent.
  parent = nullptr;

  // The array of children is initialized to nullptr.
  // This means that the tree does not have any children.
  for (int i = 0; i < MaxChild; i++) {
    children[i] = nullptr;
  }

  // The hasData flag is set to false, indicating that the tree is empty.
  hasData = true;
}

template <typename T> Tree<T>::~Tree() {
  // We use a for loop to iterate over the MaxChild elements of the array.
  for (int i = 0; i < MaxChild; i++) {
    // For each element of the array, we check if it is not equal to nullptr.
    // If it is not equal to nullptr, then it is a valid child and we need to
    // delete it.
    if (children[i] != nullptr) {
      // We use the delete operator to delete the child.
      // This will recursively call the destructor on the child, deleting all of
      // its children.
      delete children[i];
    }
  }
}

template <typename T> bool Tree<T>::empty() {

  // Iterate over the children of the current node
  for (int i = 0; i < MaxChild; i++) {
    // If a child is not nullptr, then it is a valid child. If we have found a
    // valid child, then we return false, indicating that the tree is not empty.
    if (children[i] != nullptr) {
      return false;
    }
  }

  // If we have iterated over all the children and not found any valid children,
  // then we return true, indicating that the tree is empty.
  return true;
}

template <typename T> bool Tree<T>::NoChild() {

  // Iterate over the children of the current node
  for (int i = 0; i < MaxChild; i++) {
    // If a child is not nullptr, then it is a valid child.
    // If we have found a valid child, then we return false, indicating that
    // the node does have children.
    if (children[i] != nullptr) {
      return false;
    }
  }

  // If we have iterated over all the children and not found any valid children,
  // then we return true, indicating that the node has no children.
  return true;
}

template <typename T> void Tree<T>::insert(T value) {
  if (MaxChild <= 0) {
    throw invalid_argument("MaxChild must be greater than 0");
  }

  // If the tree is empty (i.e. the root node has no data and no children), then
  // we can simply set the data of the root node to the given value.
  if (!this->hasData && this->NoChild()) {
    data = value;
    this->hasData = true;
    return;
  }

  // Otherwise, we need to traverse the tree to find the first empty child
  // node. We do this by creating a queue and adding the root node to it.
  Queue<Tree<T> *> q;
  q.enqueue(this);

  // While the queue is not empty, continue to traverse the tree.
  while (!q.isEmpty()) {

    // Dequeue the next node in the tree.
    Tree<T> *CurrentNode = q.dequeue();

    // Iterate over the children of the current node, and for each null child,
    // set the child to a new node with the given value.
    for (int i = 0; i < MaxChild; i++) {
      if (CurrentNode->children[i] == nullptr) {
        CurrentNode->children[i] = new Tree(value);
        CurrentNode->children[i]->parent = CurrentNode;
        return;
      } else {
        // If the child is not null, add it to the queue so that we can continue
        // to traverse the tree.
        q.enqueue(CurrentNode->children[i]);
      }
    }
  }
}

template <typename T> int Tree<T>::getData() {
  if (!hasData) {
    throw out_of_range("Tree is empty");
  }
  return data;
} // return data

template <typename T> Tree<T> *Tree<T>::getChild(int data, int childNumber) {

  if (childNumber < 0 || childNumber >= MaxChild) {
    // If the child number is out of range, throw an exception.
    throw out_of_range("Child number out of range");
  }

  // Create a queue to hold the nodes as we traverse the tree.
  Queue<Tree<T> *> q;
  // Start with the current root node.
  q.enqueue(this);

  // While the queue is not empty, continue to traverse the tree.
  while (!q.isEmpty()) {
    // Dequeue the next node in the tree.
    Tree<T> *CurrentNode = q.dequeue();

    // If the current node has data equal to the given data, then we have
    // found the node we are searching for.
    if (data == CurrentNode->getData()) {
      // If the child at the given index is null, then return null.
      if (CurrentNode->children[childNumber] == nullptr) {
        return nullptr;
      } else {
        // Otherwise, return the child at the given index.
        return CurrentNode->children[childNumber];
      }
    }

    // Otherwise, we need to search the children of the current node. Iterate
    // over the children of the current node, and for each non-null child,
    // enqueue it in the queue.
    for (int i = 0; i < MaxChild; i++) {
      if (CurrentNode->children[i] != nullptr) {
        q.enqueue(CurrentNode->children[i]);
      }
    }
  }

  // If we have traversed the entire tree and have not found the node with the
  // given data, then return null.
  return nullptr;
}

// template <typename T> Tree<T> *Tree<T>::deleteNode(T value) {

//   if (this->searchInTree(value) == nullptr) {
//     throw invalid_argument("Node with the specified value does not exist");
//   }

//   Tree<T> *newRoot = new Tree<T>();

//   Queue<Tree<T> *> q;
//   q.enqueue(this); // Start with the current root (this)

//   while (!q.isEmpty()) {
//         Tree<T> *CurrentNode = q.dequeue();

//         // If the current node's data matches the value to delete
//         if (CurrentNode->getData() == value) {
//             // Do not add this node to the new tree
//             // Instead, enqueue all its children to preserve the structure
//             for (int i = 0; i < MaxChild; i++) {
//                 if (CurrentNode->children[i] != nullptr) {
//                     q.enqueue(CurrentNode->children[i]);
//                 }
//             }
//             continue; // Skip the rest of the loop for this node
//         }

//         // Otherwise, we create the new root tree
//         if (newRoot == nullptr) {
//             newRoot->insert(CurrentNode->getData());
//         }
        
//         // Enqueue children of the current node for further processing
//         for (int i = 0; i < MaxChild; i++) {
//             if (CurrentNode->children[i] != nullptr) {
//                 q.enqueue(CurrentNode->children[i]);
//             }
//         }
//     }

//   return newRoot;
// }

template <typename T> int Tree<T>::height() {
  // Recursively calculate the height of the tree.
  // The height of a tree is the number of nodes from the root node to the
  // furthest leaf node.
  int height = 0;

  // Iterate over the children of the current node
  for (int i = 0; i < MaxChild; i++) {
    if (children[i] != nullptr) {
      // For each non-null child, recursively calculate the height of the
      // subtree rooted at that child.
      int subtreeHeight = children[i]->height();
      // Add 1 to the height of the subtree, since we are one level above the
      // subtree.
      int candidateHeight = subtreeHeight + 1;
      // Keep track of the maximum height seen so far.
      height = max(height, candidateHeight);
    }
  }
  // Return the maximum height seen.
  return height;
}

template <typename T> int Tree<T>::degreeofTree() {
  // The degree of a tree is the maximum number of children any node in the tree
  // has. This function returns the degree of the tree.
  int degree = 0;

  // Iterate over the children of the current node
  for (int i = 0; i < MaxChild; i++) {
    // If the child at index i is not null, then it is a valid child
    if (children[i] != nullptr) {
      // Increment the degree by 1 for each valid child
      degree++;
    }
  }

  // Return the degree of the tree
  return degree;
}

template <typename T> void Tree<T>::update(T oldValue, T newValue) {
  Tree<T> *nodeToUpdate = searchInTree(oldValue);
  if (!nodeToUpdate) {
    throw invalid_argument("Value to update not found");
  }

  // If the root node is the one with data equal to oldValue, then we just
  // change the data of the root node to newValue.
  if (data == oldValue) {
    data = newValue;
  } else {
    // If the root node is not the one with data equal to oldValue, then we
    // search the children of the root node for a node with data equal to
    // oldValue.
    for (int i = 0; i < MaxChild; i++) {
      if (children[i] != nullptr) {
        // For each non-null child, we recursively call the update function
        // on that child, passing in the same oldValue and newValue.
        children[i]->update(oldValue, newValue);
      }
    }
  }
}

template <typename T> Tree<T> *Tree<T>::searchInTree(T value) {
  // If the data of the root node is equal to the given value, then we return
  // the root node itself, since it is the node we are searching for.
  if (data == value) {
    return this;
  }

  // Otherwise, we need to search the children of the root node. We do this by
  // iterating over the children, and for each non-null child, we recursively
  // call the searchInTree function on that child, passing in the same value.
  for (int i = 0; i < MaxChild; i++) {
    if (children[i] != nullptr) {
      // We call the searchInTree function on the child, and check if the result
      // is not nullptr. If it is not nullptr, then the child found the node we
      // are searching for, so we return the result.
      Tree<T> *result = children[i]->searchInTree(value);
      if (result != nullptr) {
        return result;
      }
    }
  }

  // If we have checked all the children of the root node, and none of them have
  // found the node we are searching for, then we return nullptr, indicating
  // that the node was not found.
  return nullptr;
}

template <typename T> int Tree<T>::treeSize() {
  // We start with a size of 1, since we are counting the current node.
  int size = 1;

  // We then iterate over the children of the current node.
  for (int i = 0; i < MaxChild; i++) {
    // If the child at index i is not nullptr, then it is a valid child.
    if (children[i] != nullptr) {
      // We then recursively call the treeSize function on that child,
      // and add the result to our total size.
      size += children[i]->treeSize();
    }
  }

  // Finally, we return the total size of the tree.
  return size;
}

// Explicitly instantiate the Queue class template for the following types:
//   int, double, float, and char.
//
// This is necessary because the Queue class template is defined in the header
// file, and the linker will not instantiate the template for these types
// automatically. By explicitly instantiating the template here, we ensure
// that the linker will include the template instantiations in the object file.
//
// Note that this is only necessary because we are using a separate
// compilation unit for the template definitions. If we were to define the
// template functions in the header file, then the linker would automatically
// instantiate the template for all types used in the program.

template class Queue<int>;
template class Queue<double>;
template class Queue<float>;
template class Queue<char>;

template class Tree<int>;
template class Tree<double>;
template class Tree<float>;
template class Tree<char>;

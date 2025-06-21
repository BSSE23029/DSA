#include "functions.h"

int List::getIndexData(int index) {

  if (isEmpty()) {
    throw out_of_range("List is empty");
  }

  if (index == 0)
    return head->getData();

  Node *temp = head;

  for (int i = 0; i < index; i++) {
    if (temp == nullptr) {
      throw out_of_range("Index out of bounds");
    }
    temp = temp->getNext();
  }

  if (temp == nullptr) {
    throw out_of_range("Index out of bounds");
  }

  return temp->getData();
}

void List::swapNodes(Node *node1, Node *node2) {

  // Sanity check: make sure the nodes are not null and are not the same
  if (node1 == nullptr || node2 == nullptr || node1 == node2)
    return;

  // Find the previous node of the first node we want to swap
  Node *prev1 = nullptr;
  Node *temp1 = head;
  while (temp1 != node1) {
    if (temp1 == nullptr) {
      throw std::runtime_error("First node to swap does not exist in the list");
    }
    prev1 = temp1;
    temp1 = temp1->getNext();
  }

  // Find the previous node of the second node we want to swap
  Node *prev2 = nullptr;
  Node *temp2 = head;
  while (temp2 != node2) {
    if (temp2 == nullptr) {
      throw std::runtime_error(
          "Second node to swap does not exist in the list");
    }
    prev2 = temp2;
    temp2 = temp2->getNext();
  }

  // Update the next pointer of the first previous node to point to the
  // second node. If the first node is the head, update the head.
  if (prev1 == nullptr)
    head = node2;
  else
    prev1->setNext(node2);

  // Update the next pointer of the second previous node to point to the
  // first node. If the second node is the head, update the head.
  if (prev2 == nullptr)
    head = node1;
  else
    prev2->setNext(node1);

  // Update the next pointer of each of the two nodes to point to the
  // appropriate new node. We use a temporary variable to keep track of
  // the next node after the first node, so that we can update the next
  // pointer of the second node to point to it.
  Node *tempSwap = node1->getNext();
  node1->setNext(node2->getNext());
  node2->setNext(tempSwap);

  // If swapping involves the tail, update it
  if (node1->getNext() == nullptr)
    tail = node1;
  if (node2->getNext() == nullptr)
    tail = node2;
}

int List::getLength() {
  int length = 0;
  Node *temp = head;
  while (temp != nullptr) {
    length++;
    temp = temp->getNext();
  }
  return length;
}

void List::bubbleSort() {
  if (isEmpty() || getLength() == 1)
    return; // List is empty or has one element, nothing to sort

  bool swapped; // To track if any swaps were made
  do {
    swapped = false;      // Reset swapped flag for this pass
    Node *current = head; // Start from the head of the list

    while (current != nullptr && current->getNext() != nullptr) {
      if (current->getData() > current->getNext()->getData()) {
        swapNodes(current, current->getNext()); // Swap nodes
        swapped = true;                         // Set swapped to true
      }
      current = current->getNext(); // Move to the next node
    }
  } while (swapped); // Repeat until no swaps are made
}

// void List::selectionSort() {
//     if (isEmpty() || getLength() <= 1) return;

//     Node* current = head;
//     while (current != nullptr && current->getNext() != nullptr) {
//         Node* minNode = current;
//         Node* temp = current->getNext();

//         // Find minimum element in unsorted portion
//         while (temp != nullptr) {
//             if (temp->getData() < minNode->getData()) {
//                 minNode = temp;
//             }
//             temp = temp->getNext();
//         }

//         // Swap found minimum with current node
//         if (minNode != current) {
//             swapNodes(current, minNode);
//         }

//         current = current->getNext();
//     }
// }

// Select the smallest element from unsorted portion
// Swap it with the first unsorted element
// Move to the next unsorted element
// Repeat steps 1-3 until entire array is sorted

void List::selectionSort() {

  // If the list is empty or has only one element, there's nothing to sort
  if (isEmpty() || getLength() <= 1)
    return;

  // We'll keep looping until no swaps are made in a pass
  bool swapped;
  do {
    swapped = false; // Reset swapped flag for this pass
    Node *current = head; // Start from the head of the list

    while (current != nullptr && current->getNext() != nullptr) {
      // If the current node is smaller than the next node, swap them
      if (current->getData() < current->getNext()->getData()) {
        swapNodes(current, current->getNext()); // Swap nodes
        swapped = true; // Set swapped to true
      }
      current = current->getNext(); // Move to the next node
    }
  } while (swapped); // Repeat until no swaps are made

  // Reversing the list
  Node *prev = nullptr;
  Node *current = head;
  while (current != nullptr) {
    // Store the next node before changing the current node's next pointer
    Node *nextTemp = current->getNext();
    current->setNext(prev); // Set the current node's next pointer to the previous node
    prev = current; // Move the previous node to the current node
    current = nextTemp; // Move to the next node
  }
  head = prev; // Set the head to the last node in the reversed list
}


// template <typename T> void MyArray<T>::insertionSort1D(T*& array) {
//         int n = d0; // Assuming d0 represents the size of the 1D array
//         for (int i = 0; i < n; i++) {
//             T key = array[i];
//             int j = i - 1;
//             while (j >= 0 && array[j] > key) {
//                 array[j + 1] = array[j];
//                 j--;
//             }
//             array[j + 1] = key;
//         }
//     }

// Start with the second element
// Compare it with the previous elements
// Shift larger elements to the right
// Insert the current element at its correct position
// Repeat for remaining elements

Node *List::getPrevious(Node *node) {
  if (node == nullptr || node == head) {
    // If node is nullptr or the head, there's no previous node
    return nullptr;
  }

  Node *current = head;
  while (current != nullptr && current->getNext() != node) {
    current = current->getNext();
  }

  return current; // Will return nullptr if no previous node is found
}

void List::insertionSort() {
  if (isEmpty() || getLength() <= 1) {
        cout << "List is empty or has less than 2 nodes. No sorting needed." << endl;
        return;
    }

    Node *sorted = nullptr; // This will store the sorted list

    Node *current = head; // Start from the first node
    while (current != nullptr) {
        Node *next = current->getNext(); // Save the next node before re-linking
        if (sorted == nullptr || sorted->getData() >= current->getData()) {
            // Insert at the beginning of the sorted list
            current->setNext(sorted);
            sorted = current;
        } else {
            // Traverse the sorted part to find the correct position
            Node *temp = sorted;
            while (temp->getNext() != nullptr && temp->getNext()->getData() < current->getData()) {
                temp = temp->getNext();
            }
            current->setNext(temp->getNext());
            temp->setNext(current);
        }
        current = next; // Move to the next node in the original list
    }

    head = sorted; // Update the head pointer to point to the new sorted list

}

Node *List::findMin(Node *start) {
  if (start == nullptr) {
    return nullptr;
  }

  Node *minNode = start;
  while (start->getNext() != nullptr) {
    if (start->getNext()->getData() < minNode->getData()) {
      minNode = start->getNext();
    }
    start = start->getNext();
  }
  return minNode;
}

//  template <typename T> void MyArray<T>::merge(T*& array, int left, int mid,
//  int right) {
//         int n1 = mid - left + 1;
//         int n2 = right - mid;
//         T* L = new T[n1];
//         T* R = new T[n2];

//         for (int i = 0; i < n1; i++)
//             L[i] = array[left + i];
//         for (int i = 0; i < n2; i++)
//             R[i] = array[mid + 1 + i];

//         int i = 0, j = 0, k = left;
//         while (i < n1 && j < n2) {
//             if (L[i] <= R[j]) {
//                 array[k] = L[i];
//                 i++;
//             } else {
//                 array[k] = R[j];
//                 j++;
//             }
//             k++;
//         }

//         while (i < n1) {
//             array[k] = L[i];
//             i++;
//             k++;
//         }

//         while (j < n2) {
//             array[k] = R[j];
//             j++;
//             k++;
//         }

//         delete[] L;
//         delete[] R;
//     }

//     template <typename T> void MyArray<T>::mergeSortRecursion(T*& array, int
//     left, int right) {
//         if (left < right) {
//             int mid = left + (right - left) / 2;
//             mergeSortRecursion(array, left, mid);
//             mergeSortRecursion(array, mid + 1, right);
//             merge(array, left, mid, right);
//         }
//     }

// Merge function
void List::merge(Node *&headRef, Node *left, Node *right) {
  // Create a dummy node to simplify merging process
  Node dummy;
  Node *tail = &dummy;    // Pointer to the last node in the merged list
  dummy.setNext(nullptr); // Initialize dummy's next to nullptr

  // Merge the two lists until one is exhausted
  while (left && right) {
    if (left->getData() <= right->getData()) {
      tail->setNext(left);    // Link the next node
      left = left->getNext(); // Move to the next node in the left list
    } else {
      tail->setNext(right);     // Link the next node
      right = right->getNext(); // Move to the next node in the right list
    }
    tail = tail->getNext(); // Move the tail pointer to the last node
  }

  // Attach the remaining nodes from the non-exhausted list
  if (left) {
    tail->setNext(left); // Link remaining left nodes
  } else {
    tail->setNext(right); // Link remaining right nodes
  }

  headRef = dummy.getNext(); // Update headRef to point to the merged list
}

// Recursively split the list into halves
void List::mergeSortRecursion(Node *&headRef) {
  if (!headRef || !headRef->getNext())
    return;

  Node *left = headRef;
  Node *right = headRef;
  Node *prev = nullptr;

  // Split the list into two halves
  while (right && right->getNext()) {
    prev = left;
    left = left->getNext();
    right = right->getNext()->getNext();
  }

  prev->setNext(nullptr); // Break the list into two parts

  // Recursively sort both halves
  mergeSortRecursion(headRef);
  mergeSortRecursion(left);

  // Merge the two sorted halves
  merge(headRef, headRef, left);
}

// Call mergeSort on the entire list
void List::mergeSort() { mergeSortRecursion(head); }

// Helper function to partition the list
int List::partition(List *list, int low, int high) {
  int pivot = list->getIndexData(high);
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (list->getIndexData(j) < pivot) {
      i++;
      // Swap elements at indices i and j
      list->swapNodes(list->getNodeAtIndex(i), list->getNodeAtIndex(j));
    }
  }

  // Swap pivot element with element at index i+1
  list->swapNodes(list->getNodeAtIndex(i + 1), list->getNodeAtIndex(high));

  return i + 1;
}

void List::quickSort(int low, int high) {
  if (low >= high)
    return;

  int pivotIndex = partition(this, low, high);

  quickSort(low, pivotIndex - 1);
  quickSort(pivotIndex + 1, high);
}

void List::quickSort() {
  if (isEmpty() || getLength() <= 1)
    return;
  quickSort(0, getLength() - 1);
}

Node *List::getNodeAtIndex(int index) {
  Node *temp = head;
  for (int i = 0; i < index && temp != nullptr; i++) {
    temp = temp->getNext();
  }
  return temp;
}

void List::countSort() {
  if (isEmpty())
    return;

  int maxVal = findMaxValue();
  int minVal = findMinValue();

  // cout << "\ndone\n";

  int range = maxVal - minVal + 1;
  vector<int> count(range, 0);

  // Count occurrences
  Node *temp = head;
  while (temp != nullptr) {
    count[temp->getData() - minVal]++;
    temp = temp->getNext();
  }

  // Calculate cumulative counts
  for (int i = 1; i < range; i++) {
    count[i] += count[i - 1];
  }

  // Build output array
  vector<int> output(getLength());
  temp = head;
  int index = 0;
  while (temp != nullptr) {
    output[count[temp->getData() - minVal] - 1] = temp->getData();
    count[temp->getData() - minVal]--;
    temp = temp->getNext();
    index++;
  }

  // Update original list
  clearList();
  for (int val : output) {
    append(val);
  }
}

int List::findMaxValue() {
  int maxVal = 0;
  Node *temp = head;
  while (temp != nullptr) {
    maxVal = max(maxVal, temp->getData());
    temp = temp->getNext();
  }
  return maxVal;
}

int List::findMinValue() {
  int minVal = 0;
  Node *temp = head;
  while (temp != nullptr) {
    minVal = min(minVal, temp->getData());
    temp = temp->getNext();
  }
  return minVal;
}

void List::clearList() {
  while (!isEmpty()) {
    deleteFromStart();
  }
}

void List::radixSort() {
  if (isEmpty())
    return;

  int maxVal = findMaxValue();
  int exp = 1;

  while (maxVal / exp > 0) {
    countingSort(exp);
    exp *= 10;
  }
}

void List::countingSort(int exp) {
  const int MAX_DIGIT = 10;
  vector<List> buckets(MAX_DIGIT);

  // Distribute elements into buckets
  Node *temp = head;
  while (temp != nullptr) {
    int bucketIndex = (temp->getData() / exp) % MAX_DIGIT;
    buckets[bucketIndex].append(temp->getData());
    temp = temp->getNext();
  }

  // Collect elements from buckets
  clearList();
  for (auto &bucket : buckets) {
    Node *bucketTemp = bucket.getHead();
    while (bucketTemp != nullptr) {
      append(bucketTemp->getData());
      bucketTemp = bucketTemp->getNext();
    }
  }
}

// Lab-5

Node::Node() { next = nullptr; }

Node::~Node() { // delete next;
}

Node::Node(int data) {
  this->data = data;
  next = nullptr;
}

void Node::setNext(Node *val) { next = val; }

Node *Node::getNext() { return next; }

int Node::getData() { return data; }

void Node::setData(int data) { this->data = data; }

List::List() {
  head = nullptr;
  tail = nullptr;
}

List::~List() {

  Node *current = head;
  while (current != nullptr) {
    Node *next = current->getNext();
    delete current;
    current = next;
  }
}

bool List::isEmpty() {
  if (head == nullptr && tail == nullptr)
    return true;
  return false;
}

void List::append(int data) {

  Node *newNode = new Node(data);

  if (isEmpty()) {
    head = newNode;
    tail = newNode;
  }

  else {
    tail->setNext(newNode);
    tail = newNode;
  }
}

void List::prepend(int data) {

  Node *newNode = new Node(data);

  if (isEmpty()) {
    head = newNode;
    tail = newNode;
  }

  else {

    newNode->setNext(head);
    head = newNode;
  }
}

void List::insertAtIndex(int data, int index) {

  // Case: Empty list, simply append or prepend
  if (index <= 0 || isEmpty()) {
    prepend(data); // Insert at the start for index <= 0
    return;
  }

  Node *newNode = new Node(data);
  Node *temp = head;

  // Traverse to the node just before the target index
  for (int i = 0; i < index - 1 && temp->getNext() != nullptr; i++) {
    temp = temp->getNext();
  }

  // Insert the new node between temp and temp->getNext()
  newNode->setNext(temp->getNext());
  temp->setNext(newNode);

  // If inserting at the last position, update the tail
  if (newNode->getNext() == nullptr) {
    tail = newNode;
  }
}

void List::deleteFromEnd() {
  if (isEmpty()) {
    // List is empty Cannot delete from end
    return;
  }

  Node *temp = head;

  if (temp->getNext() == nullptr) {
    delete temp;
    head = nullptr;
    tail = nullptr;
    return;
  }

  while (temp->getNext() != tail) {
    temp = temp->getNext();
  }

  delete tail;
  tail = temp;
  temp->setNext(nullptr);
}

void List::deleteFromStart() {

  if (isEmpty()) {
    // List is empty Cannot delete from start
    return;
  }

  //   Node *temp = head;

  //   if (temp->getNext() == nullptr) {
  //     head = nullptr;
  //     tail = nullptr;
  //     delete temp;
  //     return;
  //   }

  //   head = temp->getNext();
  //   delete temp;

  //   if (isEmpty()) return;

  Node *temp = head;
  head = head->getNext();
  delete temp;
  if (head == nullptr)
    tail = nullptr;
}

void List::deleteFromIndex(int index) {

  if (isEmpty() || index < 0) {
    return;
  }

  //   Node *temp = head;

  //   Node *max = head;
  //   int maxIndex = -1;

  //   while (max != nullptr) {
  //     maxIndex++;
  //     max = max->getNext();
  //   }

  if (index == 0) {
    deleteFromStart();
    return;
  }

  Node *temp = head;
  for (int i = 0; i < index - 1 && temp->getNext() != nullptr; i++) {
    temp = temp->getNext();
  }

  if (temp->getNext() == nullptr) {
    return;
  }

  Node *temp2 = temp->getNext();
  temp->setNext(temp2->getNext());
  if (temp2 == tail)
    tail = temp;
  delete temp2;

  //   if (index == maxIndex) {
  //     deleteFromEnd();
  //     return;
  //   }

  //   for (int i = 0; i < index - 1; i++) {
  //     temp = temp->getNext();
  //   }

  //   Node *temp2 = temp->getNext();

  //   temp->setNext(temp2->getNext());

  //   // No need to update tail here

  //   delete temp2;
}

Node *List::getHead() { return head; }

Node *List::getTail() { return tail; }

void List::printList() {

  Node *temp = head;

  while (temp != nullptr) {
    cout << temp->getData() << " ";
    temp = temp->getNext();
  }
}

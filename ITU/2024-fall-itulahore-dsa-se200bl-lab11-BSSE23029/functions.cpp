#include "functions.h"

Edge::Edge(int dest, int c) {
  destination = dest;
  cost = c;
  next = nullptr;
}

int Edge::getDestination() { return destination; }

int Edge::getCost() { return cost; }

Edge *Edge::getNext() { return next; }

void Edge::setNext(Edge *nextEdge) { next = nextEdge; }

void Edge::setDestination(int dest) { destination = dest; }

void Edge::setCost(int c) { cost = c; }

Node::Node(int val) {
  data = val;
  next = nullptr;
  edges = nullptr;
  edgeCount = 0;
}

int Node::getData() { return data; }

Node *Node::getNext() { return next; }

Edge *Node::getEdges() { return edges; }

int Node::getEdgeCount() { return edgeCount; }

void Node::setNext(Node *nextNode) { next = nextNode; }

void Node::setEdges(Edge *edgeList) { edges = edgeList; }

void Node::setData(int value) { data = value; }

void Node::incrementEdgeCount() { edgeCount++; }

void Node::decrementEdgeCount() { edgeCount--; }

Graph::Graph() {
  nodes = nullptr;
  nodeCount = 0;
}

Graph::~Graph() {
  delete nodes;
}

void Graph::addNode(int nodeValue) {
  Node *newNode = new Node(nodeValue);
  newNode->setNext(nodes);
  nodes = newNode;
  nodeCount++;
}

Node *Graph::getNode(int src) {
  Node *temp = nodes;
  while (temp->getData() != src) {
    temp = temp->getNext();
  }
  return temp;
}

void Graph::addEdge(int source, int destination, int cost) {
  // Find the source node and the destination node in the graph.
  Node *sourceNode = getNode(source);
  Node *destinationNode = getNode(destination);

  // Create a new edge with the given cost.
  Edge *newEdge = new Edge(destination, cost);

  // Set the next pointer of the new edge to the edge list of the source node.
  newEdge->setNext(sourceNode->getEdges());

  // Set the edge list of the source node to the new edge.
  sourceNode->setEdges(newEdge);

  // Increment the edge count of the source node by one.
  sourceNode->incrementEdgeCount();

  // Increment the edge count of the destination node by one.
  destinationNode->incrementEdgeCount();
}

int Graph::getEdgeCost(int source, int destination) {
  Node *sourceNode = getNode(source);
  Edge *temp = sourceNode->getEdges();
  while (temp->getDestination() != destination) {
    temp = temp->getNext();
  }
  return temp->getCost();
}

int Graph::getEdgeCountForNode(int nodeValue) {
  Node *temp = getNode(nodeValue);
  return temp->getEdgeCount();
}

int Graph::getNodeCount() { return nodeCount; }

void Graph::updateNode(int oldValue, int newValue) {
  Node *temp = nodes;
  while (temp->getData() != oldValue) {
    temp = temp->getNext();
  }
  temp->setData(newValue);

  // update edges for all nodes
  
  temp = nodes;
  while (temp->getNext()) {
    Edge *edge = temp->getEdges();
    while (edge->getNext()) {
      if (edge->getDestination() == oldValue) {
        edge->setDestination(newValue);
      }
      edge = edge->getNext();
    }
    temp = temp->getNext();
  }
}

void Graph::deleteNode(int nodeValue) {
  Node *temp = nodes;
  Node *prev = nullptr;
  while (temp->getData() != nodeValue) {
    prev = temp;
    temp = temp->getNext();
  }
  prev->setNext(temp->getNext());
  delete temp;
  nodeCount--;

  // update edges for all nodes
  
  temp = nodes;
  while (temp->getNext()) {
    Edge *edge = temp->getEdges();
    while (edge->getNext()) {
      if (edge->getDestination() == nodeValue) {
        deleteEdge(temp->getData(), edge->getDestination());
      }
      edge = edge->getNext();
    }
    temp = temp->getNext();
  }
}

bool Graph::hasNode(int nodeValue) {
  Node *temp = getNode(nodeValue);
  return temp != nullptr;
}

void Graph::deleteEdge(int source, int destination) {
  Node *sourceNode = getNode(source);
  Edge *temp = sourceNode->getEdges();
  Edge *prev = nullptr;
  while (temp->getDestination() != destination) {
    prev = temp;
    temp = temp->getNext();
  }
  prev->setNext(temp->getNext());
  delete temp;
  sourceNode->decrementEdgeCount();
  getNode(destination)->decrementEdgeCount();
}

void Graph::display() {
  Node *temp = nodes;
  while (temp->getNext()) {
    cout << temp->getData() << " -> ";
    temp = temp->getNext();
  }
  cout << temp->getData() << endl;
}

Node *Graph::getNodes() { return nodes; }

MinHeap::MinHeap(int capacity) {
  heap = new Edge *[capacity + 1];

  heapSIze = 0;
  this->capacity = capacity;
}

bool MinHeap::isEmpty() { return heapSIze == 0; }

void MinHeap::insert(Edge *edge) {
  if (heapSIze == capacity) {
    cout << "Heap is full. Cannot insert" << std::endl;
    return;
  }

  // increment the heap size
  heapSIze++;

  // start at the last element in the heap
  int currentIndex = heapSIze;

  // store the edge in the heap
  heap[currentIndex] = edge;

  /*
    Now, we need to bubble up the inserted element to the correct
    position in the heap. We do this by swapping the element with
    its parent if the element is smaller than its parent. We
    continue this process until we reach the root of the heap, or
    the element is larger than its parent.
   */
  while (currentIndex > 1 &&
         heap[currentIndex]->getCost() < heap[currentIndex / 2]->getCost()) {
    // swap the element with its parent
    swap(currentIndex, currentIndex / 2);

    // move to the parent
    currentIndex /= 2;
  }
}

Edge *MinHeap::extractMin() {
  // Check if the heap is empty. If it is, we cannot extract an element.
  if (isEmpty()) {
    cout << "Heap is empty. Cannot extract" << endl;
    return nullptr;
  }

  // Store the root of the heap in a temporary variable, as we'll be
  // overwriting it with the last element of the heap.
  Edge *root = heap[1];

  // Store the last element of the heap in a temporary variable, as we'll
  // be moving it to the root of the heap.
  Edge *last = heap[heapSIze];

  // Move the last element of the heap to the root of the heap.
  heap[1] = last;

  // Decrement the heap size, as we've just removed an element from the
  // heap.
  heapSIze--;

  // Call the heapify function to ensure that the heap is still valid.
  // This is necessary, as we've just changed the root of the heap, and
  // we need to make sure that the heap property is maintained.
  heapify(1);

  // Return the root of the heap, which is now the minimum element in the
  // heap.
  return root;
}

void MinHeap::heapify(int index) {
  // Assume the smallest element is at the current index
  int smallest = index;

  // Calculate the index of the left child
  int leftChild = 2 * index;

  // Calculate the index of the right child
  int rightChild = 2 * index + 1;

  // Check if the left child exists and is smaller than the current smallest element
  if (leftChild <= heapSIze &&
      heap[leftChild]->getCost() < heap[smallest]->getCost()) {
    // Update smallest to be the left child
    smallest = leftChild;
  }

  // Check if the right child exists and is smaller than the current smallest element
  if (rightChild <= heapSIze &&
      heap[rightChild]->getCost() < heap[smallest]->getCost()) {
    // Update smallest to be the right child
    smallest = rightChild;
  }

  // If the smallest element is not the current index, swap and continue heapifying
  if (smallest != index) {
    // Swap the current element with the smallest element
    swap(index, smallest);

    // Recursively call heapify on the smallest index
    heapify(smallest);
  }
}

void MinHeap::swap(int i, int j) {
  Edge *temp = heap[i];
  heap[i] = heap[j];
  heap[j] = temp;
}

PrimMST::PrimMST(Graph *graph) {
  this->graph = graph;
  inMST = new bool[graph->getNodeCount() + 1];
  mstCost = 0;
}

void PrimMST::runPrim(int startNode) {
  // First, we need to initialize the inMST array to keep track of which nodes
  // are in the minimum spanning tree (MST). We'll set all of them to false
  // initially.
  for (int i = 0; i < graph->getNodeCount(); i++) {
    inMST[i] = false;
  }

  // Next, we'll create a MinHeap to store the edges of the graph. We'll use
  // this heap to find the minimum-weight edge at each step of the algorithm.
  MinHeap heap(graph->getNodeCount());

  // We'll start by adding all the edges of the starting node to the heap. This
  // is because we'll be expanding from this node in the first step of the
  // algorithm.
  Edge *startNodeEdge = graph->getNode(startNode)->getEdges();
  while (startNodeEdge != nullptr) {
    heap.insert(startNodeEdge);
    startNodeEdge = startNodeEdge->getNext();
  }

  // We'll mark the starting node as included in the MST, since we've already
  // added all its edges to the heap.
  inMST[startNode] = true;

  // Now, we'll enter the main loop of the algorithm. We'll keep extracting
  // the minimum-weight edge from the heap until the heap is empty.
  while (!heap.isEmpty()) {
    // Extract the minimum-weight edge from the heap
    Edge *minEdge = heap.extractMin();

    // We need to find the correct 'u' from the graph structure. This is the
    // node that the minimum-weight edge is incident on.
    int u = startNode; // You need to find the correct 'u' from the graph structure

    // The other end of the minimum-weight edge is the node 'v'.
    int v = minEdge->getDestination();

    // If 'v' is not already in the MST, we'll add it to the MST and update
    // the cost of the MST.
    if (!inMST[v]) {
      inMST[v] = true;
      mstCost += minEdge->getCost();

      // We'll also add all the edges of 'v' to the heap, so that we can
      // consider them in the next step of the algorithm.
      addEdgesToHeap(v, heap);
    }
  }
}

void PrimMST::addEdgesToHeap(int node, MinHeap &heap) {
  // Get the first edge of the node
  Edge *neighbourEdge = graph->getNode(node)->getEdges();

  // Iterate over all the edges of the node
  while (neighbourEdge != nullptr) {
    // Check if the destination of the edge is not already in the
    // MST. If it is not, add the edge to the heap.
    if (!inMST[neighbourEdge->getDestination()]) {
      heap.insert(neighbourEdge);
    }

    // Move to the next edge of the node
    neighbourEdge = neighbourEdge->getNext();
  }
}


int PrimMST::getMSTCost() { return mstCost; }

bool PrimMST::isNodeInMST(int node) { return inMST[node]; }

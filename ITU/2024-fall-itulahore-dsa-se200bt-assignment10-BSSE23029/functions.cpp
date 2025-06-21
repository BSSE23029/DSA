#include "functions.h"
/*





EDGE




*/

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

/*





NODE




*/

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

void Node::setEdges(Edge *edgeList) {
  edges = edgeList;
  // if (edgeList == nullptr) {
  //   edges = nullptr;
  // } else {
  //   Edge *lastEdge = edges;
  //   while (!lastEdge->getNext()) {
  //     lastEdge = lastEdge->getNext();
  //   }
  //   lastEdge->setNext(edgeList);
  //   incrementEdge();
  // }
}

void Node::setData(int value) { data = value; }

void Node::incrementEdge() { edgeCount++; }

void Node::decrementEdge() { edgeCount--; }

void Node::deleteEdges() {
  Edge *currentEdge = edges;
  while (currentEdge != nullptr) {
    Edge *nextEdge = currentEdge->getNext();
    delete currentEdge;
    currentEdge = nextEdge;
  }
  edges = nullptr;
  edgeCount = 0;
}

/*





GRAPH




*/

Graph::Graph() {
  nodes = nullptr;
  nodeCount = 0;
}

Graph::~Graph() { delete[] nodes; }

Node *Graph::findNode(int sourceValue) {
  Node *current = nodes;
  while (current != nullptr) {
    if (current->getData() == sourceValue) {
      return current;
    }
    current = current->getNext();
  }
  return nullptr;
}

void Graph::addNode(int nodeValue) {
  if (hasNode(nodeValue)) {
    return;
  }

  Node *newNode = new Node(nodeValue);
  if (nodes == nullptr) {
    nodes = newNode;
    nodeCount = 1;
  } else {
    newNode->setNext(nodes);
    nodes = newNode;
    nodeCount++;
  }
}

void Graph::addEdge(int source, int destination, int cost) {

  // cout << "\nin loop: " << 1 << endl;
  if (source == destination) {
    // Cannot add an edge to itself
    cout << "Cannot add an edge to the same node" << endl;
    return;
  }

  Node *sourceNode = findNode(source);
  Node *destinationNode = findNode(destination);

  // cout << "\nin loop: " << 2 << endl;
  if (!sourceNode) {
    cout << "Source node does not exist" << endl;
    return;
  }

  // cout << "\nin loop: " << 3 << endl;
  if (!destinationNode) {
    cout << "Destination node does not exist" << endl;
    return;
  }

  // cout << "\nin loop: " << 4 << endl;
  Edge *currentEdge = sourceNode->getEdges();
  while (currentEdge != nullptr) {
    if (currentEdge->getDestination() == destination) {
      // Edge already exists, do not add a duplicate
      cout << "Edge already exists" << endl;
      return;
    }
    currentEdge = currentEdge->getNext();
  }

  // cout << "\nin loop: " << 5 << endl;
  try {
    Edge *newEdge = new Edge(destination, cost);
    newEdge->setNext(sourceNode->getEdges());
    sourceNode->setEdges(newEdge);
    sourceNode->incrementEdge();
  } catch (const std::bad_alloc &e) { // bad allocation with exception e
    cout << "Memory allocation failed: " << e.what() << endl;
  }
}

int Graph::getEdgeCost(int source, int destination) {
  Node *sourceNode = findNode(source);
  if (sourceNode) {
    // cout << endl << "d1:" << source << "\td2:" << destination << endl;
    Edge *currentEdge = sourceNode->getEdges();
    while (currentEdge != nullptr) {
      // cout << endl << "d3: " << currentEdge->getDestination() << endl;
      if (currentEdge->getDestination() == destination) {
        return currentEdge->getCost();
      }
      currentEdge = currentEdge->getNext();
    }
  }
  return -1; // Edge not found
}

int Graph::getEdgeCountForNode(int nodeValue) {
  Node *node = findNode(nodeValue);

  if (node) {
    return node->getEdgeCount();
  }
  return -1; // Node not found
}

int Graph::getNodeCount() { return nodeCount; }

void Graph::updateNode(int oldValue, int newValue) {

  Node *oldNode = findNode(oldValue);

  if (!oldNode) {
    cout << "\nNode does not exists\n";
    return;
  }

  Node *newNode = findNode(newValue);

  if (newNode) {
    cout << "\nNode already exists\n";
    return;
  }

  oldNode->setData(newValue);

  Node *current = nodes;
  while (current) {
    Edge *currentEdge = current->getEdges();
    while (currentEdge) {
      if (currentEdge->getDestination() == oldValue) {
        currentEdge->setDestination(newValue);
        break;
      }
      currentEdge = currentEdge->getNext();
    }
    current = current->getNext();
  }
}

void Graph::deleteNode(int nodeValue) {
  Node *nodeToDelete = findNode(nodeValue);
  if (nodeToDelete) {
    // Remove edges pointing to this node from all other nodes
    Node *current = nodes;
    while (current) {
      Edge *currentEdge = current->getEdges();
      Edge *prevEdge = nullptr;
      while (currentEdge) {
        if (currentEdge->getDestination() == nodeValue) {
          if (prevEdge) {
            prevEdge->setNext(currentEdge->getNext());
          } else {
            current->setEdges(currentEdge->getNext());
          }
          delete currentEdge;
          current->decrementEdge();
          break; // Break to restart from the head of the edges
        }
        prevEdge = currentEdge;
        currentEdge = currentEdge->getNext();
      }
      current = current->getNext();
    }

    // Now delete the actual node
    nodeToDelete->deleteEdges();
    Node *previousNode = nodes;

    while (previousNode && previousNode->getNext() != nodeToDelete) {
      previousNode = previousNode->getNext();
    }

    if (previousNode) {
      previousNode->setNext(nodeToDelete->getNext());
    } else {
      nodes = nodeToDelete->getNext(); // Node to delete is the head
    }

    delete nodeToDelete;
    nodeCount--;
  }
}

bool Graph::hasNode(int nodeValue) { return findNode(nodeValue) != nullptr; }

void Graph::deleteEdge(int source, int destination) {
  Node *sourceNode = findNode(source);

  if (sourceNode) {
    Edge *temp = sourceNode->getEdges();
    Edge *prev = nullptr;

    while (temp && temp->getDestination() != destination) {
      prev = temp;
      temp = temp->getNext();
    }

    if (temp) {
      if (prev) {
        prev->setNext(temp->getNext());
      } else {
        sourceNode->setEdges(temp->getNext());
      }

      delete temp;
      sourceNode->decrementEdge();
    }
  }
}

void Graph::display() {
  Node *current = nodes;
  while (current != nullptr) {
    cout << "Node: " << current->getData() << endl;
    cout << "Edges: ";
    Edge *edge = current->getEdges();
    while (edge != nullptr) {
      cout << edge->getDestination() << " ";
      edge = edge->getNext();
    }
    cout << endl;
    current = current->getNext();
  }
}

int Graph::dijkstra(int src, int dest) {
    // Check if the source and destination nodes exist
    if (!hasNode(src) || !hasNode(dest)) {
        return -1; // Return -1 if source or destination node does not exist
    }

    // Map to store the minimum distance to each node
    unordered_map<int, int> distances;
    // Priority queue to process nodes by the shortest distance first
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // Initialize distances to "infinity" for all nodes except the source node
    Node* current = nodes;
    while (current != nullptr) {
        distances[current->getData()] = numeric_limits<int>::max();
        current = current->getNext();
    }
    distances[src] = 0;

    // Push the source node to the min-heap
    minHeap.push({0, src});

    // Dijkstra's algorithm loop
    while (!minHeap.empty()) {
        int currentDistance = minHeap.top().first;
        int currentNode = minHeap.top().second;
        minHeap.pop();

        // If we reached the destination node, return the distance
        if (currentNode == dest) {
            return currentDistance;
        }

        // Process all neighbors of the current node
        Node* node = findNode(currentNode);
        Edge* edge = node->getEdges();
        while (edge != nullptr) {
            int neighbor = edge->getDestination();
            int edgeCost = edge->getCost();

            // Calculate the new distance to this neighbor
            int newDistance = currentDistance + edgeCost;

            // If the new distance is shorter, update and push to min-heap
            if (newDistance < distances[neighbor]) {
                distances[neighbor] = newDistance;
                minHeap.push({newDistance, neighbor});
            }

            edge = edge->getNext();
        }
    }

    // If we finish the loop without finding the destination, return -1
    return -1;
}
#include "functions.h"
#include <algorithm>
#include <queue>
#include <unordered_map>

Edge::Edge(int dest, int c) : destination(dest), cost(c), next(nullptr) {}

int Edge::getDestination() const { return destination; }

int Edge::getCost() const { return cost; }

Edge *Edge::getNext() const { return next; }

void Edge::setNext(Edge *nextEdge) { next = nextEdge; }

void Edge::setDestination(int dest) { destination = dest; }

Node::Node(int val) : data(val), next(nullptr), edges(nullptr), edgeCount(0) {}

int Node::getData() const { return data; }

Node *Node::getNext() const { return next; }

Edge *Node::getEdges() const { return edges; }

void Node::setNext(Node *nextNode) { next = nextNode; }

void Node::setData(int value) { data = value; }

void Node::addEdge(int dest, int cost) {
  Edge *newEdge = new Edge(dest, cost);
  newEdge->setNext(edges);
  edges = newEdge;
  incrementEdgeCount();
}

void Node::removeEdge(int dest) {
  Edge *prev = nullptr;
  Edge *curr = edges;
  while (curr) {
    if (curr->getDestination() == dest) {
      if (prev) {
        prev->setNext(curr->getNext());
      } else {
        edges = curr->getNext();
      }
      delete curr;
      decrementEdgeCount();
      return;
    }
    prev = curr;
    curr = curr->getNext();
  }
}

Edge *Node::findEdge(int dest) const {
  Edge *current = edges;
  while (current) {
    if (current->getDestination() == dest) {
      return current;
    }
    current = current->getNext();
  }
  return nullptr;
}

int Node::getEdgeCount() const { return edgeCount; }

void Node::incrementEdgeCount() { edgeCount++; }

void Node::decrementEdgeCount() { edgeCount--; }

Graph::Graph() : nodes(nullptr), nodeCount(0) {}

Graph::~Graph() {
  // Start with the head node in the linked list of nodes
  Node *currentNode = nodes;
  // Iterate over each node in the graph
  while (currentNode) {
    // Store the current node to delete later
    Node *toDelete = currentNode;
    // Move to the next node in the list
    currentNode = currentNode->getNext();

    // Get the head edge in the linked list of edges for the current node
    Edge *currentEdge = toDelete->getEdges();
    // Iterate over each edge connected to the current node
    while (currentEdge) {
      // Store the current edge to delete later
      Edge *edgeToDelete = currentEdge;
      // Move to the next edge in the list
      currentEdge = currentEdge->getNext();
      // Delete the stored edge
      delete edgeToDelete;
    }
    // Delete the stored node
    delete toDelete;
  }
}

// Function to add a node to the graph
void Graph::addNode(int nodeValue) {
  // Check if a node with the given value already exists
  if (findNode(nodeValue))
    return; // If it exists, do nothing and return

  // Create a new node with the given value
  Node *newNode = new Node(nodeValue);
  // Insert the new node at the beginning of the linked list of nodes
  newNode->setNext(nodes);
  // Update the head of the list to the new node
  nodes = newNode;
  // Increment the count of nodes in the graph
  nodeCount++;
}

void Graph::addEdge(int source, int destination, int cost) {
  Node *srcNode = findNode(source);
  Node *destNode = findNode(destination);
  if (!srcNode || !destNode)
    return;

  Edge *existingEdge = srcNode->findEdge(destination);
  if (!existingEdge) {
    srcNode->addEdge(destination, cost);
  }
}

Node *Graph::findNode(int value) const {
  Node *current = nodes;
  while (current) {
    if (current->getData() == value) {
      return current;
    }
    current = current->getNext();
  }
  return nullptr;
}

int Graph::getEdgeCountForNode(int nodeValue) {
  Node *node = findNode(nodeValue);
  if (!node)
    return -1; // Node does not exist
  return node->getEdgeCount();
}

int Graph::getNodeCount() { return nodeCount; }

void Graph::updateNode(int oldValue, int newValue) {
  Node *node = findNode(oldValue);
  if (!node || hasNode(newValue)) {
    return; // Node doesn't exist or newValue already exists
  }

  // Update the value of the node
  node->setData(newValue);

  // Update all edges pointing to oldValue to point to newValue
  Node *currentNode = nodes;
  while (currentNode) {
    Edge *edge = currentNode->getEdges();
    while (edge) {
      if (edge->getDestination() == oldValue) {
        edge->setDestination(newValue); // Update the destination of the edge
      }
      edge = edge->getNext();
    }
    currentNode = currentNode->getNext();
  }
}

void Graph::deleteNode(int nodeValue) {
  Node *node = findNode(nodeValue);
  if (!node)
    return; // Node doesn't exist

  // Remove the node from the graph
  Node *prevNode = nullptr;
  Node *currentNode = nodes;
  while (currentNode) {
    if (currentNode == node) {
      if (prevNode) {
        prevNode->setNext(currentNode->getNext());
      } else {
        nodes = currentNode->getNext();
      }
      break;
    }
    prevNode = currentNode;
    currentNode = currentNode->getNext();
  }

  // Delete all edges connected to the node
  Edge *edge = node->getEdges();
  while (edge) {
    Edge *temp = edge;
    edge = edge->getNext();
    delete temp;
  }

  delete node;
  nodeCount--;

  // Remove all edges that point to this node
  currentNode = nodes;
  while (currentNode) {
    currentNode->removeEdge(nodeValue);
    currentNode = currentNode->getNext();
  }
}

bool Graph::hasNode(int nodeValue) { return findNode(nodeValue) != nullptr; }

void Graph::deleteEdge(int source, int destination) {
  Node *sourceNode = findNode(source);
  if (!sourceNode)
    return; // Source node doesn't exist

  sourceNode->removeEdge(destination); // Remove edge from source to destination
}

void Graph::display() {
  Node *currentNode = nodes;
  while (currentNode) {
    cout << "Node " << currentNode->getData() << " has edges: ";
    Edge *currentEdge = currentNode->getEdges();
    while (currentEdge) {
      cout << "(" << currentEdge->getDestination() << ", "
           << currentEdge->getCost() << ") ";
      currentEdge = currentEdge->getNext();
    }
    cout << endl;
    currentNode = currentNode->getNext();
  }
}

vector<int> Graph::reconstructPath(const unordered_map<int, int> &cameFrom,
                                   int source, int destination) const {
  // Start at the destination node and work our way backwards to the source
  // node
  int current = destination;

  // Create a vector to hold the nodes in the shortest path
  vector<int> path;

  // Loop until we reach the source node
  while (current != source) {
    // Add the current node to the path vector
    path.push_back(current);

    // Move to the predecessor of the current node
    current = cameFrom.at(current);
  }

  // Add the source node to the path vector
  path.push_back(source);

  // Reverse the path vector so that it's in the correct order
  reverse(path.begin(), path.end());

  // Return the completed path vector
  return path;
}

Edge *Graph::aStarSearch(int source, int destination) {
  // Start the search from the source node, trying to find the shortest path
  // to the destination node
  cout << "Running A* search from " << source << " to " << destination << endl;

  // If either the source or destination node doesn't exist, fail the search
  if (!findNode(source) || !findNode(destination)) {
    cout << "Source or destination node not found." << endl;
    return nullptr;
  }

  // Maps to keep track of the shortest path to each node
  unordered_map<int, int> gScore;   // The shortest distance from the source to
                                    // this node
  unordered_map<int, int> fScore;   // The estimated shortest distance from the
                                    // source to this node to the destination
  unordered_map<int, int> cameFrom; // The previous node in the shortest path
                                    // to this node

  // The heuristic function to estimate the distance from a node to the
  // destination. In this case, we're using a very simple heuristic that just
  // returns 0
  auto heuristic = [](int a, int b) { return 0; };

  // Initialize the source node with a g score of 0 and an f score of the
  // heuristic
  gScore[source] = 0;
  fScore[source] = heuristic(source, destination);

  // A priority queue to keep track of the nodes we need to explore, sorted by
  // their f score
  using NodeCost = pair<int, int>;
  priority_queue<NodeCost, vector<NodeCost>, greater<NodeCost>> openSet;
  openSet.emplace(fScore[source], source);

  // While there are still nodes to explore
  while (!openSet.empty()) {
    // Get the node with the lowest f score
    int current = openSet.top().second;
    openSet.pop();
    cout << "Exploring node " << current << endl;

    // If we've reached the destination node, we can stop the search
    if (current == destination) {
      cout << "Destination reached." << endl;

      // Reconstruct the path from the source to the destination
      vector<int> pathNodes = reconstructPath(cameFrom, source, destination);
      cout << "Path nodes: ";
      for (int node : pathNodes) {
        cout << node << " ";
      }
      cout << endl;
      Edge *path = nullptr;     // Initialize path to nullptr
      Edge *lastEdge = nullptr; // Pointer to keep track of the last edge added

      // Build the path from the nodes in the pathNodes vector
      for (size_t i = 1; i < pathNodes.size(); ++i) {
        Edge *newEdge = new Edge(pathNodes[i], gScore[pathNodes[i]] -
                                                   gScore[pathNodes[i - 1]]);
        cout << "Adding edge " << pathNodes[i - 1] << " -> " << pathNodes[i]
             << " with cost " << gScore[pathNodes[i]] - gScore[pathNodes[i - 1]]
             << endl;

        if (path == nullptr) {
          // If this is the first edge, initialize the path
          path = newEdge;
        } else {
          // If there are already edges in the path, link the new edge
          lastEdge->setNext(newEdge);
        }

        // Update lastEdge to be the new edge
        lastEdge = newEdge;
      }
      return path;
    }

    // Get the node we're currently exploring
    Node *currentNode = findNode(current);

    // Explore all of its neighbors
    for (Edge *edge = currentNode->getEdges(); edge; edge = edge->getNext()) {
      int neighbor = edge->getDestination();
      int tentativeGScore = gScore[current] + edge->getCost();

      // If we haven't seen this neighbor before, or if we've found a shorter
      // path to it
      if (!gScore.count(neighbor) || tentativeGScore < gScore[neighbor]) {
        cameFrom[neighbor] = current;
        gScore[neighbor] = tentativeGScore;
        fScore[neighbor] = gScore[neighbor] + heuristic(neighbor, destination);
        openSet.emplace(fScore[neighbor], neighbor);
        cout << "Updating node " << neighbor << "'s g score to "
             << gScore[neighbor] << endl;
      }
    }
  }

  // If we reach here, that means the search failed
  cout << "Search failed." << endl;
  return nullptr;
}

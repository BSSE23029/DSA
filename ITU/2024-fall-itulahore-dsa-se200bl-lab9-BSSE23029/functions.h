#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

using namespace std;

class Edge {
  int destination;
  int cost;
  Edge *next;

public:
  Edge(int dest, int c) {
    destination = dest;
    cost = c;
    next = nullptr;
  }

  int getDestination() { return destination; }

  int getCost() { return cost; }

  Edge *getNext() { return next; }

  void setNext(Edge *nextEdge) { next = nextEdge; }

  void setDestination(int dest) { destination = dest; }
};

class Node {
  int data;
  Node *next;
  Edge *edges;
  int edgeCount;

public:
  Node(int val) {
    data = val;
    next = nullptr;
    edges = nullptr;
    edgeCount = 0;
  }

  int getData() { return data; }

  Node *getNext() { return next; }

  Edge *getEdges() { return edges; }

  int getEdgeCount() { return edgeCount; }

  void setNext(Node *nextNode) { next = nextNode; }

  void setEdges(Edge *edgeList) {
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

  void setData(int value) { data = value; }

  void incrementEdge() { edgeCount++; }

  void decrementEdge() { edgeCount--; }

  void deleteEdges() {
    Edge *currentEdge = edges;
    while (currentEdge != nullptr) {
      Edge *nextEdge = currentEdge->getNext();
      delete currentEdge;
      currentEdge = nextEdge;
    }
    edges = nullptr;
    edgeCount = 0;
  }
};

class Graph {
  Node *nodes;
  int nodeCount;

public:
  Graph() {
    nodes = nullptr;
    nodeCount = 0;
  }

  ~Graph() { delete[] nodes; }

  Node *findNode(int sourceValue) {
    Node *current = nodes;
    while (current != nullptr) {
      if (current->getData() == sourceValue) {
        return current;
      }
      current = current->getNext();
    }
    return nullptr;
  }

  void addNode(int nodeValue) {
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

  void addEdge(int source, int destination, int cost) {

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

  int getEdgeCost(int source, int destination) {
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

  int getEdgeCountForNode(int nodeValue) {
    Node *node = findNode(nodeValue);

    if (node) {
      return node->getEdgeCount();
    }
    return -1; // Node not found
  }

  int getNodeCount() { return nodeCount; }

  void updateNode(int oldValue, int newValue) {

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

  void deleteNode(int nodeValue) {
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

  bool hasNode(int nodeValue) { return findNode(nodeValue) != nullptr; }

  void deleteEdge(int source, int destination) {
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

  void display() {
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
  
};

#endif

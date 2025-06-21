#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <limits>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Edge {
private:
  int destination;
  int cost;
  Edge *next;

public:
  Edge(int dest, int c);
  int getDestination() const;
  int getCost() const;
  Edge *getNext() const;
  void setNext(Edge *nextEdge);
  void setDestination(int dest);
};

class Node {
private:
  int data;
  Node *next;
  Edge *edges;
  int edgeCount;

public:
  Node(int val);
  int getData() const;
  Node *getNext() const;
  Edge *getEdges() const;
  void setNext(Node *nextNode);
  void setData(int value);
  void addEdge(int dest, int cost);
  void removeEdge(int dest);
  Edge *findEdge(int dest) const;
  int getEdgeCount() const;
  void incrementEdgeCount();
  void decrementEdgeCount();
};

class Graph {
private:
  Node *nodes;
  int nodeCount;

public:
  Graph();
  ~Graph();
  void addNode(int nodeValue);
  void addEdge(int source, int destination, int cost);
  void deleteNode(int nodeValue);
  int getEdgeCountForNode(int nodeValue);
  int getNodeCount();
  void updateNode(int oldValue, int newValue);
  bool hasNode(int nodeValue);
  void deleteEdge(int source, int destination);
  void display();
  Node *findNode(int value) const;
  vector<int> reconstructPath(const unordered_map<int, int> &cameFrom,
                              int source, int destination) const;
  Edge *aStarSearch(int source, int destination);
};

#endif

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

#include <queue>
#include <unordered_map>
#include <vector>
#include <limits>

using namespace std;

class Edge {
  int destination;
  int cost;
  Edge *next;

public:

  Edge(int dest, int c);

  int getDestination();

  int getCost();

  Edge *getNext();

  void setNext(Edge *nextEdge);

  void setDestination(int dest);

};

class Node {
  int data;
  Node *next;
  Edge *edges;
  int edgeCount;

public:

  Node(int val);

  int getData();

  Node *getNext();

  Edge *getEdges();

  int getEdgeCount();

  void setNext(Node *nextNode);

  void setEdges(Edge *edgeList);

  void setData(int value);

  void incrementEdge();

  void decrementEdge();

  void deleteEdges();

};

class Graph {
  Node *nodes;
  int nodeCount;

public:

  Graph();

  ~Graph();

  Node *findNode(int sourceValue);

  void addNode(int nodeValue);

  void addEdge(int source, int destination, int cost);

  int getEdgeCost(int source, int destination);

  int getEdgeCountForNode(int nodeValue);

  int getNodeCount();

  void updateNode(int oldValue, int newValue);

  void deleteNode(int nodeValue);

  bool hasNode(int nodeValue);

  void deleteEdge(int source, int destination);

  void display();

  int dijkstra(int src, int dest);
  
};

#endif

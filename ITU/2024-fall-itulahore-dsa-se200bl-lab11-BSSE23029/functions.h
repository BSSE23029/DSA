#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

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

  void setCost(int c);

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

  void incrementEdgeCount();

  void decrementEdgeCount();

};

class Graph {

  Node *nodes;
  int nodeCount;

public:
  
  Graph();

  ~Graph();

  void addNode(int nodeValue);

  Node *getNode(int src);

  void addEdge(int source, int destination, int cost);

  int getEdgeCost(int source, int destination);

  int getEdgeCountForNode(int nodeValue);

  int getNodeCount();

  void updateNode(int oldValue, int newValue);

  void deleteNode(int nodeValue);

  bool hasNode(int nodeValue);

  void deleteEdge(int source, int destination);

  void display();

  Node *getNodes();

};

class MinHeap {

  Edge **heap;
  int heapSIze;
  int capacity;

public:
  
  MinHeap(int capacity);

  bool isEmpty();

  void insert(Edge *edge);

  Edge *extractMin();

  void heapify(int index);

  void swap(int i, int j);

};

class PrimMST {

  Graph *graph;
  bool *inMST;
  int mstCost;

public:

  PrimMST(Graph *graph);

  void runPrim(int startNode);

  void addEdgesToHeap(int node, MinHeap &heap);

  int getMSTCost();

  bool isNodeInMST(int node);

};

#endif

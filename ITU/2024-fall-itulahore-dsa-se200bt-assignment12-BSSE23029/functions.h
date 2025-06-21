#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
private:
    int source;
    int destination;
    int cost;
    Edge* next;

public:
    Edge(int src, int dest, int c);
    int getDestination() const;
    int getSource() const;
    int getCost() const;
    Edge* getNext() const;
    void setNext(Edge* nextEdge);
};

class Node {
private:
    int data;
    Node* next;
    Edge* edges;
    int edgeCount;

public:
    Node(int val);
    int getData() const;
    Node* getNext() const;
    Edge* getEdges() const;
    int getEdgeCount() const;
    void setNext(Node* nextNode);
    void setEdges(Edge* edge);
    void incrementEdgeCount();
};

class UnionFind {
private:
     vector<int> parent;
     vector<int> rank;

public:
    UnionFind(int n);
    int find(int x);
    void unionSets(int x, int y);
};

class Graph {
private:
    Node* nodes;
    int nodeCount;
    Edge* mstEdges;

public:
    Graph();
    ~Graph();
    void addNode(int nodeValue);
    void addEdge(int src, int dest, int cost);
    void kruskalMST();
    Edge* sortEdges();
    Edge* getMSTEdges();
    int getMSTWeight();
};




#endif // FUNCTIONS_H
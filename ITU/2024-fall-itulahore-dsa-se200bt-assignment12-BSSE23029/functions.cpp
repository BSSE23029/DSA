#include "functions.h"

// Edge Class Implementation
Edge::Edge(int src, int dest, int c)
    : source(src), destination(dest), cost(c), next(nullptr) {}

int Edge::getDestination() const { return destination; }
int Edge::getSource() const { return source; }
int Edge::getCost() const { return cost; }
Edge *Edge::getNext() const { return next; }
void Edge::setNext(Edge *nextEdge) { next = nextEdge; }

// Node Class Implementation
Node::Node(int val) : data(val), next(nullptr), edges(nullptr), edgeCount(0) {}

int Node::getData() const { return data; }
Node *Node::getNext() const { return next; }
Edge *Node::getEdges() const { return edges; }
int Node::getEdgeCount() const { return edgeCount; }
void Node::setNext(Node *nextNode) { next = nextNode; }
void Node::setEdges(Edge *edge) { edges = edge; }
void Node::incrementEdgeCount() { edgeCount++; }

// UnionFind Class Implementation
UnionFind::UnionFind(int n) : parent(n), rank(n, 0) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

// Path compression to optimize the find operation
int UnionFind::find(int x) {
    // If x is not the root, find the root and set the parent of x to the root
    if (x != parent[x]) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void UnionFind::unionSets(int x, int y) {
    // Find the roots of x and y
    x = find(x);
    y = find(y);
    if (x != y) {
        // Union the two sets based on rank
        if (rank[x] < rank[y]) {
            parent[x] = y;  // Make y the root
        } else if (rank[x] > rank[y]) {
            parent[y] = x;  // Make x the root
        } else {
            parent[y] = x;  // Make x the root
            rank[x]++;      // Increment rank of x
        }
    }
}

// Graph Class Implementation
Graph::Graph() : nodes(nullptr), nodeCount(0), mstEdges(nullptr) {}

Graph::~Graph() {
    // Destructor logic to free memory
    while (nodes) {
        Node* temp = nodes;
        nodes = nodes->getNext();
        delete temp;  // Free node memory
    }
}

void Graph::addNode(int nodeValue) {
    Node *newNode = new Node(nodeValue);
    newNode->setNext(nodes);
    nodes = newNode;
    nodeCount++;
}


void Graph::addEdge(int src, int dest, int cost) {
    // Find the source node
    Node *srcNode = nodes;
    while (srcNode && srcNode->getData() != src) {
        srcNode = srcNode->getNext();
    }

    // Find the destination node
    Node *destNode = nodes;
    while (destNode && destNode->getData() != dest) {
        destNode = destNode->getNext();
    }

    // If either node does not exist, throw an error
    if (!srcNode || !destNode) {
        cerr << "Error: Source or destination node does not exist.\n";
        return;
    }

    // Create a new edge
    Edge *newEdge = new Edge(src, dest, cost);

    // Add edge to source node's list of edges
    newEdge->setNext(srcNode->getEdges());
    srcNode->setEdges(newEdge);

    // Increment the source node's edge count
    srcNode->incrementEdgeCount();
}

class SimpleEdge {
public:
    int source;
    int destination;
    int cost;
    SimpleEdge* next; // Pointer to the next edge

    SimpleEdge(int src, int dest, int c) : source(src), destination(dest), cost(c), next(nullptr) {}
};

void Graph::kruskalMST() {
    // Step 1: Gather all edges into a linked list
    SimpleEdge* edgeList = nullptr; // Head of the linked list of edges
    Node* currentNode = nodes;
    while (currentNode) {
        Edge* currentEdge = currentNode->getEdges();
        while (currentEdge) {
            // Create a new edge and add it to the linked list
            SimpleEdge* newEdge = new SimpleEdge(currentEdge->getSource(), currentEdge->getDestination(), currentEdge->getCost());
            newEdge->next = edgeList; // Insert at the head of the list
            edgeList = newEdge; // Move head to the new edge
            currentEdge = currentEdge->getNext();
        }
        currentNode = currentNode->getNext();
    }

    // Step 2: Sort edges by cost using Insertion Sort
    SimpleEdge* sortedEdgeList = nullptr; // Sorted linked list
    SimpleEdge* current = edgeList;

    while (current) {
        SimpleEdge* next = current->next; // Store next edge
        // Insert current into sortedEdgeList
        if (!sortedEdgeList || sortedEdgeList->cost > current->cost) {
            current->next = sortedEdgeList;
            sortedEdgeList = current; // Move head to current
        } else {
            SimpleEdge* search = sortedEdgeList;
            while (search->next && search->next->cost <= current->cost) {
                search = search->next;
            }
            current->next = search->next; // Link current to the next
            search->next = current; // Insert current into the sorted list
        }
        current = next; // Move to the next edge
    }

    // Step 3: Initialize Union-Find
    UnionFind uf(nodeCount);

    // Step 4: Build the MST
    mstEdges = nullptr;
    Edge* lastMSTEdge = nullptr;

    current = sortedEdgeList; // Reset current to the sorted edge list
    while (current) {
        int srcParent = uf.find(current->source);
        int destParent = uf.find(current->destination);

        // If adding this edge doesn't form a cycle, include it in the MST
        if (srcParent != destParent) {
            uf.unionSets(srcParent, destParent);

            // Create a new MST edge
            Edge* newEdge = new Edge(current->source, current->destination, current->cost);
            if (!mstEdges) {
                mstEdges = newEdge; // First edge in the MST
                lastMSTEdge = newEdge;
            } else {
                lastMSTEdge->setNext(newEdge);
                lastMSTEdge = newEdge;
            }
        }
        current = current->next; // Move to the next edge
    }

    // Ensure the MST is in the required order
    //sortEdges();
}



Edge* Graph::sortEdges() {
    if (!mstEdges || !mstEdges->getNext()) return mstEdges;

    Edge* sortedHead = nullptr; // This will be the head of the new sorted list

    Edge* current = mstEdges; // Start with the head of the original list
    while (current) {
        Edge* next = current->getNext(); // Store the next node
        // Insert current into the sorted linked list
        if (!sortedHead || current->getCost() < sortedHead->getCost()) {
            // Insert at the head if sortedHead is null or current's cost is less than sortedHead's cost
            current->setNext(sortedHead);
            sortedHead = current;
        } else {
            // Find the correct position to insert current
            Edge* temp = sortedHead;
            while (temp->getNext() && temp->getNext()->getCost() < current->getCost()) {
                temp = temp->getNext();
            }
            // Insert current after temp
            current->setNext(temp->getNext());
            temp->setNext(current);
        }
        current = next; // Move to the next edge in the original list
    }

    return sortedHead; // Return the head of the sorted linked list
}

Edge* Graph::getMSTEdges() {
    return mstEdges; // Return the edges of the MST
}

int Graph::getMSTWeight() {
    int totalWeight = 0;
    Edge* currentEdge = getMSTEdges();
    while (currentEdge) {
        totalWeight += currentEdge->getCost();
        currentEdge = currentEdge->getNext();
    }
    return totalWeight;
}
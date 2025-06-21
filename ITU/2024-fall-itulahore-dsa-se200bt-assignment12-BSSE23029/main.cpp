#include "functions.h"
#include <iostream>

#include "functions.h"
#include <iostream>

using namespace std;

int main() {
    Graph graph;
    int choice = -1; // Initialize choice to enter the loop

    while (choice != 0) {
        // Display menu
        cout << "Menu:\n";
        cout << "1. Add Node\n";
        cout << "2. Add Edge\n";
        cout << "3. Calculate MST using Kruskal's Algorithm\n";
        cout << "4. Display MST\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Add a node
            int nodeId;
            cout << "Enter node ID: ";
            cin >> nodeId;
            graph.addNode(nodeId);
            cout << "Node " << nodeId << " added.\n";
            break;
        }
        case 2: {
            // Add an edge
            int src, dest, cost;
            cout << "Enter source node ID: ";
            cin >> src;
            cout << "Enter destination node ID: ";
            cin >> dest;
            cout << "Enter edge cost: ";
            cin >> cost;
            graph.addEdge(src, dest, cost);
            cout << "Edge from " << src << " to " << dest << " with cost " << cost << " added.\n";
            break;
        }
        case 3: {
            // Calculate MST
            graph.kruskalMST();
            cout << "MST calculated using Kruskal's Algorithm.\n";
            break;
        }
        case 4: {
            // Display MST
            Edge* mstEdges = graph.getMSTEdges();
            cout << "Edges in the Minimum Spanning Tree:\n";
            while (mstEdges) {
                cout << "Source: " << mstEdges->getSource()
                     << ", Destination: " << mstEdges->getDestination()
                     << ", Cost: " << mstEdges->getCost() << "\n";
                mstEdges = mstEdges->getNext();
            }
            cout << "Total weight of MST: " << graph.getMSTWeight() << "\n";
            break;
        }
        case 0: {
            // Exit
            cout << "Exiting...\n";
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

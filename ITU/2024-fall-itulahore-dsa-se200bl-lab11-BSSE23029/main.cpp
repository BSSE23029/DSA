#include "functions.h"

int main() {

  cout << endl << endl;

  Graph graph;
  int choice, node1, node2, cost, startNode, primMSTCost;
  primMSTCost = 0;

  while (choice != 0) {
    cout << endl << endl;
    cout << "Menu:\n";
    cout << "1. Add Node\n";
    cout << "2. Add Edge\n";
    cout << "3. Delete Node\n";
    cout << "4. Delete Edge\n";
    cout << "5. Run Prim's Algorithm\n";
    cout << "6. Display MST Cost\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
    cin >> choice;
    cout << endl << endl;

    switch (choice) {
    case 1: // Add Node
    {
      cout << "Enter node value: ";
      cin >> node1;
      graph.addNode(node1);
      cout << "Node " << node1 << " added.\n";
      break;
    }

    case 2: // Add Edge
    {
      cout << "Enter source node, destination node, and cost: \n";
      cout << "Enter source node: ";
      cin >> node1;
      cout << "Enter destination node: ";
      cin >> node2;
      cout << "Enter cost: ";
      cin >> cost;
      graph.addEdge(node1, node2, cost);
      cout << "Edge added from " << node1 << " to " << node2 << " with cost "
           << cost << ".\n";
      break;
    }

    case 3: // Delete Node
    {
      cout << "Enter node value to delete: ";
      cin >> node1;
      graph.deleteNode(node1);
      cout << "Node " << node1 << " deleted.\n";
      break;
    }

    case 4: // Delete Edge
    {
      cout << "Enter source node and destination node to delete the edge: \n";
      cout << "Enter source node: ";
      cin >> node1;
      cout << "Enter destination node: ";
      cin >> node2;
      graph.deleteEdge(node1, node2);
      cout << "Edge from " << node1 << " to " << node2 << " deleted.\n";
      break;
    }

    case 5: // Run Prim's Algorithm
    {
      cout << "Enter starting node for Prim's Algorithm: ";
      cin >> startNode;
      PrimMST primMST(&graph);
      primMST.runPrim(startNode);
      primMSTCost = primMST.getMSTCost();
      cout << "Prim's algorithm executed. MST cost calculated.\n";
      break;
    }

    case 6: // Display MST Cost
    {
      cout << "MST Cost: " << primMSTCost << endl;
      break;
    }

    case 0: // Exit
    {
      cout << "Exiting program.\n";
      break;
    }

    default: {
      cout << "Invalid choice. Please try again.\n";
    }
    }
    cout << endl << endl;
  }

  cout << endl << endl;

  return 0;
}

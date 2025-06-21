#include "functions.h"

using namespace std;

void displayMenu() {
  cout << "\nGraph Menu:\n";
  cout << "1. Add Node\n";
  cout << "2. Add Edge\n";
  cout << "3. Delete Node\n";
  cout << "4. Delete Edge\n";
  cout << "5. Update Node\n";
  cout << "6. Get Edge Cost\n";
  cout << "7. Display Edge Count for Node\n";
  cout << "8. Display Graph\n";
  cout << "0. Exit\n";
  cout << "Choose an option: ";
}

int main() {
  Graph graph;
  int choice, node1, node2, cost;

  while (choice != 0) {
    displayMenu();
    cin >> choice;

    switch (choice) {
    case 1: {
      cout << "Enter node value to add: ";
      cin >> node1;
      graph.addNode(node1);
      cout << "Node " << node1 << " added.\n";
      break;
    }

    case 2: {
      cout << "Enter source node: ";
      cin >> node1;
      cout << "Enter destination node: ";
      cin >> node2;
      cout << "Enter cost: ";
      cin >> cost;
      graph.addEdge(node1, node2, cost);
      cout << "Edge from " << node1 << " to " << node2 << " with cost " << cost
           << " added.\n";
      break;
    }

    case 3: {
      cout << "Enter node value to delete: ";
      cin >> node1;
      graph.deleteNode(node1);
      cout << "Node " << node1 << " deleted.\n";
      break;
    }
    case 4: {
      cout << "Enter source node to delete edge: ";
      cin >> node1;
      cout << "Enter destination node to delete edge: ";
      cin >> node2;
      graph.deleteEdge(node1, node2);
      cout << "Edge from " << node1 << " to " << node2 << " deleted.\n";
      break;
    }
    case 5: {
      cout << "Enter old node value: ";
      cin >> node1;
      cout << "Enter new node value: ";
      cin >> node2;
      graph.updateNode(node1, node2);
      cout << "Node " << node1 << " updated to " << node2 << ".\n";
      break;
    }

    case 6: {
      cout << "Enter source node to get edge cost: ";
      cin >> node1;
      cout << "Enter destination node to get edge cost: ";
      cin >> node2;
      cost = graph.getEdgeCost(node1, node2);
      if (cost == -1) {
        cout << "No edge exists from " << node1 << " to " << node2 << ".\n";
      } else {
        cout << "Cost of edge from " << node1 << " to " << node2 << " is "
             << cost << ".\n";
      }
      break;
    }

    case 7: {
      cout << "Enter node value to get edge count: ";
      cin >> node1;
      int edgeCount = graph.getEdgeCountForNode(node1);
      if (edgeCount == -1) {
        cout << "Node " << node1 << " does not exist.\n";
      } else {
        cout << "Node " << node1 << " has " << edgeCount << " edges.\n";
      }
      break;
    }

    case 8: {
      graph.display();
      cout << endl;
      break;
    }

    case 0: {
      cout << "Exiting program.\n";
    }

    default: {
      cout << "Invalid choice. Please try again.\n";
      break;
    }
    }
  }

  return 0;
}
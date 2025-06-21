#include "functions.h"

int main() {
  Graph graph;
  int choice;
  int node1, node2, cost;

  while (choice != 0) {
    cout << "Menu:\n";
    cout << "1. Add Node\n";
    cout << "2. Add Edge\n";
    cout << "3. Perform A* Search\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
    cin >> choice;

    switch (choice) {
    case 1: {
      cout << "Enter node value: ";
      cin >> node1;
      graph.addNode(node1);
      cout << "Node " << node1 << " added.\n";
      break;
    }

    case 2: {
      cout << "Enter first node value: ";
      cin >> node1;
      cout << "Enter second node value: ";
      cin >> node2;
      cout << "Enter edge cost: ";
      cin >> cost;
      graph.addEdge(node1, node2, cost);
      cout << "Edge from " << node1 << " to " << node2 << " with cost " << cost
           << " added.\n";
      break;
    }

    case 3: {
      cout << "Enter start node: ";
      cin >> node1;
      cout << "Enter end node: ";
      cin >> node2;
      Edge *path = graph.aStarSearch(node1, node2);

      if (path) {
        int totalCost = 0;
        cout << "Path: ";
        while (path != nullptr) {
          totalCost += path->getCost();
          path = path->getNext();
        }
        cout << "\nTotal Cost: " << totalCost << endl;
      } else {
        cout << "No path found from " << node1 << " to " << node2 << ".\n";
      }
      break;
    }

    case 0: {
      cout << "Exiting...\n";
      break;
    }

    default:
      cout << "Invalid option. Please try again.\n";
      break;
    }
  }

  return 0;
}
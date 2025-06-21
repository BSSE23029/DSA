#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h"
#include <iostream>
#include <sstream>
using namespace std;

TEST_CASE("Node and edge count validation", "[Graph][addNode][addEdge]") {
    Graph graph;
    graph.addNode(1);
    graph.addNode(2);
    REQUIRE(graph.getNodeCount() == 2);

    graph.addEdge(1, 2, 10);
    REQUIRE(graph.getEdgeCountForNode(1) == 1);  // Access edgeCount using new method
    REQUIRE(graph.getEdgeCost(1, 2) == 10);
}

TEST_CASE("Edge existence verification", "[Graph][addEdge]") {
    Graph graph;
    graph.addNode(1);
    graph.addNode(2);
    graph.addEdge(1, 2, 10);
    REQUIRE(graph.getEdgeCost(1, 2) == 10);
    REQUIRE(graph.getEdgeCost(2, 1) == -1); // Edge should not exist in reverse
}

TEST_CASE("Avoid duplicate edges", "[Graph][addEdge]") {
    Graph graph;
    graph.addNode(1);
    graph.addNode(2);
    graph.addEdge(1, 2, 10);
    graph.addEdge(1, 2, 15);  // Should not add a duplicate edge

    REQUIRE(graph.getEdgeCost(1, 2) == 10);
    REQUIRE(graph.getEdgeCountForNode(1) == 1);
}



TEST_CASE("Delete Node functionality", "[Graph][deleteNode]") {
    Graph graph;
    
    // Add nodes and edges
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addEdge(1, 2, 10);
    graph.addEdge(2, 3, 20);
    
    // Verify initial state
    REQUIRE(graph.hasNode(1));
    REQUIRE(graph.hasNode(2));
    REQUIRE(graph.hasNode(3));
    REQUIRE(graph.getEdgeCountForNode(1) == 1);
    REQUIRE(graph.getEdgeCost(1, 2) == 10);
    REQUIRE(graph.getEdgeCost(2, 3) == 20);

    // Delete node 2 and verify changes
    graph.deleteNode(2);
    REQUIRE(!graph.hasNode(2));                 // Node 2 should no longer exist
    REQUIRE(graph.getEdgeCost(1, 2) == -1);     // Edge from 1 to 2 should be removed
    REQUIRE(graph.getEdgeCountForNode(1) == 0); // Node 1 should have no edges after deletion
    REQUIRE(graph.getEdgeCost(2, 3) == -1);     // Edge from 2 to 3 should be removed
    REQUIRE(graph.hasNode(1));                  // Node 1 should still exist
    REQUIRE(graph.hasNode(3));                  // Node 3 should still exist
}

TEST_CASE("Delete Edge functionality", "[Graph][deleteEdge]") {
    Graph graph;
    
    // Add nodes and edges
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addEdge(1, 2, 10);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 20);

    // Verify initial state
    REQUIRE(graph.getEdgeCountForNode(1) == 2); // Node 1 has two edges
    REQUIRE(graph.getEdgeCost(1, 2) == 10);
    REQUIRE(graph.getEdgeCost(1, 3) == 15);

    // Delete the edge between nodes 1 and 2
    graph.deleteEdge(1, 2);
    REQUIRE(graph.getEdgeCost(1, 2) == -1);     // Edge from 1 to 2 should no longer exist
    REQUIRE(graph.getEdgeCountForNode(1) == 1); // Node 1 should have one edge left

    // Ensure other edges are unaffected
    REQUIRE(graph.getEdgeCost(1, 3) == 15);     // Edge from 1 to 3 should still exist
    REQUIRE(graph.getEdgeCost(2, 3) == 20);     // Edge from 2 to 3 should still exist
}

TEST_CASE("Update Node functionality", "[Graph][updateNode]") {
    Graph graph;
    
    // Add nodes and edges
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addEdge(1, 2, 10);
    graph.addEdge(2, 3, 20);

    // Verify initial state
    REQUIRE(graph.getEdgeCost(1, 2) == 10);
    REQUIRE(graph.getEdgeCost(2, 3) == 20);

    // Update node 2 to node 4 and verify changes
    graph.updateNode(2, 4);
    REQUIRE(!graph.hasNode(2));                  // Node 2 should no longer exist
    REQUIRE(graph.hasNode(4));                   // Node 4 should exist
    REQUIRE(graph.getEdgeCost(1, 4) == 10);      // Edge from 1 to 4 should be updated
    REQUIRE(graph.getEdgeCost(4, 3) == 20);      // Edge from 4 to 3 should be updated
}

TEST_CASE("Update Node with existing destination node", "[Graph][updateNode]") {
    Graph graph;
    
    // Add nodes and edges
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addEdge(1, 2, 10);
    graph.addEdge(2, 3, 20);

    // Try to update node 2 to 3 (which already exists)
    graph.updateNode(2, 3);
    
    // Ensure the graph structure has not been corrupted
    REQUIRE(graph.hasNode(1));
    REQUIRE(graph.hasNode(2));
    REQUIRE(graph.hasNode(3));
    REQUIRE(graph.getEdgeCost(1, 2) == 10);   // Edge from 1 to 2 should remain
    REQUIRE(graph.getEdgeCost(2, 3) == 20);   // Edge from 2 to 3 should remain
    REQUIRE(graph.getEdgeCountForNode(1) == 1);
}



TEST_CASE("Dijkstra's Algorithm - Shortest Path Calculation", "[Graph][dijkstra]") {
    Graph graph;

    // Add nodes
    for (int i = 0; i <= 8; ++i) {
        graph.addNode(i);
    }

    // Add edges
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 7, 8);
    graph.addEdge(1, 2, 8);
    graph.addEdge(1, 7, 11);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 8, 2);
    graph.addEdge(2, 5, 4);
    graph.addEdge(3, 4, 9);
    graph.addEdge(3, 5, 14);
    graph.addEdge(4, 5, 10);
    graph.addEdge(5, 6, 2);
    graph.addEdge(6, 7, 1);
    graph.addEdge(6, 8, 6);
    graph.addEdge(7, 8, 7);

    
    int shortestDistance = graph.dijkstra(0, 2);
    REQUIRE(shortestDistance == 12); 


    shortestDistance = graph.dijkstra(0, 3);
    REQUIRE(shortestDistance == 19); 


    shortestDistance = graph.dijkstra(0, 7);
    REQUIRE(shortestDistance == 8);


    shortestDistance = graph.dijkstra(0, 8);
    REQUIRE(shortestDistance == 14);
}

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h"
#include <iostream>
#include <sstream>
using namespace std;


TEST_CASE("Prim's Algorithm - Basic Test", "[Prim][MST]") {
    Graph graph;

    // Add nodes to the graph
    graph.addNode(0);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);

    // Add edges to the graph (node1, node2, cost)
    graph.addEdge(0, 1, 2); // Edge from 0 to 1 with cost 2
    graph.addEdge(0, 3, 6); // Edge from 0 to 3 with cost 6
    graph.addEdge(1, 2, 3); // Edge from 1 to 2 with cost 3
    graph.addEdge(1, 3, 8); // Edge from 1 to 3 with cost 8
    graph.addEdge(2, 3, 4); // Edge from 2 to 3 with cost 4
    graph.addEdge(3, 4, 5); // Edge from 3 to 4 with cost 5
    graph.addEdge(4, 0, 7); // Edge from 4 to 0 with cost 7

    // Create PrimMST instance and run Prim's algorithm from node 0
    PrimMST primMST(&graph);
    primMST.runPrim(0);

    // Get the total cost of the MST (which should be calculated by Prim's algorithm)
    int expectedCost = 2 + 3 + 4 + 5; // MST edges: (0, 1), (1, 2), (2, 3), (3, 4)
    int actualCost = primMST.getMSTCost();

    // Test if the MST cost is as expected
    REQUIRE(actualCost == expectedCost);

    // Test if all nodes are included in the MST (should return true for each node)
    REQUIRE(primMST.isNodeInMST(0) == true);
    REQUIRE(primMST.isNodeInMST(1) == true);
    REQUIRE(primMST.isNodeInMST(2) == true);
    REQUIRE(primMST.isNodeInMST(3) == true);
    REQUIRE(primMST.isNodeInMST(4) == true);
}

TEST_CASE("Prim's Algorithm - Test with Disconnected Graph", "[Prim][MST][Disconnected]") {
    Graph graph;

    // Add nodes to the graph
    graph.addNode(0);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);

    // Add edges to the graph (node1, node2, cost)
    graph.addEdge(0, 1, 2); // Edge from 0 to 1 with cost 2
    graph.addEdge(1, 2, 3); // Edge from 1 to 2 with cost 3

    // Create PrimMST instance and run Prim's algorithm from node 0
    PrimMST primMST(&graph);
    primMST.runPrim(0);

    // The MST should include nodes 0, 1, and 2 but not node 3, as the graph is disconnected.
    int expectedCost = 2 + 3; // MST edges: (0, 1), (1, 2)
    int actualCost = primMST.getMSTCost();

    // Test if the MST cost is as expected
    REQUIRE(actualCost == expectedCost);

    // Test if all nodes are included in the MST (should not include node 3)
    REQUIRE(primMST.isNodeInMST(0) == true);
    REQUIRE(primMST.isNodeInMST(1) == true);
    REQUIRE(primMST.isNodeInMST(2) == true);
    REQUIRE(primMST.isNodeInMST(3) == false);
}

TEST_CASE("Prim's Algorithm - Test with No Edges", "[Prim][MST][NoEdges]") {
    Graph graph;

    // Add nodes to the graph, but no edges
    graph.addNode(0);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);

    // Create PrimMST instance and run Prim's algorithm from node 0
    PrimMST primMST(&graph);
    primMST.runPrim(0);

    // The MST should include only node 0 as no other nodes are connected by edges
    int expectedCost = 0; // No edges to add
    int actualCost = primMST.getMSTCost();

    // Test if the MST cost is as expected
    REQUIRE(actualCost == expectedCost);

    // Test if only node 0 is included in the MST
    REQUIRE(primMST.isNodeInMST(0) == true);
    REQUIRE(primMST.isNodeInMST(1) == false);
    REQUIRE(primMST.isNodeInMST(2) == false);
    REQUIRE(primMST.isNodeInMST(3) == false);
}
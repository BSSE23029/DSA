#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h"
#include <iostream>
#include <sstream>
using namespace std;

TEST_CASE("Update Node with existing destination node", "[Graph][updateNode]") {
    Graph g;

    // Adding nodes
    g.addNode(0);
    g.addNode(1);
    g.addNode(2);
    g.addNode(3);
    g.addNode(4);
    g.addNode(5);
    g.addNode(6);
    g.addNode(7);
    g.addNode(8);

    // Adding edges to the graph
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 

    
    g.kruskalMST();

    Edge* edge_ptr = g.getMSTEdges();

    int total_cost = 0;

    REQUIRE(edge_ptr->getSource() == 6);
    REQUIRE(edge_ptr->getDestination() == 7);
    total_cost += edge_ptr->getCost();
    edge_ptr = edge_ptr->getNext();

    REQUIRE(edge_ptr->getSource() == 2);
    REQUIRE(edge_ptr->getDestination() == 8);
    total_cost += edge_ptr->getCost();
    edge_ptr = edge_ptr->getNext();

    REQUIRE(edge_ptr->getSource() == 5);
    REQUIRE(edge_ptr->getDestination() == 6);
    total_cost += edge_ptr->getCost();
    edge_ptr = edge_ptr->getNext();

    REQUIRE(edge_ptr->getSource() == 0);
    REQUIRE(edge_ptr->getDestination() == 1);
    total_cost += edge_ptr->getCost();
    edge_ptr = edge_ptr->getNext();

    REQUIRE(edge_ptr->getSource() == 2);
    REQUIRE(edge_ptr->getDestination() == 5);
    total_cost += edge_ptr->getCost();
    edge_ptr = edge_ptr->getNext();

    REQUIRE(edge_ptr->getSource() == 2);
    REQUIRE(edge_ptr->getDestination() == 3);
    total_cost += edge_ptr->getCost();
    edge_ptr = edge_ptr->getNext();

    REQUIRE(edge_ptr->getSource() == 0);
    REQUIRE(edge_ptr->getDestination() == 7);
    total_cost += edge_ptr->getCost();
    edge_ptr = edge_ptr->getNext();

    REQUIRE(edge_ptr->getSource() == 3);
    REQUIRE(edge_ptr->getDestination() == 4);
    total_cost += edge_ptr->getCost();
    edge_ptr = edge_ptr->getNext();

    REQUIRE(edge_ptr == nullptr);  


    REQUIRE(total_cost == 37);

    
}


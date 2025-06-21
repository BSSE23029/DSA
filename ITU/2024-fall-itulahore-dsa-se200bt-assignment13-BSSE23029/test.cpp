#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h"
#include <iostream>
#include <sstream>
using namespace std;

TEST_CASE("A* Search - Complex Path with Loops", "[Graph][aStarSearch]") {
    Graph graph;
    
    
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);
    graph.addEdge(1, 2, 10); 
    graph.addEdge(2, 3, 5);   
    graph.addEdge(3, 4, 10);   
    graph.addEdge(4, 2, 5);    
    graph.addEdge(2, 5, 2);     
    
    
    Edge* path = graph.aStarSearch(1, 5);
    
    
    REQUIRE(path != nullptr); 
    REQUIRE(path->getDestination() == 2); 
    REQUIRE(path->getNext()->getDestination() == 5);  
}


TEST_CASE("A* Search - Empty Graph", "[Graph][aStarSearch]") {
    Graph graph;
    
    Edge* path = graph.aStarSearch(1, 2);
    
    REQUIRE(path == nullptr); 
}

TEST_CASE("A* Search - Complex Path", "[Graph][aStarSearch]") {
    Graph graph;
    
    
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);
    graph.addNode(6);
    graph.addNode(7);
    
    graph.addEdge(1, 2, 4); 
    graph.addEdge(1, 3, 3);   
    
    graph.addEdge(2, 5, 12); 
    graph.addEdge(2, 6, 5);   
    
	graph.addEdge(3, 4, 7); 
    graph.addEdge(3, 5, 10);
	
	graph.addEdge(4, 5, 2);
	
	graph.addEdge(5, 7, 5); 
    graph.addEdge(6, 7, 16);   
    
    Edge* path = graph.aStarSearch(1, 7);
    
    int totalCost = 0;
    
    REQUIRE(path != nullptr);
    
	totalCost += path->getCost(); 
    REQUIRE(path->getDestination() == 3); 
    path = path->getNext();
    
    totalCost += path->getCost(); 
    REQUIRE(path->getDestination() == 4);
	path = path->getNext();
	
	totalCost += path->getCost(); 
    REQUIRE(path->getDestination() == 5);
	path = path->getNext();
	
	totalCost += path->getCost(); 
    REQUIRE(path->getDestination() == 7);    
	
	REQUIRE(totalCost == 17);
    
}




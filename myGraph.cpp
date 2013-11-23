#include <iostream>
#include <vector>
#include "myGraph.h"


void myGraph::addVertex(float x, float y){
	myGraph::Vertex n; 
	n.setX(x);  
	n.setY(y); 
	Vertices.push_back(n); 
}

void myGraph::addEdge(int OrigID, int DestID, float weight){	
	// Obtaining the size of the vector adjacencyList
	int Adjsize = Vertices[OrigID].adjacencyList.size();

	myGraph::Vertex::Data D; 	
	D.ID = DestID; 
	D.weight = weight; 

	// Set the last position with the edge data.
	Vertices[OrigID].adjacencyList[Adjsize -1] = D; 
}

void myGraph::deleteVertex(int pos){	 
	// Obtaining the size of the vector adjacencyList
	int Adjsize = Vertices[pos].adjacencyList.size();

	for(int i=0; i<Adjsize; i++){
		Vertices[pos].adjacencyList[i].ID     = -1 ;
		Vertices[pos].adjacencyList[i].weight =  0 ; 
	}
}
	
void myGraph::deleteEdge(int Vertex, int Edge){
	Vertices[Vertex].adjacencyList[Edge].ID     = -1 ;
	Vertices[Vertex].adjacencyList[Edge].weight =  0 ;  
}
	
/*vector myGraph::getNeighbors(int Vertex){
	return Vertices[Vertex].adjacencyList; 

}*/

int myGraph::getNumberVertices(){
	return Vertices.size(); 
}

int myGraph::getNumberEdges(int Vertex){
	return Vertices[Vertex].adjacencyList.size(); 
}

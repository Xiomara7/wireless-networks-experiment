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
	D.setID(DestID);  
	D.setWeight(weight); 
	
	// Set the last position with the edge data.
	Vertices[OrigID].adjacencyList.push_back(D); 
}

void myGraph::deleteVertex(int pos){	 
	// Obtaining the size of the vector adjacencyList
	int Adjsize = Vertices[pos].adjacencyList.size();

	for(int i=0; i<Adjsize; i++){
		Vertices[pos].adjacencyList[i].setID(-1); 
		Vertices[pos].adjacencyList[i].setWeight(0);
	}
}
	
void myGraph::deleteEdge(int V1, int V2){
	Vertices[V1].adjacencyList[V2].setID(-1); 
	Vertices[V1].adjacencyList[V2].setWeight(0); 
}
	
void myGraph::getNeighbors(vector <int> &neighbors, int pos){
	for(int i=0; i<Vertices[pos].adjacencyList.size(); i++){ 
		neighbors.push_back(Vertices[pos].adjacencyList[i].getID());
		//cout << Vertices[pos].adjacencyList[i].getWeight() << " "; 
	}
	//cout << endl; 
}

int myGraph::getNumberVertices(){ 
	return Vertices.size(); 
}

int myGraph::getNumberEdges(int Vertex){
	int sum = 0; 
	for(int i=0; i<Vertices.size(); i++){
		sum += Vertices[i].adjacencyList.size();
	} 
	return sum; 
}

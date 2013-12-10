#include <iostream>
#include <vector>
#include <cmath>
#include "myGraph.h"


void myGraph::addVertex(float x, float y){
	myGraph::Vertex n; 
	n.setX(x);  
	n.setY(y); 
	Vertices.push_back(n); 
}

void myGraph::addEdge(int OrigID, int DestID, float weight){	
	myGraph::Vertex::Data D1; 	
	D1.setID(DestID);  
	D1.setWeight(weight); 
	
	// Set the last position with the edge data.
	Vertices[OrigID].adjacencyList.push_back(D1); 
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
		if(Vertices[pos].adjacencyList[i].getID() != -1){
			neighbors.push_back(Vertices[pos].adjacencyList[i].getID());
		}
	}
}

int myGraph::getNumberVertices(){ 
	return Vertices.size(); 
}

int myGraph::getNumberEdges(int Vertex){
	int sum = 0; 
	for(int i=0; i<Vertices.size(); i++){
		for(int j=0; j<Vertices[i].adjacencyList.size(); j++){
			if(Vertices[i].adjacencyList[j].getID() != -1){
				sum += Vertices[i].adjacencyList.size();
			}
		}
	} 
	return sum; 
}

void myGraph::getDistance(int V1, int V2, float &dist){ 
	dist = sqrt(pow(abs(getX(V1) - getX(V2)), 2.0) 
  		      + pow(abs(getY(V1) - getY(V2)), 2.0));
	//dist = Vertices[V1].adjacencyList[V2].getWeight();
} 

void myGraph::printVectors(){
	for(int i=0; i<Vertices.size(); i++){
		for(int j=0; j<Vertices[i].adjacencyList.size(); j++){
			//cout << "Vertices: " << Vertices[i].adjacencyList[j].getWeight() << endl ; 
		}
		
	}	
}

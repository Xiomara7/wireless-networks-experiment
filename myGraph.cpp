#include <iostream>
#include <vector>
#include <cmath>
#include "myGraph.h"

/**
 * [myGraph::addVertex Add a Vertex to the graph]
 * @param x [Position X]
 * @param y [Position Y]
 */
void myGraph::addVertex(float x, float y){
	myGraph::Vertex n; 
	n.setX(x);  
	n.setY(y); 
	Vertices.push_back(n); 
}

/**
 * [myGraph::addEdge Add an edge to the graph]
 * @param OrigID [Origin vertex]
 * @param DestID [Destination vertex]
 * @param weight [Distance between nodes]
 */
void myGraph::addEdge(int OrigID, int DestID, float weight){	
	myGraph::Vertex::Data D1; 
	myGraph::Vertex::Data D2;

	D1.setID(DestID);  
	D1.setWeight(weight);

	D2.setID(OrigID);  
	D2.setWeight(weight); 
	
	// Set the last position with the edge data.
	Vertices[OrigID].adjacencyList.push_back(D1); 
	Vertices[DestID].adjacencyList.push_back(D2); 
}

/**
 * [myGraph::deleteVertex Erase a vertex from the graph]
 * @param pos [Position of the vertex to erase]
 */
void myGraph::deleteVertex(int pos){	 
	// Obtaining the size of the vector adjacencyList
	int Adjsize = Vertices[pos].adjacencyList.size();

	for(int i=0; i<Adjsize; i++){
		Vertices[pos].adjacencyList[i].setID(-1); 
		Vertices[pos].adjacencyList[i].setWeight(0);
	}
}
	
/**
 * [myGraph::deleteEdge Erase an edge from the graph]
 * @param V1 [Origin vertex]
 * @param V2 [Destination vertex]
 */
void myGraph::deleteEdge(int V1, int V2){
	Vertices[V1].adjacencyList[V2].setID(-1); 
	Vertices[V1].adjacencyList[V2].setWeight(0);
}
	
/**
 * [myGraph::getNeighbors: Put the neighbors of a vertex in a vector]
 * @param neighbors [vector of vertex neighbors]
 * @param pos       [Position of the vertex]
 */
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

/**
 * [myGraph::getNumberEdges Count the edges of the graph]
 * @param  Vertex [Origin vertex]
 * @return        [The number of edges]
 */
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

/**
 * [myGraph::getDistance Returns a variable with the distance]
 * @param V1   [First vertex]
 * @param V2   [Secnd vertex]
 * @param dist [Variable for the distance]
 */
void myGraph::getDistance(int V1, int V2, float &dist){ 
	dist = sqrt(pow(abs(getX(V1) - getX(V2)), 2.0) 
  		      + pow(abs(getY(V1) - getY(V2)), 2.0));
	//dist = Vertices[V1].adjacencyList[V2].getWeight();
} 

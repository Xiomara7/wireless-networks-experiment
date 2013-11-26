#include <iostream>
#include <cmath>
#include "stdlib.h"
#include "myGraph.h"
#include "wirelessNetwork.h"

using namespace std; 

wirelessNetwork::wirelessNetwork(){
	srand(time(NULL)); 
	float dist; 
	float randX = rand() % 10; 
	float randY = rand() % 10;

	for(int i=0; i<500; i++){
		G.addVertex(randX, randY); 
		for(int j=0; j < G.getNumberVertices(); j++){
			dist = sqrt(pow((randX - G.getX(j)), 2.0) 
		    	     +  pow((randY - G.getY(j)), 2.0)); 
			if(dist < 1){
				G.addEdge(i, j, dist);
			}
		}
	}
}

wirelessNetwork::wirelessNetwork(int size, int n){
	srand(time(NULL)); 
	float dist; 
	float randX = rand() % size; 
	float randY = rand() % size;

	for(int i=0; i<n; i++){
		G.addVertex(randX, randY); 
		for(int j=0; j < G.getNumberVertices(); j++){
			dist = sqrt(pow((randX - G.getX(j)), 2.0) 
		    	     +  pow((randY - G.getY(j)), 2.0)); 
			if(dist < 1){
				G.addEdge(i, j, dist);	
			}
		}
	}
}

void wirelessNetwork::degree(){
	vector <int> neighbors; 
	int sum = 0; 
	int average, max; 
	for(int i=0; i < G.getNumberVertices(); i++){
			G.getNeighbors(neighbors, i); 
			sum += neighbors.size();
			cout << "sum: " << sum << endl; 
	}
	cout << "sum total: " << sum << endl; 
	average = sum / G.getNumberVertices(); 

	cout << "The average degree: " << average << endl; 
	cout << "The maximum degree: " << max << endl; 
}

/*myGraph wirelessNetwork::TopologyControl(myGraph G){

	myGraph H; 


	for(int i=0; i< ; i++){
		/*for each vertex u ∈ V do
   		temp := N(u)
   		for each neighbor v ∈ N(u) do
    	if u and v have a common neighbor w such that|uw|<|uv| and |vw|<|uv| then
    	temp := temp − {v}
   		N (u) := temp
	}

	return H; 
}

//int wirelessNetwork::compassRouting(myGraph::Vertex s, myGraph::Vertex t){
	
	if the current vertex x equals t, 
	then we are done; otherwise find 
	a neighbor v of x that makes the 
	smallest angle with the direction 
	xt and do compass routing 
	with source v and destination t.
}*/
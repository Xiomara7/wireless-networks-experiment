#include <iostream>
#include <cmath>
#include "stdlib.h"
#include "myGraph.h"
#include "wirelessNetwork.h"

using namespace std; 

wirelessNetwork::wirelessNetwork(){
	srand(time(NULL)); 
	myGraph G; 
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
	myGraph G; 
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


myGraph wirelessNetwork::TopologyControl(myGraph G){
	
	/*Input: A UDG G = (V,E).
	Output the graph H = (V,E ) where E = {(u, v) | v ∈ N(u)}.

	for each vertex u ∈ V do
   	temp := N(u)
   	for each neighbor v ∈ N(u) do
    if u and v have a common neighbor w such that|uw|<|uv| and |vw|<|uv| then
    temp := temp − {v}
   	N (u) := temp*/

	myGraph H; 
}

//int wirelessNetwork::compassRouting(myGraph::Vertex s, myGraph::Vertex t){
	
	/*if the current vertex x equals t, 
	then we are done; otherwise find 
	a neighbor v of x that makes the 
	smallest angle with the direction 
	xt and do compass routing 
	with source v and destination t.
}*/
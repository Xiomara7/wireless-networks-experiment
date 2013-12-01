#include <iostream>
#include <cmath>
#include <fstream>
#include "stdlib.h"
#include "myGraph.h"
#include "wirelessNetwork.h"

using namespace std; 

wirelessNetwork::wirelessNetwork(){
	srand(time(NULL)); 
	float dist; 
	float randX = ((double)rand()/(double)RAND_MAX)*10.0;
	float randY = ((double)rand()/(double)RAND_MAX)*10.0;
	G.addVertex(randX, randY); 

	for(int i=0; i<500-1; i++){
		randX = ((double)rand()/(double)RAND_MAX)*10.0;
		randY = ((double)rand()/(double)RAND_MAX)*10.0;
		G.addVertex(randX, randY); 
		for(int j=0; j < G.getNumberVertices(); j++){
			dist = sqrt(pow(abs(randX - G.getX(j)), 2.0) 
		    	     +  pow(abs(randY - G.getY(j)), 2.0)); 
			if(dist < 1){
				G.addEdge(i, j, dist);
			}
		}
	}
}

wirelessNetwork::wirelessNetwork(int size, int n){
	srand(time(NULL)); 
	float dist; 
	float randX = ((double)rand()/(double)RAND_MAX)*size;
	float randY = ((double)rand()/(double)RAND_MAX)*size;
	G.addVertex(randX, randY); 
	for(int i=0; i<n-1; i++){
		randX = ((double)rand()/(double)RAND_MAX)*size;
		randY = ((double)rand()/(double)RAND_MAX)*size; 
		G.addVertex(randX, randY); 
		for(int j=0; j < G.getNumberVertices()-1; j++){
			dist = sqrt(pow(abs(randX - G.getX(j)), 2.0) 
		    	     +  pow(abs(randY - G.getY(j)), 2.0)); 
			if(dist < 1){
				G.addEdge(i, j, dist);
			}
		}
	}
}

void wirelessNetwork::degree(){
	int sum = 0; 
	int average, max = 0; 
	cout << "vertices: " << G.getNumberVertices() << endl; 
	for(int i=0; i < G.getNumberVertices()-1; i++){
			vector <int> neighbors; 
			G.getNeighbors(neighbors, i); 
			sum += neighbors.size();
			if( neighbors.size() > max){ 
				max = neighbors.size();
			}
	}
	average = sum / G.getNumberVertices(); 

	cout << "The average degree: " << average << endl; 
	cout << "The maximum degree: " << max << endl; 
}

void wirelessNetwork::printGraph(){
	ofstream graph;
	graph.open("file.txt");
	for(int i=0; i<G.getNumberVertices()-1; i++){ 
		vector<int> neighbors;
		G.getNeighbors(neighbors, i); 
		for(int j=0; j<neighbors.size(); j++){
			graph << i << "--" << neighbors[j] << endl; 
		}
	}
	graph.close(); 
}

/*myGraph wirelessNetwork::TopologyControl(myGraph G){
	myGraph H;
	vector <int> neighbors1;  
	vector <int> neighbors2;  
	vector <int> temp; 
	for(int i=0; i < G.getNumberVertices()-1; i++){
		G.getNeighbors(neighbors1, i); 
		G.getNeighbors(neighbors2, neighbors1[i]); 
		for(int j=1; j < neighbors1.size(); j++){
			for(int k=0; k < neighbors2.size(); k++){
				if(neighbors1[j] == neighbors2[k]){
					if(dist < dist && dist < dist){
						//borrar (-1) en el grafo H!!; 
					}
				}
			}

		}
	}
	return H; 
}

int wirelessNetwork::compassRouting(myGraph::Vertex s, myGraph::Vertex t){
	
	if the current vertex x equals t, 
	then we are done; otherwise find 
	a neighbor v of x that makes the 
	smallest angle with the direction 
	xt and do compass routing 
	with source v and destination t.
}*/
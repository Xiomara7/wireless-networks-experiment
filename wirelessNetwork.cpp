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
		for(int j=0; j < G.Vertices.size()-1; j++){
			dist = sqrt(pow(randX - G.Vertices[j].getX()) 
		    	     +  pow(randY - G.Vertices[j].getY())); 
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
		for(int j=0; j < G.Vertices.size()-1; j++){
			dist = sqrt(pow(randX - G.Vertices[j].getX()) 
		    	     + pow(randY - G.Vertices[j].getY())); 
			if(dist < 1){
				G.addEdge(i, j, dist);	
			}
		}
	}
}

/*
wirelessNetwork wirelessNetwork::TopologyControl(){

}

int wirelessNetwork::compassRouting(int s, int t){
	
}*/
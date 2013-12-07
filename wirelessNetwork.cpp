#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
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

	for(int i=1; i<500; i++){
		randX = ((double)rand()/(double)RAND_MAX)*10.0;
		randY = ((double)rand()/(double)RAND_MAX)*10.0;
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

wirelessNetwork::wirelessNetwork(int size, int n){
	srand(time(NULL)); 
	float dist; 
	float randX = ((double)rand()/(double)RAND_MAX)*size;
	float randY = ((double)rand()/(double)RAND_MAX)*size;
	G.addVertex(randX, randY); 
	for(int i=1; i<n; i++){
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
	int count; 
	int average, max = 0; 
	for(int i=0; i < G.getNumberVertices(); i++){ 
		count = 0; 	
		vector <int> neighbors; 
		G.getNeighbors(neighbors, i); 
		if(neighbors.size() > 0){
			for(int j=0; j<neighbors.size(); j++){
				if(neighbors[j] != -1){
					count++;  		
				}
			}
			sum += count; 
			if( count > max){ 
				max = count; 
			}
		}
	}
	
	average = sum / G.getNumberVertices(); 

	cout << "The average degree: " << average << endl; 
	cout << "The maximum degree: " << max << endl; 
}

void wirelessNetwork::TopologyControl(){
	for(int i=0; i < G.getNumberVertices(); i++){ 
		vector <int> neighbors1;  
		vector <int> neighbors2;
		vector <int> temp; 
		G.getNeighbors(neighbors1, i); 
		if(neighbors1.size() != 0){
			for(int j=0; j < neighbors1.size(); j++){
				G.getNeighbors(neighbors2, neighbors1[j]);
				G.getNeighbors(temp, i);
				if(neighbors2.size() != 0){
					for(int k=0; k < neighbors2.size(); k++){
						if(neighbors1[j] == neighbors2[k]){
							if(G.getDistance(i, neighbors2[k]) <  G.getDistance(i, neighbors1[j])
							&& G.getDistance(neighbors1[j], neighbors2[k]) <  G.getDistance(i, neighbors1[j])){
									temp.insert(temp.begin()+j, -1); 
							}
						}
					}
				}
			}
		}
		for(int l=0; l<temp.size(); l++){
			if(temp[l] == -1){
				G.deleteEdge(i, l); 
			}
		}
	}
}

/*int wirelessNetwork::compassRouting(int s, int t){
	if(s == t){ return; }
	else{
		vector <int> neighbors; 
		G.getNeighbors(neighbors, s); 
		int min = (atan(getDistance(t, 0) / getDistance(s, t))); 
		for(int i=1; i<neighbors.size()-1; i++){
			if((atan(getDistance(t, i) / getDistance(s, t))) < min ){
				min = atan(getDistance(t, i) / getDistance(s, t)); 
			}
		}
	}	
 }
*/

 void wirelessNetwork::generateGraph(){
	ofstream outputFile; 
	outputFile.open("data.dot");
	outputFile << "graph G { \n overlap=false; \n size = \"10,10\"; \n node [shape=circle, fixedsize=true, fontsize=5, width=.50, height=.50];\n"; 

	for(int j=0; j<G.getNumberVertices(); j++){
		outputFile << j << "[ pos = \"" << G.getX(j) << "," << G.getY(j) << "\", label = \"" << j << "\" ]" << endl; 
	}
	for(int j=0; j<G.getNumberVertices(); j++){
		vector<int> v;
		G.getNeighbors(v, j);
		for(int k=0; k<v.size(); k++){
			outputFile << j << "--" << v[k] << ";" << endl; 
		}
	}
	outputFile << "}"; 
	outputFile.close(); 
}

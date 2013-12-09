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
	float dist, dista; 
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
				G.addEdge(j, i, dist);
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
				G.addEdge(j, i, dist);
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
			for(int j=0; j<neighbors.size(); j++)
				if(neighbors[j] != -1){ count++; }
			sum += count; 
			if( count > max){ max = count;}
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
		float dist1, dist2, dist3; 
		G.getNeighbors(neighbors1, i); 
		G.getNeighbors(temp, i);
		if(neighbors1.size() != 0){
			for(int j=0; j < neighbors1.size(); j++){
				G.getNeighbors(neighbors2, neighbors1[j]);
				if(neighbors2.size() != 0){
					for(int k=0; k < neighbors1.size(); k++){
						for(int l=0; l < neighbors2.size(); l++){
							if(neighbors1[k] == neighbors2[l]){
								G.getDistance(i, neighbors2[l], dist1); 
								G.getDistance(i, neighbors1[j], dist2); 
								G.getDistance(neighbors1[j], neighbors2[l], dist3); 
								if((dist1 <  dist2) && (dist3 <  dist2)) {
									temp.at(j) = -1;
								}		
							}
						}
					}
				}
			}
			for(int m=0; m < temp.size(); m++){
				if(temp[m] == -1){
					G.deleteEdge(i, m);
				}	
			}
		}
	}
}

/*vector<int> wirelessNetwork::compassRouting(int s, int t){
	vector <int> neighbors;
	vector<int> path;
	int src; 
	if(s == t){ return path; }
	else{ 
		for(int j=0; j<G.getNumberVertices(); j++){
			G.getNeighbors(neighbors, s); 
			int min = (acos(G.getDistance(s,t) / G.getDistance(s, neighbors[0]))); 
			for(int i=1; i<neighbors.size(); i++){
				if((acos(G.getDistance(s,t) / G.getDistance(s, neighbors[i]))) < min ){
					min = acos(G.getDistance(t, i) / G.getDistance(s, t)); 
					src = i; 
				}
			}
			path.push_back(src); 
		}
		return path; 
	}	
 }*/

 void wirelessNetwork::generateGraph(){
	ofstream outputFile; 
	outputFile.open("data.dot");
	outputFile << "graph G { \n overlap=false; \n size = \"10,10\"; \n"; 
	outputFile << "node [shape=circle, fixedsize=true, fontsize=5, "; 
	outputFile << "width=.50, height=.50];\n"; 

	for(int j=0; j<G.getNumberVertices(); j++){
		outputFile << j << "[ pos = \"" << G.getX(j) << ","; 
		outputFile << G.getY(j) << "\", label = \"" << j << "\" ]" << endl; 
	}
	for(int j=0; j<G.getNumberVertices(); j++){
		vector<int> v;
		G.getNeighbors(v, j);
		for(int k=0; k<v.size(); k++)
			if(v[k] > j)
				outputFile << j << "--" << v[k] << ";" << endl; 
	}
	outputFile << "}"; 
	outputFile.close(); 
}

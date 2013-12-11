#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include "stdlib.h"
#include "myGraph.h"
#include "wirelessNetwork.h"

using namespace std; 

/**
 * Default Constructor:
 * [Takes no parameters, and generates the UDG obtained by distributing 
 * 500 points, uniformly a trandom, on a 10 × 10 square.]
 */

wirelessNetwork::wirelessNetwork(){
	srand(time(NULL)); 
	float dist; 

	float randX = (double)(rand() % 10000) / 1000; // X for the first node
	float randY = (double)(rand() % 10000) / 1000; // Y for the first node
	
	G.addVertex(randX, randY); 

	for(int i=1; i<500; i++){
		randX = (double)(rand() % 10000) / 1000; 
		randY = (double)(rand() % 10000) / 1000; 
		G.addVertex(randX, randY); 
		for(int j = 0; j < G.getNumberVertices()-1; j++){
			dist = sqrt(pow(abs(randX - G.getX(j)), 2.0) 
		    	     +  pow(abs(randY - G.getY(j)), 2.0)); 
			if(dist < 1)
				G.addEdge(i, j, dist);
		}
	}
}

/**
 * Constructor with two parameters:
 * [Takes two parameters, size and n, and generates the UDG obtained 
 *  by distributing n points, uniformly a trandom, on a size × size 
 *  square.]
 */
wirelessNetwork::wirelessNetwork(int size, int n){
	srand(time(NULL)); 
	float dist; 
	
	float randX = (double)(rand() % 100) / 10;	// X for the first node
	float randY = (double)(rand() % 100) / 10; 	// Y for the first node
	
	G.addVertex(randX, randY); 
	
	for(int i=1; i<n; i++){
		randX = (double)(rand() % 100) / 10;
		randY = (double)(rand() % 100) / 10; 
		G.addVertex(randX, randY); 
		for(int j=0; j < G.getNumberVertices()-1; j++){
			dist = sqrt(pow(abs(randX - G.getX(j)), 2.0) 
		    	     +  pow(abs(randY - G.getY(j)), 2.0)); 
			if(dist < 1)
				G.addEdge(i, j, dist);
		}
	}
}

/**
 * [wirelessNetwork::degree This function report the average degree and 
 *  the maximum degree. Recall that the degree of  a vertex is equal to 
 *  the number of neighbors it has.]
 */
void wirelessNetwork::degree(){
	int count,   sum = 0; 			
	int average, max = 0; 
	
	for(int i = 0; i < G.getNumberVertices(); i++){ 
		vector <int> neighbors; 		// Neighbors of the (i) node.
		count = 0; 	
		
		G.getNeighbors(neighbors, i); 	// Get neighbors of (i) and
										// put them in neighbors vector
		if(neighbors.size() > 0){ 	
			for(int j = 0; j < neighbors.size(); j++)
				if(neighbors[j] != -1)
					count++; 
			sum += count; 
			if( count > max)
				max = count;
		}
	}

	average = sum / G.getNumberVertices(); 

	cout << "The average degree: " << average << endl; 
	cout << "The maximum degree: " << max << endl; 
}

/**
 * [wirelessNetwork::TopologyControl:  Protocol that each node uses to 
 *  choose  a subset of nodes to communicate with.  The algorithm  uses 
 *  a simple rule to determine whether an edge {u, v} should be kept or 
 *  dropped]
 */
void wirelessNetwork::TopologyControl(){
	for(int i=0; i < G.getNumberVertices(); i++){ 
		vector <int> neighbors_u;		// Set of neighbors of u [N(u)]
		vector <int> neighbors_v;		// Set of neighbors of v ∈ N(u)		
		vector <int> temp; 				// Temporary vector: it'll be a
										// copy of neighbors of u. 
										
		float dist1, dist2, dist3; 		// dist1: |u,w|; w ∈ N(u) & N(v)				  
										// dist2: |u,v|
										// dist3: |v,w|
		G.getNeighbors(neighbors_u, i); 
		G.getNeighbors(temp, i);
		if(neighbors_u.size() != 0){
			for(int j = 0; j < neighbors_u.size(); j++){
				// get neighbors of v in (neighbors_v)
				G.getNeighbors(neighbors_v, neighbors_u[j]);	
				
				if(neighbors_v.size() != 0)
					// for each neighbor of u
					for(int k=0; k < neighbors_u.size(); k++)		
						for(int l=0; l < neighbors_v.size(); l++)
							if(neighbors_u[k] == neighbors_v[l]){
								G.getDistance(i, neighbors_v[l], dist1); 				//dist1: |u,w|
								G.getDistance(i, neighbors_u[j], dist2); 				//dist2: |u,v|
								G.getDistance(neighbors_u[j], neighbors_v[l], dist3); 	//dist3: |v,w|
								if((dist1 <  dist2) && (dist3 <  dist2))
									temp.at(j) = -1;
							}
				}
			}
		for(int m=0; m < temp.size(); m++)
			if(temp[m] == -1){
				G.deleteEdge(i, m);
		}
	}
}

/**
 * [wirelessNetwork::compassRouting:  Suppose a node x receives a message m 
 *  intended  for  destination t. Further suppose that x knows its location
 *  the location of t, and the location of its neighbors in the plane. Then 
 *  x sends m to a neighbor v that minimizes the angle]
 * 
 * 		@param  s [source vertex]
 *      @param  t [destination vertex]
 * 
 * @return   [if the current vertex s equals t, then we are done; otherwise 
 * find a neighbor v of s that makes  the smallest angle with the direction 
 * st and do compass routing with source v and destination t.]
 */
int wirelessNetwork::compassRouting(int s, int t){
	vector <int> neighbors;			// Neighbors of the (i) node.
	vector <int> check;				// visited nodes.
	int src; 						// v, new source vertex
	int sum; 
	float dist1, dist2, dist3; 		// dist1: |s,t|
									// dist2: |s,v|; 
									// dist3: |t,v|
	float ang; 						// angle to be calculate
	
	if(s == t) return 0;
	
	else{ 
		G.getNeighbors(neighbors, s);
	
		G.getDistance(s,t, dist1); 				// dist1: |s,t|
		G.getDistance(s, neighbors[0], dist2); 	// dist2: |s,v|
		G.getDistance(t, neighbors[0], dist3); 	// dist3: |t,v|
	
		float min = acos((pow(dist1,2.0) + pow(dist2,2.0)	// first calculation to 
		- pow(dist3,2.0)) / (2*dist1*dist2)) * (180/3.14);  // use as the minimum
		
		for(int i=1; i<neighbors.size(); i++){
			cout << "s: " << s << endl; 
			cout << "t: " << t << endl; 
			G.getDistance(s,t, dist1); 				// dist1: |s,t|
			G.getDistance(s, neighbors[i], dist2);	// dist2: |s,v|
			G.getDistance(t, neighbors[i], dist3); 	// dist3: |t,v|
			
			ang = acos((pow(dist1,2.0) + pow(dist2,2.0)
		 	- pow(dist3,2.0)) / (2*dist1*dist2)) * (180/3.14); 
			// If the angle is less than the actual minimum
			cout << "ang: " << ang << endl; 
			if(ang < min){
				min = ang; 
				cout << "min" << min << endl; 
				src = neighbors[i];				// src will be v, the new source vertex
				cout << "src" << src << endl; 
				check.push_back(src);					// save the visited vertex v 
				for(int i = 0; i < check.size()-1; i++)
					if(src == check[i]){ 
						return 0; 
					}
				else {
					sum += 1 + compassRouting(src, t); 		
					return sum;
				} 
			}
		/*} check.push_back(src);					// save the visited vertex v 
		for(int i = 0; i < check.size()-1; i++){	
			// if v was visited, there's not path and return 0. 
			if(src == check[i]){ 
				cout << "check" << check[i] << endl; 
				return sum += 0;
			}
			else 
			return sum; 
		*/}
	}
}

/**
 * [wirelessNetwork::generateGraph: Generate the dot files to represent 
 *  the graph using Graphviz ]
 * @param filename [name of the file]
 */
 void wirelessNetwork::generateGraph(string filename){
	ofstream outputFile; 
	outputFile.open(filename.c_str());
	// Header of the dot files:
	outputFile << "graph G { \n size = \"100,100\"; \n";  
	outputFile << "node [shape=circle, fixedsize=true,"; 
	outputFile << " fontsize=5, height=.15];\n"; 

	for(int j = 0; j < G.getNumberVertices(); j++){
		// Position, X and Y of the vertex:
		outputFile << j << "[ pos = \"" << G.getX(j) << ","; 
		outputFile << G.getY(j) << "\" ]" << endl; 
	}
	for(int j = 0; j < G.getNumberVertices(); j++){
		vector<int> neighbors;						// Neighbors of the (j) vertex
		G.getNeighbors(neighbors, j);			
		for(int k = 0; k < neighbors.size(); k++)	// for each neighbor of (j) if it's > j, 
			if(neighbors[k] > j)					// then print, to avoid the doble edges. 
				outputFile << j << "--" << neighbors[k] << ";" << endl; 
	}
	outputFile << "}"; 
	outputFile.close(); 
}

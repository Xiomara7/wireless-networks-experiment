#include <iostream>
#include <cmath>
#include "myGraph.h"

#ifndef NETWORK
#define NETWORK

class wirelessNetwork {
	private: 
		myGraph G; 
	public: 

		wirelessNetwork();
		/**
		 * DEFAULT CONSTRUCTOR
		 */

		 wirelessNetwork(int size, int n);  
		/**
		 * CONSTRUCTOR WITH PARAMETERS
		 */
		
		void TopologyControl();
		/**
		 * [TopologyControl description]
		 *  Protocol that each node uses to choose  a subset of nodes to communicate with.  
		 *  The algorithm  uses a simple rule to determine whether an edge {u, v}  should 
		 *  be kept or dropped]
		 */

		int compassRouting(int s, int t, vector <int> &check); 
		/**
		 * [compassRouting  Suppose a node x receives a message m 
 		 *  intended  for  destination t. Further suppose that x knows its location
 		 *  the location of t, and the location of its neighbors in the plane. Then 
 		 *  x sends m to a neighbor v that minimizes the angle]]
 		 *  
		 *   @param  s [source vertex]
		 *   @param  t [destination vertex]
		 * 
		 * @return   [if the current vertex s equals t, then we are done; otherwise 
 		 * find a neighbor v of s that makes  the smallest angle with the direction 
 		 * st and do compass routing with source v and destination t.]
		 */

		
		void degree(); 
		/**
		 * [wirelessNetwork::degree This function report the average degree and 
 		 *  the maximum degree. Recall that the degree of  a vertex is equal to 
 		 *  the number of neighbors it has.]
		 */

		void generateGraph(string filename); 
		/**
 		* [wirelessNetwork::generateGraph: Generate the dot files to represent 
 		*  the graph using Graphviz ]
 		* @param filename [name of the file]
 		*/
}; 

#endif
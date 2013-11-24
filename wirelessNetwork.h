#include <iostream>
#include <cmath>
#include "myGraph.h"

#ifndef NETWORK
#define NETWORK

class wirelessNetwork {
	public: 

		/**
		 * 
		 */
		wirelessNetwork();

		/**
		 * 
		 */
		wirelessNetwork(int size, int n);  
		
		/**
		 * [TopologyControl description]
		 * @return [description]
		 */
		myGraph TopologyControl(myGraph G);

		/**
		 * [compassRouting description]
		 * @param  s [description]
		 * @param  t [description]
		 * @return   [description]
		 */
		//int compassRouting(myGraph::Vertex s, myGraph::Vertex t); 
}; 

#endif
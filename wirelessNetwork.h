#include <iostream>
#include <cmath>
#include "myGraph.h"

#ifndef NETWORK
#define NETWORK

class wirelessNetwork {
	private: 
		myGraph G; 

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
		myGraph TopologyControl();

		/**
		 * [compassRouting description]
		 * @param  s [description]
		 * @param  t [description]
		 * @return   [description]
		 */
		//int compassRouting(myGraph::Vertex s, myGraph::Vertex t); 
		
		void degree(); 

		void printGraph(); 
}; 

#endif
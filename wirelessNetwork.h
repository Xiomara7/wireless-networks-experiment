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
		 * DEFAULT CONSTRUCTOR
		 */
		wirelessNetwork();

		/**
		 * CONSTRUCTOR WITH PARAMETERS
		 */
		wirelessNetwork(int size, int n);  
		
		/**
		 * [TopologyControl description]
		 * @return [description]
		 */
		void TopologyControl();

		/**
		 * [compassRouting description]
		 * @param  s [description]
		 * @param  t [description]
		 * @return   [description]
		 */
		int compassRouting(int s, int t); 
		
		void degree(); 
		void generateGraph(string filename); 
}; 

#endif
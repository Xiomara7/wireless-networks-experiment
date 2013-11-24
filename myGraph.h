#include <iostream>
#include <vector>

#ifndef GRAPH
#define GRAPH

using namespace std;  

class myGraph {
	private: 
		class Vertex {
			private:
				float x; 
				float y; 
			public:
				class Data {
					private:
						int   ID; 
						float weight;
					public:
						void  setID(int DestID)  { ID = DestID;   } 
						void  setWeight(float w) { weight = w;    }
						float getWeight()        { return weight; } 
					 	int   getID()            { return ID;     }
				}; 
				 
				Vertex(){ x = 0; 
						  y = 0; }
				vector <Data> adjacencyList;
			 	void  setX(float n){ x = n; }
			 	void  setY(float n){ y = n; }
				float getX() { return x;    }
				float getY() { return y;    }
		};
		vector <Vertex> Vertices;

	public:  

		/**
		 * [addVertex description]
		 * @param  x [description]
		 * @param  y [description]
		 * @return   [description]
		 */
		void  addVertex(float x, float y);

		/**
		 * [addEdge description]
		 * @param  OrigID [description]
		 * @param  DestID [description]
		 * @param  weight [description]
		 * @return        [description]
		 */
		void  addEdge(int OrigID, int DestID, float weight);

		/**
		 * [deleteVertex description]
		 * @param  pos [description]
		 * @return     [description]
		 */
		void  deleteVertex(int pos);

		/**
		 * [deleteEdge description]
		 * @param  Vertex [description]
		 * @param  Edge   [description]
		 * @return        [description]
		 */
		void  deleteEdge(int Vertex, int Edge);

		 /**
		  * [getNeighbors description]
		  * @param  neighbors [description]
		  * @param  pos       [description]
		  * @return           [description]
		  */
		void  getNeighbors(vector <int> neighbors, int pos);

		/**
		 * [getNumberVertices description]
		 * @return [description]
		 */
		int   getNumberVertices();

		/**
		 * [getNumberEdges description]
		 * @param  Vertex [description]
		 * @return        [description]
		 */
		int   getNumberEdges(int Vertex);

		/*
		
		 */
		float getX(int pos) { return Vertices[pos].getX(); }
		
		/*
		
		 */
		float getY(int pos) { return Vertices[pos].getY(); } 

}; 

#endif


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
				float getX() { return x; }
				float getY() { return y; }
		};
		vector <Vertex> Vertices;

	public: 

		void addVertex(float x, float y); 

		void addEdge(int OrigID, int DestID, float weight); 

		void deleteVertex(int pos); 

		void deleteEdge(int Vertex, int Edge); 

		void getNeighbors(vector <int> neighbors, int pos); 

		int getNumberVertices(); 

		int getNumberEdges(int Vertex);  
		
		float getX(int pos) { return Vertices[pos].getX(); }

		float getY(int pos) { return Vertices[pos].getY(); } 

}; 

#endif


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
						void  setWeight(float w) { weight = w;    
						}
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
				int   getID(){ return getID();   }
		};
		vector <Vertex> Vertices;

	public:  

		void  addVertex(float x, float y);
		/**
		 * [addVertex Añadir un nodo al grafo]
		 * @param   x  [Coordenada X del nodo]
		 * @param   y  [Coordenada Y del nodo]
		 */

		void  addEdge(int OrigID, int DestID, float weight);
		/**
		 * [addEdge  Añadir arista de un nodo a otro]
		 * @param  OrigID [ID del nodo origen]
		 * @param  DestID [ID del nodo destinatario ]
		 * @param  weight [distancia entre los nodos]
		 */

		void  deleteVertex(int pos);
		/**
		 * [deleteVertex Borrar un nodo del grafo]
		 * @param pos [posición del nodo]
		 */

		void  deleteEdge(int V1, int V2);
		/**
		 * [deleteEdge Borrar una arista]
		 * @param  V1 [Nodo Origen ]
		 * @param  V2 [Nodo Destino]
		 */

		void  getNeighbors(vector <int> &neighbors, int pos);
		int   getNumberVertices();
		int   getNumberEdges(int Vertex);
		float getX(int pos) { return Vertices[pos].getX(); }
		float getY(int pos) { return Vertices[pos].getY(); } 
		
		void getDistance(int V1, int V2, float &dist); 
		void printVectors(); 
		
}; 

#endif


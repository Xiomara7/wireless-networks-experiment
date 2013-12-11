#include <iostream>
#include <cmath>
#include <sstream>
#include "wirelessNetwork.h"
#include "myGraph.h"
#include "stdlib.h"



using namespace std; 

	template <typename T>	
	string toStr(T a) {
 	stringstream s;
 	s << a;
 	return s.str();
	}

int main (){

/* Generate 10 wireless networks modeled as UDGs, by distributingn = 500,
   550, 600, 650, 700, 750, 800, 850, 900, 950 points on a 10 × 10 grid. 

   report the average degree and the maximum degree. Plot these, showing 
   how they increase with respect to n. 

   Run topology control on each of these networks to produce 10 new and 
   much sparser networks. Report and plot the average and maximum degree
   of these 10 networks as well. Based on your data and plots, write 2-3
   sentences commenting on whether performing topology control has
   resulted in a much sparser graph or not.*/

	int j = 500; 
	cout << "FIRST EXPERIMENT: \n"; 
	for(int i=0 ; i<10; i++){
		string name1 = toStr(i) + "before.dot"; 
		string name2 = toStr(i) + "after.dot"; 
		wirelessNetwork UDG(10, j);
		
		cout << "Degree before Topology Control\n"; 
		UDG.degree();
		UDG.generateGraph(name1); 
		UDG.TopologyControl();
		cout << "Degree after Topology Control\n"; 
		UDG.degree();
		UDG.generateGraph(name2); 

		j+=50; 
	}

/*  Generate a wireless network G with 1000 points distributed on a 10 × 10 
 	square. Then repeat the following 10 times. Uniformly at random, pick a 
	vertex and designate it as the source s and again uniformly  at  random,
	pick a vertex and designate it as the destination t.Run compass routing 
	on G, with source s and destination t. Report on whether compassrouting 
	was  able  to  find the destination or not and if it was, report on the 
	length of the path from s to t that was discovered. Present your results 
	in a tabular form.*/

/*  Start with the same wireless network G generated for Experiment (2) and 
	run  topology  control  on it to get a sparser network H. Run Experiment 
	(2) again, but use the network H this time. Tabulate your results as for 
	Experiment (2). Write  2-3  sentences commenting on how the path lengths 
	generated  in  Experiment  (3),  compare  with path lengths generated in 
	Experiment (2). Try to explain your observations. Place the code for your 
	experiments in a single file called experiments.cpp. The code in the file 
	experiments.cpp makes extensive calls  to  methods in the wirelessNetwork  
	class and possibly to methods in the myGraph class as well. 	
*/

	/*cout << "SECOND and THIRD EXPERIMENT: \n"; 
	for(int i=0; i<10; i++){
		wirelessNetwork UDG1000(10, 1000);			
		srand(time(NULL)); 

		int s, t; 

		s = rand()%1000; 
		t = rand()%1000; 

		cout << "length of the path, network " << i+1 << ": (before topology): "; 
		cout << UDG1000.compassRouting(s, t) << endl;

		s = rand()%1000; 
		t = rand()%1000; 

		UDG1000.TopologyControl(); 	
		cout << "length of the path, network " << i+1 << ": (after topology): "; 
		cout << UDG1000.compassRouting(s, t) << endl;   
	
	}*/	

	return 0; 
}

#include <iostream>
#include "wirelessNetwork.h"
#include "myGraph.h"
#include <cmath>


using namespace std; 

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
	for(int i=0 ; i<10; i++){
		wirelessNetwork UDG(10, j);
		
		cout << "Degree before Topology Control\n"; 
		UDG.degree();
		UDG.generateGraph(); 
		UDG.TopologyControl();
		cout << "Degree after Topology Control\n"; 
		UDG.degree();
		UDG.generateGraph(); 

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


	for(int i=0; i<10; i++){
		wirelessNetwork UDG1000(10, 1000);			
		srand(time(NULL)); 

		int s, t; 

		s = rand()%1000; 
		t = rand()%1000; 

		UDG1000.compassRouting(s, t);  
	
	}	

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

	for(int i=0; i<=10; i++){
		UDG1000.TopologyControl(); 	
		UDG1000.compassRouting(s, t); 
	}
	
	return 0; 
}

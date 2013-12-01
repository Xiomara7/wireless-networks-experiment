#include <iostream>
#include "wirelessNetwork.h"
#include "myGraph.h"

using namespace std; 
/*
Generate 10 wireless networks modeled as UDGs, 
by distributingn = 500, 550, 600, 650, 700, 750, 
800, 850, 900, 950 points on a 10 × 10 grid. For 
each network, report the average degree and the 
maximum degree. Recall that the degree of a vertex 
is equal to the number of neighbors it has. Plot 
these, showing how they increase with respect to n. 
Run topology control on each of these networks to 
produce 10 new and much sparser networks. Report 
and plot the average and maximum degree of these 
10 networks as well. Based on your data and plots, 
write 2-3 sentences commenting on whether performing 
topology control has resulted in a much sparser graph 
or not.*/

int main (){

	//Generate wireless networks:
	wirelessNetwork UDG500;  
	wirelessNetwork UDG550(10, 550);
	wirelessNetwork UDG600(10, 600);
	wirelessNetwork UDG650(10, 650);
	wirelessNetwork UDG700(10, 700); 
	wirelessNetwork UDG750(10, 750);
	wirelessNetwork UDG800(10, 800);
	wirelessNetwork UDG850(10, 850);
	wirelessNetwork UDG900(10, 900);
	wirelessNetwork UDG950(10, 950);

	//UDG500.degree();
	UDG550.degree(); 
	UDG600.degree(); 
	UDG650.degree(); 
	UDG700.degree(); 
	UDG750.degree(); 
	UDG800.degree(); 
	UDG850.degree(); 
	UDG900.degree(); 
	UDG950.degree(); 

	//UDG500.printGraph();   

/*
Generate a wireless network G with 1000 points 
distributed on a 10 × 10 square. Then repeat the
following 10 times. Uniformly at random, pick a 
vertex and designate it as the source s and again 
uniformly at random, pick a vertex and designate it
as the destination t.Run compass routing on G, with
source s and destination t. Report on whether 
compassrouting was able to find the destination or 
not and if it was, report on the length of the path 
from s to t that was discovered. Present your results 
in a tabular form.*/

	


/*
Start with the same wireless network G generated for 
Experiment (2) and run topology control on it to get 
a sparser network H. Run Experiment (2) again, but use 
the network H this time. Tabulate your results as for 
Experiment (2). Write 2-3 sentences commenting on how 
the path lengths generated in Experiment (3), compare 
with path lengths generated in Experiment (2). Try to 
explain your observations. Place the code for your 
experiments in a single file called experiments.cpp. 
The code in the file experiments.cpp makes extensive 
calls to methods in the wirelessNetwork class and 
possibly to methods in the myGraph class as well.
 */	

	return 0; 
}

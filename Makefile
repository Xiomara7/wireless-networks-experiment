myGraph: myGraph.o wirelessNetwork.o
	g++ -o myGraph myGraph.cpp wirelessNetwork.cpp

myGraph.o: myGraph.cpp myGraph.h
	g++ -c myGraph.cpp

wirelessNetwork.o: wirelessNetwork.cpp wirelessNetwork.h
	g++ -c wirelessNetwork.cpp

clean:
	rm *.o myGraph

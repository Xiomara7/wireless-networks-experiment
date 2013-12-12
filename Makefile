experiments: myGraph.o wirelessNetwork.o experiments.cpp
	g++ -o experiments myGraph.o wirelessNetwork.o experiments.cpp

myGraph.o: myGraph.cpp myGraph.h
	g++ -c myGraph.cpp

wirelessNetwork.o: wirelessNetwork.cpp wirelessNetwork.h
	g++ -c wirelessNetwork.cpp

clean:
	rm *.o experiments

dot:
	bash convert.sh





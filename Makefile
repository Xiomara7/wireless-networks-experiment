experiments: myGraph.o wirelessNetwork.o
	g++ -o experiments myGraph.cpp wirelessNetwork.cpp experiments.cpp

myGraph.o: myGraph.cpp myGraph.h
	g++ -c myGraph.cpp

wirelessNetwork.o: wirelessNetwork.cpp wirelessNetwork.h
	g++ -c wirelessNetwork.cpp

clean:
	rm *.o experiments

before: 
	dot -Kfdp -n -Tpdf -o before.pdf before.dot

after:
	dot -Kfdp -n -Tpdf -o after.pdf after.dot

data: 
	dot -Kfdp -n -Tpdf -o data.pdf data.dot

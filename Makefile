run: helperFunctions.o vector.o packet.o NodeAndLink.o path.o  networkMesh.o simulation.o main.o
	g++ -o run helperFunctions.o vector.o packet.o  NodeAndLink.o path.o networkMesh.o simulation.o main.o

helperFunctions.o: helperFunctions.h
	g++ -c helperFunctions.cpp

vector.o: vector.h
	g++ -c vector.cpp

packet.o: packet.h
	g++ -c packet.cpp

NodeAndLink.o: NodeAndLink.h
	g++ -c NodeAndLink.cpp
 
path.o: path.h
	g++ -c path.cpp

networkMesh.h: networkMesh.h
	g++ -c networkMesh.cpp

simulation.o: simulation.h
	g++ -c simulation.cpp

main.o: vector.h packet.h path.h NodeAndLink.h networkMesh.h simulation.h
	g++ -c main.cpp 

clean:
	rm *.gch *.o run 
	git rm -r *.o

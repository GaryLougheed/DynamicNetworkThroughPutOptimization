run: helperFunctions.o vector.o packet.o networkNode.o networkMesh.o simulation.o main.o
	g++ -o run helperFunctions.o vector.o packet.o networkNode.o networkMesh.o simulation.o main.o

helperFunctions.o: helperFunctions.h
	g++ -c helperFunctions.cpp

vector.o: vector.h
	g++ -c vector.cpp

packet.o: packet.h
	g++ -c packet.cpp

networkNode.o: networkNode.h
	g++ -c networkNode.cpp

networkMesh.o: networkMesh.h
	g++ -c networkMesh.cpp

simulation.o: simulation.h
	g++ -c simulation.cpp

main.o: vector.h packet.h networkNode.h networkMesh.h simulation.h
	g++ -c main.cpp 

clean:
	rm *.o run 

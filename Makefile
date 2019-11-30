run: helperFunctions.o vector.o packet.o path.o link.o networkNode.o networkMesh.o simulation.o main.o
	g++ -o run helperFunctions.o vector.o packet.o path.o link.0 networkNode.o  networkMesh.o simulation.o main.o

helperFunctions.o: helperFunctions.h
	g++ -c helperFunctions.cpp

vector.o: vector.h
	g++ -c vector.cpp

packet.o: packet.h
	g++ -c packet.cpp

path.o: path.h
	g++ -c path.cpp

link.o: link.h
	g++ -c link.cpp

networkNode.o: networkNode.h
	g++ -c networkNode.cpp

networkMesh.o: networkMesh.h
	g++ -c networkMesh.cpp

simulation.o: simulation.h
	g++ -c simulation.cpp

main.o: vector.h packet.h networkNode.h path.h networkMesh.h simulation.h
	g++ -c main.cpp 

clean:
	rm *.o run 
	git rm -r *.o

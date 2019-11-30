// Simulation Class

// Encapsulates the networking mesh and networking nodes



// Header files
  // network mesh.h

#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <cstdlib>
#include <ctime>
#include "networkMesh.h"



class Simulation
{

  public: 
   Simulation();
   // run funtion
   void GenerateInitialNetwork(int numberOfNodes);
   void RunSimulation(int numberOfHops);
   void PacketGenerator();
   // GetStats
   void DisplayStats();
   // send packets
   // access registry
   bool manipulateNetworkMesh(int option, int parameter1, int parameter2);
   //simulation will keep track of node ID assigned
   void incrementNodeID();

   //  
   
  private:
    NetworkMesh m_mesh;
    int totalHops;
    int totalPacketsPassed;
    int numberNodesAtStart;
    int totalNodesAdded;
    int totalNodesRemoved;
    int currentNodeID; 

};



#endif

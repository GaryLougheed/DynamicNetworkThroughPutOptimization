// Simulation Class

// Encapsulates the networking mesh and networking nodes



// Header files
  // network mesh.h

#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "networkMesh.h"
#include "packet.h"



class Simulation
{

  public: 
   Simulation();
   // run funtion
   void GenerateInitialNetwork(int numberOfNodes);
   void RunSimulationByPackets(int numberOfPacketsToSend);
   void RunSimulationByTime(int numberOfSeconds);
   void PacketGenerator();
   // GetStats
   void DisplayStats();
   // send packets
   // access registry
   bool manipulateNetworkMesh(int option, int parameter1, int parameter2);
   //simulation will keep track of node ID assigned
   void incrementNodeID();
   bool sendPacket(Packet packetToSend, int nodeID);
   void listNetworkNodes();

   //  
   
  private:
    NetworkMesh m_mesh;
    vector<Packet> newPackets;
    vector<Packet> sentPackets;
    Packet packetLauncher;
    Packet finishedPacket;
    int totalHops;
    int totalPacketsPassed;
    int numberNodesAtStart;
    int totalNodesAdded;
    int totalNodesRemoved;
    int currentNodeID; 

};



#endif

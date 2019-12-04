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
<<<<<<< Updated upstream
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
=======
     // access registry
     bool sendPackets();

   // build simulation
   /*
     Name: Build Simulation
     Input: none
     Output: true or false if the build becomes invalid or valid completely. 
     Process: Ask the user to add packets to the simulation. Must use valid nodes within the node reg. In Order to build a packet we must first build the node mesh.
     Dependancies: Classes: NetworkMesh NetworkNode Packet Libraries: fstream iostream 
   */
     bool buildSimulation();  


   /*
     Name:
     Input:
     Output:
     Process:
     Dependancies:
   */
     bool packetBuilder();

   // packet generation
     bool packetGenerator();
  
   // Add node to mesh.
     bool addNodeToMesh(const NetworkNode& node);

   // Establish Link within Mesh
     bool establishLink(int& src, int& dest);

   // Function to read network mesh from file
   // This function assumes that file is written correctly and is named simFile.txt
     void buildMeshFromFile();
     
   // Remove node from mesh
 
    // Output the simulation. 
   friend ostream& operator<<(ostream&, const Simulation&);
>>>>>>> Stashed changes

};



#endif

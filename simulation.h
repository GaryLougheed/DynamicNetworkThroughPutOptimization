// Simulation Class

// Encapsulates the networking mesh and networking nodes



// Header files
  // network mesh.h

#ifndef SIMULATION_H_
#define SIMULATION_H_


#include "networkMesh.h"
#include <iostream>
using namespace std;

class Simulation;
ostream& operator<<(ostream&, const Simulation&);



/*
  Class Name: Simulation
  Class Assumptions: All nodes will be able to report to a master node at a throughput faster than any other throughput in the network. This allows the master node to be able to turn the throughput of the entire network down to a safer level.
  Class Description: The simulation will access a network mesh. This mesh will accept the packets from the packet send buffer built by the buildSimulation function.
  Class Parameters: The primary data members are the network mesh, time_t a time tracker for the termination of a simulation, time_t for the current time, and packet send buffer. 
  Class Methods: The class uses methods to access the network mesh. The simulation builds a run time 
                 environment that is built up by send packet components. The routing method for the
                 simulation uses Dynamic Source Routing to obtain the maximum throughput for a send.
  Class Interactions: The simulation interacts with the main driver and the network mesh. These interactions 
                      contribute to the statistics developed from the packets sent through the network by the
                      simulation. It is important to remember that the simulation must run in real time.
*/

class Simulation
{

  private:
    NetworkMesh* m_mesh;
    Packet* m_sendBuffer;
    int m_currentPackets;
    int m_maxPackets;
    time_t m_currTime; 
    time_t m_termTime;
 
  public: 
   // Constructor
     Simulation();

   // Copy Constructor
     Simulation(const Simulation& sim);

   // Destructor
     ~Simulation();

   // getter
     NetworkMesh getNetworkMesh()const; 
     int getCurrentPackets()const;
     int getMaxPackets()const;
     time_t getCurrentTime()const;
     time_t getTerminationtime()const;
     
   // run funtion
     bool run();

   // update function
     bool update(time_t delta);

   // GetStats
             
   // send packets
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
     bool addNodeToMesh();

   // Establish Link within Mesh
     bool establishLink(int& src, int& dest);

   // Remove node from mesh
 
    // Output the simulation. 
   friend ostream& operator<<(ostream&, const Simulation&);

};



#endif

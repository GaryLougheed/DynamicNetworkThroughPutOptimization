// Simulation Class

// Encapsulates the networking mesh and networking nodes



// Header files
  // network mesh.h

#ifndef SIMULATION_H_
#define SIMULATION_H_


#include "networkMesh.h"

class Simulation;


ostream& operator<<(ostream&, const Simulation&);

class Simulation
{

  private:
    NetworkMesh* m_mesh;
     
  public: 
   // Constructor
     Simulation();

   // Copy Constructor
     Simulation(const Simulation& sim);

   // Destructor
     ~Simulation();

   // getter
     NetworkMesh getNetworkMesh()const; 

   // run funtion
     bool run();

   // GetStats
      
   // send packets
     // access registry
     bool sendPacket();

   //  
   
     
   friend ostream& operator<<(ostream&, const Simulation&);

};



#endif

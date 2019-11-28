#include "simulation.h"

Simulation::Simulation()
{

  m_mesh = new NetworkMesh(10);

}

Simulation::Simulation(const Simulation& mesh)
{

}

Simulation::~Simulation()
{
  delete []m_mesh;
  m_mesh = NULL;
}

bool Simulation::run()
{

  //cout << *this;

  return false;
}

bool Simulation::sendPacket()
{
  return false;
}

NetworkMesh Simulation::getNetworkMesh()const
{
  return *m_mesh;
}

ostream& operator<<(ostream& os, const Simulation& sim)
{

   os << "Simulation Data: " << '\n';
   os << "Network Mesh Data: " << sim.getNetworkMesh() << '\n';


  return os;
}

#include "packet.h"

Packet::Packet()
{

  m_srcID = 0;
  m_destID = 0;
  m_data = 4849386;
  m_timeTraversed = 0;
  m_TTL = 10;
  m_maxHops = 10;
  m_currNumOfHops = 0;
  nodesTravelled = new int[m_maxHops];

}

Packet::~Packet()
{



}

Packet::Packet(const Packet& rhs)
{

  m_srcID = rhs.m_srcID;
  m_destID = rhs.m_destID;
  m_data = rhs.m_data;
  m_timeTraversed = rhs.m_timeTraversed;
  m_TTL = rhs.m_TTL;
  m_maxHops = rhs.m_maxHops;

}

int Packet::getSrcId()const
{
  return m_srcID;
}

int Packet::getDestId()const
{

  return m_destID;
}

int Packet::getData()const
{

  return m_data;
}

int Packet::getTimeTraversed()const
{
  return m_timeTraversed;
}

int Packet::getTTL()const
{

  return m_TTL;
}

int Packet::getMaxHops()const
{
  return m_maxHops;
}

void Packet::setTimeTraversed(const int& updateValue)
{
  m_timeTraversed+= updateValue;
}

void Packet::setSrcId(const int& val)
{
  m_srcID = val;
}

void Packet::setDestId(const int& val)
{
  m_destID = val;
}

void Packet::setData(const int& val)
{
  m_data = val;
}

void Packet::setMaxHops(const int& val)
{
  m_maxHops = val;
}

void Packet::setTTL(const int& val)
{
  m_currNumOfHops = val;
}

void Packet::addNodeToTraversalList(const int& val)
{

  m_currNumOfHops++;

  nodesTravelled[m_currNumOfHops] = val; 

}

void Packet::addHopCount(const int& val)
{

  m_currNumOfHops++;

}







Packet& Packet::operator=(const Packet& rhs)
{

  if( this != &rhs)
  {
    m_srcID = rhs.m_srcID;
    m_destID = rhs.m_destID;
    m_data = rhs.m_data;
    m_timeTraversed = rhs.m_timeTraversed;
    m_TTL = rhs.m_TTL;
    m_maxHops = rhs.m_maxHops;

  }

 
  return *this;
}


ostream& operator<<(ostream& os, const Packet& packet)
{
  os << '\n';
  os << "Packet source ID: " << packet.getSrcId() << '\n';
  os << "Packet destination ID: " << packet.getDestId() << '\n';
  os << "Packet data: " << packet.getData() << '\n';
  os << "Packet Time traversed: " << packet.getTimeTraversed() << '\n';
  os << "Max Hops: " << packet.getMaxHops() << '\n';
  os << "Nodes Traversed: " << "Empty for meow";
  os << "Packet Time to Live: " << packet.getTTL() << '\n'; 
  
  return os;
}

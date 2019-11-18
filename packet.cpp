#include "packet.h"

Packet::Packet()
{

  m_srcID = 0;
  m_destID = 0;
  m_data = 4849386;
  m_timeTraversed = 0;
  m_TTL = 10;
  m_maxHops = 10;


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

}

int Packet::getTTL()const
{

  return m_TTL;
}

int Packet::getMaxHops()const
{
  return m_maxHops;
}

ostream& operator<<(ostream& os, const Packet& packet)
{
  os << '\n';
  os << "Packet source ID: " << packet.getSrcId() << '\n';

  return os;
}

#include "packet.h"

Packet::Packet()
{

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

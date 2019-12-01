#include "packet.h"

Packet::Packet()
{
}

Packet::~Packet()
{
}

Packet::Packet(const Packet &rhs)
{

  m_srcID = rhs.m_srcID;
  m_destID = rhs.m_destID;
  m_data = rhs.m_data;
  m_timeTraversed = rhs.m_timeTraversed;
  m_TTL = rhs.m_TTL;
  m_maxHops = rhs.m_maxHops;
}

int Packet::getPriority(
    // no parameters
)
{
  return m_priority;
}

void Packet::sendToNode(
    Node *nodeLocation)
{
  if (currentNode != nodeLocation)
  {
    currentNode = nodeLocation;
  }
}

bool Packet::atDestination(
    // no parameters
)
{
  if (currentNode == destination)
  {
    return true;
  }

  else
  {
    return false;
  }
}

size_t Packet::getSrcID() const
{

  return m_srcID;
}

size_t Packet::getMaxNumOfNodes() const
{
  return m_data;
}

Path Packet::getTimeTraversed() const
{
  return m_timeTraversed;
}

Path Packet::getTTL() const
{
  return m_TTL;
}

Path Packet::getMaxHops() const
{
  return m_maxHops;
}

size_t Packet::setSrcID() const
{

  return m_srcID;
}

size_t Packet::setMaxNumOfNodes() const
{
  return m_data;
}

Path Packet::setTimeTraversed() const
{
  return m_timeTraversed;
}

Path Packet::setTTL() const
{
  return m_TTL;
}

Path Packet::setMaxHops() const
{
  return m_maxHops;
}
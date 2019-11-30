#include "link.h"

Link::Link()
{

  // Declare and Initialize variables
  m_throughput = 0;
  m_dest = NULL;

}

Link::Link(const Link& rhs)
{
  if(this != rhs)
  {
    m_throughput = rhs.m_throughput;
    m_dest = rhs.m_dest;
  }
 
}

Link::~Link()
{
  m_dest = NULL;
  m_throughput = 0;
}

Link& Link::operator=(const Link& rhs)
{
  // declare and initialize variabels

  if( this != rhs)
  {
    m_throughput = rhs.m_throughput;
    m_dest = rhs.m_dest;
  }
 
}

int Link::getThroughput()const
{

  return m_throughput;
}

NetworkNode* Link::getLink()const
{
  return m_dest;
}


ostream& operator<<(ostream& os, const Link& rhs)
{

  if( rhs.m_dest != NULL)
     os << "Dest Node is : " << *m_dest << '\n';
     os << "Links Throughput: " << m_throughput << '\n';
  return os;
}

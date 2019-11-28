#include "link.h"

Link::Link()
{

}

Link::Link(const Link& rhs)
{

 
}

Link::~Link()
{

}

Link& Link::operator=(const Link& rhs)
{
  // declare and initialize variabels

}

int Link::getThroughput()const
{

  return m_throughput;
}

ostream& operator<<(ostream& os, const Link& rhs)
{
  return os;
}

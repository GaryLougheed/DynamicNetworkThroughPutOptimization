#ifndef _LINK_H_
#define _LINK_H_

#include <iostream>
#include "networkNode.h"
using namespace std;


class NetworkNode;

class Link;
ostream& operator<<(ostream&, const Link&);

class Link
{
  private:
    int m_throughput;
    NetworkNode* m_dest;

  public:
   // constructor
     Link();

   // parameterized constructor
     // none;

   // copy constructor
     Link(const Link& rhs);

   // assignment operator
     Link& operator=(const Link& rhs);

   // destructor
     ~Link();

   // Getters and Setters
     int getThroughPut()const;

   // overloaded operators
     friend ostream& operator<<(ostream&, const Link&);
  
};

#endif

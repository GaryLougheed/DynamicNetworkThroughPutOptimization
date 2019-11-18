#ifndef PACKET_H_
#define PACKET_H_


// Header files
#include <iostream>

using namespace std;

// Global constants

// Class Prototypes
class Packet;

ostream& operator<<(ostream&, const Packet&);


class Packet { 

  private:
    // header 
    int m_srcID;
    int m_destID;
    int m_data;
    int m_timeTraversed;
    int m_TTL;
    int m_maxHops;

  public:
    Packet();
    Packet(const Packet& rhs);
    ~Packet();
    
    // setters and getters
    int getSrcId()const;
    int getDestId()const;
    int getData()const;
    int getTimeTraversed()const;
    int getTTL()const;
    int getMaxHops()const;
  




    friend ostream& operator<<(ostream&, const Packet& );


};

#endif

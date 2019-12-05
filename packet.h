#ifndef PACKET_H_
#define PACKET_H_


// Header files
#include <iostream>
#include "helperFunctions.h"
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
    int m_currNumOfHops;
    int* nodesTravelled;

  public:
    Packet();
    Packet(const Packet& rhs);
    ~Packet();
    
    // setters and getters
    void setTimeTraversed(const int& updateValue);
    void setSrcId(const int& val);
    void setDestId(const int& val);
    void setData(const int& val);        
    void setMaxHops(const int& val);
    void setTTL(const int& val);
    void addNodeToTraversalList(const int& val);
    void addHopCount(const int& val); 


    int getSrcId()const;
    int getDestId()const;
    int getData()const;
    int getTimeTraversed()const;
    int getTTL()const;
    int getMaxHops()const;
    int* getNodesTraversed()const;
    int getHops()const;
 
    Packet& operator=(const Packet& rhs);



    friend ostream& operator<<(ostream&, const Packet& );


};

#endif

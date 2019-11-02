

#ifndef NETWORKNODE_H_ 
#define NETWORKNODE_H_

#include "vector.h"
#include "packet.h"
#include <iostream>
using namespace std;




class NetworkNode
{

  private:
    NetworkNode* m_links;
    int m_bufferSize;
    bool m_wifiEnabled;
    double m_throughput;
    double m_processingDelay;
    double m_transmissionDelay;
    double m_queueDelay;
    double m_propagationDelay;
    double m_wifiRange;
    bool m_isIPV6;
    Packet m_packet;
    Vector m_location;
    // packet array

        
  public:
    // Constructor
    NetworkNode();
    // Copy Constructor
    NetworkNode(const NetworkNode& rhs); 
    // Destructor
    ~NetworkNode();
    // Assignment Operator
    NetworkNode operator=(const NetworkNode& rhs);
     




};

#endif

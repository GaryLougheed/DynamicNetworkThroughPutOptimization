

#ifndef NETWORKNODE_H_ 
#define NETWORKNODE_H_

#include "vector.h"
#include "packet.h"
#include "link.h"
#include <iostream>
using namespace std;



class NetworkNode;
ostream& operator<<(ostream&, const NetworkNode&);


class NetworkNode
{

  private:
    Link* m_links;
    int m_nodeId;
    int m_numOfLinks;
    int m_bufferSize;
    bool m_wifiEnabled;
    double m_throughput;
    double m_processingDelay;
    double m_transmissionDelay;
    double m_queueDelay;
    double m_propagationDelay;
    double m_wifiRange;
    bool m_isIPV6;
    Packet* m_packet;
    Vector* m_location;
    static int m_nodeIdProvider;
    // packet array

        
  public:
    // Constructor
      NetworkNode();

    // Copy Constructor
      NetworkNode(const NetworkNode& rhs); 

    // Destructor
      ~NetworkNode();

    // Assignment Operator
      NetworkNode& operator=(const NetworkNode& rhs);
     
    // Getters and Setters
      
      NetworkNode* getLink()const;
      int getNodeId()const;
      int getNumOfLinks()const;
      int getBufferSize()const;
      bool getWifiEnabled()const;
      double getThroughput()const;
      double getProcessingDelay()const;
      double getTransmissionDelay()const;
      double getQueueDelay()const;
      double getPropagationDelay()const;
      double getWifiRange()const;
      bool isIPV6()const;
      Packet getPacket()const;
      Vector getLocation()const;


      void setLink(const NetworkNode* ptr_otherNode);
      void setNumOfLinks(int numOfLinks); 
      void setBufferSize(int bufferSize);
      void setWifiEnabled(bool wifiSetting);
      void setThroughput(double throughput);
      void setProcessingDelay(double processingDelay);
      void setTransmissionDelay(double transmissionDelay);
      void setQueueDelay(double queueDelay);
      void setPropagationDelay(double propagationDelay);
      void setWifiRange(double wifiRange);
      void setIPV6(bool IPV6setting);
      void setPacket(Packet packet);
      void setLocation(Vector vector);

   // Calculate 

      void addLink(NetworkNode* node);
      bool removeLink(NetworkNode* node);
      bool removeLink(int linkID);

      friend ostream& operator<<(ostream& , const NetworkNode& );

};

#endif

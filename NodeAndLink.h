#ifndef _LINK_H_
#define _LINK_H_

#include "vector.h"
#include "packet.h"
#include <iostream>
#include <iostream>
using namespace std;



// Global constants
const int MAX_NUM_OF_LINKS = 3;


// A report contains an empty message or a yes! packet reached its end

class NetworkNode;
ostream& operator<<(ostream&, const NetworkNode&);

class Link;
ostream& operator<<(ostream&, const Link&);

class Link
{
  private:
    int m_throughput;
    NetworkNode* m_dest;
    bool m_inUse; 

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
     int getThroughput()const;
     NetworkNode* getLink()const;
     bool getInUse()const;


   // set destination to a node in the heap(dynamically allocated)
     void setDest(NetworkNode* node);

   // Change the status of the links in usage.
     void toggleInUse();

   // overloaded operators
     friend ostream& operator<<(ostream&, const Link&);
  
};





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
    time_t m_timeLived;
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
     
    // Getters 

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

   // Setters 
      void setNodeID(int nodeID)const;

      bool setLink(NetworkNode* ptr_otherNode);

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


   // Update 
     bool update(time_t delta);

   // Receive Packet
     bool rcvPacket(const Packet& pkt);

   // Send Packet
     bool sendPacket(const int& linkID);

   // Calculate 

      void addLink(NetworkNode* node);

      bool removeLink(NetworkNode* node);

      bool removeLink(int linkID);

      friend ostream& operator<<(ostream& , const NetworkNode& );

};

#endif
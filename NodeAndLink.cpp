#include "NodeAndLink.h"


int NetworkNode::m_nodeIdProvider = 0;

NetworkNode::NetworkNode()
{
  m_nodeIdProvider++;
  m_nodeId = m_nodeIdProvider;
  m_links = NULL;
  m_numOfLinks = 1;
  m_bufferSize = 100000000; // Typical Buffer size for a router is 10MB, via fasterdata.es.net
  m_wifiEnabled = false;
  m_throughput = 0;
  m_processingDelay = 0;
  m_transmissionDelay = 0;
  m_queueDelay = 0;
  m_propagationDelay = 0;
  m_wifiRange = 0;
  m_isIPV6 = false;
  m_packet = new Packet;
  m_location = new Vector(0,0,0);


}

NetworkNode::NetworkNode(const NetworkNode& rhs)
{
  int index = 0;

  if(this != &rhs)
  {

    m_nodeId = rhs.m_nodeId;

    if( rhs.m_links != NULL)
    {
      for(index = 0; index < rhs.m_numOfLinks; index++)
        m_links[index] = rhs.m_links[index];
    }

    m_numOfLinks = 1;
    m_bufferSize = 100000000; // Typical Buffer size for a router is 10MB, via fasterdata.es.net
    m_wifiEnabled = false;
    m_throughput = 0;
    m_processingDelay = 0;
    m_transmissionDelay = 0;
    m_queueDelay = 0;
    m_propagationDelay = 0;
    m_wifiRange = 0;
    m_isIPV6 = false;
   
    m_packet = new Packet;
    m_location = new Vector(0,0,0);
  }

}

NetworkNode::~NetworkNode()
{
  if(m_location != NULL)
  {
    delete m_location;
    m_location = NULL;
  }

  if( m_packet != NULL)
  {
    delete m_packet;
    m_packet = NULL;
  }
  
  if( m_links != NULL)
  {
    delete []m_links;
    m_links = NULL;
  }


}

NetworkNode& NetworkNode::operator=(const NetworkNode& rhs)
{
  // Declare and Initialize variables

  // Check to see if there exists reduant assignment
    if( this != &rhs) 
    {
      // iterate through the rhs and assign the links

    }
  // return chain operation

    return *this;
}

NetworkNode* NetworkNode::getLink()const
{
  return NULL;
}
int NetworkNode::getNodeId()const
{
  return m_nodeId;
} 
int NetworkNode::getNumOfLinks()const
{
  return 0;
}

int NetworkNode::getBufferSize()const
{

  return 0;
}

bool NetworkNode::getWifiEnabled()const
{
  return false;
}

double NetworkNode::getThroughput()const
{
  return 0.0;
}

double NetworkNode::getProcessingDelay()const
{

  return 0.0;
}

double NetworkNode::getTransmissionDelay()const
{
  return 0.0;
}

double NetworkNode::getQueueDelay()const
{

  return 0.0;
}

double NetworkNode::getPropagationDelay()const
{

  return 0.0;
}

double NetworkNode::getWifiRange()const
{

  return 0.0;
}

bool NetworkNode::isIPV6()const
{

  return false;
}

Packet NetworkNode::getPacket()const
{
  if( m_packet != NULL)
    return *m_packet;
  
}

Vector NetworkNode::getLocation()const
{ 
  if( m_location!= NULL)
    return *m_location;
}

void NetworkNode::setLink(const NetworkNode* ptr_otherNode)
{

}

void NetworkNode::setNumOfLinks(int numOfLinks)
{

}

void NetworkNode::setBufferSize(int bufferSize)
{

}

void NetworkNode::setWifiEnabled(bool wifiSetting)
{

}

void NetworkNode::setThroughput(double throughput)
{

}

void NetworkNode::setProcessingDelay(double processingDelay)
{

}

void NetworkNode::setTransmissionDelay(double transmissionDelay)
{

}

void NetworkNode::setQueueDelay(double queueDelay)
{

}

void NetworkNode::setPropagationDelay(double propagationDelay)
{

}

void NetworkNode::setWifiRange(double wifiRange)
{

}

void NetworkNode::setIPV6(bool IPV6setting)
{

}

void NetworkNode::setPacket(Packet packet)
{

}

void NetworkNode::setLocation(Vector vector)
{

}

void NetworkNode::addLink(NetworkNode* node)
{

}

bool NetworkNode::removeLink(NetworkNode* node)
{
  return false;
}

bool NetworkNode::removeLink(int linkIdD)
{
  return false;
}

ostream& operator<<(ostream& os, const NetworkNode& node)
{
  os << '\n';
  os << "Network Node identifier: " << node.getNodeId() << '\n';
  os << "Node Throughput: " << node.getThroughput() << '\n';
  os << "Number of Links: " << node.getNumOfLinks() << '\n';

  os << "Buffer Size: " << node.getBufferSize() << '\n';
  os << "Wifi Enabled: " << node.getWifiEnabled() << '\n';
  os << "Processing Delay: " << node.getProcessingDelay() << '\n';
  os << "Transmission Delay: " << node.getTransmissionDelay() << '\n';
  os << "Queue Delay: " << node.getQueueDelay() << '\n';
  os << "Propagation Delay: " << node.getPropagationDelay() << '\n';
  os << "Wifi Range: " << node.getWifiRange() << '\n';
  os << "IPV6: " << node.isIPV6();
  os << "Current Packet contents: " << node.getPacket() << '\n';
  os << "Router location: " << node.getLocation() << '\n';


  return os;
}



Link::Link()
{

  // Declare and Initialize variables
  m_throughput = 0;
  m_dest = NULL;

}

Link::Link(const Link& rhs)
{
  if(this != &rhs)
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

  if( this != &rhs)
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
     os << "Dest Node is : " << *(rhs.getLink()) << '\n';
     os << "Links Throughput: " << rhs.getThroughput()<< '\n';
  return os;
}

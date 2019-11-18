#include "networkNode.h"

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
  if(this != &rhs)
  {
    return *this;
  }

}

NetworkNode::~MetworkNode()
{

}

NetworkNode NetworkNode::operator=(const NetworkNode& rhs)
{

}

NetworkNode* NetworkNode::getLink()const
{
  return NULL;
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
  return *m_packet;
}

Vector NetworkNode::getLocation()const
{
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






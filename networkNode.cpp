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

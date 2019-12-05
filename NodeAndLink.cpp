#include "NodeAndLink.h"


NetworkNode::NetworkNode()
{
  m_nodeId = 0;
  m_links = new Link[MAX_NUM_OF_LINKS];
  m_numOfLinks = 0;
  m_bufferSize = 100000000; // Typical Buffer size for a router is 10MB, via fasterdata.es.net
  m_wifiEnabled = false;
  m_throughput = 0;
  m_processingDelay = 0;
  m_transmissionDelay = 0;
  m_queueDelay = 0;
  m_propagationDelay = 0;
  m_wifiRange = 0;
  m_isIPV6 = false;
 
  m_timeLived = 0;

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

    m_numOfLinks = rhs.m_numOfLinks;
    m_bufferSize = rhs.m_bufferSize; // Typical Buffer size for a router is 10MB, via fasterdata.es.net
    m_wifiEnabled = rhs.m_wifiEnabled;
    m_throughput = rhs.m_throughput;
    m_processingDelay = rhs.m_processingDelay;
    m_transmissionDelay = rhs.m_transmissionDelay;
    m_queueDelay = rhs.m_queueDelay;
    m_propagationDelay = rhs.m_propagationDelay;
    m_wifiRange = rhs.m_wifiRange;
    m_isIPV6 = rhs.m_isIPV6;
    m_timeLived = rhs.m_timeLived;
    
    if( rhs.m_packet != NULL)
    {
      m_packet = new Packet;
      *m_packet = *(rhs.m_packet);
    }
    else
      m_packet = NULL;
    
    if( rhs.m_location != NULL)
    { 
      m_location = new Vector(0,0,0);
      *m_location = *(rhs.m_location);
    }
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
  int index = 0;

  // Check to see if there exists reduant assignment
    if( this != &rhs) 
    {
      // iterate through the rhs and assign the links


    m_nodeId = rhs.m_nodeId;

    if( rhs.m_links != NULL)
    {
      for(index = 0; index < rhs.m_numOfLinks; index++)
        m_links[index] = rhs.m_links[index];
    }

    m_numOfLinks = rhs.m_numOfLinks;
    m_bufferSize = rhs.m_bufferSize; // Typical Buffer size for a router is 10MB, via fasterdata.es.net
    m_wifiEnabled = rhs.m_wifiEnabled;
    m_throughput = rhs.m_throughput;
    m_processingDelay = rhs.m_processingDelay;
    m_transmissionDelay = rhs.m_transmissionDelay;
    m_queueDelay = rhs.m_queueDelay;
    m_propagationDelay = rhs.m_propagationDelay;
    m_wifiRange = rhs.m_wifiRange;
    m_isIPV6 = rhs.m_isIPV6;
    m_timeLived = rhs.m_timeLived;
    
    if( rhs.m_packet != NULL)
    {
      m_packet = new Packet;
      *m_packet = *(rhs.m_packet);
    }
    else
      m_packet = NULL;
    
    if( rhs.m_location != NULL)
    { 
      m_location = new Vector(0,0,0);
      *m_location = *(rhs.m_location);
    }
   }    
  // return chain operation

    return *this;
}

NetworkNode* NetworkNode::getLink(const int& linkId)const
{
  // 

    return m_links[linkId].getDest(); 
 
  //


  return NULL;
}

int NetworkNode::getNodeId()const
{
  return m_nodeId;
} 
int NetworkNode::getNumOfLinks()const
{
  return m_numOfLinks;
}

int NetworkNode::getBufferSize()const
{

  return m_bufferSize;
}

bool NetworkNode::getWifiEnabled()const
{
  return m_wifiEnabled;
}

double NetworkNode::getThroughput()const
{
  // TODO: One throughput for each node for testing.
  return m_throughput;
}

double NetworkNode::getProcessingDelay()const
{

  return m_processingDelay;
}

double NetworkNode::getTransmissionDelay()const
{
  return m_transmissionDelay;
}

double NetworkNode::getQueueDelay()const
{

  return m_queueDelay;
}

double NetworkNode::getPropagationDelay()const
{

  return m_propagationDelay;
}

double NetworkNode::getWifiRange()const
{

  return m_wifiRange;
}

bool NetworkNode::isIPV6()const
{

  return m_isIPV6;
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

void NetworkNode::setNodeID(const int& val)
{
  m_nodeId = val;
}

void NetworkNode::setNumOfLinks(int numOfLinks)
{
  m_numOfLinks = numOfLinks; 
}

void NetworkNode::setBufferSize(int bufferSize)
{
  m_bufferSize = bufferSize;
}

void NetworkNode::setWifiEnabled(bool wifiSetting)
{
  m_wifiEnabled = wifiSetting;
}

void NetworkNode::setThroughput(double throughput)
{
  m_throughput = throughput;
}

void NetworkNode::setProcessingDelay(double processingDelay)
{
  m_processingDelay = processingDelay;
}

void NetworkNode::setTransmissionDelay(double transmissionDelay)
{
  m_transmissionDelay = transmissionDelay;
}

void NetworkNode::setQueueDelay(double queueDelay)
{
  m_queueDelay = queueDelay;
}

void NetworkNode::setPropagationDelay(double propagationDelay)
{
  m_propagationDelay = propagationDelay;
}

void NetworkNode::setWifiRange(double wifiRange)
{
  m_wifiRange = wifiRange;
}

void NetworkNode::setIPV6(bool IPV6setting)
{
  m_isIPV6 = IPV6setting;
}

void NetworkNode::setPacket(Packet packet)
{
  *m_packet = packet;
}

void NetworkNode::setLocation(Vector vector)
{
   *m_location = vector;
}

bool NetworkNode::update(time_t delta)
{

  // Declare and Intialize variables
    int linkIndex = 0;

  // update time 
    m_timeLived+=delta;

 
  // Check to see if we can send a packet 
    if( m_packet != NULL )
    {

      // Check to see if a link is available if yes send on that link and link is unmarked
        for(linkIndex = 0; linkIndex < m_numOfLinks; linkIndex++)
        {
          if(!m_links[linkIndex].getInUse())
          {
            // send packet on link only if the there is a time sync.
              // We obtain throughput here because throughput indicates how much time
               // it will take to send one standard unit packet. 
              if(m_timeLived > m_links[linkIndex].getThroughput() + m_packet->getTimeTraversed())
              {

                // toggle in use to true.
                  m_links[linkIndex].toggleInUse();

                // send Packet src to dest.
                  return sendPacket(linkIndex);
              }
          }
        }

     }

        // A packet send means we have to decrease the packets in the buffer


    /*     Once all links have sent a packet then the links are unmarked and the packet leaves the node
          Occurs in link depletition.
     If all links have been marked for a packet then empty the link marks.*/

        // If a send reports true then a rcv was true, these truths mean that the packet was received at dest. //TODO: error handling at the send receive level.

 



  return false;
}

bool NetworkNode::rcvPacket(Packet* pkt)
{
//TODO function parameters
  // Declare and initialize variables

  // Add a packet to the packet buffer
    // TODO: Network is built on one packet send test drive.
    // The buffer is of size on packet for this simulation.
    // all nodes clear there buffer after one successful send.
    if( m_packet == NULL)
    {
      *m_packet = *pkt;
      //*m_packet.addNodeIntoPath();
    }
 
    // TODO Queueing buffer

    
 
  // Check to see if the packet has reached its destination.

  return false;
}

bool NetworkNode::sendPacket(const int& linkID)
{

  // Declare and Initialize variables

  // Send packet on link.
    // Link is assumed to be toggle prior to function call: TODO proper toggling occurance.
    // mark link as sent.
      if( m_links[linkID].getDest()->rcvPacket(m_packet))
      { 
        m_packet->setTimeTraversed(m_links[linkID].getThroughput());
        m_links[linkID].toggleInUse();
        m_packet = NULL;
        return true;
      } 


  // call rcv on the dest node of the link.
    // this rcv will report to the node mesh that the packet has reached its end.
      //return (rvc());
        m_links[linkID].toggleInUse();
        m_packet = NULL;

  return false;
}

void NetworkNode::addLink(NetworkNode* ptr_otherNode)
{

  // Declare and Initialize variables
    int index = m_numOfLinks; 
    
  // Check if we can add a link to the node
    if(m_numOfLinks <= MAX_NUM_OF_LINKS) 
    {
      // if we can add a link to the node 
      // if ptr_otherNode is null then do not add link 
        if( ptr_otherNode != NULL)
        {
         switch(m_numOfLinks)
         {
           case '0':
                 m_links[index].setDest(ptr_otherNode);
                 m_numOfLinks++;
                 break;

           case '1':
                 m_links[index].setDest(ptr_otherNode);
                 m_numOfLinks++;
                 break;

           case '2':
                 m_links[index].setDest(ptr_otherNode);
                 m_numOfLinks++;
                 break;
         }
        } 
      // increment the number of links this node has.
    }
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
  m_inUse = false;

}

Link::Link(const Link& rhs)
{
  if(this != &rhs)
  {
    m_throughput = rhs.m_throughput;
    m_dest = rhs.m_dest;
    m_inUse = rhs.m_inUse;
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
    m_inUse = rhs.m_inUse;
  }
 
}

int Link::getThroughput()const
{

  return m_throughput;
}

NetworkNode* Link::getDest()const
{
  return m_dest;
}

bool Link::getInUse()const
{

  return m_inUse;
}

void Link::setDest(NetworkNode* node)
{
  // Declare and Initialize variables

  // set destination, null if not in use.
     m_dest = node; 
}

void Link::toggleInUse()
{

  if(m_inUse == true)
    m_inUse = false;
  else
    m_inUse = true;

}

ostream& operator<<(ostream& os, const Link& rhs)
{

  if( rhs.m_dest != NULL)
     os << "Dest Node is : " << *(rhs.getDest()) << '\n';
     os << "Links Throughput: " << rhs.getThroughput()<< '\n';
  return os;
}

#include "simulation.h"

Simulation::Simulation()
{
    currentNodeID = 0;
}

void GenerateInitialNetwork(int numberOfNodes) 
{
    bool flag;
    

    if(numberOfNodes > m_mesh.getMaxNumOfNodes())
    {
        numberOfNodes = m_mesh.getMaxNumOfNodes();
    }

    for(int i = 0; i < numberOfNodes; i++)
    {
       flag = m_mesh.addNode(incrementNodeID());
       if(flag == false)
       {
           //throw error here
       }
    }

    //generate random links
    bool flagLinkNodes;
    int density = 10;
    int firstNodeID;
    int secondNodeID;
    int dice;

<<<<<<< Updated upstream
    srand(time(NULL));
=======
  // link the nodes if they exist in the node registry.
  
     m_mesh->linkNodes(src,dest);
      
    //  

  // function stubb
  return false;
}


bool Simulation::packetGenerator()
{
   // Declare and Initialize variables
   srand(time(NULL));
   Packet newPacket;
   int srcNode;
   int destNode;
   int flag = false
     // Randomize Src and Dest
     while(flag == false)
     {
        srcNode = m_mesh->nodeRegistry[rand() % m_mesh.getCurrentNumOfNodes()].getNodeId();
        destNode = m_mesh->nodeRegistry[rand() % m_mesh.getCurrentNumOfNodes()].getNodeId();
        if(srcNode != destNode)
        {
          flag = truel
        }
     }

     //still need access to setters
     // Randomize data

     // Randomize unique packet characteristics
>>>>>>> Stashed changes

    for(int nodeSelection = 0; nodeSelection < numberOfNodes; nodeSelection++)
    {
        for(int nodeToLinkTo = nodeSelection; nodeToLinkTo < numberOfNodes; nodeToLinkTo++)
        {
            firstNodeID = m_mesh->m_nodeRegistry[nodeSelection].getNodeID();
            secondNodeID = m_mesh->m_nodeRegistry[nodeToLinkTo].getNodeID();
            if( m_mesh->m_nodeRegistry[nodeSelection].getNumOfLinks() == 3 || m_mesh->m_nodeRegistry[nodeToLinkTo].getNumOfLinks() == 3)
            {
                //do nothing if one of the nodes already have too many links
                continue;
            }
            else
            {
                dice = (rand() % 100) + 1;
                //the fewer nodes, the higher probablity that chosen nodes will be connected together
                if(dice < (density + (100 / m_mesh.getCurrentNumOfNodes)) )
                {
                    flagLinkNodes = m_mesh.linkNodes(firstNodeID,secondNodeID);
                    if(flag == true)
                    {
                        //ask gary about this, he may be taking car of this inside linkNodes function
                        m_mesh->m_nodeRegistry[nodeSelection].setNumOfLinks() == m_mesh->m_nodeRegistry[nodeSelection].getNumOfLinks() + 1;
                        m_mesh->m_nodeRegistry[nodeToLinkTo].setNumOfLinks() == m_mesh->m_nodeRegistry[nodeToLinkTo].getNumOfLinks() + 1;
                    }
                }
            }
            
        }   
    }

    //generate specifications of each node
    for(int nodeSelection = 0; nodeSelection < numberOfNodes; nodeSelection++)
    {
        //dont forget to set variables after discussion
        m_mesh->m_nodeRegistry[nodeSelection].setBufferSize(1);
        m_mesh->m_nodeRegistry[nodeSelection].setWifiEnabled(false);
        m_mesh->m_nodeRegistry[nodeSelection].setThroughput(1);
        m_mesh->m_nodeRegistry[nodeSelection].setProcessingDelay(1);
        m_mesh->m_nodeRegistry[nodeSelection].setTransmissionDelay(1);
        m_mesh->m_nodeRegistry[nodeSelection].setQueueDelay(1);
        m_mesh->m_nodeRegistry[nodeSelection].setPropagationDelay(1);
        m_mesh->m_nodeRegistry[nodeSelection].setWifiRange(1);
        m_mesh->m_nodeRegistry[nodeSelection].setIPV6(false);
    }
}

void RunSimulationByPackets(int numberOfPacketsToSend) 
{
    int packetsSent = 0;

    while(packetsSent < numberOfPacketsToSend)
    {
        //check if newpacket container has packets
            //if not, create more packets
        
        //pop off packet from new container to packetlauncher

        //generate path that is at least 2 hops long
        //let packet propagate through network

        //place finished packet into finished packet variable
        //inspect for states

        //place packet into sent packet container
        packetsSent++
    }
}

void RunSimulationByTime(int numberOfSeconds)
{

}

void PacketGenerator()
{
    Packet newPacket;
}

void DisplayStats()
{
    //display final statistics of network simulation. Marcus has example output from pervious class
}

bool manipulateNetworkMesh(int option, int parameter1, int parameter2) 
{
    //add node to mesh if network mesh isn't full yet
    if(option == 1)
    {
        if(m_mesh.getCurrentNumberofNodes() < m_mesh.getMaxNumOfNodes())
        {
            int flag;
            flag = m_mesh.addNode(incrementNodeID());
            if(flag == true)
            {
                return true;
            }
        }
        else
        {
            return false;
        }
        
    }
    //delete node if there is more than three left. Mesh network size should never drop below 3 nodes.
    else if(option == 2)
    {
        if(m_mesh.getCurrentNumberofNodes() > 3)
        {
            int flag;
            flag = m_mesh.deleteNode(parameter1);
            if(flag == true)
            {
                return true;
            }
        }
        else
        {
            return false;
        }
    }
    //change node parameter
    else if(option == 3)
    {
        //access and change various network settings using get and set functions
    }
    //link together two specific nodes
    else if(option == 4)
    {
        if(linkNodes(parameter1, parameter2) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
    }
}

void incrementNodeID()
{
    currentNodeID++;
}

bool sendPacket(Packet packetToSend, int nodeID)
{
    //send packet from and to specific nodes
}

<<<<<<< Updated upstream
void listNetworkNodes()
{
    for(int i = 1; i <= m_mesh.getCurrentNumberofNodes(); i++)
    {
        std::cout << "Network Node #" << i << " ";
        std::cout << "Node ID: " << m_mesh->m_nodeRegistry[i].getNodeID() << " ";
        std::cout << "Links: " << m_mesh->m_nodeRegistry[i].getNumOfLinks() << " ";
        std::cout << "Throughput: " << m_mesh->m_nodeRegistry[i].getThroughput() << std::endl;
    }
}
=======

void Simulation::buildMeshFromFile()
{
    int numOfNodes;
    int numOfLinks;
    int tempInt;
    bool tempBool;
    double tempDouble;
    NetworkNode temp;
    ifstream simFile;

    //open the file and extract number of nodes in mesh
    simFile.open("simFile.txt");
    simFile.ignore(256, ':');
    simFile >> numOfNodes;

    //loop through for each node in file
    for(int i = 0; i < numOfNodes; i++)
    {
        //set node ID
        simFile.ignore(256, ':');
        simFile >> tempInt;
        temp.setNodeID(tempInt);
        //set number of links;
        simFile.ignore(256, ':');
        simFile >> numOfLinks;
        temp.setNumOfLinks(numOfLinks);
        //set wifi feature
        simFile.ignore(256, ':');
        simFile >> tempBool;
        temp.setWifiEnabled(tempBool);
        //set processing delay
        simFile.ignore(256, ':');
        simFile >> tempDouble;
        temp.setProcessingDelay(tempDouble);
        //set transmission delay
        simFile.ignore(256, ':');
        simFile >> tempDouble;
        temp.setTransmissionDelay(tempDouble);
        //set queue delay
        simFile.ignore(256, ':');
        simFile >> tempDouble;
        temp.setQueueDelay(tempDouble);
        //set propragation delay
        simFile.ignore(256, ':');
        simFile >> tempDouble;
        temp.setPropagationDelay(tempDouble);
        //set wifi range
        simFile.ignore(256, ':');
        simFile >> tempDouble;
        temp.setWifiRange(tempDouble);
        //set IPV6 feature
        simFile.ignore(256, ':');
        simFile >> tempBool;
        temp.setIPV6(tempBool);
        //set the location
        simFile.ignore(256, ':');

        //add the node to the mesh
        m_mesh.addNode(temp);
    }

    int idA, idB;
    for(int i = 0; i < numOfNodes; i++)
    {
        simFile.ignore(256, ':');
        for(int j = 0; j < m_mesh->nodeRegistry[i].getNumOfLinks(); j++)
        {
            simFile.ignore(256, ':');
            simFile >> idA;
            simFile.ignore(256, ':');
            simFile >> idB;
            m_mesh->nodeRegistry[i].setLink(m_mesh->nodeRegistry[idB]);
            simFile.ignore(256, ':');
            simFile >> tempDouble;
            m_mesh->nodeRegistry[i].setThroughput(tempDouble);
        }
    }
}

ostream& operator<<(ostream& os, const Simulation& sim)
{

   os << "Simulation Data: " << '\n';
   os << "Network Mesh Data: " << sim.getNetworkMesh() << '\n';


  return os;
}

/**
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
    **/
>>>>>>> Stashed changes

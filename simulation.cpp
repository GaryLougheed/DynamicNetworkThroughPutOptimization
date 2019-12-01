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

    srand(time(NULL));

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
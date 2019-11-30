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
                }
            }
            
        }   
    }
}

void RunSimulation(int numberOfHops) 
{

}

void PacketGenerator()
{
    
}

void DisplayStats()
{

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
    //delete node if if there is more than three left. Mesh network size should never drop below 3 nodes.
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
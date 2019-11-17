#include "simulation.h"

Simulation::Simulation()
{

}

void GenerateInitialNetwork(int numberOfNodes) 
{

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
            flag = m_mesh.addNode(m_mesh.incrementID);
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
        if(linkeNodes(parameter1, parameter2) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
    }
}
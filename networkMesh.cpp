#include "networkMesh.h"

NetworkMesh::NetworkMesh()
{

  // Node reg
    m_nodeRegistry = NULL;

  // A path not a pointer and does not need to be initialized.

  // An array of paths
    m_pathReg = NULL;

  // Max num of nodes
    m_maxNodes = 100;

  // Current num of nodes
    m_currentNumOfNodes = 0;

}

NetworkMesh::~NetworkMesh()
{

  // delete dynamic memory
    delete []m_pathReg;
    
}

NetworkMesh::NetworkMesh(const NetworkMesh& rhs)
{

  int index = 0;

  if(this != &rhs)
  {/*
    // copy path registry
      if(rhs.m_pathReg != NULL)
      {

        m_currentNumOfNodes = rhs.m_currentNumNodes;
        m_maxNodes = rhs.m_maxNodes;

 
        for(index = 0; index < rhs.m_currentNumNodes; index++)
        {
          m_nodeRegistry[index] = rhs.m_nodeRegistry[index];
        }

        m_path = rhs.path;
 
      }
      else
      {
        // copy path
          m_path = rhs.m_path;

        // copy current number of nodes
          m_currentNumOfNodes = rhs.currentNumOfNodes;

        // copy max number of nodes
          m_maxNodes = rhs.m_maxNodes;
      }*/
  }
}


NetworkMesh NetworkMesh::operator=(const NetworkMesh& rhs)
{

  return rhs;
}

size_t NetworkMesh::getCurrentNumOfNodes()const
{
 
  return m_currentNumOfNodes;
}

size_t NetworkMesh::getMaxNumOfNodes()const
{
  return m_maxNodes;
}

Path NetworkMesh::getPath()const
{
  return m_path;
}

Path* NetworkMesh::getPathReg()const
{

  return m_pathReg;
}

bool NetworkMesh::addNode()
{
  return false;
}

bool NetworkMesh::deleteNode(const int& nodeId)
{
  return false;
}

bool NetworkMesh::linkNodes(const int& nodeId_A, const int& nodeId_B)
{
  return false;
}

bool NetworkMesh::changeNode(const int& nodeId_A)
{
  return false;
}

bool NetworkMesh::isPathAvailable(const int& nodeId_A, const int& nodeId_B)const
{
  return false;
}

ostream& operator<<(ostream& os, const NetworkMesh& rhs)
{
  return os;
}




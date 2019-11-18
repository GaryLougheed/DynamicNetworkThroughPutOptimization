#include "networkMesh.h"

NetworkMesh::NetworkMesh()
{

  // Node reg
    m_nodeRegistry = NULL;

  // A path not a pointer and does not need to be initialized.
    
  // An array of paths
    m_pathReg = NULL;

  // Max num of nodes
    m_maxNodes = 10;

  // Current num of nodes
    m_currentNumOfNodes = 0;

}

NetworkMesh::NetworkMesh( const size_t& currentNumOfNodes, const size_t& maxNumNodes)
{

  m_currentNumOfNodes = currentNumOfNodes;
  m_maxNodes = maxNumNodes;
  m_pathReg = NULL;
  m_numOfPaths = 0;
  m_nodeRegistry = new NetworkNode[m_maxNodes];




}


NetworkMesh::~NetworkMesh()
{

  // delete dynamic memory
    delete []m_nodeRegistry;
    delete []m_pathReg;

    m_nodeRegistry = NULL;
    m_pathReg = NULL;
        
}

NetworkMesh::NetworkMesh(const NetworkMesh& rhs)
{

  int index = 0;

  if(this != &rhs)
  {

    // Allow the object copied into the function to maintain the same data.
      m_currentNumOfNodes = rhs.m_currentNumOfNodes;
      m_maxNodes = rhs.m_maxNodes;
      m_pathReg = NULL;
      m_numOfPaths = 0; 
      m_nodeRegistry = new NetworkNode[m_maxNodes];
// TODO FIXED STATIC UPDATE  
      

   /*
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

NetworkNode& NetworkMesh::operator[](int index)const
{
  return m_nodeRegistry[index];
}

ostream& operator<<(ostream& os, const NetworkMesh& rhs)
{

  

  int index = 0;

  os << "NetworkMesh out stream operator: " << '\n';
 
  // Iterate through the network mesh. 
    for(index = 0; index < rhs.getMaxNumOfNodes(); index++)
      os << rhs[index] << '\n'; 

 
  return os;
}




// Network Mesh

// Adds nodes to the mesh and manages the mesh structure

// header files


#ifndef NETWORKMESH_H_
#define NETWORKMESH_H_ 

#include "networkNode.h"
#include "path.h"

#include <iostream>

using namespace std;


class NetworkMesh
{

  private:
    // Node reg
      NetworkNode* m_nodeRegistry;

    // Multiple Paths
      Path* m_pathReg;

    // Paths singular
      Path m_path; 

    // Current number of nodes
      size_t m_currentNumOfNode;

    // Max num of nodes
      size_t m_maxNodes; 



  public:
    // Constructor
      NetworkMesh();

    // Copy Constructor
      NetworkMesh(const NetworkMesh& rhs);

    // Destructor
      ~NetworkMesh();

    // Assignment Operator
      NetworkMesh operator=(const NetworkMesh& rhs);

    // Gettters
      NetworkMesh getNetworkReg()const;
      size_t getMaxNumOfNodes()const;
      size_t getCurrentNumOfNodes()const; 
      Path getPath()const;
      Path* getPathReg()const;
      
    // Setters
      void setNetworkReg(const NetworkMesh& srcMesh);
      void setMaxNumOfNodes(const size_t& maxNumOfNodes);

    // Add node 
      bool addNode(const int& nodeId);
  
    // Delete node (manage connections)
      bool deleteNode(const int& nodeId);

    // Link Node ( A and B )
      bool linkeNodes(const int& nodeId_A, const int& nodeId_B);

    // ChangeNode()
      bool changeNode(int nodeId_A);

    // Path available 
      bool isPathAvailable(const int& nodeId_A, const int& nodeId_B)const;
   
    // Get Path
      Path getPath();

      // Upload mesh from file 
      // Node Id, delay processing, delay queueing, delay propagation, and delay throughput.
   
      //   

     //  Overloaded Operators

       friend ostream& operator<<(ostream&, const NetworkMesh& );


};

#endif

// Network Mesh

// Adds nodes to the mesh and manages the mesh structure

// header files


#ifndef NETWORKNODE_H_
#define NETWORKNODE_H_

#include "networkNode.h"
#include "path.h"



class NetworkMesh
{

  private:
    // Node reg
	NetworkNode* m_nodeRegistry;

    // Max num of nodes
	size_t m_maxNodes; 

  public:
    // Constructor
      NetworkMesh();

    // Copy Constructor
      NetworkMesh(const NetworkMesh& rhs);

    // Destructor
      ~Network();

    // Assignment Operator
      =operator(const NetworkMesh& rhs);

    // Gettters
      NetworkMesh getNetworkReg();
      size_t getMaxNumOfNodes();

    // Setters
      void setNetworkReg(const NetworkMesh& srcMesh);
      void setMaxNumOfNodes(const size_t& maxNumOfNodes);

    // Add node 
      bool addNode(int& nodeId);
  
    // Delete node (manage connections)
      bool deleteNode(int nodeId);

    // Link Node ( A and B )
      bool linkeNodes(int nodeId_A, int nodeId_B);

    // ChangeNode()
      bool changeNode(int nodeId_A);

    // Path available 
      bool isPathAvailable(int nodeId_A, int nodeId_B)const;
   
    // Get Path

      // Upload mesh from file 
      // Node Id, delay processing, delay queueing, delay propagation, and delay throughput.
   
      //   

     //  Overloaded Operators

       friend ostream& operator<<(ostream&, const NetworkMesh& );


};

#endif

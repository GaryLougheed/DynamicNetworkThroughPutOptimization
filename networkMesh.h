// Network Mesh

// Adds nodes to the mesh and manages the mesh structure

// header files


#ifndef NETWORKMESH_H_
#define NETWORKMESH_H_ 

#include "path.h"
#include <fstream>
#include <iostream>

using namespace std;


class NetworkMesh
{

  private:
    // Node reg
      NetworkNode* m_nodeRegistry;

    // time mesh has lived 
      time_t m_timeLived;

    // Multiple Paths
      Path* m_pathReg;

    // Paths singular
      Path m_path; 

    // Current number of nodes
      size_t m_currentNumOfNodes;

    // Max num of nodes
      size_t m_maxNodes; 

    // Max num of paths
      size_t m_numOfPaths;

  public:
    // Constructor
      NetworkMesh();

    // Parameterized Constructor
      NetworkMesh( const size_t& maxNumNodes);

    // Copy Constructor
      NetworkMesh(const NetworkMesh& rhs);

    // Destructor
      ~NetworkMesh();

    // Assignment Operator
      NetworkMesh operator=(const NetworkMesh& rhs);

    // Gettters

      size_t getMaxNumOfNodes()const;

      size_t getCurrentNumOfNodes()const; 

      Path getPath()const;

      Path* getPathReg()const;
      
    // Setters

    /* Name: addNode 
       Input: generate a user menu to add a node to the network. 
       Output: return true if there was space for the node and all the data created.
       Process: There exists a contigous node registry. The node added will be assigned to the first
                available spot within the registry. 
       Dependancies: network node, iostream, vector, and packet.

      // TODO: file io for addNode overload or new function.
    */ 
      bool addNode(const NetworkNode& node);

      bool addNode(); // TODO: delete this function prototype
  
    /* Name:  deleteNode (manage connections)
       Input: nodeId 
       Output: true or false if the node is successfully deleted.
       Process: The node registry will change completely this will influence the current static
                node ID provider. The node provider must provide the empty place first. An obtain node ID
                provider must be developed // TODO.
                The deletion will iterate through the entire node reg to delete any links to the delete
                node. Once the iteration is complete the function will report true or false if the memory
                was correctly deallocated. Since the network is DSR no update tables will be influenced.
       Dependancies: nodeIdProvider function//TODO , networkNode destructor, link destructor, 
                     and node registry.
    */
      bool deleteNode(const int& nodeId);

    /* Name: linkNodes
       Input: two unqiue node IDs, if identical node is are provided the function reports false. 
       Output: an updated node registry that contains the link established
       Process: The nodeRegistry accesses the nodeID provided and
                uses the networkNode establishLink function //TODO  to link the A and B nodes.
                No updates to the table will be necessary. 
       Dependancies: establishLink function //TODO and NetworkNode 
    */
      bool linkNodes(const int& nodeId_A, const int& nodeId_B);

    /* Name: changeNode
       Input: node ID for the node to change, reports false if the node is null or out of bounds.
       Output: true or false if the node was successfully change.
       Process: Access the node from the node registry and change is data. We can not change the node
                Id. //TODO: limit change node parameters.
       Dependancies: 
    */
      bool changeNode(const int& nodeId_A);

    // Path available 
      bool isPathAvailable(const int& nodeId_A, const int& nodeId_B)const;
   
    // Get Path
      Path getPath();

    // Upload mesh from file 
      bool uploadMesh();

    //
      bool doesNodeExist(const int& nodeId);


    // Update Function
      bool update(time_t delta);

      // Node Id, delay processing, delay queueing, delay propagation, and delay throughput.
   
      //   

     //  Overloaded Operators


       NetworkNode& operator[](int index)const;

       friend ostream& operator<<(ostream&, const NetworkMesh& );


};

#endif

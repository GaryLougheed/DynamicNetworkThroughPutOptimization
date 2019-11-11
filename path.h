#ifndef PATH_H_
#define PATH_H_

#include "networkNode.h"



/*
    Class that maintains the indices of a path.
    The path must exist within the indexable space provided by a network mesh.
*/


class Path
{

  private:
   NetworkNode* m_path;
   size_t m_maxPathSize;
   int m_currentSize;
   int m_start;
   int m_end;

  public:
   // Constructor
     Path();

   // Copy Constructor
     Path(const Path& rhs);

   // Destructor
     ~Path();

   // Assignment Operator
    Path operator=(const Path& rhs);
 
   // Getters 
     NetworkNode* getPath()const;
     size_t getMaxPathSize()const;
     int getCurrentSize()const;
     int getStart()const;
     int getEnd()const;

   // Setters
     void setPath(NetworkNode* path);
     void setMaxPathSize(size_t pathSize);
     void setCurrentSize(int currentSize);
     void setStart(int start_id);
     void setEnd(int end_id);

   // public functions
     bool isEmpty()const;
     bool addNodeToPath(const int& node_id);
     bool deleteNodeFromPath(const int& node_id);


   // overloaded operators
     friend ostream& operator<<(ostream& , const Path& );

};

#endif

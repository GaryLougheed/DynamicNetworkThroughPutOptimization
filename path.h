#ifndef PATH_H_
#define PATH_H_

#include "networkNode.h"

class Path
{

  private:
   networkNode* m_path;
   size_t m_maxPathSize;
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

   // Getters 

   // Setters

   // public functions


   // overloaded operators


};

#endif

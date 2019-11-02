// Vector class, always has three data members

// header

#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
using namespace std;

class Vector;

ostream& operator<<(ostream&, const Vector&);

// Class Vector
class Vector
{
  private:
    double m_x;
    double m_y;
    double m_z;
 
  public:
    // Constructor
    Vector();

    // Copy Constructor
    Vector(const Vector& rhs);
 
    // destructor
    ~Vector();

    // Getters
    double getX()const;
    double getY()const;
    double getZ()const;

    // Setters
    void setX(double valX);
    void setY(double valY);
    void setZ(double valZ);

    // Assignment Operator
    Vector operator=(const Vector& rhs);

    // Overloaded Operators
    friend ostream& operator<<(ostream& , const Vector& );



};



#endif


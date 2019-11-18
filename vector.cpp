#include "vector.h"

Vector::Vector()
{
  m_x = 0;
  m_y = 0;
  m_z = 0;
}

Vector::Vector(double x, double y, double z)
{
  m_x = x;
  m_y = y;
  m_z = z;
}


Vector::Vector(const Vector& rhs)
{
    m_x = rhs.getX();
    m_y = rhs.getY();
    m_z = rhs.getZ();

}

Vector::~Vector()
{

}

double Vector::getX()const
{
  return m_x;
}

double Vector::getY()const
{
  return m_y;
}

double Vector::getZ()const
{
  return m_x;
}

void Vector::setX(double valX)
{
  m_x = valX;
}

void Vector::setY(double valY)
{
  m_y = valY;
}

void Vector::setZ(double valZ)
{
  m_z = valZ;
}

Vector Vector::operator=(const Vector& rhs)
{
  if(this != &rhs)
  {
    m_x = rhs.getX();
    m_y = rhs.getY();
    m_z = rhs.getZ();

    return *this;
 
  }
   
  return *this;
}

ostream& operator<<(ostream& os, const Vector& rhs)
{
  os << "X value: " << rhs.getX() << " Y value: " << rhs.getY() << " Z value: " << rhs.getZ() <<'\n';
}

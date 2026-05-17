/*! \file CRightTriangle.cpp
    \brief implementation of class RightTriangle
    \author Giorgio Cirjan, Adama Diakhite
*/

#include "CRightTriangle.h"
#include <iostream>
#include <cmath>

using namespace std;

/* ----------------------------
   CONSTRUCTORS / DESTRUCTOR
   ---------------------------- */

/// @brief default constructor
RightTriangle::RightTriangle() : Shape()
{
    cout << "RightRectangle - default constructor" << endl;
}

/// @brief constructor 
/// @param px position in the grid (x)
/// @param py position in the grid (y)
/// @param w width of the bounding box
/// @param h height of the bounding box
RightTriangle::RightTriangle(float px, float py, float w, float h) : Shape(px, py, w, h)
{
    cout << "RightTriangle - constructor" << endl;
}

/// @brief copy constructor
/// @param r reference to the object to be copied
RightTriangle::RightTriangle(const RightTriangle &r) : Shape(r)
{
    cout << "RightTriangle - copy constructor" << endl;
}

/// @brief destructor
RightTriangle::~RightTriangle()
{   
    cout << "RightTriangle - destructor" << endl;
}

/* ----------------------------
   OPERATORS
   ---------------------------- */

/// @brief overload of operator = 
/// @param r reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator
RightTriangle& RightTriangle::operator=(const RightTriangle &r)
{
    if (this != &r) 
        Shape::operator=(r);

    return *this;
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two bounding boxes have the same width and the same length  
bool RightTriangle::operator==(const RightTriangle &r)
{
    return Shape::operator==(r);
}

/* ----------------------------
   BASIC HANDLING
   ---------------------------- */

/// @brief default initialization of the object
void RightTriangle::Init()
{
    Shape::Init();
}

/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void RightTriangle::Init(const RightTriangle &r)
{
    Shape::Init(r);
}

/// @brief total reset of the object  
void RightTriangle::Reset()
{
    Shape::Reset();
}


/* ----------------------------
   GETTERS
   ---------------------------- */
   
/// @brief to get the height of the RightTriangle
/// @return height
float RightTriangle::GetVSide()
{
	return height;
    
}

/// @brief to get the width of the RightTriangle
/// @return width
float RightTriangle::GetHSide()
{
    return width;
}

/// @brief to get the hypotenuse of the RightTriangle
/// @return hypotenuse<
float RightTriangle::GetHypotenuse()
{
    return  sqrt( pow(width, 2) + pow(height, 2) ); //hypot(height, width)
}

/// @brief computes the area of the RightTriangle
/// @return area 
float RightTriangle::GetArea()
{
    return (width * height)/2;
}

/// @brief computes the perimeter of the RightTriangle
/// @return perimeter 
float RightTriangle::GetPerimeter()
{
    return  width + height + GetHypotenuse();
}

/* ----------------------------
   DEBUG and SERIALIZATION
   ---------------------------- */

/// @brief for debugging: all infos about the object
void RightTriangle::Dump()
{
	cout << endl <<  "----------------------" << endl;
    cout << "RightTriangle Dump:" << endl << endl;
	
	Shape::Dump();
	
    cout << "  RightTriangle hypotenuse:  " << GetHypotenuse() << endl;
    cout << "  Figure area:               " << GetArea() << endl;
    cout << "  Figure perimeter:          " << GetPerimeter() << endl;
    cout << "  Text:                      " << (text ? text : "(null)") << endl;
	cout << endl;
}
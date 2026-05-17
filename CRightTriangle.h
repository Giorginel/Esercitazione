/*! \file CRightTriangle.h
    \brief Declaration of the class RightTriangle
    \author Giorgio Cirjan, Adama Diakhite
*/

#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "CShape.h"

/// @class RightTriangle
/// @brief to manage an object with the shape of a RightTriangle
class RightTriangle : public Shape
{
public:

    /// @name CONSTRUCTORS / DESTRUCTOR
    /// @{
    RightTriangle();
    RightTriangle(float px, float py, float w, float h);
    RightTriangle(const RightTriangle &r);

    ~RightTriangle();
    /// @}

    /// @name OPERATORS
    /// @{
    RightTriangle& operator=(const RightTriangle &r);
    bool operator==(const RightTriangle &r);
    /// @}

    /// @name BASIC HANDLING
    /// @{
    void Init();
    void Init(const RightTriangle &r);
    void Reset();
    /// @}
	
	/// @name GETTERS
    /// @{
	float GetVSide();
	float GetHSide();
    float GetHypotenuse();
    float GetArea();
    float GetPerimeter();
    /// @}

    /// @name DEBUG and SERIALIZATION
    /// @{
    void Dump();
    /// @}
};

#endif
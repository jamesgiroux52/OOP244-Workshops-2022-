/*************************************************************
// File    Shape.h
// Version 1.0
// Date    November 11, 2022
// Author  James Giroux - jgiroux1@myseneca.ca
// Description:
// Shape Interface
// --------------------------------------
// Name            Date            Reason
// J Giroux       Nov 11, 22       Initial Version 1.0
// -----------------------------------------------------------
// I have done all the coding myself and only copied the
// code provided from the course repository to complete my
// Workshop.
// -----------------------------------------------------------
*************************************************************/

#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_

#include <iostream>

namespace sdds {
    // shape interface
    class Shape {
    public:
        virtual void draw(std::ostream& os) = 0;
        virtual void getSpecs(std::istream& is) = 0;
        virtual ~Shape();
    };
    // helper overloads - works for all children of Shape
    std::ostream& operator<<(std::ostream& os, Shape& S);
    std::istream& operator>>(std::istream& is, Shape& S);
}

#endif // !SDDS_SHAPE_H_


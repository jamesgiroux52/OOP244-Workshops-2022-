/*************************************************************
// File    Shape.cpp
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

#include <iostream>
#include "Shape.h"

using namespace std;

namespace sdds {
    Shape::~Shape() { }
    // implementation of insertion and extraction overloads
    ostream& operator<<(ostream& os, Shape& S) {
        S.draw(os);
        return os;
    }
    istream& operator>>(istream& is, Shape& S) {
        S.getSpecs(is);
        return is;
    }
}
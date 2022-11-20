/*************************************************************
// File    Rectangle.cpp
// Version 1.0
// Date    November 11, 2022
// Author  James Giroux - jgiroux1@myseneca.ca
// Description:
// Rectangle implementation
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
#include <cstring>
#include "Rectangle.h"

using namespace std;

namespace sdds {
    // default - will set the label null
    Rectangle::Rectangle() : LblShape() {
        m_width = 0;
        m_height = 0;
    }
    // create a rectangle with a valid label
    Rectangle::Rectangle(const char* label, int width, int height) 
        : LblShape(label)
    {
        m_width = width;
        m_height = height;
        if (m_height < 3 || m_width < int(strlen(LblShape::label()) + 2)) {
            m_width = 0;
            m_height = 0;
        }
    }
    // get the details of the rectangle
    void Rectangle::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore(1000, ',');
        is >> m_height;
        is.ignore(1000, '\n');
    }
    // output the rectangle
    void Rectangle::draw(std::ostream& os) {
        if (m_width && m_height) {
            os << "+";
            for (int i = 0; i < m_width - 2; os << "-", i++);
            os << "+" << endl;
            os << "|";
            os.setf(ios::left);
            os.width(m_width - 2);
            os << LblShape::label() << "|" << endl;
            for (int i = 0; i < m_height - 3; i++) {
                os << "|";
                for (int j = 0; j < m_width - 2; os << " ", j++);
                os << "|" << endl;
            }
            os << "+";
            for (int i = 0; i < m_width - 2; os << "-", i++);
            os << "+";
        }
    }
}
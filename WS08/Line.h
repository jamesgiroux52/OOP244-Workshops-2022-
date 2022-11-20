/*************************************************************
// File    Line.h
// Version 1.0
// Date    November 11, 2022
// Author  James Giroux - jgiroux1@myseneca.ca
// Description:
// Line concrete class
// --------------------------------------
// Name            Date            Reason
// J Giroux       Nov 11, 22       Initial Version 1.0
// -----------------------------------------------------------
// I have done all the coding myself and only copied the
// code provided from the course repository to complete my
// Workshop.
// -----------------------------------------------------------
*************************************************************/

#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_

#include "LblShape.h"

namespace sdds {
    // line shape with a label
    class Line : public LblShape {
        int m_length;
    public:
        Line();
        Line(const char* label, int length);
        void getSpecs(std::istream& is);
        void draw(std::ostream& os);
    };

}

#endif // !SDDS_LINE_H_

/*************************************************************
// File    Dumper.h
// Version 1.1
// Date    November 7, 2022
// Author  James Giroux - jgiroux1@myseneca.ca
// Description:
// Dumper header file
// --------------------------------------
// Name            Date            Reason
// J Giroux       Nov 7, 22       Initial Version 1.0
// -----------------------------------------------------------
// I have done all the coding myself and only copied the
// code provided from the course repository to complete my
// workshop.
// -----------------------------------------------------------
*************************************************************/

#ifndef SDDS_DUMPER_H
#define SDDS_DUMPER_H

#include <iostream>
#include "VehicleBasic.h"

namespace sdds {
    // derived class
    class Dumper : public VehicleBasic {
        double m_capacity;
        double m_load = 0;
    public:
        Dumper(const char* plate, int year, double capacity, 
            const char* location);
        bool loaddCargo(double load);
        bool unloadCargo();
        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::istream& read(std::istream& istr);
    };
    std::ostream& operator<<(std::ostream& ostr, const Dumper& D);
    std::istream& operator>>(std::istream& istr, Dumper& D);
}
#endif
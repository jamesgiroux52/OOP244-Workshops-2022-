/*************************************************************
// File    VehicleBasic.h
// Version 1.1
// Date    November 7, 2022
// Author  James Giroux - jgiroux1@myseneca.ca
// Description:
// VehicleBasic header file
// --------------------------------------
// Name            Date            Reason
// J Giroux       Nov 7, 22       Initial Version 1.0
// -----------------------------------------------------------
// I have done all the coding myself and only copied the
// code provided from the course repository to complete my
// workshop.
// -----------------------------------------------------------
*************************************************************/

#ifndef SDDS_VEHICLEBASIC_H
#define SDDS_VEHICLEBASIC_H

#include<iostream>

namespace sdds {
    // base class
    class VehicleBasic {
        char m_plate[9]{};
        char m_location[64]{};
        int m_year = 0;
    public:
        VehicleBasic(const char* plate, int year);
        void NewAddress(const char* location);
        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::istream& read(std::istream& istr);
    };
    std::ostream& operator<<(std::ostream& ostr, const VehicleBasic& V);
    std::istream& operator>>(std::istream& istr, VehicleBasic& V);
}

#endif
/*************************************************************
// File    Dumper.cpp
// Version 1.1
// Date    November 7, 2022
// Author  James Giroux - jgiroux1@myseneca.ca
// Description:
// Dumper class implimentation
// --------------------------------------
// Name            Date            Reason
// J Giroux       Nov 7, 22       Initial Version 1.0
// -----------------------------------------------------------
// I have done all the coding myself and only copied the
// code provided from the course repository to complete my
// workshop.
// -----------------------------------------------------------
*************************************************************/

#include <iostream>
#include "Dumper.h"
#include "VehicleBasic.h"

using namespace std;

namespace sdds {
    Dumper::Dumper(const char* plate, int year, double capacity, const char* location) :
            /* instantiate the inherited base class VehicleBasic */
            VehicleBasic(plate, year), m_capacity(capacity) {
        NewAddress(location); // set the location
    }
    bool Dumper::loaddCargo(double load) { // load
        bool res = false;
        double space = m_capacity - m_load;
        if (space >= load) {
            res = true;
            m_load += load;
        }
        return res;
    }
    bool Dumper::unloadCargo() { // unload
        bool res = false;
        if (m_load) {
            res = true;
            m_load = 0;
        }
        return res;
    }
    // I/O
    std::ostream& Dumper::write(std::ostream& ostr) const {
        VehicleBasic::write(ostr); // call base write
        ostr << " | " << m_load << "/" << m_capacity;
        return ostr;
    }
    std::istream& Dumper::read(std::istream& istr) {
        VehicleBasic::read(istr); // call base read
        cout << "Capacity: ";
        istr >> m_capacity;
        cout << "Cargo: ";
        istr >> m_load;
        return istr;
    }
    std::ostream& operator<<(std::ostream& ostr, const Dumper& D) {
        return D.write(ostr);
    }
    std::istream& operator>>(std::istream& istr, Dumper& D) {
        return  D.read(istr);
    }
}
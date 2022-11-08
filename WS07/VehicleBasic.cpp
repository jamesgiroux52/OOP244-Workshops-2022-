/*************************************************************
// File    VehicleBasic.cpp
// Version 1.1
// Date    November 7, 2022
// Author  James Giroux - jgiroux1@myseneca.ca
// Description:
// VehicleBasic class implimentation
// --------------------------------------
// Name            Date            Reason
// J Giroux       Nov 7, 22       Initial Version 1.0
// -----------------------------------------------------------
// I have done all the coding myself and only copied the
// code provided from the course repository to complete my
// Workshop.
// -----------------------------------------------------------
*************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"

using namespace std;

namespace sdds {
    VehicleBasic::VehicleBasic(const char* plate, int year) {
        strcpy(m_location, "Factory");
        strcpy(m_plate, plate);
        m_year = year;
    }
    // will be used in Dumper constructor initilization area
    void VehicleBasic::NewAddress(const char* location) {
        if (strcmp(m_location, location) != 0) {
            cout << "|";
            cout.width(8);
            cout << m_plate << "| |";
            cout.width(20);
            cout << m_location << " ---> ";
            cout.width(20);
            cout.setf(ios::left);
            cout << location << "|" << endl;
            cout.unsetf(ios::left);
            strcpy(m_location, location);
        }
    }
    // I/O
    std::ostream& VehicleBasic::write(std::ostream& ostr) const {
        ostr << "| " << m_year << " | " << m_plate << " | "
            << m_location;
        return ostr;
    }
    std::istream& VehicleBasic::read(std::istream& istr) {
        cout << "Built year: ";
        istr >> m_year;
        istr.ignore(1000, '\n');
        cout << "License plate: ";
        istr.getline(m_plate, '\n');
        cout << "Current location: ";
        istr.getline(m_location, '\n');
        return istr;
    }
    std::ostream& operator<<(std::ostream& ostr, const VehicleBasic& V) {
        return V.write(ostr);
    }
    std::istream& operator>>(std::istream& istr, VehicleBasic& V) {
        return V.read(istr);
    }
}

/*
 ============================================================================
 Name        : Apartment.h
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : October 11, 2022 - Workshop 5 - part 1
 ============================================================================
 */

#ifndef SDDS_APARTMENT_H_
#define SDDS_APARTMENT_H_
#include <iostream>

namespace sdds {
	class Apartment {
		int m_number = -1;
		double m_balance = 0.0;
		bool isValid(int number, double balance = 0) const;		
		void setEmpty();
	public:
		// constructors
		Apartment();
		Apartment(int number, double balance);
		// destructor
		~Apartment();
		std::ostream& display()const; // display	
		double balance()const;
		// unary member operator
		bool operator ~() const;
		// operator overloads
		Apartment& operator=(int number);
		Apartment& operator=(Apartment& apt);
		Apartment& operator+=(const double balance);
		Apartment& operator-=(const double balance);
		Apartment& operator<<(Apartment& apt);
		Apartment& operator>>(Apartment& apt);
		// conversion overloads
		operator bool() const;
		operator int() const;
		operator double() const;
	};
	double operator+(const Apartment& a, const Apartment& b);
	double operator+=(double& dub, const Apartment& a);
}

#endif // SDDS_APARTMENT_H_
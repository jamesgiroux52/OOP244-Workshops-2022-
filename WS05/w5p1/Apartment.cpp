/*
 ============================================================================
 Name        : Apartment.cpp
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : October 11, 2022 - Workshop 5 - part 1
 ============================================================================
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;

namespace sdds {

	// checks if apartment is valid
	bool Apartment::isValid(int num, double bal) const {
		return(num >= 1000 && num <= 9999 && bal >= 0);
	}

	// sets the apartment to an empty state
	void Apartment::setEmpty() {
		m_number = -1;
		m_balance = 0.0;
	}

	// default constructor - not called
	Apartment::Apartment() {
		setEmpty();
	}

	// 2 arg constructor
	Apartment::Apartment(int number, double balance) {
		if (isValid(number, balance)) {
			m_number = number;
			m_balance = balance;
		} else {
			setEmpty();
		}
	}

	// destructor - not needed but good practice
	Apartment::~Apartment() {
		setEmpty();
		// Maybe delete memory if it is allocated
	}

	// display - provided for ws
	std::ostream& Apartment::display() const {
		if (*this) {
			cout.width(4);
			cout << m_number;
			cout << " | ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << m_balance;
			cout.unsetf(ios::right);
			cout << " ";
		} else {
			cout << "Invld|  Apartment   ";
		}
		return cout;
	}

	double Apartment::balance() const {
		return m_balance;
	}

	// used to see if an apartment is not lived in
	bool Apartment::operator~() const {
		return (m_balance == 0);
	}

	// assignment operator to set the apt number
	Apartment& Apartment::operator=(int num) {
		if (isValid(num))
			m_number = num;
		else
			setEmpty();
		return *this;
	}

	// assignment operator to swap apartments
	Apartment& Apartment::operator=(Apartment& apt) {
		Apartment temp(int(apt), apt.balance()); // won't let me use conversion overload for balance
		// swap appartments
		apt.m_number = m_number;
		apt.m_balance = m_balance;
		m_balance = temp.balance();
		m_number = int(temp);
		return *this;
	}

	// increases the balance for an apartment if valid
	Apartment& Apartment::operator+=(const double bal) {
		if (isValid(m_number, bal))
			m_balance += bal;
		return *this;
	}

	// decreases the balance for an apartment if valid
	Apartment& Apartment::operator-=(const double bal) {
		if (isValid(m_number, bal) && m_balance > bal)
			m_balance -= bal;
		return *this;
	}

	// shifts balance to the left of two objects
	Apartment& Apartment::operator<<(Apartment& apt) {
		if (&apt.m_number != &this->m_number && isValid(apt.m_number, apt.m_balance)) {
			m_balance += apt.m_balance;
			apt.m_balance = 0;
		}
		return *this;
	}

	// shifts balance to the right of two objects
	Apartment& Apartment::operator>>(Apartment& apt) {
		if (&apt.m_number != &this->m_number && isValid(apt.m_number, apt.m_balance)) {
			apt.m_balance += m_balance;
			m_balance = 0;
		}
		return *this;
	}

	// used to check (*this) in display
	Apartment::operator bool() const {
		return (isValid(m_number, m_balance));
	}

	// gets the apartment number
	Apartment::operator int() const {
		return m_number;
	}

	// gets the balance
	Apartment::operator double() const {
		return m_balance;
	}

	// gets the sum of two apartments balances
	double operator+(const Apartment& a, const Apartment& b) {		
		return (double(a) + double(b));
	}

	// adds balances to a variable where called
	double operator+=(double& dub, const Apartment& a){
		return (dub += double(a));
	}
}
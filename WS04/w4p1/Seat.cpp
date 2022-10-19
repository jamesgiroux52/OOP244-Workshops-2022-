/*
 ============================================================================
 Name        : Seat.cpp
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : October 3, 2022 - Workshop 4 - part 1
 ============================================================================
 I have done all the coding by myself and only copied the code that my professor
 provided to complete my workshops and assignments.
 */

#include "Seat.h"
#include "Utils.h"

using namespace std;

namespace sdds {

	bool Seat::validate(int row, char seat) const {
		bool res = false;
		// valid seats arrays
		char onetofour[] = {'A', 'B', 'E', 'F'};
		char rest[] = {'A', 'B','C','D', 'E', 'F'};		
		if (row > 0 && row < 5) {			
			for (int i = 0; i < 4; i++) {
				if (seat == onetofour[i]) res = true;
		}}		
		if ((row > 6 && row < 16) || (row > 19 && row < 39)) {
			for (int i = 0; i < 6; i++) {
				if (seat == rest[i]) res = true;
		}}
		return res;
	}

	Seat& Seat::alAndCp(const char* str) {
		m_name = nullptr;
		if (str != nullptr && strlen(str) > 0) {
			int len = strlen(str);
			m_name = new char[len + 1];
			strcpy(m_name, str, len);
		}
		return *this;
	}

	Seat& Seat::reset() {
		delete[] m_name;
		m_name = nullptr;
		m_row = 0;
		m_seat = '\0';
		return *this;
	}

	bool Seat::isEmpty()const {
		return (m_name == nullptr);
	}

	bool Seat::assigned()const {
		return validate(m_row, m_seat);
	}

	Seat::Seat() {
		m_name = nullptr;
		reset();
	}

	Seat::Seat(const char* name) {
		if (name != nullptr && strlen(name) > 0) {
			alAndCp(name);
			m_row = 0; 
			m_seat = '\0';
		}
	}

	Seat::Seat(const char* name, int row, char seat) {
		if (validate(row, seat)) {
			alAndCp(name);
			set(row, seat);
		} else {
			m_row = 0;
			m_seat = '\0';
		}
	}

	Seat::~Seat() {
		delete[] m_name;
		m_name = nullptr;
	}

	Seat& Seat::set(int row, char seat) {
		if (validate(row, seat)) {
			m_row = row;
			m_seat = seat;
		} else {
			m_row = 0;
			m_seat = '\0';
		}
		return *this;
	}

	int Seat::row()const {
		return m_row;
	}

	char Seat::letter()const {
		return m_seat;
	}

	const char* Seat::passenger()const {
		return m_name;
	}

	std::ostream& Seat::display(std::ostream& coutRef)const {
		char tempName[41];
		if (!isEmpty()) {
			strcpy(tempName, m_name, 40);
			coutRef.setf(ios::left);
			coutRef.fill('.');
			coutRef.width(40);
			coutRef << tempName << " ";
			coutRef.unsetf(ios::left);
			coutRef.fill(' ');
			// validate seat
			if (validate(m_row, m_seat))
				coutRef << m_row << m_seat;
			else if (m_row == 0)
				coutRef << "___";							
		} else {
			coutRef << "Invalid Seat!";
		}
		return coutRef;
	}

	std::istream& Seat::read(std::istream& cinRef) {
		reset();
		char tName[71];
		int tRow = 0;
		char tSeat = 0;
		cinRef.getline(tName, 71, ',');		
		cinRef >> tRow >> tSeat;
		cinRef.ignore(); // ignore /n
		if (!cinRef.fail()) {
			alAndCp(tName);
			if (m_name != nullptr)
				set(tRow, tSeat);
		}
		return cinRef;
	}
}
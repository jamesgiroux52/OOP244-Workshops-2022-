/*
 ============================================================================
 Name        : Seat.h
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : October 3, 2022 - Workshop 4 - part 1
 ============================================================================
 I have done all the coding by myself and only copied the code that my professor 
 provided to complete my workshops and assignments.
 */

#ifndef SDDS_SEAT_H_
#define SDDS_SEAT_H_

#include <iostream>

namespace sdds {

	class Seat {
		char* m_name = nullptr;
		int m_row = 0;
		char m_seat = '\0';

		bool validate(int row, char seat)const;
		Seat& alAndCp(const char* str);
	public:
		Seat& reset();
		bool isEmpty()const;
		bool assigned()const;
		Seat();
		Seat(const char* name);
		Seat(const char* name, int row, char seat);
		~Seat();
		Seat& set(int row, char seat);
		int row()const;
		char letter()const;
		const char* passenger()const;
		std::ostream& display(std::ostream& coutRef = std::cout)const;
		std::istream& read(std::istream& cinRef = std::cin);
	};
}

#endif // !SDDS_SEAT_H_
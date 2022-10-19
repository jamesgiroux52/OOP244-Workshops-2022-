/*
 ============================================================================
 Name        : Mark.h
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : October 11, 2022 - Workshop 5 - part 2
 ============================================================================
 */

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_

namespace sdds {

	class Mark {
		int m_mark; // number mark (0-100)
		// personal private member functions
		bool isValid(int mark) const;
		void setEmpty(); // not needed in this app - rem destructor if del
		int checkMark() const;
	public:
		// constructors and destructor
		Mark();
		Mark(int mark);
		~Mark();
		// type converion operator overloads
		operator int() const;
		operator double() const;
		operator char() const;
		operator bool() const;
		// comparison operator overloads
		bool operator==(const Mark& mark) const;
		bool operator!=(const Mark& mark) const;
		bool operator<(const Mark & mark) const;
		bool operator>(const Mark& mark) const;
		bool operator>=(const Mark& mark) const;
		bool operator<=(const Mark& mark) const;
		// prefix operator overloads
		Mark& operator++();
		Mark& operator--();
		// postfix operator overloads
		Mark operator++(int);
		Mark operator--(int);
		bool operator~() const;
		// binary operator overloads
		Mark& operator=(const int mark); // correct invalid marks
		Mark& operator+=(const int mark);
		Mark& operator-=(const int mark);
		Mark operator+(const Mark& mark) const;
		Mark operator+(const int mark) const;
		Mark& operator<<(Mark& mark);
		Mark& operator>>(Mark& mark);
	};
	// binary helper operators
	int operator+=(int& num, const Mark& mark);
	int operator-=(int& num, const Mark& mark);
	int operator+(int& num, const Mark& mark);
}

#endif // !SDDS_MARK_H_



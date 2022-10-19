/*
 ============================================================================
 Name        : CC.h
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : September 24, 2022 - Workshop 3 - part 1
 ============================================================================
 */

#ifndef SDDS_CC_H_
#define SDDS_CC_H_

namespace sdds {

	class CC {
		char* m_name = nullptr;
		short m_cvv, m_expMon, m_expYr;
		unsigned long long m_ccNum;

		bool validate(const char* name, unsigned long long ccNum, short cvv, short expMon, short expYr) const;
		void prnNumber() const;
	public:
		void set();
		void cleanUp();
		bool isEmpty();
		void set(const char* name, unsigned long long ccNum, short cvv, short expMon, short expYr);
		bool read();
		void display(int row = 0) const;
	};

}

#endif
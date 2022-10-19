/*
 ============================================================================
 Name        : CC.cpp
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : September 24, 2022 - Workshop 3 - part 1
 ============================================================================
 */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "CC.h"
#include "Utils.h"

using namespace std;

namespace sdds {

	bool CC::validate(const char* name, unsigned long long ccNum, short cvv, short expMon, short expYr) const {
		bool res = false;
		if (name != nullptr && strlen(name) > 2 && ccNum > 4000000000000000 && ccNum < 4099999999999999 &&
			cvv < 1000 && cvv > 99 && expMon > 0 && expMon < 13 && expYr > 21 && expYr < 33) res = true;
		return res;
	}

	void CC::prnNumber() const {
		unsigned long long output;
		unsigned long long div[] = {1000000000000, 100000000, 10000};
		int count = 0;
		output = m_ccNum / div[count];
		do {
			cout.fill('0');
			cout.width(4);
			cout << output;
			if (count < 2) {
				cout << " ";
				output = (m_ccNum % div[count]) / div[count + 1];
			} else if (count == 2) {
				output = m_ccNum % div[count];
				cout << " ";
			}
			count++;
		} while (count < 4);

		cout.fill(' ');
	}

	void CC::cleanUp() {
		delete[] m_name;
		set();
	}

	bool CC::isEmpty() {
		bool res = false;
		if (m_name == nullptr) res = true;
		return res;
	}

	void CC::set() {
		m_name = nullptr; m_cvv = 0; m_expMon = 0; m_expYr = 0; m_ccNum = 0;
	}

	void CC::set(const char* name, unsigned long long ccNum, short cvv, short expMon, short expYr) {
		cleanUp();
		if (validate(name, ccNum, cvv, expMon, expYr)) {
			int length = strlen(name);
			m_name = new char[length + 1];
			strcpy(m_name, name, length);
			m_ccNum = ccNum;
			m_cvv = cvv;
			m_expMon = expMon;
			m_expYr = expYr;
		}
	}

	bool CC::read() {
		bool res = false;
		char name[72];
		short cvv, expMon, expYr;
		unsigned long long ccNum;
		cleanUp();

		cout << "Card holder name: ";
		cin.clear();
		cin.getline(name, 71);
		if (cin) {
			cout << "Credit card number: ";
			cin >> ccNum;
			if (cin) {
				cout << "Card Verification Value (CVV): ";
				cin >> cvv;
				if (cin) {
					cout << "Expiry month and year (MM/YY): ";
					cin >> expMon;
					cin.ignore();
					cin >> expYr;
					clearBuffer();
					if (cin) {
						set(name, ccNum, cvv, expMon, expYr);
					}
				} else {
					clearBuffer();
				}
			} else {
				clearBuffer();
			}
		} else {
			clearBuffer();
		}

		if (!isEmpty()) res = true;

		return res;
	}

	void CC::display(int row) const {
		char name[31];

		if (m_name != nullptr) {
			if (row <= 0) {
				cout << "Name: " << m_name << endl;
				cout << "Creditcard No: "; prnNumber();
				cout << endl << "Card Verification Value: " << m_cvv << endl;
				cout << "Expiry Date: " << m_expMon << "/" << m_expYr << endl;
			} else {
				cout << "| ";
				cout.width(3);
				cout << row << " | ";
				cout.setf(ios::left);
				if (strlen(m_name) > 30)
					strcpy(name, m_name, 30);
				else
					strcpy(name, m_name, strlen(m_name));
				cout.width(30);
				cout << name << " | ";
				cout.unsetf(ios::left);
				prnNumber();
				cout << " | " << m_cvv << " | ";
				cout.width(2);
				cout << m_expMon << "/";
				cout << m_expYr << " |" << endl;
			}
		} else {
			cout << "Invalid Credit Card Record" << endl;
		}
	}
}
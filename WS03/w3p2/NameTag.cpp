/*
 ============================================================================
 Name        : NameTag.cpp
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : September 26, 2022 - Workshop 3 - part 2
 ========
====================================================================
 */

#include <iostream>
#include "NameTag.h"
#include "Utils.h"

using namespace std;

namespace sdds {	
	// keep track of the longest name
	int longest = 0;

	// add the name
	void NameTag::set(const char* name) {
		int len = strlen(name);
		strcpy(m_name, name, len);
	}

	// set the name and keep track of the longest name
	void NameTag::set(const NameTag& nt) {
		set(nt.m_name);
		int length = strlen(nt.m_name);		
		if (longest < length) longest = length;
	}
	
	// display the names with a constant border defined by longest name
	void NameTag::display(const NameTag* nt, int numTags) const {
		char line = '*';
		for (int i = 0; i < numTags; i++) {
			cout.fill('*');
			cout.width(longest + 4);
			cout << line << endl << "* ";
			cout.fill(' ');
			cout.setf(ios::left);
			cout.width(longest);
			cout << nt[i].m_name << " *" << endl;
			cout.fill('*');
			cout.width(longest + 4);
			cout << line << endl;
		}
	}
}

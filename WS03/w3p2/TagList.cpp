/*
 ============================================================================
 Name        : TagList.cpp
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : September 26, 2022 - Workshop 3 - part 2
 ============================================================================
 */

#include "TagList.h"
#include "Utils.h"

using namespace std;

namespace sdds {
	// keep track of which name tag
	int count = 0;

	// set taglist empty
	void TagList::set() {
		m_nt = nullptr;
	}

	// allocate memory for num names
	void TagList::set(int num) {
		cleanup();
		numTags = num;
		m_nt = new NameTag[num];		
	}

	// add nametag[count]
	void TagList::add(const NameTag& nt) {	
		m_nt[count].set(nt);
		count++;		
	}

	// display names
	void TagList::print() {		
		m_nt->display(m_nt, numTags);
	}

	// deallocate memory
	void TagList::cleanup() {
		delete[] m_nt;
		m_nt = nullptr;
	}
}
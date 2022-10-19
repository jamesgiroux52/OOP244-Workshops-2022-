/*
 ============================================================================
 Name        : TagList.h
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : September 26, 2022 - Workshop 3 - part 2
 ============================================================================
 */

#ifndef SDDS_TAGLIST_H_
#define SDDS_TAGLIST_H_
#include "NameTag.h"

namespace sdds {

	class TagList {
		NameTag* m_nt;		
		int numTags = 0;		
	public:
		void set();
		void set(int num);
		void add(const NameTag& nt);
		void print();
		void cleanup();
	};
}
#endif
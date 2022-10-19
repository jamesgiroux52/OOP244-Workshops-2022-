/*
 ============================================================================
 Name        : NameTag.h
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : September 26, 2022 - Workshop 3 - part 2
 ============================================================================
 */
#ifndef SDDS_NAMETAG_H_
#define SDDS_NAMETAG_H_

namespace sdds {

	class NameTag {
		char m_name[51];		
	public:
		void set(const char* name);
		void set(const NameTag& nt);		
		void display(const NameTag* nt, int numTags) const;
	};
}
#endif
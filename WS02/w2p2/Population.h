/*
 ============================================================================
 Name        : Population.h
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : September 21, 2022 - Workshop 2 - part 2
 ============================================================================
 */


#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {

	struct Population {
		char* m_postal{nullptr};
		int* m_population;		
	};

	bool load(const char* filename);
	void display();
	void deallocateMemory();

	
	bool read(Population& p);
	int read(Population*& p);
}

#endif
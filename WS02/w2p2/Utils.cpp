/*
 ============================================================================
 Name        : Utils.cpp
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : September 19, 2022 - Workshop 2 - part 1
 ============================================================================
 */

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "Utils.h"

namespace sdds {
	
	// sort population array object
	void sortP(Population* p, int count) {
		// temporary variable for swapping entries
		char tempPostal[4];
		int* tempPopulation;
		// sort populations
		for (int i = 0; i < count; i++) {
			for (int j = i + 1; j < count; j++) {
				
				if (*(p[i].m_population) > *(p[j].m_population)) {					
					// Swap postal info
					strcpy(tempPostal, p[i].m_postal);
					strcpy(p[i].m_postal, p[j].m_postal);
					strcpy(p[j].m_postal, tempPostal);
										
					// swap population info
					tempPopulation = p[i].m_population;
					p[i].m_population = p[j].m_population;
					p[j].m_population = tempPopulation;
				}
			}
		}
		//sort postal codes within same population values
		for (int i = 0; i < count; i++) {
			for (int j = i + 1; j < count; j++) {

				if (strcmp(p[i].m_postal, p[j].m_postal) > 0 && *(p[i].m_population) == *(p[j].m_population)) {
					// Swap postal info
					strcpy(tempPostal, p[i].m_postal);
					strcpy(p[i].m_postal, p[j].m_postal);
					strcpy(p[j].m_postal, tempPostal);

					// swap population info - not really needed because the pop value is the same
					tempPopulation = p[i].m_population;
					p[i].m_population = p[j].m_population;
					p[j].m_population = tempPopulation;
				}
			}
		}
		return;
	}
}
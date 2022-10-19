/*
 ============================================================================
 Name        : Assessment.h
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : September 19, 2022 - Workshop 2 - part 1
 ============================================================================
 */

#include <iostream>

namespace sdds {
	// Assessment struct
	struct Assessment {
		double* m_mark;
		char* m_title{nullptr};
	};

	// prototypes for read and freeMem
	bool read(int& value, FILE* fptr);
	bool read(double& value, FILE* fptr);
	bool read(char* cstr, FILE* fptr);

	bool read(Assessment& a, FILE* fptr);
	void freeMem(Assessment*& a, int size);
	int read(Assessment*& a, FILE* fptr);
}
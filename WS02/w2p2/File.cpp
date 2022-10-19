/*
 ============================================================================
 Name        : File.cpp
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : September 21, 2022 - Workshop 2 - part 2
 ============================================================================
 */

 /***********************************************************************
 // OOP244 Workshop 2 p2: tester program
 //
 // File  File.cpp
 // Version 1.0
 // Date  2022/09/17
 // Author   Fardad Soleimanloo
 // Description
 // This file is incomplete and to be completed by students
 // Revision History
 // -----------------------------------------------------------
 // Name            Date            Reason
 //
 /////////////////////////////////////////////////////////////////
 ***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
	FILE* fptr = nullptr;

	// Opens a file and keeps the file pointer in the File.cpp (file scope)
	bool openFile(const char filename[]) {
		fptr = fopen(filename, "r");
		return fptr != NULL;
	}
	// Finds and returns the number of records kept in the file 
	// to be used for the dynamic memory allocation of the records in the program
	int noOfRecords() {
		int noOfRecs = 0;
		char ch;
		rewind(fptr);
		while (fscanf(fptr, "%c", &ch) == 1) {
			if (ch == '\n')
				noOfRecs += 1;
		}
		rewind(fptr);
		return noOfRecs;
	}

	// Closes the open file
	void closeFile() {
		if (fptr) fclose(fptr);
	}

	// my functions		
	bool getLine(char* postal, int& population) {
		bool ok = fscanf(fptr, "%[^,],%d\n", postal, &population) == 2;

		return ok;
	}

}
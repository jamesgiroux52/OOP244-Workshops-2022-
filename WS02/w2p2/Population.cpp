/*
 ============================================================================
 Name        : Population.cpp
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : September 21, 2022 - Workshop 2 - part 2
 ============================================================================
 */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Population.h"
#include "File.h"
#include "Utils.h"

using namespace std;

namespace sdds {

	const int POSTAL_LENGTH = 4; // includes null terminator

	// global variables
	Population* p = nullptr;
	long int numRecs = 0;


	bool load(const char* filename) {

		// try opening file
		bool ok = openFile(filename);


		if (!ok) { // can't load file
			cout << "Could not open data file: " << filename << endl;
		} else {
			numRecs = noOfRecords();
			p = new Population[numRecs];

			// Read records from the file			
			int numRecords = read(p);

			// check if it was in the expected format			
			if (numRecords < numRecs)
				cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
		}
		// close the file
		if (ok) closeFile();

		return ok;
	}

	bool read(Population& p) {
		int pop = 0;
		char postal[POSTAL_LENGTH]; // will always be 3 char plus '\0'
		bool ok = false;

		if (getLine(postal, pop)) ok = true;

		if (ok) {
			p.m_population = nullptr;
			p.m_postal = nullptr;

			p.m_population = new int(pop);
			p.m_postal = new char[POSTAL_LENGTH];

			strcpy(p.m_postal, postal);
		}

		return ok;
	}

	int read(Population*& p) {
		int count = 0;		
		bool ok = false;

		// get data
		do {
			ok = read(p[count]);
			if (ok) count++;
		} while (ok);

		return count;
	}

	void display() {
		int totalPopulation = 0;

		sortP(p, numRecs);

		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;
		for (int i = 0; i < numRecs; i++) {
			totalPopulation += *(p[i].m_population);
			cout << i + 1 << "- " << p[i].m_postal << ":  " << *(p[i].m_population) << endl;
		}
		cout << "-------------------------" << endl;
		cout << "Population of Canada: " << totalPopulation << endl;
	}

	// Free memory
	void deallocateMemory() {
		for (int i = 0; i < numRecs; i++) {
			delete p[i].m_population;
			delete[] p[i].m_postal;
		}
		delete[] p;
		p = nullptr;
	}
}
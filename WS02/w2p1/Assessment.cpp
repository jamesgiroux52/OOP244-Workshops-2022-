/*
 ============================================================================
 Name        : Assessment.cpp
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : September 19, 2022 - Workshop 2 - part 1
 ============================================================================
 */
#define _CRT_SECURE_NO_WARNINGS

#include "Assessment.h"
#include "Utils.h"


namespace sdds {

	using namespace std;
	// read overload for number of records
	bool read(int& value, FILE* fptr) {
		return fscanf(fptr, "%d", &value);
	}

	// read overload for double mark value
	bool read(double& value, FILE* fptr) {
		int res = fscanf(fptr, "%lf", &value);
		if (res != 1)
			return false; else return res;
	}

	// read overload for course name
	bool read(char* title, FILE* fptr) {
		int res = fscanf(fptr, ",%60[^\n]\n", title);
		if (res != 1)
			return false; else return res;
	}

	// Free dynamic memory
	void freeMem(Assessment*& a, int size) {
		for (int i = 0; i < size; i++) {
			delete a[i].m_mark;			
			delete[] a[i].m_title;
		}
		delete[] a; // Deallocate memory
		a = nullptr;
	}

	// read overload for getting one line and assigning memory
	bool read(Assessment& a, FILE* fptr) {
		double d = 0;
		char title[61];
		bool ok = false;
		int length = 0;

		if (read(d, fptr) && read(title, fptr)) ok = true;

		if (ok) {
			// assign pointers to nullptr
			length = strlen(title);
			a.m_mark = nullptr;
			a.m_title = nullptr;

			// assign dynamic memory
			a.m_mark = new double(d); // assign d here double(d)
			a.m_title = new char[length + 1];

			// assign values
			strcpy(a.m_title, title, length);
		}
		return ok;
	}

	// read overload for reading the whole file
	int read(Assessment*& a, FILE* fptr) {
		int numValues = 0;
		int count = 0;
		bool ok = false;

		read(numValues, fptr);
		fgetc(fptr); // get \n and scrap... ready for data

		// allocate memory		
		a = new Assessment[numValues];
        a = nullptr;

		// get data
		do {
			ok = read(a[count], fptr);
			if (ok) count++;
		} while (ok);

		// if it's a bad read free memory and return 0
		if (count != numValues) {
			freeMem(a, count);
			return 0;
		} else {
			return count;
		}
	}
}
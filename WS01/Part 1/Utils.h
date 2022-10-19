/*
 ============================================================================
 Name        : Utils.h
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : September 12, 2022 - Workshop 1 - part 1
 ============================================================================
 */

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds {

	void flushkeys();
	bool ValidYesResponse(char ch);
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);
}

#endif
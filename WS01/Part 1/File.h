/*
 ============================================================================
 Name        : File.h
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : September 12, 2022 - Workshop 1 - part 1
 ============================================================================
 */

#ifndef SDDS_FILE_H
#define SDDS_FILE_H

#include <cstdio>
#include "ShoppingRec.h"

namespace sdds {

	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif
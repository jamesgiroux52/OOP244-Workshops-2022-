/*
 ============================================================================
 Name        : Population.h
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : September 21, 2022 - Workshop 2 - part 2
 ============================================================================
 */

 /***********************************************************************
 // OOP244 Workshop 2 p2: tester program
 //
 // File  File.h
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
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds {

	// Opens a file and keeps the file pointer in the File.cpp (file scope)
	bool openFile(const char filename[]);

	// Closes the open file
	void closeFile();

	// Finds the records kept in the file to be used for the dynamic memory allocation 
	// of the records in the file
	int noOfRecords();

	//mine
	bool getLine(char* postal, int& population);
}

#endif // !SDDS_FILE_H_

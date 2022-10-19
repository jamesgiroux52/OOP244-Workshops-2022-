/*
 ============================================================================
 Name        : dictonary.h
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : September 14, 2022 - Workshop 1 - part 2
 ============================================================================
 */

#ifndef SDDS_DICTONARY_H
#define SDDS_DICTONARY_H

#include "word.h" 
using namespace std;

namespace sdds {

	const int MAX_DEFINITIONS = 8;
	const int MAX_WORDS = 100;

	struct Dictionary {
		Words word; // inherited struct for word
		int numOfLines = 0; // number of entries in the dictionary
		int numOfWords = 0; // number of words in the dictionary
		int numOfDefinitions[MAX_DEFINITIONS]; //how many defininitions a word has
	};

	int LoadDictionary(const char* filename);
	void SaveDictionary(const char* filename);
	void DisplayWord(const char* word);
	void AddWord(const char* word, const char* type, const char* definition);
	int UpdateDefinition(const char* word, const char* type, const char* definition);
	void addWordToDictionary(const char* word, const char* type, const char* definition, int i);	
}

#endif
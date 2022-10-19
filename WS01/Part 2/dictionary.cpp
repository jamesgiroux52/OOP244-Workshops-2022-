/*
 ============================================================================
 Name        : dictonary.cpp
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : September 14, 2022 - Workshop 1 - part 2
 ============================================================================
 */
#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <string.h>
#include <stdio.h>

#include "dictionary.h"
#include "word.h"

namespace sdds {

	const int MAX_WORD_LENGTH = 30;

	using namespace std;

	Dictionary d[MAX_WORDS];

	int LoadDictionary(const char* filename) {
		// clear previous dictionary struct
		for (int i = 0; i < MAX_WORDS; i++) {
			d[i].word.word[0] = '\0';
			d[i].word.type[0] = '\0';
			d[i].word.definition[0] = '\0';
		}

		// local variables
		char nextChar;
		char word[20];
		char type[MAX_TYPE_LENGTH + 1];
		char definition[MAX_DEFINITION_LENGTH + 1];
		bool ok = false;

		// assign filename, create fptr, open file
		const char* const SHOPPING_DATA_FILE = filename;
		FILE* fptr = nullptr;
		fptr = fopen(SHOPPING_DATA_FILE, "r");

		// Dr. Khan helped a bit with this logic
		if (fptr) {
			int index = 0;
			do {
				ok = fscanf(fptr, "%s", word); //reading word
				fgetc(fptr); // skip '\n'
				if (ok) {
					d->numOfWords++; // increase word count
					nextChar = std::fgetc(fptr);
				} //which is /t
				while (nextChar == '\t') {
					ok = fscanf(fptr, "%[^:]: ", type);
					ok = fscanf(fptr, "%[^\n]", definition);
					fgetc(fptr);    // skip '\n'
					nextChar = fgetc(fptr); //reading \t of next defination
					// Store values read from file
					addWordToDictionary(word, type, definition, index);
					if (nextChar == -1) ok = false;
					index++;
				} //until records are loaded
			} while (ok);
			fclose(fptr);
			return 0;
		} else {
			// file open failed
			return 1;
		}
	}

	void DisplayWord(const char* word) {
		int index = 0;
		int locations[100] = {0};
		int defCount = 0;

		// get locations of definitions in the Dictionary object
		for (int i = 0; i < MAX_WORDS; i++) {
			if (strcmp(d[i].word.word, word) == 0) {
				// Match found
				locations[index] = i;
				index++;
				defCount++;
			}
		}
		// display word and definition(s) if found
		if (index == 0) {
			cout << "NOT FOUND: word [" << word << "] is not in the dictionary." << endl;
		} else {
			index = 1;
			cout << "FOUND: [" << word << "] has [" << defCount << "] definitions:" << endl;
			for (int i = 0; i < defCount; i++) {
				cout << index << ". {" << d[locations[i]].word.type << "} " << d[locations[i]].word.definition << endl;
				index++;
			}
		}
	}

	void addWordToDictionary(const char* word, const char* type, const char* definition, int i) {
		// add a word and definition to dictionary
		strncpy(d[i].word.word, word, strlen(word) + 1);
		strncpy(d[i].word.type, type, strlen(type) + 1);
		strncpy(d[i].word.definition, definition, strlen(definition) + 1);
		d->numOfLines++;
	}

	void AddWord(const char* word, const char* type, const char* definition) {
		// add definitions 

		for (int i = 0; i < MAX_WORDS; i++) {
			if (strcmp(d[i].word.word, "\0") == 0) {
				addWordToDictionary(word, type, definition, i);
				i = MAX_WORDS; // to exit
			}
		}
	}

	void SaveDictionary(const char* filename) {
		const char* const SHOPPING_DATA_FILE = filename;
		FILE* fptr = nullptr;
		fptr = fopen(SHOPPING_DATA_FILE, "w");

		int num = d->numOfLines - 2;
		int next = 0;

		if (fptr) {
			//write to file - I really impressed with myself with this one
			for (int i = 0; i <= num; i++) {
				if (i > 0) fprintf(fptr, "\n");
				fprintf(fptr, "%s\n", d[i].word.word);
				do {
					fprintf(fptr, "\t%s: %s\n", d[next].word.type, d[next].word.definition);
					next++;
				} while (strcmp(d[i].word.word, d[next].word.word) == 0);
				i = next - 1;
			}
		}
		fclose(fptr);
	}

	int UpdateDefinition(const char* word, const char* type, const char* definition) {
		int index = 0;
		int defCount = 0;
		int locations[50];

		// get locations of definitions in the Dictionary object
		for (int i = 0; i < MAX_WORDS; i++) {
			if (strcmp(d[i].word.word, word) == 0) {
				// Match found
				locations[index] = i;
				index++;
				defCount++;
			}
		}
		// display word and definition(s) to be updated if found
		if (index > 0) {
			index = 1;
			if (defCount > 1) {
				cout << "The word [" << word << "] has multiple definitions:" << endl;
				for (int i = 0; i < defCount; i++) {
					cout << index << ". {" << d[locations[i]].word.type << "} " << d[locations[i]].word.definition << endl;
					index++;
				}
				cout << "Which one to update? 2" << endl;;
			}
			addWordToDictionary(word, type, definition, locations[1]);
			return 0; // sucess
		}
		return 1; // fail
	}
}
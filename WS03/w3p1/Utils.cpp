/***********************************************************************
// OOP244 Workshop 3 p1: tester program
//
// File	main.cpp
// Version 1.0
// Date	2022/09/23
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Utils.h"
using namespace std;
namespace sdds {
    int strlen(const char* str) {
        int len = 0;
        while (str[len]) {
            len++;
        }
        return len;
    }
    void strcpy(char* des, const char* src, int len) {
        int i;
        for (i = 0; src[i] && (len < 0 || i < len); i++) {
            des[i] = src[i];
        }
        des[i] = 0; // turning the char array des in to a cString by null terminating it.
    }
    int strcmp(const char* s1, const char* s2) {
        int i;
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }
    void clearBuffer() {
        cin.clear();
        cin.ignore(2000, '\n');
    }
}
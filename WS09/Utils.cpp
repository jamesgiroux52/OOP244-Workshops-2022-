/*************************************************************
//                  Utils Module
// File    Utils.cpp
// Version 1.3
// Date    October 31, 2022 v1.0
// Author  Fardad
// Description:
// Extra Classes and functions needed in the project
// -----------------------------------------------------------
// This was provided in one of the workshops from Fardad on
// GitHub. I fully understand how it works and is implimented.
// and have added to it:
//
// James Giroux - Nov 3, 2022 - v1.1
// -- Added getInt() - used to get a number from istream
//              and returns a number in a valid range.
// James Giroux - Nov 11, 2022 v1.2
// -- Added getYN() - Waits for user input and only accepts
//              y or Y or n or N
// James Giroux - Nov 12, 20221v1.3
// -- Added getStr() - recieves a char* and bool to make uppercase
//              will also work with csv and null terminates the
//              cstring
// -- Added stricmp() - compares two strings and ignores case
//              returns 0 if strings are the same 1 if not
// -- Added some of Fardad's utils functions for 
// -----------------------------------------------------------
*************************************************************/

#include <iostream>
#include <cstring>
#include "Utils.h"

using namespace std;

namespace sdds {
    // instantiating Utils object
    Utils ut;
    // finds length of string without using built in cstring functions
    int Utils::strlen(const char* str) {
        int len = 0;
        while (str[len])
            len++;
        return len;
    }
    // copy a cstring
    void Utils::strcpy(char* des, const char* src, int len) {
        int i;
        for (i = 0; src[i] && (len < 0 || i < len); i++)
            des[i] = src[i];
        des[i] = 0; // turning the char array des in to a cString by null terminating it.
    }
    // Compare a cstring
    int Utils::strcmp(const char* s1, const char* s2) {
        int i;
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }
    // used in Menu logic to receive a valid menu list item
    int Utils::getInt(int low, int high) {
        int num;
        bool ok = false;
        do {
            cin >> num;
            if (!cin) {
                cout << "Invalid Integer, try again: ";
                cin.clear();
            } else if (num < low || num > high)
                cout << "Invalid selection, try again: ";
            else ok = true;
            cin.ignore(1000, '\n');
        } while (!ok);
        return num;
    }
    bool Utils::getYN() {
        char ch;
        bool ok = false;
        bool res;
        do {
            cin >> ch;
            if (!cin) {
                cin.clear();
            } else if (ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n') {
                if (ch == 'Y' || ch == 'y') res = true;
                else res = false;
                ok = true;
            }
            cin.ignore(1000, '\n');
            if (!ok) cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
        } while (!ok);
        return res;
    }
    int Utils::getStr(char* str, bool upper) {
        char ch;
        bool ok = true;
        int count = 0;
        do {
            cin.get(ch);
            if (ch != ',' && ch != '\n') {
                str[count] = upper ? toupper(ch) : ch;
                count++;
            } else ok = false;
            str[count] = '\0';
        } while (ok);
        return count;
    }
    int Utils::stricmp(const char* s1, const char* s2) {
        bool ok = true;
        int count = 0;
        while (s1 && s2 && ok && s1[count] != '\0') {
            if (toupper(s1[count]) != toupper(s2[count]))
                ok = false;
            count++;
        }
        return ok ? 0 : 1;
    }
    char* Utils::alcpy(const char* cstr) {
        char* newStr{};
        if (cstr) {
            newStr = new char[strlen(cstr) + 1];
            strcpy(newStr, cstr);
        }
        return newStr;
    }
}

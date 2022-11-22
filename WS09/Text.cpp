/*************************************************************
// File    Text.cpp
// Version 1.0
// Date    November 19, 2022
// Author  James Giroux - jgiroux1@myseneca.ca
// Description:
// Text class implementation
// --------------------------------------
// Name            Date            Reason
// ----            ----            ------
// J Giroux       Nov 19, 22       Initial Version 1.0
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the
// code that my professor provided to complete my project
// milestones.
// -----------------------------------------------------------
*************************************************************/

#include <iostream>
#include "Text.h"
#include "Utils.h"

using namespace std;

namespace sdds {
    // returns the character at index as long as it is within 
    // the size of m_content
    const char& Text::operator[](int index) const {
         return m_content[index];
    }
    // constructor overload - if no value is passed then it will
    // create an empty string.
    // this is good because then we know that our dynamic memebr
    // will never be nullptr.
    Text::Text(const char* content){
        if (content)
            m_content = ut.alcpy(content);
        else
            m_content = ut.alcpy("");
    }
    // copy constructor uses copy assignment overload
    Text::Text(const Text& T) {
        *this = T;
    }
    // copy assignemt
    Text& Text::operator=(const Text& T) {
        if (this != &T) {
            delete[] m_content;
            m_content = ut.alcpy(T.m_content);
        }
        return *this;
    }
    // // destructor - ensures no mem leak when obj goes out of scope
    Text::~Text() {
        delete[] m_content;
    }
    // reads a text file into m_content
    std::istream& Text::read(std::istream& is) {
        unsigned len = getFileLength(is);
        char ch;
        int cnt = 0;
        delete[] m_content;
        m_content = new char[len + 1];
        while (is.get(ch)) {
            if (ch == '\n') m_content[cnt] = '\n';
            else m_content[cnt] = ch;
            cnt++;
        }
        m_content[cnt] = 0; // null terminate
        if (cnt > 0) is.clear();
        return is;
    }
    // display m_content
    std::ostream& Text::write(std::ostream& os) const {
        os << m_content;
        return os;
    }
    // helper overloads for insertion and extraction
    std::istream& operator>>(std::istream& is, Text& T) {
        return T.read(is);
    }
    std::ostream& operator<<(std::ostream& os, const Text& T) {
        T.write(os);
        return os;
    }
    // provided in WS to find number of bits in file
    unsigned getFileLength(std::istream& is) {
        unsigned len{};
        if (is) {
            // save the current read position
            std::streampos cur = is.tellg();
            // go to the end
            is.seekg(0, ios::end);
            // tell what is the positions (end position = size)
            len = unsigned(is.tellg());
            // now go back to where you were.
            is.seekg(cur);
        }
        return len;
    }
}
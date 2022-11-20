/*************************************************************
// File    htmlText.cpp
// Version 1.0
// Date    November 19, 2022
// Author  James Giroux - jgiroux1@myseneca.ca
// Description:
// HtmlText class implementation
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
#include "HtmlText.h"
#include "Utils.h"

namespace sdds {
    HtmlText::HtmlText(const char* title) : Text() {
        if (title) m_title = ut.alcpy(title);
        else m_title = ut.alcpy("");
   }
    HtmlText& HtmlText::operator=(const HtmlText& H) {
        if (this != &H) {
            Text::operator=(H); // dont quite understand
            delete[] m_title;
            m_title = ut.alcpy(H.m_title);
        }
        return *this;
    }
    HtmlText::HtmlText(const HtmlText& H) : Text(H) {
        *this = H;
    }
    HtmlText::~HtmlText() {
        delete[] m_title;
    }
    std::ostream& HtmlText::write(std::ostream& os) const {
        bool ms = false; // multiple spaces read
        int cnt = 0;
        os << "<html><head><title>";
        if (m_title[0] == '\0') os << "No Title";
        else os << m_title;
        os << "</title></head>\n<body>\n";
        if (m_title[0] != '\0') os << "<h1>" << m_title << "</h1>\n";
        while (operator[](cnt) != 0) {
            if (operator[](cnt) == ' ') {
                if (ms) os << "&nbsp;";
                else { ms = true; os << " "; }
            }
            else if (operator[](cnt) == '<') {
                os << "&lt;"; ms = false;
            }
            else if (operator[](cnt) == '>') {
                os << "&gt;"; ms = false;
            }
            else if (operator[](cnt) == '\n') {
                os << "<br />\n"; ms = false;
            } else {
                os << operator[](cnt); ms = false;
            }
            cnt++;
        }
        os << "</body>\n</html>";
        return os;
    }
}
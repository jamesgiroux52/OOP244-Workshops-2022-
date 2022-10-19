/*
 ============================================================================
 Name        : Mark.cpp
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : October 11, 2022 - Workshop 5 - part 2
 ============================================================================
 */

#include "Mark.h"

namespace sdds {

    // check if mark is valid (0-100)
    bool Mark::isValid(int mark) const {
        return (mark >= 0 && mark <= 100);
    }

    // set safe empty state
    void Mark::setEmpty() {
        m_mark = 0;
    }

    // one arg constructor
    Mark::Mark() : m_mark{ 0 } {} // could remove setEmpty()

    // one arg constructor - only initializes if valid mark (0-100)
    // otherwise sets to invalid state
    Mark::Mark(int mark) {
        if (isValid(mark)) m_mark = mark;
        else m_mark = -1; // only place that you would set a mark invalid
                          // so SetInvalid() was not needed - removed
    }

    // destructor - not needed
    Mark::~Mark() {
        setEmpty(); // not needed because one arg constructor does this
    } 

    // logic for operators double() char() and operator~()
    int Mark::checkMark() const {
        int res = 0;
        if (m_mark >= 0 && m_mark < 50) res = 1;
        else if (m_mark >= 50 && m_mark < 60) res = 2;
        else if (m_mark >= 60 && m_mark < 70) res = 3;
        else if (m_mark >= 70 && m_mark < 80) res = 4;
        else if (m_mark >= 80 && m_mark <= 100) res = 5;
        return res; // returns 0 if invalid mark
    }

    // type overloads
    // returs mark
    Mark::operator int() const {
        return m_mark;
    }
    // return gpa like mark
    Mark::operator double() const {
        int res = checkMark();
        if (res != 0)
            res--;
        return res;
    }
    // returns letter grade or X for invalid grade
    Mark::operator char() const {
        int res = checkMark();
        char grade{};
        if (res == 0) grade = 'X';
        else if (res == 1) grade = 'F';
        else if (res == 2) grade = 'D';
        else if (res == 3) grade = 'C';
        else if (res == 4) grade = 'B';
        else if (res == 5) grade = 'A';
        return grade;
    }
    // bool overload to test if mark is valid
    Mark::operator bool() const {
        return isValid(m_mark);
    }

    // boolean comparison operators
    bool Mark::operator==(const Mark& left) const {
        return (m_mark == left.m_mark);
    }
    bool Mark::operator!=(const Mark& left) const {
        return (!operator==(left)); // m_mark != left.m_mark
    }
    bool Mark::operator<(const Mark& left) const {
        return (m_mark < left.m_mark);
    }
    bool Mark::operator>(const Mark& left) const {
        return (m_mark > left.m_mark);
    }
    bool Mark::operator>=(const Mark& left) const {
        return (m_mark >= left.m_mark);
    }
    bool Mark::operator<=(const Mark& left) const {
        return (m_mark <= left.m_mark);
    }

    // prefix operators
    Mark& Mark::operator++() {
        if (isValid(m_mark))
            m_mark++;
        return *this;
    }
    Mark& Mark::operator--() {
        if (isValid(m_mark))
            m_mark--;
        return *this;
    }

    // postfix operators - return the original value 
    // but still increase m_value for later
    Mark Mark::operator++(int) {
        Mark temp = *this;
        operator++();
        return temp;
    }
    Mark Mark::operator--(int) {
        Mark temp = *this;
        operator--();
        return temp;
    }

    // postfix tilda operator - return if mark is a fail (0-49)
    bool Mark::operator~() const {
        return(checkMark() != 1);
    }

    // binary operators
    // assignment
    Mark& Mark::operator=(const int mark) {
        m_mark = mark;
        return *this;
    }
    // increase
    Mark& Mark::operator+=(const int mark) {
        m_mark += mark;
        return *this;
    }
    // reduce
    Mark& Mark::operator-=(const int mark) {
        m_mark -= mark;
        return *this;
    }
    // add two "Mark"'s together
    Mark Mark::operator+(const Mark& mark) const {
        return Mark(mark.m_mark + m_mark);
    }
    // add an int into a Mark
    Mark Mark::operator+(const int mark) const {
        return Mark(this->m_mark + mark);
    }
    // add right mark to left and set right empty
    Mark& Mark::operator<<(Mark& mark) {
        operator+=(mark.m_mark);
        mark.m_mark = 0;
        return *this;
    }
    // shift a mark to right and set left empty
    Mark& Mark::operator>>(Mark& mark) {
        mark.m_mark = this->m_mark;
        this->m_mark = 0;
        return *this;
    }

    // bianary helper operators - needed to assign 
    // a mark into an int
    int operator+=(int& num, const Mark& mark) {
        return (num += int(mark));
    }
    int operator-=(int& num, const Mark& mark) {
        return (num -= int(mark));
    }
    int operator+(int& num, const Mark& mark) {
        return (num + int(mark));
    }
}
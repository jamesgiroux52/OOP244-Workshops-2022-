/*
 ============================================================================
 Name        : Numbers.cpp
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : October 17, 2022 - Workshop 6 - part 1
 ============================================================================
*/
/*
 ============================================================================
 I have done all the coding by myself and only copied the code that was
 provided to complete the workshop.
 ============================================================================
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"

using namespace std;

namespace sdds {

    // copy constructor - done by me
    Numbers::Numbers(const Numbers& N) {
        setEmpty();
        m_isOriginal = false;
        operator=(N);
    }

    // copy assignment op - done by me
    Numbers& Numbers::operator=(const Numbers& N) {
        if (this != &N) {
            deallocate();
            setEmpty();
            m_isOriginal = false;
            m_numbers = new double[N.m_numCount + 1];
            for (int i = 0; i < N.m_numCount; i++) {
                m_numbers[i] = N.m_numbers[i];
                m_numCount++;
            }
        }
        return *this;
    }
    // sort either asc or desc - done by me
    Numbers& Numbers::sort(bool asc) {
        int i, j, num = m_numCount;
        double temp;
        if (asc) {
            for (i = 0; i < num - 1; i++) {
                for (j = 0; j < num - i - 1; j++) {
                    if (this->m_numbers[j] > this->m_numbers[j + 1]) {
                        temp = this->m_numbers[j];
                        this->m_numbers[j] = this->m_numbers[j + 1];
                        this->m_numbers[j + 1] = temp;
                    }
                }
            }
        } else {
            for (i = 0; i < num - 1; i++) {
                for (j = 0; j < num - i - 1; j++) {
                    if (this->m_numbers[j] < this->m_numbers[j + 1]) {
                        temp = this->m_numbers[j];
                        this->m_numbers[j] = this->m_numbers[j + 1];
                        this->m_numbers[j + 1] = temp;
                    }
                }
            }
        }
        return *this;
    }

    // overload to sort descending - done by me
    Numbers Numbers::operator-() const {
        Numbers temp = *this;
        temp.sort(false);
        return temp;
    }
    // overload to sort ascending - done by me
    Numbers Numbers::operator+() const {
        Numbers temp = *this;
        temp.sort(true);
        return temp;
    }
    // return the number of doubles in the file - done by me
    int Numbers::numberCount() const {
        int res = 0;
        char ch;
        ifstream fstr(m_filename);
        while (fstr) {
            fstr.get(ch);
            if (ch == '\n') res++;
        }
        res--;

        return res;
    }
    // load the records into the Numbers object return 
    // true if successfull - done by me
    bool Numbers::load() {
        bool res = false;
        int count = 0;
        if (m_numCount > 0) {
            double dub{};
            delete[] m_numbers;
            m_numbers = new double[m_numCount];
            ifstream fstr(m_filename);
            if (!fstr) delete[] m_numbers;
            for (int i = 0; i < m_numCount; i++) {
                fstr >> dub;
                if (!fstr.fail()) {
                    m_numbers[i] = dub;
                    count++;
                    fstr.get(); // for \n
                }
            }
            fstr.close();
        }
        if (count == m_numCount) res = true;        
        return res;
    }
    // save the numbers to a file - done by me
    void Numbers::save() {
        if (this->m_isOriginal && !isEmpty()) {
            ofstream ostr(m_filename);
            ostr.clear();
            ostr.setf(ios::fixed);
            ostr.precision(2);
            for (int i = 0; i < m_numCount; i++) {
                ostr << m_numbers[i] << "\n";
            }
            ostr.close();
        }
    }
    // += overload to add a number to the array and resize dynamic mem
    Numbers& Numbers::operator+=(double N) {
        if (!isEmpty()) {
            double* temp{};
            int i{};
            temp = new double[m_numCount + 1];
            for (i = 0; i < m_numCount; i++) {
                temp[i] = m_numbers[i];
            }
            temp[m_numCount] = N;
            m_numCount++;
            delete[] m_numbers;
            this->m_numbers = temp;
        }
        return *this;
    }
    // display formatted output
    ostream& Numbers::display(ostream& out) const {
        if (!isEmpty()) {
            out.clear();
            out << "=========================" << endl;
            if (m_isOriginal) out << m_filename << endl;
            else out << "*** COPY ***" << endl;
            out.setf(ios::fixed);
            out.precision(2);
            for (int i = 0; i < m_numCount; i++) {
                out << m_numbers[i];
                if (!(i == m_numCount - 1))
                    out << ", ";
            }
            out << endl;
            out << "-------------------------" << endl;
            out << "Total of " << m_numCount << " number(s)" << endl;
            out << "Largest number:  " << max() << endl;
            out << "Smallest number: " << min() << endl;
            out << "Average:         " << average() << endl;
            out << "=========================";
        } else {
            out << "Empty list";
        }
        return out;
    }
    // display helper
    ostream& operator<<(ostream& os, const Numbers& N) {
        N.display(os);
        return os;
    }
    // input helper
    istream& operator>>(istream& istr, Numbers& N) {
        double d{};
        istr >> d;
        if (!istr.fail()) N.operator+=(d);
        return istr;
    }

    // ********************************************
    // the following provided with workshop
    // ********************************************
    bool Numbers::isEmpty() const {
        return m_numbers == nullptr;
    }
    void Numbers::setEmpty() {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }
    void Numbers::deallocate() {
        delete[] m_filename;
        delete[] m_numbers;
    }
    void Numbers::setFilename(const char* filename) {
        delete[] m_filename;
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
    }
    double Numbers::average() const {
        double aver = 0.0;
        if (!isEmpty()) {
            for (int i = 0; i < m_numCount; i++)
                aver += m_numbers[i];
            aver = aver / m_numCount;
        }
        return aver;
    }
    double Numbers::min() const {
        double minVal = 0.0;
        if (!isEmpty()) {
            minVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (minVal > m_numbers[i]) minVal = m_numbers[i];
        }
        return minVal;
    }
    double Numbers::max() const {
        double maxVal = 0.0;
        if (!isEmpty()) {
            maxVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
        }
        return maxVal;
    }
    Numbers::Numbers() {
        setEmpty();
        m_isOriginal = false;
    }
    Numbers::Numbers(const char* filename) {
        setEmpty();
        m_isOriginal = true;
        setFilename(filename);
        m_numCount = numberCount();
        if (m_numCount <= 0 || !load()) {
            deallocate();
            setEmpty();
            m_isOriginal = false;
        }
    }
    Numbers::~Numbers() {
        save();
        deallocate();
    }
}

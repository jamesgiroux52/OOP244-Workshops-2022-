/*
 ============================================================================
 Name        : Basket.cpp
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : October 18, 2022 - Workshop 5 - part 2
 ============================================================================
*/
/*
 ============================================================================
 I have done all the coding by myself in this module
 ============================================================================
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Basket.h"

using namespace std;

namespace sdds {
    // check if a basket is empty
    bool Basket::isValid() const {
        return (m_fruits != nullptr && m_numFruits != 0 && m_cost != 0.0);
    }
    // set a basket empty
    void Basket::setEmpty() {
        m_fruits = nullptr;
        m_numFruits = 0;
        m_cost = 0;
    }
    // logic for allocating memory and copying values
    void Basket::allAndCopy(const Basket& B) {
        m_numFruits = B.m_numFruits;
        m_cost = B.m_cost;
        m_fruits = new Fruit[m_numFruits];
        for (int i = 0; i < m_numFruits; i++) {
            strcpy(m_fruits[i].m_name, B.m_fruits[i].m_name);
            m_fruits[i].m_qty = B.m_fruits[i].m_qty;
        }
    }
    // default constructor
    Basket::Basket() : m_fruits(nullptr), m_numFruits(0), m_cost(0) {}
    // custom cunstructor
    Basket::Basket(Fruit* frt, int num, double cost)
        :m_fruits(nullptr), m_numFruits(num), m_cost(cost) {
        if (num > 0 && frt && cost > 0) {
            m_fruits = new Fruit[num];
            for (int i = 0; i < num; i++) {
                m_fruits[i] = frt[i];
            }
        } else {
            m_fruits = nullptr;
            *this = Basket();
        }
    }
    // copy constructor
    Basket::Basket(const Basket& B) {
        setEmpty();
        *this = B;
    }
    // copy assignment operator
    Basket& Basket::operator=(const Basket& B) {
        if (this != &B) {
            delete[] m_fruits;
            allAndCopy(B);
        }
        return *this;
    }
    // destructor
    Basket::~Basket() {
        delete[] m_fruits;
        m_fruits = nullptr;
    }
    // set a price for the basket
    void Basket::setPrice(double cost) {
        m_cost = cost;
    }
    // check if a basket has fruit
    Basket::operator bool() const {
        return m_numFruits > 0;
    }
    // += overload - copy old values, resize array, and set values
    Basket& Basket::operator+=(Fruit frt) {
        Fruit* temp = nullptr;
        if (frt.m_name) {
            temp = new Fruit[m_numFruits + 1];
            for (int i = 0; i < m_numFruits; i++) {
                temp[i] = m_fruits[i];
            }
            temp[m_numFruits] = frt;
            m_numFruits++;
            delete[] m_fruits;
            this->m_fruits = temp;
        }
        return *this;
    }
    // display member - return output stream
    ostream& Basket::display(ostream& ostr) const {
        if (isValid()) {
            ostr << "Basket Content:" << endl;
            ostr.setf(ios::fixed);
            ostr.precision(2);
            for (int i = 0; i < m_numFruits; i++) {
                ostr.width(10);
                ostr << m_fruits[i].m_name << ": ";
                ostr << m_fruits[i].m_qty << "kg" << endl;
            }
            ostr << "Price: " << m_cost << endl;
            ostr.unsetf(ios::fixed);
        } else {
            ostr << "The basket is empty!" << endl;
        }
        return ostr;
    }
    // helper insertion overload - calls display
    ostream& operator<<(ostream& ostr, const Basket& basket) {
        basket.display(ostr);
        return ostr;
    }
}
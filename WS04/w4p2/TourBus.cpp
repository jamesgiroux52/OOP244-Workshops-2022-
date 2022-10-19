/*
 ============================================================================
 Name        : TourBus.cpp
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : October 3, 2022 - Workshop 4 - part 2
 ============================================================================
 */

#include <iostream>
#include "TourBus.h"
#include "TourTicket.h"

using namespace std;
namespace sdds {

	// one arg constructor - not used but good practice
	TourBus::TourBus() {
		init();
	}

	// single arg constructor called in main()
	TourBus::TourBus(int num) {
		init();
		m_numTickets = num;
		m_passenger = new TourTicket[num];
	}

	// destructor - deallocate memory and set to safe state
	TourBus::~TourBus() {
		delete[] m_passenger;
		m_passenger = nullptr;
	}

	// check if object is empty
	bool TourBus::isEmpty() const {
		return (m_passenger == nullptr);
	}

	// check if bus is loaded
	bool TourBus::fullBus() const {
		return (m_numCheckedIn == m_numTickets);
	}

	// Set empty
	void TourBus::init() {
		m_passenger = nullptr;
		m_numTickets = 0;
		m_numCheckedIn = 0;
	}

	// Validate bus size
	bool TourBus::validTour() const {
		return (m_numTickets == 4 || m_numTickets == 16 || m_numTickets == 22);
	}

	// check in the passengers
	TourBus& TourBus::board() {
		char name[41]{};
		cout << "Boarding " << m_numTickets << " Passengers:" << endl;
		for (int i = 0; i < m_numTickets; i++) {
			cout << i + 1 << "/" << m_numTickets << "- Passenger Name: ";
			cin.getline(name, 40);
			m_passenger[i].issue(name);
			m_numCheckedIn++;
		}
		return *this;
	}

	// List all the passengers if the bus is full
	void TourBus::startTheTour() const {
		int row = 0;
		if (fullBus() && !isEmpty()) {
			cout << "Starting the tour...." << endl;
			cout << "Passenger List:" << endl;
			cout << "|Row | Passenger Name                           | Num |" << endl;
			cout << "+----+------------------------------------------+-----+" << endl;
			for (int i = 0; i < m_numTickets; i++) {
				row++;
				cout << "|";
				cout.width(3);
				cout << row << " ";
				m_passenger[i].display();
				cout << endl;
			}
			cout << "+----+------------------------------------------+-----+" << endl;
		} else {
			cout << "Cannot start the tour, the bus is not fully boarded!" << endl;
		}
	}
}
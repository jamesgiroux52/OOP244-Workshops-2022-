/*
 ============================================================================
 Name        : ShoppingList.cpp
 Author      : James Giroux - jgiroux1@myseneca.ca
 Student #   : 129198164
 Section     : NEE
 Date        : September 12, 2022 - Workshop 1 - part 1
 ============================================================================
 */

#include <iostream>
#include "ShoppingList.h"
#include "ShoppingRec.h"
#include "Utils.h"
#include "File.h"


namespace sdds {

    using namespace std;

    const int MAX_NO_OF_RECS = 15;
    ShoppingRec recs[MAX_NO_OF_RECS] = {};
    int noOfRecs = 0;

    bool loadList() {
        ShoppingRec shpr = {};
        bool ok = false;
        if (openFileForRead()) {
            ok = true;
            while (noOfRecs < MAX_NO_OF_RECS &&
                freadShoppingRec(&shpr)) {
                recs[noOfRecs++] = shpr;

            }
            closeFile();
        }
        return ok;
    }

    void displayList() {
        for (int i = 0; i < noOfRecs; i++) {
            cout << (i + 1) << "-";
            displayShoppingRec(&recs[i]);
        }
    }

    bool saveList() {
        bool ok = false;
        if (openFileForOverwrite()) {
            ok = true;
            for (int i = 0; i < noOfRecs; i++) {
                fwriteShoppintRec(&recs[i]);
            }
            closeFile();
        }
        return ok;
    }

    void clearList() {
        cout << "This will remove all the items from the list;" << endl
            << "Are you sure? (Y)es/(N)o" << endl;
        if (yes()) {
            noOfRecs = 0;
        }
        else {
            cout << "Cancelled!" << endl;
        }
    }
    void toggleBought() {
        cout << "Item number: ";
        toggleBoughtFlag(&recs[readInt(1, noOfRecs) - 1]);
    }

    void addItemToList() {
        if (noOfRecs < MAX_NO_OF_RECS) {
            recs[noOfRecs] = getShoppingRec();
            noOfRecs += !isShoppingRecEmpty(&recs[noOfRecs]);
        }
        else {
            cout << "Shopping List is full!" << endl;
        }
    }

    void removeItemfromList() {
        if (!listIsEmpty()) {
            int value = 0;
            cout << "Item number to delete: ";
            value = readInt(1, noOfRecs);
            cout << "Deleting following item, are you sure?" << endl;
            displayShoppingRec(&recs[value - 1]);
            cout << "(Y)es/(N)o: ";
            if (yes()) {
                removeItem(value - 1);
            }
            else {
                cout << "Cancelled!" << endl;
            }
        }
        else {
            cout << "List is empty!" << endl;
        }

    }

    void removeBoughtItems() {
        if (!listIsEmpty()) {
            cout << "Removing bought items, are you sure?" << endl;
            cout << "(Y)es/(N)o: ";
            if (yes()) {
                for (int i = 0; i < noOfRecs; i++) {
                    if (recs[i].m_bought) removeItem(i--);
                }
            }
            else {
                cout << "Cancelled!" << endl;
            }
        }
        else {
            cout << "List is empty!" << endl;
        }
    }

    bool listIsEmpty() {
        return noOfRecs == 0;
    }

    void removeItem(int index) {
        if (index >= 0 && index < noOfRecs) {
            noOfRecs--;
            for (int i = index; i < noOfRecs; i++) {
                recs[i] = recs[i + 1];
            }
        }
    }
}
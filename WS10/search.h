/*************************************************************
// File    search.h
// Version 1.0
// Date    November 28, 2022
// Author  James Giroux - jgiroux1@myseneca.ca
// Description:
// search header file
// --------------------------------------
// Name            Date            Reason
// ----            ----            ------
// J Giroux       Nov 28, 22       Initial Version 1.0
// -----------------------------------------------------------
// I have done all the coding by myself and only used the
// code that was provided to complete my workshop
// -----------------------------------------------------------
*************************************************************/

#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_

#include "Collection.h"

namespace sdds {
    // T must support overload== for each type passed
    // Collection must know how to add items
    template <typename T>
    bool search(T* arr, int numElem, const char* find, 
            Collection<T>& coll) 
    {
        int count = 0;
        for (int i = 0; i < numElem; i++) 
            if (arr[i] == find) { // == overload
                coll.add(arr[i]); // Collection::add()
                count++;
            }
        // if there is no matches return false
        return count ? true : false;
    }
}

#endif // !SDDS_SEARCH_H_
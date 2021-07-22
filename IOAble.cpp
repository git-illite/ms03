//==============================================
// Name:           Abdalla Aden
// Student Number: 021720057
// Email:          aaaden1@myseneca.ca
// Section:        NDD
// Date:           Jul 14 2021
//==============================================
// Project MS2 
//==============================================
#include "IOAble.h"
#include <iostream>

namespace sdds {
    std::ostream& operator<<(std::ostream& ostr, const IOAble& IO)
    {
        return IO.write(ostr);
    }

    std::istream& operator>>(std::istream& istr, IOAble& IO)
    {
        return IO.read(istr);
    }

    IOAble::~IOAble()
    {
    }
}
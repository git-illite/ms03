//==============================================
// Name:           Abdalla Aden
// Student Number: 021720057
// Email:          aaaden1@myseneca.ca
// Section:        NDD
// Date:           Jul 14 2021
//==============================================
// Project MS2 
//==============================================
#ifndef SDDS_IOAble_H
#define SDDS_IOAble_H
#include <iostream>
namespace sdds {
	class IOAble {

	public:
		virtual std::ostream& csvWrite(std::ostream& ostr)const = 0;
		virtual std::istream& csvRead(std::istream& istr) = 0;
		virtual std::ostream& write(std::ostream& ostr)const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
		virtual ~IOAble();
	};
	std::ostream& operator<<(std::ostream& ostr, const IOAble& IO);
	std::istream& operator>>(std::istream& istr, IOAble& IO);
}
#endif

//==============================================
// Name:           Abdalla Aden
// Student Number: 021720057
// Email:          aaaden1@myseneca.ca
// Section:        NDD
// Date:           Jul 18 2021
//==============================================
// Project MS3 
//==============================================
#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H
#include <iostream>
#include "IOAble.h"
#include "Ticket.h"

namespace sdds {
	class Patient : public IOAble {
		char* m_name;
		int m_ohip;
		Ticket m_Ticket;
		bool m_flag;
		
	public:
		Patient(int ticNum, bool c);
		Patient(const Patient&) = delete;
		Patient& operator=(const Patient&) = delete;
		virtual	~Patient();
		virtual char type()const = 0;
		bool fileIO()const;
		void fileIO(bool);
		bool operator==(char)const;
		bool operator==(const Patient&)const;
		void setArrivalTime();
		operator Time()const;
		int	number()const;
		std::ostream& csvWrite(std::ostream& ostr)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};
	std::ostream& operator<<(std::ostream& ostr, const Patient& P);
	std::istream& operator>>(std::istream& istr, Patient& P);
}

#endif // !SDDS_PATIENT_H_


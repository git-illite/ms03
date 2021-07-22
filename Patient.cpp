//==============================================
// Name:           Abdalla Aden
// Student Number: 021720057
// Email:          aaaden1@myseneca.ca
// Section:        NDD
// Date:           Jul 18 2021
//==============================================
// Project MS3 
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "Patient.h"
#include "Time.h"
#include "utils.h"
#include "Patient.h"
using namespace std;
namespace sdds {
	Patient::Patient(int ticNum, bool c) :m_Ticket(ticNum),m_flag(c)
	{
		m_name = nullptr;
		m_ohip = 0;
	}
	Patient::~Patient()
	{
		delete[] m_name;
	}
	bool Patient::fileIO() const
	{
		return m_flag;
	}
	void Patient::fileIO(bool c)
	{
		m_flag = c;
	}
	bool Patient::operator==(char c)const
	{
		return (c == type());
	}
	bool Patient::operator==(const Patient& p)const
	{
		return ( p == type());
	}
	void Patient::setArrivalTime()
	{
		m_Ticket.resetTime();
	}
	Patient::operator Time() const
	{
		return Time(m_Ticket);
	}
	int Patient::number() const
	{
		return m_Ticket.number();
	}
	std::ostream& Patient::csvWrite(std::ostream& ostr) const
	{
		ostr << type() << "," << m_name << "," << m_ohip << ",";
		m_Ticket.csvWrite(ostr);
		return ostr;
	}
	std::istream& Patient::csvRead(std::istream& istr)
	{
		delete[] m_name;
		m_name = getcstr(nullptr, istr, ',');
		istr >> m_ohip;
		istr.ignore(1000, ',');
		return m_Ticket.csvRead(istr);
	}
	std::ostream& Patient::write(std::ostream& ostr) const
	{
		ostr << m_Ticket << endl;
		int i = 0;
		for (i = 0; m_name[i] && i < 25; i++) ostr << m_name[i];
		ostr << ", OHIP: " << m_ohip;
		return ostr;
	}
	std::istream& Patient::read(std::istream& istr)
	{
		delete[] m_name;
		m_name = getcstr("Name: ");
		m_ohip = getInt(100000000, 999999999, "OHIP:", "Invalid OHIP Number, ");
		return istr;
	}
	ostream& operator<<(std::ostream& ostr, const Patient& P)
	{
		return P.write(ostr);
	}
	istream& operator>>(std::istream& istr, Patient& P)
	{
		return P.read(istr);
	}
}
//==============================================
// Name:           Abdalla Aden
// Student Number: 021720057
// Email:          aaaden1@myseneca.ca
// Section:        NDD
// Date:           Jul 10 2021
//==============================================
// Project MS1 
//==============================================
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Time& Time::setToNow()
	{
		m_min=getTime();
		return *this;
	}
	Time::Time(unsigned int min)
	{
		m_min = min;
	}
	std::ostream& Time::write(std::ostream& ostr) const
	{
		int hours, mins;
		if (m_min > 0) {
			hours = m_min / 60;
			mins = m_min % 60;
			if (hours <= 9)ostr << "0" << hours << ":";
			else ostr << hours << ":";
			if (mins <= 9) ostr << "0" << mins;
			else ostr << mins;
			return ostr;
		}
		else ostr << "00:00";

		return ostr;
	}
	std::istream& Time::read(std::istream& istr)
	{
		int hours = 0, mins = 0;
		char s;
		istr >> hours >> s >> mins;
		if (istr.fail()) {
			cin.ignore(1000, '\n');
			istr.setstate(ios::failbit);
		}
		else if ( hours < 0 || mins < 0 || s != ':') {
			istr.setstate(ios::failbit);
		}
		else {
			m_min = (hours * 60)+mins;
		}
		return istr;
	}
	/*Time& Time::operator-=(const Time& D)
	{
		if (this != &D) {
			if (m_min > D.m_min) m_min -= D.m_min;
			else if (m_min < D.m_min) {
				m_min = (m_min + 1440) - D.m_min;
			}
		}
		return *this;
	}*/
	Time& Time::operator-=(const Time& D)
	{
		if (this != &D) {
			(m_min > D.m_min) ? m_min -= D.m_min: m_min = (m_min + 1440) - D.m_min;//im actually surprised this works
		}
		return *this;
	}
	Time Time::operator-(const Time& D) const
	{
		Time tempTime;
		unsigned int temp = m_min;
		if (this != &D) {
			if (m_min > D.m_min) { tempTime.m_min = m_min - D.m_min; }
			else {
				while (temp < D.m_min){
					temp += 1440;
				}
				tempTime.m_min = temp - D.m_min;
			}
		}
		
		return tempTime;
	}
	Time& Time::operator+=(const Time& D)
	{
		m_min = m_min + D.m_min;
		return *this;
	}
	Time Time::operator+(const Time& D) const
	{
		Time tempTime;
		tempTime = m_min + D.m_min;
		return tempTime;
	}
	Time& Time::operator=(unsigned int val)
	{
		m_min = val;
		return *this;
	}
	Time& Time::operator *= (unsigned int val) {
		m_min = val * m_min;
		return *this;
	}
	Time& Time::operator /= (unsigned int val) {
		m_min = m_min / val;
		return *this;
	}
	Time Time::operator *(unsigned int val)const { 
		Time tempTime;
		tempTime.m_min= (m_min * val);
		return tempTime; 
	}

	Time Time::operator /(unsigned int val)const { 
		Time tempTime;
		tempTime.m_min = (m_min / val);
		return tempTime;
	}
	Time::operator unsigned int() const
	{
		return int(m_min);
	}
	Time::operator int() const
	{
		return int(m_min);
	}
	std::ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		return D.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, Time& D)
	{
		return D.read(istr);
	}
}
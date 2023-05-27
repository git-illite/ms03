//==============================================
// Name:           Abdalla Aden
// Student Number: 021720057
// Email:          aaaden1@myseneca.ca
// Section:        NFF
// Date:           Nov 17 2021
//==============================================
// MS 01
//==============================================
#include "Station.h"
#include "Utilities.h"
#include <iomanip>
namespace sdds {

	unsigned Station::m_widthField = 0;
	unsigned Station::id_generator = 0;

	Station::Station(const std::string& str)
	{
		Utilities obj;
		size_t pos{},fpos;
		bool check = false;
		m_item = obj.extractToken(str,pos,check);
		fpos = (str.find(m_item)) + m_item.length()+1;
		m_serialNumber = stoi(obj.extractToken(str,fpos,check));
		std::string strNum = std::to_string(m_serialNumber);
		fpos = (str.find(strNum)) + strNum.length()+1;
		m_numItems = stoi(obj.extractToken(str,fpos,check));
		strNum = std::to_string(m_numItems);
		//fpos = (fpos) + strNum.length();
		m_widthField = (m_widthField >obj.getFieldWidth()) ? m_widthField : obj.getFieldWidth();
		m_desc = obj.extractToken(str,fpos,check);
		m_id = ++id_generator;
	}

	const std::string& Station::getItemName() const
	{
		return m_item;
	}

	size_t Station::getNextSerialNumber()
	{
		return m_serialNumber++;
	}

	size_t Station::getQuantity() const
	{
		return m_numItems;
	}

	void Station::updateQuantity()
	{
		if (m_numItems - 1 < 0) m_numItems = 0;
		else m_numItems--;
	}

	void Station::display(std::ostream& os, bool full) const
	{
		os << '[' << std::setw(3) << std::setfill('0') << std::right << m_id << "] Item: " 
			<< std::setw(m_widthField) << std::setfill(' ') << std::left << m_item
			<< " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << "]"
			<< std::setfill(' ') << std::left;
		if (full) {
			os << " Quantity: " << std::setw(m_widthField) << m_numItems
			<< " Description: " << m_desc;
		}
		os << std::endl;
	}

}
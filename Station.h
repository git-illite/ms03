//==============================================
// Name:           Abdalla Aden
// Student Number: 021720057
// Email:          aaaden1@myseneca.ca
// Section:        NFF
// Date:           Nov 17 2021
//==============================================
// MS 01
//==============================================
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <string>

namespace sdds {
	class Station
	{
		unsigned m_id;
		std::string m_item;
		std::string m_desc;
		size_t m_serialNumber{};
		size_t m_numItems{};
		static unsigned m_widthField;
		static unsigned id_generator;
	public:
		Station(const std::string& str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif

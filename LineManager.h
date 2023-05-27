//==============================================
// Name:           Abdalla Aden
// Student Number: 021720057
// Email:          aaaden1@myseneca.ca
// Section:        NFF
// Date:           Nov 28 2021
//==============================================
// MS 03
//==============================================
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include "Workstation.h"
#include <vector>
namespace sdds {
	class LineManager
	{
		std::vector<Workstation*> activeLine;
		size_t m_cntCustomerOrder{};
		Workstation* m_firstStation{ nullptr };

	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void linkStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif
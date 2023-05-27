//==============================================
// Name:           Abdalla Aden
// Student Number: 021720057
// Email:          aaaden1@myseneca.ca
// Section:        NFF
// Date:           Nov 28 2021
//==============================================
// MS 03
//==============================================
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include "Station.h"
#include "CustomerOrder.h"
#include <deque>
namespace sdds {
	extern std::deque<CustomerOrder> pending;
	extern std::deque<CustomerOrder> completed;
	extern std::deque<CustomerOrder> incomplete;
	class Workstation :public Station
	{
		std::deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation{ nullptr };

	public:
		Workstation(std::string obj); //Station(obj)
		Workstation(const Workstation&) = delete;
		Workstation(Workstation&&)noexcept = delete;
		Workstation& operator=(const Workstation&) = delete;
		Workstation& operator=(Workstation&&)noexcept = delete;
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);

	};
}
#endif

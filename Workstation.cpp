//==============================================
// Name:           Abdalla Aden
// Student Number: 021720057
// Email:          aaaden1@myseneca.ca
// Section:        NFF
// Date:           Nov 28 2021
//==============================================
// MS 03
//==============================================
#include "Workstation.h"
namespace sdds {
	std::deque<CustomerOrder> pending{};
	std::deque<CustomerOrder> completed{};
	std::deque<CustomerOrder> incomplete{};
	Workstation::Workstation(std::string obj) :Station(obj)
	{
	}
	void Workstation::fill(std::ostream& os)
	{
		if(!m_orders.empty())
		m_orders.front().fillItem(*this, os);
	}
	bool Workstation::attemptToMoveOrder()
	{
		bool move = false;
		if (!m_orders.empty()) {
			if (m_orders.front().isItemFilled(getItemName()) || (getQuantity()<1)) {
				if (m_pNextStation!=nullptr) {
					*m_pNextStation += std::move(m_orders.front());
					m_orders.pop_front();
				}
				else {
					if (m_orders.front().isFilled()) {
						completed.push_back(std::move(m_orders.front()));
						m_orders.pop_front();
					}
					else {
						incomplete.push_back(std::move(m_orders.front()));
						m_orders.pop_front();
					}
				}
				move = true;
			}
		}
		return move;
	}
	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}
	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}
	void Workstation::display(std::ostream& os) const
	{
		if (m_pNextStation!=nullptr) {
			os << getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
		}
		else {
			os << getItemName() << " --> " << "End of Line" << std::endl;
		}
	}
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
}
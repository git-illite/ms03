//==============================================
// Name:           Abdalla Aden
// Student Number: 021720057
// Email:          aaaden1@myseneca.ca
// Section:        NFF
// Date:           Nov 21 2021
//==============================================
// MS 02
//==============================================
#include "CustomerOrder.h"
#include "Utilities.h"
#include <algorithm>
#include <iomanip>
namespace sdds {
	size_t CustomerOrder::m_widthField = 0;
	CustomerOrder::CustomerOrder(const std::string& str)
	{
		Utilities temp;
		char del = temp.getDelimiter();
		size_t n{}, pos{};
		bool more = true;
		
		n = str.find(del, pos);
		m_name = str.substr(pos, n);
		pos = n + 1;
		n = str.find(del, pos);
		m_product = temp.extractToken(str, pos, more);
		//m_product = str.substr(pos, n-pos);
		//m_widthField = m_product.length();
		
		if (more) {
			more = false;
			m_cntItem = std::count(str.begin(), str.end(), del)-1;
			m_lstItem = new Item * [m_cntItem];
			pos = n + 1;
			for (size_t i=0u; i < m_cntItem; i++) {
				n = str.find(del, pos)+1;
				//std::string nStr = str.substr(pos, str.length());
				m_lstItem[i] = new Item(temp.extractToken(str, pos, more));
				pos = n;
				
			}
		}
		
		m_widthField = temp.getFieldWidth() > m_widthField ? temp.getFieldWidth() : m_widthField;

	}
	CustomerOrder::CustomerOrder(const CustomerOrder& obj)
	{
		throw "no copying allowed";
	}
	CustomerOrder::CustomerOrder(CustomerOrder&& obj) noexcept
	{
		*this = std::move(obj);
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& obj) noexcept
	{
		if (this != &obj) {
			for (auto i = 0u; i < m_cntItem; i++) {
				delete m_lstItem[i];
			}
			delete[] m_lstItem;
			
			m_cntItem = obj.m_cntItem;
			m_lstItem = obj.m_lstItem;
			m_name = obj.m_name;
			m_product = obj.m_product;
			m_widthField = obj.m_widthField;

			obj.m_cntItem = 0u;
			obj.m_lstItem = nullptr;
			obj.m_name = "";
			obj.m_product= "";
			

		}
		return *this;
	}
	CustomerOrder::~CustomerOrder()
	{
		for (auto i = 0u; i < m_cntItem; i++) {
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
		m_lstItem = nullptr;
	}
	bool CustomerOrder::isFilled() const
	{
		bool filled = true;
		for (size_t i = 0u; i < m_cntItem && filled; i++) {
			filled = m_lstItem[i]->m_isFilled;
			//if (filled==false)break;
		}
		return filled;
	}
	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool filled = true;
		for (size_t i = 0u; i < m_cntItem && filled; i++) {
			if (m_lstItem[i]->m_itemName == itemName) 
				filled = m_lstItem[i]->m_isFilled;
			//if (filled == false) break;
		}
		return filled;
	}
	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (size_t i = 0u; i < m_cntItem; i++) {
			if (station.getItemName() == m_lstItem[i]->m_itemName) {
				if (station.getQuantity() > 0) {
					m_lstItem[i]->m_isFilled = true;
					station.updateQuantity();
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					os << "    Filled " << m_name << ", "
					   << m_product << " [" << m_lstItem[i]->m_itemName 
					   << "]" << std::endl;
				}
				else {
					m_lstItem[i]->m_isFilled = false;
					os << "    Unable to fill " << m_name << ", "
						<< m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
				}
			}
		}
	}
	void CustomerOrder::display(std::ostream& os) const
	{
		os<<m_name<<" - "<<m_product<<std::endl;
		for (size_t i = 0u; i < m_cntItem; i++) {
		os<<"[" << std::setw(6) <<std::setfill('0') << std::right <<m_lstItem[i]->m_serialNumber<<"] "
		<<std::left<<std::setw(m_widthField) << std::setfill(' ') <<m_lstItem[i]->m_itemName
		<< " - "<< (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED")<< std::endl;
		}
	}
}

//==============================================
// Name:           Abdalla Aden
// Student Number: 021720057
// Email:          aaaden1@myseneca.ca
// Section:        NFF
// Date:           Nov 28 2021
//==============================================
// MS 03
//==============================================
#include "LineManager.h"
#include "Utilities.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
namespace sdds {
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		std::ifstream f(file);
		if (!f)
			throw std::string("Unable to open [") + file + "] file.";

		else {
			Utilities temp;
			std::string first{}, second{}, line;
			Workstation* firW{};
			Workstation* secW{};
			size_t n{};
			bool more = false;
			while (std::getline(f, line)) {
				if (!line.empty()) {
					first = temp.extractToken(line, n, more);
					firW = *std::find_if(stations.begin(), stations.end(), [&](Workstation* shop) {
						return shop->getItemName() == first;
						});
					activeLine.push_back(firW);

					if (more) {
						n = line.find(temp.getDelimiter())+1;
						second = temp.extractToken(line, n, more);
						secW = *std::find_if(stations.begin(), stations.end(), [&](Workstation* shop) {
							return shop->getItemName() == second;
							});
						firW->setNextStation(secW);
					}
				}
			}
			for_each(stations.begin(), stations.end(), [&](Workstation* tmp) {
				m_firstStation = *find_if(stations.begin(), stations.end(), [&](Workstation* station) {
					return station->getNextStation() == m_firstStation;
					});
				});
		}
		f.close();
		m_cntCustomerOrder = pending.size();

	}

	void LineManager::linkStations()
	{
		Workstation* first = m_firstStation;
		std::vector<Workstation*> temp;
		while (first) {
			temp.push_back(first);
			first = first->getNextStation();
		}
		activeLine = temp;
	}

	bool LineManager::run(std::ostream& os)
	{
		static size_t count{};
		os << "Line Manager Iteration: " << ++count << std::endl;

		if (!pending.empty()) {
			*m_firstStation += std::move(pending.front());
			pending.pop_front();
		}
		
		std::for_each(activeLine.begin(), activeLine.end(), [&](Workstation* shop) {
			shop->fill(os);
			});

		std::for_each(activeLine.begin(), activeLine.end(), [](Workstation* shop) {
			shop->attemptToMoveOrder();
			});
		

		return m_cntCustomerOrder == (completed.size() + incomplete.size());
	}

	void LineManager::display(std::ostream& os) const
	{
		for (auto item : activeLine)
			item->display(os);
	}



}
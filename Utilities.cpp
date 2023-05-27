//==============================================
// Name:           Abdalla Aden
// Student Number: 021720057
// Email:          aaaden1@myseneca.ca
// Section:        NFF
// Date:           Nov 17 2021
//==============================================
// MS 01
//==============================================
#include "Utilities.h"
#include <sstream>

namespace sdds {
    char Utilities::m_delimiter = ';';
    void Utilities::setFieldWidth(size_t newWidth)
    {
        if (newWidth > 0)
            m_widthField = newWidth;
    }

    size_t Utilities::getFieldWidth() const
    {
        return this->m_widthField;
    }

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
    {

        if ((str[next_pos] == m_delimiter)) {
            more = false;
            throw "Delimiter at start";
        }
       
        /*if (n != std::string::npos) {
            more = false;
        }*/
        else {

            std::string line, newStr, token;
            size_t n = str.find(m_delimiter, next_pos);
            newStr = str.substr(next_pos, n);
            std::stringstream ss(newStr);
            (std::getline(ss, line, m_delimiter));
            token = line;
            if (n == std::string::npos) {
                more = false;
            }
            else more = true;
            if (token.length() > m_widthField)m_widthField = token.length();
            next_pos=n+1;
            return token;
        }
    }

    void Utilities::setDelimiter(char newDelimiter)
    {
        m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter()
    {
        return m_delimiter;
    }
}
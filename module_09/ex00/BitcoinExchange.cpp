#include "BitcoinExchange.hpp"

std::map<std::string, float> BitcoinExchange::getData() const{
	return m_data; }

bool BitcoinExchange::isValidDate(std::string line) {
	return (not (line.size() != 10 || line[4] != '-' || line[7] != '-' 
		|| atol(line.c_str()) < 2009 || atol(line.c_str()) > 2023
		|| atol(line.c_str() + 5) < 1 || atol(line.c_str() + 5) > 12
		|| atol(line.c_str() + 8) < 1 || atol(line.c_str() + 8) > 31));
}

bool BitcoinExchange::isValidValue(std::string line) {
	if (line.size() == 0)
		return false;
	if (line.find(".") != line.rfind("."))
		return false;
	for (size_t i = 0; i < line.size(); i++){
		if (isdigit(line[i]) || line[i] == '.')
			continue;
		else
			return false;
	}
	if (strtof(line.c_str(), NULL) > FLT_MAX)
		return false;
	return true;
}

void BitcoinExchange::parseDatabase(std::string filename) {
	std::string line, date;

	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw ErrorOpenException();
	getline(file, line);
	if (line.compare("date,exchange_rate"))
			throw CustomException("First line must be \"date,exchange_rate\"");
	while (getline(file, line, ','))
	{
		if (!isValidDate(line))
			throw CustomException("Invalid date");
		date = line;
		getline(file, line);
		if (m_data.find(date) != m_data.end())
			throw CustomException("Duplicate date in the database");
		if (!isValidValue(line))
			throw CustomException("Invalid date");
		m_data.insert(std::make_pair(date, strtof(line.c_str(), NULL)));
	}
	file.close();
}

void printDate(Data data)
{
		std::cout << data.time.tm_year << "-" << data.time.tm_mon << "-" << data.time.tm_mday << std::endl;
}

void BitcoinExchange::exchange(std::string inputname) {
	std::ifstream file(inputname.c_str());
	if (!file.is_open())
		throw ErrorOpenException();

	std::string line, date;
	std::string buffer_error, buffer_value;

	getline(file, line);
	if (line.compare("date | value"))
			throw CustomException("First line must be \"date | value\"");
	while (getline(file, line))
	{
		try {
			if (line.size() < 10)
				throw CustomException("Error: bad format.");
			if (!isValidDate(line.substr(0, 10))){
				buffer_error = "Error: bad input => " + line; // potential segfault
				throw CustomException(buffer_error.c_str());
			}
			date = line.substr(0, 10);
			line.erase(0, 10);
			if (line.compare(0, 3, " | "))
				throw CustomException("Error: bad format.");
			line.erase(0, 3);

			std::map<std::string, float>::iterator it = m_data.find(date);
			if (it == m_data.end())
			{
				it = m_data.lower_bound(date);
				if (it != m_data.begin() && it != m_data.end())
					it--;
			}
			float value = strtof(line.c_str(), NULL);
			if (value < 0)
				throw CustomException("Error: not a positive number.");
			if (value > 1000)
				throw CustomException("Error: too large number.");
			if (it == m_data.end())
				throw CustomException("Error: date too recent.");
			if (!isValidValue(line))
				throw CustomException("Error: bad format.");
			std::cout << date << " => "	<< line << " = " << value * it->second << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;		
		}
	}
}
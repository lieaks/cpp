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

// Data setDate(std::string line)
// {
// 	std::string buffer;
// 	Data data;
// 	buffer = line.substr(0, 4);
// 	data.time.tm_year = atoi(buffer.c_str());
// 	buffer = line.substr(5, 2);
// 	data.time.tm_mon = atoi(buffer.c_str());
// 	buffer = line.substr(8, 2);
// 	data.time.tm_mday = atoi(buffer.c_str());
// 	return data;
// }

// bool isNotValidDate(Data data)
// {
// 	if (data.time.tm_mon < 1 || data.time.tm_mon > 12 || data.time.tm_mday < 1 || data.time.tm_mday > 31)
// 		return 1;
// 	return 0;
// }

void printDate(Data data)
{
		std::cout << data.time.tm_year << "-" << data.time.tm_mon << "-" << data.time.tm_mday << std::endl;
}

void BitcoinExchange::exchange(std::string inputname) {
	std::ifstream file(inputname.c_str());
	if (!file.is_open())
		throw ErrorOpenException();
	std::string line, date;
	std::string buffer_error;
	// std::vector<Data>::iterator it = m_data.begin();
	getline(file, line);
	if (line.compare("date | value"))
			throw CustomException("First line must be \"date | value\"");
	while (getline(file, line, ' '))
	{
		try {
			if (!isValidDate(line)){
				buffer_error = "Error: bad input => " + line; // potential segfault
				throw CustomException(buffer_error.c_str());
			}
			date = line;
			getline(file, line);
			if (line.compare(0, 3, "| "))
				throw CustomException("Error: bad format");
			line.erase(0, 3);
			if (!isValidValue(line))
				throw CustomException("Error: bad format");
				
			std::map<std::string, float>::iterator it = m_data.find(date);
			if (it == m_data.end())
				it = m_data.lower_bound(date);
			if (it != m_data.begin())
				it--;
			
			float value = strtof(line.c_str(), NULL);
			if (value < 0)
				throw CustomException("Error: not a positive number.");
			if (value > 1000)
				throw CustomException("Error: number too high");
			if (it == m_data.end())
				throw CustomException("Error: date too recent");
			std::cout << date << " => "	<< line << " = " << value * it->second << std::endl;


		// if (isdigit(line[0]))
		// {
		// 	data = setDate(line);
		// 	if (isNotValidDate(data))
		// 		std::cout << "Error: bad input => " << line.substr(0, 10) << std::endl;
		// 	else{
		// 		while (it->time.tm_year < data.time.tm_year && it != m_data.end())
		// 			it++;
		// 		while (it->time.tm_year <= data.time.tm_year && it->time.tm_mon < data.time.tm_mon && it != m_data.end())
		// 			it++;
		// 		while (it->time.tm_year <= data.time.tm_year && it->time.tm_mon <= data.time.tm_mon
		// 				&& it->time.tm_mday < data.time.tm_mday && it != m_data.end()
		// 				&& (it + 1)->time.tm_mday <= data.time.tm_mday)
		// 			it++;
		// 		buffer = line.substr(13, line.size() - 13);
		// 		if (atol(buffer.c_str()) < 0)
		// 			std::cout << "Error: not a positive number." << std::endl;
		// 		else if (atol(buffer.c_str()) > INT_MAX)
		// 			std::cout << "Error: too large a number." << std::endl;
		// 		else{
		// 			std::cout << line.substr(0, 10) << " => " << buffer << " = " << it->price * strtof(buffer.c_str(), NULL) << std::endl;
		// 		}
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;		
		}
		}
	}
}
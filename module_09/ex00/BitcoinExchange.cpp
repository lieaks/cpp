#include "BitcoinExchange.hpp"

std::map<std::string, float> BitcoinExchange::getData() const{
	return m_data; }

void BitcoinExchange::parseDatabase(std::string filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw ErrorOpenException();
		
	std::string line;
	Data data;
	std::string buffer;
	getline(file, line);
	if (line.compare("date,exchange_rate"))
			throw CustomException("First line must be \"date,exchange_rate\"");
	while (getline(file, line))
	{
		if (line.size() < 12)
			throw CustomException("Data must have <Year-Month-Day,prices>");
		else if (atoi(line.))
		if (isdigit(line[0])){
			data = setDate(line);
			buffer = line.substr(11, line.size() - 11);
			data.price = strtof(buffer.c_str(), NULL);
			data.len_price = buffer.size();
			m_data.push_back(data);
		}
	}
	file.close();
}

Data setDate(std::string line)
{
	std::string buffer;
	Data data;
	buffer = line.substr(0, 4);
	data.time.tm_year = atoi(buffer.c_str());
	buffer = line.substr(5, 2);
	data.time.tm_mon = atoi(buffer.c_str());
	buffer = line.substr(8, 2);
	data.time.tm_mday = atoi(buffer.c_str());
	return data;
}

bool isNotValidDate(Data data)
{
	if (data.time.tm_mon < 1 || data.time.tm_mon > 12 || data.time.tm_mday < 1 || data.time.tm_mday > 31)
		return 1;
	return 0;
}

void printDate(Data data)
{
		std::cout << data.time.tm_year << "-" << data.time.tm_mon << "-" << data.time.tm_mday << std::endl;
}

void BitcoinExchange::exchange(std::string inputname) {
	std::ifstream file(inputname.c_str());
	if (!file.is_open())
		throw ErrorOpenException();
	std::string line;
	std::string buffer;
	Data data;
	std::vector<Data>::iterator it = m_data.begin();
	while (getline(file, line))
	{
		if (isdigit(line[0]))
		{
			data = setDate(line);
			if (isNotValidDate(data))
				std::cout << "Error: bad input => " << line.substr(0, 10) << std::endl;
			else{
				while (it->time.tm_year < data.time.tm_year && it != m_data.end())
					it++;
				while (it->time.tm_year <= data.time.tm_year && it->time.tm_mon < data.time.tm_mon && it != m_data.end())
					it++;
				while (it->time.tm_year <= data.time.tm_year && it->time.tm_mon <= data.time.tm_mon
						&& it->time.tm_mday < data.time.tm_mday && it != m_data.end()
						&& (it + 1)->time.tm_mday <= data.time.tm_mday)
					it++;
				buffer = line.substr(13, line.size() - 13);
				if (atol(buffer.c_str()) < 0)
					std::cout << "Error: not a positive number." << std::endl;
				else if (atol(buffer.c_str()) > INT_MAX)
					std::cout << "Error: too large a number." << std::endl;
				else{
					std::cout << line.substr(0, 10) << " => " << buffer << " = " << it->price * strtof(buffer.c_str(), NULL) << std::endl;
				}
			}
		}
	}
}
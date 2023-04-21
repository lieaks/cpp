#pragma once

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

struct Data
{
	tm time;
	float price;
	int len_price;
};

class BitcoinExchange
{
public:
	// BitcoinExchange();
	// BitcoinExchange(const BitcoinExchange &);
	// ~BitcoinExchange();
	// BitcoinExchange & operator = (const BitcoinExchange &);
	void setData(std::string filename);
	void exchange(std::string inputname);
	std::vector<Data> getData() const;
	class ErrorOpenException : public std::exception {
		public:
		virtual const char* what() const throw() {return "Error: open file failed";};
	};
private:
	std::vector<Data> m_data;
};

Data setDate(std::string line);
void printDate(Data data);

#endif //BITCOINEXCHANGE_HPP
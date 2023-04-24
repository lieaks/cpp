#pragma once

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <climits>
#include <cstdlib>

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
	void parseDatabase(std::string filename);
	void exchange(std::string inputname);
	std::map<std::string, float> getData() const;
	class ErrorOpenException : public std::exception {
		public:
		virtual const char* what() const throw() {return "Error: open file failed";};
	};
	class CustomException : public std::exception {
		private:
		const char* m_message;
		public:
		CustomException(char * message) : m_message(message) {};
		virtual const char* what() {return m_message;};
	};
private:
	std::map<std::string, float> m_data;
};

Data setDate(std::string line);
void printDate(Data data);

#endif //BITCOINEXCHANGE_HPP
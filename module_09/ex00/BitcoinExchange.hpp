#pragma once

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <climits>
#include <cstdlib>
#include <float.h>

class BitcoinExchange
{
public:
	BitcoinExchange(std::string input);
	~BitcoinExchange();

	bool isValidDate(std::string line);
	bool isValidValue(std::string line);
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
			CustomException(const char * message) : m_message(message) {};
			virtual const char* what() const throw() {return m_message;};
	};
private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &);
	BitcoinExchange & operator = (const BitcoinExchange &);

	std::map<std::string, float> m_data;
};

#endif //BITCOINEXCHANGE_HPP
#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <algorithm>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <utility>

enum DATE { YEAR, MONTH, DAY };
enum NUMBER { NOT_A_NUMBER = -1, NON_POSITIVE = -2, BIG = -3 };

class BitcoinExchange {
 private:
  std::map<std::string, double> database_;
  bool isValidDate(int year, int month, int day) const;
  bool isLeapYear(const int year) const;
  bool isValidDateKey(std::string token) const;
  double convertValue(std::string value);
  double getExchangeRate(std::string date);

 public:
  BitcoinExchange();
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange& copy);
  BitcoinExchange& operator=(const BitcoinExchange& copy);
  void saveDatabase(const std::string& filename);
  void exchange(std::ifstream& input);
};

#endif
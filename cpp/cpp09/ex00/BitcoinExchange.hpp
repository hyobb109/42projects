#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <utility>

enum DATE { INVALID_DATE = -1, YEAR, MONTH, DAY };
enum NUMBER { NOT_A_NUMBER = -1, NON_POSITIVE = -2, BIG = -3 };

class BitcoinExchange {
 private:
  int today_;
  std::map<int, double> database_;
  bool isValidDate(int year, int month, int day) const;
  bool isLeapYear(const int year) const;
  int getDateKey(std::string token) const;
  double getValue(std::string value);
  double getClosestDateValue(int date);

 public:
  BitcoinExchange();
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange& copy);
  BitcoinExchange& operator=(const BitcoinExchange& copy);
  void saveDatabase(const std::string& filename);
  void exchange(std::ifstream& input);
};

#endif
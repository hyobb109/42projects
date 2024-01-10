#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <algorithm>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

enum DATE { YEAR, MONTH, DAY };

class BitcoinExchange {
 private:
  std::map<std::string, double> database_;
  bool isValidDate(std::string date);
  void printDatabase();

 public:
  BitcoinExchange();
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange& copy);
  BitcoinExchange& operator=(const BitcoinExchange& copy);
  void saveDatabase(const std::string& filename);
  void exchange(std::ifstream& input);
};

#endif
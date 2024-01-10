#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
    : database_(copy.database_) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy) {
  if (this != &copy) {
    database_ = copy.database_;
  }
  return *this;
}

void BitcoinExchange::printDatabase() {
  for (std::map<std::string, double>::iterator it = database_.begin();
       it != database_.end(); ++it) {
    std::cout << it->first << " => " << it->second << std::endl;
  }
}

bool BitcoinExchange::isValidDate(std::string token) {
  std::stringstream ss(token);
  std::string date;
  for (int i = 0; getline(ss, date, '-'); i++) {
    switch (i) {
      case YEAR:
        std::cout << "YEAR" << date << std::endl;
        break;
      case MONTH:
        std::cout << "MONTH" << date << std::endl;
        break;
      case DAY:
        std::cout << "DAY" << date << std::endl;
        break;
      default:
        return false;
        break;
    }
  }
  return true;
}

void BitcoinExchange::saveDatabase(const std::string& filename) {
  std::size_t found = filename.rfind(".csv");
  if (found == std::string::npos || found != filename.length() - 4)
    throw std::runtime_error("🚨 데이터베이스 확장자가 잘못되었습니다 🚨");
  std::ifstream database(filename);
  if (!database.is_open())
    throw std::runtime_error("🚨 파일을 열 수 없습니다 🚨");
  std::string data;
  getline(database, data);  // 헤더 제외
  while (getline(database, data)) {
    std::stringstream ss(data);
    std::string token;
    std::string date;
    double exchange_rate;
    for (int i = 0; getline(ss, token, ','); ++i) {
      if (i == 0)
        date = token;
      else
        exchange_rate = strtod(token.c_str(), NULL);
    }
    database_[date] = exchange_rate;
  }
  database.close();
  // printDatabase();
}

void BitcoinExchange::exchange(std::ifstream& input) {
  if (!database_.size())
    throw std::runtime_error("🚨 저장된 데이터베이스가 없습니다 🚨");
  std::string str;
  bool header = true;
  getline(input, str);
  if (str != "date | value")
    throw std::runtime_error("🚨 파일 형식 오류입니다 🚨");
  while (getline(input, str)) {
    }
}

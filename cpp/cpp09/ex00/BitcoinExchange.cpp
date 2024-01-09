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

bool BitcoinExchange::isValidDate(std::string date) {
  std::stringstream ss;

  return true;
}

void BitcoinExchange::saveDatabase(const std::string& filename) {
  //  확장자 확인
  std::size_t found = filename.rfind(".csv");
  if (found == std::string::npos || found != filename.length() - 4)
    throw std::runtime_error("🚨 데이터베이스 확장자가 잘못되었습니다 🚨");
  // 파일 오픈 확인
  std::ifstream database(filename);
  if (!database.is_open())
    throw std::runtime_error("🚨 파일을 열 수 없습니다 🚨");
  std::string data;
  bool header = true;
  while (getline(database, data)) {
    if (header && data != "date,exchange_rate") {
      database.close();
      throw std::runtime_error("🚨 데이터베이스 형식 오류입니다 🚨");
    }
    if (header) {
      if (data != "date,exchange_rate") {
        database.close();
        throw std::runtime_error("🚨 데이터베이스 형식 오류입니다 🚨");
      }
      header = false;
      continue;
    }
    std::stringstream ss(data);
    std::string token;
    std::string date;
    double exchange_rate;
    for (int i = 0; getline(ss, token, ','); ++i) {
      if (i == 0) {
        if (isValidDate(token)) {
          date = token;
        }
      } else {
        char* endptr;
        exchange_rate = strtod(token.c_str(), &endptr);
        if (*endptr != '\0') {
          database.close();
          throw std::runtime_error("🚨 가격 형식 오류입니다 🚨");
        }
      }
      std::cout << token << std::endl;
    }
    database_[date] = exchange_rate;
  }
  database.close();
  printDatabase();
}

void BitcoinExchange::exchange(std::ifstream& input) {
  (void)input;
  //
}
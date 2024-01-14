#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
  time_t now;
  time(&now);
  struct tm* tm = localtime(&now);

  int cyear = tm->tm_year + 1900;
  int cmonth = tm->tm_mon + 1;
  int cday = tm->tm_mday;

  today_ = cyear * 10000 + cmonth * 100 + cday;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
    : today_(copy.today_), database_(copy.database_) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy) {
  if (this != &copy) {
    today_ = copy.today_;
    database_ = copy.database_;
  }
  return *this;
}

bool BitcoinExchange::isLeapYear(const int year) const {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(int year, int month, int day) const {
  if (year > today_ / 10000) return false;
  if (month < 1 || month > 12) return false;
  int valid_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (isLeapYear(year)) ++valid_days[2];
  return (day > 0) && (day <= valid_days[month]);
}

int BitcoinExchange::getDateKey(std::string token) const {
  std::stringstream ss(token);
  std::string str;
  int date[3];
  for (int i = 0; i < 3; i++) {
    getline(ss, str, '-');
    int data = atoi(str.c_str());
    if (data < 0) return INVALID_DATE;
    date[i] = data;
  }
  if (!ss.eof()) {
    return INVALID_DATE;
  }
  if (!isValidDate(date[YEAR], date[MONTH], date[DAY])) return INVALID_DATE;
  int date_key = date[YEAR] * 10000 + date[MONTH] * 100 + date[DAY];
  return date_key;
}

void BitcoinExchange::saveDatabase(const std::string& filename) {
  std::size_t found = filename.rfind(".csv");
  if (found == std::string::npos || found != filename.length() - 4)
    throw std::runtime_error("🚨 데이터베이스 확장자가 잘못되었습니다 🚨");
  std::ifstream database(filename);
  if (!database.is_open())
    throw std::runtime_error("🚨 데이터베이스를 열 수 없습니다 🚨");
  std::string data;
  getline(database, data);  // 헤더 제외
  while (getline(database, data)) {
    std::stringstream ss(data);
    std::string token;
    std::pair<int, double> info;
    for (int i = 0; getline(ss, token, ','); ++i) {
      i == 0 ? info.first = getDateKey(token)
             : info.second = strtod(token.c_str(), NULL);
    }
    database_.insert(info);
  }
  database.close();
}

double BitcoinExchange::getValue(std::string value) {
  char* endptr;
  double res = strtod(value.c_str(), &endptr);
  if (*endptr != '\0') {
    std::cerr << "🚨 숫자 형식 오류입니다 => " << value << std::endl;
    return NOT_A_NUMBER;
  }
  if (res <= 0) {
    std::cerr << "🚨 양수가 아닙니다 => " << value << std::endl;
    return NON_POSITIVE;
  }
  if (res > 1000) {
    std::cerr << "🚨 숫자가 너무 큽니다 => " << value << std::endl;
    return BIG;
  }
  return res;
}

double BitcoinExchange::getClosestDateValue(int date) {
  std::map<int, double>::reverse_iterator most_recent = database_.rbegin();
  if (date > most_recent->first) return most_recent->second;
  while (--date) {
    if (date % 100 == 0) {
      date -= 100;
      date += date % 10000 ? 31 : -10000 + 1231;
    }
    std::map<int, double>::iterator it = database_.find(date);
    if (it != database_.end()) break;
  }
  return database_[date];
}

void BitcoinExchange::exchange(std::ifstream& input) {
  if (!database_.size())
    throw std::runtime_error("🚨 저장된 데이터베이스가 없습니다 🚨");
  std::string str;
  getline(input, str);
  if (str != "date | value")
    throw std::runtime_error("🚨 입력 파일 형식 오류입니다 🚨");
  while (getline(input, str)) {
    std::size_t del = str.find(" | ");
    if (del == std::string::npos) {
      std::cerr << "🚨 입력 파일 형식 오류입니다 => " << str << std::endl;
      continue;
    }
    std::string date = str.substr(0, del);
    std::string num = str.substr(del + 3);
    int date_key = getDateKey(date);
    if (date_key == INVALID_DATE) {
      std::cerr << "🚨 잘못된 날짜입니다 => " << date << std::endl;
      continue;
    }
    if (date_key < database_.begin()->first) {
      std::cerr << "🚨 데이터베이스에서 값을 가져올 수 없는 날짜입니다 => "
                << date << std::endl;
      continue;
    }
    double value = getValue(num);
    if (value > 0) {
      std::map<int, double>::iterator it = database_.find(date_key);
      double rate = it == database_.end() ? getClosestDateValue(date_key)
                                          : database_[date_key];
      std::cout << date << " => " << num << " = " << value * rate << std::endl;
    }
  }
}

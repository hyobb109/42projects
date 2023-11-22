#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& s) { (void)s; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& s) {
  (void)s;
  return *this;
}

void ScalarConverter::notANumber() {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: nanf" << std::endl;
  std::cout << "double: nan" << std::endl;
}

void ScalarConverter::infiniteNumber(const char* str) {
  double num = strtod(str, NULL);
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: " << num << 'f' << std::endl;
  std::cout << "double: " << num << std::endl;
}

void ScalarConverter::printChar(int num) {
  if (num < CHAR_MIN || num > CHAR_MAX) {
    std::cout << "char: impossible" << std::endl;
  } else {
    std::isprint(num) ? std::cout << "char: " << '\'' << static_cast<char>(num)
                                  << '\'' << std::endl
                      : std::cout << "char: Non displayable" << std::endl;
  }
}

void ScalarConverter::printInt(double num) {
  if (num < INT_MIN || num > INT_MAX) {
    std::cout << "int: impossible" << std::endl;
  } else {
    std::cout << "int: " << static_cast<int>(num) << std::endl;
  }
}

void ScalarConverter::convertNumber(const char* str, int precision,
                                    bool isFloat) {
  double num;
  isFloat ? num = atof(str) : num = strtod(str, NULL);
  printChar(static_cast<int>(num));
  printInt(num);
  if (num < -FLT_MAX || num > FLT_MAX) {
    std::cout << "float: impossible" << std::endl;
  } else {
    std::cout << std::fixed << std::setprecision(precision);
    std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
  }
  if (num < -DBL_MAX || num > DBL_MAX) {
    std::cout << "double: impossible" << std::endl;
  } else {
    std::cout << std::fixed << std::setprecision(precision);
    std::cout << "double: " << static_cast<double>(num) << std::endl;
  }
}

void ScalarConverter::convertChar(char c) {
  int num = static_cast<int>(c);
  std::isprint(num) ? std::cout << "char: " << '\'' << c << '\'' << std::endl
                    : std::cout << "char: Non displayable" << std::endl;
  std::cout << "int: " << num << std::endl;
  std::cout << std::fixed << std::setprecision(1);
  std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
  std::cout << std::fixed << std::setprecision(1);
  std::cout << "double: " << static_cast<double>(c) << std::endl;
}

bool ScalarConverter::isPseudoLiteral(std::string str) {
  if (str == "nan" || str == "+nan" || str == "-nan") {
    notANumber();
    return true;
  }
  if (str == "inf" || str == "+inf" || str == "-inf") {
    infiniteNumber(str.c_str());
    return true;
  }
  return false;
}

void ScalarConverter::convert(std::string str) {
  std::size_t pos = 0;
  // 앞에 공백 삭제
  std::size_t s_idx = str.find_first_not_of(" \t\n\r\f\v");
  str.erase(0, s_idx);
  if (isPseudoLiteral(str)) return;
  // 부호 있으면 str[1]부터 탐색
  if (str[0] == '+' || str[0] == '-') pos = 1;
  if (str.length() == 1 && !isdigit(str[0])) {
    convertChar(str[0]);
    return;
  }
  std::size_t found = str.find_first_not_of("0123456789", pos);
  // digit 으로만 이루어져 있을 때
  if (found == std::string::npos) {
    convertNumber(str.c_str(), 1, false);
  } else if (str[found] == '.') {
    pos = found;
    std::string decimal_part = str.substr(found + 1);
    found = str.find_first_not_of("0123456789", pos + 1);
    // .뒤에 숫자만 나오면 double
    if (found == std::string::npos && str[str.length() - 1] != '.') {
      convertNumber(str.c_str(), decimal_part.length(), false);
    } else if (str[found] == 'f' && found == str.length() - 1) {
      convertNumber(str.c_str(), decimal_part.length() - 1, true);
    } else {
      notANumber();
    }
    // f로 끝나면 float
  } else if (str[found] == 'f' && found == str.length() - 1) {
    convertNumber(str.c_str(), 1, true);
  } else {
    notANumber();
  }
}

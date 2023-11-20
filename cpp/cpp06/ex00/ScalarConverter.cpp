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

void ScalarConverter::convertInt(const char* str) {
  std::cout << "===int===" << std::endl;
  std::cout << str << std::endl;
}

void ScalarConverter::convertChar(const char* str) {
  std::cout << "===char===" << std::endl;
  std::cout << str << std::endl;
  int num = 0;
  std::cout << "char " << num << std::endl;
  std::cout << "int: " << num << std::endl;
  std::cout << "float: " << num << std::endl;
  std::cout << "double: " << num << 'f' << std::endl;
}

void ScalarConverter::convertFloat(const char* str, int precision) {
  double num = atof(str);
  std::cout << "===float===" << std::endl;
  std::cout << "char " << num << std::endl;
  std::cout << "int: " << num << std::endl;
  std::cout << std::fixed << std::setprecision(precision);
  std::cout << "float: " << num << "f\n";
  std::cout << "double: " << num << std::endl;
}

void ScalarConverter::convertDouble(const char* str, int precision) {
  char** endptr = NULL;
  double num = strtod(str, endptr);
  std::cout << "===double===" << std::endl;
  std::cout << "char " << num << std::endl;
  std::cout << "int: " << num << std::endl;
  std::cout << std::fixed << std::setprecision(precision);
  std::cout << "float: " << num << "f\n";
  std::cout << "double: " << num << std::endl;
}

bool ScalarConverter::isPseudoLiteral(std::string str) {
  if (str == "nan" || str == "+nan" || str == "-nan") {
    notANumber();
    return true;
  }
  if (str == "inf" || str == "+inf" || str == "-inf") {
    // inf추가
    return true;
  }
  return false;
}

void ScalarConverter::convert(std::string str) {
  char** endptr = NULL;
  double d_num = 0;
  std::size_t pos = 0;
  d_num = strtod(str.c_str(), endptr);
  std::cout << "num: " << d_num << std::endl;
  // 앞에 공백 삭제
  std::size_t s_idx = str.find_first_not_of(" \t\n\r\f\v");
  str.erase(0, s_idx);
  if (isPseudoLiteral(str)) return;
  // 부호 있으면 str[1]부터 탐색
  if (str[0] == '+' || str[0] == '-') pos = 1;
  std::size_t found = str.find_first_not_of("0123456789", pos);
  // digit 으로만 이루어져 있으면 int or char
  if (found == std::string::npos) {
    convertInt(str.c_str());
  } else if (str[found] == '.') {
    std::string decimal_part = str.substr(found + 1);
    std::cout << "." << decimal_part << std::endl;
    found = decimal_part.find_first_not_of("0123456789");
    // .뒤에 숫자만 나오면 double 1.00 4
    if (found == std::string::npos) {
      convertDouble(str.c_str(), decimal_part.length());
    } else if (str[found] == 'f' && found == str.length() - 1) {
      convertFloat(str.c_str(), decimal_part.length() - 1);
    } else {
      notANumber();
    }
    // f로 끝나면 float
  } else if (str[found] == 'f' && found == str.length() - 1) {
    convertFloat(str.c_str(), 0);
  } else {
    notANumber();
  }
}

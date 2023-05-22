#include <iostream>
#include <string>

int main(int ac, char **av) {
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		std::string str = "";
		for (int i = 1; av[i]; i++)
			str += av[i];
		for (int i = 0; i < str.size(); i++)
			str[i] = toupper(str[i]);
		std::cout << str << std::endl;
	}
	return 0;
}
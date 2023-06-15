#include <iostream>
#include <string>

int main() {
	std::string cmd;
	while (1)
	{
		std::cin >> cmd;
		if (cmd.compare("EXIT") == 0)
			return 0;
		std::cout << cmd << '\n';
	}
	return 0;
}
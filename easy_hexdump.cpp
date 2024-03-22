#include <iostream>
#include <fstream>

void PrintAscii(char ch) {
	if (ch >= ' ' && ch <= '~') {
		std::cout << ch;
	}
	else {
		std::cout << '.';
	}
}
int main(int argc,char *argv[]) {

	std::ifstream file("./test.txt", std::ios::binary | std::ios::ate);
	int len = file.tellg();
	unsigned char* buf = new unsigned char[len]('\0');
	file.seekg(0, std::ios::beg);
	file.read((char *)buf, len);

	int pos_hex = 0,pos_ascii = 0;

	while (pos_hex < len) {
		int num = 0;
		for (; pos_hex < len && num < 16; ++num) {
			std::cout.width(2);
			std::cout.fill('0');
			std::cout << std::hex << (int)buf[pos_hex++] << " ";
			std::cout.fill(' ');
		}
		while (num < 16) {
			std::cout << "   ";
			num++;
		}
		std::cout << "\t|";
		for (int i = 0; pos_ascii < len && i < 16; ++i) {
			PrintAscii(buf[pos_ascii++]);
		}
		std::cout << "|";
		std::endl(std::cout);
	}

	delete[] buf;

	return 0;
}

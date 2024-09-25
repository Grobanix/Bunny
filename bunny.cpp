#include <string>
#include <fstream>
#include <vector>
#include <iostream>

#include "lib.hpp"
#include "parser.hpp"

int main(int argc, char* argv[]) {
	std::string FileName(argv[1]);
	std::cout << FileName << "\n\t";
	
	std::vector<std::vector<std::vector<Token>>> Code = ParseFile(FileName);
	
	for (std::vector<std::vector<Token>> block : Code) {
		for (std::vector<Token> statement : block) {
			for (Token token : statement)
			{ std::cout << token.stType << token.ndType << token.rdType << token.Content; }
		std::cout << '\t';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	return 0;
}

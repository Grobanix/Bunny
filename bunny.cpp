#include <string>
#include <fstream>
#include <vector>
#include <iostream>

short Order{0};
int Statements{-1};
int Tokens{-1};
int Blocks{0};

enum TokenType {
	None ,Number, String, Variable, Operator, Function, Condition , Standard
};

struct Token {
	enum TokenType stType{};
	enum TokenType ndType{};
	enum TokenType rdType{};
	std::string Content{""};
	int Block{0};
	
	Token(TokenType Type)
	{ Order = 1; ++Tokens; this->stType = Type; }
};

class FileManager {
	public: std::ifstream File;
	
	FileManager(std::string FileName) {
		File.open(FileName);
	}
	~FileManager() { File.close(); }
};

void Parse(std::string& Line, std::vector<Token>& Statement) {
	for (int i{0}; i < Line.length(); i++) {
		switch (Order) {
			case 2:
			switch (Line.at(i)) {
				case ' ': { Order = 0; } break;
				case '~': { Statement.at(Tokens).rdType = Standard; } break;
				default: { Statement.at(Tokens).Content += Line.at(i); }
			}
			break;
			case 1:
			switch (Line.at(i)) {
				case ' ': { Order = 0; } break;
				case '~': { ++Order; Statement.at(Tokens).ndType = Standard; } break;
				case '#': { ++Order; Statement.at(Tokens).ndType = Number; } break;
				case '"': { ++Order; Statement.at(Tokens).ndType = String; } break;
				default: { Statement.at(Tokens).Content += Line.at(i); }
			}
			break;
			case 0:
			switch (Line.at(i)) {
				case '#': { Token token(Number); Statement.push_back(token); } break;
				case '"': { Token token(String); Statement.push_back(token); } break;
				case '$': { Token token(Variable); Statement.push_back(token); } break;
				case '%': { Token token(Operator); Statement.push_back(token); } break;
				case '@': { Token token(Function); Statement.push_back(token); } break;
				case '|': { Token token(Condition); Statement.push_back(token); } break;
			}
			break;
		}
	}
}

int main(int argc, char* argv[]) {
	
	std::vector<std::vector<std::vector<Token>>> Code;
	{
	std::vector<std::vector<Token>> block;
	Code.push_back(block);
	}
	std::string FileName(argv[1]);
	std::cout << FileName << '\n';
	
	FileManager fm(FileName);
	std::string Line;
	while (getline(fm.File, Line)) {
		if (Line == "")
		{ ++Blocks; Statements = -1; std::vector<std::vector<Token>> block; Code.push_back(block); }
		++Statements;
		std::vector<Token> Statement;
		Code.at(Blocks).push_back(Statement);
		Parse(Line, Code.at(Blocks).at(Statements));
		Order = 0;
		Tokens = -1;
	}
	
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

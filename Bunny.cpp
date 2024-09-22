#include <string>
#include <fstream>
#include <vector>
#include <iostream>

bool Condition{0};
int Statements{-1};
int Tokens{-1};
int Block{0};

enum TokenType {
	Number, String, Variable
};

struct Token {
	enum TokenType Type{};
	std::string Content{""};
	int Block{0};
	
	Token(TokenType Type)
	{ Condition = 1; ++Tokens; this->Type = Type; }
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
		if (Condition) {
			if (Line.at(i) == ' ') { Condition = 0; }
			else { Statement.at(Tokens).Content += Line.at(i); }
		} else {
			switch (Line.at(i)) {
				case '#': { Token token(Number); Statement.push_back(token); } break;
				case '"': { Token token(String); Statement.push_back(token); } break;
				case '$': { Token token(Variable); Statement.push_back(token); } break;
			}
		}
	}
}

int main(int argc, char* argv[]) {
	
	std::vector<std::vector<Token>> Code;
	std::string FileName(argv[1]);
	std::cout << FileName << '\n';
	
	FileManager fm(FileName);
	std::string Line;
	while (getline(fm.File, Line)) {
		++Statements;
		std::vector<Token> Statement;
		Code.push_back(Statement);
		Parse(Line, Code.at(Statements));
		Condition = 0;
		Tokens = -1;
	}
	
	for (std::vector<Token> statement : Code) {
		for (Token token : statement)
		{ std::cout << token.Type << token.Content; }
	}
	std::cout << std::endl;
	
	return 0;
}

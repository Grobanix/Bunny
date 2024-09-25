#pragma once

struct State {
	short Order{0};
	int Statements{-1};
	int Tokens{-1};
	int Blocks{0};
};

enum TokenType {
	None ,Number, String, Variable, Operator, Function, Condition , Standard
};

struct Token {
	enum TokenType stType{};
	enum TokenType ndType{};
	enum TokenType rdType{};
	std::string Content{""};
	
	Token(TokenType Type, State& state)
	{ state.Order = 1; ++state.Tokens; this->stType = Type; }
};

class FileManager {
	public: std::ifstream File;
	
	FileManager(std::string FileName) {
		File.open(FileName);
	}
	~FileManager() { File.close(); }
};

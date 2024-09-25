#pragma once

void ParseLine(std::string& Line, std::vector<Token>& Statement, State& state) {
	for (int i{0}; i < Line.length(); i++) {
		switch (state.Order) {
			case 2:
			switch (Line.at(i)) {
				case ' ': { state.Order = 0; } break;
				case '~': { Statement.at(state.Tokens).rdType = Standard; } break;
				default: { Statement.at(state.Tokens).Content += Line.at(i); }
			}
			break;
			case 1:
			switch (Line.at(i)) {
				case ' ': { state.Order = 0; } break;
				case '~': { ++state.Order; Statement.at(state.Tokens).ndType = Standard; } break;
				case '#': { ++state.Order; Statement.at(state.Tokens).ndType = Number; } break;
				case '"': { ++state.Order; Statement.at(state.Tokens).ndType = String; } break;
				default: { Statement.at(state.Tokens).Content += Line.at(i); }
			}
			break;
			case 0:
			switch (Line.at(i)) {
				case '#': { Token token(Number, state); Statement.push_back(token); } break;
				case '"': { Token token(String, state); Statement.push_back(token); } break;
				case '$': { Token token(Variable, state); Statement.push_back(token); } break;
				case '%': { Token token(Operator, state); Statement.push_back(token); } break;
				case '@': { Token token(Function, state); Statement.push_back(token); } break;
				case '|': { Token token(Condition, state); Statement.push_back(token); } break;
			}
			break;
		}
	}
}

std::vector<std::vector<std::vector<Token>>> ParseFile(std::string FileName) {
	State state;
	std::vector<std::vector<std::vector<Token>>> Code;
	{
	std::vector<std::vector<Token>> block;
	Code.push_back(block);
	}
	
	FileManager fm(FileName);
	std::string Line;
	while (getline(fm.File, Line)) {
		if (Line == "")
		{ ++state.Blocks; state.Statements = -1; std::vector<std::vector<Token>> block; Code.push_back(block); }
		++state.Statements;
		std::vector<Token> Statement;
		Code.at(state.Blocks).push_back(Statement);
		ParseLine(Line, Code.at(state.Blocks).at(state.Statements), state);
		state.Order = 0;
		state.Tokens = -1;
	}
	
	return Code;
}

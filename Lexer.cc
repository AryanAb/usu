#include "Lexer.h"

#include <iostream>
#include <fstream>
#include <string>

namespace usu
{
	std::vector<DFA::Type> Lexer::analyse(const std::string &path)
	{
		DFA dfa;
		std::vector<DFA::Type> res;
		int last_final_state = 0;
		int last_final_position = 0;
		int current_state = 1;
		int line_num = 1;
		
		std::ifstream f{path};
		std::string line;
		
		while (std::getline(f, line))
		{
			last_final_position = 0;
			for (size_t i = 0; i < line.length(); ++i)
			{
				char c = line.at(i);

				current_state = dfa.step(current_state, c);
				if (current_state == 0)
				{
					current_state = 1;
					DFA::Type last_final_state_token = dfa.getStateToken(last_final_state);

					if (last_final_state_token == DFA::Type::ERROR)
					{
						std::cerr << "\033[1;31mERROR\033[0m: Invalid token at line " << line_num << ", position " << last_final_position + 1 << "." << std::endl;
						break;
					}
					
					res.push_back(last_final_state_token);
					last_final_state = 0;
				
					i = last_final_position;
				}
				else if (current_state != 74)
				{
					last_final_state = current_state;
					last_final_position = i;
				}
			}

			if (current_state == 74)
			{
				std::cerr << "\033[1;31mERROR\033[0m: Missing closing '#' on comment starting at line " << line_num << ", position " << last_final_position + 2 << "." << std::endl;
				break;
			}

			++line_num;
		} 

		return res;
	}


	void Lexer::print(std::vector<DFA::Type> res)
	{
		for (auto t : res)
		{
			switch (t)
			{
			case DFA::Type::BREAK:
				std::cout << "BREAK";
				break;
			case DFA::Type::CHAR:
				std::cout << "CHAR";
				break;
			case DFA::Type::CONST:
				std::cout << "CONST" ;
				break;
			case DFA::Type::CONTINUE:
				std::cout << "CONTINUE" ;
				break;
			case DFA::Type::ENUM:
				std::cout << "ENUM" ;
				break;
			case DFA::Type::FLOAT:
				std::cout << "FLOAT" ;
				break;
			case DFA::Type::FOR:
				std::cout << "FOR" ;
				break;
			case DFA::Type::IF:
				std::cout << "IF" ;
				break;
			case DFA::Type::INT:
				std::cout << "INT" ;
				break;
			case DFA::Type::RETURN:
				std::cout << "RETURN" ;
				break;
			case DFA::Type::VOID:
				std::cout << "VOID" ;
				break;
			case DFA::Type::WHILE:
				std::cout << "WHILE" ;
				break;
			case DFA::Type::LPAREN:
				std::cout << "LPAREN" ;
				break;
			case DFA::Type::RPAREN:
				std::cout << "RPAREN" ;
				break;
			case DFA::Type::RBRACKET:
				std::cout << "RBRACKET" ;
				break;
			case DFA::Type::LBRACKET:
				std::cout << "LBRACKET" ;
				break;
			case DFA::Type::ASSIGN:
				std::cout << "ASSGIN" ;
				break;
			case DFA::Type::EQ:
				std::cout << "EQ" ;
				break;
			case DFA::Type::NEQ:
				std::cout << "NEQ" ;
				break;
			case DFA::Type::GE:
				std::cout << "GE" ;
				break;
			case DFA::Type::GT:
				std::cout << "GT" ;
				break;
			case DFA::Type::LT:
				std::cout << "LT" ;
				break;
			case DFA::Type::LE:
				std::cout << "LE" ;
				break;
			case DFA::Type::ARROW:
				std::cout << "ARROW" ;
				break;
			case DFA::Type::MULT:
				std::cout << "MULT" ;
				break;
			case DFA::Type::PLUS:
				std::cout << "PLUS" ;
				break;
			case DFA::Type::SUB:
				std::cout << "SUB" ;
				break;
			case DFA::Type::DIV:
				std::cout << "DIV" ;
				break;
			case DFA::Type::MOD:
				std::cout << "MOD" ;
				break;
			case DFA::Type::ID:
				std::cout << "ID" ;
				break;
			case DFA::Type::NUM:
				std::cout << "NUM";
				break;
			case DFA::Type::COMMENT:
				std::cout << "COMMENT" ;
				break;
			case DFA::Type::WHITESPACE:
				std::cout << "WHITESPACE";
				break;
			case DFA::Type::ERROR:
				std::cout << "ERROR";
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
};

#include "Lexer.h"

#include "Messages.h"
#include "Exception.h"

#include <iostream>
#include <string>
#include <vector>
#include <utility>

namespace usu
{
	std::vector<std::pair<usu::DFA::Token, std::string>> Lexer::analyze(const std::string &src)
	{
		DFA dfa;
		std::vector<std::pair<DFA::Token, std::string>> res;
		int last_final_state = 0;
		int last_final_position = 0;
		int current_state = 1;
		std::string word = "";
		
		for (size_t i = 0; i < src.length(); ++i)
		{
			char c = src.at(i);
			current_state = dfa.step(current_state, c);
			
			if (current_state == 0)
			{
				current_state = 1;
				DFA::Token last_final_state_token = dfa.getStateToken(last_final_state);

				if (last_final_state_token == DFA::Token::ERROR)
				{
					std::string msg = Messages::error("Invalid token: '" + word + "'");
					throw Exception("lexing", msg);
				}
					
				res.push_back(std::make_pair(last_final_state_token, word));
				word = "";
				last_final_state = 0;
				
				i = last_final_position;
			}
			else if (current_state != 51)
			{
				word += c;
				last_final_state = current_state;
				last_final_position = i;
			}
		}

		return res;
	}

	void Lexer::print(std::vector<std::pair<usu::DFA::Token, std::string>> tokens)
	{
		for (auto token : tokens)
		{
			if (token.first == DFA::Token::WHITESPACE || token.first == DFA::Token::COMMENT) continue;
			
			switch (token.first)
			{
			case DFA::Token::LESS:
				std::cout << "(LESS, '" << token.second << "')";
				break;
			case DFA::Token::LENGTH:
				std::cout << "(LENGTH, '" << token.second << "')";
				break;
			case DFA::Token::TIME:
				std::cout << "(TIME, '" << token.second << "')";
				break;
			case DFA::Token::MASS:
				std::cout << "(MASS, '" << token.second << "')";
				break;
			case DFA::Token::CURRENT:
				std::cout << "(CURRENT, '" << token.second << "')";
				break;
			case DFA::Token::TEMP:
				std::cout << "(TEMP, '" << token.second << "')";
				break;
			case DFA::Token::AMOUNT:
				std::cout << "(AMOUNT, '" << token.second << "')";
				break;
			case DFA::Token::A:
				std::cout << "(A, '" << token.second << "')";
				break;
			case DFA::Token::M:
				std::cout << "(M, '" << token.second << "')";
				break;
			case DFA::Token::S:
				std::cout << "(S, '" << token.second << "')";
				break;
			case DFA::Token::KG:
				std::cout << "(KG, '" << token.second << "')";
				break;
			case DFA::Token::LUM:
				std::cout << "(LUM, '" << token.second << "')";
				break;
			case DFA::Token::K:
				std::cout << "(K, '" << token.second << "')";
				break;
			case DFA::Token::MOL:
				std::cout << "(MOL, '" << token.second << "')";
				break;
			case DFA::Token::CD:
				std::cout << "(CD, '" << token.second << "')";
				break;
			case DFA::Token::ASSIGN:
				std::cout << "(ASSGIN, '" << token.second << "')";
				break;
			case DFA::Token::DEFINE:
				std::cout << "(DEFINE, '" << token.second << "')";
				break;
			case DFA::Token::MULT:
				std::cout << "(MULT, '" << token.second << "')";
				break;
			case DFA::Token::PLUS:
				std::cout << "(PLUS, '" << token.second << "')";
				break;
			case DFA::Token::SUB:
				std::cout << "(SUB, '" << token.second << "')";
				break;
			case DFA::Token::DIV:
				std::cout << "(DIV, '" << token.second << "')";
				break;
			case DFA::Token::ID:
				std::cout << "(ID, '" << token.second << "')";
				break;
			case DFA::Token::NUMBER:
				std::cout << "(NUMBER, '" << token.second << "')";
				break;
			case DFA::Token::COMMENT:
				std::cout << "(COMMENT, '" << token.second << "')";
				break;
			case DFA::Token::WHITESPACE:
				std::cout << "(WHITESPACE, '" << token.second << "')";
				break;
			case DFA::Token::ERROR:
				std::cout << "(ERROR, '" << token.second << "')";
				break;
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}

	std::pair<size_t, size_t> Lexer::getLocation(const std::string &str, size_t pos)
	{
		size_t line_num = 1;
		size_t column = 1;
		for (size_t i = 0; i < pos; ++i)
		{
			if (str[i] == '\n')
			{
				++line_num;
				column = 1;
			}
			++column;
		}
		return std::make_pair(line_num, column);
	}
};

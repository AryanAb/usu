#include "Lexer.h"

#include "Messages.h"
#include "Exception.h"

#include <iostream>
#include <string>

namespace usu
{
	std::vector<std::pair<DFA::Token, std::string>> Lexer::analyse(const std::string &src)
	{
		DFA dfa;
		std::vector<std::pair<DFA::Token, std::string>> res;
		int last_final_state = 0;
		int last_final_position = 0;
		int current_state = 1;
		int line_num = 1;
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
					auto l = getLocation(src, last_final_position);
					auto msg = Messages::error("Invalid token '" + word + "' at line: " + std::to_string(l.first) + ", " + std::to_string(l.second));
					throw Exception("lexing", msg);
				}
					
				res.push_back(std::make_pair(last_final_state_token, word));
				word = "";
				last_final_state = 0;
				
				i = last_final_position;
			}
			else if (current_state != 74)
			{
				word += c;
				last_final_state = current_state;
				last_final_position = i;
			}

			if (c == '\n') ++line_num;
		}

		if (current_state == 74)
		{
			std::pair<size_t, size_t> l = getLocation(src, last_final_position);
		   std::string msg = Messages::error("Missing closing '#' on comment starting at line: " + std::to_string(l.first) + ", " + std::to_string(l.second));
		   throw Exception("lexing", msg);
		}

		return res;
	}


	void Lexer::print(std::vector<std::pair<DFA::Token, std::string>> res)
	{
		for (auto t : res)
		{
			if (t.first == DFA::Token::WHITESPACE || t.first == DFA::Token::COMMENT) continue;
			
			switch (t.first)
			{
			case DFA::Token::BREAK:
				std::cout << "(BREAK, '" << t.second << "')";
				break;
			case DFA::Token::CHAR:
				std::cout << "(CHAR, '" << t.second << "')";
				break;
			case DFA::Token::CONST:
				std::cout << "(CONST, '" << t.second << "')";
				break;
			case DFA::Token::CONTINUE:
				std::cout << "(CONTINU, '" << t.second << "')";
				break;
			case DFA::Token::ENUM:
				std::cout << "(ENUM, '" << t.second << "')";
				break;
			case DFA::Token::FLOAT:
				std::cout << "(FLOAT, '" << t.second << "')";
				break;
			case DFA::Token::FOR:
				std::cout << "(FOR, '" << t.second << "')";
				break;
			case DFA::Token::IF:
				std::cout << "(IF, '" << t.second << "')";
				break;
			case DFA::Token::INT:
				std::cout << "(INT, '" << t.second << "')";
				break;
			case DFA::Token::RETURN:
				std::cout << "(RETURN, '" << t.second << "')";
				break;
			case DFA::Token::VOID:
				std::cout << "(VOID, '" << t.second << "')";
				break;
			case DFA::Token::WHILE:
				std::cout << "(WHILE, '" << t.second << "')";
				break;
			case DFA::Token::LPAREN:
				std::cout << "(LPAREN, '" << t.second << "')";
				break;
			case DFA::Token::RPAREN:
				std::cout << "(RPAREN, '" << t.second << "')";
				break;
			case DFA::Token::RBRACKET:
				std::cout << "(RBRACKET, '" << t.second << "')";
				break;
			case DFA::Token::LBRACKET:
				std::cout << "(LBRACKET, '" << t.second << "')";
				break;
			case DFA::Token::ASSIGN:
				std::cout << "(ASSGIN, '" << t.second << "')";
				break;
			case DFA::Token::EQ:
				std::cout << "(EQ, '" << t.second << "')";
				break;
			case DFA::Token::NEQ:
				std::cout << "(NEQ, '" << t.second << "')";
				break;
			case DFA::Token::GE:
				std::cout << "(GE, '" << t.second << "')";
				break;
			case DFA::Token::GT:
				std::cout << "(GT, '" << t.second << "')";
				break;
			case DFA::Token::LT:
				std::cout << "(LT, '" << t.second << "')";
				break;
			case DFA::Token::LE:
				std::cout << "(LE, '" << t.second << "')";
				break;
			case DFA::Token::ARROW:
				std::cout << "(ARROW, '" << t.second << "')";
				break;
			case DFA::Token::MULT:
				std::cout << "(MULT, '" << t.second << "')";
				break;
			case DFA::Token::PLUS:
				std::cout << "(PLUS, '" << t.second << "')";
				break;
			case DFA::Token::SUB:
				std::cout << "(SUB, '" << t.second << "')";
				break;
			case DFA::Token::DIV:
				std::cout << "(DIV, '" << t.second << "')";
				break;
			case DFA::Token::MOD:
				std::cout << "(MOD, '" << t.second << "')";
				break;
			case DFA::Token::ID:
				std::cout << "(ID, '" << t.second << "')";
				break;
			case DFA::Token::NUM:
				std::cout << "(NUM, '" << t.second << "')";
				break;
			case DFA::Token::COMMENT:
				std::cout << "(COMMENT, '" << t.second << "')";
				break;
			case DFA::Token::WHITESPACE:
				std::cout << "(WHITESPACE, '" << t.second << "')";
				break;
			case DFA::Token::COMMA:
				std::cout << "(COMMA, '" << t.second << "')";
				break;
			case DFA::Token::STRING:
				std::cout << "(STRING, '" << t.second << "')";
				break;
			case DFA::Token::ERROR:
				std::cout << "(ERROR, '" << t.second << "')";
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

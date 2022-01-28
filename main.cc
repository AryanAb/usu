#include "Lexer.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
	std::ifstream f(argv[1]);
	std::stringstream buffer;
	buffer << f.rdbuf();
	
	usu::Lexer lex;
	std::vector<usu::DFA::Type> res = lex.analyse(buffer.str());
	for (auto t : res)
	{
		switch (t)
		{
		case usu::DFA::Type::BREAK:
			std::cout << "BREAK";
			break;
		case usu::DFA::Type::CHAR:
			std::cout << "CHAR";
			break;
		case usu::DFA::Type::CONST:
			std::cout << "CONST" ;
			break;
		case usu::DFA::Type::CONTINUE:
			std::cout << "CONTINUE" ;
			break;
		case usu::DFA::Type::ENUM:
			std::cout << "ENUM" ;
			break;
		case usu::DFA::Type::FLOAT:
			std::cout << "FLOAT" ;
			break;
		case usu::DFA::Type::FOR:
			std::cout << "FOR" ;
			break;
		case usu::DFA::Type::IF:
			std::cout << "IF" ;
			break;
		case usu::DFA::Type::INT:
			std::cout << "INT" ;
			break;
		case usu::DFA::Type::RETURN:
			std::cout << "RETURN" ;
			break;
		case usu::DFA::Type::VOID:
			std::cout << "VOID" ;
			break;
		case usu::DFA::Type::WHILE:
			std::cout << "WHILE" ;
			break;
		case usu::DFA::Type::LPAREN:
			std::cout << "LPAREN" ;
			break;
		case usu::DFA::Type::RPAREN:
			std::cout << "RPAREN" ;
			break;
		case usu::DFA::Type::RBRACKET:
			std::cout << "RBRACKET" ;
			break;
		case usu::DFA::Type::LBRACKET:
			std::cout << "LBRACKET" ;
			break;
		case usu::DFA::Type::ASSIGN:
			std::cout << "ASSGIN" ;
			break;
		case usu::DFA::Type::EQ:
			std::cout << "EQ" ;
			break;
		case usu::DFA::Type::NEQ:
			std::cout << "NEQ" ;
			break;
		case usu::DFA::Type::GE:
			std::cout << "GE" ;
			break;
		case usu::DFA::Type::GT:
			std::cout << "GT" ;
			break;
		case usu::DFA::Type::LT:
			std::cout << "LT" ;
			break;
		case usu::DFA::Type::LE:
			std::cout << "LE" ;
			break;
		case usu::DFA::Type::ARROW:
			std::cout << "ARROW" ;
			break;
		case usu::DFA::Type::MULT:
			std::cout << "MULT" ;
			break;
		case usu::DFA::Type::PLUS:
			std::cout << "PLUS" ;
			break;
		case usu::DFA::Type::SUB:
			std::cout << "SUB" ;
			break;
		case usu::DFA::Type::DIV:
			std::cout << "DIV" ;
			break;
		case usu::DFA::Type::MOD:
			std::cout << "MOD" ;
			break;
		case usu::DFA::Type::ID:
			std::cout << "ID" ;
			break;
		case usu::DFA::Type::COMMENT:
			std::cout << "COMMENT" ;
			break;
		case usu::DFA::Type::WHITESPACE:
			std::cout << "WHITESPACE";
			break;
		}
		std::cout << " ";
	}
	std::cout << std::endl;
}

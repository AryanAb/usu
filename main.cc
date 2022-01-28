#include "Lexer.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{	
	usu::Lexer lex;
	std::vector<usu::DFA::Type> res = lex.analyse(argv[1]);
	lex.print(res);
}

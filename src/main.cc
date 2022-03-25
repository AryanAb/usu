#include "Lexer.h"

#include "Exception.h"

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <sstream>

int main(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::ifstream f{argv[i]};
		std::stringstream buffer;
		buffer << f.rdbuf();

		try
		{
			usu::Lexer lex;
			std::vector<std::pair<usu::DFA::Token, std::string>> res = lex.analyse(buffer.str());
			lex.print(res);
		}
		catch (const usu::Exception &e) 
		{
			std::cout << "Error while compiling " << argv[i] << "." << std::endl;
			e.details();
		}
	}
	
}

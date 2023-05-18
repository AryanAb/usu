#include "Lexer.h"
#include "Exception.h"

#include <iostream>
#include <string>
#include <vector>
#include <utility>

int main(int argc, char **argv)
{
	usu::Lexer lex;
	std::vector<std::pair<usu::DFA::Token, std::string>> res;

	while (true)
	{
		std::cout << "usu> " << std::flush;
		std::string line;
		std::getline(std::cin, line);

		try
		{
			res = lex.analyze(line + '\n');
			lex.print(res);
		}
		catch(const usu::Exception &e)
		{
			e.details();
		}
	}
}

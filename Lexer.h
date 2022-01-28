#ifndef __LEXER_H
#define __LEXER_H

#include "DFA.h"

#include <vector>
#include <string>

namespace usu
{
	class Lexer
	{
	public:
		std::vector<DFA::Type> analyse(const std::string &prog);
		void print(std::vector<DFA::Type> res);
   	};
};

#endif

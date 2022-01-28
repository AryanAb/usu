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
	private:
		int last_final_state = 0;
		int last_final_position = 0;
		int current_state = 1;
	};
};

#endif

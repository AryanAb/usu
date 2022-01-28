#include "Lexer.h"

#include <iostream>

namespace usu
{
	std::vector<DFA::Type> Lexer::analyse(const std::string &prog)
	{
		DFA dfa;
		std::vector<DFA::Type> res;
		
		for (size_t i = 0; i < prog.length(); ++i)
		{
			char c = prog.at(i);

			//std::cout << i << std::endl;
			current_state = dfa.step(current_state, c);
			if (current_state == 0)
			{
				current_state = 1;
				res.push_back(dfa.getStateToken(last_final_state));
				last_final_state = 0;
				i = last_final_position;
			}
			else
			{
				last_final_state = current_state;
				last_final_position = i;
			}
		}

		return res;
	}
};

#pragma once

#include "DFA.h"

#include <vector>
#include <string>
#include <utility>

namespace usu
{
	class Lexer
	{
	public:
		std::vector<std::pair<DFA::Token, std::string>> analyse(const std::string &prog);
		void print(std::vector<std::pair<DFA::Token, std::string>> res);
		std::pair<size_t, size_t> getLocation(const std::string &str, size_t pos);
   	};
};


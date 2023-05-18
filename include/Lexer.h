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
		std::vector<std::pair<usu::DFA::Token, std::string>> analyze(const std::string &line);
		void print(std::vector<std::pair<usu::DFA::Token, std::string>> tokens);
		std::pair<size_t, size_t> getLocation(const std::string &str, size_t pos);
	};
};


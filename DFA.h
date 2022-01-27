#ifndef __DFA_H
#define __DFA_H

#include <array>
#include <map>

namespace usu
{
	class DFA
	{
	public:
		enum Type{ID, NUM, REAL, IF, WHITESPACE, ERROR};
		DFA();
		
	private:
		static constexpr int NUM_STATES = 14;
		const std::map<int, Type> accepting{{2, Type::ID}, {3, Type::IF}, {4, Type::ID}, {5, Type::ERROR}, {6, Type::REAL},
			{7, Type::NUM}, {8, Type::REAL}, {9, Type::ERROR}, {11, Type::WHITESPACE}, {12, Type::WHITESPACE}, {13, Type::WHITESPACE}};
		std::array<std::array<int, 128>, NUM_STATES> transition_matrix;
	};
};

#endif

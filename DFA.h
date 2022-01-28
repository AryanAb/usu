#ifndef __DFA_H
#define __DFA_H

#include <array>
#include <map>
#include <cstddef>

namespace usu
{
	class DFA
	{
	public:
   		enum Type {BREAK, CHAR, CONST, CONTINUE, ENUM, FLOAT, FOR, IF, INT, RETURN, VOID, WHILE, LPAREN, RPAREN, LBRACKET, RBRACKET, ASSIGN, EQ, NEQ, GE, GT, LT, LE, ARROW, MULT, PLUS, SUB, DIV, MOD, ID, COMMENT, WHITESPACE, ERROR};
		
		DFA();
		size_t step(size_t state, char c);
		Type getStateToken(size_t state);

	private:
		static constexpr size_t NUM_STATES = 77;
		std::array<std::array<char, 128>, NUM_STATES> transition_matrix;
		std::map<size_t, Type> accepting;
		void constructTransitionMatrix();
		void constructAcceptingStates();
	};
};

#endif

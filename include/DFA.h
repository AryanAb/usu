#pragma once

#include <array>
#include <map>
#include <cstddef>

namespace usu
{
	class DFA
	{
	public:
   		enum Token {BREAK, CHAR, CONST, CONTINUE, ENUM, FLOAT, FOR, IF, INT, RETURN, VOID, WHILE, LPAREN, RPAREN, LBRACKET, RBRACKET, ASSIGN, EQ, NEQ, GE, GT, LT, LE, ARROW, MULT, PLUS, SUB, DIV, MOD, ID, NUM, COMMENT, WHITESPACE, COMMA, STRING, ERROR};
		
		DFA();
		size_t step(size_t state, char c);
		Token getStateToken(size_t state);

	private:
		static constexpr size_t NUM_STATES = 80;
		std::array<std::array<size_t, 128>, NUM_STATES> transition_matrix;
		std::map<size_t, Token> accepting;
		void constructTransitionMatrix();
		void constructAcceptingStates();
	};
};

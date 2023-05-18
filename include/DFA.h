#pragma once

#include <array>
#include <map>
#include <cstddef>

namespace usu
{
	class DFA
	{
	public:
		enum Token {
			NUMBER,
			ID,
			LESS, 
			LENGTH, 
			TIME, 
			MASS, 
			CURRENT, 
			TEMP, 
			AMOUNT, 
			LUM, 
			M, 
			S, 
			KG, 
			A, 
			K, 
			MOL, 
			CD,
			ASSIGN,
			DEFINE,
			MULT,
			PLUS,
			SUB,
			DIV,
			COMMENT,
			WHITESPACE,
			ERROR
		};
		
		DFA();
		size_t step(size_t state, char c);
		Token getStateToken(size_t state);

	private:
		static constexpr size_t NUM_STATES = 57;
		std::array<std::array<size_t, 128>, NUM_STATES> transition_matrix;
		std::map<size_t, Token> accepting;
		void constructTransitionMatrix();
		void constructAcceptingStates();
	};
};

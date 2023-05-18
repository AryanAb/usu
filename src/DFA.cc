#include "DFA.h"

#include <cstddef>
#include <iostream>

namespace usu
{
	void DFA::constructTransitionMatrix()
	{
		for (size_t i = 0; i < transition_matrix.size(); ++i)
		{
			for (int c = 0; c < 128; ++c)
				transition_matrix[i][c] = 0;
		}
		
		for (size_t i = 1; i <= 43; ++i)
		{
			if (i != 1)
				for (char c = '0'; c <= '9'; ++c) { transition_matrix[i][c] = 53; }
			
			for (char c = 'A'; c <= 'Z'; ++c) { transition_matrix[i][c] = 53; }
			for (char c = 'a'; c <= 'z'; ++c) { transition_matrix[i][c] = 53; }
		}
		
		transition_matrix[1]['l'] = 2;
		// l -> length | less | lum

		transition_matrix[2]['u'] = 3;
		transition_matrix[3]['m'] = 4;
		// LUM

		transition_matrix[2]['e'] = 5;
		// le -> length | less

		transition_matrix[5]['n'] = 6;
		transition_matrix[6]['g'] = 7;
		transition_matrix[7]['t'] = 8;
		transition_matrix[8]['h'] = 9;
		// LENGTH

		transition_matrix[5]['s'] = 10;
		transition_matrix[10]['s'] = 11;
		// LESS

		transition_matrix[1]['t'] = 12;
		// t -> time | temp

		transition_matrix[12]['i'] = 13;
		transition_matrix[13]['m'] = 14;
		transition_matrix[14]['e'] = 15;
		// TIME

		transition_matrix[12]['e'] = 16;
		transition_matrix[16]['m'] = 17;
		transition_matrix[17]['p'] = 18;
		// TEMP

		transition_matrix[1]['m'] = 19;
		// m -> m | mass | mol
		// M

		transition_matrix[19]['a'] = 20;
		transition_matrix[20]['s'] = 21;
		transition_matrix[21]['s'] = 22;
		// MASS

		transition_matrix[19]['o'] = 23;
		transition_matrix[23]['l'] = 24;
		// MOL

		transition_matrix[1]['c'] = 25;
		// c -> cd | current

		transition_matrix[25]['d'] = 26;
		// CD

		transition_matrix[25]['u'] = 27;
		transition_matrix[27]['r'] = 28;
		transition_matrix[26]['r'] = 29;
		transition_matrix[27]['e'] = 30;
		transition_matrix[28]['n'] = 31;
		transition_matrix[29]['t'] = 32;
		// CURRENT

		transition_matrix[1]['a'] = 33;
		transition_matrix[33]['m'] = 34;
		transition_matrix[34]['o'] = 35;
		transition_matrix[35]['u'] = 36;
		transition_matrix[36]['n'] = 37;
		transition_matrix[37]['t'] = 38;
		// AMOUNT

		transition_matrix[1]['A'] = 39;
		// A

		transition_matrix[1]['s'] = 40;
		// S

		transition_matrix[1]['k'] = 41;
		transition_matrix[41]['g'] = 42;
		// KG

		transition_matrix[1]['K'] = 43;
		// K

		transition_matrix[1]['='] = 44;
		// ASSIGN

		transition_matrix[1][':'] = 45;
		transition_matrix[45]['='] = 46;
		// DEFINE

		transition_matrix[1]['*'] = 47;
		// MULT
		transition_matrix[1]['+'] = 48;
		// PLUS
		transition_matrix[1]['-'] = 49;
		// SUB
		transition_matrix[1]['/'] = 50;
		// DIV

		transition_matrix[1]['#'] = 51;
		for (int c = 0; c < 128; ++c) { transition_matrix[51][c] = 51; }
		// COMMENT

		transition_matrix[1][' '] = 52;
		transition_matrix[1]['\t'] = 52;
		transition_matrix[1]['\n'] = 52;
		// WHITESPACE

		for (char c = '0'; c <= '9'; ++c) { transition_matrix[53][c] = 53; }
		for (char c = 'A'; c <= 'Z'; ++c) { transition_matrix[53][c] = 53; }
		for (char c = 'a'; c <= 'z'; ++c) { transition_matrix[53][c] = 53; }
		// ID

		for (char c = '0'; c <= '9'; ++c) { transition_matrix[1][c] = 54; }
		for (char c = '0'; c <= '9'; ++c) { transition_matrix[54][c] = 54; }
		transition_matrix[54]['.'] = 55;
		for (char c = '0'; c <= '9'; ++c) { transition_matrix[55][c] = 55; }
		// NUMBER

		// if there are more than one decimal point, go to an non-accepting state
		transition_matrix[55]['.'] = 56;
	}


	void DFA::constructAcceptingStates()
	{
		for (size_t i = 0; i <= 49; ++i)
		{
			accepting[i] = Token::ID;
		}
		accepting[4] = Token::LUM;
		accepting[9] = Token::LENGTH;
		accepting[11] = Token::LESS;
		accepting[15] = Token::TIME;
		accepting[18] = Token::TEMP;
		accepting[19] = Token::M;
		accepting[22] = Token::MASS;
		accepting[24] = Token::MOL;
		accepting[26] = Token::CD;
		accepting[32] = Token::CURRENT;
		accepting[38] = Token::AMOUNT;
		accepting[39] = Token::A;
		accepting[40] = Token::S;
		accepting[42] = Token::KG;
		accepting[43] = Token::K;
		accepting[44] = Token::ASSIGN;
		accepting[46] = Token::DEFINE;
		accepting[47] = Token::MULT;
		accepting[48] = Token::PLUS;
		accepting[49] = Token::SUB;
		accepting[50] = Token::DIV;
		accepting[51] = Token::COMMENT;
		accepting[52] = Token::WHITESPACE;
		accepting[53] = Token::ID;
		accepting[54] = Token::NUMBER;
		accepting[55] = Token::NUMBER;
	}

	
	DFA::DFA()
	{
		constructTransitionMatrix();
		constructAcceptingStates();
	}

	
	size_t DFA::step(size_t state, char c)
	{
		return transition_matrix[state][c];
	}

	
	DFA::Token DFA::getStateToken(size_t state)
	{
		if (accepting.count(state) != 0)
			return accepting.at(state);
		return Token::ERROR;
	}
};

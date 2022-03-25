#include "DFA.h"

#include <cstddef>
#include <iostream>

namespace usu
{
	void DFA::constructTransitionMatrix()
	{
		for (size_t i = 0; i < transition_matrix.size(); ++i)
		{
			for (char c = 0; c > -1 && c < 128; ++c)
				transition_matrix[i][c] = 0;
		}
		
		for (size_t i = 1; i <= 49; ++i)
		{
			if (i != 1)
				for (char c = '0'; c <= '9'; ++c) { transition_matrix[i][c] = 70; }
			
			for (char c = 'A'; c <= 'Z'; ++c) { transition_matrix[i][c] = 70; }
			for (char c = 'a'; c <= 'z'; ++c) { transition_matrix[i][c] = 70; }
		}
		
		transition_matrix[1]['b'] = 2;
		transition_matrix[2]['r'] = 3;
		transition_matrix[3]['e'] = 4;
		transition_matrix[4]['a'] = 5;
		transition_matrix[5]['k'] = 6;
		// BREAK

		transition_matrix[1]['c'] = 7;
		
		transition_matrix[7]['h'] = 8;
		transition_matrix[8]['a'] = 9;
		transition_matrix[9]['r'] = 10;
		// CHAR

		transition_matrix[7]['o'] = 11;
		transition_matrix[11]['n'] = 12;
		
		transition_matrix[12]['s'] = 13;
		transition_matrix[13]['t'] = 14;
		// CONST

		transition_matrix[12]['t'] = 15;
		transition_matrix[15]['i'] = 16;
		transition_matrix[16]['n'] = 17;
		transition_matrix[17]['u'] = 18;
		transition_matrix[18]['e'] = 19;
		// CONTINUE

		transition_matrix[1]['e'] = 20;
		transition_matrix[20]['n'] = 21;
		transition_matrix[21]['u'] = 22;
		transition_matrix[22]['m'] = 23;
		// ENUM

		transition_matrix[1]['f'] = 24;

		transition_matrix[24]['l'] = 25;
		transition_matrix[25]['o'] = 26;
		transition_matrix[26]['a'] = 27;
		transition_matrix[27]['t'] = 28;
		// FLOAT

		transition_matrix[24]['o'] = 29;
		transition_matrix[29]['r'] = 30;
		// FOR

		transition_matrix[1]['i'] = 31;
		
		transition_matrix[31]['f'] = 32;
		// IF

		transition_matrix[31]['n'] = 33;
		transition_matrix[33]['t'] = 34;
		// INT

		transition_matrix[1]['r'] = 35;
		transition_matrix[35]['e'] = 36;
		transition_matrix[36]['t'] = 37;
		transition_matrix[37]['u'] = 38;
		transition_matrix[38]['r'] = 39;
		transition_matrix[39]['n'] = 40;
		// RETURN

		transition_matrix[1]['v'] = 41;
		transition_matrix[41]['o'] = 42;
		transition_matrix[42]['i'] = 43;
		transition_matrix[43]['d'] = 44;
		// VOID

		transition_matrix[1]['w'] = 45;
		transition_matrix[45]['h'] = 46;
		transition_matrix[46]['i'] = 47;
		transition_matrix[47]['l'] = 48;
		transition_matrix[48]['e'] = 49;
		// WHILE

		transition_matrix[1]['('] = 50; // LPAREN
		transition_matrix[1][')'] = 51; // RPAREN
		transition_matrix[1]['{'] = 52; // LBRACKET
		transition_matrix[1]['}'] = 53; // RBRACKET
		
		transition_matrix[1][':'] = 54;
		transition_matrix[54]['='] = 55;
		// ASSIGN

		transition_matrix[1]['='] = 56;
		transition_matrix[56]['='] = 57;
		// EQ

		transition_matrix[1]['!'] = 58;
		transition_matrix[58]['='] = 59;
		// NEQ

		transition_matrix[1]['>'] = 60; // GT
		transition_matrix[60]['='] = 61; // GE

		transition_matrix[1]['<'] = 62; // LT
		transition_matrix[62]['='] = 63; // LE

		transition_matrix[1]['-'] = 64; // SUB
		transition_matrix[1]['+'] = 65; // PLUS
		transition_matrix[1]['*'] = 66; // MULT
		transition_matrix[1]['/'] = 67; // DIV
		transition_matrix[1]['%'] = 68; // MOD

		transition_matrix[64]['>'] = 69; // ARROW

		for (char c = '0'; c <= '9'; ++c) { transition_matrix[70][c] = 70; }
		for (char c = 'A'; c <= 'Z'; ++c) { transition_matrix[70][c] = 70; }
		for (char c = 'a'; c <= 'z'; ++c) { transition_matrix[70][c] = 70; }
		// ID

		for (char c = '0'; c <= '9'; ++c) { transition_matrix[1][c] = 71; }
		for (char c = '0'; c <= '9'; ++c) { transition_matrix[71][c] = 71; }
		// NUM
		
		transition_matrix[71]['.'] = 72;
		for (char c = '0'; c <= '9'; ++c) { transition_matrix[72][c] = 73; }
		for (char c = '0'; c <= '9'; ++c) { transition_matrix[73][c] = 73; }
		// FLOAT
		
		transition_matrix[1]['#'] = 74;
		for (char c = 0; c > -1 && c < 128; ++c) { transition_matrix[74][c] = 74; }
		transition_matrix[74]['#'] = 75;
		// COMMENT

		transition_matrix[1][' '] = 76;
		transition_matrix[1]['\n'] = 76;
		transition_matrix[1]['\t'] = 76;
		// WHITEPSACE

		transition_matrix[1][','] = 77;
		// COMMA

		transition_matrix[1]['"'] = 78;
		for (char c = 0; c > -1 && c < 128; ++c) { transition_matrix[78][c] = 78; }
		transition_matrix[78]['"'] = 79;
		// STRING
		
	}

	
	void DFA::constructAcceptingStates()
	{
		for (size_t i = 0; i <= 49; ++i)
		{
			accepting.insert({i, Token::ID});
		}
		accepting[6] = Token::BREAK;
		accepting[10] = Token::CHAR;
		accepting[14] = Token::CONST;
		accepting[19] = Token::CONTINUE;
		accepting[23] = Token::ENUM;
		accepting[28] = Token::FLOAT;
		accepting[30] = Token::FOR;
		accepting[32] = Token::IF;
		accepting[34] = Token::INT;
		accepting[40] = Token::RETURN;
		accepting[44] = Token::VOID;
		accepting[49] = Token::WHILE;

		accepting.insert({50, Token::LPAREN});
		accepting.insert({51, Token::RPAREN});
		accepting.insert({52, Token::LBRACKET});
		accepting.insert({53, Token::RBRACKET});

		accepting.insert({55, Token::ASSIGN});
		accepting.insert({57, Token::EQ});
		accepting.insert({59, Token::NEQ});
		
		accepting.insert({60, Token::GT});
		accepting.insert({61, Token::GE});
		accepting.insert({62, Token::LT});
		accepting.insert({63, Token::LE});

		accepting.insert({64, Token::SUB});
		accepting.insert({65, Token::PLUS});
		accepting.insert({66, Token::MULT});
		accepting.insert({67, Token::DIV});
		accepting.insert({68, Token::MOD});

		accepting.insert({69, Token::ARROW});

		accepting.insert({70, Token::ID});
		accepting.insert({71, Token::NUM});
		accepting.insert({72, Token::FLOAT});
		accepting.insert({75, Token::COMMENT});
		accepting.insert({76, Token::WHITESPACE});

		accepting.insert({77, Token::COMMA});
		
		accepting.insert({79, Token::STRING});
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

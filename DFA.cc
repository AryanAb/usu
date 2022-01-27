#include "DFA.h"

namespace usu
{
	DFA::DFA()
	{
		for (int i = 48; i <= 57; ++i)
		{
			transition_matrix[1][i] = 7;
			transition_matrix[2][i] = 4;
			transition_matrix[3][i] = 4;
			transition_matrix[4][i] = 4;
			transition_matrix[5][i] = 6;
			transition_matrix[6][i] = 6;
			transition_matrix[7][i] = 7;
				
		}

		for (int i = 97; i <= 122; ++i)
		{
			transition_matrix[1][i] = 4;
			transition_matrix[2][i] = 4;
			transition_matrix[3][i] = 4;
			transition_matrix[4][i] = 4;
		}

		for (int i = 65; i <= 90; ++i)
		{
			transition_matrix[1][i] = 4;
			transition_matrix[2][i] = 4;
			transition_matrix[3][i] = 4;
			transition_matrix[4][i] = 4;
		}

		transition_matrix[1][45] = 9; // the '-' character
			
		transition_matrix[1][105] = 2; // the 'i' character
		transition_matrix[2][102] = 3; // the 'f' character

		transition_matrix[7][46] = 8; // the '.' character
	}
};

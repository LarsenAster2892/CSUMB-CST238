// ------  Includes ------
#include <iostream>
#include <string>
#include "EParser.h"

//----- Using Statements ----
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

// ------ Functions -------

// ------  Main (Driver) ------
int main(void)
{
	string tokenArr[14] = {"ERROR",
						   "PLUS",
						   "MINUS",
						   "MULT",
						   "DIVIDE",
						   "EXP",
						   "ASSIGN",
						   "LPAREN",
						   "RPAREN",
						   "COMMA",
						   "NUMBER",
						   "STRING",
						   "FUNCTION",
						   "END"
	};

	int ti;

	//EParser po("A = B + C - 2");
	EParser po2;
	TokenItem tt;
	string ts;
	//double td;

	//cout << "Expression 1 is " << po.Expression() << std::endl;

	po2.Expression("D = (5.4 + 7.5) / SIN(A)");

	cout << "Expression 2 is " << po2.Expression() << std::endl;
	tt = po2.GetNextToken();
	while (tt.Token != TKN_END)
	{
		ti = (int) tt.Token;
		cout << "   Token Type = " << tokenArr[ti] << endl;
		tt = po2.GetNextToken();
	}

    return 0;
}


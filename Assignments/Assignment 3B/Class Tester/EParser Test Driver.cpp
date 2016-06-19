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
	TokenType tt;
	string ts;
	double td;

	//cout << "Expression 1 is " << po.Expression() << std::endl;

	po2.Expression("D = (5 + 7) / SIN(A)");

	cout << "Expression 2 is " << po2.Expression() << std::endl;
	while ((tt = po2.GetNextToken(ts,td)) != TKN_END)
	{
		ti = (int) tt;
		cout << "   Token Type = " << tokenArr[ti] << endl;
	}

    return 0;
}


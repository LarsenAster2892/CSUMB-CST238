//********************************************************
// File Name   : EParser.cpp    
// Author      : Clarence Mitchell
// Assignment  : Number 3B
// Date Due    : October 8, 2003 (5:30 PM)
// Description : Class member functions for Expression Parser Class 
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
// ------  Includes ------
#include "EParser.H"

//
// ================= Constructors ==========================
//
EParser::EParser(/* IN    */ string inExpression): funcTable_()
	//-------------------------------------------------
	// Pre : none
	// Post: top is initialized
	//-------------------------------------------------
{
	(*this).Expression(inExpression);
}

//
// ================= Destructor ==========================
//
EParser::~EParser() 
	//-------------------------------------------------
	// Pre : none
	// Post: Parser is destructed and cleaned up
	//-------------------------------------------------
{
}

//
// ================= Accessors ==========================
//

//
// Get length of expression
//
int EParser::Count(void)	const
	//-------------------------------------------------
	// Pre : none
	// Post: total items in list is returned
	//-------------------------------------------------
{
	return ((int)expression_.length()); 
}


//
// return stored expression
//
string EParser::Expression(void)	const
	//-------------------------------------------------
	// Pre : none
	// Post: stored expression is retuned
	//-------------------------------------------------
{

	return (expression_);
}

//
// ================= Mutators ==========================
//

//
//  store expression
//
void EParser::Expression(/* IN    */ string newExpression)
	//-------------------------------------------------
	// Pre : none
	// Post: stored expression is retuned
	//-------------------------------------------------
{
	expression_ = newExpression;
	processExpression_ = expression_;

	currentPosition_ = 0;
	lastPosition_ = (int)newExpression.length();
}


//
// ================= Member Methods ==========================
//


//
// retrieves the next token in string
//
TokenItem EParser::GetNextToken(void)
	//-------------------------------------------------
	// Pre : none
	// Post: if more tokens exist
	//          return next TokenItem
	//          with Token sets TokenType
    //          if TokenType is NUMBER
	//             TokenNumer contains value
	//          else
	//             TokenString contains value
	//       else
	//          return END token with
	//          TokenNumber = 0   &&
	//          TokenString = ""
	//      processExpression is set to expression minus token
	//-------------------------------------------------

{

	//
	//  The following codes creates a string that is a substring 
	//  of expression_ from the currentPosition_ to the end of string.
 	istringstream insr(processExpression_);                      // use string as stream buffer
		
	TokenItem returnToken;
	returnToken.Token =  TKN_END;
	returnToken.data_string = "";
	returnToken.data_number = 0;
	//
	// -- move pass whitespace 
	//
	bool EndOfString = false;
	char ch = 0;

	do {
		
		if (!insr.get(ch))
		{
			EndOfString = true;
		}
		else
		{
			currentPosition_++;
		}

	} while((!EndOfString) && (ch != '\n') && isspace(ch));


	if  (!EndOfString)
	{
		switch(ch)
		{
			case '\n': break;

			case '+': returnToken.Token = TKN_PLUS;
				      returnToken.data_string = ch;
					  break;

			case '-': returnToken.Token = TKN_MINUS;
				      returnToken.data_string = ch;
					  break;

			case '*': returnToken.Token = TKN_MULT;
				      returnToken.data_string = ch;
					  break;

			case '/': returnToken.Token = TKN_DIVIDE;
				      returnToken.data_string = ch;
					  break;

			case '(': returnToken.Token = TKN_LPAREN;
				      returnToken.data_string = ch;
					  break;

			case ')': returnToken.Token = TKN_RPAREN;
				      returnToken.data_string = ch;
					  break;

			case ',':  returnToken.Token = TKN_COMMA;
				      returnToken.data_string = ch;
					  break;

			case '^':  returnToken.Token = TKN_EXP;
				      returnToken.data_string = ch;
					  break;

			case '=': returnToken.Token = TKN_ASSIGN;
				      returnToken.data_string = ch;
					  break;

			case '0': case '1':	case '2': case '3': case '4':
			case '5': case '6':	case '7': case '8': case '9':
			case '.':
					insr.putback(ch);
					insr >> returnToken.data_number;
					returnToken.Token = TKN_NUMBER;
					break;

			default:
					if (isalpha(ch))
					{
						returnToken.data_string = ch;
						while (insr.get(ch) && isalpha(ch))
						{
							returnToken.data_string += ch;
							currentPosition_++;
						}
						insr.unget();
						if (funcTable_.IsFunction(returnToken.data_string))
						{
							returnToken.Token = TKN_FUNCTION;
						}
						else
						{
							returnToken.Token = TKN_STRING;
						}
					}
					else
					{
						returnToken.Token = TKN_ERROR;
					}
		}
	}

	//
	// retrieve the rest of the buffer and store back into processExpression
	//

    string tmpExpression = "";
	while (insr.get(ch))
	{
		tmpExpression += ch;
	}

	processExpression_  = tmpExpression;

	return (returnToken);
}



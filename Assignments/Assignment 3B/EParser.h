//********************************************************
// File Name   : EParser.h       
// Author      : Clarence Mitchell
// Assignment  : Number 3A
// Date Due    : October 8, 2003 (5:30 PM)
// Description : Header file for Expression Parser class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************


#ifndef EPARSER_h
#define EPARSER_h
//
// --- INCLUDES -----
// 
#include <string>
#include <sstream>
#include "FunctionTable.h"

//----- Using Statements ----
using std::string;
using std::istringstream;


//
// --- ENUMERATORS -----
// 

static enum TokenType {
	TKN_ERROR,
	TKN_PLUS,
	TKN_MINUS,
	TKN_MULT,
	TKN_DIVIDE,
	TKN_EXP,
	TKN_ASSIGN,
	TKN_LPAREN,
	TKN_RPAREN,
	TKN_COMMA,
	TKN_NUMBER,
	TKN_STRING,
	TKN_FUNCTION,
	TKN_END
};

struct TokenItem {
	TokenType	Token;  
	double data_number;
	string data_string;

};




class EParser
{

	//
	// -- data members -----
	//
	private:
		string			expression_;
		string          processExpression_;
		int				currentPosition_;
		int				lastPosition_;
		FunctionTable   funcTable_;

		// ---- Private Member methods ----
		bool IsNumberValue(char ch); 
			//-------------------------------------------------
			// Pre : ch is assigned
			// Post: returns true if ch '0' thru '9' or '.'
			//-------------------------------------------------
	public:

		// --- Constructors ----
		EParser(/* IN    */ string inExpression = "");
	
		// --- Destructor ----
		virtual ~EParser();

		// --- Accessors -----
		int	Count(void)	const;
			//-------------------------------------------------
			// Pre : none
			// Post: total length of expression is returned
			//-------------------------------------------------

		string   Expression(void) const;
			//-------------------------------------------------
			// Pre : none
			// Post: stored expression is retuned
			//-------------------------------------------------

		// --- Mutators -------

		void   Expression(/* IN    */ string newExpression);
			//-------------------------------------------------
			// Pre : newExpression is assigned
			// Post: newexpression is stored
			//-------------------------------------------------


		// --- Member Methods -------

		TokenItem  GetNextToken(void);
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

};

#endif	
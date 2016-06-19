//********************************************************
// File Name   : EParser.h       
// Author      : Clarence Mitchell
// Assignment  : Number 3A
// Date Due    : October 8, 2003 (5:30 PM)
// Description : Header file for Evaluator class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************


#ifndef EVALUATOR_h
#define EVALUATOR_h
//
// --- INCLUDES -----
// 
#include <string>
#include <sstream>
#include <iostream>
#include "SymbolTable.h"
#include "FunctionTable.h"
#include "EParser.h"
#include "Stack.h"
#include "Queue.h"


//----- Using Statements ----
using std::string;
using std::istringstream;
using std::cout;
using std::cerr;

class Evaluator
{

	//
	// -- data members -----
	//
	private:
		string		  infixExpression_;
		string		  postfixExpression_;
		EParser		  eparser_;
		SymbolTable	  symbols_;
		FunctionTable functions_;
		Stack		  s2_;
		Queue		  q1_;

		void ConvertToPostfix(void);
        
		bool ProcessToken(string    inString,
			              TokenType inToken);

		TokenType Double2Token(double inValue);

		bool s1(string    keyString,
				TokenType dataToken);
		
		bool s2(string    keyString,
				TokenType dataToken);
		
		bool u1(TokenType dataToken);
		
		bool u2(void);
		
		bool uc(void);
		

	public:

		// --- Constructors ----
		Evaluator(/* IN    */ string infixExpression = "");
	
		// --- Destructor ----
		virtual ~Evaluator();

		// --- Accessors -----
		string   Infix(void) const;
			//-------------------------------------------------
			// Pre : none
			// Post: stored Infix expression is retuned
			//-------------------------------------------------
	
		string   Postfix(void) const;
			//-------------------------------------------------
			// Pre : none
			// Post: stored Postfix expression is retuned
			//-------------------------------------------------

		double	Value(void)	const;
			//-------------------------------------------------
			// Pre : none
			// Post: evaluated value is returned
			//-------------------------------------------------


		// --- Mutators -------

		void   Infix(/* IN    */ string newInfixExpression);
			//-------------------------------------------------
			// Pre : newInfixExpression is assigned
			// Post: newInfixexpression is stored
			//-------------------------------------------------


};

#endif	
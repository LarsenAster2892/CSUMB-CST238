//********************************************************
// File Name   : Evaluator.cpp    
// Author      : Clarence Mitchell
// Assignment  : Number 3B
// Date Due    : October 8, 2003 (5:30 PM)
// Description : Class member functions for Evaluator Class 
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
// ------  Includes ------
#include "Evaluator.H"

//
// ================= Constructors ==========================
//
Evaluator::Evaluator(/* IN    */ string infixExpression):parser_(infixExpression)  
													    :symbols_()
														:functions_()
														:s1_()
														:q1_()

	//-------------------------------------------------
	// Pre : none
	// Post: top is initialized
	//-------------------------------------------------
{
	infixExpression_ = infixExpression;
    postfixExpression_ = "";
}

//
// ================= Destructor ==========================
//
Evaluator::~Evaluator() 
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
// return stored Infix expression
//
string Evaluator::Infix(void)	const
	//-------------------------------------------------
	// Pre : none
	// Post: stored infix expression is retuned
	//-------------------------------------------------
{

	return (infixExpression_);
}

//
// return stored Postfix expression
//
string Evaluator::Postfix(void)	const
	//-------------------------------------------------
	// Pre : none
	// Post: stored postfix expression is retuned
	//-------------------------------------------------
{

	return (postfixExpression_);
}

//
// return stored Postfix expression
//
double Evaluator::Value(void)	const
	//-------------------------------------------------
	// Pre : none
	// Post: calculate and return expression value
	//-------------------------------------------------
{

	return 0;
}



//
// ================= Mutators ==========================
//

//
//  store expression
//
void Evaluator::Infix(/* IN    */ string newInfixExpression)
	//-------------------------------------------------
	// Pre : none
	// Post: stored expression is retuned
	//-------------------------------------------------
{
	infixExpression_ = infixExpression;
	parser_.Expression(infixExpression);
	symbols_.Clear();
    postfixExpression_ = "";

}


//
// ================= Member Methods ==========================
//
//
// convert infix expression to postfix expression
//
void Evaluator::ConvertToPostfix(void)
{
   TokenType tmpToken;
   double tmpValue;
   string tmpString;
   bool continueConversion = true;

	s1_.Clear();
	q1_.Clear();
	while (((tmpToken = po2.GetNextToken(tmpString,tmpValue)) != TKN_END) &&
		   (continueConversion))
	{

		switch(tmpToken)
		{
			case TokenType::TKN_STRING:
				 break;

			case TokenType::TKN_ASSIGN:
				 break;

			case TokenType::TKN_PLUS:
			case TokenType::TKN_MINUS:
				 break;

			case TokenType::TKN_MULT:
			case TokenType::TKN_DIVIDE:

				break;

			case TokenType::TKN_LPAREN:
				 break;


			case TokenType::TKN_RPAREN:
				 break;

			default:
				cerr << " invalid expression -- Cannot evaluate";
				continueConversion = false;
		}

	}

}


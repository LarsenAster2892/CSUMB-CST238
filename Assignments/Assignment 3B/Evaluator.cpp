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
Evaluator::Evaluator(/* IN    */ string infixExpression) : symbols_(),
													       eparser_(infixExpression),  
														   functions_(),
														   s2_(),
														   q1_()

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
	infixExpression_ = newInfixExpression;
	eparser_.Expression(newInfixExpression);
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
   TokenType	tmpToken;
   double		tmpValue;
   string		tmpString;
   bool			continueConversion = true;

	s2_.Clear();
	q1_.Clear();
	while (((tmpToken = eparser_.GetNextToken(tmpString, tmpValue)) != TKN_END) &&
		   (continueConversion))
	{
		continueConversion = ProcessToken(tmpString, tmpToken);
	}
	
	if (tmpToken == TKN_END)
	{
		u2();
	}

}

//
// convert infix expression to postfix expression
//
bool Evaluator::ProcessToken(string    inString,
			                 TokenType inToken)
{
	bool returnValue = true;
    ItemType		tmpItem;

		switch(inToken)
		{
			case TKN_STRING:
				 s1(inString, inToken);
				 break;

			case TKN_ASSIGN:
				if (s2_.IsEmpty())
				{
					s2(inString, inToken);
				}
				else
				{
					cerr << " invalid expression -- Cannot evaluate";
					returnValue = false;
				}

				break;

			case TKN_PLUS:
			case TKN_MINUS:
				 if (s2_.IsEmpty())
			     {
					cerr << " invalid expression -- Cannot evaluate";
					returnValue = false;
				 }
				 else
				 {
					 tmpItem = s2_.CurrentItem();
					 
					 TokenType testtoken = Double2Token(tmpItem.data);
					 
					 switch(testtoken)
					 {
						case TKN_ASSIGN:
						case TKN_LPAREN:
							 s2(inString, inToken);
							 break;

						case TKN_PLUS: 
						case TKN_MINUS:
						case TKN_MULT:
						case TKN_DIVIDE:
						case TKN_FUNCTION:
							 u1(testtoken);
							 break;

					 }
				 }
				 break;

			case TKN_MULT:
			case TKN_DIVIDE:
				 if (s2_.IsEmpty())
			     {
					cerr << " invalid expression -- Cannot evaluate";
					returnValue = false;
				 }
				 else
				 {
					 tmpItem = s2_.CurrentItem();
					 
					 TokenType testtoken = Double2Token(tmpItem.data);
					 
					 switch(testtoken)
					 {
						case TKN_ASSIGN:
						case TKN_PLUS: 
						case TKN_MINUS:
						case TKN_LPAREN:
							 s2(inString, inToken);
							 break;

						case TKN_MULT:
						case TKN_DIVIDE:
						case TKN_FUNCTION:
							 u1(tmpToken);
							 break;

					 }
				 }

				break;

			case TKN_FUNCTION:
				 if (s2_.IsEmpty())
			     {
					cerr << " invalid expression -- Cannot evaluate";
					returnValue = false;
				 }
				 else
				 {
					 tmpItem = s2_.CurrentItem();
					 
					 TokenType testtoken = Double2Token(tmpItem.data);
					 
					 switch(testtoken)
					 {
						case TKN_ASSIGN:
						case TKN_PLUS: 
						case TKN_MINUS:
						case TKN_MULT:
						case TKN_DIVIDE:
						case TKN_LPAREN:
							 s2(inString, inToken);
							 break;

						case TKN_FUNCTION:
							 u1(tmpToken);
							 break;

					 }
				 }

				break;


			case TKN_LPAREN:
				 if (s2_.IsEmpty())
			     {
					cerr << " invalid expression -- Cannot evaluate";
					returnValue = false;
				 }
				 else
				 {
					 tmpItem = s2_.CurrentItem();
					 
					 TokenType testtoken = Double2Token(tmpItem.data);
					 
					 switch(testtoken)
					 {
						case TKN_ASSIGN:
						case TKN_PLUS: 
						case TKN_MINUS:
						case TKN_MULT:
						case TKN_DIVIDE:
						case TKN_FUNCTION:
						case TKN_LPAREN:
							 s2(inString, inToken);
							 break;

					 }
				 }
				 break;


			case TKN_RPAREN:
				 if (s2_.IsEmpty())
			     {
					cerr << " invalid expression -- Cannot evaluate";
					returnValue = false;
				 }
				 else
				 {
					 tmpItem = s2_.CurrentItem();
					 
					 TokenType testtoken = Double2Token(tmpItem.data);
					 
					 switch(testtoken)
					 {
						case TKN_ASSIGN:
							cerr << " invalid expression -- Cannot evaluate";
							returnValue = false;
							break;

						case TKN_PLUS: 
						case TKN_MINUS:
						case TKN_MULT:
						case TKN_DIVIDE:
						case TKN_LPAREN:
						case TKN_FUNCTION:
							 uc();
							 break;

					 }
				 }
				 break;


			case TKN_END:
				 u2();;
				 break;

			default:
				cerr << " invalid expression -- Cannot evaluate";
				returnValue = false;
		}

	

	return (returnValue);
}


//
// convert a double to a enumerated tokenvalue
//
TokenType Evaluator::Double2Token(double inValue)
{
	int	tmpValue = (int)inValue;
    TokenType  returnToken;

	returnToken = TokenType(tmpValue);

	return(returnToken);
}

//
// Stack input onto s1 (Q1 per updated specification)
//
bool Evaluator::s1(string	keyString,
		TokenType dataToken)
{
   ItemType		tmpItem;

	tmpItem.key = keyString;
	tmpItem.data = (double)dataToken;
	q1_.Enqueue(tmpItem);

	return	(true);
}

//
// Stack input onto s2 
//
bool Evaluator::s2(string keyString,
		           TokenType dataToken)
{
   ItemType		tmpItem;

	tmpItem.key = keyString;
	tmpItem.data = (double)dataToken;
	s2_.Push(tmpItem);

	return	(true);
}

//
// unstack s2 to s1 and do another comparison
//
bool Evaluator::u1(TokenType dataToken)
{
   ItemType		tmpItem;

    tmpItem = s2_.Pop();
	q1_.Enqueue(tmpItem);

	return(ProcessToken(dataToken));
}

//
// unstack s2 to s1 until "(" then check next value for function
//     if next value is function, unstack s2 to s1
//
bool Evaluator::uc(void)
{
	bool continueFlag = true;

	ItemType		tmpItem;
	TokenType		tmpToken;

    while ( !(s2_.IsEmpty()) && (continueFlag) )
	{
		tmpItem = s2_.Pop();
		tmpToken = Double2Token(tmpItem.data);

		if (tmpToken == TKN_LPAREN)
		{
			continueFlag = false;
		}
		else
		{
			q1_.Enqueue(tmpItem);
		}
	}

	if ( !(s2_.IsEmpty()) ) 
	{	
		tmpItem = s2_.CurrentItem();
		tmpToken = Double2Token(tmpItem.data);
		if (tmpToken == TKN_FUNCTION)
		{
			q1_.Enqueue(tmpItem);
		}


	}

	return	(true);

}

//
// unstack s2 to s1 until s2 is empty
//
bool Evaluator::u2(void)
{
	bool continueFlag = true;

	ItemType		tmpItem;
	TokenType		tmpToken;

    while (!(s2_.IsEmpty()))
	{
		tmpItem = s2_.Pop();
		tmpToken = Double2Token(tmpItem.data);
		q1_.Enqueue(tmpItem);
	}

	return	(true);

}
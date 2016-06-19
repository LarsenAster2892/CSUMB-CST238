//********************************************************
// File Name   : Drill.h       
// Author      : Clarence Mitchell
// Assignment  : Number 1
// Date Due    : October 22, 2003 (5:30 PM)
// Description : Header file for Drill
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************

#ifndef DRILL_h
#define DRILL_h
//
// --- ENUMERATORS -----
// 

static enum OperatorType {
	OP_Multiply = '*',
	OP_Divide = '/',
	OP_Add = '+',
	Op_Subtract = '-'
};


class Drill
{
  private:
	int		operand1_;
	int		operand2_;
	int		answer_;
	char	operator_;
	
	// --- private functions ----

  public:
    // --- Constructors ----
    Drill();
	
	// --- Accessors -----
	int   Answer(void);
			//-------------------------------------------------
			// Pre : none
			// Post: returns value of answer
			//-------------------------------------------------
	
	int	  Operand1(void);
			//-------------------------------------------------
			// Pre : none
			// Post: returns value of operand1.
			//-------------------------------------------------
	
	int   Operand2(void);
			//-------------------------------------------------
			// Pre : none
			// Post: returns value of operand2.
			//-------------------------------------------------


	char  Operator(void);
			//-------------------------------------------------
			// Pre : none
			// Post: returns value of operator
			//-------------------------------------------------


	// --- Mutators -------


	void  Generate(void);
			//-------------------------------------------------
			// Pre : none
			// Post: random generated drill question
			//       operand1, operand2 and operator are set.
			//-------------------------------------------------


	// --- Member Methods ---

	

	// -- stream functions ---
	friend std::ostream & operator<<(/* INOUT */ std::ostream &os,
									 /* IN    */ const Drill &d);

};

	std::ostream & operator<<(std::ostream &os, const Drill &d);

#endif
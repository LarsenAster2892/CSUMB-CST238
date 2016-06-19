//********************************************************
// File Name   : Midterm 5-30
// Author      : Clarence Mitchell
// Assignment  : Midterm Extra Credit
// Date Due    : October 22, 2003 (5:30 PM)
// Description : Midterm Problem 5-30 Solution 1-15
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************

// ------  Includes ------
#include <iostream>
#include <string>

//----- Using Statements ----
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
//
// --- ENUMERATORS -----
// 

static enum OperatorType {
	OP_Multiply = '*',
	OP_Divide = '/',
	OP_Add = '+',
	Op_Subtract = '-'
};

//
// --- DEFINED TYPES  -----
//
struct DrillType {
	int				Operand1;  
	OperatorType	Operator;
	int				Operand2;
	int				Answer;
};


struct SummaryType {
	int		RigntAnswers;  
	int		MissedAnswers;
};

// ------ Functions -------
bool		GetContinue(void);
			//-------------------------------------------------
			// Pre : none
			// Post: if users enters 'Y' to continue 
			//          returns TRUE
			//       else
			//          return FALSE
			//-------------------------------------------------


DrillType	GenerateQuestion();
			//-------------------------------------------------
			// Pre : none
			// Post: returns random generated drill question
			//-------------------------------------------------

void		DisplayQuestion(/*	IN	*/ DrillType DrillQuestion);
			//-------------------------------------------------
			// Pre : DrillQuestion is assigned
			// Post: DrillQuestion is displayed for user
			//-------------------------------------------------

bool		ValidateAnswer(/*	IN	*/ DrillType DrillQuestion,
						   /*	IN	*/ int		 UserAnswer);
			//-------------------------------------------------
			// Pre : DrillQuestion is assigned
			// Post: Returns True if User Answer is correct
			//       else returns False 
			//-------------------------------------------------


void		DisplayPositiveFeedBack();
			//-------------------------------------------------
			// Pre : None
			// Post: Displays At-a-boy/girl message
			//-------------------------------------------------


void		DisplayEncouragement();
			//-------------------------------------------------
			// Pre : None
			// Post: Displays good Try, but not right message
			//-------------------------------------------------

void		DisplaySummary(/*	IN	*/ SummaryType DrillSummary);
			//-------------------------------------------------
			// Pre : None
			// Post: Displays summary of Drill
			//-------------------------------------------------

// ------  Main (Driver) ------
int main(void)
{
	DrillType	dt;
	SummaryType st;
	int			UserAnswer;

	st.MissedAnswers = 0;
	st.RigntAnswers = 0;

	cout << endl;
	cout << "------- Welcome to the Computer Assisted Instruction (CAI) Program ------" << endl;
	cout << endl;
	cout << "   This program provides basic math drills  " << endl;
	cout << "   You are presented with math drills  " << endl;
	cout << "   consisting of two whole numbers and one operator " << endl;
	cout << "   you will prompted for the answer " << endl;
	cout << endl;

	while (GetContinue())
	{
		dt = GenerateQuestion();
		DisplayQuestion(dt);
		cin >> UserAnswer;
		cin.ignore();
		if (ValidateAnswer(dt, UserAnswer))
		{
			DisplayPositiveFeedBack();
			st.RigntAnswers++;
		}
		else
		{
			DisplayEncouragement();
			st.MissedAnswers++;
		}

	}
	DisplaySummary(st);
    return 0;
}

//========================================================================
// Functions
//=======================================================================
bool		GetContinue(void)
//-------------------------------------------------
// Pre : none
// Post: if users enters 'Y' to continue 
//          returns TRUE
//       else
//          return FALSE
//-------------------------------------------------

{
	char ch;
	cout << " Continue (Y/N)? ";
	ch = cin.get();
	return (ch != 'N');
}

DrillType	GenerateQuestion()
//-------------------------------------------------
// Pre : none
// Post: returns random generated drill question
//-------------------------------------------------
{
	DrillType tmpdt;
	tmpdt.Operand1 = 2;
	tmpdt.Operand2 = 6;
	tmpdt.Operator = OP_Add;
	tmpdt.Answer = 8;
	return (tmpdt);

}

void		DisplayQuestion(/*	IN	*/ DrillType DrillQuestion)
//-------------------------------------------------
// Pre : DrillQuestion is assigned
// Post: DrillQuestion is displayed for user
//-------------------------------------------------

{

	cout << " How much is " << DrillQuestion.Operand1 << " " 
		                    << (char)DrillQuestion.Operator << " "
				            << DrillQuestion.Operand2 << " ?";
}


bool		ValidateAnswer(/*	IN	*/ DrillType DrillQuestion,
						   /*	IN	*/ int		 UserAnswer)
//-------------------------------------------------
// Pre : DrillQuestion is assigned
// Post: Returns True if User Answer is correct
//       else returns False 
//-------------------------------------------------
{
	return (DrillQuestion.Answer == UserAnswer);
}


void		DisplayPositiveFeedBack()
//-------------------------------------------------
// Pre : None
// Post: Displays At-a-boy/girl message
//-------------------------------------------------
{
	cout << endl;
	cout << "  You are right.  Great Job!! " << endl;
	cout << endl;
}

void		DisplayEncouragement()
//-------------------------------------------------
// Pre : None
// Post: Displays good Try, but not right message
//-------------------------------------------------
{
	cout << endl;
	cout << "  Incorrect Answer but Good Try! " << endl;
	cout << endl;
}

void		DisplaySummary(/*	IN	*/ SummaryType DrillSummary)
//-------------------------------------------------
// Pre : None
// Post: Displays summary of Drill
//-------------------------------------------------
{
	cout << endl;
	cout << "---- Summary of your drill ----" << endl;
	cout << "  Correct Answers: " << DrillSummary.RigntAnswers << endl;
	cout << "  Missed  Answers: " << DrillSummary.MissedAnswers << endl;
	cout << endl;
}

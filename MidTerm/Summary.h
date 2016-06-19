//********************************************************
// File Name   : Summary.h       
// Author      : Clarence Mitchell
// Assignment  : Number 1
// Date Due    : October 22, 2003 (5:30 PM)
// Description : Header file for Summary
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************

#ifndef SUMMARY_h
#define SUMMARY_h
using std::cout;
using std::endl;

class Summary
{
  private:
	int	right_;
	int wrong_;							  	

	
	// --- private functions ----

  public:
    // --- Constructors ----
    Summary();
	
	// --- Accessors -----
	int	  CorrectAnswers(void);
			//-------------------------------------------------
			// Pre : none
			// Post: returns number of correct Answer so far.
			//-------------------------------------------------
	
	int   MissedAnswers(void);
			//-------------------------------------------------
			// Pre : none
			// Post: returns number of missed Answer so far.
			//-------------------------------------------------


	// --- Mutators -------
	void Clear(void);
			//-------------------------------------------------
			// Pre : none
			// Post: correct and missed answers are set to zero
			//-------------------------------------------------

	void IncrementCorrect(void);
			//-------------------------------------------------
			// Pre : none
			// Post: correct answers is incremented by 1
			//-------------------------------------------------

	void IncrementMissed(void);
			//-------------------------------------------------
			// Pre : none
			// Post: missed answers is incremented by 1
			//-------------------------------------------------


	// --- Member Methods ---




	// -- stream functions ---
	friend std::ostream & operator<<(/* INOUT */ std::ostream &os,
									 /* IN    */ const Summary &s);

};

	std::ostream & operator<<(std::ostream &os, const Summary &s);

#endif
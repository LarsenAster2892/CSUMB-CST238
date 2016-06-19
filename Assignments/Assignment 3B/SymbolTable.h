//********************************************************
// File Name   : SymbolTable.h       
// Author      : Clarence Mitchell
// Assignment  : Number 3B
// Date Due    : October 8, 2003 (5:30 PM)
// Description : Header file for SymbolTable class
// -----------------------------------------------------------             
// Class       : CISP430 - FALL 2003 MW 5:30PM
// Instructor  : Dixon
// ********************************************************
//
// --- INCLUDES -----
// 
#include <string>
#include "List.h"
//
// ---- USING STATEMENTS ---
//
using std::string;

#ifndef SYMBOLTABLE_h
#define SYMBOLTABLE_h

//
// --- CONSTANTS -----
// 


class SymbolTable
{

	//
	// -- data members -----
	//
	private:
	List symbolList_;
	// --- private functions ----

	public:
		// --- Constructors ----
		SymbolTable();
	
		// --- Destructor ----
		virtual ~SymbolTable();

		// --- Accessors -----
		long Count(void)	const;
			//-------------------------------------------------
			// Pre : none
			// Post: total items in SymbolTable is returned
			//-------------------------------------------------

		// --- Mutators -------


		// --- Member Methods ---

		bool Add(/* IN    */ string	symbolName,
			     /* IN    */ double symbolValue = 0.0 );
			//-------------------------------------------------
			// Pre : SymbolName is assigned 
			// Post: if Memory available 
			//          SymbolName and value are added to table
			//          and TRUE is returned
			//       else
			//          FALSE is returned
			//-------------------------------------------------

		void Clear(void);
			//-------------------------------------------------
			// Pre : none
			// Post: SymbolTable is empty 
			//-------------------------------------------------

		bool CurrentSymbol(/* OUT    */ string & symbolName,
			               /* OUT    */ double & symbolValue) const;
			//-------------------------------------------------
			// Pre : !IsEmpty 
			// Post: if not IsEmpty
			//			SymbolName is set to name
			//          SymbolValue is set to value
			//          and TRUE is returned
			//       else
			//          FALSE is returned
			//-------------------------------------------------


		bool Delete(/* IN    */ string	symbolName);
			//-------------------------------------------------
			// Pre : SymbolName is assigned 
			// Post: if symbolname in symboltable
			//          SymbolName and value are deleted from table
			//          and TRUE is returned
			//       else
			//          FALSE is returned
			//-------------------------------------------------
		
		bool GetValue(/* IN    */ string   symbolName,
			          /* OUT   */ double & symbolValue);
			//-------------------------------------------------
			// Pre : SymbolName is assigned 
			// Post: if symbolname in symboltable
			//          SymbolValue is set to value
			//          and TRUE is returned
			//       else
			//          FALSE is returned
			//-------------------------------------------------

		bool IsEmpty(void)	const;
			//-------------------------------------------------
			// Pre : none
			// Post: returns TRUE Symbol Table is empty 
			//-------------------------------------------------


		bool IsFull(void)	const;
			//-------------------------------------------------
			// Pre : none
			// Post: returns TRUE out of memory space
			//-------------------------------------------------

		bool SetValue(/* IN    */ string symbolName,
			          /* IN    */ double symbolValue);
			//-------------------------------------------------
			// Pre : SymbolName is assigned 
			// Post: if symbolname in symboltable
			//          value is set to SymbolValue
			//          and TRUE is returned
			//       else
			//          FALSE is returned
			//-------------------------------------------------


		void MoveFirst(void);
			//-------------------------------------------------
			// Pre : none
			// Post: set Current to first Item
			//-------------------------------------------------

		
		void MoveLast(void);
			//-------------------------------------------------
			// Pre : none
			// Post: set Current to Last Item
			//-------------------------------------------------

		void MoveNext(void);
			//-------------------------------------------------
			// Pre : !IsEmpty && current item != Last
			// Post: if !isEmpty
		    //          if current Item != last
			//             current points to next symbol
			//          else
		    //             current points to last symbol
			//       
			//-------------------------------------------------

};

#endif
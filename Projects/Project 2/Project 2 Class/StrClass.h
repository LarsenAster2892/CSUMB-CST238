/***************************************************************************

	Clarence Mitchell
    (Header)
****************************************************************************/
/*=========================================================================**

  Member functions should operate on the object.
  Producing a new object as the return value is more appropriately done
  as a regular or friend function.

**==========================================================================*/
#include <iostream.h>
// #include <strstrea.h>
#include <iomanip.h>
//#include <string.h>
#include <stdlib.h>  // for strtol()

//
// - namespace used only for mutliple instances --
//
//namespace cmitchell_string_nmspace
//{

//================================================================
//
// STRING CLASS DEFINITION
//
//==============================================================
class string
{
//--------------------------------
// member data & private functions
//--------------------------------
	private:
// ---  member data

        char *strData;                    // storage for characters
        size_t strLength;                 // length of string (# of characters)


//--  private member functions 

//
//  This function is used to coping string data
//
	void String_Copy (/* OUT */ char* string_1,
					  /* IN  */ const char* string_2);
	//----------------------------------------------------------------------
	//Pre:  IsAllocated(string1) && IsAllocated(string2) &&
	//      IsNullTerminated(string1) && IsNullterminated(string2)
	//Post: (string_length(string_1) == string_length(string_2) 
	//       && FA(i = 1...80):(string_1[i] == string_2[i])  
	//		 && string_2 == string_2 <entry>
	//======================================================================*/

//
//  This function is to determine char string length
//
	int String_Length (/* IN */ const char* string_1);
	//----------------------------------------------------------------------
	//Pre:  IsAllocated(string1) && IsNullTerminated(string1)
	//      
	//Post: FCTVAL  == Character_Postion(string_1, '\0') - 1
	//      &&  string_1 == string_1 <entry>  
	//======================================================================*/


		
		
		
	public
		// 
		// === CONSTRUCTORS AND DESTRUCTORS ===
		//
		string();
		string(const char* ptrChar_1);
		string(const char Char_1);
		string(const string& String_1);   // Copy constructor
		~string();
 		
		//
		// -- CASE 
		//
		void ucase();
		void downcase();
		void togglecase();
		//
		// -- OPERATOR
		//
		void operator =(const string& String_1);
		void operator +=(const string& String_1);
		// 
		// === CONSTANT MEMBER FUNCTIONS ===
		//
		size_t length() const;
		int	position(const char char_1) const;
		char operator [ ](size_t intNum_1) const;
		char &operator [ ](size_t intNum_1);
		//
		// === FRIEND FUNCTIONS ===
		//
		// -- CAST ---
	    operator const char *() const; // cast to C-style string
        operator long() const;         // cast to long integer
		//
		//
		// -- COMPARE (string op string)
		//
		friend bool operator ==(const string& String_1, const string String_2);
		friend bool operator !=(const string& String_1, const string String_2);
		friend bool operator >=(const string& String_1, const string String_2);
		friend bool operator <=(const string& String_1, const string String_2);
		friend bool operator <(const string& String_1, const string String_2);
		friend bool operator <(const string& String_1, const string String_2);
//
//
// The following are not needed as the promotion path for char and char* 
// have been provided via the constructors (see constructors).
//		
//		
//		void operator +=(const char* ptrChar_1);
//		void operator +=(const char);
//
//
		
		//
		// -- COMPARE (string op char)
		//
//		friend bool operator ==(const string& String_1, const char Char_1);
//		friend bool operator !=(const string& String_1, const char Char_1);
//		friend bool operator >=(const string& String_1, const char Char_1);
//		friend bool operator <=(const string& String_1, const char Char_1);
//		friend bool operator <(const string& String_1, const char Char_1);
//		friend bool operator <(const string& String_1, const char Char_1);
		//
		// -- COMPARE (string op char*)
		//
//		friend bool operator ==(const string& String_1, const char* Char_1);
//		friend bool operator !=(const string& String_1, const char* Char_1);
//		friend bool operator >=(const string& String_1, const char* Char_1);
//		friend bool operator <=(const string& String_1, const char* Char_1);
//		friend bool operator <(const string& String_1, const char* Char_1);
//		friend bool operator <(const string& String_1, const char* Char_1);

		//
		// -- COMPARE (char op string)
		//
//		friend bool operator ==(const char Char_1, const string& String_1);
//		friend bool operator !=(const char Char_1, const string& String_1);
//		friend bool operator >=(const char Char_1, const string& String_1);
//		friend bool operator <=(const char Char_1, const string& String_1);
//		friend bool operator <(const char Char_1, const string& String_1);
//		friend bool operator <(const char Char_1, const string& String_1);
		//
		// -- COMPARE (char* op string)
		//
//		friend bool operator ==(const char* Char_1, const string& String_1);
//		friend bool operator !=(const char* Char_1, const string& String_1);
//		friend bool operator >=(const char* Char_1, const string& String_1);
//		friend bool operator <=(const char* Char_1, const string& String_1);
//		friend bool operator <(const char* Char_1, const string& String_1);
//		friend bool operator <(const char* Char_1, const string& String_1);
		//	
		// Stream I/O operators and functions
		//
		void GetLine( istream & inp );
		friend istream & operator >>( istream & inp, string & s );
		friend ostream & operator <<( ostream & os, const string & s );
//
//} /* End of Namespace */

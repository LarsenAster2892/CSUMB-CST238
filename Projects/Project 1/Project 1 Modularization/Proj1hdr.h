/***************************************************************************

	Clarence Mitchell
	CIS 40 - MW 1:30 pm
	Programming Project 1
	February 4, 2002
    (Headers)
****************************************************************************/
const int MAXSTRING = 81;	    // The max string length plus one for Null 
								//	  terminator
typedef char STR80[MAXSTRING];  // Declare a type for variable declarations
                                //	This forces all strings passed to the 
								//	created string functions to be declared
								//	as char[81] arrarys;

/*==========================================================================
Predicate functions used in PRE and POST conditions

  bool IsAllocated ( STR80 string1): returns true if string1 points to an 
							allocated STR80 memory.
							false otherwise

  bool IsCharAllocated ( char char1): returns true if char1 points to an 
							allocated char memory. 
							false otherwise

  bool IsIntAllocated ( int int1): returns true if int1 points to an 
							allocated integer memory. 
						   false otherwise

  bool IsMaxString (STR80 string1): returns true if string1 points to an
							allocated str80 that has a length equal 
							to MAXSTRING

  bool IsNullTerminated ( STR80 string1): returns true if string1 points to 
					       allocated memory string that is terminated
							by a null and the null termination is within
							its memory allocation. 
						    false otherwise

  bool IsValid ( STR80 string1): returns true if string1 points to an 
							allocated STR80 memory with a null terminator
							within the 80 char memory bounds.
							false otherwise


 ===========================================================================*/


bool String_Compare (/* IN */ const STR80 string_1,
					 /* IN */ const STR80 string_2);
	//----------------------------------------------------------------------
	//Pre:  IsAllocated(string1) && IsAllocated(string2) &&
	//      IsNullTerminated(string1) && IsNullterminated(string2)
	//Post: FCTVAL == ((string_length(string_1) == string_length(string_2)) 
	//       && FA(i = 1...80):(string_1[i] == string_2[i])
	//       && string_1 == string_1 <entry>  
	//		 && string_2 == string_2 <entry>
	//======================================================================*/


void String_Copy (/* OUT */ STR80& string_1,
				  /* IN  */ const STR80 string_2);
	//----------------------------------------------------------------------
	//Pre:  IsAllocated(string1) && IsAllocated(string2) &&
	//      IsNullTerminated(string1) && IsNullterminated(string2)
	//Post: (string_length(string_1) == string_length(string_2) 
	//       && FA(i = 1...80):(string_1[i] == string_2[i])  
	//		 && string_2 == string_2 <entry>
	//======================================================================*/


int String_Length (/* IN */ const STR80 string_1);
	//----------------------------------------------------------------------
	//Pre:  IsAllocated(string1) && IsNullTerminated(string1)
	//      
	//Post: FCTVAL  == Character_Postion(string_1, '\0') - 1
	//      &&  string_1 == string_1 <entry>  
	//======================================================================*/



bool Compare_String_Length (/* OUT */ const STR80 string_1,
						    /* IN  */ const STR80 string_2);
	//----------------------------------------------------------------------
	//Pre:  IsAllocated(string1) && IsAllocated(string2) &&
	//      IsNullTerminated(string1) && IsNullterminated(string2)
	//Post: FCTVAL == ((string_length(string_1) == string_length(string_2)) 
	//       && string_1 == string_1 <entry>  
	//		 && string_2 == string_2 <entry>
	//======================================================================*/


bool Compare_Alpha (/* OUT */ const STR80 string_1,
				    /* IN  */ const STR80 string_2);
	//----------------------------------------------------------------------
	//Pre:  IsAllocated(string1) && IsAllocated(string2) &&
	//      IsNullTerminated(string1) && IsNullterminated(string2)
	//Post: FCTVAL == (string_1 < string_2)
	//       && string_1 == string_1 <entry>  
	//		 && string_2 == string_2 <entry>
	//======================================================================*/

					
void String_Concat (/* INOUT */ STR80& string_1,
				    /* IN    */ const STR80 string_2);
	//----------------------------------------------------------------------
	//Pre:  IsAllocated(string1) && IsAllocated(string2) &&
	//      IsNullTerminated(string1) && IsNullterminated(string2) &&
	//      (String_Length(string_1) + String_Length(string_2) < MAXSTRING)
	//Post: String_1 === FA(i = 1 .. Character_Postion(string_1 <entry>, '\0')): 
	//             string_1[i] == string_1[i] <entry>) &&
	//             FA(i = 1 .. String_length(string_2):
	//             string_1[Character_Postion(string_1 <entry>, '\0')) + i] =
	//             string_2[i])
	//		 && string_2 == string_2 <entry>
	//======================================================================*/


void Char_Concat_Post (/* INOUT */ STR80& string_1,
				       /* IN    */ const char char_1);
	//----------------------------------------------------------------------
	//Pre:  IsAllocated(string1) && IsAllocated(char_1) &&
	//      IsNullTerminated(string1) 
	//      (String_Length(string_1) + 1 < MAXSTRING)
	//Post: String_1 === FA(i = 1 .. Character_Postion(string_1 <entry>, '\0')): 
	//             string_1[i] == string_1[i] <entry>) &&
	//             string_1[Character_Postion(string_1 <entry>, '\0'))] =
	//             char_1) &&
	//             string_1[Character_Postion(string_1 <entry>, '\0'))] +1]
	//             = '\0'    
	//		 && char_1 == char_1 <entry>
	//======================================================================*/


void Char_Concat_Pre (/* IN    */ const char char_1,
				      /* INOUT */ STR80& string_1);
	//----------------------------------------------------------------------
	//Pre:  IsAllocated(string1) && IsAllocated(char_1) &&
	//      IsNullTerminated(string1)
	//      (String_Length(string_1) + 1 < MAXSTRING)
	//Post: String_1 == (string[1] = char_1) &&
	//             FA(i = 2 .. Character_Postion(string_1 <entry>, '\0')): 
	//             string_1[i] == string_1[i-1] <entry>) &&
	//             string_1[Character_Postion(string_1 <entry>, '\0'))] +1]
	//             = '\0'    
	//		 && char_1 == char_1 <entry>
	//======================================================================*/


int Character_Postion (/* IN */ const STR80 string_1,
				     /* IN */ const char  char_1);
	//----------------------------------------------------------------------
	//Pre:  IsAllocated(string1) && IsIntAllocated(char_1) &&
	//      IsNullTerminated(string1) 
	//Post: FCTVAL == if char_1 within string1,
    //                   INT : 0<= INT <= string_length(string1),
	//                else
	//                   -1
	//======================================================================*/




int Numeric_Postion (/* IN */ const STR80 string_1,
				     /* IN */ const int   int_1);
	//----------------------------------------------------------------------
	//Pre:  IsAllocated(string1) && IsIntAllocated(int_1) &&
	//      IsNullTerminated(string1) 
	//Post: FCTVAL == if int_1 <= string_length(string1)
    //                   string[int_1]
	//                else
	//                   -1
	//======================================================================*/



void Display_String (/* IN */ const STR80 string_1);
	//----------------------------------------------------------------------
	//Pre:  IsAllocated(string_1) && IsNullTerminated(string_1)
	//      
	//Post: cout << string_1
	//Post: ( cout << "< " &&
	//        FA(i = 1...String_lenght(string_1)): cout << string_1[i] <<", "
	//			cout << "< NULL >"
	//======================================================================*/

      
void Empty_String (/* OUT*/ STR80& string_1);
	//----------------------------------------------------------------------
	//Pre:  IsAllocated(string_1) 
	//      
	//Post: string_1[1] = '\n'
	//======================================================================*/



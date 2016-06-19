/*********************************************************************************

	Clarence Mitchell
	CIS 40 - MW 1:30 pm
	Programming Project 1
	February 13, 2002
    (String Functions)
**********************************************************************************/
#include <iostream.h>
#include <conio.h>
#include <ctype.h>

#include "proj1hdr.h"

/*--------------------------------------------------------------------------*/
bool String_Compare (/* IN */ const STR80 string_1,
					 /* IN */ const STR80 string_2)
//-------------------------------------------------------------------------
//Pre:  #include "proj1hdr.h"
//Post: #include "proj1hdr.h"    
//	
	
{
	bool blnReturn = false;
	int intTestLen = 0;

	if (Compare_String_Length(string_1,string_2))
	{
		intTestLen = String_Length(string_1);
		for (int intX = 0;
			 intX <= intTestLen && string_1[intX] == string_2[intX];
			 intX++);
		blnReturn = (intX > intTestLen); 
	}

	return blnReturn;
}
/*--------------------------------------------------------------------------*/
/*            End of Function
/*--------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------*/

void String_Copy (/* OUT */ STR80& string_1,
				  /* IN  */ const STR80 string_2)
//-------------------------------------------------------------------------
//Pre:  #include "proj1hdr.h"
//Post: #include "proj1hdr.h"    
//	
{
	for (int intX = 0;
		 intX <= String_Length(string_2)+1;
		 intX++)
		 {
			string_1[intX] =  string_2[intX];
		 }

	/* return void */
}
/*--------------------------------------------------------------------------*/
/*            End of Function
/*--------------------------------------------------------------------------*/



//-------------------------------------------------------------------------
int String_Length (/* IN */ const STR80 string_1)
//-------------------------------------------------------------------------
//Pre:  #include "proj1hdr.h"
//Post: #include "proj1hdr.h"    
//	
{
	int intX;

	for (intX = 0; intX < MAXSTRING && string_1[intX] != '\0'; intX++);
    
	return intX;

}
/*--------------------------------------------------------------------------*/
/*            End of Function
/*--------------------------------------------------------------------------*/



//-------------------------------------------------------------------------
bool Compare_String_Length (/* OUT */ const STR80 string_1,
							/* IN  */ const STR80 string_2)
//-------------------------------------------------------------------------
//Pre:  #include "proj1hdr.h"
//Post: #include "proj1hdr.h"    
//	
{
	return (String_Length(string_1) == String_Length(string_2));
//	return true;
}
/*--------------------------------------------------------------------------*/
/*            End of Function
/*--------------------------------------------------------------------------*/


/*==========================================================================*/
bool Compare_Alpha (/* OUT */ const STR80 string_1,
				    /* IN  */ const STR80 string_2)
//-------------------------------------------------------------------------
//Pre:  #include "proj1hdr.h"
//Post: #include "proj1hdr.h"
//      
//	
{
	bool blnReturn;
	int intStr1Len, intStr2Len, intEndVal;

  intStr1Len = String_Length(string_1);
  intStr2Len = String_Length(string_2);
  
  intEndVal = (intStr1Len < intStr2Len) ? intStr1Len : intStr2Len;
  
  for (int intX = 0; 
     ((intX <= intEndVal) && (string_1[intX] == string_2[intX]));
	   intX++);
	
   if (intX > intEndVal)				// Reached end and both strings are the same
	  blnReturn = (intStr1Len <  intStr2Len);
   else  
		if  ((isalpha(string_1[intX]) && isalpha(string_2[intX])) && 
		     (toupper(string_1[intX]) != toupper(string_2[intX])))

			blnReturn = (toupper(string_1[intX]) < toupper(string_2[intX]));

		else

			blnReturn = (string_1[intX] < string_2[intX]);

	return blnReturn;
}
/*--------------------------------------------------------------------------*/
/*            End of Function
/*--------------------------------------------------------------------------*/
	

//-------------------------------------------------------------------------
void String_Concat (/* INOUT */ STR80& string_1,
				    /* IN    */ const STR80 string_2)
//-------------------------------------------------------------------------
//Pre:  #include "proj1hdr.h"
//Post: #include "proj1hdr.h"    
//	
{
	int intEnd;

	if (((String_Length(string_1) + String_Length(string_2)) >= MAXSTRING))
		intEnd = (String_Length(string_1) + String_Length(string_2)) - MAXSTRING;
	else
		intEnd = String_Length(string_2);
	
	for (int intX = 0; intX <= intEnd; intX++)
		Char_Concat_Post(string_1, string_2[intX]);

//	string_1[intX] = '\0';

}
/*--------------------------------------------------------------------------*/
/*            End of Function
/*--------------------------------------------------------------------------*/


//-------------------------------------------------------------------------
void Char_Concat_Post (/* INOUT */ STR80& string_1,
				       /* IN    */ const char char_1)
//-------------------------------------------------------------------------
//Pre:  #include "proj1hdr.h"
//Post: #include "proj1hdr.h"    
//	
{
	int intEnd ;

	intEnd = String_Length(string_1);

	if (intEnd < MAXSTRING)
	{
		string_1[intEnd] = char_1;
		string_1[intEnd + 1] = '\0';
	
	}

}
/*--------------------------------------------------------------------------*/
/*            End of Function
/*--------------------------------------------------------------------------*/


//-------------------------------------------------------------------------
void Char_Concat_Pre (/* IN    */ const char char_1,
				      /* INOUT */ STR80& string_1)
//-------------------------------------------------------------------------
//Pre:  #include "proj1hdr.h"
//Post: #include "proj1hdr.h"    
//	

{
	int intEnd ;

	intEnd = String_Length(string_1);

	if ((intEnd + 1) < MAXSTRING)
	{
		for (int intX = intEnd+1; intX >= 0; intX--)
		{
			string_1[intX + 1] = string_1[intX];
		}

		string_1[0] = char_1;
	}

}
/*--------------------------------------------------------------------------*/
/*            End of Function
/*--------------------------------------------------------------------------*/


//-------------------------------------------------------------------------
int Character_Postion (/* IN */ const STR80 string_1,
				     /* IN */ const char  char_1)
//-------------------------------------------------------------------------
//Pre:  #include "proj1hdr.h"
//Post: #include "proj1hdr.h"    
//	
{
	int intStrLen;
	
	intStrLen = String_Length(string_1);
	for (int intX = 0; (intX <= intStrLen) && (string_1[intX] != char_1); intX++);
	


	return ((intX <= intStrLen)? intX+1 : -1);
}
/*--------------------------------------------------------------------------*/
/*            End of Function
/*--------------------------------------------------------------------------*/

//-------------------------------------------------------------------------
int Numeric_Postion (/* IN */ const STR80 string_1,
				     /* IN */ const int   int_1)
//-------------------------------------------------------------------------
//Pre:  #include "proj1hdr.h"
//Post: #include "proj1hdr.h"    
//	
{
    int intReturnValue = -1;

	if (int_1 <= String_Length(string_1))
		intReturnValue = string_1[int_1 - 1];

	return intReturnValue;
}
/*--------------------------------------------------------------------------*/
/*            End of Function
/*--------------------------------------------------------------------------*/


//-------------------------------------------------------------------------
void Display_String (/* IN */ const STR80 string_1)
//-------------------------------------------------------------------------
//Pre:  #include "proj1hdr.h"
//Post: #include "proj1hdr.h"    
//	
{
	
	for (int intX = 0;
		 intX <= String_Length(string_1);
		 intX++)
		 {
			cout <<string_1[intX];
		 }
	cout <<endl;

}
/*--------------------------------------------------------------------------*/
/*            End of Function
/*--------------------------------------------------------------------------*/

//-------------------------------------------------------------------------
void Empty_String (/* OUT*/ STR80& string_1)
//-------------------------------------------------------------------------
//Pre:  #include "proj1hdr.h"
//Post: #include "proj1hdr.h"    
//	
{
	STR80 strEmpty = "\n";
	String_Copy(string_1,strEmpty);
	/* return void */
}
/*--------------------------------------------------------------------------*/
/*            End of Function
/*--------------------------------------------------------------------------*/



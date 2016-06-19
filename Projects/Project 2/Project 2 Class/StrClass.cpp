// #include <string.h>
#include "StrClass.h"
//#include <strstream.h>
//
//###########################################################
//
// Constuctors and Destructor
//
//###########################################################
//

//==========================================================*/
//
// Default constructor creates string of 0 bytes
//
//==========================================================*/
String::String()
//---------------------------------------------------------
{
	strData = new char[1];
	strData[0] = '\0';
	strLength=0;
	// cout << "\tDefault string constructor\n";
	// ConstructorCount++;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            End of Member Function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//==========================================================*/
//
//  Constructor used for promotion path of char* to string
//
//==========================================================*/
string::string(/* IN  */ const char* ptrChar_1 )
//---------------------------------------------------------
{
    if( ptrChar_1 == NULL )
        ptrChar_1 = "";

	strLength = String_Length(ptrChar_1);
	strData = new char[strLength+1];
	String_Copy(strData, ptrChar_1);
   //
   // cout << "\tString(char*) constructor\n";
   // ConstructorCount++;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            End of Member Function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


//==========================================================*/
//
// Constructor used for promotion path of char to string 
//
//==========================================================*/
string::string(/* IN  */ const char Char_1 )
//---------------------------------------------------------
{

	strLength = 1;
	strData = new char[strLength+1];
	strData[0] = Char_1;
	strData[1] = '\0';
   //
   // cout << "\tString(char*) constructor\n";
   // ConstructorCount++;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            End of Member Function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


//==========================================================*/
//
// Copy Constructor
//
//==========================================================*/
string::string(/* IN  */ const string& String_1 )
//---------------------------------------------------------
{
    strLength = String_1.strLength;
    strData = new char[ strLength + 1 ];
    String_Copy( strData, String_1.strData );
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            End of Member Function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//==========================================================*/
//
// Destructor
//
//==========================================================*/
string::~string()
//---------------------------------------------------------
{
	delete [] strData;
	strLength = 0;
	// cout << "\tString destructor\n";
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            End of Member Function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


//
//==========================================================
//
// Private member functions
//
//==========================================================

//---------------------------------------------------------*/
void String_Copy (/* OUT */ char* string_1,
				  /* IN  */ const char* string_2)
//---------------------------------------------------------
{
	for (int intX = 0;
		 intX <= String_Length(string_2)+1;
		 intX++)
		 {
			string_1[intX] =  string_2[intX];
		 }

	/* return void */
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            End of Member Function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/



//---------------------------------------------------------*/
int String_Length (/* IN */ const char* string_1)
//---------------------------------------------------------
{
	int intX;

	for (intX = 0; string_1[intX] != '\0'; intX++);
    
	return intX;

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            End of Member Function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/



//---------------------------------------------------------*/
bool String_Compare (/* OUT */ const STR80 string_1,
				    /* IN  */ const STR80 string_2)
//---------------------------------------------------------
//	
{
  int intReturn;
  int intStr1Len, intStr2Len, intEndVal;
  char chrTest_1, chrTest_2;

  intStr1Len = String_Length(string_1);
  intStr2Len = String_Length(string_2);
  
  intEndVal = (intStr1Len < intStr2Len) ? intStr1Len : intStr2Len;
  
  for (int intX = 0; 
     ((intX <= intEndVal) && (string_1[intX] == string_2[intX]));
	   intX++);
	
   if (intX > intEndVal)	// Reached end
	                        // and strings match to this point
	  intReturn = (intStr1Len -  intStr2Len);
   else 
   // Add assertion that strings are equal up to intX point,
   // and therefore only intX position needs to be tested.
   // Additionally, intX position can only be < or >, since
   // equal would be handled in the first part of the this if statement.
   {
		if  ((isalpha(string_1[intX]) && isalpha(string_2[intX])) && 
			(toupper(string_1[intX]) != toupper(string_2[intX])))
		{
            chrTest_1 = toupper(string_1[intX]);
		    chrTest_2 = toupper(string_2[intX]);

		}
		else
		{
            chrTest_1 = string_1[intX];
		    chrTest_2 = string_2[intX];
		}

	
		intReturn = (chrTest_1 < chrTest_2 ? -1 : 1;
   }
	return (intReturn);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            End of Function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	

//
//==========================================================
//
// Public Member Functions
//
//==========================================================
//
//---------------------------------------------------------*/
const string &string::operator=( const string & String_1 )
//---------------------------------------------------------
{
    if( this != &string_1 )
    {
        if( buffLen < string_1.strLength + 1 )
        {
            delete [ ] strData;
            strLentgh = string_1.strLength + 1;
            strData = new char[ buffLen ];
        }
        strLength = string_1.strLength;
        String_Copy( strData, string_1.strData );
    }
    return *this;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            End of Function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//---------------------------------------------------------*/
const string &string::operator+=( const string& String_1 )
//---------------------------------------------------------
{
    int saveLength = strLength;
    int newLength = String_Length(string_1) + strLength;

    {
        char *oldstrData = strData;
        strData = new char[ newLength ];
        String_Copy( strData, oldstrData );
        delete [ ] oldstrData;
    }

    String_Copy( (strData + saveLength), string_2.strData );
    strLength = newLength;
    return *this;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            End of Function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//---------------------------------------------------------*/
char & string::operator[ ]( int intNum_1 )
//---------------------------------------------------------
{
    if( intNum_1 < 0 || intNum_1 >= strLength )
        throw StringIndexOutOfBounds( );
    return strData[ intNum_1 ];
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            End of Function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//---------------------------------------------------------*/
char string::operator[ ]( int intNum_1 ) const
//---------------------------------------------------------
{
    if( intNum_1 < 0 || intNum_1 >= strLength )
        throw StringIndexOutOfBounds( );
    return strData[ intNum_1 ];
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            End of Function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


//---------------------------------------------------------*/
ostream & operator<<( ostream & out, const string & string_1 )
//---------------------------------------------------------
{
    return out << string_1.strData;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            End of Function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//---------------------------------------------------------*/
istream & operator>>( istream & in, string & string_1 )
//---------------------------------------------------------
{
    char buf[ string::strLength + 1 ];
    in >> buf;
    string_1 = buf;
    return in;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            End of Function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


//---------------------------------------------------------*/
istream & getline( istream & in, string & string_1 )
//---------------------------------------------------------
{
    char buf[ string::strLength + 1 ];
    in.getline( buf, string::MAX_LENGTH );
    str = buf;
    return in;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            End of Function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//---------------------------------------------------------*/
bool operator==( const string & string_1, const string & string_2 )
//---------------------------------------------------------
{
    return (String_Compare( string_1.strData, string_2.strData ) == 0) ;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            End of Function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


//---------------------------------------------------------*/
bool operator!=( const string & string_1, const string & string_2 )
//---------------------------------------------------------
{
    return (String_Compare( string_1.strData, string_2.strData ) != 0) ;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            End of Function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


//---------------------------------------------------------*/
bool operator<( const string & string_1, const string & string_2 )
//---------------------------------------------------------
{
    return (String_Compare( string_1.strData, string_2.strData ) < 0) ;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            End of Function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


//---------------------------------------------------------*/
bool operator<=( const string & string_1, const string & string_2 )
//---------------------------------------------------------
{
    return (String_Compare( string_1.strData, string_2.strData ) <= 0) ;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            End of Function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


//---------------------------------------------------------*/
bool operator>( const string & string_1, const string & string_2 )
//---------------------------------------------------------
{
    return (String_Compare( string_1.strData, string_2.strData ) > 0) ;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//            End of Function
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


//---------------------------------------------------------*/
bool operator>=( const string & string_1, const string & string_2 )
//---------------------------------------------------------
{
    return (String_Compare( string_1.strData, string_2.strData ) >= 0) ;
}

//
//==========================================================
//
// Friend Functions
//
//==========================================================
//


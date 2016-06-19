/*********************************************************************************

	Clarence Mitchell
	CIS 40 - MW 1:30 pm
	Programming Project 1
	February 13, 2002
    (Driver)
**********************************************************************************/

// ============================================================
//                 "C" String test main Implementation File
// ============================================================
//
//      This is the main driver used to test the following string functions:
//			
//		String_Compare
//		String_Copy
//
// ============================================================

#include <iostream.h>
#include <iomanip.h>
#include <stdio.h>



#include "proj1hdr.h"
//#include "Strfuns.cpp"

char cc;



void test_String_Compare (  );			// done
void test_String_Copy (  );				// done
void test_String_Length (  );			// done
void test_Compare_String_Length ( );	// done
void test_Compare_String_Alpha (  );
void test_Concatenate_String_SS (  );	// done
void test_Concatenate_String_SC (  );	// done
void test_Concatenate_String_CS (  );	// done
void test_Character_Position (  );		// done
void test_Numeric_Position (  );		// done
void test_Display_String ( );			// done
void test_Create_Empty_String (  );		// done

void pause_display();
void GetTestString(const char* strMessage, STR80 strReturn);

char menu ( );

int main ()
{

   char choice = menu();

   while ( ( choice != 'Q' ) && ( choice != 'q' ) )
   {
     switch (choice)
     {
       case 'a':
       case 'A': test_String_Compare (  ); break;
       case 'b':
       case 'B': test_String_Copy (  ); break;
       case 'c':
       case 'C': test_String_Length (  ); break;
       case 'd':
       case 'D': test_Compare_String_Length ( ); break;
       case 'e':
       case 'E': test_Compare_String_Alpha (  ); break;
       case 'f':
       case 'F': test_Concatenate_String_SS (  ); break;
       case 'g':
       case 'G': test_Concatenate_String_SC (  ); break;
       case 'h':
       case 'H': test_Concatenate_String_CS (  ); break;
       case 'i':
       case 'I': test_Character_Position (  ); break;
       case 'j':
       case 'J': test_Numeric_Position (  ); break;
       case 'k':
       case 'K': test_Display_String ( ); break;
       case 'l':
       case 'L': test_Create_Empty_String (  ); break;
       case 'q':
       case 'Q': break;
       default: break;
     }
     choice = menu();
   }
   return 0;
}

void test_String_Compare (  )
{
  STR80 strTest1, strTest2;
  cout << "Testing:" << endl;
  cout <<"bool String_Compare" << endl;

  GetTestString("....Enter a string 1:",strTest1);

  GetTestString("....Enter a string 2:",strTest2);

  cout <<"....String 1 before execution:"<<strTest1<<endl;
  cout <<"....String 2 before execution:"<<strTest2<<endl;
  cout <<endl;

  if (String_Compare(strTest1, strTest2))
     cout <<"....Strings are equal"<<endl;
  else
     cout <<"....Strings are NOT equal"<<endl;

  cout <<endl;
  cout <<"....String 1 after execution:"<<strTest1<<endl;
  cout <<"....String 2 after execution:"<<strTest2<<endl;

  pause_display();

}
void test_String_Copy (  )
{
  STR80 strTest1, strTest2;

  cout << "Testing:" << endl;
  cout << "void String_Copy"<<endl;
 
  GetTestString("....Enter a string 1:",strTest1);

  GetTestString("....Enter a string 2:",strTest2);

  cout <<"....String 1 before execution:"<<strTest1<<endl;
  cout <<"....String 2 before execution:"<<strTest2<<endl;
  cout <<endl;

  String_Copy (strTest1, strTest2);
  
  cout <<endl;
  cout <<"....String 1 after execution:"<<strTest1<<endl;
  cout <<"....String 2 after execution:"<<strTest2<<endl;

  pause_display();

}

void test_String_Length (  )
{
  STR80 strTest1;

  cout << "Testing:" << endl;
  cout <<"int String_Length"<<endl;

  GetTestString("....Enter a string 1:",strTest1);

  cout <<"....String 1 before execution:"<<strTest1<<endl;
  cout << endl;

  cout <<"....Length of string is :"
	   <<String_Length(strTest1)
	   <<endl;

  cout << endl;
  cout <<"....String 1 after execution:"<<strTest1<<endl;

  pause_display();

}

void test_Compare_String_Length ( )
{
  STR80 strTest1, strTest2;
  
  cout << "Testing:" << endl;
  cout <<"bool Compare_String_Length"<<endl;

  GetTestString("....Enter a string 1:",strTest1);
  GetTestString("....Enter a string 2:",strTest2);

  cout <<"....String 1 before execution:"<<strTest1<<endl;
  cout <<"....String 2 before execution:"<<strTest2<<endl;
  cout << endl;

  if (Compare_String_Length(strTest1, strTest2))
     cout <<"....Strings are equal in length"<<endl;
  else
     cout <<"....Strings are NOT equal in length"<<endl;

  cout << endl;
  cout <<"....String 1 after execution:"<<strTest1<<endl;
  cout <<"....String 2 after execution:"<<strTest2<<endl;


  pause_display();

}

void test_Compare_String_Alpha (  )
{
  STR80 strTest1, strTest2;

  cout << "Testing:" << endl;
  cout << "bool Compare_String_Alpha"<<endl;
 
  GetTestString("....Enter a string 1:",strTest1);
  GetTestString("....Enter a string 2:",strTest2);
 
  cout <<"....String 1 before execution:"<<strTest1<<endl;
  cout <<"....String 2 before execution:"<<strTest2<<endl;
  cout << endl;


  if (Compare_Alpha(strTest1, strTest2))
     cout <<"....String "<<strTest1<<" comes before "<<strTest2<<endl;
  else
     cout <<"....String "<<strTest1<<" DOES NOT comes before "<<strTest2<<endl;

  cout <<endl;
  cout <<"....String 1 after execution:"<<strTest1<<endl;
  cout <<"....String 2 after execution:"<<strTest2<<endl;

  pause_display();

}

void test_Concatenate_String_SS (  )
{
  STR80 strTest1, strTest2;


  cout << "Testing:" << endl;
  cout << "void Concatenate_String string string"<<endl;

  GetTestString("....Enter a string 1: ",strTest1);
  GetTestString("....Enter a string 2: ",strTest2);

  cout <<"....String 1 before execution:"<<strTest1<<endl;
  cout <<"....String 2 before execution:"<<strTest2<<endl;
  cout << endl;

  String_Concat(strTest1, strTest2);

  cout << endl;
  cout <<"....String 1 after execution:"<<strTest1<<endl;
  cout <<"....String 2 after execution:"<<strTest2<<endl;


  pause_display();

}

void test_Concatenate_String_SC (  )
{
  STR80 strTest1;
  char  chrTest1;

  cout << "Testing:" << endl;
  cout << "void Concatenate_String string char"<<endl;

  GetTestString("....Enter a string: ",strTest1);
  cout <<"....Enter a character: "<<flush;

  chrTest1=getchar();

  cout <<"....String 1 before execution:"<<strTest1<<endl;
  cout <<"....Character 1 before execution:"<<chrTest1<<endl;
  cout << endl;

  Char_Concat_Post(strTest1, chrTest1);

  cout << endl;
  cout <<"....String 1 after execution:"<<strTest1<<endl;
  cout <<"....Character 1 after execution:"<<chrTest1<<endl;

  pause_display();

}

void test_Concatenate_String_CS (  )
{
  STR80 strTest1;
  char  chrTest1;

  cout << "Testing:" << endl;
  cout << "void Concatenate_String char string"<<endl;

  cout <<"....Enter a character: " <<flush;
  chrTest1=getchar();
  GetTestString("....Enter a string: ",strTest1);

  cout <<"....Character 1 before execution:"<<chrTest1<<endl;
  cout <<"....String 1 before execution:"<<strTest1<<endl;
  cout << endl;

  Char_Concat_Pre(chrTest1, strTest1);

  cout << endl;
  cout <<"....Character 1 after execution:"<<chrTest1<<endl;
  cout <<"....String 1 after execution:"<<strTest1<<endl;

  pause_display();

}

void test_Character_Position (  )
{
  STR80 strTest1;
  char  chrTest1;
  int   intCharPos;

  cout << "Testing:" << endl;
  cout << "int Character_Position"<<endl;
  
  GetTestString("....Enter a string: ",strTest1);
  cout <<"....Enter a character: "<<flush;
  chrTest1=getchar();

  cout <<"....String 1 before execution:"<<strTest1<<endl;
  cout <<"....Character 1 before execution:"<<chrTest1<<endl;
  cout << endl;
  
  intCharPos = Character_Postion(strTest1,chrTest1);
  if (intCharPos == -1)
 	  cout << "Char "<<chrTest1<<" not found in string "<<strTest1;
  else
	  cout << "Char "<<chrTest1<<" found at "<<intCharPos<<" in string "<<strTest1;

  cout << endl<<endl;
  cout <<"....String 1 after execution:"<<strTest1<<endl;
  cout <<"....Character 1 after execution:"<<chrTest1<<endl;

  pause_display();

}

void test_Numeric_Position (  )
{
  STR80 strTest1;
  int intNumber1, rtnValue, intStringLen;
  
  cout << "Testing:" << endl;
  cout << "char Numeric_Position"<<endl;

  GetTestString("....Enter a string: ",strTest1);
  intStringLen = String_Length(strTest1);

  cout << "....Enter character position from 1 to "
	   << setw(2)
	   << intStringLen
	   << ":";

  cin  >>intNumber1;		   
  cin.ignore(100,'\n');  

  cout << "....String 1 before execution:"<<strTest1<<endl;
  cout << "....Number 1 before execution:"<<intNumber1<<endl;
  cout << endl;
  
  if ((rtnValue=Numeric_Postion(strTest1, intNumber1))!=-1)
	  cout << "....Character at positon "
	       << setw(2)
		   << intNumber1
		   << " is :"
		   << (char) rtnValue
		   << endl;
  else
	  cout << "....Error!!! Value exceeds maximum of "
		   << setw(2)
		   << intStringLen
		   << endl;

  cout << endl;
  cout << "....String 1 after execution:"<<strTest1<<endl;
  cout << "....Number 1 after execution:"<<intNumber1<<endl;

  pause_display();

}

void test_Display_String ( )
{
   STR80 strTest1;

	cout << "Testing:" << endl;
	cout << "void Display_String"<<endl;

    GetTestString("....Enter a string: ",strTest1);

	cout << endl;
	cout << "You entered ";
	Display_String(strTest1);
	cout  << endl;
 
    pause_display();

}

//=========================================================================
//
// Test Drvier Support Funtions
//
//=========================================================================
void test_Create_Empty_String (  )
{
  STR80 strTest1;
  cout << "Testing:" << endl;
  cout << "void Create_Empty_String"<<endl;

  GetTestString("....Enter a string: ",strTest1);
  cout << "You entered " << strTest1 << endl;
 
  pause_display();
  
  Empty_String(strTest1);

  cout << "After call to Create_Empty_String( c ) the string is "
       << strTest1 << endl;
		
  pause_display();

}
void GetTestString(const char* strMessage, STR80 strReturn)
{
  cout <<strMessage;
  cin.getline(strReturn,MAXSTRING,'\n');
  cout <<endl;

}


void pause_display()
{
  char cc[255];
  int numflushed;

 // cout <<"Press <ENTER> key to continue..."<<flush;
  cout <<flush<<"Press <ENTER> key to continue..."<<flush;
  cin.getline(cc,255,'\n');

  numflushed = _flushall();
  cout <<endl <<endl;
}

char menu ( )
{
  cout << endl;
  cout << "  ---- String Functions Test Driver ------ " << endl;
  cout << "================================================" << endl;
  cout << "A: " << "bool String_Compare" << endl; 
  cout << "B: " << "void String_Copy" << endl; 
  cout << "C: " << "int String_Length" << endl;
  cout << "D: " << "bool Compare_String_Length" << endl;
  cout << "E: " << "bool Compare_String_Alpha" << endl;
  cout << "F: " << "void Concatenate_String string string" << endl;
  cout << "G: " << "void Concatenate_String string char" << endl;
  cout << "H: " << "void Concatenate_String char string" << endl;
  cout << "I: " << "int Character_Position" << endl;
  cout << "J: " << "char Numeric_Position" << endl;
  cout << "K: " << "void Display_String" << endl;
  cout << "L: " << "void Create_Empty_String" << endl;
  cout << "Q: " << "---Quit Program "<< endl;
  cout << "================================================" << endl;
  cout << "Enter selection:";
  char ret;

  cin.get(ret);
  cin.ignore(100,'\n');  
 
  return ret;
}




// ============================================================
//                 General Vector Header File
// ============================================================
//
//      Copyright (C) 2002
//      Assistant Professor David E. Fox
//      Computer and Information Science
//      American River College
//      4700 College Oak Drive
//      Sacramento, CA  95841
//
//      Permission is granted to use at your own risk and
//      distribute this software in source and binary forms
//      provided the above copyright notice and this paragraph
//      are preserved on all copies.  This software is provided
//      "as is" with no express or implied warranty.
//
// ============================================================


/**********************************************************
  We will define a vector to be an array of doubles.
  This array will contain a maximum of MAXVECTOR doubles.
  We will reserve the zero location in the array and store
  the size of the vector in that position.  For example,
  suppose we have a vector that contains the following data:

  < 7.0, 8.5, 9.3 >

  We would store the following in our array:

  { 3, 7.0, 8.5, 9.3, garbage after this }

  The letters FA mean "For all"

***********************************************************/

#include <iostream.h>

/**********************************************************
Predicate functions used in PRE and POST conditions
  bool IsAllocated ( double* v): returns true if v points to allocated
                                 memory. false otherwise

  bool IsAllocatedMAXVECTOR(double* v): returns true if v points to
                                        MAXVECTOR+1 allocated spaces.
                                        false otherwise.

  bool IsConstructed( double* v): returns true if v != NULL &&
                                  IsAllocatedMAXVECTOR(v). false otherwise

  bool MemoryDeallocated(V): returns true if the memory pointed to by V has
                             been deallocated

  bool assigned( double d ): returns true if d has been assigned a value.
                             false otherwise.
***********************************************************/


const int MAXVECTOR = 31;	// plus one additional space for the vector size

//Pre: !IsAllocated(v)
//Post: ( (IsConstructed(v) => ( v != NULL && IsAllocatedMAXVECTOR(v) )) &&
//       v[0] == 0 ) ||
//			exit(1)
void Construct_Vector ( double*& v );

//Pre: IsConstructed(v) && V == v
//Post: MemoryDeallocated(V) && v == NULL
void Destruct_Vector ( double*& v );


//Pre: IsConstructed(v0) && IsConstructed(v1)
//Post: FCTVAL == ((v0[0] == v1[0]) && FA(i = 1...v0[0]):(v0[i] == v1[i]))
bool Compare_Vector ( const double* v0, const double* v1 );

//Pre: IsConstructed(dest) && IsConstructed(src)
//Post: Compare_Vector( dest, src )
void Copy_Vector ( double* dest, const double* src );

//Pre: IsConstructed(v)
//Post: FCTVAL == v[0]
int Length_Vector ( const double* v );

//Pre: IsConstructed(v0) && IsConstructed(v1) && Compare_Vector( V0, v0 )
//Post: FA(i = 1...V0[0]):(v0[i] == V0[i]) &&
//		 ( ((v1[0]+V0[0]) <= MAXVECTOR) &&
//			FA(i = 1...v1[0]):(v0[i+V[0]] == v1[i]) &&
//	      v0[0] == V0[0] + v1[0] ) ||
//		   ((v1[0]+V0[0]) > MAXVECTOR) &&
//       FA(i = 1...MAXVECTOR-V0[0]):(v0[i+V[0]] == v1[i]) &&
//       v0[0] == MAXVECTOR) )
void Add_Vector ( double* v0, const double* v1 );

//Pre: IsConstructed(v) && assigned(d) && Compare_Vector( V, v )
//Post: FA(i = 1...V[0]):(v[i] == V[i]) &&
//     ( ( !IsFull_Vector(v) && v[1+V[0]] == d) &&
//	     v[0] == V[0] + 1 ) ||
//		   Compare_Vector( V, v ) )
void Add_Vector ( double* v, const double d );

//PRE: IsConstructed(v)
//Post: v[0] == 0
void Empty_Vector ( double* v );

//Pre: IsConstructed(v)
//Post: FCTVAL == ( v[0] == MAXVECTOR )
bool IsFull_Vector ( const double* v );

//Pre: IsConstructed(v)
//Post: FCTVAL == ( v[0] == 0 )
bool IsEmpty_Vector ( const double* v );

//Pre: IsConstructed(v)
//Post: ( !IsEmpty_Vector(v) && cout << "< " &&
//        FA(i = 1...v[0]-1): cout << v[i]<<", " &&
//        cout << v[v[0] << " >" ) ||
//			cout << "< NULL >"
void Display_Vector ( const double* v );


void pause( void );


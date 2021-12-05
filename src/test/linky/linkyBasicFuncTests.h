/*
 * Author -- Meevs
 * Creation Date -- Wed Dec  1 22:33:06 2021
 * File Name -- linkyBasicFuncTests.h
 * Notes -- 
 */

#ifndef __LINKY_BASIC_FUNCTIONALITY_TESTS__
#define __LINKY_BASIC_FUNCTIONALITY_TESTS__

#include <stdio.h>
#include <linky.h>

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:25:47 2021
 * Function Name -- linkyListCreation 
 * Function Purpose -- Tests the basic creation of a Linky list, asserting that the data it is to be created with is indeed stored correctly and the size of the list is properly initialized.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (linkyListCreation)
{
  linky *list = NULL;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Linky List Creation                                                          * */\r\n"
	  "/* ******************************************************************************** */\r\n\r\n");

  printf ("Creating Linky list with element: 10\r\n");
  
  linkyAddNode (list, 10);

  printf ("Checking data stored in Linky node:\r\n");
  printf ("\tExpected data: 10, Actual data: %d\r\n", *(int *)list->data);
  printf ("\tExpected size: 1, Actual size: %d\r\n", list->size);
  
  ck_assert (*(int *)list->data == 10);
  ck_assert (list->size == 1);

  linkyDestroyList (list);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:26:28 2021
 * Function Name -- linkyGetDataTest 
 * Function Purpose -- Tests the functionality of the 'linkyGetData' macro, asserting that the macro properly extracts the data from the Linky list.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (linkyGetDataTest)
{
  linky *list = NULL;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Linky Get Data Test                                                          * */\r\n"
	  "/* ******************************************************************************** */\r\n\r\n");

  printf ("Creating Linky list with element: 5\r\n"); 
  linkyAddNode (list, 5);
  
  printf ("Expected data: 5, Actual data: %d\r\n", linkyGetData (list, int));
  ck_assert (linkyGetData (list, int) == 5);
  
  linkyDestroyList (list);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:27:03 2021
 * Function Name -- basicCharList 
 * Function Purpose -- Tests the compatability of Linky lists with the char data type, asserting that chars within the Linky list are properly stored as they would be expected to be.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (basicCharList)
{
  linky *charList = NULL;
  linky *tempPtr = NULL;
  const char elements [] = {'a', 'b', 'c', '\0'};
  int index = 0;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Basic Char List                                                              * */\r\n"
	  "/* ******************************************************************************** */\r\n\r\n");

  printf ("Init Linky char list:\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("\tAdding char: %c\r\n", elements [index]);
      linkyAddNode (charList, elements [index]);
    }
  
  printf ("Char List traversal:\r\n");

  for (tempPtr = charList, index = 0; tempPtr; tempPtr = tempPtr->next, index++)
    {
      printf ("\tExpected value: %c, Actual value: %c\r\n", elements [index], linkyGetData (tempPtr, char));
      ck_assert (linkyGetData (tempPtr, char) == elements [index]);
    }

  linkyDestroyList (charList);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:27:03 2021
 * Function Name -- basicShortList 
 * Function Purpose -- Tests the compatability of Linky lists with the short data type, asserting that shorts within the Linky list are properly stored as they would be expected to be.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (basicShortList)
{
  linky *shortList = NULL;
  linky *tempPtr = NULL;
  const short elements [] = {5, 10, 15, 0};
  int index = 0;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Basic Short List                                                             * */\r\n"
	  "/* ******************************************************************************** */\r\n\r\n");

  printf ("Init Linky short list:\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("\tAdding short: %hd\r\n", elements [index]);
      linkyAddNode (shortList, elements [index]);
    }
  
  printf ("Short List traversal:\r\n");

  for (tempPtr = shortList, index = 0; tempPtr; tempPtr = tempPtr->next, index++)
    {
      printf ("\tExpected value: %hd, Actual value: %hd\r\n", elements [index], linkyGetData (tempPtr, short));
      ck_assert (linkyGetData (tempPtr, short) == elements [index]);
    }

  linkyDestroyList (shortList);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:27:03 2021
 * Function Name -- basicIntList 
 * Function Purpose -- Tests the compatability of Linky lists with the int data type, asserting that ints within the Linky list are properly stored as they would be expected to be.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (basicIntList)
{
  linky *intList = NULL;
  linky *tempPtr = NULL;
  const int elements [] = {5, 10, 15, 0};
  int index = 0;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Basic Int List                                                               * */\r\n"
	  "/* ******************************************************************************** */\r\n\r\n");

  printf ("Init Linky int list:\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("\tAdding int: %d\r\n", elements [index]);
      linkyAddNode (intList, elements [index]);
    }
  
  printf ("Int List traversal:\r\n");

  for (tempPtr = intList, index = 0; tempPtr; tempPtr = tempPtr->next, index++)
    {
      printf ("\tExpected value: %d, Actual value: %d\r\n", elements [index], linkyGetData (tempPtr, int));
      ck_assert (linkyGetData (tempPtr, int) == elements [index]);
    }

  linkyDestroyList (intList);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:27:03 2021
 * Function Name -- basicLongList 
 * Function Purpose -- Tests the compatability of Linky lists with the long data type, asserting that longs within the Linky list are properly stored as they would be expected to be.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (basicLongList)
{
  linky *longList = NULL;
  linky *tempPtr = NULL;
  const long elements [] = {5, 10, 15, 0};
  long index = 0;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Basic Long List                                                              * */\r\n"
	  "/* ******************************************************************************** */\r\n\r\n");

  printf ("Init Linky long list:\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("\tAdding long: %ld\r\n", elements [index]);
      linkyAddNode (longList, elements [index]);
    }
  
  printf ("Long List traversal:\r\n");

  for (tempPtr = longList, index = 0; tempPtr; tempPtr = tempPtr->next, index++)
    {
      printf ("\tExpected value: %ld, Actual value: %ld\r\n", elements [index], linkyGetData (tempPtr, long));
      ck_assert (linkyGetData (tempPtr, long) == elements [index]);
    }

  linkyDestroyList (longList);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:27:03 2021
 * Function Name -- basicPtrList 
 * Function Purpose -- Tests the compatability of Linky lists with the ptr data type, asserting that ptrs within the Linky list are properly stored as they would be expected to be.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (basicPtrList)
{
  linky *longList = NULL;
  linky *tempPtr = NULL;
  const char *elements [] = {"Hello", " ", "World", NULL};
  long index = 0;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	   "/* * Basic Ptr List                                                               * */\r\n"
	   "/* ******************************************************************************** */\r\n\r\n");

  printf ("Init Linky string list:\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("\tAdding : \"%s\"\r\n", elements [index]);
      linkyAddNode (longList, elements [index]);
    }
  
  printf ("String List traversal:\r\n");

  for (tempPtr = longList, index = 0; tempPtr; tempPtr = tempPtr->next, index++)
    {
      printf ("\tExpected value: \"%s\", Actual value: \"%s\"\r\n", elements [index], linkyGetData (tempPtr, char *));
      ck_assert (strncmp (linkyGetData (tempPtr, char*), elements [index], 5) == 0);
    }

  linkyDestroyList (longList);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:29:28 2021
 * Function Name -- removeElementTest 
 * Function Purpose -- Tests the capability of removing elements from the given Linky list, asserting that the remaining elements of the list are properly strung together after the desired element has been removed.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 *     -- 2021-12-05 -- This test is currently a stub as there is no function to remove elements from a Linky list yet!
 */
START_TEST (removeElementTest)
{
  linky *list = NULL;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Remove Element Test                                                          * */\r\n"
	  "/* ******************************************************************************** */\r\n\r\n");

  printf ("This test is currently a STUB!\r\n");
  
  /* <<TODO>> -- This test is currently a stub! */
  
  linkyDestroyList (list);
}
END_TEST

#endif

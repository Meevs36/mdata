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

  linkyAddNode (list, 10);
  
  ck_assert_int_eq (*(int *)list->data, 10);
  ck_assert_int_eq (list->size, 1);

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

  linkyAddNode (list, 5);
  
  ck_assert_int_eq (linkyGetData (list, int), 5);
  
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

  for (index = 0; elements [index]; index++)
    linkyAddNode (charList, elements [index]);

  for (tempPtr = charList, index = 0; tempPtr; tempPtr = tempPtr->next, index++)
    ck_assert_msg (linkyGetData (tempPtr, char) == elements [index], "Expected char: '%c', instead got char: '%c'\r\n", elements [index], linkyGetData (tempPtr, char));

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

  for (index = 0; elements [index]; index++)
    linkyAddNode (shortList, elements [index]);

  for (tempPtr = shortList, index = 0; tempPtr; tempPtr = tempPtr->next, index++)
    ck_assert_int_eq (linkyGetData (tempPtr, short), elements [index]);

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

  for (index = 0; elements [index]; index++)
    linkyAddNode (intList, elements [index]);

  for (tempPtr = intList, index = 0; tempPtr; tempPtr = tempPtr->next, index++)
    ck_assert_int_eq (linkyGetData (tempPtr, int), elements [index]);

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

  for (index = 0; elements [index]; index++)
    linkyAddNode (longList, elements [index]);

  for (tempPtr = longList, index = 0; tempPtr; tempPtr = tempPtr->next, index++)
    ck_assert_int_eq (linkyGetData (tempPtr, long), elements [index]);

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
  linky *strList = NULL;
  linky *tempPtr = NULL;
  const char *elements [] = {"Hello", " ", "World", NULL};
  long index = 0;
  for (index = 0; elements [index]; index++)
      linkyAddNode (strList, elements [index]);
  
  for (tempPtr = strList, index = 0; tempPtr; tempPtr = tempPtr->next, index++)
    ck_assert_str_eq (linkyGetData (tempPtr, char *), elements [index]);

  linkyDestroyList (strList);
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

  printf ("This test is currently a STUB!\r\n");
  
  /* <<TODO>> -- This test is currently a stub! */
  
  linkyDestroyList (list);
}
END_TEST

#endif

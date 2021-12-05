/*
 * Author -- Meevs
 * Creation Date -- Wed Dec  1 22:33:06 2021
 * File Name -- linkyBasicFuncTests.h
 * Notes -- 
 */

#ifndef __LINKY_BASIC_FUNCTIONALITY_TESTS__
#define __LINKY_BASIC_FUNCTIONALITY_TESTS__

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

  linkyAddNode (list, 5);

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

  /* Init basic char list */
  linkyAddNode (charList, 'a');  
  linkyAddNode (charList, 'b');    
  linkyAddNode (charList, 'c');

  /* Check for the all of the right values */
  ck_assert (linkyGetData (charList, char) == 'a');
  ck_assert (linkyGetData (charList->next, char) == 'b');
  ck_assert (linkyGetData (charList->next->next, char) == 'c');

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

  linkyAddNode (shortList, (short)5);
  linkyAddNode (shortList, (short)15);
  linkyAddNode (shortList, (short)10);

  ck_assert (linkyGetData (shortList, short) == (short)5);
  ck_assert (linkyGetData (shortList->next, short) == (short)15);
  ck_assert (linkyGetData (shortList->next->next, short) == (short)10);
  
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

  linkyAddNode (intList, 5);
  linkyAddNode (intList, 15);
  linkyAddNode (intList, 10);

  ck_assert (linkyGetData (intList, int) == 5);
  ck_assert (linkyGetData (intList->next, int) == 15);
  ck_assert (linkyGetData (intList->next->next, int) == 10);
  
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

  linkyAddNode (longList, (long)5);
  linkyAddNode (longList, (long)15);
  linkyAddNode (longList, (long)10);

  ck_assert (linkyGetData (longList, long) == 5);
  ck_assert (linkyGetData (longList->next, long) == 15);
  ck_assert (linkyGetData (longList->next->next, long) == 10);
  
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
  char *str1 = "Hello";
  char *str2 = " ";
  char *str3 = "World!";

  linky *strList = NULL;

  linkyAddNode (strList, str1);
  linkyAddNode (strList, str2);
  linkyAddNode (strList, str3);

  ck_assert_str_eq (linkyGetData (strList, char *), str1);
  ck_assert_str_eq (linkyGetData (strList->next, char *), str2);
  ck_assert_str_eq (linkyGetData (strList->next, char *), str2);
  
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

  /* <<TODO>> -- This test is currently a stub! */
  
  linkyDestroyList (list);
}
END_TEST

#endif

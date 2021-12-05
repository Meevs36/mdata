/*
 * Author -- Meevs
 * Creation Date -- Wed Dec  1 22:33:06 2021
 * File Name -- linkyBasicFuncTests.h
 * Notes -- 
 */

#ifndef __LINKY_BASIC_FUNCTIONALITY_TESTS__
#define __LINKY_BASIC_FUNCTIONALITY_TESTS__

START_TEST (linkyListCreation)
{
  linky *list = NULL;

  linkyAddNode (list, 10);

  ck_assert (*(int *)list->data == 10);
  ck_assert (list->size == 1);

  linkyDestroyList (list);
}
END_TEST

START_TEST (linkyGetDataTest)
{
  linky *list = NULL;

  linkyAddNode (list, 5);

  ck_assert (linkyGetData (list, int) == 5);
  
  linkyDestroyList (list);
}
END_TEST

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

START_TEST (removeElementTest)
{
  linky *list = NULL;

  /* <<TODO>> -- This test is currently a stub! */
  
  linkyDestroyList (list);
}
END_TEST

#endif

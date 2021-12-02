/*
 * Author -- Meevs
 * Creation Date -- Thu Dec  2 02:03:37 2021
 * File Name -- stackyTestSuite.c
 * Notes -- 
 */

#include <stdio.h>
#include "stackyTestSuite.h"

int main (int argC, char **argV)
{
  SRunner *suiteRunner = NULL;
  Suite *stackySuite = NULL;

  int numberFailed = 0;

  stackySuite = genStackyTestSuite ();
  suiteRunner = srunner_create (stackySuite);

  srunner_run_all (suiteRunner, CK_NORMAL);
  numberFailed = srunner_ntests_failed (suiteRunner);

  srunner_free (suiteRunner);  

  return (numberFailed == 0)? 0 : 1;
}

Suite *genStackyTestSuite ()
{
  Suite *suite = NULL;
  TCase *basicTestCase = NULL;

  suite = suite_create ("stacky");

  basicTestCase = genBasicTestCase ();
  suite_add_tcase (suite, basicTestCase);
  
  return suite;
}

TCase *genBasicTestCase ()
{
  TCase *basicTestCase = NULL;

  basicTestCase = tcase_create ("basicFunc");
  tcase_add_test (basicTestCase, simpleStack);
  tcase_add_test (basicTestCase, isEmptyTestEmptyStack);
  tcase_add_test (basicTestCase, isEmptyTestSingleElement);
  tcase_add_test (basicTestCase, isEmptyTestMultipleElements);
  tcase_add_test (basicTestCase, popTest);
  
  return basicTestCase;
}

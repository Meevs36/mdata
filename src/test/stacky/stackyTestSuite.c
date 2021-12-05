/*
 * Author -- Meevs
 * Creation Date -- Thu Dec  2 02:03:37 2021
 * File Name -- stackyTestSuite.c
 * Notes -- 
 */

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

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 01:39:06 2021
 * Function Name -- genStackyTestSuite 
 * Function Purpose -- Generates the Stacky test suite, populating it with all test cases to be run
 * Function Parameters -- 
 * Function Returns -- The generated test suite
 * Notes --
 */
Suite *genStackyTestSuite ()
{
  Suite *suite = NULL;
  TCase *basicTestCase = NULL;

  suite = suite_create ("stacky");

  basicTestCase = genBasicTestCase ();
  suite_add_tcase (suite, basicTestCase);
  
  return suite;
}

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 01:40:18 2021
 * Function Name -- genBasicTestCase 
 * Function Purpose -- Generates a test case for testing basic functionality of the stack. These tests include basic push/pop operations along with testing whether or not the 'isEmpty' function works as expected
 * Function Parameters -- 
 * Function Returns -- A basic test case for use with the stacky test suite
 * Notes --
 */
TCase *genBasicTestCase ()
{
  TCase *basicTestCase = NULL;

  basicTestCase = tcase_create ("basicFunc");
  tcase_add_test (basicTestCase, stackyInitTest);
  tcase_add_test (basicTestCase, stackyCharTest);
  tcase_add_test (basicTestCase, stackyShortTest);
  tcase_add_test (basicTestCase, stackyIntTest);
  tcase_add_test (basicTestCase, stackyLongTest);
  tcase_add_test (basicTestCase, stackyPtrTest);
  tcase_add_test (basicTestCase, simpleStack);
  tcase_add_test (basicTestCase, isEmptyTestEmptyStack);
  tcase_add_test (basicTestCase, isEmptyTestSingleElement);
  tcase_add_test (basicTestCase, isEmptyTestMultipleElements);
  tcase_add_test (basicTestCase, popTest);
  
  return basicTestCase;
}

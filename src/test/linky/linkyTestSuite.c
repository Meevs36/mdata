/*
 * Author -- Meevs
 * Creation Date -- Wed Dec  1 22:12:50 2021
 * File Name -- linkyTestSuite.c
 * Notes -- 
 */

#include "linkyTestSuite.h"

int main (int argC, char **argV)
{
  SRunner *suiteRunner = NULL;
  Suite *linkySuite = NULL;

  int numberFailed = 0;

  linkySuite = genLinkyTestSuite ();
  suiteRunner = srunner_create (linkySuite);

  srunner_run_all (suiteRunner, CK_NORMAL);
  numberFailed = srunner_ntests_failed (suiteRunner);

  srunner_free (suiteRunner);
  
  return (numberFailed == 0)? 0 : 1;
}

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:14:50 2021
 * Function Name -- genLinkyTestSuite 
 * Function Purpose -- Generates the Linky test suite containing all test cases to test the functionality of the Linky module
 * Function Parameters -- 
 * Function Returns -- The test suite that will be run
 * Notes --
 */
Suite *genLinkyTestSuite ()
{
  Suite *suite = NULL;
  TCase *basicTestCase = NULL;
  TCase *dllTestCase = NULL;

  suite = suite_create ("linky");

  basicTestCase = genBasicTestCase ();
  dllTestCase = genDLLTestCase ();

  suite_add_tcase (suite, basicTestCase);
  suite_add_tcase (suite, dllTestCase);
  
  return suite;
}

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:15:36 2021
 * Function Name -- genBasicTestCase 
 * Function Purpose -- Generates a test case testing the basic functionality of the Linky module
 * Function Parameters -- 
 * Function Returns -- A test case containing basic tests for the Linky module
 * Notes --
 */
TCase *genBasicTestCase ()
{
  TCase *basicTestCase = NULL;

  basicTestCase = tcase_create ("basicFunc");
  tcase_add_test (basicTestCase, linkyListCreation);
  tcase_add_test (basicTestCase, linkyGetDataTest);
  tcase_add_test (basicTestCase, basicCharList);
  tcase_add_test (basicTestCase, basicShortList);
  tcase_add_test (basicTestCase, basicIntList);
  tcase_add_test (basicTestCase, basicLongList);
  tcase_add_test (basicTestCase, basicPtrList);
  tcase_add_test (basicTestCase, removeElementTest);
  
  return basicTestCase;
}

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:16:29 2021
 * Function Name -- genDLLTestCase
 * Function Purpose -- Generates a test case for testing the functionality of double linked lists in the Linky module
 * Function Parameters -- 
 * Function Returns -- A test case containing tests for double linked lists for the Linky module
 * Notes --
 */
TCase *genDLLTestCase ()
{
  TCase *dllTestCase = NULL;

  dllTestCase = tcase_create ("dll");
  tcase_add_test (dllTestCase, dllTraversalTest);

  return dllTestCase;
}

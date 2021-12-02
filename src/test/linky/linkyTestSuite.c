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
  
  return (numberFailed == 0)? EXIT_SUCCESS : EXIT_FAILURE;
}

Suite *genLinkyTestSuite ()
{
  Suite *suite = NULL;
  TCase *basicTestCase = NULL;

  suite = suite_create ("linky");

  basicTestCase = genBasicTestCase ();

  suite_add_tcase (suite, basicTestCase);  
  
  return suite;
}

TCase *genBasicTestCase ()
{
  TCase *basicTestCase = NULL;

  basicTestCase = tcase_create ("basicFunc");
  tcase_add_test (basicTestCase, basicCharList);
  tcase_add_test (basicTestCase, basicShortList);
  tcase_add_test (basicTestCase, basicIntList);
  tcase_add_test (basicTestCase, basicLongList);  
  
  return basicTestCase;
}


/*
 * Author -- Meevs
 * Creation Date -- Wed Dec  1 22:10:20 2021
 * File Name -- mdataTestSuite.c
 * Notes -- 
 */

#include "mdataTestSuite.h"

int main (int argC, char **argV)
{
  SRunner *suiteRunner = NULL;
  Suite *linkySuite = NULL;
  Suite *stackySuite = NULL;
  Suite *queueSuite = NULL;
  Suite *btSuite = NULL;
  int numberFailed = 0;

  linkySuite = genLinkyTestSuite ();
  stackySuite = genStackyTestSuite ();
  queueSuite = genQueueTestSuite ();
  btSuite = genBinaryTreeTestSuite ();

  /* Add test suites */
  suiteRunner = srunner_create (linkySuite);
  srunner_add_suite (suiteRunner, stackySuite);
  srunner_add_suite (suiteRunner, queueSuite);
  srunner_add_suite (suiteRunner, btSuite);

  srunner_run_all (suiteRunner, CK_NORMAL);
  numberFailed = srunner_ntests_failed (suiteRunner);

  srunner_free (suiteRunner);
  
  return (numberFailed == 0)? EXIT_SUCCESS : EXIT_FAILURE;
}

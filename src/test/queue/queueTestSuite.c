/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 01:31:42 2021
 * File Name -- queueTestSuite.c
 * Notes -- 
 */

#include "queueTestSuite.h"

int main (int argC, char **argV)
{
  SRunner *suiteRunner = NULL;
  Suite *queueSuite = NULL;

  int numberFailed = 0;

  queueSuite = genQueueTestSuite ();
  suiteRunner = srunner_create (queueSuite);

  srunner_run_all (suiteRunner, CK_NORMAL);
  numberFailed = srunner_ntests_failed (suiteRunner);

  srunner_free (suiteRunner);
  
  return (numberFailed == 0)? 0 : 1;
}

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 01:40:56 2021
 * Function Name -- genQueueTestSuite 
 * Function Purpose -- Generates the queue test suite with all test cases to test it's functionality
 * Function Parameters -- 
 * Function Returns -- The queue test suite
 * Notes --
 */
Suite *genQueueTestSuite ()
{
  Suite *suite = NULL;
  TCase *basicTestCase = NULL;

  suite = suite_create ("queue");

  basicTestCase = genBasicTestCase ();
  suite_add_tcase (suite, basicTestCase);
  
  return suite;
}

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 01:41:32 2021
 * Function Name -- genBasicTestCase 
 * Function Purpose -- Generates a test case to test the basic functionality of the queue
 * Function Parameters -- 
 * Function Returns -- A test case loaded with all tests to test basic functionality
 * Notes --
 */
TCase *genBasicTestCase ()
{
  TCase *basicTestCase = NULL;

  basicTestCase = tcase_create ("basicFunc");
  tcase_add_test (basicTestCase, initQueueTest0);
  tcase_add_test (basicTestCase, queueGetSizeTest0);
  tcase_add_test (basicTestCase, queueGetSizeTest1);
  tcase_add_test (basicTestCase, queueFrontTest0);
  tcase_add_test (basicTestCase, queueFrontTest1);
  tcase_add_test (basicTestCase, queueRearTest0);
  tcase_add_test (basicTestCase, queueRearTest1);
  tcase_add_test (basicTestCase, queueDequeueTest);
  tcase_add_test (basicTestCase, queueCharTest);
  tcase_add_test (basicTestCase, queueShortTest);
  tcase_add_test (basicTestCase, queueIntTest);
  tcase_add_test (basicTestCase, queueLongTest);
  tcase_add_test (basicTestCase, queuePtrTest);
  
  return basicTestCase;
}

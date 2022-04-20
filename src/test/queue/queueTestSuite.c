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

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

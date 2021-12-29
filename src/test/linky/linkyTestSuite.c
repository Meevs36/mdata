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


/*
 * Author -- Meevs
 * Creation Date -- Wed Dec  1 22:10:20 2021
 * File Name -- mdataTestSuite.c
 * Notes -- 
 */

#include <stdio.h>
#include <check.h>

#include "linky/linkyTestSuite.h"

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

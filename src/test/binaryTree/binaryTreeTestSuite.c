/*
 * Author -- Meevs
 * Creation Date -- Fri Dec 24 09:52:02 2021
 * File Name -- binaryTreeTestSuite.c
 * Notes -- 
 */

#include "binaryTreeTestSuite.h"

int main (int argC, char **argV)
{
  SRunner *suiteRunner = NULL;
  Suite *binaryTreeSuite = NULL;

  int numberFailed = 0;

  binaryTreeSuite = genBinaryTreeTestSuite ();
  suiteRunner = srunner_create (binaryTreeSuite);

  srunner_run_all (suiteRunner, CK_NORMAL);
  numberFailed = srunner_ntests_failed (suiteRunner);

  srunner_free (suiteRunner);
  
  return (numberFailed == 0)? 0 : 1;
}


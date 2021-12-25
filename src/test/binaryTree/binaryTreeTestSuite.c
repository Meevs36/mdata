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

/*
 * Author -- Meevs
 * Creation Date -- Fri Dec 24 10:09:12 2021
 * Function Name -- genBinaryTreeTestSuite 
 * Function Purpose -- Generates the test suite for the Binary Tree data structure
 * Function Parameters -- 
 * Function Returns -- A pointer to the created test suite.
 * Notes --
 */
Suite *genBinaryTreeTestSuite ()
{
  Suite *btTestSuite = NULL;
  TCase *btBasicTestCase = NULL;

  btTestSuite = suite_create ("bt");

  btBasicTestCase = genBasicTestCase ();

  suite_add_tcase (btTestSuite, btBasicTestCase);  
  
  return btTestSuite;
}

/*
 * Author -- Meevs
 * Creation Date -- Fri Dec 24 10:10:21 2021
 * Function Name -- genBasicTestCase 
 * Function Purpose -- Generates and populates the basic test cases for the Binary Tree data structure.
 * Function Parameters -- 
 * Function Returns -- A pointer to the generated test case, containing basic unit tests for the Binary Tree data structure.
 * Notes -- 
 */
TCase *genBasicTestCase ()
{
  TCase *btBasicTestCase = NULL;

  btBasicTestCase = tcase_create ("basicFunc");
  tcase_add_test (btBasicTestCase, btDefaultCmpFuncTestChar);
  tcase_add_test (btBasicTestCase, btDefaultCmpFuncTestShort);
  tcase_add_test (btBasicTestCase, btDefaultCmpFuncTestInt);
  tcase_add_test (btBasicTestCase, btDefaultCmpFuncTestLong);
  tcase_add_test (btBasicTestCase, btDefaultCmpNULLTreeTest0);
  tcase_add_test (btBasicTestCase, btDefaultCmpNULLTreeTest1);
  tcase_add_test (btBasicTestCase, btInsertNodeTest0);
  tcase_add_test (btBasicTestCase, btInsertNodeTest1);
  tcase_add_test (btBasicTestCase, btInitTest);
  tcase_add_test (btBasicTestCase, btGetSizeTest0);
  tcase_add_test (btBasicTestCase, btGetSizeTest1);
  tcase_add_test (btBasicTestCase, btCharTest);
  tcase_add_test (btBasicTestCase, btShortTest);
  tcase_add_test (btBasicTestCase, btIntTest);
  tcase_add_test (btBasicTestCase, btLongTest);
  

  return btBasicTestCase;
}

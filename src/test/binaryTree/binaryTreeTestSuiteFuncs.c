/*
 * Author -- Meevs
 * Creation Date -- Wed Dec 29 01:14:50 2021
 * File Name -- binaryTreeTestSuiteFuncs.c
 * Notes -- 
 */

#include "binaryTreeTestSuite.h"

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

  btBasicTestCase = genBTBasicTestCase ();

  suite_add_tcase (btTestSuite, btBasicTestCase);  
  
  return btTestSuite;
}

/*
 * Author -- Meevs
 * Creation Date -- Fri Dec 24 10:10:21 2021
 * Function Name -- genBTBasicTestCase 
 * Function Purpose -- Generates and populates the basic test cases for the Binary Tree data structure.
 * Function Parameters -- 
 * Function Returns -- A pointer to the generated test case, containing basic unit tests for the Binary Tree data structure.
 * Notes -- 
 */
TCase *genBTBasicTestCase ()
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

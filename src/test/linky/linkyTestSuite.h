/*
 * Author -- Meevs
 * Creation Date -- Wed Dec  1 22:29:44 2021
 * File Name -- linkyTestSuite.h
 * Notes -- 
 */

#ifndef __LINKY_TEST_SUITE__
#define __LINKY_TEST_SUITE__

#include <stdlib.h>
#include <check.h>
#include <linky.h>

#include "linkyBasicFuncTests.h" /* Defines basic functionality tests */
#include "linkyDoubleLinkedListTest.h" /* Defines functionality tests for double linked lists */

Suite *genLinkyTestSuite ();
TCase *genLinkyBasicTestCase ();
TCase *genLinkyDLLTestCase ();

#endif

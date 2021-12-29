/*
 * Author -- Meevs
 * Creation Date -- Thu Dec  2 02:04:44 2021
 * File Name -- stackyTestSuite.h
 * Notes -- 
 */

#ifndef __STACKY_TEST_SUITE__
#define __STACKY_TEST_SUITE__

#include <stdlib.h>
#include <check.h>
#include <stacky.h>

#include "stackyBasicFuncTest.h" /* Defines basic functionality tests */

Suite *genStackyTestSuite ();
TCase *genStackyBasicTestCase ();

#endif

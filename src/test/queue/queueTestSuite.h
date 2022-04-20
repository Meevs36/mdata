/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 01:32:07 2021
 * File Name -- queueTestSuite.h
 * Notes -- 
 */

#ifndef __QUEUE_TEST_SUITE__
#define __QUEUE_TEST_SUITE__

#include <stdlib.h>
#include <check.h>
#include <queue.h>

#include "queueBasicFuncTest.h"

Suite *genQueueTestSuite ();
TCase *genQueueBasicTestCase ();

#endif

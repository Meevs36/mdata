/*
 * Author -- Meevs
 * Creation Date -- Thu Dec  2 02:13:53 2021
 * File Name -- stackyBasicFuncTestSuite.h
 * Notes -- 
 */

#ifndef __STACKY_BASIC_FUNC_TESTS__
#define __STACKY_BASIC_FUNC_TESTS__

#include <stdio.h>
#include <string.h>
#include <stacky.h>

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:31:15 2021
 * Function Name -- stackyInitTest 
 * Function Purpose -- Tests the initialization of a Stacky stack, asserting that the data entered into the stack is properly stored.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (stackyInitTest)
{
  stacky *stack = NULL;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Stacky Init Test                                                             * */\r\n"
	  "/* ******************************************************************************** */\r\n\r\n"	  
	  "Initializing Stacky stack with value: 10\r\n");
  
  stackyPush (stack, 10);

  printf ("Checking data of Stacky stack:\r\n");
  printf ("\tExpected value: 10, Actual value: %d\r\n", *(int *)stack->data);
  
  ck_assert (*(int *)stack->data == 10);
  
  stackyDestroyStack (stack);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:31:54 2021
 * Function Name -- simpleStack 
 * Function Purpose -- Tests that the push and pop commands for a Stacky stack are properly working as intended.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (simpleStack)
{
  stacky *stack = NULL;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Simple Stack                                                                 * */\r\n"
	  "/* ******************************************************************************** */\r\n\r\n"
	  "Initializing Stacky stack with value: 10\r\n");

  stackyPush (stack, 10);

  printf ("Confirming return value of 'stackyPop':\r\n");
  printf ("\tExpected value: 10, Actual value; %d\r\n", *(int *)stack->data);
	  
  ck_assert (stackyPop (stack, int) == 10);

  stackyDestroyStack (stack);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:41:01 2021
 * Function Name -- popTest 
 * Function Purpose -- Tests the functionality of the Stacky module to properly handle the popping of elements off of it's stack.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (popTest)
{
  stacky *stack = NULL;
  const int elements [] = {15, 10, 5, 0};
  int index = 0;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Pop Test                                                                     * */\r\n"
	  "/* ******************************************************************************** */\r\n\r\n"
	  "Initializing Stack stack:\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("\tAdding element: %d\r\n", elements [index]);
      stackyPush (stack, elements [index]);
    }

  printf ("\r\nConfirming structure of stack:\r\n");
  for (index = index - 1; index >= 0; index--)
    {
      printf ("Expected value: %d, Actual value: %d\r\n", elements [index], *(int *)stack->data);
      ck_assert (stackyPop (stack, int) == elements [index]);
    }

  stackyDestroyStack (stack);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:42:05 2021
 * Function Name -- peakTest 
 * Function Purpose -- Tests the functionality of the Stacky module to peak at the element on the top of the stack without removing it.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (peakTest)
{
  stacky *stack = NULL;
  const int elements [] = {15, 10, 5, 0};
  int index = 0;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Peak Test                                                                    * */\r\n"
	  "/* ******************************************************************************** */\r\n\r\n"
	  "Initialization of Stacky stack:\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("\tAdding element: %d\r\n", elements [index]);
      stackyPush (stack, elements [index]);

      printf ("\tPeaking:\r\n");
      printf ("\t\tExpected value: %d, Actual value: %d\r\n", elements [index], stackyPeak (stack, int));
      ck_assert (stackyPeak (stack, int) == elements [index]);
    }

  stackyDestroyStack (stack);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:34:03 2021
 * Function Name -- stackyCharTest 
 * Function Purpose -- Tests the functionality of the Stacky stack to handle char data types. Asserting that chars entering the stacky stack are stored in the expected order.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (stackyCharTest)
{
  stacky *stack = NULL;
  const char elements [] = {'a', 'b', 'c', '\0'};
  int index = 0;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Stacky Char Test                                                             * */\r\n"
	  "/* ******************************************************************************** */\r\n\r\n"	  
	  "Initialization of Stacky stack:\r\n");
  
  for (index = 0; elements [index]; index++)
    {
      printf ("\tAdding element: %c\r\n", elements [index]);
      stackyPush (stack, elements [index]);
    }

  printf ("\r\nConfirming structure of Stacky stack:\r\n");
  
  for (index = index - 1; index >= 0; index--)
    {
      printf ("\tExpected value: %c, Actual value: %c\r\n", elements [index], stackyPeak (stack, char));
      ck_assert (stackyPop (stack, char) == elements [index]);
    }
  
  stackyDestroyStack (stack);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:34:03 2021
 * Function Name -- stackyShortTest 
 * Function Purpose -- Tests the functionality of the Stacky stack to handle short data types. Asserting that shorts entering the stacky stack are stored in the expected order.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (stackyShortTest)
{
  stacky *stack = NULL;
  const short elements [] = {10, 15, 20, 0};
  int index = 0;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Stacky Short Test                                                            * */\r\n"
	  "/* ******************************************************************************** */\r\n\r\n"
	  "Initialization of Stacky stack:\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("\tAdding element: %hd\r\n", elements [index]);
      stackyPush (stack, elements [index]);
    }

  printf ("\r\nConfirming structure of Stacky stack:\r\n");

  for (index = index - 1; index >= 0; index--)
    {
      printf ("\tExpected value: %hd, Actual value: %hd\r\n", elements [index], stackyPeak (stack, short));
      ck_assert (stackyPop (stack, short) == elements [index]);
    }
  
  stackyDestroyStack (stack);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:34:03 2021
 * Function Name -- stackyIntTest 
 * Function Purpose -- Tests the functionality of the Stacky stack to handle int data types. Asserting that ints entering the stacky stack are stored in the expected order.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (stackyIntTest)
{
  stacky *stack = NULL;
  const int elements [] = {10, 15, 20, 0};
  int index = 0;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Stacky Int Test                                                              * */\r\n"
	  "/* ******************************************************************************** */\r\n\r\n"
	  "Initialization of Stacky stack:\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("\tAdding element: %d\r\n", elements [index]);
      stackyPush (stack, elements [index]);
    }

  printf ("\r\nConfirming structure of Stacky stack:\r\n");

  for (index = index - 1; index >= 0; index--)
    {
      printf ("\tExpected value: %d, Actual value: %d\r\n", elements [index], stackyPeak (stack, int));
      ck_assert (stackyPop (stack, int) == elements [index]);
    }

  stackyDestroyStack (stack);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:34:03 2021
 * Function Name -- stackyLognTest 
 * Function Purpose -- Tests the functionality of the Stacky stack to handle logn data types. Asserting that logns entering the stacky stack are stored in the expected order.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (stackyLongTest)
{
  stacky *stack = NULL;
  const long elements [] = {10, 15, 20, 0};
  int index = 0;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Stacky Long Test                                                             * */\r\n"
	  "/* ******************************************************************************** */\r\n\r\n"
	  "Initialization of Stacky stack:\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("\tAdding element: %ld\r\n", elements [index]);
      stackyPush (stack, elements [index]);
    }

  printf ("\r\nConfirming structure of Stacky stack:\r\n");

  for (index = index - 1; index >= 0; index--)
    {
      printf ("\tExpected value: %ld, Actual value: %ld\r\n", elements [index], stackyPeak (stack, long));
      ck_assert (stackyPop (stack, long) == elements [index]);
    }


  stackyDestroyStack (stack);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:34:03 2021
 * Function Name -- stackyPtrTest 
 * Function Purpose -- Tests the functionality of the Stacky stack to handle ptr data types. Asserting that ptrs entering the stacky stack are stored in the expected order.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (stackyPtrTest)
{
  stacky *stack = NULL;
  const char *elements [] = {"Hello", " ", "World", NULL};
  int index = 0;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Stacky Ptr Test                                                              * */\r\n"
	  "/* ******************************************************************************** */\r\n\r\n"
	  "Initialization of Stacky stack:\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("\tAdding element: %s\r\n", elements [index]);
      stackyPush (stack, elements [index]);
    }

  printf ("\r\nConfirming structure of Stacky stack:\r\n");
  
  for (index = index - 1; index >= 0; index--)
    {
      printf ("\tExpected value: %s, Actual value: %s\r\n", elements [index], stackyPeak (stack, char *));
      ck_assert (strncmp (stackyPop (stack, char *), elements [index], 5) == 0);
    }

  stackyDestroyStack (stack);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:36:18 2021
 * Function Name -- isEmptyTestEmptyStack 
 * Function Purpose -- Tests the 'isEmpty' function to ensure that it properly works on an empty stack.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (isEmptyTestEmptyStack)
{
  stacky *stack = NULL;
  const int elements [] = {10, 15, 0};
  int index = 0;
  
  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * IsEmpty Test with Empty Stack                                                * */\r\n"
	  "/* ******************************************************************************** */\r\n\r\n"  
	  "Confirm empty stack with non-initialized stack:\r\n"
	  "\tExpected value: 1, Actual value: %d\r\n", stackyIsEmpty (stack));
  
  ck_assert (stackyIsEmpty (stack));

  printf ("\r\nInitializing Stacky stack:\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("\tAdding element: %d\r\n", elements [index]);
      stackyPush (stack, elements [index]);
    }
  
  printf ("\r\nDeconstructing stack:\r\n");

  for (; index > 0; index--)
    {
      printf ("\tRemoving element: %d\r\n", stackyPop (stack, int));
    }

  printf ("\r\nConfirming that isEmpty still returns true:\r\n"
	  "\tExpected value: 1, Actual value: %d\r\n", stackyIsEmpty (stack));
    
  ck_assert (stackyIsEmpty (stack));

  stackyDestroyStack (stack);  
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:39:30 2021
 * Function Name -- isEmptyTestSingleElement 
 * Function Purpose -- Tests the 'isEmpty' funciton to ensure that it properly detects a non-empty stack with one element.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (isEmptyTestSingleElement)
{
  stacky *stack = NULL;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * IsEmpty Test with Empty Stack                                                * */\r\n"
	  "/* ******************************************************************************** */\r\n\r\n"
	  "Initializing stack with single element:\r\n"
	  "\tAdding element: 10\r\n");

  stackyPush (stack, 10);

  printf ("\r\nConfirming Stacky stack is non-empty:\r\n"
	  "\tExpected value: 0, Actual value: %d\r\n", stackyIsEmpty (stack));
  
  ck_assert (!stackyIsEmpty (stack));

  stackyDestroyStack (stack);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:40:05 2021
 * Function Name -- isEmptyTestMultipleElements 
 * Function Purpose -- Tests the 'isEmpty' function to ensure it properly detects a non-empty stack with more than one element.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (isEmptyTestMultipleElements)
{
  stacky *stack = NULL;
  const int elements [] = {15, 10, 5, 0};
  int index = 0;
  
  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * IsEmpty Test with Empty Stack                                                * */\r\n"
	  "/* ******************************************************************************** */\r\n\r\n"
	  "Initializing stack with multiple  elements:\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("\tAdding element: %d\r\n", elements [index]);
      stackyPush (stack, elements [index]);
    }

  printf ("\r\nConfirm isEmpty can still recognize that the Stacky stack is non-empty with multiple elements contained:\r\n"
	  "\tExpected value: 0, Actual value: %d\r\n", stackyIsEmpty (stack));
  
  ck_assert (!stackyIsEmpty (stack));
  
  stackyDestroyStack (stack);
}
END_TEST
  
#endif

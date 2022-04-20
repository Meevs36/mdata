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

  stackyPush (stack, 10);

  ck_assert_ptr_ne (stack, NULL);
  ck_assert_int_eq (stack->data.i, 10);
  
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

  stackyPush (stack, 10);
  ck_assert_ptr_ne (stack, NULL);
  ck_assert_int_eq (stackyPop (stack, int), 10);

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
  const int MAX_SIZE = 3;
  const int elements [] = {15, 10, 5, 100};
  int index = 0;

  for (index = 0; index < MAX_SIZE; index++)    
    stackyPush (stack, elements [index]);

  for (index = MAX_SIZE - 1; index >= 0; index--)
    {
      ck_assert_ptr_ne (stack, NULL);
      ck_assert_int_eq (stackyPop (stack, int), elements [index]);
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

  for (index = 0; elements [index]; index++)
    {
      stackyPush (stack, elements [index]);
      ck_assert_ptr_ne (stack, NULL);
      ck_assert_int_eq (stackyPeak (stack, int), elements [index]);
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

  for (index = 0; elements [index]; index++)
    stackyPush (stack, elements [index]); 

  for (index = index - 1; index >= 0; index--)
    {
      ck_assert_ptr_ne (stack, NULL);
      ck_assert_int_eq (stackyPop (stack, char), elements [index]);
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

  for (index = 0; elements [index]; index++)
    stackyPush (stack, elements [index]);

  for (index = index - 1; index >= 0; index--)
    {
      ck_assert_ptr_ne (stack, NULL);
      ck_assert_int_eq (stackyPop (stack, short), elements [index]);
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

  for (index = 0; elements [index]; index++)
      stackyPush (stack, elements [index]);
  
  for (index = index - 1; index >= 0; index--)
    {
      ck_assert_ptr_ne (stack, NULL);
      ck_assert_int_eq (stackyPop (stack, int), elements [index]);
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

  for (index = 0; elements [index]; index++)
    stackyPush (stack, elements [index]);
		    
  for (index = index - 1; index >= 0; index--)
    {
      ck_assert_ptr_ne (stack, NULL);
      ck_assert_int_eq (stackyPop (stack, long), elements [index]);
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

  for (index = 0; elements [index]; index++)
    stackyPush (stack, elements [index]);
  
  for (index = index - 1; index >= 0; index--)
    {
      ck_assert_ptr_ne (stack, NULL);
      ck_assert_str_eq (stackyPop (stack, char *), elements [index]);
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
  
  ck_assert_int_eq (stackyIsEmpty (stack), 1);

  for (index = 0; elements [index]; index++)
      stackyPush (stack, elements [index]);

  for (; index > 0; index--)
    {
      ck_assert_ptr_ne (stack, NULL);
      stackyPop (stack, int);
    }
  
  ck_assert_int_eq (stackyIsEmpty (stack), 1);

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

  stackyPush (stack, 10);

  ck_assert_ptr_ne (stack, NULL);
  ck_assert_int_eq (stackyIsEmpty (stack), 0);

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
  
  for (index = 0; elements [index]; index++)
    stackyPush (stack, elements [index]);

  ck_assert_ptr_ne (stack, NULL);
  ck_assert_int_eq (stackyIsEmpty (stack), 0);
  
  stackyDestroyStack (stack);
}
END_TEST
  
#endif

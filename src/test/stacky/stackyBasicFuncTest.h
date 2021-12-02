/*
 * Author -- Meevs
 * Creation Date -- Thu Dec  2 02:13:53 2021
 * File Name -- stackyBasicFuncTestSuite.h
 * Notes -- 
 */

#ifndef __STACKY_BASIC_FUNC_TESTS__
#define __STACKY_BASIC_FUNC_TESTS__

START_TEST (simpleStack)
{
  stacky *stack = NULL;

  stackyPush (stack, 10);
  
  ck_assert (stackyPop (stack, int) == 10);

  stackyDestroyStack (stack);
}
END_TEST

START_TEST (isEmptyTestEmptyStack)
{
  stacky *stack = NULL;

  stackyPush (stack, 10);
  stackyPush (stack, 15);

  stackyPop (stack, int);
  stackyPop (stack, int);

  ck_assert (stackyIsEmpty (stack));

  stackyDestroyStack (stack);  
}
END_TEST

START_TEST (isEmptyTestSingleElement)
{
  stacky *stack = NULL;

  stackyPush (stack, 10);

  ck_assert (!stackyIsEmpty (stack));

  stackyDestroyStack (stack);
}
END_TEST

START_TEST (isEmptyTestMultipleElements)
{
  stacky *stack = NULL;

  stackyPush (stack, 15);
  stackyPush (stack, 10);
  stackyPush (stack, 5);

  ck_assert (!stackyIsEmpty (stack));
  
  stackyDestroyStack (stack);
}
END_TEST
  
START_TEST (popTest)
{
  stacky *stack = NULL;

  stackyPush (stack, 15);
  stackyPush (stack, 10);
  stackyPush (stack, 5);

  ck_assert (stackyPop (stack, int) == 5);
  ck_assert (stackyPop (stack, int) == 10);
  ck_assert (stackyPop (stack, int) == 15);

  stackyDestroyStack (stack);
}
END_TEST

START_TEST (peakTest)
{
  stacky *stack = NULL;

  stackyPush (stack, 15);
  ck_assert (stackyPeak (stack, int) == 15);
  stackyPush (stack, 10); 
  ck_assert (stackyPeak (stack, int) == 10);
  stackyPush (stack, 5);
  ck_assert (stackyPeak (stack, int) == 5);

  stackyDestroyStack (stack);
}
END_TEST

#endif

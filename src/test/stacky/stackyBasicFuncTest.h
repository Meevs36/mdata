/*
 * Author -- Meevs
 * Creation Date -- Thu Dec  2 02:13:53 2021
 * File Name -- stackyBasicFuncTestSuite.h
 * Notes -- 
 */

#ifndef __STACKY_BASIC_FUNC_TESTS__
#define __STACKY_BASIC_FUNC_TESTS__

#include <string.h>

START_TEST (stackyInitTest)
{
  stacky *stack = NULL;

  stackyPush (stack, 10);

  ck_assert (*(int *)stack->data == 10);
  
  stackyDestroyStack (stack);
}
END_TEST

START_TEST (simpleStack)
{
  stacky *stack = NULL;

  stackyPush (stack, 10);
  
  ck_assert (stackyPop (stack, int) == 10);

  stackyDestroyStack (stack);
}
END_TEST

START_TEST (stackyCharTest)
{
  stacky *stack = NULL;
  const char elements [] = {'a', 'b', 'c', '\0'};
  int index = 0;

  for (index = 0; elements [index]; index++)
    {
      stackyPush (stack, elements [index]);
    }

  for (index = index - 1; index >= 0; index--)
    {
      ck_assert (stackyPop (stack, char) == elements [index]);
    }
  
  stackyDestroyStack (stack);
}
END_TEST

START_TEST (stackyShortTest)
{
  stacky *stack = NULL;
  const short elements [] = {10, 15, 20, 0};
  int index = 0;

  for (index = 0; elements [index]; index++)
    {
      stackyPush (stack, elements [index]);
    }

  for (index = index - 1; index >= 0; index--)
    {
      ck_assert (stackyPop (stack, short) == elements [index]);
    }
  
  stackyDestroyStack (stack);
}
END_TEST

START_TEST (stackyIntTest)
{
  stacky *stack = NULL;
  const int elements [] = {10, 15, 20, 0};
  int index = 0;

  for (index = 0; elements [index]; index++)
    {
      stackyPush (stack, elements [index]);
    }

  for (index = index - 1; index >= 0; index--)
    {
      ck_assert (stackyPop (stack, int) == elements [index]);
    }

  stackyDestroyStack (stack);
}
END_TEST

START_TEST (stackyLongTest)
{
  stacky *stack = NULL;
  const long elements [] = {10, 15, 20, 0};
  int index = 0;

  for (index = 0; elements [index]; index++)
    {
      stackyPush (stack, elements [index]);
    }

  for (index = index - 1; index >= 0; index--)
    {
      ck_assert (stackyPop (stack, long) == elements [index]);
    }


  stackyDestroyStack (stack);
}
END_TEST

START_TEST (stackyPtrTest)
{
  stacky *stack = NULL;
  const char *elements [] = {"Hello", " ", "World", NULL};
  int index = 0;

  for (index = 0; elements [index]; index++)
    {
      stackyPush (stack, elements [index]);
    }

  for (index = index - 1; index >= 0; index--)
    {
      ck_assert (strncmp (stackyPop (stack, char *), elements [index], 5) == 0);
    }

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

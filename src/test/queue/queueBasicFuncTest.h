/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 02:24:12 2021
 * File Name -- queueBasicFuncTest.h
 * Notes -- 
 */

#ifndef __QUEUE_BASIC_FUNC_TESTS__
#define __QUEUE_BASIC_FUNC_TESTS__

#include <stdio.h>

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec 19 06:08:14 2021
 * Function Name -- initQueueTest0
 * Function Purpose -- Tests the basic initialization of a queue
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (initQueueTest0)
{
  queue *queue = NULL;

  queueInitNode (&queue);
  ck_assert_ptr_ne (queue, NULL);
  free (queue);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec 19 06:27:02 2021
 * Function Name -- queueGetSizeTest0 
 * Function Purpose -- Tests the 'queueGetSize' macro to ensure the size of the queue is as expected. This test is with a queue of size 1
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (queueGetSizeTest0)
{
  queue *queue = NULL;

  queueEnqueue (queue, 'a');
  
  ck_assert_ptr_ne (queue, NULL);
  ck_assert_int_eq (queueGetSize (queue), 1);
  
  free (queue);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec 19 06:29:36 2021
 * Function Name -- queueGetSizeTest1 
 * Function Purpose -- Tests the 'queueGetSize' macro to ensure the size of the queue is as expected. This test is with a queue greater than size 1
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (queueGetSizeTest1)
{
  struct queue *queue = NULL;
  struct queue *tempPtr = NULL;
  const char elements [] = {'a', 'b', 'c', '\0'};  
  int index = 0;

  for (index = 0; elements [index]; index++)
    queueEnqueue (queue, elements [index]);

  ck_assert_ptr_ne (queue, NULL);
  ck_assert_int_eq (queueGetSize (queue), index - 1);

  for (tempPtr = queue; tempPtr; tempPtr = tempPtr->next)
    free (tempPtr);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec 19 06:08:41 2021
 * Function Name -- queueFrontTest0
 * Function Purpose -- Tests the functionality of the queueFront macro-function
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (queueFrontTest0)
{
  struct queue *queue = NULL;

  queueEnqueue (queue, 'a');
  
  ck_assert_ptr_ne (queue, NULL);
  ck_assert_int_eq (queueFront (queue, char), 'a');
  
  free (queue);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec 19 06:16:47 2021
 * Function Name -- queueFrontTest1 
 * Function Purpose -- Tests the 'queueFront' macro-function with a queue larger than a single element.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (queueFrontTest1)
{
  struct queue *queue = NULL;
  struct queue *tempPtr = NULL;
  const char elements [] = {'a', 'b', 'c', '\0'};
  int index = 0;

  for (index = 0; elements [index]; index++)
    queueEnqueue (queue, elements [index]);

  ck_assert_ptr_ne (queue, NULL);
  ck_assert_int_eq (queueFront (queue, char), 'a');
  
  for (tempPtr = queue; tempPtr; tempPtr = tempPtr->next)
    free (tempPtr);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec 19 06:10:08 2021
 * Function Name -- queueRearTest0
 * Function Purpose -- Tests the functionality of the queueRear macro-function
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (queueRearTest0)
{
  struct queue *queue = NULL;

  queueEnqueue (queue, 'a');

  ck_assert_ptr_ne (queue, NULL);
  ck_assert_int_eq (queueRear (queue, char), 'a');
  
  free (queue);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec 19 06:20:12 2021
 * Function Name -- queueRearTest1 
 * Function Purpose -- Tests the functionality of the queueRear macro-function with a queue larger than a single element
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (queueRearTest1)
{
  struct queue *queue = NULL;
  struct queue *tempPtr = NULL;
  const char elements [] = {'a', 'b', 'c', '\0'};
  int index = 0;
  
  for (index = 0; elements [index]; index++)
    queueEnqueue (queue, elements [index]);
  
  ck_assert_ptr_ne (queue, NULL);
  ck_assert_int_eq (queueRear (queue, char), 'c');

  for (tempPtr = queue; tempPtr; tempPtr = tempPtr->next)
    free (tempPtr);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Thu Dec 23 22:05:35 2021
 * Function Name -- queueDequeueTest 
 * Function Purpose -- Tests the dequeue macro-function
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (queueDequeueTest)
{
  queue *queue = NULL;
  
  queueEnqueue (queue, 20);
  
  ck_assert_ptr_ne (queue, NULL);  
  ck_assert_int_eq (queueDequeue (queue, int), 20);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec 19 06:08:58 2021
 * Function Name -- charQueue 
 * Function Purpose -- Tests the functionality of a queue made up of chars
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (queueCharTest)
{
  queue *queue = NULL;
  const char elements [] = {'a', 'b', 'c', '\0'};
  int index = 0;
  
  for (index = 0; elements [index]; index++)
    queueEnqueue (queue, elements [index]);

  for (index = 0; elements [index]; index++)
    {
      ck_assert_ptr_ne (queue, NULL);
      ck_assert_int_eq (queueDequeue (queue, char), elements [index]);
    }
  
  queueDestroyQueue (queue);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec 19 06:38:25 2021
 * Function Name -- queueShortTest 
 * Function Purpose -- Tests the functionality of a queue made up of shorts
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (queueShortTest)
{
  queue *queue = NULL;
  const short elements [] = {10, 15, 25, 0};
  int index = 0;

  for (index = 0; elements [index]; index++)
    queueEnqueue (queue, elements [index]);

  for (index = 0; elements [index]; index++)
    {
      ck_assert_ptr_ne (queue, NULL);
      ck_assert_int_eq (queueDequeue (queue, short), elements [index]);
    }
  
  queueDestroyQueue (queue);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec 19 06:09:39 2021
 * Function Name -- queueIntTest 
 * Function Purpose -- Tests the functionality of a queue made up of ints
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (queueIntTest)
{
  queue *queue = NULL;
  const int elements [] = {10, 15, 25, 0};
  int index = 0;

  for (index = 0; elements [index]; index++)
    queueEnqueue (queue, elements [index]);

  for (index = 0; elements [index]; index++)
    {
      ck_assert_ptr_ne (queue, NULL);
      ck_assert_int_eq (queueDequeue (queue, int), elements [index]);
    }
  
  queueDestroyQueue (queue);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec 19 06:38:25 2021
 * Function Name -- queueLongTest 
 * Function Purpose -- Tests the functionality of a queue made up of longs
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (queueLongTest)
{
  queue *queue = NULL;
  const long elements [] = {10, 15, 25, 0};
  int index = 0;

  for (index = 0; elements [index]; index++)
    queueEnqueue (queue, elements [index]);

  for (index = 0; elements [index]; index++)
    {
      ck_assert_ptr_ne (queue, NULL);
      ck_assert_int_eq (queueDequeue (queue, long), elements [index]);
    }

  queueDestroyQueue (queue);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 07:49:35 2021
 * Function Name -- queuePtrTest 
 * Function Purpose -- Tests the functionality of a queue made up of pointers
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (queuePtrTest)
{
  struct queue *queue = NULL;
  const char *elements [] = {"Hello", " ", "World", NULL};
  int index = 0;

  for (index = 0; elements [index]; index++)
    queueEnqueue (queue, elements [index]);

  ck_assert_ptr_ne (queue, NULL);

  for (index = 0; elements [index]; index++)
    ck_assert_str_eq (queueDequeue (queue, char *), elements [index]);
  
  queueDestroyQueue (queue);
}
END_TEST

#endif

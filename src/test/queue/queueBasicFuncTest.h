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
 * Function Name -- initQueueTest
 * Function Purpose -- Tests the basic initialization of a queue
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (initQueueTest)
{
  queue *queue = NULL;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Queue Initialization Test                                                    * */\r\n"
	  "/* ******************************************************************************** */\r\n"
	  "Initializing Queue with value: 'a'\r\n");
  
  queueEnqueue (queue, 'a');

  printf ("Ensuring queue was successfully initialized\r\n");
  ck_assert (queue != NULL);
  printf ("Expected value: a, Actual value: %c\r\n", *(char *)(queue->data));
  ck_assert (*(char *)(queue->data) == 'a');

  queueDestroyQueue (queue);
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

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Queue Get Size Test 0                                                        * */\r\n"
	  "/* ******************************************************************************** */\r\n"
	  "Initializing Queue with value: 'a'\r\n");

  queueEnqueue (queue, 'a');
  printf ("Ensuring queue was successfully initialized");
  ck_assert (queue != NULL);
  printf ("Expected size: 1, Actual size: %d\r\n", queueGetSize (queue));
  ck_assert (queueGetSize (queue) == 1);

  queueDestroyQueue (queue);
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
  queue *queue = NULL;
  const char elements [] = {'a', 'b', 'c', '\0'};
  int index = 0;
  
  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Queue Get Size Test 1                                                        * */\r\n"
	  "/* ******************************************************************************** */\r\n"
	  "Initializing Queue:\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("\tEnqueueing value: '%c'\r\n", elements [index]);
      queueEnqueue (queue, elements [index]);
    }

  printf ("Ensuring queue was successfully initialized\r\n");
  ck_assert (queue != NULL);
  printf ("Expected value: %d, Actual value: %d\r\n", index - 1, queueGetSize (queue));
  ck_assert (queueGetSize (queue) == index - 1);

  queueDestroyQueue (queue);
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
  queue *queue = NULL;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Queue Front Test 0                                                           * */\r\n"
	  "/* ******************************************************************************** */\r\n"
	  "Initializing Queue with value: 'a'\r\n");
  
  queueEnqueue (queue, 'a');

  printf ("Ensuring queue was successfully initialized\r\n");
  ck_assert (queue != NULL);
  printf ("Expected value: 'a', Actual value: '%c'\r\n", queueFront (queue, char));
  ck_assert (queueFront (queue, char) == 'a');
  
  queueDestroyQueue (queue);
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
  queue *queue = NULL;
  const char elements [] = {'a', 'b', 'c', '\0'};
  int index = 0;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Queue Front Test 1                                                           * */\r\n"
	  "/* ******************************************************************************** */\r\n"
	  "Initializing Queue\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("\tAdding value: '%c'\r\n", elements [index]);
      queueEnqueue (queue, elements [index]);
    }

  printf ("Ensuring queue was successfully initialized\r\n");
  ck_assert (queue != NULL);
  
  printf ("Expected value: 'a', Actual value: '%c'\r\n", queueFront (queue, char));
  ck_assert (queueFront (queue, char) == 'a');
  
  queueDestroyQueue (queue);
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
  queue *queue = NULL;

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Queue Rear Test 0                                                            * */\r\n"
	  "/* ******************************************************************************** */\r\n"
	  "Initializing Queue with value: 'a'\r\n");
  
  queueEnqueue (queue, 'a');

  printf ("Ensuring queue was successfully initialized\r\n");
  ck_assert (queue != NULL);
  printf ("Expected value: 'a', Actual value: '%c'\r\n", queueRear (queue, char));
  ck_assert (queueRear (queue, char) == 'a');
  
  queueDestroyQueue (queue);
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
  queue *queue = NULL;
  const char elements [] = {'a', 'b', 'c', '\0'};
  int index = 0;
  
  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Queue Rear Test 1                                                            * */\r\n"
	  "/* ******************************************************************************** */\r\n"
	  "Initializing Queue:\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("\tEnqueueing value: '%c'\r\n", elements [index]);
      queueEnqueue (queue, elements [index]);      
    }

  printf ("Ensuring queue was successfully initialized\r\n");
  ck_assert (queue != NULL);

  printf ("Expected value: 'c', Actual value: '%c'\r\n", queueRear (queue, char));
  ck_assert (queueRear (queue, char) == 'c');

  queueDestroyQueue (queue);
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
  
  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Queue Char Test                                                              * */\r\n"
	  "/* ******************************************************************************** */\r\n"
	  "Initializing Queue:\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("\tAdding value: %c\r\n", elements [index]);
      queueEnqueue (queue, elements [index]);
    }

  printf ("Ensuring structure of queue is as expected:\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("Expected value: %c, Actual value: %c\r\n", elements [index], queueFront (queue, char));
      ck_assert (queueDequeue (queue, char) == elements [index]);
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

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Queue Simple Short Test                                                      * */\r\n"
	  "/* ******************************************************************************** */\r\n"
	  "Initializing Queue queue:\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("\tAdding element: %hd\r\n", elements [index]);
      queueEnqueue (queue, elements [index]);
    }

  
  printf ("\r\nConfirming the structure of the stack:\r\n");
  for (index = 0; elements [index]; index++)
    {
      printf ("\tExpected value: %hd, Actual value: %hd\r\n", elements [index], queueFront (queue, short));
      ck_assert (queueDequeue (queue, short) == elements [index]);
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

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Queue Simple Queue Test                                                      * */\r\n"
	  "/* ******************************************************************************** */\r\n"
	  "Initializing Queue queue:\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("\tAdding element: %d\r\n", elements [index]);
      queueEnqueue (queue, elements [index]);
    }

  
  printf ("\r\nConfirming the structure of the stack:\r\n");
  for (index = 0; elements [index]; index++)
    {
      printf ("\tExpected value: %d, Actual value: %d\r\n", elements [index], queueFront (queue, int));
      ck_assert (queueDequeue (queue, int) == elements [index]);
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

  printf ("\r\n/* ******************************************************************************** */\r\n"
	  "/* * Queue Simple Long Test                                                      * */\r\n"
	  "/* ******************************************************************************** */\r\n"
	  "Initializing Queue queue:\r\n");

  for (index = 0; elements [index]; index++)
    {
      printf ("\tAdding element: %ld\r\n", elements [index]);
      queueEnqueue (queue, elements [index]);
    }

  
  printf ("\r\nConfirming the structure of the stack:\r\n");
  for (index = 0; elements [index]; index++)
    {
      printf ("\tExpected value: %ld, Actual value: %ld\r\n", elements [index], queueFront (queue, long));
      ck_assert (queueDequeue (queue, long) == elements [index]);
    }
  
  queueDestroyQueue (queue);
}
END_TEST

#endif

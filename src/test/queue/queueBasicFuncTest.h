/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 02:24:12 2021
 * File Name -- queueBasicFuncTest.h
 * Notes -- 
 */

#ifndef __QUEUE_BASIC_FUNC_TESTS__
#define __QUEUE_BASIC_FUNC_TESTS__

START_TEST (simpleQueue)
{
  queue *queue = NULL;

  /* Initialize queue with values [10, 15, 25] */
  queueAppendNode (queue, 10);
  queueAppendNode (queue, 15);
  queueAppendNode (queue, 25);

  /* Assert that queue is as it was intended */
  ck_assert (queueGetData (queue, int) == 10);
  ck_assert (queueGetData (queue->next, int) == 15);
  ck_assert (queueGetData (queue->next->next, int) == 25);

  queueDestroyQueue (queue);
}
END_TEST

START_TEST (incrementalQueue)
{
  queue *queue = NULL;

  /* Incrementally initialize queue and assure values are intended as values are added */
  queueAppendNode (queue, 1);
  ck_assert (queueGetData (queue, int) == 1);
  queueAppendNode (queue, 2);
  ck_assert (queueGetData (queue, int) == 1);
  ck_assert (queueGetData (queue->next, int ) == 2);
  queueAppendNode (queue, 3);
  ck_assert (queueGetData (queue, int) == 1);
  ck_assert (queueGetData (queue->next, int ) == 2);
  ck_assert (queueGetData (queue->next->next, int ) == 3);

  queueDestroyQueue (queue);
}
END_TEST

START_TEST (insertElementTest)
{
  queue *queue = NULL;

  queueAppendNode (queue, 'a');
  queueAppendNode (queue, 'c');

  queueInsertElement (queue, 'b', 1);

  ck_assert (queueGetData (queue->next, char) == 'b');
  
  queueDestroyQueue (queue);
}
END_TEST

START_TEST (removeElementTest)
{
  queue *queue = NULL;

  queueAppendNode (queue, 'a');
  queueAppendNode (queue, 'b');
  queueAppendNode (queue, 'c');

  ck_assert (queueGetData (queue->next, char) == 'b');
  
  queueRemoveElement (queue, 1);

  ck_assert (queueGetData (queue->next, char) == 'c');
  
  queueDestroyQueue (queue);
}
END_TEST

#endif

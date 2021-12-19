/*
 * Author -- Meevs
 * Creation Date -- Sat Jul 31 18:20:18 2021
 * File Name -- queue.c
 * Notes -- 
 */

#include <queue/queue.h>

/*
 * Author -- Meevs
 * Creation Date -- Sat Jul 31 18:23:03 2021
 * Function Name -- queueEnqueueChar 
 * Function Purpose -- Enqueues a char node to the given queue
 * Function Parameters -- 
 * Function Returns -- The queue that the char was enqueueed to
 * Notes --
 */
struct queue *queueEnqueueChar (struct queue **queue, char data)
{
  struct queue *tempPtr = NULL;
  
  if (queue)
    {
      /* Traverse to the end of the queue */
      for (tempPtr = *queue; tempPtr && tempPtr->next; tempPtr = tempPtr->next);

      /* Allocate space for the queue data structure */
      tempPtr->next = calloc (1, sizeof (queue));
      /* Ensure that the allocation for the queue was successful */
      if (tempPtr->next)
	{
	  /* Allocate memory for the data of the queue */
	  tempPtr->next->data = calloc (1, sizeof (char *));
	  /* Ensure that the allocation for the data was successful */
	  if (tempPtr->next->data)
	    *(char *)(tempPtr->next->data) = data;
	  else /* If the allocation failed, we shall free up the un-populated queue node */
	    free (tempPtr->next);
	}
      
      tempPtr = *queue;
    }
  
  return tempPtr;
}

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec 19 01:20:05 2021
 * Function Name -- queueEnqueueShort 
 * Function Purpose -- Enqueues a short node to the given queue
 * Function Parameters -- 
 * Function Returns -- The queue that the short was enqueueed to
 * Notes --
 */
struct queue *queueEnqueueShort (struct queue **queue, short data)
{
  struct queue *tempPtr = NULL;
  

  
  return tempPtr;
}

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec 19 01:25:26 2021
 * Function Name -- queueEnqueueInt 
 * Function Purpose -- Enqueues an int node to the given queue
 * Function Parameters -- 
 * Function Returns -- The queue that the int was enqueueed to
 * Notes --
 */
struct queue *queueEnqueueInt (struct queue **queue, int data)
{
  struct queue *tempPtr = NULL;

  return tempPtr;
}

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec 19 01:26:24 2021
 * Function Name -- queueEnqueueLong 
 * Function Purpose -- Enqueues a long node to the given queue
 * Function Parameters -- 
 * Function Returns -- The queue that the long was enqueueed to
 * Notes --
 */
struct queue *queueEnqueueLong (struct queue **queue, long data)
{
  struct queue *tempPtr = NULL;

  
  return tempPtr;
}

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec 19 01:28:16 2021
 * Function Name -- queueEnqueuePtr
 * Function Purpose -- Enqueues the given pointer to the given queue
 * Function Parameters -- 
 * Function Returns -- The queue that the pointer was enqueueed to
 * Notes --
 */
struct queue *queueEnqueuePtr (struct queue **queue, void *data)
{
  struct queue *tempPtr = NULL;

  return tempPtr;
}

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec 19 01:30:21 2021
 * Function Name -- voidDestroyQueue 
 * Function Purpose -- Releases the given queue from memory
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
void queueDestroyQueue (struct queue *queue)
{
  
}

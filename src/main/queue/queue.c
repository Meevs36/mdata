/*
 * Author -- Meevs
 * Creation Date -- Sat Jul 31 18:20:18 2021
 * File Name -- queue.c
 * Notes -- 
 */

#include <queue/queue.h>

/*
 * Author -- Meevs
 * Creation Date -- Wed Dec 22 08:30:10 2021
 * Function Name -- queueInitNode 
 * Function Purpose -- Initializes a queue node at the end of the given queue, or initializes a queue with one element if the given queue is NULL
 * Function Parameters -- 
 *     -- struct queue *queue -- The queue which the new node will be appended to.
 *     -- void *dataPtr -- A void pointer to the data that will be held by this node.
 * Function Returns -- void
 * Notes --
 */
void queueInitNode (struct queue **queue, void *dataPtr)
{
  struct queue *newNode = NULL;
  struct queue *tempPtr = NULL;
  
  /* Ensure we were given a valid address to work with */
  if (queue)
    /* Attempt to initialize a queue node */
    if (newNode = calloc (1, sizeof (struct queue)))
      {
	newNode->data = dataPtr;
	newNode->size = 1;
	
	/* If the address is non-NULL, we must have a pre-initialized queue */
	if (*queue)
	  {
	    /* Traverse to the end of the queue */
	    for (tempPtr = *queue; tempPtr && tempPtr->next; tempPtr = tempPtr->next)
	      tempPtr->size++;
	    
	    /* Append the new node to the end of the queue */
	    tempPtr->next = newNode;	    
	  }
	else /* Otherwise, the newly initialized node will be the beginning of the queue */
	  *queue = newNode;
      }
}

/*
 * Author -- Meevs
 * Creation Date -- Wed Dec 22 09:25:35 2021
 * Function Name -- queueDequeueBase 
 * Function Purpose -- Dequeues the next element from the given queue.
 * Function Parameters -- 
 *     -- struct queue **queue -- The queue who's element will be dequeued
 * Function Returns -- The data held by the dequeued node
 * Notes --
 *     -- 2021-12-23 -- The data returned is stored in a void *, and should be casted to the desired data type
 */
void *queueDequeueBase (struct queue **queue)
{
  struct queue *tempPtr = NULL;
  void *data = NULL;

  /* Ensure we were given a valid address and that address contains a queue */
  if (queue && *queue)
    {
      tempPtr = *queue;
      *queue = (*queue)->next;

      data = tempPtr->data;
      free (tempPtr);
    }

  return data;
}

/*
 * Author -- Meevs
 * Creation Date -- Fri Dec 24 02:20:56 2021
 * Function Name -- queueGetRear 
 * Function Purpose -- Gets the pointer of the last node in the queue
 * Function Parameters -- 
 * Function Returns -- A void * to the data value of the last node in the queue
 * Notes --
 */
void *queueGetRear (struct queue **queue)
{
  struct queue *tempPtr = NULL;
  void *dataPtr = NULL;

  if (queue)
    {
      /* Traverse to the end of the queue */
      for (tempPtr = *queue; tempPtr && tempPtr->next; tempPtr = tempPtr->next);
      dataPtr = tempPtr->data;
    }
  
  return dataPtr;
}

/*
 * Author -- Meevs
 * Creation Date -- Sat Jul 31 18:23:03 2021
 * Function Name -- queueEnqueueChar 
 * Function Purpose -- Enqueues a char node to the given queue
 * Function Parameters -- 
 * Function Returns -- void 
 * Notes --
 */
void queueEnqueueChar (struct queue **queue, char data)
{
  char *dataPtr = NULL;
  
  if (queue)
    if (dataPtr = (char *)calloc (1, sizeof (char)))
      {
	*dataPtr = data;
	queueInitNode (queue, (void *)dataPtr);
      }
}

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec 19 01:20:05 2021
 * Function Name -- queueEnqueueShort 
 * Function Purpose -- Enqueues a short node to the given queue
 * Function Parameters -- 
 * Function Returns -- void 
 * Notes --
 */
void queueEnqueueShort (struct queue **queue, short data)
{
  short *dataPtr = NULL;

  if (queue)
    if (dataPtr = (short *)calloc (1, sizeof (short)))
    {
      *dataPtr = data;
      queueInitNode (queue, (void *)dataPtr);
    }
}

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec 19 01:25:26 2021
 * Function Name -- queueEnqueueInt 
 * Function Purpose -- Enqueues an int node to the given queue
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
void queueEnqueueInt (struct queue **queue, int data)
{
  int *dataPtr = NULL;

  if (queue)
    if (dataPtr = (int *)calloc (1, sizeof (int)))
      {
	*dataPtr = data;
	queueInitNode (queue, (void *)dataPtr);
      }
}

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec 19 01:26:24 2021
 * Function Name -- queueEnqueueLong 
 * Function Purpose -- Enqueues a long node to the given queue
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
void queueEnqueueLong (struct queue **queue, long data)
{
  long *dataPtr = NULL;

  if (queue)
    if (dataPtr = (long *)calloc (1, sizeof (long)))
      {
	*dataPtr = data;
	queueInitNode (queue, (void *)dataPtr);
      }
}

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec 19 01:28:16 2021
 * Function Name -- queueEnqueuePtr
 * Function Purpose -- Enqueues the given pointer to the given queue
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
void queueEnqueuePtr (struct queue **queue, void *data)
{
  void **dataPtr = NULL;

  if (queue)
    if (dataPtr = (void *)calloc (1, sizeof (void *)))
      {
	*dataPtr = data;
	queueInitNode (queue, dataPtr);
      }
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

 

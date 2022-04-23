/*
 * Author -- Meevs
 * Creation Date -- Sat Jul 31 18:20:18 2021
 * File Name -- queue.c
 * Notes -- 
 */

#include <queue.h>

/*
 * Author -- Meevs
 * Creation Date -- Wed Dec 22 08:30:10 2021
 * Function Name -- queueInitNode 
 * Function Purpose -- Initializes a queue node at the end of the given queue, or initializes a queue with one element if the given queue is NULL
 * Function Parameters -- 
 *     -- struct queue *queue -- The queue which the new node will be appended to.
 * Function Returns -- A pointer to the newly created queue node
 * Notes --
 */
struct queue *queueInitNode (struct queue **queue)
{
  struct queue *newNode = NULL;
  struct queue *tempPtr = NULL;
  
  /* Ensure we were given a valid address to work with */
  if (queue && (newNode = calloc (1, sizeof (struct queue))))
    {
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

  return newNode;
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
long queueDequeueBase (struct queue **queue)
{
  struct queue *tempPtr = NULL;
  long data = 0;

  /* Ensure we were given a valid address and that address contains a queue */
  if (queue && *queue)
    {
      tempPtr = *queue;
      *queue = (*queue)->next;

      data = tempPtr->data.l;
      free (tempPtr);
    }

  return data;
}

/*
 * Author -- Meevs
 * Creation Date -- Wed Dec 29 09:57:26 2021
 * Function Name -- queueGetSize 
 * Function Purpose -- Gets the size of the given queue
 * Function Parameters -- 
 * Function Returns -- The number of elements contained within the given queue
 * Notes --
 */
unsigned int queueGetSize (struct queue *queue)
{
  unsigned int size = 0;

  if (queue)
    size = queue->size;
  
  return size;
}

/*
 * Author -- Meevs
 * Creation Date -- Wed Dec 29 10:06:41 2021
 * Function Name -- queueGetFront 
 * Function Purpose -- Gets the value from the front of the given queue
 * Function Parameters -- 
 * Function Returns -- The data held at the front of the given queue
 * Notes --
 */
long queueGetFront (struct queue *queue)
{
  long data = 0;

  if (queue)
    data = queue->data.l;
  
  return data;
}

/*
 * Author -- Meevs
 * Creation Date -- Fri Dec 24 02:20:56 2021
 * Function Name -- queueGetRear 
 * Function Purpose -- Gets the pointer of the last node in the queue
 * Function Parameters -- 
 * Function Returns -- The data held at the last node of the queue
 * Notes --
 *     -- 2021-12-24 -- Modified to return a long instead of the original void *. This instead makes use of the union structure.
 */
long queueGetRear (struct queue **queue)
{
  struct queue *tempPtr = NULL;
  long data = 0;

  if (queue)
    {
      /* Traverse to the end of the queue */
      for (tempPtr = *queue; tempPtr && tempPtr->next; tempPtr = tempPtr->next);
      if (tempPtr)
	data = tempPtr->data.l;      
    }
  
  return data;
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
  struct queue *tempPtr = NULL;
  
  if (queue && (tempPtr = queueInitNode (queue)))
    tempPtr->data.c = data;
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
  struct queue *tempPtr = NULL;
  
  if (queue && (tempPtr = queueInitNode (queue)))
    tempPtr->data.s = data;
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
  struct queue *tempPtr = NULL;
  
  if (queue && (tempPtr = queueInitNode (queue)))
    tempPtr->data.i = data;
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
  struct queue *tempPtr = NULL;

  if (queue && (tempPtr = queueInitNode (queue)))
    tempPtr->data.l = data;
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
  struct queue *tempPtr = NULL;

  if (queue && (tempPtr = queueInitNode (queue)))
    tempPtr->data.ptr = data;
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

 

/*
 * Author -- Meevs
 * Creation Date -- Sat Jul 31 18:03:37 2021
 * File Name -- queue.h
 * Notes -- 
 */

#ifndef __QUEUE__
#define __QUEUE__

#include <stdlib.h>

typedef struct queue queue;

struct queue
{
  unsigned int size;
  union
  {
    char c;
    short s;
    int i;
    long l;
    void *ptr;    
  } data;

  struct queue *next;
};

#define queueEnqueue(queue, data)					\
  {									\
    _Pragma ("GCC diagnostic push")					\
      _Pragma ("GCC diagnostic ignored \"-Wint-to-pointer-cast\"")	\
      _Pragma ("GCC diagnostic ignored \"-Wpointer-to-int-cast\"")	\
      _Generic (data,							\
		char: queueEnqueueChar (&queue, (char)data),		\
		short: queueEnqueueShort (&queue, (short)data),		\
		int: queueEnqueueInt (&queue, (int)data),		\
		long: queueEnqueueLong (&queue, (long)data),		\
		default: queueEnqueuePtr (&queue, (void *)data));	\
      _Pragma ("GCC diagnostic pop")					\
      }

#define queueDequeue(queue, type) (type)queueDequeueBase (&queue)
#define queueFront(queue, type) (type)queueGetFront (queue)
#define queueRear(queue, type) (type)queueGetRear (&queue)

struct queue *queueInitNode (struct queue **queue);
long queueDequeueBase (struct queue **queue);
unsigned int queueGetSize (struct queue *queue);
long queueGetFront (struct queue *queue);
long queueGetRear (struct queue **queue);
void queueEnqueueChar (struct queue **queue, char data);
void queueEnqueueShort (struct queue **queue, short data);
void queueEnqueueInt (struct queue **queue, int data);
void queueEnqueueLong (struct queue **queue, long data);
void queueEnqueuePtr (struct queue **queue, void *data);
void queueDestroyQueue (struct queue *queue);

#endif

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
  void *data;

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

#define queueGetSize(queue) queue->size
#define queueDequeue(queue, type) (type)0 /* <<STUB>> */
#define queueFront(queue, type) (*((type *) queue->data))
#define queueRear(queue, type) (type)0 /* <<STUB>> */

struct queue *queueEnqueueChar (struct queue **queue, char data);
struct queue *queueEnqueueShort (struct queue **queue, short data);
struct queue *queueEnqueueInt (struct queue **queue, int data);
struct queue *queueEnqueueLong (struct queue **queue, long data);
struct queue *queueEnqueuePtr (struct queue **queue, void *data);
void queueDestroyQueue (struct queue *queue);

#endif

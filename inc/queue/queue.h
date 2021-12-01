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

#define queueAppendNode(queue, data)					\
  {									\
    _Pragma ("GCC diagnostic push")					\
      _Pragma ("GCC diagnostic ignored \"-Wint-to-pointer-cast\"")	\
      _Pragma ("GCC diagnostic ignored \"-Wpointer-to-int-cast\"")	\
      _Generic (data,							\
		char: queueAppendChar (&queue, (char)data),		\
		short: queueAppendShort (&queue, (short)data),		\
		int: queueAppendInt (&queue, (int)data),		\
		long: queueAppendLong (&queue, (long)data),		\
		default: queueAppendBase (&queue, (void *)data));	\
      _Pragma ("GCC diagnostic pop")					\
      }

#define queueGetData(queue, type) (*((type *) queue->data))

struct queue *queueAppendChar (struct queue **queue, char data);
struct queue *queueAppendShort (struct queue **queue, short data);
struct queue *queueAppendInt (struct queue **queue, int data);
struct queue *queueAppendLong (struct queue **queue, long data);
struct queue *queueAppendBase (struct queue **queue, void *data);
void queueDestroyQueue (struct queue *queue);

#endif

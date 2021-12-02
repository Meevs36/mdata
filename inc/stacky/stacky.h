/*
 * Author -- Meevs
 * Creation Date -- Wed Dec 23 08:08:17 2020
 * File Name -- stacky.h
 * Notes -- 
 */

#ifndef __STACKY__
#define __STACKY__

#include <stdlib.h>

typedef struct stacky stacky;
struct stacky
{
  void *data;
  
  struct stacky *next;
};


#define stackyPush(stacky, data)				\
  _Pragma ("GCC diagnostic push")				\
  _Pragma ("GCC diagnostic ignored \"-Wint-to-pointer-cast\"")	\
  _Pragma ("GCC diagnostic ignored \"-Wpointer-to-int-cast\"")	\
    _Generic (data,						\
	      char: stackyPushChar (&stacky, (char)data),	\
	      short: stackyPushShort (&stacky, (short)data),	\
	      int: stackyPushInt (&stacky, (int)data),		\
	      long: stackyPushLong (&stacky, (long)data),	\
	      default: stackyPushBase (&stacky, (void *)data));	\
  _Pragma ("GCC diagnostic pop")				

#define stackyPop(stacky, type) (*(type *)stackyPopData (&stacky))
#define stackyPeak(stacky, type) (*(type *)stacky->data)

struct stacky *stackyCreateNode (struct stacky **stack);

void stackyPushChar (struct stacky **stack, char data);
void stackyPushShort (struct stacky **stack, short data);
void stackyPushInt (struct stacky **stack, int data);
void stackyPushLong (struct stacky **stack, long data);
void stackyPushBase (struct stacky **stack, void *data);

void *stackyPopData (struct stacky **stack);
int stackyIsEmpty (struct stacky *stack);
void stackyDestroyStack (struct stacky *stack);

#endif

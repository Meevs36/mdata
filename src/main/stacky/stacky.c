/*
 * Author -- Meevs
 * Creation Date -- Wed Dec 23 08:08:02 2020
 * File Name -- stacky.c
 * Notes -- 
 */

#include <stacky.h>


/*
 * Author -- Meevs
 * Creation Date -- Wed Dec 23 09:28:42 2020
 * Function Name -- stackyCreateNode 
 * Function Purpose -- Creates a new Stacky node and puts it ontop of the given Stacky stack.
 * Function Parameters --
 *     -- struct stacky *stack -- The Stacky stack that the created node will be place on top of.
 * Function Returns -- The newly created Stacky node ontop of the Stacky stack.
 * Notes --
 *     2020 Dec, 23 -- This function does not initialize the data of the newly created Stacky node.
 */
struct stacky *stackyCreateNode (struct stacky **stack)
{
  struct stacky *node = NULL;

  if (stack && (node = calloc (1, sizeof (struct stacky))))
    node->next = *stack;
  
  return node;
}

/*
 * Author -- Meevs
 * Creation Date -- Wed Dec 23 08:43:28 2020
 * Function Name -- stackyPushChar 
 * Function Purpose -- Pushes the given char onto the given Stacky stack.
 * Function Parameters -- 
 *     -- struct stacky **stackPtr -- A pointer to the location of the Stacky stack that the data will be pushed onto.
 *     -- char data -- The character data that will be pushed onto the given Stacky stack.
 * Function Returns -- void
 * Notes --
 */
void stackyPushChar (struct stacky **stackPtr, char data)
{
  struct stacky *temp = NULL;

  if (stackPtr && (temp = stackyCreateNode (stackPtr)))
    {
      temp->data.c = data;
      *stackPtr = temp;
    }
}

/*
 * Author -- Meevs
 * Creation Date -- Wed Dec 23 09:45:21 2020
 * Function Name -- stackyPushShort 
 * Function Purpose -- Pushes the given short onto the given Stacky stack.
 * Function Parameters -- 
 *     -- struct stacky **stackPtr -- A pointer to the location of the Stacky stack that the data will be pushed onto.
 *     -- short data -- The short integer data that will be pushed onto the given Stacky stack.
 * Function Returns -- void
 * Notes --
 */
void stackyPushShort (struct stacky **stackPtr, short data)
{
  struct stacky *temp = NULL;

  if (stackPtr && (temp = stackyCreateNode (stackPtr)))
    {
      temp->data.s = data;
      *stackPtr = temp;
    }
}

/*
 * Author -- Meevs
 * Creation Date -- Wed Dec 23 09:47:06 2020
 * Function Name -- stackyPushInt 
 * Function Purpose -- Pushed the given int onto the given Stacky stack.
 * Function Parameters -- 
 *     -- struct stacky **stackPtr -- A pointer to the location of the Stacky stack that the data will be pushed onto.
 *     -- int data -- The integer data that will be pushed onto the given Stacky stack.
 * Function Returns -- void
 * Notes --
 */
void stackyPushInt (struct stacky **stackPtr, int data)
{
  struct stacky *temp = NULL;

  if (stackPtr && (temp = stackyCreateNode (stackPtr)))
    {
      temp->data.i = data;
      *stackPtr = temp;
    }
}

/*
 * Author -- Meevs
 * Creation Date -- Wed Dec 23 09:48:31 2020
 * Function Name -- stackyPushLong 
 * Function Purpose -- Pushes the given long onto the given Stacky stack.
 * Function Parameters -- 
 *     -- struct stacky **stackPtr -- A pointer to the location of the Stacky stack that the data will be pushed onto.
 *     -- long data -- The long integer data that will be pushed onto the given Stacky stack.
 * Function Returns -- void
 * Notes --
 */
void stackyPushLong (struct stacky **stackPtr, long data)
{
  struct stacky *temp = NULL;

  if (stackPtr && (temp = stackyCreateNode (stackPtr)))
    {
      temp->data.l = data;
      *stackPtr = temp;
    }
}

/*
 * Author -- Meevs
 * Creation Date -- Wed Dec 23 09:49:52 2020
 * Function Name -- stackyPushBase 
 * Function Purpose -- Pushes the given pointer onto the given Stacky stack.
 * Function Parameters -- 
 *     -- struct stacky **stackPtr -- A pointer to the location of the Stacky stack that the data will be pushed onto.
 *     -- void *data -- A pointer to the generic data that will be pushed onto the given Stacky stack.
 * Function Returns -- void
 * Notes --
 */
void stackyPushBase (struct stacky **stackPtr, void *data)
{
  struct stacky *temp = NULL;

  if (stackPtr && (temp = stackyCreateNode (stackPtr)))
    {
      temp->data.ptr = data;
      *stackPtr = temp;
    }
}

/*
 * Author -- Meevs
 * Creation Date -- Wed Dec 23 09:20:31 2020
 * Function Name -- stackyPopData 
 * Function Purpose -- Pops the next node from the given Stacky.
 * Function Parameters -- 
 *     -- struct stacky **stackPtr -- A pointer to the desired Stacky stack who's data will be popped
 * Function Returns -- A pointer to the data popped off of the given Stacky stack.
 * Notes --
 */
long stackyPopData (struct stacky **stackPtr)
{
  struct stacky *temp = NULL;
  long data = 0;
  
  if (stackPtr && (*stackPtr))
    {
      data = (long)(*stackPtr)->data.l;
      temp = (*stackPtr);
      (*stackPtr) = (*stackPtr)->next;
      
      free (temp);      
    }

  return data;
}

/*
 * Author -- Meevs
 * Creation Date -- Wed Dec 23 09:35:55 2020
 * Function Name -- stackyIsEmpty 
 * Function Purpose -- Checks if the given Stacky stack is empty or not.
 * Function Parameters -- 
 *     -- struct stacky *stack -- The Stacky stack that will be checked if is empty or not.
 * Function Returns -- This function will return the integer value of 1 if the given Stacky stack is empty, otherwise it will return the integer value of 0.
 * Notes --
 *     -- 2020 Dec, 23 -- This is a convenience function, the same can be achieved by checking if the Stacky pointer is NULL or not.
 */
int stackyIsEmpty (struct stacky *stack)
{
  int isEmpty = 0;

  if (!stack)
    {
      isEmpty = 1;
    }
  
  return isEmpty;
}

/*
 * Author -- Meevs
 * Creation Date -- Wed Dec 23 09:57:16 2020
 * Function Name -- stackyDestroyStack 
 * Function Purpose -- Releases the memory allocated to the given Stack stack.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
void stackyDestroyStack (struct stacky *stack)
{
  if (stack)
    {
      stackyDestroyStack (stack->next);
      free (stack);
    }
}

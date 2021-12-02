/*
 * Author -- Meevs
 * Creation Date -- Sat Oct  3 12:24:06 2020
 * File Name -- linky.c
 * Notes -- 
 */

#include <linky.h>

/*
 * Author -- Meevs
 * Creation Date -- Sat Oct  3 17:17:18 2020
 * Function Name -- linkyAppendNode
 * Function Purpose -- Constructs and appends a new node to the given list.
 * Function Parameters -- 
 *     -- struct linky **list -- The linky list which the new ndoe will be appended to.
 * Function Returns -- A pointer to the generated node.
 * Notes --
 *     -- 2020 Dec, 22 -- Renamed function to better represent what the function does.
 *                        Also updated description of the function header to better describe it's purpose.
 */
struct linky **linkyAppendNode (struct linky **list)
{
  struct linky **tempPtr = NULL;

  if (list != NULL)
    {
      /* Iterates through all nodes in the given list. */
      for (tempPtr = list; *tempPtr != NULL && (*tempPtr)->size++ && (*tempPtr)->next != NULL; tempPtr = &(*tempPtr)->next);

      if (*tempPtr == NULL)
	*tempPtr = (struct linky *)calloc (1, sizeof (struct linky));
      else
	{
	  (*tempPtr)->next = (struct linky *)calloc (1, sizeof (struct linky));
	  (*tempPtr)->next->prev = (*tempPtr);
	  tempPtr = &(*tempPtr)->next;
	}

      (*tempPtr)->size++;
    }

  return tempPtr;
}

/*
 * Author -- Meevs
 * Creation Date -- Sat Oct  3 17:04:03 2020
 * Function Name -- linkyAddChar 
 * Function Purpose -- LinkyAdds a given char value to the given linky list.
 * Function Parameters -- 
 *     -- struct linky **list -- The linkyAddress of the given linky list.
 *     -- char data -- The character that will be appended to the given list.
 * Function Returns -- A pointer to the generated node.
 * Notes --
 */
struct linky *linkyAddChar (struct linky **list, char data)
{
  struct linky **tempPtr = NULL;
  struct linky *generatedNode = NULL;

  tempPtr = linkyAppendNode (list);

  if (tempPtr != NULL)
    {
      generatedNode = *tempPtr;
      generatedNode->data = calloc (1, sizeof (char));
      *(char *)generatedNode->data = data;
    }
  
  return generatedNode;
}

/*
 * Author -- Meevs
 * Creation Date -- Sat Oct  3 17:40:40 2020
 * Function Name -- linkyAddShort 
 * Function Purpose -- LinkyAdds the given short to the given linky list.
 * Function Parameters -- 
 *     -- struct linky **list -- The list that the short will be appended to.
 *     -- short data -- The short that will be appended to the end of the linky list.
 * Function Returns -- A pointer to the generated linky node.
 * Notes --
 */
struct linky *linkyAddShort (struct linky **list, short data)
{
  struct linky **tempPtr = NULL;
  struct linky *generatedNode = NULL;

  tempPtr = linkyAppendNode (list);

  if (tempPtr != NULL)
    {
      generatedNode = *tempPtr;
      generatedNode->data = calloc (1, sizeof (short));
      *(short *)generatedNode->data = data;     
    }
  
  return generatedNode;
}

/*
 * Author -- Meevs
 * Creation Date -- Sat Oct  3 17:56:02 2020
 * Function Name -- linkyAddInt 
 * Function Purpose -- Appends the given int to the end of the given linky list.
 * Function Parameters -- 
 *     -- struct linky *list -- The list that the given int will be appended onto.
 *     -- int data -- The int that will be appended onto the given list.
 * Function Returns -- A pointer to the generated linky node containing the given int.
 * Notes --
 */
struct linky *linkyAddInt (struct linky **list, int data)
{
  struct linky **tempPtr = NULL;
  struct linky *generatedNode = NULL;

  tempPtr = linkyAppendNode (list);

  if (tempPtr != NULL)
    {
      generatedNode = *tempPtr;
      generatedNode->data = calloc (1, sizeof (int));
      *(int *)generatedNode->data = data;
    }
  
  return generatedNode;
}

/*
 * Author -- Meevs
 * Creation Date -- Sat Oct  3 18:04:24 2020
 * Function Name -- linkyAddLong 
 * Function Purpose -- Appends the given long to the end of the given linky list.
 * Function Parameters -- 
 * Function Returns -- A pointer to the generated linky node containing the given long.
 * Notes --
 */
struct linky *linkyAddLong (struct linky **list, long data)
{
  struct linky **tempPtr = NULL;
  struct linky *generatedNode = NULL;

  tempPtr = linkyAppendNode (list);

  if (tempPtr != NULL)
    {
      generatedNode = *tempPtr;
      generatedNode->data = calloc (1, sizeof (long));
      *(long *)generatedNode->data = data;
    }
  
  return generatedNode;
}

/*
 * Author -- Meevs
 * Creation Date -- Sat Oct  3 12:35:15 2020
 * Function Name -- linkyAddBase 
 * Function Purpose -- Appends the given data to the end of the given list.
 * Function Parameters -- 
 *     -- struct linky *list -- The list that the data will be appended onto.
 *     -- void *data -- The generic data that will be appended onto the list.
 * Function Returns -- A pointer to the list being operated on.
 * Notes --
 */
struct linky *linkyAddBase (struct linky **list, void *data)
{
  struct linky **tempPtr = NULL;
  struct linky *generatedNode = NULL;

  tempPtr = linkyAppendNode (list);

  if (tempPtr != NULL)
    {
      generatedNode = *tempPtr;
      generatedNode->data = calloc (1, sizeof (void *));
      *(void **)generatedNode->data = data;
    }
  
  return generatedNode;
}

/*
 * Author -- Meevs
 * Creation Date -- Sat Oct  3 19:48:42 2020
 * Function Name -- linkyDestroyList 
 * Function Purpose -- Releases the memory used by the given list.
 * Function Parameters -- 
 * Function Returns -- void
 *     -- struct linky *list -- The list who's memory will be freed.
 * Notes --
 */
void linkyDestroyList (struct linky *list)
{
  if (list != NULL)
    {
      linkyDestroyList (list->next);
      free (list->data);
      free (list);
    }
}

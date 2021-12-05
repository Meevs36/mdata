/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:08:55 2021
 * File Name -- linkyDoubleLinkedListTest.h
 * Notes -- 
 */

#ifndef __LINKY_DOUBLE_LINKED_LIST_TEST__
#define __LINKY_DOUBLE_LINKED_LIST_TEST__

#inlcude <linky.h>

/*
 * Author -- Meevs
 * Creation Date -- Sun Dec  5 20:20:41 2021
 * Function Name -- dllTraversalTest 
 * Function Purpose -- Tests the capability of the double linked lists in the Linky module. This test attempts to traverse to the end of a Linky list, than turn around and come back to the beginning, asserting that all values are as to be expected.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (dllTraversalTest)
{
  linky *list = NULL;
  linky *tempPtr = NULL;
  int index = 0;

  /* Init List */
  for (index = 0; index < 10; index++)
    linkyAddNode (list, index);

  /* Traverse list forwards */
  for (tempPtr = list, index = 1; tempPtr; tempPtr = tempPtr->next, index++)
    ck_assert (linkyGetData (list, int) == index);

  /* Repoint tempPtr to end of list */
  for (tempPtr = list; tempPtr->next; tempPtr = tempPtr->next);
  
  /* Traverse list backwards */
  for (index = 9; tempPtr; tempPtr = tempPtr->prev, index--)
    ck_assert (linkyGetData (list, int) == index);
  
  linkyDestroyList (list);
}
END_TEST

#endif

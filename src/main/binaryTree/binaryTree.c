/*
 * Author -- Meevs
 * Creation Date -- Fri Dec 24 10:00:49 2021
 * File Name -- binaryTree.c
 * Notes -- 
 */

#include <binaryTree.h>


/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 10:30:12 2021
 * Function Name -- btDefaultCmp 
 * Function Purpose -- Compares the values of the two given binaryTree nodes
 * Function Parameters -- 
 *     -- struct binaryTree *tree1 -- The first tree who's value will be compared
 *     -- struct binaryTree *tree2 -- The second tree who's value will be compared
 * Function Returns -- This function will return a value less than 0, the value 0, or a value greater than 0 when, respectively tree1 is less than tree 2, tree1 is equivalent to tree2, or tree1 is greater than tree2.
 * Notes --
 */
long btDefaultCmp (struct binaryTree *tree1, struct binaryTree *tree2)
{
  long retVal = 0;

  long val1 = 0;
  long val2 = 0;

  if (tree1 && tree2)
    {
      /* To compare the values, we assume them to be longs */
      val1 = tree1->data.l;
      val2 = tree2->data.l;

      retVal = val2 - val1;
    }
  else if (tree1)
    retVal = 1;
  else
    retVal = -1;

  return retVal;
}

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 10:39:31 2021
 * Function Name -- btAddChar 
 * Function Purpose -- Adds a char value to the given binaryTree
 * Function Parameters -- 
 *     -- struct binaryTree **bt -- The binary tree who the data will be added to
 *     -- char data -- The char data value that will be added to the given binary tree
 *     -- long (*cmpFunc)(struct binaryTree *t1, struct binaryTree *t2) -- The compare function that will be used to determine where to put the given data value
 * Function Returns -- void
 * Notes --
 */
void btAddChar (struct binaryTree **bt, char data, long (*cmpFunc)(struct binaryTree *t1, struct binaryTree *t2))
{
  struct binaryTree *newCharNode = NULL;

  /* Ensure we have valid addresses to work with */
  if (bt && cmpFunc && (newCharNode = (struct binaryTree *)calloc (1, sizeof (struct binaryTree))))
    {
      newCharNode->data.c = data;
      newCharNode->size = 1;
      *bt = btInsertNode (*bt, newCharNode, cmpFunc);
    }
}

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 10:39:59 2021
 * Function Name -- btAddShort 
 * Function Purpose -- Adds a short value to the given binaryTree
 * Function Parameters -- 
 *     -- struct binaryTree **bt -- The binary tree who the data will be added to
 *     -- short data -- The short data value that will be added to the given binary tree
 *     -- long (*cmpFunc)(struct binaryTree *t1, struct binaryTree *t2) -- The compare function that will be used to determine where to put the given data value
 * Function Returns -- void
 * Notes --
 */
void btAddShort (struct binaryTree **bt, short data, long (*cmpFunc)(struct binaryTree *t1, struct binaryTree *t2))
{
  struct binaryTree *newShortNode = NULL;

  /* Ensure we have valid addresses to work with */
  if (bt && cmpFunc && (newShortNode = (struct binaryTree *)calloc (1, sizeof (struct binaryTree))))
    {
      newShortNode->data.s = data;
      newShortNode->size = 1;
      *bt = btInsertNode (*bt, newShortNode, cmpFunc);
    }
}

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 10:41:13 2021
 * Function Name -- btAddInt 
 * Function Purpose -- Adds an integer value to the given binaryTree
 * Function Parameters -- 
 *     -- struct binaryTree **bt -- The binary tree who the data will be added to
 *     -- int data -- The int data value that will be added to the given binary tree
 *     -- long (*cmpFunc)(struct binaryTree *t1, struct binaryTree *t2) -- The compare function that will be used to determine where to put the given data value
 * Function Returns -- void
 * Notes --
 */
void btAddInt (struct binaryTree **bt, int data, long (*cmpFunc)(struct binaryTree *t1, struct binaryTree *t2))
{
  struct binaryTree *newIntNode = NULL;

  /* Ensure we have valid addresses to work with */
  if (bt && cmpFunc && (newIntNode = (struct binaryTree *)calloc (1, sizeof (struct binaryTree))))
    {
      newIntNode->data.i = data;
      newIntNode->size = 1;
      *bt = btInsertNode (*bt, newIntNode, cmpFunc);
    }
}

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 10:42:01 2021
 * Function Name -- btAddLong 
 * Function Purpose -- Adds a long value to the given binaryTree
 * Function Parameters -- 
 *     -- struct binaryTree **bt -- The binary tree who the data will be added to
 *     -- long data -- The long data value that will be added to the given binary tree
 *     -- long (*cmpFunc)(struct binaryTree *t1, struct binaryTree *t2) -- The compare function that will be used to determine where to put the given data value
 * Function Returns -- void
 * Notes --
 */
void btAddLong (struct binaryTree **bt, long data, long (*cmpFunc)(struct binaryTree *t1, struct binaryTree *t2))
{
  struct binaryTree *newLongNode = NULL;

  /* Ensure we have valid addresses to work with */
  if (bt && cmpFunc && (newLongNode = (struct binaryTree *)calloc (1, sizeof (struct binaryTree))))
    {
      newLongNode->data.l = data;
      newLongNode->size = 1;
      *bt = btInsertNode (*bt, newLongNode, cmpFunc);
    }
}

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 10:42:48 2021
 * Function Name -- btAddPtr 
 * Function Purpose -- Adds a pointer value to the given binaryTree
 * Function Parameters -- 
 *     -- struct binaryTree **bt -- The binary tree who the data will be added to
 *     -- void *data -- The pointer that will be added to the given binary tree
 *     -- long (*cmpFunc)(struct binaryTree *t1, struct binaryTree *t2) -- The compare function that will be used to determine where to put the given data value
 * Function Returns -- void
 * Notes --
 */
void btAddPtr (struct binaryTree **bt, void *data, long (*cmpFunc)(struct binaryTree *t1, struct binaryTree *t2))
{
  struct binaryTree *newPtrNode = NULL;

  /* Ensure we have valid addresses to work with */
  if (bt && cmpFunc && (newPtrNode = (struct binaryTree *)calloc (1, sizeof (struct binaryTree))))
    {
      newPtrNode->data.ptr = data;
      newPtrNode->size = 1;
      *bt = btInsertNode (*bt, newPtrNode, cmpFunc);
    }
}

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 10:58:36 2021
 * Function Name -- btInsertNode 
 * Function Purpose -- Inserts the given newNode into the given srcTree using the provided compare function.
 * Function Parameters -- 
 *     -- struct binaryTree *srcTree -- The source tree to which the provided newNode will be attached to
 *     -- struct binaryTree *newNode -- The new node that will be attached to the given srcTree
 *     -- long (*cmpFunc)(struct binaryTree *t1, struct binaryTreee *t2) -- The compare function that will be used to determine the location of the newNode within the srcTree
 * Function Returns -- A pointer to the root of the source tree
 * Notes --
 */
struct binaryTree *btInsertNode (struct binaryTree *srcTree, struct binaryTree *newNode, long (*cmpFunc)(struct binaryTree *t1, struct binaryTree *t2))
{
  long cmpResult = 0;
  
  /* If we do not have an initial source tree */
  if (srcTree == NULL)
    /* No real work must be done, the newNode is the entire source tree */
    srcTree = newNode; 
  /* Otherwise, an we have a pre-existing source tree */
  /* Firstly, ensure we have valid addresses to work with */
  else if (srcTree && newNode && cmpFunc)
    {
      srcTree->size++;
      
      /* Compute the compare result */
      cmpResult = cmpFunc (srcTree, newNode);
      
      /* If the values of the srcTree and the newNode are equivalent or if the newNode is larger  */
      if (cmpResult <= 0)
	/* Insert the node to the left of the source node */
	srcTree->left = btInsertNode (srcTree->left, newNode, cmpFunc);
      else
	/* Insert the node to the right of the source node */
	srcTree->right = btInsertNode (srcTree->right, newNode, cmpFunc);
    }    
  
  return srcTree;
}

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 10:43:49 2021
 * Function Name -- btDestroyBt 
 * Function Purpose -- Releases the given binaryTree from memory
 * Function Parameters -- 
 *     -- struct binaryTree *bt -- The binaryTree who will be released from memory
 * Function Returns -- void
 * Notes --
 */
void btDestroyBt (struct binaryTree *bt)
{
  if (bt)
    {
      btDestroyBt (bt->left);
      btDestroyBt (bt->right);

      free (bt);
    }
}



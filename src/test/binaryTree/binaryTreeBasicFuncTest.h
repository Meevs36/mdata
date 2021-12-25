/*
 * Author -- Meevs
 * Creation Date -- Fri Dec 24 10:01:57 2021
 * File Name -- binaryTreeBasicFuncTest.h
 * Notes -- 
 */

#ifndef __BINARY_TREE_BASIC_FUNCTIONALITY_TEST__
#define __BINARY_TREE_BASIC_FUNCTIONALITY_TEST__

#include <check.h>

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 10:34:58 2021
 * Function Name -- btDefaultCmpNULLTreeTest0 
 * Function Purpose -- Tests the default compare function with a NULL value provided as the first argument
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (btDefaultCmpNULLTreeTest0)
{
  struct binaryTree *tree1 = NULL;
  struct binaryTree *tree2 = (struct binaryTree *)calloc (1, sizeof (struct binaryTree));

  ck_assert_ptr_eq (tree1, NULL);
  ck_assert_ptr_ne (tree2, NULL);

  ck_assert_int_lt (btDefaultCmp (tree1, tree2), 0);

  free (tree2);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 10:34:58 2021
 * Function Name -- btDefaultCmpNULLTreeTest1 
 * Function Purpose -- Tests the default compare function with a NULL value provided as the second argument
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (btDefaultCmpNULLTreeTest1)
{
  struct binaryTree *tree1 = (struct binaryTree *)calloc (1, sizeof (struct binaryTree));
  struct binaryTree *tree2 = NULL;

  ck_assert_ptr_ne (tree1, NULL);
  ck_assert_ptr_eq (tree2, NULL);

  ck_assert_int_gt (btDefaultCmp (tree1, tree2), 0);

  free (tree1);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 10:12:42 2021
 * Function Name -- btDefaultCmpFuncTestChar 
 * Function Purpose -- Tests the default compare function with chars
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (btDefaultCmpFuncTestChar)
{
  struct binaryTree *tree1 = (struct binaryTree *)calloc (1, sizeof (struct binaryTree));
  struct binaryTree *tree2 = (struct binaryTree *)calloc (1, sizeof (struct binaryTree));

  /* Ensure memory allocation was successful */
  ck_assert_ptr_ne (tree1, NULL);
  ck_assert_ptr_ne (tree2, NULL);

  /* Allocate character data to the new trees */
  tree1->data.c = 'a';
  tree2->data.c = 'b';

  /* Conduct test */
  ck_assert_int_gt (btDefaultCmp (tree1, tree2), 0);
  ck_assert_int_lt (btDefaultCmp (tree2, tree1), 0);

  /* Set both values of the tree equivalent to one another */
  tree1->data.c = tree2->data.c;

  /* Ensure that when the two values are equivalent, we get the expected value of 0 */
  ck_assert_int_eq (btDefaultCmp (tree1, tree2), 0);

  free (tree1);
  free (tree2);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 10:22:02 2021
 * Function Name -- btDefaultCmpFuncTestShort 
 * Function Purpose -- Tests the default compare function with short values
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (btDefaultCmpFuncTestShort)
{
  struct binaryTree *tree1 = (struct binaryTree *)calloc (1, sizeof (struct binaryTree));
  struct binaryTree *tree2 = (struct binaryTree *)calloc (1, sizeof (struct binaryTree));

  /* Ensure memory allocation was successful */
  ck_assert_ptr_ne (tree1, NULL);
  ck_assert_ptr_ne (tree2, NULL);

  /* Allocate data to both trees */
  tree1->data.s = 10;
  tree2->data.s = 15;

  /* Conduct the test */
  ck_assert_int_gt (btDefaultCmp (tree1, tree2), 0);
  ck_assert_int_lt (btDefaultCmp (tree2, tree1), 0);

  /* Set values of the trees equivalent to one another */
  tree1->data.s = tree2->data.s;

  /* Confirm default compare function returns 0 when values are equivalent */
  ck_assert_int_eq (btDefaultCmp (tree1, tree2), 0);

  /* Tidy up */
  free (tree1);
  free (tree2);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 10:22:02 2021
 * Function Name -- btDefaultCmpFuncTestInt 
 * Function Purpose -- Tests the default compare function with int values
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (btDefaultCmpFuncTestInt)
{
  struct binaryTree *tree1 = (struct binaryTree *)calloc (1, sizeof (struct binaryTree));
  struct binaryTree *tree2 = (struct binaryTree *)calloc (1, sizeof (struct binaryTree));

  /* Ensure memory allocation was successful */
  ck_assert_ptr_ne (tree1, NULL);
  ck_assert_ptr_ne (tree2, NULL);

  /* Allocate data to both trees */
  tree1->data.i = 10;
  tree2->data.i = 15;

  /* Conduct the test */
  ck_assert_int_gt (btDefaultCmp (tree1, tree2), 0);
  ck_assert_int_lt (btDefaultCmp (tree2, tree1), 0);

  /* Set values of the trees equivalent to one another */
  tree1->data.i = tree2->data.s;

  /* Confirm default compare function returns 0 when values are equivalent */
  ck_assert_int_eq (btDefaultCmp (tree1, tree2), 0);

  /* Tidy up */
  free (tree1);
  free (tree2);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 10:22:02 2021
 * Function Name -- btDefaultCmpFuncTestLong 
 * Function Purpose -- Tests the default compare function with long values
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (btDefaultCmpFuncTestLong)
{
  struct binaryTree *tree1 = (struct binaryTree *)calloc (1, sizeof (struct binaryTree));
  struct binaryTree *tree2 = (struct binaryTree *)calloc (1, sizeof (struct binaryTree));

  /* Ensure memory allocation was successful */
  ck_assert_ptr_ne (tree1, NULL);
  ck_assert_ptr_ne (tree2, NULL);

  /* Allocate data to both trees */
  tree1->data.l = 10;
  tree2->data.l = 15;

  /* Conduct the test */
  ck_assert_int_gt (btDefaultCmp (tree1, tree2), 0);
  ck_assert_int_lt (btDefaultCmp (tree2, tree1), 0);

  /* Set values of the trees equivalent to one another */
  tree1->data.l = tree2->data.s;

  /* Confirm default compare function returns 0 when values are equivalent */
  ck_assert_int_eq (btDefaultCmp (tree1, tree2), 0);

  /* Tidy up */
  free (tree1);
  free (tree2);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 11:09:58 2021
 * Function Name -- btInsertNodeTest0 
 * Function Purpose -- Tests the functionality of the insertNode function, handling a new node being provided to an empty tree
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (btInsertNodeTest0)
{
  struct binaryTree *srcTree = NULL;
  struct binaryTree *newNode = (struct binaryTree *)calloc (1, sizeof (struct binaryTree));

  ck_assert_ptr_ne (newNode, NULL);

  newNode->data.i = 10;

  srcTree = btInsertNode (srcTree, newNode, &btDefaultCmp);
  
  ck_assert_ptr_eq (srcTree, newNode);
  ck_assert_int_eq (srcTree->data.i, 10);

  free (newNode);
}

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 11:22:09 2021
 * Function Name -- btInsertNodeTest1 
 * Function Purpose -- Tests the functionality of the insertNode function, handling multiple new nodes being provided to an originally empty tree
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (btInsertNodeTest1)
{
  struct binaryTree *srcTree = NULL;
  struct binaryTree *newNode = NULL;
  const int elements [] = {15, 20, 10, 17, 0};
  int index = 0;

  /* Insert all elements into the binaryTree */
  for (index = 0; elements [index]; index++)
    {
      /* Allocate a new node */
      newNode = (struct binaryTree *)calloc (1, sizeof (struct binaryTree));
      ck_assert_ptr_ne (newNode, NULL);
      newNode->data.i = elements [index];

      /* Add the new node to the source tree */
      srcTree = btInsertNode (srcTree, newNode, &btDefaultCmp);
    }

  /* Conduct the test */
  ck_assert_ptr_ne (srcTree, NULL);
  ck_assert_int_eq (srcTree->data.i, 15);
  ck_assert_ptr_ne (srcTree->left, NULL);
  ck_assert_int_eq (srcTree->left->data.i, 10);
  ck_assert_ptr_ne (srcTree->right, NULL);
  ck_assert_int_eq (srcTree->right->data.i, 20);
  ck_assert_ptr_ne (srcTree->right->left, NULL);
  ck_assert_int_eq (srcTree->right->left->data.i, 17);

  btDestroyBt (srcTree);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 08:05:37 2021
 * Function Name -- btInitTest 
 * Function Purpose -- Tests the basic initialization of a binary tree
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (btInitTest)
{
  struct binaryTree *bt = NULL;

  btAddNode (bt, 10);

  ck_assert_ptr_ne (bt, NULL);
  ck_assert_int_eq (bt->data.i, 10);

  free (bt);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 08:19:42 2021
 * Function Name -- btGetSizeTest0 
 * Function Purpose -- Tests the functionality of the 'getSize' macro-function for a binary tree. This test is conducted with only one element.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (btGetSizeTest0)
{
  struct binaryTree *bt = NULL;

  btAddNode (bt, 10);

  ck_assert_ptr_ne (bt, NULL);
  ck_assert_int_eq (btGetSize (bt), 1);

  free (bt);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 08:22:30 2021
 * Function Name -- btGetSizeTest1 
 * Function Purpose -- Tests the functionality of the 'getSize' macro-function for a binaryTree. This test is conducted with more than one element.
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (btGetSizeTest1)
{
  struct binaryTree *bt = NULL;
  const int elements [] = {10, 20, 15, 0};
  int index = 0;

  for (index = 0; elements [index]; index++)
    btAddNode (bt, elements [index]);

  ck_assert_ptr_ne (bt, NULL);
  ck_assert_int_eq (btGetSize (bt), index);

  btDestroyBt (bt);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 08:29:28 2021
 * Function Name -- btCharTest 
 * Function Purpose -- Tests the functionality of the binary tree while handling chars
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (btCharTest)
{
  struct binaryTree *bt = NULL;
  struct binaryTree *tempPtr = NULL;
  const char elements [] = {'b', 'a', 'c', '\0'};
  int index = 0;

  for (index = 0; elements [index]; index++)
    btAddNode (bt, elements [index]);

  ck_assert_ptr_ne (bt, NULL);
  ck_assert_int_eq (btGetData (bt, char), 'b');
  ck_assert_ptr_ne (bt->left, NULL);
  ck_assert_int_eq (btGetData (bt->left, char), 'a');
  ck_assert_ptr_ne (bt->right, NULL);
  ck_assert_int_eq (btGetData (bt->right, char), 'c');

  btDestroyBt (bt);  
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 08:35:04 2021
 * Function Name -- btShortTest 
 * Function Purpose -- Tests the functionality of the binary tree while handling shorts
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (btShortTest)
{
  struct binaryTree *bt = NULL;
  const short elements [] = {15, 20, 10, 0};
  int index = 0;

  for (index = 0; elements [index]; index++)
    btAddNode (bt, elements [index]);

  ck_assert_ptr_ne (bt, NULL);
  ck_assert_int_eq (btGetData (bt, short), 15);
  ck_assert_ptr_ne (bt->left, NULL);
  ck_assert_int_eq (btGetData (bt->left, short), 10);
  ck_assert_ptr_ne (bt->right, NULL);
  ck_assert_int_eq (btGetData (bt->right, short), 20);

  btDestroyBt (bt);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 08:35:04 2021
 * Function Name -- btIntTest 
 * Function Purpose -- Tests the functionality of the binary tree while handling ints
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (btIntTest)
{
  struct binaryTree *bt = NULL;
  const int elements [] = {15, 20, 10, 0};
  int index = 0;

  for (index = 0; elements [index]; index++)
    btAddNode (bt, elements [index]);

  ck_assert_ptr_ne (bt, NULL);
  ck_assert_int_eq (btGetData (bt, int), 15);
  ck_assert_ptr_ne (bt->left, NULL);
  ck_assert_int_eq (btGetData (bt->left, int), 10);
  ck_assert_ptr_ne (bt->right, NULL);
  ck_assert_int_eq (btGetData (bt->right, int), 20);

  btDestroyBt (bt);
}
END_TEST

/*
 * Author -- Meevs
 * Creation Date -- Sat Dec 25 08:35:04 2021
 * Function Name -- btLongTest 
 * Function Purpose -- Tests the functionality of the binary tree while handling longs
 * Function Parameters -- 
 * Function Returns -- void
 * Notes --
 */
START_TEST (btLongTest)
{
  struct binaryTree *bt = NULL;
  const long elements [] = {15, 20, 10, 0};
  int index = 0;

  for (index = 0; elements [index]; index++)
    btAddNode (bt, elements [index]);

  ck_assert_ptr_ne (bt, NULL);
  ck_assert_int_eq (btGetData (bt, long), 15);
  ck_assert_ptr_ne (bt->left, NULL);
  ck_assert_int_eq (btGetData (bt->left, long), 10);
  ck_assert_ptr_ne (bt->right, NULL);
  ck_assert_int_eq (btGetData (bt->right, long), 20);

  btDestroyBt (bt);
}
END_TEST


#endif

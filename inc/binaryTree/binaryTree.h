/*
 * Author -- Meevs
 * Creation Date -- Fri Dec 24 09:56:08 2021
 * File Name -- binaryTree.h
 * Notes -- 
 */

#ifndef __BINARY_TREE__
#define __BINARY_TREE__

#include <stdlib.h>

typedef struct binaryTree binaryTree;

struct binaryTree
{
  unsigned int size;
  
  struct binaryTree *left;
  struct binaryTree *right;

  union
  {
    char c;
    short s;
    int i;
    long l;
    void *ptr;
  } data;
};


#define btAddNode(bt, data) btAddNodeCustom(bt, data, &btDefaultCmp)
#define btAddNodeCustom(bt, data, cmpFunc)				\
  {									\
    _Pragma ("GCC diagnostic push")					\
      _Pragma ("GCC diagnostic ignored \"-Wint-to-pointer-cast\"")	\
      _Pragma ("GCC diagnostic ignored \"-Wpointer-to-int-cast\"")	\
      _Generic (data,							\
		char: btAddChar (&bt, (char)data, cmpFunc),		\
		short: btAddShort (&bt, (short)data, cmpFunc),		\
		int: btAddInt (&bt, (int)data, cmpFunc),		\
		long: btAddLong (&bt, (long)data, cmpFunc),		\
		default: btAddPtr (&bt, (void *)data, cmpFunc));	\
    _Pragma ("GCC diagnostic pop")					\
      }

#define btGetData(bt, type) (type)btGetDataBase (bt)

long btDefaultCmp (struct binaryTree *tree1, struct binaryTree *tree2);
unsigned int btGetSize (struct binaryTree *bt);
long btGetDataBase (struct binaryTree *bt);
void btAddChar (struct binaryTree **bt, char data, long (*cmpFunc)(struct binaryTree *t1, struct binaryTree *t2));
void btAddShort (struct binaryTree **bt, short data, long (*cmpFunc)(struct binaryTree *t1, struct binaryTree *t2));
void btAddInt (struct binaryTree **bt, int data, long (*cmpFunc)(struct binaryTree *t1, struct binaryTree *t2));
void btAddLong (struct binaryTree **bt, long data, long (*cmpFunc)(struct binaryTree *t1, struct binaryTree *t2));
void btAddPtr (struct binaryTree **bt, void *data, long (*cmpFunc)(struct binaryTree *t1, struct binaryTree *t2));
struct binaryTree *btInsertNode (struct binaryTree *srcTree, struct binaryTree *newNode, long (*cmpFunc)(struct binaryTree *t1, struct binaryTree *t2));
void btDestroyBt (struct binaryTree *bt);

#endif

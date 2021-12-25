# MData Binary Tree

A generic binary tree implemented in C

---

## The Binary Tree Data Structure

```C
  struct binaryTree
  {
    unsigned int size;

    struct binaryTree *left;
    struct binaryTree *right;

    union data
    {
      char c;
      short s;
      int i;
      long l;
      void *ptr;
    } data;
  };
```

## Binary Tree Functions

- `btAddNode (struct binaryTree *bt, data)` is a macro-function that enables the user to add the given data value to the given binary tree. It should be noted that this function should only be used with simple data values (char, short, int, long). If the intention is to use this with complex data structures, or pointers, the user should refer to the `btAddNodeCustom` function defined below.

- `btAddNodeCustom (struct binaryTree *bt, data, long (*cmpFunc)(struct binaryTree *t1, struct binaryTree *t2))` is a macro function much like the `btAddNode` function. The primary difference between this function and `btAddNode` is this function requires the user to specify the comparison function used when sorting the binary tree. `btAddNode` uses a default comparison function which works well with simple data types. If the user intends to use the binary tree with complex data structures, they must provide their own comparison function. This function is called whenever a new node is being added to the tree to determine where in the tree it belongs. The comparison function should return a long value less than zero if the new data value is less than the current. 0 if they are equivalent, and a long value greater than zero if the new data value is greater than the current.

- `btGetSize (struct binaryTree *bt)` is a macro-function that allows a user to easily determine how many nodes are in the given binary tree.

- `btGetData (struct binaryTree *bt, type)` is a macro-function that enables the user to easily extract data casted to the given type from the given binary tree node.

- `btDestroyBt (struct binaryTree *bt)` is a function that allows for the easy deallocation of the given binary tree.

## Example

The below example demonstrates how to initialize a binary tree:

```C
  long x = 15;
  long z = 17;

  struct binaryTree *bt = NULL;

  btAddNode (bt, x);
  btAddNode (bt, 20);
  btAddNode (bt, z);

  printf ("BT node: %ld\r\n", btGetData (bt, long));
  printf ("BT->right node: %ld\r\n", btGetData (bt->right, long));
  printf ("BT->right->left node: %ld\r\n", btGetData (bt->right->left, long));

  btDestroyBt (bt);
```

The above code would yield the following output:

```bash
  BT node: 15
  BT->right node: 20
  BT->right->left node: 17
```
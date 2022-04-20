# MData Stacky

A generic stack implemented in C

---

## The Stacky Data Structure

```C
struct stacky
{
  union data
  {
    char c;
    short s;
    int i;
    long l;
    void *ptr;
  } data;

  struct stacky *next;
};
```

## Stacky Functions

- `stackyPush (struct stacky *stackPtr, data)` is a convienence macro-function enabling users to push data onto a Stacky stack. This function does not return anything.

- `stackyPop (struct stacky *stackPtr, type)` is a convienence macro-function enabling users to pop data off of a Stacky stack. This function will return the data value from the top of the stack, casted to the specified type.

- `stackyPeak (struct stacky *stackPtr, type)` is a convienence macro-function enabling users to look at the data value on the top of the stack casted to the specified type, without removing that value from the stack.

- `stackyIsEmpty (struct stacky *stackPtr)` is a function allowing users to easily determine whether or not the given stack is empty or not. This function will return 1 if the given Stacky stack is empty, or 0 if it is not.

- `stackyDestroyStack (struct stacky *stack)` is a function that allows for easy disposal of a stack. This function will release all memory allocated to the given stack.

## Example

The below example demonstrates how a user could initialize a Stacky stack of chars, and printing them to the command line.

```C

  char x = 'a';
  char z = 'c';

  struct stacky *stack = NULL;

  stackyPush (stack, x);
  stackyPush (stack, 'b');
  stackyPush (stack, z);

  printf ("Current value at the top of the stack: '%c'\r\n", stackyPeak (stack, char));

  while (!stackyIsEmpty (stack))
    printf ("Popping value: '%c'\r\n", stackyPop (stack, char));

  /* Since we already popped everything off of the stack, destroying it in this case would be unrequired. */
  /* The next function call is simply here for demonstration */
  stackyDestroyStack (stack);
```

The expected output would be:

```bash
 Current value at the top of the stack: 'c'
 Popping value: 'c'
 Popping value: 'b'
 Popping value: 'a'
```
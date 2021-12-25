# MData Queue

A generic queue implemented in C

---

## The Queue Data Structure

```C
struct queue
{
  unsigned int size;
  union data
  {
    char c;
    short s;
    int i;
    long l;
    void *ptr;
  } data;

  struct queue *next;
};
```

## Queue Functions

- `queueEnqueue (struct queue *queue, data)` is a convienience macro-function that enables users to enqueue data into the queue.

- `queueDequeue (struct queue *queue, type)` is a convienience macro-function that enables users to dequeue data casted to the given type from the queue.

- `queueGetSize (struct queue *queue)` is a convienience macro-function that allows the user to easily determine the current size of the given queue.

- `queueFront (struct queue *queue, type)` is a convienience macro-function allowing the user to look at the data value casted to the given type that is currently at the front of the given queue.

- `queueRear (struct queue *queue, type)` is a convienience macro-function that allows the user to look at the data value casted to the given type that is currently at the back of the given queue.

- `queueDestroyQueue (struct queue *queue)` is a function that allows for easy deallocate the memory associated with the given queue.

## Example

Provided is an example of how to initialize a queue with short values:

```C
  short x = 0;
  short z = 13;

  struct queue *queue = NULL;

  queueEnqueue (queue, x);
  queueEnqueue (queue, 20);
  queueEnqueue (queue, z);

  printf ("Current value at the front of the queue: %d\r\n", queueFront (queue, short));
  printf ("Current value at the rear of the queue: %d\r\n", queueRear (queue, short));

  while (0 < queueGetSize (queue))
    printf ("Dequeing value: %d\r\n", queueDequeue (queue, short));

  queueDestroyQueue (queue);
```

The expected output would be:

```bash
  Current value at the front of the queue: 0
  Current value at the rear of the queue: 13
  Dequeing value: 0
  Dequeing value: 20
  Dequeing value: 13
```
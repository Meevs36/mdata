# Linky

A generic linked list implemented in C.

---

## The Linky Data Structure

The Linky data structure is defined as follows:

```
  struct linky
  {
    unsigned int size;
    void *data;

    struct linky *next;
    struct linky *prev;
  };
```

## Linky Functions

- `linkyAddNode (struct linky *list, data)` is a convenience macro that will append the given data value to the given list.
If `list` is `NULL` the function will initialize a new Linky list for you.
`data` can be of any type (with the exception of `float` or `double` for the time being.

- `linkyGetData (struct linky *list, type)` is a convenience macro that will retrieve the data at the given node.
The expected data `type` must be provides, meaning the user is reponsible for maintaining the type integrity of the Linky lists they create.

- `linkyDestroyList (struct linky *list)` will release all allocated memory associated with the list.
User allocated memory that is appended to the list will not be released, it is expected the user will handle this.

## Example

Provided is an example of a Linky list being used to store multiple integers.

```
  int x = 5;
  int z = 15;

  struct linky *list = NULL;
  struct linky *temp = NULL;

  linkyAddNode (list, x); /* Initializes the Linky list */
  linkyAddNode (list, 10); /* Following calls append the data to the end of the list */
  linkyAddNode (list, z);

  /* Print all integers stored in the Linky list */
  for (temp = list; temp; temp = temp->next)
    printf ("%d\r\n", linkyGetData (temp, int));

  linkyDestroyList (list); /* Clean up memory allocated by Linky */
```




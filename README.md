## Dlist
Dlist is a templated, doubly-linked, double-ended container list. It supports the following operational methods:

  * isEmpty: a predicate that returns true if the list is empty, false otherwise
  * clear: remove all items in the Dlist
  * insertFront/insertBack: insert an object at the front/back of the list, respectively
  * removeFront/removeBack: remove an object from the front/back of a non-empty list, respectively; throws an exception if the list is empty.
  * peekFront/peekBack: get an object form the front/back of the Dlist. Returns NULL if the list is empty

## Simple RPN Calculator
A RPN ([Reverse-Polish Notation](http://en.wikipedia.org/wiki/Reverse_Polish_notation)) calculator uses a postfix notation for computation, which can be easily implemented using a stack. This RPN calculator uses a DList as a stack and offers simple list of commands.

To run the calculator:

    g++ calc.cc
    ./calc
#ifndef __DLIST_H__
#define __DLIST_H__

class emptyList {};

template <typename T>
class Dlist {
public:
  Dlist() { this->makeEmpty(); }
  Dlist(const Dlist &l);
  Dlist& operator=(const Dlist& l);
  ~Dlist() { removeAll(); }

  bool isEmpty() { return first == NULL && last == NULL; }
  
  void insertFront(T* o);
  void insertBack(T* o);
  T* peekFront();
  T* peekBack();
  T* removeFront();
  T* removeBack();
  
  void clear() { this->removeAll(); }

private:
  struct Node {
    Node* next;
    Node* prev;
    T* o;
    Node(T*);
  };

  Node* first;
  Node* last;

  void makeEmpty() { first = last = NULL; }
  void removeAll();
  void copyAll(const Dlist &l);
};

/*
Note: this is here *only* because the gnu compiler needs to see the
"templatized" versions of your methods.  This is the *only* instance
in which it is acceptable to #include a cc file.
*/

#include "dlist.cc"

#endif /* __DLIST_H__ */

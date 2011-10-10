#ifndef __DLIST_H__
#define __DLIST_H__

class emptyList {
    // OVERVIEW: an exception class
};

template <typename T>
class Dlist {
    // OVERVIEW: contains a double-ended list of Objects

 public:

    // Operational methods

    bool isEmpty();
    // EFFECTS: returns true if list is empy, false otherwise

    void insertFront(T *o);
    // MODIFIES this
    // EFFECTS inserts o at the front of the list
    
    void insertBack(T *o);
    // MODIFIES this
    // EFFECTS inserts o at the back of the list

    T *removeFront();
    // MODIFIES this
    // EFFECTS removes and returns first object from non-empty list
    //         throws an instance of emptyList if empty

    T *removeBack();
    // MODIFIES this
    // EFFECTS removes and returns last object from non-empty list
    //         throws an instance of emptyList if empty

    // Maintenance methods
    Dlist();                                   // ctor
    Dlist(const Dlist &l);                     // copy ctor
    Dlist &operator=(const Dlist &l);          // assignment
    ~Dlist();                                  // dtor

 private:
    // A private type
    struct node {
	node   *next;
	node   *prev;
	T      *o;
    };

    node   *first; // The pointer to the 1st node (NULL if none)
    node   *last;  // The pointer to the 2nd node (NULL if none)

    // Utility methods

    void makeEmpty();
    // EFFECT: called by constructors/operator= to establish empty
    // list invariant
    
    void removeAll();
    // EFFECT: called by destructor/operator= to remove and destroy
    // all list elements

    void copyAll(const Dlist &l);
    // EFFECT: called by copy constructor/operator= to copy elements
    // from a source instance l to this instance
};

/*
Note: this is here *only* because the gnu compiler needs to see the
"templatized" versions of your methods.  This is the *only* instance
in which it is acceptable to #include a cc file.
*/

#include "dlist.cc"

#endif /* __DLIST_H__ */

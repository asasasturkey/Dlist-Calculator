template <typename T>
Dlist<T>::Node::Node(T* o) {
  this->o = o;
}

template <typename T>
Dlist<T>::Dlist(const Dlist &l) {
  this->makeEmpty();
  this->copyAll(l);
}

template <typename T>
Dlist<T>& Dlist<T>::operator= (const Dlist &l) {
  removeAll();
  copyAll(l);
  return *this;
}

template <typename T>
void Dlist<T>::removeAll() {
  while(!this->isEmpty())
    this->removeFront();
}

template <typename T>
void Dlist<T>::copyAll(const Dlist &l) {
  Node* copyNode = l.first;
  while(copyNode != NULL) {
    this->insertBack(new T(*(copyNode->o)));
    copyNode = copyNode->next;
  }
}

template <typename T>
void Dlist<T>::insertFront(T* o) {
  Node* newNode = new Node(o);
  if (this->isEmpty()) {
    first = newNode;
    first->prev = NULL;
    first->next = NULL;
    last = first;
  }
  else {
    first->prev = newNode;
    newNode->next = first;
    newNode->prev = NULL;
    first = first->prev;
  }
}

template <typename T>
void Dlist<T>::insertBack(T* o) {
  Node* newNode = new Node(o);
  if (this->isEmpty()) {
    last = newNode;
    last->prev = NULL;
    last->next = NULL;
    first = last;
  }
  else {
    last->next = newNode;
    newNode->prev = last;
    newNode->next = NULL;
    last = last->next;
  }
}

template <typename T>
T* Dlist<T>::removeFront() {
  if (this->isEmpty())
    throw emptyList();
  else {
    Node* front = first;
    if (first->next)
      this->makeEmpty();
    else {
      first = first->next;
      first->prev = NULL;
    }
    T* o = front->o;
    delete front;
    return o;
  }
}

template <typename T>
T* Dlist<T>::removeBack() {
  if (this->isEmpty())
    throw emptyList();
  else {
    Node* back = last;
    if (last->prev)
      this->makeEmpty();
    else {
      last = last->prev;
      last->next = NULL;
    }
    T* o = back->o;
    delete back;
    return o;
  }
}
template <typename T>
bool Dlist<T>::isEmpty() {
  return first == NULL && last == NULL;
}

template <typename T>
void Dlist<T>::insertFront(T* o) {
  node* temp = new node;
  temp->o = o;
  if (this->isEmpty()) {
    first = temp;
    first->prev = NULL;
    first->next = NULL;
    last = first;
  }
  else {
    first->prev = temp;
    temp->next = first;
    temp->prev = NULL;
    first = first->prev;
  }
}

template <typename T>
void Dlist<T>::insertBack(T* o) {
  node* temp = new node;
  temp->o = o;
  if (this->isEmpty()) {
    last = temp;
    last->prev = NULL;
    last->next = NULL;
    first = last;
  }
  else {
    last->next = temp;
    temp->prev = last;
    temp->next = NULL;
    last = last->next;
  }
}

template <typename T>
T* Dlist<T>::removeFront() {
  if (this->isEmpty())
    throw emptyList();
  else {
    node* temp = first;
    if (first->next == NULL) //only one element in the list
      this->makeEmpty();
    else {
      first = first->next;
      first->prev = NULL;
    }
    T* o = temp->o;
    delete temp;
    return o;
  }
}

template <typename T>
T* Dlist<T>::removeBack() {
  if (this->isEmpty())
    throw emptyList();
  else {
    node* temp = last;
    if (last->prev == NULL) //only one element in the list
      this->makeEmpty();
    else {
      last = last->prev;
      last->next = NULL;
    }
    T* o = temp->o;
    delete temp;
    return o;
  }
}

template <typename T>
Dlist<T>::Dlist() { this->makeEmpty(); }

template <typename T>
Dlist<T>::Dlist(const Dlist &l) {
  this->makeEmpty();
  copyAll(l);
}

template <typename T>
Dlist<T>& Dlist<T>::operator = (const Dlist &l) {
  removeAll();
  copyAll(l);
  return *this;
}
template <typename T>
Dlist<T>::~Dlist() {
  removeAll();
}

template <typename T>
void Dlist<T>::makeEmpty() {
  first = NULL;
  last = NULL;
}

template <typename T>
void Dlist<T>::removeAll() {
  node* current;
  while(first != NULL) {
    current = first;
    first = first->next;
    delete current->o;
    delete current;
  }
  current = NULL;
  first = NULL;
  last = NULL;
}

template <typename T>
void Dlist<T>::copyAll(const Dlist &l) {
  node* copyNode = l.first;
  T* obj;
  while(copyNode != NULL) {
    obj = new T(*(copyNode->o));
    insertBack(obj);
    copyNode = copyNode->next;
  }
  obj = NULL;
}
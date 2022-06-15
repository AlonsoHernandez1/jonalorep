#ifndef LIST
#define LIST

#include "ListItem.h"

template<typename T>
class List {
private:
  ListItem<T>* first;
  int mSize;
 
  ListItem<T>* getLastItem() {
    if(first == nullptr) {
      return nullptr;
    }
    ListItem<T>* ptr = first;
    while(ptr->getNext() != nullptr) {
      ptr = ptr->getNext();
    }
    return ptr;
  }

public:
  List(){
    first = nullptr;
    mSize = 0;
  }

  ~List(){
    delete first;
  }

  int getSize(){
    return mSize;
  }

  void add(T item){
    //Create a copy on dynamic memory of the item passed.
    T* ptr = new T(item);
    ListItem<T>* newItem = new ListItem<T>(ptr);
    ListItem<T>* lastItem = getLastItem();
    if(lastItem == nullptr){
      first = newItem;
    } else {
      lastItem->setNext(newItem);
    }
    mSize++;
  }
  
  T* getAt(int i){
    if (i >= mSize) {
      return nullptr;
    }
    ListItem<T>* ptr = first;
    for(int j = 0; j < i; j++) {    
      ptr = ptr->getNext();
    }
    return ptr->getElement();
  }

};

#endif
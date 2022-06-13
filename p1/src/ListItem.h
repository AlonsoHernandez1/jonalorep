#ifndef LIST_ITEM
#define LIST_ITEM

template<typename T>
class ListItem {
private:
  T* mElement;
  ListItem* mNext;
public:

  ListItem(T* pElement){ 
    mElement = pElement;
    mNext = nullptr;
  }

  ~ListItem(){
    delete mElement;
    delete mNext;    
  }

  T* getElement(){
    return mElement;
  }

  ListItem<T>* getNext(){
    return mNext;
  }

  void setNext(ListItem<T>* pNext){
    mNext = pNext;
  }

};

#endif
  

  

  

  
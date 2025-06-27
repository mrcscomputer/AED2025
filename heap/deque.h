#ifndef Deque_H 
#define Deque_H
template <class T>
class Node{
  T m_data;
  Node* next;
  Node* prev;
  
  public:

  Node (T _data){
    m_data=_data;
    next=nullptr;
    prev=nullptr;
  }
};


template <class T>
class Deque{
  private:
  Node<T>* head;
  Node<T>* tail;
  unsigned int size;  
  public:
  void insertAtBegin (T);
  void insertAtEnd (T);
  void removeFromBegin();
  void removeFromEnd();
  T getBegin();
  T getEnd();
  bool isEmpty();
};

#endif

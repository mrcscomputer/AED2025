#include "deque.h"

void Deque::insertAtBegin(T val){
  Node<T>* node=new Node<T>(val);
  if (isEmpty()){
    head=node;
    tail=node;
  }else{
    node->next=head;
    head->prev=node;
    head=node;
  }
  size++;
}

void Deque::insertAtEnd(T val){
  Node<T>* node=new Node<T>(val);
  if (isEmpty()){
    head=node;
    tail=node;
  }else{
    tail->next=node;
    node->prev=tail;
    tail=node;
  }
  size++;
}

bool Deque::isEmpty(){
  return head==nullptr;
}
 
void Deque::removeFromBegin(){
  if(isEmpty())
    return;
  
  Node*<T> tmp=head;
  head=head->next;
  if(head){
    tail=nullptr;
    delete tmp;
  }
  else{
    head->prev=nullptr;
    head=head->next;
    delete tmp;
  }
  size--;
}

void Deque::removeFromEnd(){
  if(isEmpty())
    return;
  else{
    Node*<T> tmp=tail;
    tail->prev->next=nullptr;
    tail=tail->prev;
    delete tmp;
  }
  size--;
}


#include <iostream>
using namespace std;

class Node {
  int m_data;
  Node *m_next;
  Node *m_prev;
  friend class dLinkedList;  // Para que dLinkedList pueda acceder
public:
  Node(int data) : m_data(data), m_next(nullptr), m_prev(nullptr) {}
};

class dLinkedList {
  Node *m_head;
  Node *m_tail;

public:
  dLinkedList() : m_head(nullptr), m_tail(nullptr) {}
  ~dLinkedList();
  bool insert(int data);
  bool find(int data, Node **&pointer, Node *&prev);
  bool remove(int data);
  void print();
  void printReverse();
};

bool dLinkedList::find(int data, Node **&pointer, Node *&previous) {
  pointer = &m_head;
  previous = nullptr;

  while (*pointer && (*pointer)->m_data < data) {
    previous = *pointer;
    pointer = &((*pointer)->m_next);
  }

  return *pointer && (*pointer)->m_data == data;
}

bool dLinkedList::insert(int data) {
  Node **pointer;
  Node *previous;

  find(data, pointer, previous);  // Corrige: llamada correcta

  Node *nodo = new Node(data);
  Node *temporal = *pointer;
  *pointer = nodo;
  nodo->m_next = temporal;

  if (temporal) {
    nodo->m_prev = temporal->m_prev;
    temporal->m_prev = nodo;
  } else {
    nodo->m_prev = previous;
    m_tail = nodo;
  }

  if (nodo->m_prev == nullptr) {
    m_head = nodo;  // Si no hay anterior, es el nuevo head
  }

  return true;
}

bool dLinkedList::remove(int data) {
  Node **pointer;
  Node *previous;

  if (!find(data, pointer, previous)) {
    return false;
  }

  Node *temporal = *pointer;
  *pointer = temporal->m_next;

  if (*pointer) {
    (*pointer)->m_prev = temporal->m_prev;
  } else {
    m_tail = previous;
  }

  delete temporal;
  return true;
}

void dLinkedList::print() {
  Node *pointer = m_head;
  while (pointer) {
    cout << pointer->m_data << " ";
    pointer = pointer->m_next;
  }
  cout << endl;
}
void dLinkedList::printReverse() {
  Node *pointer = m_tail;
  while (pointer) {
    cout << pointer->m_data << " ";
    pointer = pointer->m_prev;
  }
  cout << endl;
}

dLinkedList::~dLinkedList() {
  while (m_head) {
    Node *temporal = m_head;
    m_head = m_head->m_next;
    delete temporal;
  }
}

int main() {
  cout << "Hola mundo" << endl;
  dLinkedList *linkedList = new dLinkedList();

  linkedList->insert(10);
  linkedList->insert(5);
  linkedList->insert(15);
  linkedList->insert(20);
  linkedList->insert(25);
  linkedList->insert(70);

  cout << "Lista: ";
  linkedList->print();

  linkedList->remove(15);
  cout << "Lista después de eliminar 15: ";
  linkedList->print();
  cout << "Impresión en reversa: ";
  linkedList->printReverse();


  delete linkedList;
  return 0;
}


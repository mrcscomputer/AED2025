#include <iostream>
using namespace std;

class Node {
  public:
  int m_data;
  Node *m_next;

//public:
  Node(int data) : m_data(data), m_next(nullptr) {}  // Constructor

//  friend class LinkedList;  // Para que LinkedList pueda acceder a m_data y m_next
};

class LinkedList {

  Node *m_head;
public:
  LinkedList() : m_head(nullptr) {}  // Constructor por defecto
  ~LinkedList();  // Destructor
  bool insert(int data);
  bool find(int data, Node **&pointer);
  bool remove(int data);
  void print();
};

bool LinkedList::insert(int data) {
  Node **pointer = &m_head;
  Node *temporal = *pointer;
  *pointer = new Node(data);
  (*pointer)->m_next = temporal;
  return true;
}

void LinkedList::print() {
  Node *pointer = m_head;
  while (pointer) {
    cout << pointer->m_data << " ";
    pointer = pointer->m_next;
  }
  cout << endl;
}

bool LinkedList::find(int data, Node **&pointer) {
  pointer = &m_head;
  while (*pointer && (*pointer)->m_data != data) {
    pointer = &((*pointer)->m_next);
  }
  return *pointer != nullptr;  // Si encontramos el nodo, return true
}

bool LinkedList::remove(int data) {
  Node **pointer = nullptr;
  if (!find(data, pointer)) {
    return false;  // No se encuentra el dato
  }
  Node *temporal = *pointer;
  *pointer = (*pointer)->m_next;
  delete temporal;
  return true;
}

LinkedList::~LinkedList() {
  // Limpiar la lista al destruir el objeto
  while (m_head) {
    Node *temporal = m_head;
    m_head = m_head->m_next;
    delete temporal;
  }
}

int main() {
  cout << "Hola mundo" << endl;
  LinkedList *linkedList = new LinkedList();
  
  linkedList->insert(10);
  linkedList->insert(5);
  linkedList->insert(15);
  linkedList->insert(20);
  linkedList->insert(25);
  linkedList->insert(70);
  cout << "Lista: ";
  linkedList->print();

  linkedList->remove(15);  // Eliminar el nodo con valor 10
  cout << "Lista después de eliminar 10: ";
  linkedList->print();

  delete linkedList;
  return 0;
}


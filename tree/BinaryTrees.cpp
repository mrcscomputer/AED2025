#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T m_data;
    Node<T>* children[2];

    Node(T data) {
        m_data = data;
        children[0] = children[1] = nullptr;
    }
};

template <class T>
class BTree {
private:
    Node<T>* root;

    bool find(int, Node<T>**&);
    void go_to(Node<T>**&);
    void print(Node<T>*);

public:
    BTree();
    ~BTree();
    bool insert(int);
    bool remove(int);
    void print();
};

template <class T>
BTree<T>::BTree() {
    root = nullptr;
}

template <class T>
BTree<T>::~BTree() {
}

template <class T>
bool BTree<T>::insert(int _data) {
    Node<T>** pointer;
    if (find(_data, pointer))
        return false;
    *pointer = new Node<T>(_data);
    return true;
}

template <class T>
bool BTree<T>::find(int _data, Node<T>**& p) {
    p = &root;
    while (*p) {
        if (_data == (*p)->m_data)
            return true;
        if (_data > (*p)->m_data)
            p = &((*p)->children[1]);
        else
            p = &((*p)->children[0]);
    }
    return false;
}

template <class T>
bool BTree<T>::remove(int _data) {
    Node<T>** p;
    if (!find(_data, p))
        return false;

    if ((*p)->children[0] != nullptr && (*p)->children[1] != nullptr) {
        Node<T>** q = p;
        go_to(q);
        (*p)->m_data = (*q)->m_data;
        p = q;
    }

    Node<T>* temp = *p;
    int idx = ((*p)->children[1] != nullptr) ? 1 : 0;
    *p = (*p)->children[idx];
    delete temp;
    return true;
}

template <class T>
void BTree<T>::go_to(Node<T>**& q) {
    q = &((*q)->children[1]);
    while ((*q)->children[0] != nullptr) {
        q = &((*q)->children[0]);
    }
}

template <class T>
void BTree<T>::print(Node<T>* n) {
    if (n == nullptr)
        return;
    print(n->children[0]);
    cout << n->m_data << " ";
    print(n->children[1]);
}

template <class T>
void BTree<T>::print() {
    print(root);
    cout << endl;
}

int main() {
    BTree<int>* arbol = new BTree<int>();
    arbol->insert(50);
    arbol->insert(0);
    arbol->insert(-25);
    arbol->insert(25);
    arbol->insert(-10);
    arbol->insert(-15);
    arbol->insert(100);
    arbol->insert(75);
    arbol->insert(60);
    arbol->insert(87);
    arbol->insert(150);
    arbol->insert(120);
    arbol->insert(110);

    arbol->print();
    arbol->remove(50);
    arbol->print();

    delete arbol;
    return 0;
}

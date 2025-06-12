#include <iostream>
using namespace std;

template <class T>
class Node {
	T m_data;
	Node <T> *children[2];
}

template <class T>

class BTree{
	private:
	Node<T> *root;
	public:
	BTree();
	~BTree();
	bool insert(int);
	bool remove(int);
	bool find(int, Node **&);
	void print();
}
BTree:: BTree()

bool BTree::insert(int _data){
	Node ** pointer;
	if (find(_data, pointer)
		return false;
	*pointer=new Node(m_data);
       }

bool BTree::find(int _data, Node **&p){
	p=&(root);
	while (*p && (*p)->m_data){
		if(_data > (*p)->m_data)
			p=&(*p)->m_data;
		else
			p=&(*p)->children[0];
	}
	return false;
       }
       
bool BTree::remove(int _data){
	Node<T> **p;
	if (!find(_data, p)){
		return false;
	}
	if ((*p)->children[0]!=nullptr && (*p)->children[1]!=nullptr){
		Node<T> **q=p;
		go_to(q);
		(*p)->m_data=(*q)->m_data;
		p=q;
	}
	Node <T> *temp=*p;
	int idx=(*p)->children[1]!=nullptr;
	*p=(*p)->children[idx];
	delete temp;
	return true;
}
void go_to(Node **&q){
	q=&((*q)->children[1]);
		while ((*q)->children[0]!=nullptr) {
			q=&((*q)->children[0]);
		}
}

void BTree::print(Node<T> *n){
	if(n=nullptr)
		return;
	print(n->children[0]);
	cout<<n->m_data<<" ";
	print(n->children[1]);
	}
int main(){
  Btree* arbol=new Btree();
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

	return 0;
}

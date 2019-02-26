/* Include more information
*
*
*/

#include <iostream>
#include <string>

template <class type>
struct Node<type>{
	Node();
	~Node();
	type* next;
	type* data;
};

Node::Node(){
	next = NULL;
	data = NULL;
}

Node::~Node(){
	delete next;
	delete prev;
	delete data;
}


template <class type>
class LinkedList<type>{
	Node<type>* current;
	Node<type>* head;
	void destoryList();
	
	
	public:
	LinkedList();
	~LinkedList();
	void insert(type data);
	Node<type>* rBegin();
	void assign(type data);
	
};

// INSERT DESCRIPTIONS
template <class type>
void insert(type data){
	// INSERT DATA
}

template <class type>
Node<type>* rBegin(){ return head; }

template <class type>
void assign(type data){
	// CHANGE THE DATA HERE
}

void destoryList(){
	// destroy the list by removing either head to tail in recursive fashion (make sure its reverse recursion)
}
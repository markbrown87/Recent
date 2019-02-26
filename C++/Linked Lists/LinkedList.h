/* Include more information
*
*
*/

#include <iostream>
#include <string>

#ifndef __LINKEDLISTS_H__
#define __LINKEDLISTS_H__

template <class type>
struct Node{
	Node();
	~Node();
	type* next;
	type* data;
};

template <class type>
Node<type>::Node(){
	next = NULL;
	data = NULL;
}

template <class type>
Node<type>::~Node(){
	delete next;
	delete data;
}


template <class type>
class LinkedList{
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
void LinkedList<type>::insert(type data){
	Node<type>* temp;
	temp = new Node<type>;
	
	if(current == NULL){
		temp -> data = data;
		temp -> next = NULL;
		current = temp;
		head = current;
	} else if (current -> next = NULL){
		temp -> data = data;
		temp -> next = NULL;
		current -> next = temp;
		current = temp;
	} else 
		std::cout << "Error inserting data into list -> please resolve...\n";
}

template <class type>
Node<type>* LinkedList<type>::rBegin(){ return head; }

template <class type>
void LinkedList<type>::assign(type data){
	// CHANGE THE DATA HERE
}

template <class type>
void LinkedList<type>::destoryList(){
	// destroy the list by removing either head to tail in recursive fashion (make sure its reverse recursion)
}

#endif
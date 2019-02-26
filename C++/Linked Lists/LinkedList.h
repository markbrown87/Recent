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
	void destoryList(Node<type>* ticker);
	
	
	public:
	LinkedList();
	~LinkedList();
	void insert(type data);
	Node<type>* rBegin();
	void assign(type data);
	
};

// Inserts data into the list
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

// Constructor/Destructor
template <class type>
LinkedList<type>::LinkedList(){
	Node<type>* tmp;
	tmp = new Node<type>;
	
	tmp -> next = NULL;
	tmp -> data = NULL;
	
	head = tmp;
	current = head;
}
template <class type>
LinkedList<type>::~LinkedList(){
	destoryList(head);
}

// returns the head of the list
template <class type>
Node<type>* LinkedList<type>::rBegin(){ return head; }

// overwrites the data in the 'current' node
template <class type>
void LinkedList<type>::assign(type data){ current -> data = data; }

// destroys the list
template <class type>
void LinkedList<type>::destoryList(Node<type>* ticker){
	// destroy the list by removing either head to tail in recursive fashion (make sure its reverse recursion)
	Node<type>* troy;
	troy = ticker -> next;

	if(troy == NULL){
		std::cout << "List Destroyed...\n";
		return; // Destroyed!!
	} else {
		delete ticker;
		
		destoryList(troy);
	}
}

#endif
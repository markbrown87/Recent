/*
 * LinkedList.h
 * 
 * Copyright 2019 Mark Brown <mark.brown8790@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#include <iostream>

#ifndef __LINKEDLISTS_H__
#define __LINKEDLISTS_H__

template <class type>
struct Node{
	Node();
	~Node();
	Node<type>* next;
	type* data;
};

template <class type>
Node<type>::Node(){	
	next = NULL;
	data = NULL;
}

template <class type>
Node<type>::~Node(){
	//free((void*)(data));
	//delete next;
	//delete data;
	//next = NULL;
	//data = NULL;
}


template <class type>
class LinkedList{
	Node<type>* current;
	Node<type>* head;
	void destoryList(Node<type>* ticker);
	Node<type>* nextNode();
	
	
	public:
	LinkedList();
	~LinkedList();
	void insert(type* data);
	void assign(type* data);
	bool searchList(type* data);
	type* returnData();
	void lBegin();
	void printList();
	bool nodeNull();
	void iterateNext();
	
	Node<type>* &operator ++() { if(current != NULL) { return current = current -> nextNode(); }else{ std::cout << "End of list...\n"; } }
	
};

// Inserts data into the list
template <class type>
void LinkedList<type>::insert(type* data){
	Node<type>* temp;
	temp = new Node<type>;
	
	if(current == NULL){
		temp -> data = data;
		temp -> next = NULL;
		current = temp;
		head = current;
	} else if (current -> next == NULL){
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
	current = NULL;
}
template <class type>
LinkedList<type>::~LinkedList(){
	destoryList(head);
}

// returns the head of the list
template <class type>
void LinkedList<type>::lBegin(){ current = head; }

// overwrites the data in the 'current' node
template <class type>
void LinkedList<type>::assign(type* data){ current -> data = data; }

// destroys the list
template <class type>
void LinkedList<type>::destoryList(Node<type>* ticker){
	// destroy the list by removing either head to tail in recursive fashion (make sure its reverse recursion)
	Node<type>* troy = ticker -> next;
	//ticker = ticker -> next;

	if(troy == NULL){
		std::cout << "List Destroyed...\n";
		return; // Destroyed!!
	} else {
		delete ticker;
		
		destoryList(troy);
	}
}

// Searches the list and returns true/false depending on if data is in the list
template <class type>
bool LinkedList<type>::searchList(type* data){
	for(lBegin(); current != NULL; current++ )
		if(current -> data == data) 
			return true;
	
	return false;
}

// Returns the data at the current pointer
template <class type>
type* LinkedList<type>::returnData(){ return current -> data; }

// Iterates to next node
template <class type>
Node<type>* LinkedList<type>::nextNode(){ return current -> next; }

// Prints out the list
template <class type>
void LinkedList<type>::printList(){
	
}

// Returns if data is NULL or not
template <class type>
bool LinkedList<type>::nodeNull(){
	return (current == NULL) ? true: false;
}

// iterators the current pointer to the next node
template <class type>
void LinkedList<type>::iterateNext(){
	current = current -> next;
}

#endif
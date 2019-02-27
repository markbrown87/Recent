/* 
 * Created by Mark Brown
 * On 22/2/2019
 * To practice creating a Queue data structure. Header file that handles the Queue class and node structure
 * 
 */

#include <iostream>
#include <string>

#ifndef __NODE_H__
#define __NODE_H__

//	Structure data structure is no different than a class other than Structure members are public by default 
// 		.. and classes are private by default. Both have public, private, and protected.
// 		-> Note: protected is just like private other than the variables can be inherited.
template <class T>
struct Node {
	Node<T> *prev;
	T data;
};

//	Queue (or stk for short) is a class data structure that houses all the possibilies that a Queue could
//		.. use normally; pop, push, and peak.
template <class T>
class Queue{
	public:
	// constructor and destructor
	Queue();
	~Queue();
	
	// basic functions that allow for normal Queue functionality
	void pop();
	void push(T data);
	T peek();
	
	//overloaded '=' operator between two Node structs
	Node<T>& operator=(const Node<T> &other); 
	
	protected:
	void destroyQueue();
	
	Node<T> *current;
};

// Constructor
template <class T>
Queue<T>::Queue(){
	current = NULL; 
}

// Destructor
template <class T>
Queue<T>::~Queue(){
	destroyQueue();
}

// takes a peak at the current data
template <class T>
T Queue<T>::peek(){
	if(current != NULL)
		return current -> data;
	else
		return "Empty Queue";
}

// Destroys the Queue and all items
template <class T>
void Queue<T>::destroyQueue(){
	Node<T> *temp;
	
	if(current == NULL){
		std::cout << "Queue Destroyed." << std::endl;
	}
	else if(current -> prev == NULL){
		std::cout << "Destorying: " << current -> data << std::endl;
		temp = current;
		current = NULL;
		delete temp;
		std::cout << "Queue Destroyed." << std::endl;
	}
	else{
		std::cout << "Destorying: " << current -> data << std::endl;
		temp = current;
		current = current -> prev;
		delete temp;
		destroyQueue();
	}
}

// Pops off the top item on the Queue
template <class T>
void Queue<T>::pop(){
	Node<T> *temp; 
	
	// Checks if the current pointer is pointed at nothing
	if(current == NULL){
		std::cout << "No more items to pop." << std::endl;
	}
	// (hold on to your seat) Checks if the (current pointer pointed at the) item on the Queue is pointing at nothing
	else if(current->prev == NULL){
		temp = current;
		current = NULL;
		delete temp;
		std::cout << "Last Data item popped." << std::endl;
	}
	// Moves current pointer to prev pointers' location and deletes item that the current pointer was pointed at before moving :S
	else{
		temp = current;
		current = current -> prev;
		delete temp;
		std::cout << "Data item popped." << std::endl;
	}
}

// Pushes a new item onto the Queue
template <class T>
void Queue<T>::push(T data){
	Node<T> *newNode;
	newNode = new Node<T>;
	
	if(current == NULL){
		// FYI the '->' is like saying newNode.data BUT you have to use '->' instead with pointers
		newNode -> data = data;
		newNode -> prev = NULL;
		
		current = newNode;
		
		std::cout << "Pushed Data Item on the Queue (New Queue Item)." << std::endl;
	}
	else{
		newNode -> data = data;
		newNode -> prev = current;
		
		current = newNode;
		
		std::cout << "Pushed Data Item on to Queue (previous data present)." << std::endl;
	}
}

// Overloaded pointer to correctly assign when two nodes are pointed at eachother
template <class T>
Node<T>& Queue<T>::operator=(const Node<T> &other){
	// 'this' is a pointer SOOOO if you want to check if it's pointed at the same memory location then dereference the other variable
	if (this != &other){
		// HOWEVER! if you want to make the data location that 'this' is pointed at be over written then you must dereference the 'this' pointer
		*this = other;
	}

	return *this;
}

/* End definition */
#endif
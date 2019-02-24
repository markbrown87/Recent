/* 
 * Created by Mark Brown
 * On 22/2/2019
 * To practice creating a stack data structure. Header file that handles the stack class and node structure
 * 
 */

#include <iostream>
#include <string>
#include <vector>

#ifndef __NODE_H__
#define __NODE_H__

//	Structure data structure is no different than a class other than Structure members are public by default 
// 		.. and classes are private by default. Both have public, private, and protected.
// 		-> Note: protected is just like private other than the variables can be inherited.

struct Node {
	Node *prev;
	int **data;
	
	//overloaded '=' operator between two Node structs
	Node& operator=(const Node &other);
	
};

//	Stack (or stk for short) is a class data structure that houses all the possibilies that a stack could
//		.. use normally; pop, push, and peak.

class stk{
	public:
	// constructor and destructor
	stk();
	~stk();
	
	// basic functions that allow for normal stack functionality
	void pop();
	void push(int** data);
	int** peek();
	
	//~ //overloaded '=' operator between two Node structs
	//~ Node& operator=(const Node &other);  
	
	protected:
	void destroyStack();
	
	Node *current;
};

// Constructor
stk::stk(){
	current = NULL; 
}

// Destructor
stk::~stk(){
	destroyStack();
}

// takes a peak at the current data
int** stk::peek(){
	if(current != NULL)
		return current -> data;
	else
		return NULL;
}

// Destroys the Stack and all items
void stk::destroyStack(){
	Node *temp;
	
	if(current == NULL){
		std::cout << "Stack Destroyed." << std::endl;
	}
	else if(current -> prev == NULL){
		temp = current;
		current = NULL;
		delete temp;
		std::cout << "Stack Destroyed." << std::endl;
	}
	else{
		temp = current;
		current = current -> prev;
		delete temp;
		destroyStack();
	}
}

// Pops off the top item on the stack
void stk::pop(){
	Node *temp; 
	
	// Checks if the current pointer is pointed at nothing
	if(current == NULL){
		std::cout << "No more items to pop." << std::endl;
	}
	// (hold on to your seat) Checks if the (current pointer pointed at the) item on the stack is pointing at nothing
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

// Pushes a new item onto the stack
void stk::push(int** data){
	Node *newNode;
	newNode = new Node;
	
	if(current == NULL){
		// FYI the '->' is like saying newNode.data BUT you have to use '->' instead with pointers
		newNode -> data = data;
		newNode -> prev = NULL;
		
		current = newNode;
		
		std::cout << "Pushed Data Item on the Stack (New Stack Item)." << std::endl;
	}
	else{
		newNode -> data = data;
		newNode -> prev = current;
		
		current = newNode;
		
		std::cout << "Pushed Data Item on to Stack (previous data present)." << std::endl;
	}
}

// Overloaded pointer to correctly assign when two nodes are pointed at eachother
Node& Node::operator=(const Node &other){
	// 'this' is a pointer SOOOO if you want to check if it's pointed at the same memory location then dereference the other variable
	if (this != &other){
		// HOWEVER! if you want to make the data location that 'this' is pointed at be over written then you must dereference the 'this' pointer
		*this = other;
	}

	return *this;
}

/* End definition */
#endif
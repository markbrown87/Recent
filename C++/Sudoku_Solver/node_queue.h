/*
 * node_queue.h
 * 
 * Copyright 2019 Mark Brown <mark_VM@mark_VM-VirtualBox>
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
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>

#ifndef __NODE_QUEUE_H__
#define __NODE_QUEUE_H__

//	Structure data structure is no different than a class other than Structure members are public by default 
// 		.. and classes are private by default. Both have public, private, and protected.
// 		-> Note: protected is just like private other than the variables can be inherited.

struct Node {
	Node *prev;
	int **data;
	
	//overloaded '=' operator between two Node structs
	Node& operator=(const Node &other);
	
};

//	Queue(or stk for short) is a class data structure that houses all the possibilies that a Queue could
//		.. use normally; pop, push, and peak.

class Queue{
	public:
	// constructor and destructor
	Queue();
	~Queue();
	
	// basic functions that allow for normal Queue functionality
	void pop();
	void push(int** data);
	int** peek();
	int** parseString(std::string rawData); 
	
	protected:
	void destroyQueue();
	
	Node *current;
};

// Constructor
Queue::Queue(){
	current = NULL;

}

// Destructor
Queue::~Queue(){
	destroyQueue();
}

// takes a peak at the current data
int** Queue::peek(){
	if(current != NULL)
		return current -> data;
	else
		return NULL;
}

// Destroys the Queue and all items
void Queue::destroyQueue(){
	Node *temp;
	
	if(current == NULL){
		std::cout << "Queue Destroyed." << std::endl;
	}
	else if(current -> prev == NULL){
		temp = current;
		current = NULL;
		delete temp;
		std::cout << "Queue Destroyed." << std::endl;
	}
	else{
		temp = current;
		current = current -> prev;
		delete temp;
		destroyQueue();
	}
}

// Pops off the top item on the Queue
void Queue::pop(){
	Node *temp; 
	
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

// Assigns data to the node item
int** Queue::parseString(std::string rawData){
	
	int **tmpPtr = new int*[25];
	
	for (int i = 0; i < 25; ++i)
		tmpPtr[i] = new int[25];
	
	for (int i = 0; i < 25; ++i)
		for(int j = 0; j < 25; ++j)
			tmpPtr[i][j] = -1;
	

	std::regex emptyData("\'\'");
	std::regex digits("-*[0-9]");
	std::regex lines("\\], \\[");
	std::smatch match;
	
	std::vector<std::string> rows(5);
	std::string token;
	int m = 0, n = 0;
	
	rawData = std::regex_replace(rawData,emptyData,"'0'");	
	rawData = std::regex_replace(rawData,lines,"]\n[");		
	std::stringstream tmp(rawData);
	
	while(std::getline(tmp,token,'\n'))
		rows.push_back(token);

	for(unsigned int k = 0; k < rows.size(); ++k){
		if(rows[k] != ""){
			while(std::regex_search(rows[k], match, digits)){
				for (auto x:match) tmpPtr[m][n] = stoi(x);
				rows[k] = match.suffix().str();
				++n;
			}
			++m;
			n = 0;
		}
			
	}
	
	return tmpPtr;
}

// Pushes a new item onto the Queue
void Queue::push(int** data){
	Node *newNode;
	newNode = new Node;
	
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
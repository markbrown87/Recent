/*
 * QueueLoader.cc
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
 * 
 */


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "node_stack.h"

// Queues up the files
class QueueLoader{
	stk stack;	
	int** parsedData;
	
	public:
	QueueLoader();
	void loadQueue(std::string rawData);
	int** useData();
	void nextItem();
};

// Constructor
QueueLoader::QueueLoader(){
	// nothing here
}

// builds the stack and returns it for use in the main file
void QueueLoader::loadQueue(std::string rawData){
	
	parsedData = stack.parseString(rawData);
	stack.push(parsedData);
	
}

// reads out parsed data
int** QueueLoader::useData(){
	return stack.peek();
}

// pops and cycles to next item
void QueueLoader::nextItem(){
	stack.pop();
}
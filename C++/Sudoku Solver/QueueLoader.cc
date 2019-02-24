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
#include <regex>
#include "node_stack.h"

// Queues up the files
// CONSIDER RETURNING TO THIS AND MAKING IT A STRUCT IN STEAD
class QueueLoader{
	stk stack;
	
	int** parsedData = new int*[25];
	void parseData(std::string rawData);
	//~ std::string scanFile();
	
	public:
	QueueLoader();
	void loadQueue(std::string rawData);
	int** useData();
};

// Constructor
QueueLoader::QueueLoader(){
	for (int i = 0; i < 25; ++i)
		parsedData[i] = new int[25];
}

// Takes in a string and then parses it into a 2D vector
void QueueLoader::parseData(std::string rawData){

	std::regex exp("\'\'");
	
	rawData = std::regex_replace(rawData,exp,"-1");
	
	std::cout << rawData << std::endl;

	// do stuff
	
}

//~ //Scans the file in and gets the string in the bin file
//~ std::string QueueLoader::scanFile(){
	
	//~ std::string lineOfData;
	
	//~ ifstream inFile;
	//~ inFile.open
	
	//~ return lineOfData;
//~ }

// builds the stack and returns it for use in the main file
void QueueLoader::loadQueue(std::string rawData){
	
	parseData(rawData);
	
	//stack.push(parsedData);
	
	//Loop here to get all files!

}

// reads out parsed data
int** QueueLoader::useData(){
	return parsedData;
}
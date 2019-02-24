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
#include <sstream>
#include "node_stack.h"

// Queues up the files
// CONSIDER RETURNING TO THIS AND MAKING IT A STRUCT IN STEAD
class QueueLoader{
	stk stack;
	
	int** parsedData = new int*[25];
	void parseData(std::string rawData);
	
	public:
	QueueLoader();
	void loadQueue(std::string rawData);
	int** useData();
	void nextItem();
};

// Constructor
QueueLoader::QueueLoader(){
	int j = 0;
	
	for (int i = 0; i < 25; ++i)
		parsedData[i] = new int[25];
	
	for (int i = 0; i < 25; ++i){
		for(j = 0; j < 25; ++j)
			parsedData[i][j] = -1;
		
		j = 0;
	}
}

// Takes in a string and then parses it into a 2D vector
void QueueLoader::parseData(std::string rawData){

	std::regex emptyData("\'\'");
	std::regex digits("-*[0-9]");
	std::regex lines("\\], \\[");
	std::smatch match;
	
	std::vector<std::string> rows(5);
	std::string token;
	int i = 0, j = 0;
	
	rawData = std::regex_replace(rawData,emptyData,"'0'");	
	rawData = std::regex_replace(rawData,lines,"]\n[");		
	std::stringstream tmp(rawData);
	
	while(std::getline(tmp,token,'\n'))
		rows.push_back(token);

	for(unsigned int k = 0; k < rows.size(); ++k){
		if(rows[k] != ""){
			//std::cout << rows[k] << ": In Vector" << std::endl;
			while(std::regex_search(rows[k], match, digits)){
				for (auto x:match) parsedData[i][j] = stoi(x);
				rows[k] = match.suffix().str();
				++j;
			}
			++i;
			j = 0;
		}
			
	}
	
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
	
	stack.push(parsedData);
	
	//Loop here to get all files!

}

// reads out parsed data
int** QueueLoader::useData(){
	return stack.peek();
}

// pops and cycles to next item
void QueueLoader::nextItem(){
	stack.pop();
}
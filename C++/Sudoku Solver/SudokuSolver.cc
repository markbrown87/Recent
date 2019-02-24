/*
 * Created by Mark Brown
 * On 23/2/2019
 * INSERT DESCRIPTION HERE AS YOU GO ALONG
 * 
 */

#include <iostream>
#include <string>
#include <math.h>
#include "QueueLoader.cc"

void solveIt(int** data);
void fillRow(int** data);
int getLength(int** data);
int* getArrayOfNums(int** data, int col);

class Boards{	
	int copy[25][25];
	
	public:
	Boards();
	bool checkMutability(int row, int col);
	void makeCopy(int ** data);
};


int main(int argc, char *argv[])
{
	QueueLoader queue;
	Boards copy;
	
	int** data;
	
	std::string rawData = "";
	while(std::getline(std::cin, rawData)){
		std::cout << rawData << std::endl;
		queue.loadQueue(rawData);
	}
	
	
	data = queue.useData();
	
	while(data != NULL){
		
		std::cout << "Solving Puzzle now...\n";
		
		int lth = getLength(data);
		
		for(int i = 0; i < lth; ++i){
			int* tmp = NULL;
			
			tmp = new int[lth];
			
			tmp = getArrayOfNums(data, i);
			
			std::cout << "Missing Numbers: ";
			
			for(int j = 0; j < lth; ++j)
				std::cout << tmp[j] << " ";
			
			std::cout << std::endl;
			
			delete [] tmp;
		}
		
		
		queue.nextItem();
		data = queue.useData();
	}
	
	
	delete [] data;
	return 0;
}

// constructor
Boards::Boards(){
	for(int i = 0; i < 25; ++i)
		for(int j = 0; j < 25; ++j)
			copy[i][j] = -1;
}

// Make copy of board (check immutability)
void Boards::makeCopy(int** data){
	for(int i = 0; i < 25; ++i)
		for(int j = 0; j < 25; ++j){
			if(data[i][j] == -1)
				copy[i][j] = -2;
			else
				copy[i][j] = data[i][j];
				
		}
}

// find missing numbers
int* getArrayOfNums(int** data, int row){
	int count = getLength(data);
	
	int * temp = NULL;
	
	temp = new int[count];
	
	for(int i = 0; i < count; ++i)
		temp[i] = i + 1;
		
	for(int i = 0; i < count; ++i)
		for(int j = 0; j < count; ++j)
			if(temp[i] == data[row][j]){
				temp[i] = 0;
			}
	
	return temp;
}

// fills in the rows with needed values
void fillRow(int** data){
	
}

// returns to the count of the dimension
int getLength(int** data){
	int count = 0;
	
	for(int i = 0; i < 25; ++i){
		if(data[i][0] != -1)
			count++;
	}
	
	return count;
}

// calculates score of the position

// returns bool if value can be changed
bool Boards::checkMutability(int row, int col){
	return (copy[row][col] != 0);
}

// takes in the pointer and solves the puzzle
void solveIt(int** data){
	// 
}
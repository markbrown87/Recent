/*
 * Created by Mark Brown
 * On 23/2/2019
 * INSERT DESCRIPTION HERE AS YOU GO ALONG
 * 
 */

#include <iostream>
#include <string>
#include "QueueLoader.cc"

void solveIt(int** data);
void fillRow(int** data);
int getDim(int** data);

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
	int j = 0;
	
	std::string rawData = "";
	while(std::getline(std::cin, rawData)){
		std::cout << rawData << std::endl;
		queue.loadQueue(rawData);
	}
	
	
	data = queue.useData();
	
	while(data != NULL){
		
		for(int i = 0; i < 25; ++i){
			for(int j = 0; j < 25; ++j)
				if(data[i][j] != -1){
					//solveIt(data);
					std::cout << data[i][j] << " ";
					
				}
				
			if(data[i][j] != -1)
				std::cout << std::endl;	
		}
		
		std::cout << "Dim count: " << getDim(data) << std::endl;
		
		queue.nextItem();
		data = queue.useData();
	}
	
	

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
		for(int j = 0; j < 25; ++j)
			copy[i][j] = data[i][j];
}

// fills in the rows with needed values
void fillRow(int** data){
	// fill row with missing values
}

// returns to the count of the dimension
int getDim(int** data){
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
	return (copy[row][col] == -1);
}

// takes in the pointer and solves the puzzle
void solveIt(int** data){
	// 
}
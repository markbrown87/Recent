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

//#define UNASSIGNED 0;

int getLength(int** data);
bool findUnassignedLoc(int** data, int &row, int &col);
bool solveIt(int** data);
bool isSafe(int** data, int row, int col, int num);
bool usedInCol(int** data, int col, int num);
bool usedInRow(int** data, int row, int num);
bool usedInBox(int** data, int boxRow, int boxCol, int num);

int main(int argc, char *argv[])
{
	QueueLoader queue;
	
	int** data;
	
	std::string rawData = "";
	while(std::getline(std::cin, rawData)){
		queue.loadQueue(rawData);
	}
	
	
	data = queue.useData();
	
	while(data != NULL){
		
		std::cout << "\nSolving Puzzle now...\n";
		
		int count = getLength(data);
			
		if(solveIt(data)){
			for(int i = 0; i < count; ++i){
				for(int j = 0; j < count; ++j){
					std::cout << data[i][j] << " ";
				
				}
				
				std::cout << std::endl;
			}
			
			std::cout << "Solved Puzzle!\n";
		}else
			std::cout << "failed to solve puzzle... \n";		
			
		
		queue.nextItem();
		data = queue.useData();
	}
	
	
	delete [] data;
	return 0;
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

// If this works make sure to review why it works!! 
// finds the first instance of an unassigned value in the puzzle (by passing in the row, col by reference -> smart!)
bool findUnassignedLoc(int** data, int &row, int &col){
	int lth = getLength(data);
	
	for(row = 0; row < lth; ++row)
		for(col = 0; col < lth; ++col)
			if (data[row][col] == 0)
				return true;
	
	return false;
}

bool usedInCol(int** data, int col, int num){
	int lth = getLength(data);
	
	for(int row = 0; row < lth; ++row)
		if(data[row][col] == num)
			return true;
			
	return false;
}

bool usedInRow(int** data, int row, int num){
	int lth = getLength(data);
	
	for(int col = 0; col < lth; ++col)
		if(data[row][col] == num)
			return true;
			
	return false;
}

bool usedInBox(int** data, int boxRow, int boxCol, int num){
	int lth = sqrt(getLength(data));	
	
	for(int row = 0; row < lth; ++row)
		for(int col = 0; col < lth; ++col)
			if(data[row+boxRow][col+boxCol] == num)
				return true;
				
	return false;
}

// MAKE SURE TO EXPLAIN THIS ONE IF IT WORKS!!!!
bool isSafe(int** data, int row, int col, int num){
	int sqrtLth = sqrt(getLength(data));
	
	return !usedInRow(data, row, num) && !usedInCol(data, col, num) && !usedInBox(data, (row - row%sqrtLth), (col - col%sqrtLth) , num) && data[row][col] == 0;
}

// Solve it function
bool solveIt(int** data){
	
	int row, col;
	int num = getLength(data);
	
	if(!findUnassignedLoc(data, row, col))
		return true; // success!!
		
	for(int i = 1; i <= num; ++i)
		if(isSafe(data, row, col, i)){
			data[row][col] = i;
			if(solveIt(data))
				return true;
				
			data[row][col] = 0;
		}
	
	return false;
}
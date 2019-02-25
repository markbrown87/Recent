/*
 * SudokuSolver.cc
 * 
 * Copyright Mark Brown <mark_VM@mark_VM-VirtualBox>
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
 * I was guided by geeksforgeeks.org/sudoku-backtracing-7 on creating this project.
 * 
 */


#include <iostream>
#include <string>
#include <math.h>
#include "QueueLoader.cc"

int getLength(int** data);
bool findFirstUnassigned(int** data, int &row, int &col);
bool solvePuzzle(int** data);
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
			
		if(solvePuzzle(data)){
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

// finds the first unassigned value (0) to use for solving the puzzle
bool findFirstUnassigned(int** data, int &row, int &col){
	int lth = getLength(data);
	
	for(row = 0; row < lth; ++row)
		for(col = 0; col < lth; ++col)
			if (data[row][col] == 0)
				return true;
	
	return false;
}

// checks if the value is used in the column
bool usedInCol(int** data, int col, int num){
	int lth = getLength(data);
	
	for(int row = 0; row < lth; ++row)
		if(data[row][col] == num)
			return true;
			
	return false;
}

// checks if the value is used in the row
bool usedInRow(int** data, int row, int num){
	int lth = getLength(data);
	
	for(int col = 0; col < lth; ++col)
		if(data[row][col] == num)
			return true;
			
	return false;
}

// Checks if the value is used in the surrounding box
bool usedInBox(int** data, int boxRow, int boxCol, int num){
	int lth = sqrt(getLength(data));	
	
	for(int row = 0; row < lth; ++row)
		for(int col = 0; col < lth; ++col)
			if(data[row+boxRow][col+boxCol] == num)
				return true;
				
	return false;
}

// Checks to make sure the number value isn't in the surrounding box AND rows/cols
bool isSafe(int** data, int row, int col, int num){
	int sqrtLth = sqrt(getLength(data));
	
	return !usedInRow(data, row, num) && !usedInCol(data, col, num) && !usedInBox(data, (row - row%sqrtLth), (col - col%sqrtLth) , num) && data[row][col] == 0;
}

// function that uses recursion (backtracing) to find the solution to the puzzle
bool solvePuzzle(int** data){
	
	int row, col;
	int num = getLength(data);
	
	if(!findFirstUnassigned(data, row, col))
		return true; 
		
	for(int i = 1; i <= num; ++i)
		if(isSafe(data, row, col, i)){
			data[row][col] = i;
			if(solvePuzzle(data))
				return true;
				
			data[row][col] = 0;
		}
	
	return false;
}
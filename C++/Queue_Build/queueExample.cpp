/* 
 * Created by Mark Brown
 * On 22/2/2019
 * To practice creating a stack data structure.
 * 
 */

#include <iostream>
#include <string>
#include "node.h"

// Declarations
void menu();

int main(){

	menu();
	
	return 0;
}

// Menu that displays what options you have (Currently templated Node class BUT only accepts strings for now when using Menu() interaction)
void menu(){
	
	Queue<std::string> tmpQueue;
	int input;
	std::string tmpData;

	do{
	std::cout << "What would you like to do with the stack?..\n";
	std::cout << "1 - Push(string) into the stack\n2 - pop top\n3 - peek data\n4 - quit\n";
	std::cin >> input;
	
	while(std::cin.fail() || (input < 1 || input > 4)){
		std::cin.clear();
		std::cin.ignore(256,'\n');
		std::cout << "Incorrect input... please use select again.\n\n";
		std::cout << "1 - Push(data) into the stack\n2 - pop top\n3 - peek data\n4 - quit\n";;
		std::cin >> input; 
	}
	
	std::cin.clear();
	std::cin.ignore(256,'\n');
	
	
	
	switch (input){
			case 1:
				std::cout << "What string value would you like to input into the stack?\n";
				std::getline(std::cin, tmpData);
				tmpQueue.push(tmpData);
				break;
				
			case 2:
				tmpQueue.pop();
				break;
				
			case 3:
				std::cout << "Data peeked: " << tmpQueue.peek() << std::endl;
				break;

			case 4:
				std::cout << "Exiting Application...\n";
				break;
				
			default:
				std::cout << "Error... what happened?\n\n";
				break;
	}
	
	}while(input < 4 && input > 0);	
}
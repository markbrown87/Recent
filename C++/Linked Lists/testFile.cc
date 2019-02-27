/* 
*	Created by Mark Brown
*	On 26/2/2019
*	To test out the linked list header file
*/

#include <iostream>
#include <string>
#include "LinkedList.h"

int main(int argc, char* argv[]){
	
	LinkedList<std::string> list;
	
	std::string* var1 = new std::string("Smelly1");
	std::string* var2 = new std::string("Smelly2");
	std::string* var3 = new std::string("Smelly3");
	
	list.insert(var1);
	list.insert(var2);
	list.insert(var3);
	
	if(list.nodeNull())
		std::cout << "Current node Null\n";
	
		
	for(list.lBegin(); !list.nodeNull(); list.iterateNext())
		std::cout << *list.returnData() << std::endl;

	
	if(list.searchList(var2))
		std::cout << "Yes " << *var2 << " was found!\n";
	else
		std::cout << "Nothing found...\n";

	return 0;
}
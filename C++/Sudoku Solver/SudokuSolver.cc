/*
 * Created by Mark Brown
 * On 23/2/2019
 * INSERT DESCRIPTION HERE AS YOU GO ALONG
 * 
 */

#include <iostream>
#include <string>
#include "QueueLoader.cc"


/*
 * NOTES:
 * 	- Issue with stack pointer (I think) where the data item in the Node is pointed at the QueueLoader Array
 * 		0 if that changes then so does all the data items on the stack
 * 		0 Possible fix: move the parsedData to the Node and all of it's functionality
 */



int main(int argc, char *argv[])
{
	QueueLoader queue;
	
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
			for(j = 0; j < 25; ++j){
				if(data[i][j] != -1)
					std::cout << data[i][j] << " ";
			}
			j = 0;
			if(data[i][j] != -1)
				std::cout << std::endl;	
		}
		
		queue.nextItem();
		data = queue.useData();
	}
	
	
	return 0;
}
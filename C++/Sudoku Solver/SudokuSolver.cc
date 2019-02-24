/*
 * Created by Mark Brown
 * On 23/2/2019
 * INSERT DESCRIPTION HERE AS YOU GO ALONG
 * 
 */

#include <iostream>
#include <string>
#include "QueueLoader.cc"

int main(int argc, char *argv[])
{
	QueueLoader queue;
	
	std::vector<std::vector<int>> parsedData;
	
	std::string rawData = "";
	std::getline(std::cin, rawData);
	
	
	queue.loadQueue(rawData);
	
	//parsedData = queue.useData();
	
	
	return 0;
}
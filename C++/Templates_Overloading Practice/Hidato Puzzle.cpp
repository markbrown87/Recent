// Hidato Puzzle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

#include "BagOf_Goodies.h"

using namespace std;

int main()
{
	BagOf_Goodies<string> tmp("THIS IS A TEST!!!");
	BagOf_Goodies<string> other("HEYYYY");

	BagOf_Goodies<int> tmpInt;

	tmpInt = 10;
	tmp = other;

	tmp.print_item();

	tmp = "Hola!";

	cout << tmpInt << endl;

	cout << tmp << endl;

	tmpInt += 5;

	cout << tmpInt << endl;

	if (tmp == "Hola!")
		cout << "YES it works!!" << endl;
	else
		cout << "awww man!! It didn't work :S" << endl;

	tmp = tmp + " NOPE!!";
	
	cout << tmp << endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

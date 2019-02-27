#include <iostream>
#include "BagOf_Goodies.h"

using namespace std;


BagOf_Goodies<T>::BagOf_Goodies() {
	item = NULL;
}

BagOf_Goodies<T>::~BagOf_Goodies() {
	//Do Nothing
}

void BagOf_Goodies<T>::add_items(T value) {
	item = value;
};

void BagOf_Goodies<T>::print_all() {
	cout << item << endl;
}
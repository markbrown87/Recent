#include <iostream>
#include <string>

using namespace std;

template <class T>
class BagOf_Goodies {
public:
	BagOf_Goodies();
	BagOf_Goodies(T value);
	~BagOf_Goodies();

	void add_items(T value);
	void print_item();

	// Overloading Functions
	friend ostream& operator<<(ostream& out, const BagOf_Goodies<T>& item) {
		out << item.item;
		return out;
	};
	// Overloading 
	T operator=(const T& value) { item = value; return item; };
	T operator+(const T& value) { item = item + value; return item; }
	T operator+=(const T& value) { item = item + value; return item; }

	//int operator-(const int& value) { (int)item = (int)item - value; return item; }
	//double operator-(const double& value) { (double)item = (double)item - value; return item; }
	//float operator-(const float& value) { (float)item = (float)item - value; return item; }

	//int operator++(const int& value) { (int)item = (int)item + 1; return item; }
	//int operator--(const int& value) { (int)item = (int)item - 1; return item; }
	bool operator ==(const T& value) { return (item == value); }
	//T operator=(const string value) { item = value; return item; };

protected:
	T item;
};

template <class T>
BagOf_Goodies<T>::BagOf_Goodies() {
	item = NULL;
}

template <class T>
BagOf_Goodies<T>::~BagOf_Goodies() {
	//Do Nothing
}

template <class T>
BagOf_Goodies<T>::BagOf_Goodies(T value) {
	item = value;
}

template <class T>
void BagOf_Goodies<T>::add_items(T value) {
	item = value;
}

template <class T>
void BagOf_Goodies<T>::print_item() {
	cout << item << endl;
}
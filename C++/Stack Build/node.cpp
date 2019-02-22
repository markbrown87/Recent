#include <iostream>
#include <string>
#include "node.h"

Node Node::Node(){
	prev => NULL;
	current => this;
		
	item = "";
}

Node Node::~Node(){
	delete prev;
	delete current;
}

Node Node::pop(){
	delete prev;
	delete current;
	
	return item;
}

void Node::push(Node node){
	prev => node;
	current => this;
}

Node Node::peak(){
	return *current;
}

void Node::assign(string value){
	item = value;
}

/* End CPP file for Node.h */
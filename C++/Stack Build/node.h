#ifndef __NODE_H__
#define __NODE_H__

class Node {
	public:
		Node();
		~Node();
		
		Node pop();
		void push(Node);
		Node peak();
		
		void assign(string value);
		
	private:
		Node *prev;
		Node *current;
		
		string item;
}

/* End definition */
#endif
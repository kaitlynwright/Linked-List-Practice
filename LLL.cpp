#include "LLL.hpp"
#include <stdio.h>
#include <stdlib.h>

LLL::LLL() {				//default constructor 
	length = 0;
	head = NULL;
	tail = NULL;
}



LLL::LLL(int x) {
	length = 0;			//constructor - takes initial value
	insert(x);
}



LLL::LLL(int size, int max) {		//contructor - fills lll with random data
	length = 0;
	srand(2);
	for (int i = 0; i < size; ++i) {
		int rand_data = rand()%max;
		insert(rand_data);
	}
}



LLL::~LLL(){				//deconstructor
	while(head) {
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	tail = NULL;
}



void LLL::insert(int x) {
	// inserts node with specified data at front of list
	Node *temp = new Node;
	temp->data = x;
	temp->next = NULL;

	if (!head) {
		head = temp;
		tail = head;
		++length;
		return;
	}

	temp->next = head;
	if (length == 2) tail = temp->next;		
	head = temp;
	++length;
	return;
}	



int LLL::insert_at(int data, int pos) {
	// inserts node with specified data at specified position
	int i = 0;
	Node *temp = new Node;
	temp->data = data;
	temp->next = NULL;
	Node *cur = head;
	
	if (pos > length+1) return 0;

	if(pos == 1) {
		temp->next = head;
		head = temp;
		++length;
		if (length == 1) tail = head;
		return 1;
	} 	

	while(cur && cur->next && i < pos-2) {
		cur = cur->next;
		++i;
	}

	if (pos == length+1) tail = temp; 
	temp->next = cur->next;
	cur->next = temp;
	++length;
	return 1;
}



void LLL::remove(int x) {
	// removes node with specified data
	Node *cur = head;
	if (cur->data == x) {
		head = cur->next;
		--length;
		return;
	} else {
		while(cur && cur->next && cur->next->data != x) { 
			cur = cur->next;
		}
		if (cur) {
			cur->next = cur->next->next;
			--length;
		}
		return;
	}
}



int LLL::remove_at(int pos) {
	// removes node at specified position
	int i = 0;
	Node *cur = head;
	if(pos > length) return 0;

	while(cur && cur->next && i < pos-2) {
		cur = cur->next;		//points to (n-1) node
		++i;
	}
	cur->next = cur->next->next;
	--length;
	return 1; 
}



void LLL::print() {
	Node *cur = head;
	while(cur) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

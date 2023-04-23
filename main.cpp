//Kevin Yu
//4-6-23
//Binary Search Tree with add print search and delete

#include <iostream>
#include <cstring>
#include <fstream>
#include "node.h"

using namespace std;

//trunk function from nathan zou to help print the tree

struct Trunk { //Used for printing
    Trunk *previous;
    char* str;

    Trunk(Trunk* previous, char* str) {
        this->previous = previous;
        this->str = str;
    }
};

void showTrunks(Trunk* p) { //Uesd for printing
    if (p == NULL) 
        return;

    showTrunks(p->previous);

    cout << p->str;
}

void createArray(char* in, int* array, int& count);
void add(Node*& head, Node*& current, Node*& prev, int data);
void print(Node* head, Trunk *previous, bool prev);

int main() {

	char option[10];
	char filename[20];
	char input[10000];
	bool play = true;
	int count = 0;
	int array[100];
	int modesize = 0;
	
	//see if need to create tree 
	bool tree = false;

	while (play == true) {

		//help from nathan zou with memset
		memset(input, 0, 10000);
		memset(array ,0, 100);
		
		

		modesize = 0;
		count = 0;
		cout << "File or Console? ";
		cin.get(option, 10);
		cin.get();
		//console input
		if (strcmp(option, "Console") == 0) {
			tree = true;
			cout << "Enter input with spaces: ";
			char in[10000];	
			cin.get(in, 100);
			cin.get();
			createArray(in, array, count);
			for (int i = 0; i < 100; i++) {
				if (array[i] != 0) {
					modesize++;
				}
			}
		}
		//file input
		else if (strcmp(option, "File") == 0) {
			tree = true;
		}
		//wrong input
		else {
			cout << "Wrong Input Type" << endl;
		}

		//are we creating tree?
		if (tree == true) {
		
			Node* head = NULL;
			Node* current = NULL;
			Node* previous = NULL;
			for (int i = 0; i < modesize; i++) {
				if(array[i] != 0) {
					current = head;
					add(head, current, previous, array[i]);
				}
			}
			print(head, NULL, false);
		}

	
	}
	return 0;
}

void print(Node* head, Trunk *previous, bool prev) {
	
	if (head == NULL) {
		return;
	}

	char* prevStr = (char*)("    ");
	Trunk *trunk = new Trunk(previous, prevStr);
	print(head -> getPrev(), trunk, true);

	if (!previous) {
		trunk -> str = (char*)("---");
	}
	else if (prev) {
		trunk -> str = (char*)(".---");
		prevStr = (char*)("   |");
	}
	else {
		trunk -> str = (char*)("'---");
		previous -> str = prevStr;
	}
	showTrunks(trunk);
	cout << " " << head->getData() << endl;

	if (previous) {
		previous -> str = prevStr;
	}
	trunk->str = (char*)("   |");
	print(head -> getNext(), trunk, false);
}


void add(Node*& head, Node*& current, Node*& previous, int data) {
	//first
	if (head == NULL) {
		head = new Node();
		head -> setData(data);
		return;
	}
	else {
		//if smaller
		if (data < current -> getData()) {
			previous = current;
			current = current -> getPrev();
			//if nothing here just insert it in tree
			if (current == NULL) {
				current = new Node();
				current -> setData(data);
				previous -> setPrev(current);
				return;
			}
			else {
				//repeat
				add(head, current, previous, data);
			}
		}
		//if bigger
		else {
			previous = current;
			current = current -> getNext();
			if (current == NULL) {
				current = new Node();
				current -> setData(data);
				previous -> setNext(current);
				return;
			}
			else {
				add(head, current, previous, data);
			}
		}
	}
}



void createArray(char* in, int* array, int& count) {
	int x = 0; // counter of char before add
	for (int i = 0;i < strlen(in); i++) {
		if (in[i] == ' ') {
			//if one digit so far, add it
			if(x == 1) {
				int temp = 0;
				temp = in[i-1] - '0';
				array[count] = temp;
				count++;
				x = 0;
			}	
			else {
			//if more than 1 digit, add everything till where was space
				int temp = 0;
				for (int j = 0; j < x; j++) {
					temp = 10 * temp + (in[i- x + j] - '0');
				}
				array[count] = temp;
				count++;
				x = 0;
			}
		}
		//If no space
		else {
			int temp = 0;
			// add digit counter
			x++;
			//add everything at the end
			if (i == strlen(in) - 1) {
				for (int j = 0; j < x; j++) {
					temp = 10 * temp + (in[i + j + 1 - x] - '0');
				}
				array[count] = temp;
				count++;
			}
		}
	}
}


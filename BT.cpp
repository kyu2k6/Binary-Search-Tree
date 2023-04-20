#include <iostream>
#include <cstring>
#include <fstream>
#include "node.h"

using namespace std;

void add(Node* head, char input);

int main() {

	Node* head = NULL;
		
	char input[10];
	char nums[100];
	bool play = true;
	
	while (play == true) {
	
		cout << "File or Console? ";
		cin.get(input, 10);
		cin.get();
		//console input
		if (strcmp(input, "Console") == 0) {
			cout << "Enter input with spaces: ";
			cin.get(nums, 100);
			cin.get();

			for (int i = 0; i < strlen(input); i++) {
				if (input[i] != ' ') {
					add(head, input[i]);
				}
			}
			
				

		}
		//file input
		else if (strcmp(input, "File") == 0) {
			
		}
		//wrong input
		else {
			cout << "Wrong Input Type" << endl;
		}
	
	}
	return 0;
}

void add(Node* head, char data) {
	
	//creates a new node for each num
	Node* n = new Node();
	n -> setData(data);
	n -> setNext(NULL);
	n -> setPrev(NULL);
	
	//first value added
	if (head == NULL) {
		head = n;
	}
	
	//add it to the tree by greater lesser
	else {
		
	}

}




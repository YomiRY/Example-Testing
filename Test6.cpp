/*
 * Test6.cpp
 *
 *  Created on: 2015年6月15日
 *      Author: yomi
 */

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

struct node {
	int data;
	node *next;
};

typedef node *list;

int main() {
	list head, tail, link;
	int n = 5, position = 1, found = 0, data;

	link = new node;
	head = tail = link;
	srand(time(0));
	head->data = rand() % 21;
	tail->next = NULL;
	for (int i = 1; i < n; i++) {
		link = new node;
		link->data = rand() % 21 + 1;
		link->next = head;
		head = link;
	}

	cout << "Please input the data that you want to find:";
	cin >> data;

	link = head;
	while (link) {
		if (link->data == data) {
			found = 1;
			break;
		}
		position++;
		link = link->next;
	}

	if (found) {
		cout << "Find out the data at position " << position << endl;
	} else {
		cout << "Sorry, the data " << data << " can't be found." << endl;
		cout << "The list is as below" << endl;
		link = head;

		while (link) {
			cout << "data = " << link->data << endl;
			head = head->next;
			delete link;
			link = head;
		}
	}

	return 0;
}


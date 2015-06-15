/*
 * DoubleLinkListEx.cpp
 *
 *  Created on: 2015年6月15日
 *      Author: yomi
 */
#include <iostream>
#include "head_files/const_definition.h"

using namespace std;

struct node {
	int data;
	node *right;
	node *left;
};

typedef node *list;

list Inqueue(list, int, char);
list Outqueue(list, int*, char);

int main() {
	list Right_Queue, Left_Queue;
	Right_Queue = NULL;
	Left_Queue = Right_Queue;
	int data;

	cout << "Add data to right:" << endl;

	for (int i = 0; i < SIZE; i++) {
		Right_Queue = Inqueue(Right_Queue, i, RIGHT_MODE);
		if (Left_Queue == NULL) {
			Left_Queue = Right_Queue;
		}
		cout << i << endl;
	}

	cout << "Remove data from left:" << endl;
	while (Left_Queue) {
		Left_Queue = Outqueue(Left_Queue, &data, LEFT_MODE);
		cout << data << endl;
	}

	Right_Queue = NULL;
	Left_Queue = Right_Queue;

	cout << "Add data to left" << endl;
	for (int i = 0; i < SIZE; i++) {
		Left_Queue = Inqueue(Left_Queue, i, LEFT_MODE);
		if (!Right_Queue) {
			Right_Queue = Left_Queue;
		}
		cout << i << endl;
	}

	cout << "Remove data from right:" << endl;
	while (Right_Queue) {
		Right_Queue = Outqueue(Right_Queue, &data, RIGHT_MODE);
		cout << data << endl;
	}

	return 0;
}

list Inqueue(list queue, int data, char mode) {
	list link = new node;
	link->data = data;
	link->right = NULL;
	link->left = NULL;

	if (queue) {
		if (mode == RIGHT_MODE) {
			link->left = queue;
			queue->right = link;
		} else if (mode == LEFT_MODE) {
			link->right = queue;
			queue->left = link;
		}
	}
	return link;
}

list Outqueue(list queue, int *data, char mode) {
	list link = queue;

	if (mode == RIGHT_MODE) {
		queue = queue->left;

		if (queue) {
			queue->right = NULL;
		}
	} else if (mode == LEFT_MODE) {
		queue = queue->right;

		if (queue) {
			queue->left = NULL;
		}
	}
	*data = link->data;
	delete link;
	return queue;
}


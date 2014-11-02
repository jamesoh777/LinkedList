#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

// Node data
struct ListNode {
	int data;
	ListNode *nextNode;
} *firstNode = NULL;

// Inserting from the front
void frontInsert(int info) {
	ListNode *temp;
	temp = (ListNode*)malloc(sizeof(ListNode));
	temp->data = info;
	temp->nextNode = firstNode;
	firstNode = temp;
}

// Delete the front node
void frontDelete() {
	ListNode *temp;
	temp = (ListNode*)malloc(sizeof(ListNode));
	temp = firstNode->nextNode;
	firstNode = temp;
	free(temp);
}

// Inserting from the back
void behindInsert(int info) {
	ListNode *back;
	back = (ListNode*)malloc(sizeof(ListNode));
	back = firstNode;

	while(back->nextNode != NULL) {
		back = back->nextNode;
	}

	ListNode *temp;
	temp = (ListNode*)malloc(sizeof(ListNode));
	temp->data = info;
	temp->nextNode = NULL;
	back->nextNode = temp;
}

// Delete the last node
void behindDelete() {
	ListNode *back;
	back = (ListNode*)malloc(sizeof(ListNode));
	back = firstNode;

	ListNode *temp;
	temp = (ListNode*)malloc(sizeof(ListNode));

	while(back->nextNode != NULL) {
		temp = back;
		back = back->nextNode;
	}
	temp->nextNode = NULL;
	back = temp;
	free(temp);
}

// Insert after a specified node
void insertAfterPosition(int info, int position) {
	ListNode *curNode;
	curNode = (ListNode*)malloc(sizeof(ListNode));

	curNode = firstNode;
	for(int i = 0; i < position; i++) {
		curNode = curNode->nextNode;
	}

	ListNode *node;
	node = (ListNode*)malloc(sizeof(ListNode));
	node->data = info;

	node->nextNode = curNode->nextNode;
	curNode->nextNode = node;
}

// Delete a specified node
void deleteAtPosition(int position) {
	if(position == 0) {
		frontDelete();
	} else {
		ListNode *prevNode;
		prevNode = (ListNode*)malloc(sizeof(ListNode));

		prevNode = firstNode;
		for(int i = 0; i < position - 1; i++) {
			prevNode = prevNode->nextNode;
		}

		prevNode->nextNode = prevNode->nextNode->nextNode;
		free(prevNode);
	}
}

// Sort the nodes
void sort() {
	ListNode *temp;
	temp = (ListNode*)malloc(sizeof(ListNode));

	ListNode *temp1;
	temp1 = (ListNode*)malloc(sizeof(ListNode));

	int holder;

	for (temp = firstNode; temp != NULL; temp = temp->nextNode) {
		for (temp1 = temp->nextNode; temp1 != NULL; temp1 = temp1->nextNode) {
			if(temp->data > temp1->data) {
				holder = temp->data;
				temp->data = temp1->data;
				temp1->data = holder;
			}
		}
	}

	free(temp);
	free(temp1);
}

// Iterator
void printList() {
	ListNode *curNode;
	curNode = firstNode;

	while(curNode != NULL) {
		cout << curNode->data << endl;
		curNode = curNode->nextNode;
	}
}

// Testing
int main() {
	frontInsert(1);
	behindInsert(3);
	behindInsert(2);
	behindInsert(7);
	behindInsert(2);
	behindInsert(3);
	behindInsert(1);

	sort();
	printList();
	return 0;
}







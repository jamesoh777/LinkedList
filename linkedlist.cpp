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
	string data;
	ListNode *nextNode;
} *firstNode = NULL;

// Inserting from the front
void frontInsert(string info) {
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
void behindInsert(string info) {
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
void insertAfterPosition(string info, int position) {
	if(position == 0) {
		frontInsert(info);
	} else {
		ListNode *curNode;
		curNode = (ListNode*)malloc(sizeof(ListNode));

		curNode = firstNode;
		for(int i = 1; i < position; i++) {
			curNode = curNode->nextNode;
			if (curNode == NULL) {
				break;
			}
		}
		ListNode *node;
		node = (ListNode*)malloc(sizeof(ListNode));
		node->data = info;

		node->nextNode = curNode->nextNode;
		curNode->nextNode = node;
	}
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
	frontInsert("cool");
	behindInsert("trist");
	behindInsert("twitch");
	behindDelete();
	behindDelete();
	printList();
	return 0;
}







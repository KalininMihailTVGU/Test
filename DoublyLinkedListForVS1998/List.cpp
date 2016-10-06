#include "stdafx.h"

struct Node {
	int data;
	Node*next;
};

void addAtEnd(struct Node**first, Node*n){

	Node*temp = *first;
	if (temp == NULL) {
		*first = n;
	}
	else {
 		while (temp -> next != NULL) temp = temp -> next;
		temp -> next = n;
	}
}

void addAtBegin(struct Node**root, Node*n) {
	n -> next = *root;
	*root = n;
}

Node*search(Node*node, int val) {
	while (node != NULL &&
		node -> data != val)
	node = node -> next;
	return node;
}

Node*insert(Node*head, Node*beforeNode, Node*node) {

	if (beforeNode == head) {

		node -> next = head;
		head = node;

	}
	else {
		Node*t = head;
		while (t -> next != beforeNode)
			t = t -> next;
		node -> next = beforeNode;
		t -> next = node;
	}
	return head;
}

Node*deleteNode(Node*head, Node*node) {

	if (node != NULL) {
		if (node == head) {
			head = head -> next;
			delete node;
		}
		else {
			Node*t = head;
		
			while (t -> next != node)
				t = t -> next;
			t -> next = node -> next;
			delete node;
		}
	}
	return head;
}

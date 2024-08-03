#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

class node {
public:
	int val;
	Node* next;

	node(int val) {
		this.val = val;
		this.next = NULL;
	}
};

void insertAtHead(node* &head, int val) {
	node* n = new node(val);
	n.next = head;
	head = n;
}

void insertAtTail(node* &head, node* &tail, int val) {
	if (tail == NULL) {
		insertAtHead(head, val);
		tail = head;

		return;
	}

	tail.next = new node(val);
	tail = tail.next;
}

int main() {
	

	return 0;
}
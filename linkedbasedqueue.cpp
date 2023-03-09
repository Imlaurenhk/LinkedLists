#include <iostream>
using namespace std;

class Node {
	public:
	int value;
	Node *next;
};

class Queue {
	public:
	Node *front = 0;
	Node *end = 0;
	int count = Count();

	bool isEmpty() {
		if (front == 0 && end == 0) {
			return true;
		} else { 
			return false;
			}
	}

	int Count() {
		Node* temp = front;
		int count = 0;
		while (temp != 0) {
			count++;
			temp = temp -> next;
		}
		return count;
	}

	void Enqueue(int value) {
		Node *p = new Node();
		p -> value = value;
		p -> next = 0;
		if (front == 0) {
			front = p;
			end = p;
		} else {
			end -> next = p;
			end = p;
		}
	}

	void Dequeue() {
		if (isEmpty() == true) {
		cout << "Empty." << endl;
		} else {
			if (front == end) {
				free(front);
				front = end = 0;
			} else {
				Node *p = front;
				front = front -> next;
				free(p);
			}
		}
	}
};

int main() {
	Queue queue;
	int value;
	cout << "Enter a number";
	cin >> value;
	queue.Enqueue(value);
	queue.Dequeue();
	queue.Count();
	return 0;
}
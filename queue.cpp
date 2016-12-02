#include<iostream>
using namespace std;

/* Queue Data Structure:
 *
 * Queue is a linear data structure that follows a particular order of operations.
 * It is a FIFO data sturcture, i.e first-in-first-out data structure.
 * 
 * The operations usually done on a queue are:
 * 1. Enqueue: Add an item to the queue.
 * 2. Dequeue: Remove an item from the queue. Whatever went in first, goes out first.
 * 3. Front: Get the front item from the queue.
 * 4. Rear: Get the last item from the queue.
 *
 * This program is a linked list implementation of a queue. We define the node as we usually do in a linkedlist.
 */

struct node{
	int data;
	node *next;
} *front=NULL, *rear=NULL, *p=NULL, *np=NULL;

void enqueue(int );
int dequeue();

int main(){
	int n,c=0,x;
	cout << "Enter the number of values to be pushed into queue: ";
	cin >> n;
	while(c < n){
		cout << "Enter the value to be entered into queue: ";
		cin >> x;
		enqueue(x);
		c++;
	}
	cout << endl << endl <<  "Removed values" << endl << endl;
	while(true){
		if(front != NULL)
			cout << dequeue() << endl;
		else
			break;
	}
	return 0;
}

void enqueue(int x){
	np = new node;
	np->data = x;
	np->next = NULL;
	if(front == NULL){
		front = rear = np;
		rear->next = NULL;
	}
	else{
		rear->next = np;
		rear = np;
		rear->next=NULL;
	}
}

int dequeue(){
	int x;
	if(front == NULL){
		cout << "empty queue" << endl;
		return 0;
	}
	else
	{
		p = front;
		x = p->data;
		front = front->next;
		delete(p);
		return(x);
	}
}

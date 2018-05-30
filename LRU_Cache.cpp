/*
Implementation of LRU Cache using queue and maps.
Queue implemnted using double linked list.
Map used is unoredered map
*/


#include <bits/stdc++.h>
using namespace std;
#define SIZE 2

typedef struct QNode
{
	int key;
	struct QNode *prev, *next;
}Node;

typedef struct Queue
{
	Node *front, *rear;
}Queue;

typedef unordered_map<int,pair<int,Node*> > MPP;

Node* newNode (int x)
{
	Node *temp = new Node();
	temp->key = x;
	temp->prev= temp->next = NULL;
	return temp;
}

Queue* createQueue()
{
	Queue *q = new Queue();
	q->front = q->rear = NULL;
	return q;
}

void insert_front(Queue *q, int val)
{
	Node *curr = newNode(val);
	if(q->front == NULL)
	{
		q->front = curr;
		q->rear = curr;
		return;
	}
	
	curr->next = q->front;
	q->front->prev = curr;
	q->front = curr;
	return;
}

void delete_from_list(Queue *q, Node *temp)
{
	if(q->front == NULL && q->rear == NULL)
	{
		cout<<"Dude, don't try deleting from an empty queue";
		return;
	}
	Node *left = temp->prev;
	Node *right = temp->next;
	free(temp);
	if(left)
		left->next = right;
	if(right)
		right->prev = left;
	if(!left)
		q->front = right;
	if(!right)
		q->rear = left;
}

void touch(MPP :: iterator it, Queue *q)
{
	Node *del = it->second.second;
	delete_from_list(q, del);
	insert_front(q, it->first);
	it->second.second = q->front;
}

int read(MPP &cache, Queue *q, int key)
{
	MPP :: iterator it;
	it = cache.find(key);
	if(it==cache.end())
		return INT_MAX;
	touch(it, q);
	return it->second.first;
}

void write(MPP &cache, int key, int val, Queue *q)
{
	MPP :: iterator it;
	it = cache.find(key);
	if(it!=cache.end())
	{
		touch(it,q);
	}
	else
	{
		if(cache.size()==SIZE)
		{
			cache.erase(q->rear->key);
			delete_from_list(q, q->rear);
		}
		insert_front(q,key);
	}
	cache[key] = make_pair(val, q->front);
}

void printQueue(Queue *q)
{
	Node *curr = q->front;
	while(curr!=NULL)
	{
		cout<<curr->key<<" ";
		curr = curr->next;
	}
	cout<<endl;
}

int main()
{
	MPP cache;
	Queue *q = createQueue();
	write(cache, 1, 10,q);
	printQueue(q);
	write(cache, 5, 12,q);
	printQueue(q);
	cout<<"key 5 values to "<<read(cache,q,5)<<endl;
	printQueue(q);
	cout<<"key 1 values to "<<read(cache,q,1)<<endl;
	printQueue(q);
	cout<<"key 10 values to "<<read(cache,q,10)<<endl;
	printQueue(q);
	write(cache, 6, 14,q);
	printQueue(q);
	cout<<"key 5 values to "<<read(cache,q,5)<<endl;
	printQueue(q);
}

#pragma once

#include <string>
#include <list>
#include <iostream>
#include <limits>

class LinkedList
{
private:
	struct Node
	{
		int value;
		Node *next;
		Node(int v, Node *n);
		Node(int v);
	};

	Node *head;
	int list_size;

public:
	virtual int size();
	virtual bool isEmpty();
	virtual int peek();
	virtual void addHead(int value);
	virtual int removeHead();
	// Other linked list methods.


	virtual void addTail(int value);
	virtual bool isPresent(int data);
	virtual bool deleteNode(int delValue);
	virtual void deleteNodes(int delValue);
	virtual Node *reverseRecurseUtil(Node *currentNode, Node *nextNode);
	virtual void reverseRecurse();
	virtual void reverse();
	virtual LinkedList* CopyListReversed();
	virtual LinkedList* CopyList();
	virtual bool compareList(LinkedList* ll);
	virtual bool compareList(Node *head1, Node *head2);
	virtual int findLength();
	virtual int nthNodeFromBegining(int index);
	virtual int nthNodeFromEnd(int index);
	virtual int nthNodeFromEnd2(int index);
	virtual Node *findIntersection(Node *head, Node *head2);
	virtual void freeList();
	virtual void print();
	virtual void sortedInsert(int value);
	virtual void removeDuplicate();
	virtual void makeLoop();
	virtual bool loopDetect();
	virtual bool reverseListLoopDetect();
	virtual int loopTypeDetect();
	virtual Node *loopPointDetect();
	virtual void removeLoop();
};
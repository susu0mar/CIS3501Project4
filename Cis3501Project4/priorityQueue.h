#pragma once
#include "ArrayHeap.h"


class priorityQueue : public ArrayHeap
{

public:
	//default constructor
	priorityQueue() : ArrayHeap() {} //uses array heap default constructor

	//parameterized constructor
	priorityQueue(int userCap) :ArrayHeap(userCap) {} //uses array heap parameter constructor

	void enqueue(priorityData elem, int& count) { //insert into queue
		
		insert(elem, count); //use insert method from array heap to insert into queue
		
	}

	priorityData dequeue(int& count) {
		
		return removeMin(count); //use removeMin method from array heap to delete from queue
	
	}

	priorityData peek() { //see top element
	
		return getMin(); //use getMin from array heap to see top element

	}

	bool isEmpty() {
	
		return getSize() == 0;
	}

	string toString() {
	
		if (isEmpty()) {
		
			return "[Priority Queue is Empty]";
		}
		else {
		
			return ArrayHeap::toString(); //use array heap toString method to convert priority queue into a string
		}
	
	}

	void initializedUnsorted(priorityData elem) 
	{
		ArrayHeap::initializeUnsorted(elem);
	}

	void heapify(int& count, int index = 1) {
	
		
		ArrayHeap::heapify(count, index);
	}

	void sort(int& count) {
	
		ArrayHeap::heapSort(count);
	}
};


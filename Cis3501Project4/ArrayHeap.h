#pragma once
#include "priorityData.h"


class ArrayHeap
{

private:
	priorityData* heap;  //pointer to array heap

	int capacity; //keeps track of total capacity allocated to array

	int size; //keeps track of total size of array, if size == capacity then double capacity


	//helper functions to access specific elements in array (makes it easier)

	int parent(int i) { return i/ 2; } //returns parent of a node

	int left(int i) { return 2* i; } //returns left child
	 
	int right(int i) { return 2 * i + 1; } //returns right child

public:

	

	//helper function to swap two elements in heap

	void swap(priorityData& first, priorityData& second) {
		
		priorityData temp = first; //have temp variable to hold first element

		first = second;

		second = temp; 

	
	}

	//helper method to move an element up the heap (used in insert)
	
	//int& count to cont heap up action

	void bubbleUp(int i, int& count) {
		
		while (i > 1 && heap[parent(i)].priorityValue > heap[i].priorityValue) { //continues to swap elements until min heap condition is satisified
			
			swap(heap[parent(i)], heap[i]); //use helper method to swap both elements

			count++;

			i = parent(i);
		}
		
	}


	//helper method to move an element down heap (used in delete) //int& count to count total heap down aciton

	void bubbleDown(int i, int& count) {
	
		int minIndex = i;



		if (left(i) <= size && heap[left(i)].priorityValue < heap[minIndex].priorityValue) { //check that left of i is valid index and that left i is less than current min
		
			minIndex = left(i);
		}

		if (right(i) <= size && heap[right(i)].priorityValue < heap[minIndex].priorityValue) {
		
			minIndex = right(i);
		}

		if (minIndex != i) {
		
			swap(heap[i], heap[minIndex]);

			count++;

			bubbleDown(minIndex, count);
		}
		
	}


	//Default constructor!

	ArrayHeap() {
		
		capacity = 10; //default heap capacity is 10!
		size = 0;

		heap = new priorityData[capacity + 1]; //1 is added to index to account for index starting at 1 insead of 0

	
	}

	//another constructor for user entered array capacity
	ArrayHeap(int userCap) {
	
		capacity = userCap;
		size = 0;

		heap = new priorityData[capacity + 1];//1 is added to index to account for index starting at 1 insead of 0
	}


	//heap destructor!!! 
	~ArrayHeap() {
	
		delete[] heap;
	}


	//initialize heap unsorted

	void initializeUnsorted(priorityData elem) {
		
		if (size == capacity) { //if array full

			cout << "Array full, double size!" << endl;
			priorityData* newHeap = new priorityData[2 * capacity + 1]; //double capacity, the +1 to account for starting at index 1


			for (int i = 1; i <= size; i++) {

				newHeap[i] = heap[i]; //transfer all elements from old heap to new larger heap //GOT WARNING ON THIS LINE OF CODE!! MAY NEED TO CHANGE IT

			}

			//after increasing array delete old heap 

			delete[] heap;

			heap = newHeap;

			capacity *= 2; //update capacity to double

		}


		size++; //increment size to account for insertion

		heap[size] = elem; //insert at bottom 
		
	}

	void heapify(int& count, int index = 1) {
		
		
			int smallest = index;
			int left = 2 * index;
			int right = 2 * index + 1;

			if (left <= size && heap[left].priorityValue < heap[smallest].priorityValue) {
				smallest = left;
			}

			if (right <= size && heap[right].priorityValue < heap[smallest].priorityValue) {
				smallest = right;
			}

			if (smallest != index) {
				swap(heap[index], heap[smallest]);
				count++;
				heapify(smallest, count);
			}
		

		
	
	}

	void heapSort(int& count) {
		
		// Build heap (rearrange array)
		for (int i = size / 2; i >= 1; i--) {
			heapify(count, i);
		}

		
	}





	

	//insert method- doubles in size if array full

	void insert(priorityData elem, int& count) { //TEST THIS
	
		if (size == capacity) { //if array full
			
			cout << "Array full, double size!" << endl;
			priorityData* newHeap = new priorityData[2 * capacity + 1]; //double capacity, the +1 to account for starting at index 1

			
			for (int i = 1; i <= size; i++) {
			
				newHeap[i] = heap[i]; //transfer all elements from old heap to new larger heap //GOT WARNING ON THIS LINE OF CODE!! MAY NEED TO CHANGE IT
			
			}

			//after increasing array delete old heap 

			delete[] heap;

			heap = newHeap;

			capacity *= 2; //update capacity to double
		
		}
		

		size++; //increment size to account for insertion

		heap[size] = elem; //insert at bottom //ALSO WARNING :( still works tho so idk

		bubbleUp(size, count);
	
	
	}


	//get min

	priorityData getMin() {
	
		if (size == 0) {

			cout << "ERROR: HEAP EMPTY! ENDING PROGRAM" << endl;
			throw std::runtime_error("Heap is empty");
		
		}
		
		return heap[1];
	}

	//remove and return min

	priorityData removeMin(int& count) { 
	
		if (size == 0) {
			cout << "Heap is empty! Ending Program!" << endl;
			throw std::runtime_error("Heap is empty");
		
		}


		priorityData min = heap[1];

		heap[1] = heap[size]; //overwrite heap at root

		size--; //reduce size by 1

		bubbleDown(1,count);

		return min;
	
	}


	//convert entire heap contents into a string!!!
	string toString() const  { 
	
		if (size == 0) {
		
			return "[The Heap is Empty]";
		
		}
		
		//create local string variable to hold all of the data 
		string result = "[";

		for (int i = 1; i <= size; i++) {
			
			result += "(" + heap[i].dataValue + "," + to_string(heap[i].priorityValue) + ")";
			

			//have if statement to determine whether to put ; (basically to determine if it is or isn't the last member of heap

			if (i < size) {
				
				result += ";\n"; //ADDED \N TO PARSE THE STRING OUT! 
			
			}
			


		
		}
		result += "]"; //this at end of all elements
		
		//return the string

		return result;
	
	}

	int getSize() { //use this for priority queue isEmpty method
	
		return size;

	}


	

};


#include"priorityData.h"
#include "ArrayHeap.h"
#include"priorityQueue.h"

using namespace std;


int main() {

	//User interaction Variables
	char ans1;
	int ans2;
	//int ans3;
	int userCap = 10; //10 is default size 
	string tstCase;

	//file variables
	string inputFileName;
	string outputFileName;
	string actionFileName;

	ifstream initialFile;
	ifstream actionFile;

	ofstream outputFile;

	//METRIC COUNTERS!!!!
	int numInitialInsert = 0;
	int numHeapUpInitial = 0;
	int numUserInsert = 0;
	int numUserRemove = 0;
	int numUserReturn = 0;
	int numUserPrint = 0;

	//user heap up and down
	int numHeapUpUser = 0;
	int numHeapDownUser = 0;

	//Action Variables!!
	//char Action; //used to hold action type


	//test case name
	cout << "Hello! Please Enter test case name:" << endl;

	getline(cin, tstCase);
	
	//ask user about queue size
	cout << "Would you like a custom sized priority queue(y/n)?" << endl;
	cin >> ans1;
	if (ans1 == 'y') {
		
		cout << "Enter priority queue capacity: " << endl;
		cin >> userCap;
		cout << "Creating queue of size " << userCap<<endl;
		outputFile<< "Creating queue of size " << userCap << endl;
	
	}
	else if (ans1 == 'n') {
	
		cout << "Creating queue of default size 10" << endl;
		outputFile<< "Creating queue of default size 10" << endl;
	
	}
	else {
	
		cout << "Invalid response. Ending Program." << endl;
		return 1;
	
	}

		


	
	//Declare priority queue object with specific size (OR DEFAULT!)

	priorityQueue queue(userCap);




	//NOW LETS START WITH THE FILES (initialization and output)

	cout << "Enter Initialization file name" << endl;

	cin >> inputFileName;
	
	inputFileName = inputFileName + ".txt";

	cout << "Enter output file name" << endl;

	cin >> outputFileName;

	outputFileName = outputFileName + ".txt";

	initialFile.open(inputFileName); //open initial file
	outputFile.open(outputFileName); //open output file

	if (!initialFile.is_open()) {

		//terminate program if file fails to open

		cout << "Unable to open File" << endl;

		return 1;
	}

	if (!outputFile.is_open()) {

		//terminate program if file fails to open

		cout << "Unable to open File" << endl;

		return 1;
	}

	cout << endl<<"Initialization File!" << endl<<endl;
	outputFile<< endl<< "Initialization File!" << endl<<endl;
	

	//check if file is empty
	if (initialFile.peek() == EOF) { // IT WORKS :) //works for output file

		cout << "Empty File. Queue is empty" << endl;
		outputFile << "Empty File. Queue is empty" << endl;

	}
	else {
	
		string item; //store file string
		int number; //store file priority

		while (initialFile >> item >> number) {
			
			//increment metric
			numInitialInsert++;

			//create priority data item which will be inserted into queue
			priorityData data(item, number);

			queue.initializedUnsorted(data); //insert into queue!!
			

		}
		//now use heap sort
		queue.sort(numHeapUpInitial);

		cout << "Queue initialized with " << numInitialInsert << " elements!" << endl;
		outputFile<< "Queue initialized with " << numInitialInsert << " elements!" << endl;


		//print out initial queue if number of elements less than or equal to 20
		if (numInitialInsert <= 20) {
			
			cout << "Here is Initial Queue:" << endl;
			cout << queue.toString() << endl;

			outputFile << "Here is Initial Queue:" << endl;
			outputFile << queue.toString() << endl;
		}
		else{
			cout << "Queue size too large to print!" << endl;
			outputFile<< "Queue size too large to print!" << endl;

		}
		cout << endl<<"Initialization File Complete" << endl;
		outputFile<< endl<<"Initialization File Complete" << endl;

		
	
	}
	

	initialFile.close(); //DONE WITH INITIALIZATION FILE SO CLOSE!!


	//NOW FOR ACTIONS!!!
	cout << " Would you like to use file actions(1), user actions(2), or both(3)?" << endl;
	cin >> ans2;

	

	if (ans2 == 1 || ans2 ==3) {

		cout <<endl <<"Action File!" << endl << endl;
		outputFile<< endl<<"Action File!" << endl << endl;

		cout << "Please enter action file name:" << endl;
		cin >> actionFileName;
		cout << endl << endl;
		actionFileName = actionFileName + ".txt";

		//open action file
		
		actionFile.open(actionFileName);

		//check that it actually opened, if not then send message and end program!
		if (!actionFile.is_open()) {

			//terminate program if file fails to open

			cout << "Unable to open Action File" << endl;

			return 1;
		}

		//check that if file is empty
		if (actionFile.peek() == EOF) { 

			cout << "Empty File. No file actions performed" << endl;
			outputFile << "Empty File. No file actions performed" << endl;

		}
		else {
			
			string item; //store file string
			char action; //store action character
			int priority; //store priority value

			while (actionFile >> action) {
				
				if (action == 'I') {
				if (actionFile >> item >> priority) { //this means its an insert!!!!
					

					//create priority data 
					priorityData data(item, priority);
					cout << "Inserting: " << item <<" " << priority << endl;
					outputFile<< "Inserting: " << item << " " << priority << endl;

					queue.enqueue(data, numHeapUpUser);

					numUserInsert++;


				}
				}
				else {
				//got transfer of control bypasses intiializaiton so declared here
				priorityData min;

				//if there was an insert, then nothing will be done with switch statement
				switch (action) {
				
				
					case 'R':

						cout << "Removing Min: ";
						outputFile << "Removing Min: ";
						min = queue.dequeue(numHeapDownUser);
						cout << min.dataValue << " " << min.priorityValue <<endl;
						outputFile << min.dataValue << " " << min.priorityValue << endl;
						numUserRemove++;

						break;

					case 'S':

							cout << "Top Element: ";
							outputFile << "Top Element: ";
							min =queue.getMin();
							cout << min.dataValue << " " << min.priorityValue<<endl;
							outputFile << min.dataValue << " " << min.priorityValue << endl;
							numUserReturn++;
						break;

					case 'A':
						cout << "Printing Queue: " << endl;
						outputFile << "Printing Queue: " << endl;
						cout << queue.toString()<<endl;
						outputFile << queue.toString() << endl;
						numUserPrint++;

						break;

					default: 

						break;
				
				}
				}
			
			
			}
			cout << "Action File Complete!!" << endl << endl;
			outputFile << "Action File Complete!!" << endl << endl;
			actionFile.close(); //close action file after use
		
		}

	
		
		//ACTION FILE WORKS SO FAR!! 
	}
	if (ans2 == 2 || ans2 ==3 ) {
		
		char action;
		int priority;
		string item;
		char ans = 'y';
		cout << endl<<"User Interface Actions!" << endl<<endl;
		outputFile<< endl << "User Interface Actions!" << endl << endl;

		do{
			cout << "Enter Action Code (I = insert, R = remove min, S = see top, and A = print all)" << endl;
			

			cin >> action;

			if (action == 'I') {
				
				cin.ignore(); //use this to clear input buffer (program was skipping the getline)


				cout << "Enter string item" << endl;
				getline(cin, item);

				//need to add quotes to the item
				item = "\"" + item + "\"";

				cout << "Enter integer priority" << endl;
				cin >> priority;
				
				priorityData data(item, priority);

				cout << "Inserting " << item << " " << priority << endl;
				outputFile<< "Inserting " << item << " " << priority << endl;

				queue.enqueue(data, numHeapUpUser);
				numUserInsert++;

			}
			else {
				//got transfer of control bypasses intiializaiton so declared here
				priorityData min;

				//if there was an insert, then nothing will be done with switch statement
				switch (action) {


				case 'R':

					cout << "Removing Min: ";
					outputFile<< "Removing Min: ";
					min = queue.dequeue(numHeapDownUser);
					cout << min.dataValue << " " << min.priorityValue << endl;
					outputFile<< min.dataValue << " " << min.priorityValue << endl;
					numUserRemove++;

					break;

				case 'S':

					cout << "Top Element: ";
					outputFile<< "Top Element: ";
					min = queue.getMin();
					cout << min.dataValue << " " << min.priorityValue << endl;
					outputFile<< min.dataValue << " " << min.priorityValue << endl;
					numUserReturn++;
					break;

				case 'A':
					cout << "Printing Queue: " << endl;
					outputFile<< "Printing Queue: " << endl;
					cout << queue.toString() << endl;
					outputFile<< queue.toString() << endl;
					numUserPrint++;

					break;

				default:

					break;

				}
			
				
			
			}
				//ask user if they want to continue
				cout << endl<<"Would you like to continue with more actions? (y/n)" << endl;
				cin >> ans;

		} while (ans == 'y');
	
		cout << "User Actions Complete!" << endl;
		outputFile<< "User Actions Complete!" << endl;
	
	}
	else if (ans2 != 1 && ans2 !=2 && ans2 !=3) { //if neither choice selected, end program!
		
		
		cout << "Invalid Answer" << endl;
		outputFile<< "Invalid Answer" << endl;
		return 1;
	
	}
	

	//THEN OUTPUT METRICS!

	cout << "TEST NAME: " << tstCase<<endl<<endl<<endl;

	cout << "Total number of Inserts - Initialization: \t" << numInitialInsert << endl;
	cout << "Total number of Heap-up actions- Initialization: \t" << numHeapUpInitial << endl;


	cout << "Total number of User Inserts:\t" << numUserInsert << endl;
	cout << "Total number of User Removes:\t" << numUserRemove << endl;
	cout << "Total number of user Return Top:\t" << numUserReturn << endl;
	cout << "Total number of user Prints:\t" << numUserPrint << endl;
	cout << "Total Number of user Heap Actions:\t" << numHeapUpUser + numHeapDownUser << endl;
	cout << "Total number of user Heap-up actions:\t" << numHeapUpUser << endl;
	cout << "Total number of user Heap-Down actions:\t" << numHeapDownUser << endl;

	cout << "Goodbye :D" << endl;

	//print metrics to output file

	outputFile << "TEST NAME: " << tstCase << endl << endl << endl;

	outputFile << "Total number of Inserts - Initialization: \t" << numInitialInsert << endl;
	outputFile << "Total number of Heap-up actions- Initialization: \t" << numHeapUpInitial << endl;

	outputFile << "Total number of User Inserts:\t" << numUserInsert << endl;
	outputFile << "Total number of User Removes:\t" << numUserRemove << endl;
	outputFile << "Total number of user Return Top:\t" << numUserReturn << endl;
	outputFile << "Total number of user Prints:\t" << numUserPrint << endl;
	outputFile << "Total Number of user Heap Actions:\t" << numHeapUpUser + numHeapDownUser << endl;
	outputFile << "Total number of user Heap-up actions:\t" << numHeapUpUser << endl;
	outputFile << "Total number of user Heap-Down actions:\t" << numHeapDownUser << endl;

	outputFile << "Goodbye :D" << endl;


}
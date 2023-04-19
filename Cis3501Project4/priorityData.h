#pragma once
#include <iostream>
#include <string>
#include <stdexcept> //use this mainly to throw an exception when returnmin or remove min on empty 
#include <fstream>

using namespace std;

//input this priorityData in the array

struct priorityData {

	string dataValue;

	int priorityValue;

	priorityData(string data = "", int priorityValue = 0) : dataValue(data), priorityValue(priorityValue) {};
};
//ARAM ISIKBAY

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

// Input integers from filename into the vector, catch and report errors
void getInput(std::vector<int>& inputList) {
	//Open file
	std::ifstream inputStream;
	std::string fileName = "incseq.txt";
	inputStream.open(fileName);
	//Catch if file cannot be located:
	if (inputStream.fail()) {
		std::cout << "Unable to locate \"" << fileName << "\"" << std::endl;
		exit(1);
	}
	//Catch if file contains any non-integer (non-valid) input
	std::string str;
	while (std::getline(inputStream, str)) {
		try {
			int num = std::stoi(str);
			//Push input to vector
			inputList.push_back(num);
		}
		catch (...) {
			std::cout << "Non-integer data \"" << str << "\" is invalid." << std::endl;
			exit(1);
		}
	}
	inputStream.close();
}

//Recursively print members of the LIS
void printLIS(std::vector<int>x, std::vector<int>L, int index, int max) {
	if (max == 0) {
		return;
	}
	if (L[index] == max) {
		printLIS(x, L, index - 1, max - 1);
		std::cout << x[index] << " ";
	}
	else {
		printLIS(x, L, index - 1, max);
	}
}

//Fill L:
void determineLIS(std::vector<int>& x) {
	int n = x.size();
	//L[j] stores the length of the LIS ending with x[j]
	std::vector<int>L(n,1);
	std::cout << "Input: ";
	for (int i = 0; i < n; i++) {
		std::cout << x[i] << " ";
		for (int j = 0; j < i; j++) {
			if (x[j] < x[i]) {
				L[i] = std::max(L[i], L[j] + 1);
			}
		}
	}
	std::cout << std::endl << std::endl;
	//Get max value of L vector 
	int maxLength = *max_element(std::begin(L), std::end(L));
	//Print LIS length
	std::cout << "LIS length: " << maxLength <<  std::endl << std::endl;
	//Print actual LIS
	std::cout << "LIS: ";
	printLIS(x, L, L.size()-1, maxLength);
	std::cout << std::endl;
}

int main() {
	//Get input values to x
	std::vector<int> x;
	getInput(x);
	//Determine LIS, print length, and print LIS
	determineLIS(x);
	return 0;
}
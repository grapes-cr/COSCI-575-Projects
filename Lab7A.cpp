//Rafael, Caitlin
//Lab 7, 12/06/18
//CS 575, 9 AM

#include <iostream>
#include <fstream>

using namespace std;

ifstream inFile;
ofstream outFile;
const int evenLength = 30;
const int oddLength = 20;
double avg;
void findHighLowAvg(int arr[], int length, double &avg);
void findHigherThanAvg(int arr[], int length, double avg);

int main() {
	int num;
	int evenArray[evenLength];
	int oddArray[oddLength];
	int i = 0;
	int j = 0;
	inFile.open("C:\\Users\\Caitlin\\Desktop\\lab7input.txt"); //CHANGE
	if (!(inFile)) {
		cout << "Error opening file, now exiting";
		exit(1);
	}
	outFile.open("C:\\Users\\Caitlin\\Desktop\\lab7output.txt");
	while (inFile >> num) {
		if ((abs(num) % 2) == 0) {
			evenArray[i] = num;
			i++;
		}
		else if ((abs(num) % 2) == 1) {
			oddArray[j] = num;
			j++;
		}		
	}
	outFile << "Even Array: ";
	for (i = 0; i < evenLength; i++) {
		outFile << evenArray[i] << " ";
	}
	findHighLowAvg(evenArray, evenLength, avg);
	findHigherThanAvg(evenArray, evenLength, avg);
	outFile << endl;
	outFile << "\nOdd Array: ";
	for (j = 0; j < oddLength; j++) {
		outFile << oddArray[j] << " ";
	}
	findHighLowAvg(oddArray, oddLength, avg);
	findHigherThanAvg(oddArray, oddLength, avg);
	inFile.close();
	outFile.close();
	return 0;
}

void findHighLowAvg(int arr[], int length, double &avg) {
	int high, low;
	double total;
	high = arr[0];
	low = arr[0];
	total = arr[0];
	
	for (int k = 1; k < length; k++) {
		if (arr[k] > high) {
			high = arr[k];
		}
		if (arr[k] < low) {
			low = arr[k];
		}
		total += arr[k];
	}
	avg = total / length;
	outFile << endl << "High: " << high << "\tLow: " << low << "\t\tAverage: " << avg;
}

void findHigherThanAvg(int arr[], int length, double avg) {
	outFile << endl << "#'s higher than " << avg << ": ";
	for (int k = 0; k < length; k++) {
		if (arr[k] > avg) {
			outFile << arr[k] << " ";
		}
	}
}

/*
Even Array: 46 30 82 90 56 16 48 26 4 58 0 78 92 60 12 90 14 52 16 80 102 34 10 92 88 66 64 92 66 64
High: 102	Low: 0		Average: 54.2667
#'s higher than 54.2667: 82 90 56 58 78 92 60 90 80 102 92 88 66 64 92 66 64

Odd Array: 17 95 21 63 47 19 41 85 -9 71 79 51 95 79 95 61 89 63 39 5
High: 95	Low: -9		Average: 55.3
#'s higher than 55.3: 95 63 85 71 79 95 79 95 61 89 63 
*/

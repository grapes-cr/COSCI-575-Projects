//Rafael, Caitlin
//Lab 8, 12/06/18
//CS 575, 9 AM

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct data;
ifstream inFile;
const int arrayLength = 16;
double avg;
void sort(struct data tempArr[]);
void read(struct data arr[]);


struct data {
	double income;
	int people;
	string name;
};

struct data tempArray[arrayLength];
struct data temp;

int main() {
	char input;
	string name;
	double income;
	int people;
	double total = 0;
	char toRetry = 'R';

	cout << "Reading input data.." << endl;
	inFile.open("C:\\Users\\Caitlin\\Desktop\\lab8input.txt");
	if (!(inFile)) {
		cout << "Error opening file, now exiting";
		exit(1);
	}
	struct data records[arrayLength];
	int i = 0;
	while (inFile >> name >> income >> people) {
		records[i].name = name;
		tempArray[i].name = name;
		records[i].income = income;
		tempArray[i].income = income;
		records[i].people = people;
		tempArray[i].people = people;
		i++;
	}
	while ((toRetry == 'R') || (toRetry == 'r')) {
		cout << "Input data read. What would you like to do? PRESS: \n'A' to read your data.\n'B' to calculate the average household income and which households have greater income than the average.\n'C' to determine which households have income below poverty level.\n'D' to read the data sorted by income.\n or 'E' to calculate and print the median household income." << endl;
		cin >> input;
		switch (input) {
		case 'A':
		case 'a':
			read(records);
			break;
		case 'B':
		case 'b':
			for (i = 0; i < arrayLength; i++) {
				total += records[i].income;
			}
			avg = total / arrayLength;
			cout << "Average household income is: " << avg << endl;
			cout << "List of households with income higher than " << avg << ": " << endl;
			for (i = 0; i < arrayLength; i++) {
				if (records[i].income > avg) {
					cout << records[i].name << "\t" << records[i].income << endl;
				}
			}
			total = 0;
			break;
		case 'C':
		case 'c':
			cout << "Households with income below poverty level: " << endl;
			for (i = 0; i < arrayLength; i++) {
				if (records[i].income < (8000 + (500 * (records[i].people - 2)))) {
					cout << records[i].name << ", ";
				}
			}
			cout << endl;
			break;
		case 'D':
		case 'd':
			sort(tempArray);
			read(tempArray);
			break;
		case 'E':
		case 'e':
			sort(tempArray);
			if ((arrayLength % 2) == 1) {
				cout << "Median household income is: " << tempArray[(arrayLength / 2) + 1].income << endl;
			}
			else if ((arrayLength % 2) == 0) {
				cout << "Median household income is: " << ((tempArray[(arrayLength / 2)-1].income + tempArray[(arrayLength / 2)].income) / 2.) << endl;
			}
			break;
		default:
			cout << "try again" << endl;
			break;
		}
		cout << "Press 'R' to try another option" << endl;
		cin >> toRetry;
		cout << endl;
	}
	cout << "Now exiting." << endl;
	system("pause");
	system("exit");

}

void read(struct data arr[]) {
	for (int i = 0; i < arrayLength; i++) {
		cout << arr[i].name << "\t" << arr[i].income << "\t" << arr[i].people << "\t" << endl;
	}
}

void sort(struct data tempArr[]) {
	for (int i = 0; i < arrayLength - 1; i++) {
		for (int j = 0; j < arrayLength - i - 1; j++) {
			if (tempArray[j].income > tempArray[j + 1].income) {
				temp = tempArray[j];
				tempArray[j] = tempArray[j + 1];
				tempArray[j + 1] = temp;
			}
		}
	}
}
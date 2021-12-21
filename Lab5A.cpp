//Rafael, Caitlin
//Lab 5A, CS 575 9 AM, 11/6/18
#include <iostream>
#include <fstream>

using namespace std;

ifstream inFile;
ofstream outFile;
int max;
int min;
int total;
int num;

int main() {
	total = 0;
	inFile.open("C:\\Users\\student\\Desktop\\lab5input.txt");
	if (!inFile) {
		cout << "Cannot open file, exiting program" << endl;
		exit(1);
	}
	outFile.open("C:\\Users\\student\\Desktop\\lab5output.txt");
	inFile >> num;
	total += num;
	max = num;
	min = num;
	while (inFile) {
		for (int i = 1; i <= 7; i++) {
			outFile << num << "\t";
			inFile >> num;
			if (num >= max) {
				max = num;
			}
			if (num <= min) {
				min = num;
			}
			total += num;
		}
		total -= num; //I did (total -= num) to get the correct total and average since line 30 adds the next num of the next line to the total
		outFile << "\tMax: " << max << "\tMin: " << min << "\t\tTotal: " << total << "\t\tAverage: " << (total / 7.) << endl; 
		max = num;
		min = num;
		total = 0;
	}
	inFile.close();
	outFile.close();
	return 0;
}

/*
346	130	982	90	656	117	595		Max: 982	Min: 90		Total: 2916		Average: 416.571
415	948	126	4	558	571	87		Max: 948	Min: 4		Total: 2294		Average: 327.714
42	360	412	721	463	47	119		Max: 721	Min: 42		Total: 2122		Average: 303.143
441	190	985	214	509	2	571		Max: 985	Min: 2		Total: 2471		Average: 353
77	81	681	651	995	93	74		Max: 995	Min: 74		Total: 2575		Average: 367.857
310	9	995	561	92	14	288		Max: 995	Min: 9		Total: 1959		Average: 279.857
466	664	892	8	766	34	639		Max: 892	Min: 8		Total: 3003		Average: 429
151	64	98	813	67	834	369		Max: 834	Min: 64		Total: 2245		Average: 320.714
*/
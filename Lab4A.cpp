//Rafael, Caitlin
//CD 575, 10/16/18
//Lab 4A, 9 AM, 10/18/18

#include <iostream>
#include <cstdlib>

using namespace std;

int sum;
int input;
const int MAX = 1000;
bool isPrime(int num);

int main() {
	sum = 0;
	int count = 0;

	char stop = 'c';

	while (stop == 'c') {

		cout << "Input a number, from 1 - 1000 and see if it's prime. \n";
		if ((!(cin >> input)) || (input < 1) || (input > MAX)) {
			cout << "error, try again \n";
			cin.clear();
			cin.ignore(200, '\n');
		}
		else if (isPrime(input)) {
			cout << "That is prime. \n";
		}
		else {
			cout << "That is not prime. \nDivisors of this number: \n";
			for (int i = 1; i <= input; ++i) {
				if ((input % i) == 0) {
					cout << i << "\t";
					sum += i;
					count++;
					if (count == 8) {
						cout << endl;
						count = 0;
					}
				}
			}
			if (sum == (input * 2)) { //I did input*2 since sum+=i adds the input number to the sum 
				cout << "(Number is also a perfect number!)";
			}
			sum = 0;
			cout << endl;
		}
		cout << "Press 'c' to continue or press any other key to stop.\n";
		cin >> stop;
		cout << endl;
	}
	cout << "Now exiting.\n";
	system("pause");
	system("exit");
}

bool isPrime(int num) {
	int count = 0;
	if ((num > 1) && (num < 4)) {
		return true;
	}
	else if (num >= 4) {
		for (int i = 1; i <= num; ++i) {
			if ((num % i) == 0) {
				count++;
			}
		}
		if (count == 2) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

/*
Input a number, from 1 - 1000 and see if it's prime.
-5
error, try again
Press 'c' to continue or press any other key to stop.
c

Input a number, from 1 - 1000 and see if it's prime.
5000
error, try again
Press 'c' to continue or press any other key to stop.
c

Input a number, from 1 - 1000 and see if it's prime.
aaaa
error, try again
Press 'c' to continue or press any other key to stop.
c

Input a number, from 1 - 1000 and see if it's prime.
7
That is prime.
Press 'c' to continue or press any other key to stop.
c

Input a number, from 1 - 1000 and see if it's prime.
28
That is not prime.
Divisors of this number:
1       2       4       7       14      28      (Number is also a perfect number!)
Press 'c' to continue or press any other key to stop.
c

Input a number, from 1 - 1000 and see if it's prime.
496
That is not prime.
Divisors of this number:
1       2
4       8       16      31      62      124     248     496
(Number is also a perfect number!)
Press 'c' to continue or press any other key to stop.
c

Input a number, from 1 - 1000 and see if it's prime.
997
That is prime.
Press 'c' to continue or press any other key to stop.
c

Input a number, from 1 - 1000 and see if it's prime.
864
That is not prime.
Divisors of this number:
1       2       3       4       6       8       9       12
16      18      24      27      32      36      48      54
72      96      108     144     216     288     432     864

Press 'c' to continue or press any other key to stop.
*/
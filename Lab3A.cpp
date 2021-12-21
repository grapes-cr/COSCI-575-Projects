//Rafael, Caitlin
//Sep. 27th Lab 3A
//Co Sci 575, T-Th, 9 AM - 11 AM
#include <iostream>
#include <string>
using namespace std;

string initials;
int side1;
int side2;
int side3;

int main() {
	cout << "Give me your 3 initials." << endl;
	cin >> initials;
	cout << "Now input your sides (no negative #'s)." << endl;
	cin >> side1 >> side2 >> side3;
	if ((side1 < 0) || (side2 < 0) || (side3 < 0)) {
		cout << "There's a negative side. I can't do anything with this!" << endl;
		system("pause");
		return 0;
	}
	if ((side1 + side2 <= side3) || (side2 + side3 <= side1) || (side3 + side1 <= side2)) {
		cout << initials << ": your sides do not make a triangle. ";
		system("pause");
		return 0;
	}
	else {


		if ((side1 == side2) && (side2 == side3) && (side3 == side1)) {
			cout << initials << ": your triangle is equilateral. It is not a right triangle." << endl;
		}
		else if ((side1 == side2) || (side2 == side3) && (side3 == side1)){
				cout << initials << ": your triangle is isosceles. ";
		}
		else {
			cout << initials << ": your triangle is scalene. ";
		}
		if ((side1 * side1) + (side2 * side2) == (side3*side3) || (side2 * side2) + (side3 * side3) == (side1*side1) || (side1 * side1) + (side3 * side3) == (side2*side2)) {
			cout << "Your triangle is a right triangle. ";
			system("pause");
			return 0;
		}
		else {
			cout << "Your triangle is not a right triangle. ";
			system("pause");
			return 0;
		}
	}
}

/*
Give me your 3 initials.
CJR
Now input your sides (no negative #'s).
5
4
3
CJR: your triangle is scalene. Your triangle is a right triangle. Press any key to continue . . .

Give me your 3 initials.
CJR
Now input your sides (no negative #'s).
4
2
2
CJR: your sides do not make a triangle. Press any key to continue . . .

Give me your 3 initials.
CJR
Now input your sides (no negative #'s).
2
5
4
CJR: your triangle is scalene. Your triangle is not a right triangle. Press any key to continue . . .

*/
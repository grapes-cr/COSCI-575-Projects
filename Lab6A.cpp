//Rafael, Caitlin 
// Lab 6, CS 575
//9 AM, 12/6/18

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int ID, hoursError, allowError, allowance; string name; string frstname; string lstname; double wage, hours, wageError, grossAmt, netAmt, weeklyAmt; char status, statusError;
void getData(int &ID, string &frstname, string &lstname, double &wage, double &hours, int &allowance, char &status, int &hoursError, double &wageError, int &allowError, char &statusError, ifstream &inputF, ofstream &errorF);
void sendData(int ID, string name, double wage, double hours, int allowance, double grossAmt, double netAmt, ofstream &outputF);
void calcGrossAmt(double wage, double hours, int allowance, double &grossAmt, double &weeklyAmt);
void calcNetAmt(double grossAmt, double &netAmt, char status, double weeklyAmt);
double taxWithheld(char status, double grossAmt);

int main() {
	ifstream inputF;
	ofstream outputF;
	ofstream errorF;
	inputF.open("C:\\Users\\student.CS.000\\Desktop\\lab6input.txt"); 
	if (!inputF) {
		cout << "Error opening your file, now exiting\n";
		exit(1);
	}
	outputF.open("C:\\Users\\student.CS.000\\Desktop\\lab6output.txt");
	errorF.open("C:\\Users\\student.CS.000\\Desktop\\lab6error.txt");
	while (inputF >> ID >> frstname >> lstname >> wage >> hours >> allowance >> status) {
		getData(ID, frstname, lstname, wage, hours, allowance, status, hoursError, wageError, allowError, statusError, inputF, errorF);
		if ((!(hoursError)) && (!(wageError)) && (!(allowError)) && (!(statusError))) {
			calcGrossAmt(wage, hours, allowance, grossAmt, weeklyAmt);
			calcNetAmt(grossAmt, netAmt, status, weeklyAmt);
			sendData(ID, name, wage, hours, allowance, grossAmt, netAmt, outputF);
		}

	}
	inputF.close();
	outputF.close();
	errorF.close();
	return 0;

}

void getData(int &ID, string &frstname, string &lstname, double &wage, double &hours, int &allowance, char &status, int &hoursError, double &wageError, int &allowError, char &statusError, ifstream &inputF, ofstream &errorF) {
	name = frstname + " " + lstname;
	wageError = (wage < 0);
	hoursError = (hours < 0);
	allowError = (allowance < 0);
	statusError = !((status == 'M') || (status == 'm') || (status == 'S') || (status == 's'));
	if (wageError) {
		errorF << "Error, negative wages: \t\t" << setw(10) << ID << " " << name << ": " << wage << endl;
	}
	if (hoursError) {
		errorF << "Error, negative hours: \t\t" << setw(10) << ID << " " << name << ": " << hours << endl;
	}
	if (allowError) {
		errorF << "Error, negative allowances: \t" << setw(10) << ID << " " << name << ": " << allowance << endl;
	}
	if (statusError) {
		errorF << "Error, invalid marital status: \t" << setw(10) << ID << " " << name << ": " << status << endl;
	}
}

void sendData(int ID, string name, double wage, double hours, int allowance, double grossAmt, double netAmt, ofstream &outputF) {
	outputF << fixed << showpoint << setprecision(2);
	outputF << ID << "\t" << name << "\t" << wage << "\t" << hours << "\t" << allowance << "\t" << "Gross wage: " << grossAmt << "\t" << "Net wage: " << netAmt << endl;
}

void calcGrossAmt(double wage, double hours, int allowance, double &grossAmt, double &weeklyAmt) {
	if (hours > 40) {
		grossAmt = (wage * 40) + ((wage*1.5)*(hours - 40)); //calculate overtime pay
	}
	else {
		grossAmt = wage * hours;
	}
	if (grossAmt > 0) {
		weeklyAmt = grossAmt - (allowance*73.08);
	}
	else {
		weeklyAmt = 0;
	}
}

void calcNetAmt(double grossAmt, double &netAmt, char status, double weeklyAmt) {
	netAmt = (grossAmt - (grossAmt*0.0565)) - taxWithheld(status, weeklyAmt);
}

double taxWithheld(char status, double weeklyAmt) {
	if ((status == 'S') || (status == 's')) {
		if ((weeklyAmt >= 0) && (weeklyAmt <= 721)) {
			return 0;
		}
		else if ((weeklyAmt > 721) && (weeklyAmt <= 7510)) {
			return 93.60 + (.28*weeklyAmt);
		}
		else {
			return 2167.16 + (.35*weeklyAmt);
		}
	}
	else if ((status == 'M') || (status == 'm')) {
		if ((weeklyAmt >= 0) && (weeklyAmt <= 1515)) {
			return 0;
		}
		else if ((weeklyAmt > 1515) && (weeklyAmt <= 7624)) {
			return 187.15 + (.15*weeklyAmt);
		}
		else {
			return 2020.42 + (.30*weeklyAmt);
		}
	}
	else {
		return 0;
	}
}

/*
//Output file

111	Al Clark		38.00	45.50	4	Gross wage: 1833.50		Net wage: 1311.58
123	Joyce Itin		120.00	77.00	3	Gross wage: 11460.00	Net wage: 5419.86
156	Vahid Hamidi	15.00	25.00	3	Gross wage: 375.00		Net wage: 353.81
200	Melody Jung		27.00	60.60	1	Gross wage: 1914.30		Net wage: 1342.81
300	Robert Innes	19.85	40.00	1	Gross wage: 794.00		Net wage: 749.14
350	Angela Klein	0.00	54.32	6	Gross wage: 0.00		Net wage: 0.00
400	Jerry Smith		168.50	36.50	2	Gross wage: 6150.25		Net wage: 4028.02
410	Leslie McHenry	68.00	95.63	1	Gross wage: 8394.26		Net wage: 2840.41
444	Morgan Stock	72.00	99.00	2	Gross wage: 9252.00		Net wage: 3375.06
475	Nick Lee		15.00	5.00	1	Gross wage: 75.00		Net wage: 70.76
490	Mary Jones		45.00	75.36	2	Gross wage: 4186.80		Net wage: 2725.27

//Error file

Error, negative wages: 		       245 Joahn Garcia: -25
Error, negative hours: 		       245 Joahn Garcia: -3
Error, negative allowances: 	   245 Joahn Garcia: -3
Error, invalid marital status: 	   270 Vera Moroz: N
Error, negative wages: 		       320 Mark Armstrong: -25
Error, negative allowances: 	   330 Ashton Williams: -6

*/
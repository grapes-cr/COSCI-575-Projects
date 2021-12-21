//Rafael, Caitlin
//Sep. 9th Lab 2A
//Co Sci 575, T-Th, 9 AM - 11 AM
#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

const double FED_RATE = .18;
const double STATE_RATE = .045;
const double HOSPITALIZATION = 25.65;
const double UNION_DUES = .02;
string employeeName;
double hoursWorked;
double hourlyWage;
double grossWage;
double fedTax;
double stateTax;
double unionTax;
double totalDeductions;
double totalPay;

int main() {
	cout << fixed << showpoint << setprecision(2);
	cout << "Enter employee name: ";
	cin >> employeeName;
	cout << "Enter hours worked: ";
	cin >> hoursWorked;
	cout << "Enter the hourly rate: ";
	cin >> hourlyWage;
	grossWage = hoursWorked * hourlyWage;
	fedTax = grossWage * FED_RATE;
	stateTax = grossWage * STATE_RATE;
	unionTax = grossWage * UNION_DUES;
	totalDeductions = fedTax + stateTax + unionTax + HOSPITALIZATION;
	totalPay = grossWage - totalDeductions;
	cout << "Employee:\t\t" << setw(10) << right << employeeName << endl;
	cout << "Hours Worked:\t\t" << setw(10) << right << hoursWorked << endl;
	cout << "Hourly rate:\t\t" << setw(10) << right << hourlyWage << endl;
	cout << "Total Wages:\t\t" << setw(10) << right << grossWage << endl;
	cout << "Deductions" << endl;
	cout << "Federal Withholding:\" << setw(10) << right << fedTax << endl;
	cout << "State Withholding:" << setw(10) << right << stateTax << endl;
	cout << "Hospitalization:\t" << setw(10) << right << HOSPITALIZATION << endl;
	cout << "Union Dues:\t" << setw(10) << right << unionTax << endl;
	cout << "Total Deductions:" << setw(10) << right << totalDeductions << endl;
	cout << "Net Pay:\t" << setw(10) << right << totalPay << endl;
	system("pause");
	system("exit");

	/*
	Employee:  ABC
	Hours Worked:  40
	Hourly rate:  8.75
	Total Wages:  350
	Deductions
	Federal Withholding:  63
	State Withholding:  15.75
	Hospitalization:  25.65
	Union Dues:  7
	Total Deductions:  111.4
	Net Pay:  238.6
	Press any key to continue . . .
	*/
}
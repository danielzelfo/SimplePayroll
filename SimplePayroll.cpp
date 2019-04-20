/*  Program: Simple Payroll (with extra credit 1&2)
Author: Daniel Zelfo
Class: CSCI 110
Date: 9/26/2018
Description: Displays user's Payroll Information including gross pay, tax deducations and netpay
Altered on 10/1/2018 to work with multiple employees and show their total payroll information

I certify that the code below is my own work.

Exception(s): N/A

*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//prototypes
void programInfo();
void inputDataC(string out, char& data);
void inputDataS(string out, string& data);
void inputDataD(string out, double& data);
void getGrossPay(double hours, double rate, double& grossPay);
void getTax(double grossPay, double& socialTax, double& federalTax, double& stateTax, double& totalTax, double& totalSocialTax, double& totalFederalTax, double& totalStateTax);
void outputData(bool employee, string name, double grossPay, double socialTax, double federalTax, double stateTax, double netPay, double hours = 0, double rate = 0);

int main()
{
	char contin;
	string name;
	double hours, rate, grossPay, socialTax, federalTax, stateTax, totalTax, netPay, totalGrossPay = 0, totalSocialTax = 0, totalFederalTax = 0, totalStateTax = 0, totalNetPay = 0;
	int numEmployees = 0;
	programInfo();

	contin = 'y';
	while (contin == 'y')
	{
		inputDataS("\nEnter employee name: ", name);
		inputDataD("Enter hours worked: ", hours);
		inputDataD("Enter hourly rate: ", rate);
		getGrossPay(hours, rate, grossPay);
		totalGrossPay += grossPay;
		getTax(grossPay, socialTax, federalTax, stateTax, totalTax, totalSocialTax, totalFederalTax, totalStateTax);
		netPay = grossPay - totalTax;
		totalNetPay += netPay;
		numEmployees += 1;
		outputData(true, name, grossPay, socialTax, federalTax, stateTax, netPay, hours, rate);
		inputDataC("\n\nWould you like to continue with another employee (y/n)? ", contin);
	}
	if (numEmployees > 1)
		outputData(false, "All Employees", totalGrossPay, totalSocialTax, totalFederalTax, totalStateTax, totalNetPay);
	cout << "\n\nThank you for using my program.\n";

	return 0;
}

void programInfo()
{
	cout << "Simple Payroll Program v1.0\nAuthor: Daniel Zelfo\n";
}

void inputDataC(string out, char& data)
{
	cout << out;
	cin >> data;
}
void inputDataD(string out, double& data)
{
	cout << out;
	cin >> data;
}
void inputDataS(string out, string& data)
{
	cout << out;
	cin >> data;
}

void getGrossPay(double hours, double rate, double& grossPay)
{
	if (hours <= 40)
		grossPay = hours*rate;
	else if (hours <= 60)
		grossPay = 40 * rate + (hours - 40)*1.5*rate;
	else
		grossPay = 60 * rate + 30 * rate + (hours - 60) * 2 * rate;
}

void getTax(double grossPay, double& socialTax, double& federalTax, double& stateTax, double& totalTax, double& totalSocialTax, double& totalFederalTax, double& totalStateTax)
{
	socialTax = .085*grossPay;
	totalSocialTax += socialTax;
	federalTax = .1*grossPay;
	totalFederalTax += federalTax;
	stateTax = .05*grossPay;
	totalStateTax += stateTax;
	totalTax = socialTax + federalTax + stateTax;
}

void outputData(bool employee, string name, double grossPay, double socialTax, double federalTax, double stateTax, double netPay, double hours, double rate)
{
	cout << fixed << showpoint << setprecision(2) << endl;
	if (employee)
		cout << name << " worked " << hours << " hours with an hourly rate of $" << rate << ".\n";
	if (rate >= 10.00 || !employee)
		cout << "Weekly salary statement for " << name << ":\n\tGross pay: " << grossPay << "\n\tSocial security tax: " << socialTax << "\n\tFederal tax: " << federalTax << "\n\tState tax: " << stateTax << "\n----------------------------------------\n\tNet pay: " << netPay;
	else
		cout << "Input error: below minimum wage of $10.00.";
}

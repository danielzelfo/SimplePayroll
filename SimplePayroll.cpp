/*  Program: Simple Payroll
Author: Daniel Zelfo
Class: CSCI 110
Date: 9/26/2018
Description: Displays user's Payroll Information including gross pay, tax deducations and netpay

I certify that the code below is my own work.

Exception(s): N/A

*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//prototypes
void programInfo();
void inputDataS(string out, string& data);
void inputDataD(string out, double& data);
void getGrossPay(double hours, double rate, double& grossPay);
void getTax(double grossPay, double& socialTax, double& federalTax, double& stateTax, double& totalTax);
void outputData(string name, double hours, double rate, double grossPay, double socialTax, double federalTax, double stateTax, double netPay);

int main()
{
	string name;
	double hours, rate, grossPay, socialTax, federalTax, stateTax, totalTax, netPay;
	
	programInfo();
	inputDataS("\nEnter employee name: ", name);
	inputDataD("Enter hours worked: ", hours);
	inputDataD("Enter hourly rate: ", rate);
	getGrossPay(hours, rate, grossPay);
	getTax(grossPay, socialTax, federalTax, stateTax, totalTax);
	netPay = grossPay - totalTax;
	outputData(name, hours, rate, grossPay, socialTax, federalTax, stateTax, netPay);
	cout << "\n\nThank you for using my program.\n";

	return 0;
}

void programInfo()
{
	cout << "Simple Payroll Program v1.0\nAuthor: Daniel Zelfo\n";
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

void getTax(double grossPay, double& socialTax, double& federalTax, double& stateTax, double& totalTax)
{
	socialTax = .085*grossPay;
	federalTax = .1*grossPay;
	stateTax = .05*grossPay;
	totalTax = socialTax + federalTax + stateTax;
}

void outputData(string name, double hours, double rate, double grossPay, double socialTax, double federalTax, double stateTax, double netPay)
{
	cout << fixed << showpoint << setprecision(2) << endl << name << " worked " << hours << " hours with an hourly rate of $" << rate << ".\n";
	if (rate >= 10.00)
		cout << "Weekly salary statement for " << name << ":\n\tGross pay: " << grossPay << "\n\tSocial security tax: " << socialTax << "\n\tFederal tax: " << federalTax << "\n\tState tax: " << stateTax << "\n----------------------------------------\n\tNet pay: " << netPay;
	else
		cout << "Input error: below minimum wage of $10.00.";
}

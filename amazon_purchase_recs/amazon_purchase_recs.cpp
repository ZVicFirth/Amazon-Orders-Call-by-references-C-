/*
Name:  Zachary Firth                               
Z# : Z23543282
Course : Foundations of Computer Science(COP3014)
Professor : Dr.Lofton Bullard
Due Date : 2/9/22 Due Time : 11:59pm
Total Points : 20
Assignment #3: amazon_purchase_recs.cpp
Description : To declare and initialize variables from an outside file (purchase_dataAssignment4.txt)
by using call-by-reference functions and printing the inputs and also the outputs based on these inputs*/
//Include the following
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//Prototypes for your functions: input, output, and process will go here

void input(ifstream&, string&, string&, double&, double&, int&);
void output(string, string, double, double, int, double, double, double, double);
void process(double, double, int, double&, double&, double&, double&);

//Name:  input
//Precondition: The variables cell_number, item_number, quantity, price, and processing_plant have not been initialized. 
//Postcondition: The variables cell_number, item_number, quantity, price, and processing_plant have been initialized.

//Description:  
// Example:Get the input values for cell_number, item_number, quantity, price, and processing_plant from data file.


void input(ifstream& in, string& cell_number, string& item_number, double&
	quantity, double& price, int& processing_plant) 
{
	in >> cell_number >> item_number >> quantity >> price >> processing_plant;
	
}

//Name:  output
//Precondition: The variables cell_number, item_number, quantity, price, processing_plant, tax_rate, order_tax, net_cost,
// and total_cost have not been intialized and/or printed.
//Postcondition: The variables cell_number, item_number, quantity, price, processing_plant, tax_rate, order_tax, net_cost,
// and total_cost have been intialized and printed.
//Description:  Get the input and output values from data file based off the process function and print them out.


void output(string cell_number, string item_number, double quantity, double price,
	int processing_plant, double tax_rate, double order_tax, double net_cost, double
	total_cost)
{

	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	cout << setw(15) << left << cell_number 
		<< setw(10) << left << item_number 
		<< setw(6) << right << (int)quantity 
		<< setw(10) << right << price 
		<< setw(8) << right << processing_plant 
		<< setw(8) << right << (int)tax_rate 
		<< setw(10) << right << order_tax 
		<< setw(10) << right << net_cost 
		<< setw(10) << right << total_cost <<endl;
	
}


//Name:  process
//Precondition: The output values (tax_rate, order_tax, net_cost,and total_cost) have not been caluclated
//Postcondition: The output values (tax_rate, order_tax, net_cost,and total_cost) have been caluclated
//Description:  Calculate the output values based off the input values (cell_number, item_number, quantity, price, and processing_plant)


void process(double quantity, double price, int processing_plant, double&
	tax_rate, double& order_tax, double& net_cost, double& total_cost)
{
	if (0 <= processing_plant && processing_plant <= 50)
		tax_rate = 6;
	else if (51 <= processing_plant && processing_plant <= 11)
		tax_rate = 7;
	else if (111 <= processing_plant && processing_plant <=
		200)
		tax_rate = 8;
	else if (201 <= processing_plant && processing_plant <=
		500)
		tax_rate = 9;
	else if (501 <= processing_plant)
		tax_rate = 11;
	order_tax = quantity * price * (tax_rate / 100);
	net_cost = quantity * price;
	total_cost = net_cost + order_tax;
}

//Driver
int main()
{
	string cell_number;
	string item_number;
	double quantity;
	double price;
	int processing_plant;
	double tax_rate;
	double order_tax;
	double net_cost;
	double total_cost;
	ifstream in;    
	in.open("purchase_dataAssignment4.txt");
	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		while (!in.eof())
		{
			input(in, cell_number, item_number, quantity, price,
				processing_plant);
			process(quantity, price, processing_plant, tax_rate, order_tax, net_cost, total_cost);
			output(cell_number, item_number, quantity, price, processing_plant, tax_rate, order_tax, net_cost, total_cost);
		}
	}
	in.close();
	return 0;
}

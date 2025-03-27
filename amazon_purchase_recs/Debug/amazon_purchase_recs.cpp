/*
Name:  Zachary Firth                               
Z# : Z23543282
Course : Foundations of Computer Science(COP3014)
Professor : Dr.Lofton Bullard
Due Date : 2/9/22 Due Time : 11:59pm
Total Points : 20
Assignment #3: amazon_purchase_recs.cpp
Description :
*/
//Include the following
#include <iostream>
#include <string>
#include <fstream>  
using namespace std;
//Prototypes for your functions: input, output, and process will go here
void input(ifstream&, string&, string&, double&, double&, int&);
void output(string, string, double, double, int, double, double, double, double);
void process(double, double, int, double&, double&, double&, double&);
//Function Implementations will go here
///
***********************************************************************************
**
//Name:  input
//Precondition: State what is true before the function is called.
// Example: the varialbes (formal parameters) have not been initialized
//Postcondition: State what is true after the function has executed.
// Example: the varaibles (formal parameters) have been initialized
//Description:  
// Example:Get input (values of cell_number, item_number, quantity, price, 
//processing_plant )
//from data file.
//PURPOSE: 
//

void input(ifstream& in, string& cell_number, string& item_number, double&
	quantity, double& price, int& processing_plant)
{
	in >> cell_number >> item_number >> quantity >> price >> processing_plant;
	
}

//Name:  output
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//
***********************************************************************************
**
void output(string cell_number, string item_number, double quantity, double price,
	int processing_plant, double tax_rate, double order_tax, double net_cost, double
	total_cost)
{
	//Use thee following statement to help you format you our output. These 
	statements are called the magic formula.
		cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	/********************************************/
	//cout << cell_number << "\t";
	//add more code to print all the variables
}
///

//Name:  process
//Precondition: The state what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//

//Note: there is one 1 input/output parameter
void process(double quantity, double price, int processing_plant, double&
	tax_rate, double& order_tax, double& net_cost, double& total_cost)
{
	//put your code here to process/calculate the tax_rate, order_tax, net_cost, 
	//and total_cost
}
//Here is your driver to test the program
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
	ifstream in;    //declaring an input file stream
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

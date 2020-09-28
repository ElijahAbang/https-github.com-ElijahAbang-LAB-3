/*
Elijah Abang
C++ Fall 2020
Due: 9/28/2020
Write an interactive C++ program that computes and outputs the mean and  population standard deviation of a set of four integers
that are inputted by a file called “inMeanStd.dat” and the user (should handle both). Although the individual values are integers,
the results are floating-point values. Be sure to use proper formatting and appropriate comments in your code.
Provide appropriate prompts to the user. The output should be to the screen for the user inputted values and to a file called
“outMeanStd.dat”. The programs output should be labeled clearly and formatted neatly. You must calculate the mean and standard
deviation in separate functions.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

float mean_Function(int, int, int, int); //prototype for the mean functinon
float std_Function(int, int, int, int, float); // prototype for the population standard deviation  function


int main()
{
	//input data
	int input1;
	int input2;
	int input3;
	int input4;
	ifstream infile;
	ofstream outfile;

	//open files
	infile.open("inMeanStd.dat");
	outfile.open("outMeanStd.dat");

	//read values of the input file
	infile >> input1 >> input2 >> input3 >> input4;



	//puts the calculated values in the document
	outfile << "This is the mean of the integers in the document: " << mean_Function(input1, input2, input3, input4) << endl;
	outfile << "This is the population standard deviation of the integers in the document: " << std_Function(input1, input2, input3, input4, mean_Function(input1, input2, input3, input4)) << endl << endl << endl;

	//the user inputs values
	cout << "Fill in 4 integers and press enter after each" << endl;
	cin >> input1 >> input2 >> input3 >> input4;

	//outputs the calulated values that the user put in the document
	outfile << endl << "This is the mean of the integers that user filled in:  " << mean_Function(input1, input2, input3, input4);
	outfile << endl << "This is the population standard deviation of the integers that user filled in:  " << std_Function(input1, input2, input3, input4, mean_Function(input1, input2, input3, input4)) << endl;

	//outputs the calulated values that the user put on the screen
	cout << "This is the mean of the integers that user filled in: " << mean_Function(input1, input2, input3, input4) << endl;
	cout << "This is the population standard deviation of the integers that user filled in: " << std_Function(input1, input2, input3, input4, mean_Function(input1, input2, input3, input4)) << endl;






	return 0;

}

float mean_Function(int input1, int input2, int input3, int input4) //Function defintion of the mean function
{
	return (float(input1 + input2 + input3 + input4) / float(4));
}

float std_Function(int input1, int input2, int input3, int input4, float average) //Function defintion of the population standard deviation
{
	return sqrt((float(pow((input1 - average), 2) + pow((input2 - average), 2) + pow((input3 - average), 2)) + pow((input4 - average), 2)) / 4);
}
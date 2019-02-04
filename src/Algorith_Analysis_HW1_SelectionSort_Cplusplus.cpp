// File        : Algorithm_Analysis_HW1_SelectionSort_Cplusplus
// Author      : John Carvajal
// Description : Implement the selection sort algorithm. This program accepts an input file
// name as a command line argument. The first line of data in file file is the number of
// elements to sort, and the input elements are separated by a new line. Implements the algorithm
// as a function in each program. You are also required to measure the wall clock time of
// the implemented algorithm.
// Usage       : Pass the input file name in with the command line argument


//includes
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
//#include <ctime>

//function prototypes
void selectionSort(int arr[], int n);

int main(int argc,char** argv)
{
	std::cout << "Program has started.\n";
	std::cout << "Author: John Carvajal\n";

	//check to see if command line argument is valid
	if (argc < 1)
	{
		std::cout << "Error: No command line argument provided\n";
	}
	else
	{
		//try to open the file
		//create string named fileName
		std::string fileName;

		//store command line argument in fileName
		fileName = argv[1];

		//create ifstream object and pass it file name
		std::ifstream inFile(fileName.c_str());

		//error message if file name does not exist
		if(!inFile)
		{
			std::cout << "Error: Unable to open file named " << fileName << std::endl;
			return -1;
		}

        //print file name
		std::cout << "File name is: " << fileName << std::endl << std::endl;
		//get the first line to store size of the array we need, and create array
		std::string firstLine;
		getline(inFile,firstLine);
		int numInputs = std::stoi(firstLine);
		int dataToSort[numInputs];

		//loop through the rest of the data and store in dataToSort
		std::cout << "input:" << std::endl;
		std::cout << "[";
		bool firstNumFlag = true;
		std::string str;
		int x = 0;
		int i = 0;
		while(!inFile.eof())
		{
			inFile >> x;
			dataToSort[i] = x;
			i++;
			if (i == numInputs)
			{
				std::cout << x;
			}
			else
			{
			std::cout << x << ", ";
			}
		}
		std::cout << "]\n";

		//start the clock
		std::clock_t c_start = std::clock();
		auto t_start = std::chrono::high_resolution_clock::now();

		//perform the selection sort
		selectionSort(dataToSort, numInputs);

		//stop the clock
		std::clock_t c_end = std::clock();
		auto t_end = std::chrono::high_resolution_clock::now();

		std::cout << "Elapsed time: "<< std::chrono::duration<double, std::milli>(t_end-t_start).count()<< " ms" << std::endl;

		//print out the sorted data
		std::cout << "output:" << std::endl;
		std::cout << "[";
		for (int i = 0; i < numInputs; i++)
		{
			if (i == numInputs-1)
			{
				std::cout << dataToSort[i];
			}
			else
			{
				std::cout << dataToSort[i] << ", ";
			}

		}
		std::cout << "]\n";

		//close file
		inFile.close();

		std::cout << "Program has ended.\n";
	}
	return 0;
}

void selectionSort(int arr[], int n)
{
	int i, j, minIndex, tmp;
	for (i = 0; i < n - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
			if (minIndex != i)
			{
				tmp = arr[i];
				arr[i] = arr[minIndex];
				arr[minIndex] = tmp;
            }
      }
}



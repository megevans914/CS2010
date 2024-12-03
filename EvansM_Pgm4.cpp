//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Program: This program reads numerical data from a uder-determined file and creates a data summary, including a bar graph and a list of first, second, and third largest and smallest values, stopping when the value 9999 is reached. It takes special steps to correctly format and compute with negative values and large values.
// Process: First, the program asks the user for a file, making sure the file selected is one that is actually openable. Next, it checks to make sure the file opened properly with no errors. Then, a while loop is used to read data values until the sentinel value of 9999 is reacked. Within this while loop, the program computes largest and smallest values using else-if statements. Then, within this while loop, the program outputs a "bar graph" depicting each number with Xs. The program also determines if a particular value read is larger than 112 (the threshold value) or negative, formatting output for those lines red or blue, respectively. Finally, outside of the while loop, the program creates the X-axis and outputs the largest and smallest values.
// Results: The final result of this program is a bar graph with a Y-axis showing how many values have been read and the corresponding place on the list for any particular value. The X-axis shows numbers by 10 that make it easier to read the actual bars, which are the numbers read displayed as Xs. For example, if the fifth number in a list is 30, the output for that line would be " 5 | " and 30 Xs.

// Class: CS2010
// Section: 1001
// Term: Fall 2024
// Author: Megan Evans
//
// Reflection: This program was particularly challenging, but I enjoyed and rose to the challenge. One aspect that went well was the use of a switch statement. It is a concept I kind of forgot about, but I remembered it for this assignment and enjoyed its simplicity compared to if-else statements. Something that was difficult was the computation of the largest and smallest values. I struggled with this computation, particularly the order in which to put the statements and the proper initialization and assignment of variables. However, through trial and error and a lot of effort, I was able to make it work. In order to do better next time, I should refresh my knowledge of that type of computation using loops.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <windows.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
HANDLE hConsole;
int main() {
   //declare variables
   hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   const int WHITE = 7;
   ifstream fileFS;
   string fileName;
   int fileChoice;
   int value;
   int countAll = 0;
   int countInvalid = 0;
   int numValues;
   int small1 = 9999;
   int small2 = 9999;
   int small3 = 9999;
   int large1 = 0;
   int large2 = 0;
   int large3 = 0;
   const char OUTPUT_X = 'X';
   const char OUTPUT_SPACE = ' ';
   
   //output menu for files, using a do-while loop for data validation
   do {
      cout << "Select file to process: \n";
      cout << "1. mixed.txt\n2. valid.txt\n3. three.txt\n4. missing.txt";
      cout << "\n\nChoice: ";
      cin >> fileChoice;
      cout << "\n\n";
   }
   while ((fileChoice != 1) && (fileChoice != 2) && (fileChoice != 3) && (fileChoice != 4));
   
   //set fileName
   switch (fileChoice) {
      case 1:
         fileName = "mixed.txt";
         break;
      case 2:
         fileName = "valid.txt";
         break;
      case 3:
         fileName = "three.txt";
         break;
      case 4:
         cout << "\n\nERROR: Data file not found.";
         return 1;
         break;
   }
   
   //open file, check if opened properly
   fileFS.open(fileName);
   if (!(fileFS.is_open())) {
      cout << "ERROR: file could not be opened.";
      return 1;
   }

   //main while loop to read values until sentinel is reached
   fileFS >> value;
   cout << "Bar graph for data contained in " << fileName << " file.\n\n";
   while (value != 9999) {
      ++ countAll;
      
      //calculate largest and smallest values
      if (value > large1) {
         large3 = large2;
         large2 = large1;
         large1 = value;
      }
      else if (value > large2) {
         large3 = large2;
         large2 = value;
      }
      else if (value > large3) {
         large3 = value;
      }
      if (value < small1) {
         small3 = small2;
         small2 = small1;
         small1 = value;
      }
      else if (value < small2) {
         small3 = small2;
         small2 = value;
      }
      else if (value < small3) {
         small3 = value;
      }
      
      //executes if value is positive and less than or equal to 112
      if ((value > 0) && (value <= 112)) {
        
         //one digit numbers get a space added
         if (countAll <= 9) {
            cout << OUTPUT_SPACE << countAll << " | ";
         }
         else {
            cout << countAll << " | ";
         }
         int i;
         for (i = 0; i < value; ++i) {
            cout << OUTPUT_X;
         }
         cout << "\n";
      } //end of if statement
      
      //executes if value is negative
      else if (value < 0) {
         ++countInvalid;
         value = fabs(value);
         
         //one digit numbers get a space added
         if (countAll <= 9) {
            cout << OUTPUT_SPACE << countAll << " | ";
         }
         else {
            cout << countAll << " | ";
         }
         int i;
         for (i = 0; i < value; ++i) {
            SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE);
            cout << OUTPUT_X;
         }
         SetConsoleTextAttribute(hConsole, WHITE);
         cout << "\n";
      } //end of if statement
      
      //executes if value is greater than 112
      else if (value > 112) {
         ++countInvalid;
         cout << countAll << " | ";
         SetConsoleTextAttribute(hConsole, BACKGROUND_RED);
         int i;
         for (i = 0; i < 112; ++i) {
            cout << OUTPUT_X;
         }
         SetConsoleTextAttribute(hConsole, WHITE);
         cout << "\n";
      }
      fileFS >> value; //update at end of loop
   } //end of main while loop
   
   fileFS.close(); //close file
   //format the x axis
   cout << setfill('-') << setw(121) << "\n";
   cout << setfill(OUTPUT_SPACE) << setw(6) << "1";
   int j;
   for (j = 10; j < 115; j = j + 10) {
      cout << "        " << j;
   }
   
   //display smallest, largest, and invalid
   cout << "\n\nSMALLEST\n========\n";
   cout << "The smallest value: " << small1 << "\n";
   cout << "2nd smallest value: " << small2 << "\n";
   cout << "3rd smallest value: " << small3 << "\n\n";
   cout << "LARGEST:\n=======\n";
   cout << "The largest value: " << large1 << "\n";
   cout << "2nd largest value: " << large2 << "\n";
   cout << "3rd largest value: " << large3 << "\n\n";
   if (countInvalid != 0) {
      cout << "INVALID:\n=======\n";
      cout << "There are " << countInvalid << " invalid values in the data.";
   }
   if (countInvalid == 1) {
      cout << "INVALID:\n=======\n";
      cout << "There is " << countInvalid << " invalid value in the data.";
   }
   return 0;
}
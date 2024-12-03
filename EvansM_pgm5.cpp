//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Program: The purpose of this program is to read data regarding US states' finanaces, then run calculations on it and return a neatly formatted list in addition to the average budget, the state with the highest budget, the state with the highest surplus, and the state with the lowest population.
// Process: This program reads data from a file containing data formatted like
    //State name
    //Population
    //Budget
    //Revenue
//The program reads in all these files to four different arrays. Then, it outputs onto a file the data in neat columns, displaying the state's name, population, budget, and revenue on one line. After outputting this, the program uses a for loop to calcualte average budget, max budget, max surplus, and min population, and prints these values at the end of the file. Finally, the program closes the files and ends.
// Results: The result is a neat table displaying all the states' financial information in a readable format, along with the requested "highlight" values below this table.
//
// Class: CS2010
// Section: 1001
// Term: Fall 2024
// Author: Megan Evans
//
// Reflection: I enjoyed this programming assignment. I previously struggled with loops, but now, having worked with them a lot on multiple different occasions, they are becoming easier for me to understand. This assignment also helped me to get a better understanding of the output manipulators, which is another concept with which I had been struggling.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
int main() {

//declare variables
const int STATES = 50;
ifstream infile;
ofstream outfile;
string statename[STATES];
int population[STATES];
double budget[STATES];
double revenue[STATES];
int i;
double sumBudget = 0;
double averageBudget;
double maxBudget;
double maxSurplus;
int minPopulation;
string stateHighestBudget;
string stateHighestSurplus;
string stateLowestPop;

//open file
infile.open("pgm5.txt");
outfile.open("report5.txt");

//check if files were successfully opened; 
if (!(infile.is_open())) {
    return 1;
   }
if(!(outfile.is_open())) {
    return 1;
}

//read data into arrays using sentinel loop with eof()
while (!(infile.eof())) {
    for (i = 0; i < STATES; ++i) {
        getline(infile, statename[i]);
        infile >> population[i];
        infile.ignore();
        infile >> budget[i];
        infile.ignore();
        infile >> revenue[i];
        infile.ignore();
    }
}

//format header
outfile << "=========================================================" << endl;

outfile << left << setw(1) << "#";
outfile << "    ";
outfile << left << setw(14) << "Name";
outfile << "      ";
outfile << right << setw(10) << "Population";
outfile << "   ";
outfile << right << setw(7) << "Budget";
outfile << "   ";
outfile << right << setw(7) << "Revenue";
outfile << "  ";
outfile << endl;

outfile << left << setw(1) << "-";
outfile << "    ";
outfile << left << setw(14) << "----";
outfile << "      ";
outfile << right << setw(10) << "----------";
outfile << "   ";
outfile << right << setw(7) << "------";
outfile << "   ";
outfile << right << setw(7) << "-------";
outfile << "  ";
outfile << endl;

//iterate through, print each state's data in tubular form
for (i = 0; i < STATES; ++i) {
    outfile << fixed << setprecision(2);
    if (i < 10) {
        outfile << left << setw(2) << i + 1;
        outfile << "   ";
    }
    else {
        outfile << left << setw(2) << i + 1;
        outfile << "   "; 
    }
    outfile << left << setw(14) << statename[i];
    outfile << "      ";
    outfile << right << setw(10) << population[i];
    outfile << "   ";
    outfile << right << setw(7) << budget[i];
    outfile << "   ";
    outfile << right << setw(7) << revenue[i];
    outfile << "  ";
    outfile << endl;
}

//for loop to calculate the average state budget, find the state with the highest budget, the state with the highest surplus and the state with the lowest population.
maxBudget = budget[0];
minPopulation = population[0];
maxSurplus = revenue[0] - budget[0];

    for (i = 0; i < STATES; ++i) {
        sumBudget = sumBudget + budget[i];
        averageBudget = sumBudget / STATES;

        if (budget[i] > maxBudget) {
            maxBudget = budget[i];
            stateHighestBudget = statename[i];
        }
        if (population[i] < minPopulation) {
            minPopulation = population[i];
            stateLowestPop = statename[i];
        }
        if ((revenue[i] - budget[i]) > maxSurplus) {
            maxSurplus = revenue[i] - budget[i];
            stateHighestSurplus = statename[i];
        }
    }

//output values
outfile << endl << endl;
outfile << "The average state budget is $" << averageBudget << " billion." << endl;
outfile << stateHighestBudget << " has the highest budget : $" << maxBudget << " billion." << endl;
outfile << stateHighestSurplus << " has the highest surplus: $" << maxSurplus << " billion." << endl;
outfile << stateLowestPop << " has the lowest population : " << minPopulation << " people.";

//close files
infile.close();
outfile.close();
return 0;
}
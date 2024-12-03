//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Program: This program reads data from two files and creates a summary in the terminal, as well as a different summary in a file named out.txt.
// Process: The program uses six user-defined functions (plus a main function) to read, process, and write data regarding state hurricane statistics.

// Results: What are the calculated results
    //readHurricaneData() reads from pgm6.txt and reads values into the parallel arrays used in this program.
    //readStateLookUpTable() reads the state names from statelookup.txt and puts them into an array.
    //printHurricaneData() (the first one) prints out the data in a readable format.
    //mostHitState() returns the index of the state hit by the most hurricanes.
    //statesHitByCat5Hur() outputs which states were hit by category 5 hurricanes and which one was hit by the most category 5 hurricanes.
    //printHurricaneData() (the second one) calculates total hurricane hits and major hurricane hits for each state and writes it to a file named out.txt.
// Class: CS2010
// Section: 1001
// Term: Fall 2024
// Author: Megan Evans
//
// Reflection: This assignment was challenging in a good way. It was a it difficult to keep track of all the functions, arrays, variables, and data values, and sometimes using the wrong thing in a calculation or output statement causes strange errors. However, I believe I've come away from this assignment with a better understanding of how to use user-defined functions.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//Declare constants
const int MAX_STATE = 18;
const string DATA_FILE = "pgm6.txt";
const string STATE_LOOKUP_FILE = "statelookup.txt";
const string OUT_FILE = "out.txt";

//Declare globals
ifstream pgm6;
ofstream out;

int readHurricaneData(string stateAbbr[], int numHur[], int cat3Hur[], int cat4Hur[], int cat5Hur[]) {
    //open file
    pgm6.open(DATA_FILE);
    
    //check if file failed to open
    if (!(pgm6.is_open())) {
        cout << "Did not read" << endl;
        return -1;
    }
    //run these statements if file opened successfully
    else {
        //declare local variables
        int i;
        int numState = 18;

        //read data into arrays
        for (i = 0; i < MAX_STATE; ++i) {
            pgm6 >> stateAbbr[i];
            pgm6.ignore();
            pgm6 >> numHur[i];
            pgm6.ignore();
            pgm6 >> cat3Hur[i];
            pgm6.ignore();
            pgm6 >> cat4Hur[i];
            pgm6.ignore();
            pgm6 >> cat5Hur[i];
        }
        pgm6.close();

        return numState;
    }
    //close file
}

int readStateLookUpTable(string stateAbbr[], string stateNames[]) {
    //declare local variables
    int i = 0;
    int num = MAX_STATE;
    
    //open file
    pgm6.open(STATE_LOOKUP_FILE);
    
    //if file failed to open
    if (!pgm6.is_open()) {
        return -1;
    }
    //run this if file opened properly
    else {
        //read data
        while (!pgm6.eof()) {
            pgm6.ignore(3);
            getline(pgm6, stateNames[i]);
            ++i;
        }
    //close file
    pgm6.close();
    }

    //return value
    return num;
}

int mostHitState(int numHur[], int num) {
    //declare local variables
    num = numHur[0]; //num will hold the index of the state with the most hits
    int i;
    int max_i;

    //loop through array
    for (i = 0; i < MAX_STATE; ++i) {
        if (numHur[i] > num) {
            num = numHur[i];
            max_i = i;
        }
    }
    //return
    return max_i; //index of state hit most
}

void statesHitByCat5Hur(string stateNames[], int cat5Hur[], int num) {

    //declare local variables and array
    int indexOfStateHitByCat5Hur[MAX_STATE] = {};
    int i;
    int cntState = 0;
    int stateHitMax = cat5Hur[0];
    int stateHitMaxIndex = 0;

    //loop through cat5Hur[], print their state names
    for (i = 0; i < MAX_STATE; ++i) {
        if (cat5Hur[i] != 0) {
            indexOfStateHitByCat5Hur[cntState] = i;
            ++cntState;
        }
    }
    //output three states
    cout << "Among the " << MAX_STATE << " states, " << cntState << " states were hit by Category 5 hurricanes between 1900 and 2000:" << endl;
    for (i = 0; i < cntState; ++i) {
        cout << "- " << stateNames[indexOfStateHitByCat5Hur[i]] << " with " << cat5Hur[indexOfStateHitByCat5Hur[i]] << " Category 5 hurricane(s)" << endl;
    }

    //loop through indexOfStateHitByCat5Hur[] to find the state that got hit the most
    for (i = 0; i < MAX_STATE; ++i) {
        if (cat5Hur[i] > stateHitMax) {
            stateHitMax = cat5Hur[i]; //this returns the number of cat5 hurricanes hit the state with the most, in this case 2.
            stateHitMaxIndex = i;
        }
    }
    //Florida got hit by the most hurricanes, and Florida has an index of 3 in the stateNames[] array. stateHitMax needs to equal three.
    cout << stateNames[stateHitMaxIndex] << " was hit by the most Category 5 hurricanes during this period." << endl;
}

void printHurricaneData(string stateNames[], int numHur[], int cat3Hur[], int cat4Hur[], int cat5Hur[], int num) {

    //declare local variables
    int i = 0;

    cout << "======================================================================" << endl;
    cout << left << setw(20) << "State Name" << left << setw(20) << "Hurricane Hits" << left << setw(10) << "CAT3" << left << setw(10) << "CAT4" << left << setw(10) << "CAT5" << endl;
    for (i = 0; i < MAX_STATE; ++i) {
        cout << left << setw(20) << stateNames[i] << left << setw(20) << numHur[i] << left << setw(10) << cat3Hur[i] << left << setw(10) << cat4Hur[i] << left << setw(10) << cat5Hur[i] << endl;
    }
    cout << "======================================================================" << endl;
 
}

void printHurricaneData(string stateNames[], int numHur[], int cat3Hur[], int cat4Hur[], int cat5Hur[], int num, string fName) {

    //open file
    out.open(fName);

    //declare local variables
    int i;
    int totalHurricaneHits = 0;
    int majorHurricaneHits = 0;

    //output
    out << left << setw(20) << "State Name" << left << setw(30) << "Total Hurricane Hits" << left << setw(10) << "Major Hurricane Hits (Category 3 and Above)" << endl;
    for (i = 0; i < MAX_STATE; ++i) {
        if (i == MAX_STATE - 1) {
            out << left << setw(20) << stateNames[i] << left << setw(30) << numHur[i] << left << setw(10) << cat3Hur[i] + cat4Hur[i] + cat5Hur[i];  
        }
        else {
            out << left << setw(20) << stateNames[i] << left << setw(30) << numHur[i] << left << setw(10) << cat3Hur[i] + cat4Hur[i] + cat5Hur[i] << endl;
        }
    }
    

    //close file
    out.close();
}

int main() {

    //You should only call the last four functions when the two file reading functions are success. The details about the user-defined functions are explained in the rest of the numbered list.
        //Print a summative sentence in the main function using the returned value of mostHitState(...) as shown in the sample output.
        //NO NEED to print the content written to out.txt file in the console/terminal.
        //see directions for what the console output should look like

    //declare arrays
    string stateAbbr[MAX_STATE]; // a list of 2-letter abbreviation of the states hit by hurricanes
    string stateNames[MAX_STATE]; // a list of the full name of the states hit by hurricanes
    int numHur[MAX_STATE]; // the total number of hurricane hits for a state
    int cat3Hur[MAX_STATE], cat4Hur[MAX_STATE], cat5Hur[MAX_STATE]; // the number of Cat 3 hurricane hits for a state
    int cntCat3AndAbove[MAX_STATE]; // the total number of CAT3, CAT4, and CAT5 hurricanes

    //declare local variables
    int num;
    string fName = "out.txt"; //FIXME: assign a real value
    int test1;
    int test2;

    test1 = readHurricaneData(stateAbbr, numHur, cat3Hur, cat4Hur, cat5Hur);
    test2 = readStateLookUpTable(stateAbbr, stateNames);

    if (test1 == -1 || test2 == -1) {
        return 1;
    }
    else {

        printHurricaneData(stateNames, numHur, cat3Hur, cat4Hur, cat5Hur, num);
        cout << "Between 1900 and 2000, " << stateNames[mostHitState(numHur, num)] << " was hit by the most hurricanes, with a total of " << numHur[mostHitState(numHur, num)] << "." << endl;
        //mostHitState(numHur, num);
        statesHitByCat5Hur(stateNames, cat5Hur, num);
        printHurricaneData(stateNames, numHur, cat3Hur, cat4Hur, cat5Hur, num, fName);
        return 0;
    }

}
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//Program: This is a program designed to act as a simple cashier at an ice cream shop, taking orders, calculating change, and printing a receipt.
//Process: First, this program prints out a list of ice cream choices for the customer to choose from. If the customer does not decide to quit by pressing five, they will make an ice cream choice. Then, after the customer has made a choice and the program has assured its validity, the customer is prompted to choose a type of cone, and the program assures the validity of the cone choice as well. Next, the program tells the customer what they ordered and its price. The program next computes the cost deficit and/or change, if applicable, based on the user's inputted money. Finally, the receipt is printed.
//Results: The results will be different each time depending on ice cream choice and money. The program calculates the results by taking the price of the ice cream ordered and comparing it to the amount of money the customer has provided. If they have not provided enough money, the program asks for more money, adding the money together until the correct amount is reached or exceeded. In the amount of excess money, the program subtracts the ice cream price from the amount of money provided to calculate change for the customer.
//
//Class: CS2010
//Section: 1001
//Term: Fall 2024
//Author: Megan Evans
//
//Reflection: I enjoyed making this program. It was very straightforward, which is something I enjoy in a programming assignment. I also realized in the middle of it that I was wasting a lot of time and space by creating a ton of if-else statements for each ice cream type, so I optimized it by adding the cost variable. This represents a shift in my thinking due to learning programming; I am beginning to become aware of the simple, logical solution to problems instead of the overly complicated solution.
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    //Variable declaration
    const double ROCKY = 2.5;
    const double STORMY = 3.25;
    const double BLIZZARD = 3.75;
    const double SUPERCELL = 4.25;
    int iceCreamChoice;
    string coneChoice;
    string combinedOrder;
    double amountPaid;
    double newPayment;
    double changeBack;
    double cost;

    //Ice cream choices
    cout << "---------------------------------------------------------" << endl;
    cout << setw(20) << left << "1. Rocky";
    cout << setw(1) << left << "$";
    cout << setw(5) << left << fixed << setprecision(2) << ROCKY << endl;

    cout << setw(20) << left << "2. Stormy";
    cout << setw(1) << left << "$";
    cout << setw(5) << left << fixed << setprecision(2) << STORMY << endl;

    cout << setw(20) << left << "3. Blizzard";
    cout << setw(1) << left << "$";
    cout << setw(5) << left << fixed << setprecision(2) << BLIZZARD << endl;

    cout << setw(20) << left << "4. SuperCell";
    cout << setw(1) << left << "$";
    cout << setw(5) << left << fixed << setprecision(2) << SUPERCELL << endl;

    cout << "5. Quit" << endl;
    cout << "---------------------------------------------------------" << endl;

    //Ice cream choice
    cout << "Enter your choice of ice creams: ";
    cin >> iceCreamChoice;
    while (!((iceCreamChoice > 0) && (iceCreamChoice <= 5))) {
        cout << "Invalid Choice, please re-enter: ";
        cin >> iceCreamChoice;
    }
    if (iceCreamChoice == 5) {
        cout << "Goodbye!";
        return 0;
    }
    cout << "---------------------------------------------------------" << endl;

    //Cone choice
    cout << "Waffle" << endl << "Sugar" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "Enter your choice of cones: ";
    cin >> coneChoice;
    while (!((coneChoice == "Waffle") || (coneChoice == "Sugar"))) {
        cout << "Invalid Choice, please re-enter: ";
        cin >> coneChoice;
    }
    cout << "---------------------------------------------------------" << endl;

    //Order and receipt
    cout << "You have ordered a " << endl;
    if (coneChoice == "Waffle") {
        if (iceCreamChoice == 1) {
            combinedOrder = "Waffle Cone Rocky ice cream";
        }
        else if (iceCreamChoice == 2) {
            combinedOrder = "Waffle Cone Stormy ice cream";
        }
        else if (iceCreamChoice == 3) {
            combinedOrder = "Waffle Cone Blizzard ice cream";
        }
        else if (iceCreamChoice == 4) {
            combinedOrder = "Waffle Cone SuperCell ice cream";
        }
    }
    else if (coneChoice == "Sugar") {
        if (iceCreamChoice == 1) {
            combinedOrder = "Sugar Cone Rocky ice cream";
        }
        else if (iceCreamChoice == 2) {
            combinedOrder = "Sugar Cone Stormy ice cream";
        }
        else if (iceCreamChoice == 3) {
            combinedOrder = "Sugar Cone Blizzard ice cream";
        }
        else if (iceCreamChoice == 4) {
            combinedOrder = "Sugar Cone SuperCell ice cream";
        }
    }
    cout << combinedOrder;

    //Tell the customer the price
    cout << endl << "that will be ";
    if (iceCreamChoice == 1) {
        cout << "$" << fixed << setprecision(2) << ROCKY << endl;
    }
    else if (iceCreamChoice == 2) {
        cout << "$" << fixed << setprecision(2) << STORMY << endl;
    }
    else if (iceCreamChoice == 3) {
        cout << "$" << fixed << setprecision(2) << BLIZZARD << endl;
    }
    else if (iceCreamChoice == 4) {
        cout << "$" << fixed << setprecision(2) << SUPERCELL << endl;
    }
    cout << "---------------------------------------------------------" << endl;

    //Calculate money values
    cout << "Enter the amount to pay: ";
    cin >> amountPaid;
    if (iceCreamChoice == 1) {
        cost = ROCKY;
    }
    else if (iceCreamChoice == 2) {
        cost = STORMY;
    }
    else if (iceCreamChoice == 3) {
        cost = BLIZZARD;
    }
    else if (iceCreamChoice == 4) {
        cost = SUPERCELL;
    }
        
    if (amountPaid < cost) {
        while (amountPaid < cost) {
            cout << "You still owe: $" << (cost - amountPaid) << endl;
            cout << "Enter additional payment: ";
            cin >> newPayment;
            amountPaid = amountPaid + newPayment;
        }
    }
    if (amountPaid >= cost) {
        changeBack = amountPaid - cost;
    }

    //Print final receipt
    cout << "---------------------------------------------------------" << endl;
    cout << "Here is your: " << combinedOrder << "!" << endl;
    
    cout << setw(20) << left << "Cost: ";
    cout << setw(1) << left << "$";
    cout << setw(5) << left << fixed << setprecision(2) << cost << endl;

    cout << setw(20) << left << "Paid";
    cout << setw(1) << left << "$";
    cout << setw(5) << left << fixed << setprecision(2) << amountPaid << endl;

    cout << setw(20) << left << "Change Back: ";
    cout << setw(1) << left << "$";
    cout << setw(5) << left << fixed << setprecision(2) << changeBack << endl;

    cout << "---------------------------------------------------------" << endl;


    return 0;
}
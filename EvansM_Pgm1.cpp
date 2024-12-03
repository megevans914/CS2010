//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-
// Program: This is a program used to help a movie theater calculate its gross sales, net profit, and how much should be paid to a movie's distributor.
// Description of input data needed by the program when you run it: This program needs three input values: a movie title, the number of adult tickets sold, and the number of children's tickets sold.
// Process (calculations): describe how the program computes the solution: This program computes the gross ticket sales by multiplying the price of the adult ticket by the number of adult tickets sold and multiplying the price of the child ticket by the number of child tickets sold. It computes the net profit by calculating 80% of the gross ticket sales, and it computes the amount paid to the movie distributor by calculating 20% of the gross ticket sales.
// Results: What are the calculated results? The calculated results are, in a neat format, the movie title, the number of adult and child tickets sold, the calculated gross sales, the calculated net profit, and the calculated amount paid to the movie distributor.
//
//Class: CS2010
//Section: 1001
//Term: Fall 2024
//Author: Megan Evans
//
//Reflection: This assignment was very helpful in learning some of the basics of C++ coding! I have never used a "real" code environment before, so this was a good introduction to that. Some things that initially worked well for me were assigning the correct variable types. However, I had some initial struggles too; I made a few silly math errors, and almost forgot the getline statement when reading the movie title. I only realized that I needed that statement when I tried "Harry Potter" for the title and my program failed. Overall, this was a great learning experience!
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    //declare all variables
    const double PERCENT_PROFIT = 0.8;
    string movieTitle;
    int adultTickets;
    int childTickets;
    double grossTicketSales;
    double netProfit;
    double amountPaid;
    double adultTicketPrice = 11.50;
    double childTicketPrice = 7.75;

    //assign values to variables
    cout << "Enter the movie title: ";
    getline(cin, movieTitle); //in case the movie title is more than one word
    
    cout << "How many adult tickets were sold: ";
    cin >> adultTickets;

    cout << "How many children's tickets were sold: ";
    cin >> childTickets;

    //perform calculations
    grossTicketSales = (adultTickets * adultTicketPrice) + (childTickets * childTicketPrice);
    netProfit = grossTicketSales * PERCENT_PROFIT; //what theater makes after subtracting 20% owed to movie distributor
    amountPaid = grossTicketSales - (grossTicketSales * PERCENT_PROFIT); //subtract 80%
    
    //output
    cout << "Gross Ticket Sales for \'" << movieTitle << "\': $" << fixed << setprecision(2) << grossTicketSales << endl;
    cout << "Theater Net Profit: $" << fixed << setprecision(2) << netProfit << endl;
    cout << "Amount Paid to Distributor: $" << fixed << setprecision(2) << amountPaid << endl;
    
    return 0;
}
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Program: This is a program that is designed to get user input for the number and type of Cedar Point passes and meal plans, calculate different costs and charges based on these inputs, and print a reciept for that customer.
// Process: First, the program takes input for the type of pass, how many, the type of meal, and how many (if any). Then, the program calculates admission cost, meal cost, discount, subtotal, tax, and total. Finally, the program uses left, right, setw, and setprecision to print these results in receipt format.
// Results:
//   Admission cost is calculated by multiplying the price corresponding to the admission type by the number of admissions.
//   Meal cost is calculated by multiplying the price corresponding to the meal type by the number of meals.
//   Discount is calculated by using an if statement to determine which discount rate to use based on the cost of admissions, then multiplying the cost of admissions by the appropriate discount rate. To get the price left over, that result is subtracted from the admisson cost.
//   Parking is calculated by using an if statement to check if the user has inputted a gold or platinum pass. If they have not, the cost of parking is set equal to $20.00. If the pass is gold or platinum, parking is free.
//   Subtotal is calculated by adding the cost of meals, parking (if there is any), and admission price after discount.
//   Tax is calculated by multiplying the tax rate by the subtotal.
//   Total is calculated by adding the tax to the subtotal.
//
// Class: CS2010
// Section: 1001
// Term: Fall 2024
// Author: Megan Evans
//
// Reflection: This program was an incredible exercise of the skills I learned during this unit. I really enjoy these programming assignments because I get to put in practice what I learn in the textbook, and as someone who prefers to learn by doing, this is an ideal way to assess and grow my knowledge and skills. One challenge I had during the process of building this program was that I struggled with calculating the discount and the price after discount. I kept having logic errors, and I had to try many different solutions in order to make the code work as intended. Overall, this was an incredible learning experience!
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   //declare and assign constant variables
   const double PLATINUMPRICE = 230.0;
   const double GOLDPRICE = 135.0;
   const double TWODAYPRICE = 70.0;
   const double DAYPRICE = 45.0;

   const double ALLDAYMEAL = 31.55;
   const double SINGLEMEAL = 14.95;
   const double ENTREEMEAL = 8.25;
   const double NONEMEAL = 0.0;

   const double PARKING = 20.0;

   const double DISCOUNT_1000 = 0.15;
   const double DISCOUNT_500 = 0.10;
   const double DISCOUNT_100 = 0.05;

   const double TAXRATE = 0.07;

   //get input, declare and assign non-constant variables
   
   //admission type
   string admissionType;
   int numberAdmissions;
   
   cout << "enter your admission choice(platinum, gold, twoday or day): ";
   cin >> admissionType;
   
   if ((admissionType == "platinum") || (admissionType == "gold") || (admissionType == "twoday") || (admissionType == "day")) {
      cout << "how many " << admissionType << ": ";
      cin >> numberAdmissions;
   }
   else {
      cout << "Invalid Admission Entry";
      return 0;
   }
      

   //meal type
   string mealType;
   int numberMeals;
  
   cout << "enter your meal choice(allday, single, entree or none): "; //FIXME: ask about possible typo in instructions (you instead of your)
   cin >> mealType;

   //number of meals
   if (mealType == "none") {
      numberMeals = 0;
   }
   else if ((mealType == "allday") || (mealType == "single") || (mealType == "entree")) {
      cout << "how many " << mealType << ": ";
      cin >> numberMeals;
   }
   else {
      cout << "Invalid Meal Entry";
      return 0;
   }


   //Calculate the admission cost based on admission price and admission type entered
   double admissionCost;

   if (admissionType == "platinum") {
      admissionCost = numberAdmissions * PLATINUMPRICE;
   }
   else if (admissionType == "gold") {
      admissionCost = numberAdmissions * GOLDPRICE;
   }
   else if (admissionType == "twoday") {
      admissionCost = numberAdmissions * TWODAYPRICE;
   }
   else if (admissionType == "day") {
      admissionCost = numberAdmissions * DAYPRICE;
   }

   //Calculate meal cost based on meal price and meal type
   double mealCost;

   if (mealType == "allday") {
      mealCost = numberMeals * ALLDAYMEAL;
   }
   else if (mealType == "single") {
      mealCost = numberMeals * SINGLEMEAL;
   }
   else if (mealType == "entree") {
      mealCost = numberMeals * ENTREEMEAL;
   }
   else if (mealType == "none") {
      mealCost = numberMeals * NONEMEAL;
   }

   //Calculate discount
   double admissionDiscount;
   double costMinusDiscount;

   if (admissionCost >= 1000.0) {
      admissionDiscount = admissionCost * DISCOUNT_1000;
      costMinusDiscount = admissionCost - admissionDiscount;
   }
   else if (admissionCost >= 500.0) {
      admissionDiscount = admissionCost * DISCOUNT_500;
      costMinusDiscount = admissionCost - admissionDiscount;
   }
   else if (admissionCost >= 100.0) {
      admissionDiscount = admissionCost * DISCOUNT_100;
      costMinusDiscount = admissionCost - admissionDiscount;  
      }
   else {
      costMinusDiscount = admissionCost;
   }
   

   //Calculate subtotal based on admission cost, meal cost, parking, and discount
   double subTotal;
   double parkingPrice;

   if ((admissionType == "platinum") || (admissionType == "gold")) {
      parkingPrice = 0;
   }
   else {
      parkingPrice = PARKING;
   }
   subTotal = costMinusDiscount + mealCost + parkingPrice;

   //Calculate tax based on a 7% rate applied to subtotal
   double tax = subTotal * TAXRATE;

   //calculate total
   double total = subTotal + tax;

   //print a receipt
   cout << "-----------------------------------" << endl;
   cout << "Cedar Point:" << endl;
   cout << "-----------------------------------" << endl;

   cout << setw(20) << left << "Admission";
   cout << setw(1) << left << ":";
   cout << setw(7) << left << numberAdmissions;
   cout << setw(23) << left << admissionType << endl;
   
   cout << setw(20) << left << "Meal";
   cout << setw(1) << left << ":";
   cout << setw(7) << left << numberMeals;
   cout << setw(23) << left << mealType << endl;
   cout << "-----------------------------------" << endl;

   cout << setw(20) << left << "Admission Cost";
   cout << setw(1) << left << "$";
   cout << setw(12) << right << fixed << setprecision(2) << admissionCost << endl;

   cout << setw(20) << left << "Meal Cost";
   cout << setw(1) << left << "$";
   cout << setw(12) << right << fixed << setprecision(2) << mealCost << endl;
   
   cout << setw(20) << left << "Parking";
   cout << setw(1) << left << "$";
   cout << setw(12) << right << fixed << setprecision(2) << parkingPrice << endl;
   

   cout << setw(20) << left << "Admission Discount";
   cout << setw(1) << left << "$";
   cout << setw(12) << right << fixed << setprecision(2) << admissionDiscount << endl;
   
   cout << setw(20) << left << "Subtotal";
   cout << setw(1) << left << "$";
   cout << setw(12) << right << fixed << setprecision(2) << subTotal << endl;

   cout << "-----------------------------------" << endl;
   cout << "-----------------------------------" << endl;

   cout << setw(20) << left << "Tax";
   cout << setw(1) << left << "$";
   cout << setw(12) << right << fixed << setprecision(2) << tax << endl;
   
   cout << "-----------------------------------" << endl;
   
   cout << setw(20) << left << "Final Total";
   cout << setw(1) << left << "$";
   cout << setw(12) << right << fixed << setprecision(2) << total << endl;

   cout << "\n\n";


   return 0;
}
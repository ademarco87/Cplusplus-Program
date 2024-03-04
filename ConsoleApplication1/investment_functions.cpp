// investment_functions.cpp
#include <iostream>
#include <iomanip>
#include "investment_functions.h"

namespace InvestmentFunctions {
    void displayInputForm() {
        std::cout << "++++++++++++++++++++++++++++++++\n";
        std::cout << "++++++++++ Data Input ++++++++++\n";
        // Display your input form here
    }

    void getDataFromUser(float& initialInv, float& monthlyDep, float& annualInt, float& years) {
        while (true) {
            std::cout << "Initial Investment Amount: $";
            if (std::cin >> initialInv && initialInv > 0) {
                break;  // Exit the loop if input is valid
            }
            else {
                std::cout << "Invalid input. Please enter a positive numeric value.\n";
                std::cin.clear();  // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
            }
        }

        // Get monthly deposit with input validation
        while (true) {
            std::cout << "Monthly Deposit: $";
            if (std::cin >> monthlyDep && monthlyDep >= 0) {
                break;
            }
            else {
                std::cout << "Invalid input. Please enter a numeric value.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        // Get annual interest rate with input validation
        while (true) {
            std::cout << "Annual Interest: %";
            if (std::cin >> annualInt && annualInt >= 0) {
                break;
            }
            else {
                std::cout << "Invalid input. Please enter a numeric value.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        // Get number of years with input validation
        while (true) {
            std::cout << "Number of years: ";
            if (std::cin >> years && years > 0) {
                break;
            }
            else {
                std::cout << "Invalid input. Please enter a positive numeric value.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        // Increase number of years input by 12
        years += 12;
    }

    void calculateAndDisplayResults(float initialInv, float monthlyDep, float annualInt, float years) {
        // Set initial total amount
        float totalAmt = initialInv;

        // Display year data without monthly deposits
        std::cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
        std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        std::cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
        std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

        for (int i = 0; i < years; i++) {
            // Declare variables within the scope
            float yearTotalInt = 0;

            for (int j = 0; j < 12; j++) {
                // Calculate monthly interest
                float interestAmt = (totalAmt) * ((annualInt / 100) / 12);
                // Calculate month-end total
                totalAmt = totalAmt + interestAmt;
                // Accumulate month-end interest for the year
                yearTotalInt = yearTotalInt + interestAmt;
            }

            // Print results to the table showcasing only two decimal points
            std::cout << (i + 1) << "\t\t$" << std::fixed << std::setprecision(2) << totalAmt << "\t\t\t$" << yearTotalInt << "\n";
        }
    }

    void calculateAndDisplayResultsWithMonthly(float initialInv, float monthlyDep, float annualInt, float years) {
        float totalAmt = initialInv;

        std::cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
        std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        std::cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
        std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        for (int i = 0; i < years; i++) {
            // Set yearly interest to zero at the start of the year
            float yearTotalInt = 0;
            for (int j = 0; j < 12; j++) {
                // Calculate monthly interest
                float interestAmt = (totalAmt + monthlyDep) * ((annualInt / 100) / 12);
                // Calculate month-end interest
                yearTotalInt = yearTotalInt + interestAmt;
                // Calculate month-end total
                totalAmt = totalAmt + monthlyDep + interestAmt;
            }
            // Print results to the table showcasing only two decimal points
            std::cout << (i + 1) << "\t\t$" << std::fixed << std::setprecision(2) << totalAmt << "\t\t\t$" << yearTotalInt << "\n";
        }
    }
}

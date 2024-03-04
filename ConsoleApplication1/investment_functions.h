// investment_functions.h
#pragma once

namespace InvestmentFunctions {
    void displayInputForm();
    void getDataFromUser(float& initialInv, float& monthlyDep, float& annualInt, float& years);
    void calculateAndDisplayResults(float initialInv, float monthlyDep, float annualInt, float years);
    void calculateAndDisplayResultsWithMonthly(float initialInv, float monthlyDep, float annualInt, float years);
}

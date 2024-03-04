#include "investment_functions.h"
using namespace InvestmentFunctions;

int main() {
    displayInputForm();

    float initialInv, monthlyDep, annualInt, years;
    getDataFromUser(initialInv, monthlyDep, annualInt, years);

    calculateAndDisplayResults(initialInv, monthlyDep, annualInt, years);

    calculateAndDisplayResultsWithMonthly(initialInv, monthlyDep, annualInt, years);

    return 0;
}

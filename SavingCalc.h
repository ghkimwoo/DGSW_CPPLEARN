#pragma once
#include <iostream>
#define SAVING_DATE 1
#define SAVING_HALF 2
#define YEAR_DATE 12
using namespace std;



class CSavingsCalculator {
public:
    void SavingsNormalCalc();
    void SavingsTaxCalc();
    int SavingsPrintResult();
    int monthlypay;
    int period = YEAR_DATE;
    const float interestrate = 0.04f;
    const float tax = 0.154f;
    int SavingsNormalResult;
    int SavingsTaxResult;
};

void CSavingsCalculator::SavingsNormalCalc()
{
    SavingsNormalResult = (monthlypay * interestrate * (period + SAVING_DATE) * period / SAVING_HALF) / YEAR_DATE;
}

void CSavingsCalculator::SavingsTaxCalc()
{
    SavingsTaxResult = SavingsNormalResult - (SavingsNormalResult * tax);
    SavingsTaxResult += monthlypay * period;
}
int CSavingsCalculator::SavingsPrintResult() {
    cout << "적금만기수령액: " << SavingsTaxResult << "원" << endl;
    return SavingsTaxResult;
}
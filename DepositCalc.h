#pragma once
#include <sstream>
#include <locale>
#include <string>
#include <iostream>
#define YEARDATE 12
using namespace std;

class CDepositCalculator {
public:
    void DepositNormalCalc();
    void DepositTaxCalc();
    int DepositPrintResult();
    int pay;
    int period = YEARDATE;
    const float interestrate = 0.03f;
    const float tax = 0.154f;
    int DepositNormalResult;
    int DepositTaxResult;
};

void CDepositCalculator::DepositNormalCalc()
{
    DepositNormalResult = pay * interestrate;
}

void CDepositCalculator::DepositTaxCalc()
{
    DepositTaxResult = DepositNormalResult - (DepositNormalResult * tax);
    DepositTaxResult += pay * period;
}
int CDepositCalculator::DepositPrintResult() {
    cout << "예금 만기 수령액: " << DepositTaxResult << "원" << endl;
	return DepositTaxResult;
}
#define _CRT_SECURE_NO_WARNINGS
#include "DepositCalc.h"
#include "SavingCalc.h"
#include "TaxCalc.h"
#define THISYEAR 2023
#define HUNDRED 100
#define CONSUMPTION 15600000
#define LINE 50000000

int main(void) {
	CInsurance insurance;
	int pay, income, nottax, realpay, fullpay = 0;
	float uppay;
	cout << "연봉을 입력하세요: ";
	cin >> pay;
	cout << "연봉인상율을 입력하세요: ";
	cin >> uppay;
	cout << "비과세액을 입력하세요: ";
	cin >> nottax;
	for (int i = 0; i < 10; i++) {
		pay = pay * (1 + (i * uppay) / HUNDRED) - nottax;
		insurance.Get(pay);
		realpay = insurance.Print();
		realpay -= CONSUMPTION;

		if (fullpay != 0) {
			CDepositCalculator DepositCalc;
			DepositCalc.pay = fullpay;
			DepositCalc.DepositNormalCalc();
			DepositCalc.DepositTaxCalc();
			fullpay = DepositCalc.DepositPrintResult();
		}
		CSavingsCalculator SavingsCalc;
		SavingsCalc.monthlypay = realpay / YEARDATE;
		SavingsCalc.SavingsNormalCalc();
		SavingsCalc.SavingsTaxCalc();
		fullpay += SavingsCalc.SavingsPrintResult();
		cout << THISYEAR + i << "년도 총 자산은 " << fullpay << "원" << endl;
	}
	
}
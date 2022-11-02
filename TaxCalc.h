#pragma once
#include <iostream>
#include "Incometax.h"
using namespace std;
#define NATION_PER 4.5
#define HEALTH_PER 3.495
#define CARE_PER 12.27
#define EMPLOY_PER 0.9
#define LOCALINCOME_PER 10
#define INCOMETAX 100

class CInsurance {
public:
	void Get(int param) {
		nation = param * NATION_PER / 100;
		health = param * HEALTH_PER / 100;
		care = health * CARE_PER / 100;
		care = care - care % 10;
		employ = param * EMPLOY_PER / 100;
		income;
		incomecalc(param);
		localincome = income * LOCALINCOME_PER / 100;
		realpay = param - nation - health - care - employ - income - localincome;
	}
	
	void incomecalc(int param) {
		int tableSize = sizeof(table);
		param / INCOMETAX;
		for (int i = 0; i < tableSize; i++)
		{
			if ((table[i].start <= param) && (table[i].end > param))
			{
				income = table[i].tax * INCOMETAX;
				break;
			}
		}
	}

	int Print() {
		cout << "공제액 합계" << endl;
		cout << "국민연금 = " << nation << endl;
		cout << "건강보험 = " << health << endl;
		cout << "고용보험 = " << employ << endl;
		cout << "장기요양 = " << care << endl;
		cout << "소득세 = " << income << endl;
		cout << "지방소득세 = " << localincome << endl;
		cout << "실 수령액 = " << realpay << endl;
		return realpay;
	}

	
private:
	int realpay;
	int nation;
	int health;
	int care;
	int employ;
	int income;
	int localincome;
};
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
		cout << "������ �հ�" << endl;
		cout << "���ο��� = " << nation << endl;
		cout << "�ǰ����� = " << health << endl;
		cout << "��뺸�� = " << employ << endl;
		cout << "����� = " << care << endl;
		cout << "�ҵ漼 = " << income << endl;
		cout << "����ҵ漼 = " << localincome << endl;
		cout << "�� ���ɾ� = " << realpay << endl;
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
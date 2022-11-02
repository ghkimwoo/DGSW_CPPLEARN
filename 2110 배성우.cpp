#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;
#define NATION_PER 4.5
#define HEALTH_PER 3.495
#define CARE_PER 12.27
#define EMPLOY_PER 0.9
#define LOCALINCOME_PER 10
#define NOTTEX 200000

class CInsurance {
public:
	void Get(int param, int incomeparam) {
		nation = param * NATION_PER / 100;
		health = param * HEALTH_PER / 100;
		care = health * CARE_PER / 100;
		care = care - care % 10;
		employ = param * EMPLOY_PER / 100;
		income = incomeparam;
		localincome = incomeparam * LOCALINCOME_PER / 100;
		realpay = param - nation - health - care - employ - income - localincome + NOTTEX;
	}
	
	void Print() {
		cout << "4대보험 계산결과" <<endl;
		cout << "국민연금 : " << nation << endl;
		cout << "건강보험 : " << health << endl;
		cout << "고용보험 : " << employ << endl;
		cout << "장기요양보험 : " << care << endl;
		cout << "소득세 :" << income << endl;
		cout << "지방소득세 : " << localincome << endl;
		cout << "실 수령액 : " << realpay << endl;
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

int main(void) {
	CInsurance insurance;
	int pay, income;
	cout << "급여를 입력하세요 (단위 : 원) : ";
	cin >> pay;
	cout << "소득세를 입력하세요 (단위 : 원) : ";
	cin >> income;
	pay = (pay / 12) - NOTTEX;
	insurance.Get(pay, income);
	cout << "급여 " << pay << "원의 계산 결과를 알려드립니다." << endl;
	insurance.Print();
	
}
#include <iostream>
using namespace std;

//대문자 구분 방법
//S : Saving(적금)
//N : Normal(세전)
//T : Tax(세후)
//M : Main(메인과의 변수 구분용)

float tax = 0.154f;
float interestrate = 0.0355f;

class CSavingsInfo
{
public:
    int monthlypay;
    int period;
};

class CSUser {
public:
    
    int SNCalc(CSavingsInfo info);
    int STCalc(int SNMResult);
};

int CSUser::SNCalc(CSavingsInfo info)
{
    
    int SNresult = 0;

    SNresult = (info.monthlypay * interestrate * (info.period + 1) * info.period / 2) / 12 - 5;
    return SNresult;
}

int CSUser::STCalc(int SNMResult)
{
    int STresult = SNMResult - (SNMResult * tax);
    return STresult;
}


int main()
{

    CSUser user;
    CSavingsInfo savingsInfo;


    //사용자 값 입력
    cout << "월납입금액을 입력하세요 : ";
    cin >> savingsInfo.monthlypay;
    cout << "목표기간을 입력하세요 : ";
    cin >> savingsInfo.period;

    //이자 계산 및 원금 계산
    int SNMResult = user.SNCalc(savingsInfo);
    int STMResult = user.STCalc(SNMResult);
    SNMResult += savingsInfo.monthlypay * savingsInfo.period;
    STMResult += savingsInfo.monthlypay * savingsInfo.period;

    //출력
    cout << "적금시 세전 합계는 " << SNMResult << "입니다." << endl;
    cout << "적금시 세후 합계는 " << STMResult << "입니다." << endl;
}

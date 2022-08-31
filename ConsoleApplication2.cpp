#include <iostream>
using namespace std;
class CUser {
public:
    CUser()
    {
        cout << "생성자 호출" << endl;
    }
    ~CUser() {
        cout << "소멸자 호출" << endl;
    }
    int nData = 10;
    void PrintData() {
        cout << nData << endl;
    }
};

int main()
{
    CUser user;
    user.PrintData();
}
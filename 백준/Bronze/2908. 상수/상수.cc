#include <iostream>

using namespace std;


int Swap(int temp)
{
    int a, b, c, result;
    a = temp / 100;
    b = temp / 10 - a * 10;
    c = temp % 10;

    result = c * 100 + b * 10 + a;
    return result;
}

int main()
{
    int C1, C2;
    cin >> C1 >> C2;

    int num1, num2;
    num1 = Swap(C1);
    num2 = Swap(C2);
    
    if (num1 >= num2) {
        cout << num1;
    }
    else {
        cout << num2;
    }




}
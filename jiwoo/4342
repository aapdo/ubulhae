#include <iostream>

using namespace std;

void euclid(long long int a, long long int b, bool winner)
{
    long long int N = max(a, b); // 두 수 중 큰 수
    long long int n = min(a, b); // 두 수 중 작은 수
    long long int k = N % n; // 큰 수 를 작은 수로 나눈 나머지
    if (k == 0) // 큰 수가 작은수의 배수일때 게임을 종료함
    {
        if (winner == true)
            cout << "A wins" << endl;
        else
            cout << "B wins" << endl;
    }
    else   
        {
            if (N / n > 1) // 17 6 ->  11 6 or 5 6
            {
                if (winner == true)
                    cout << "A wins" << endl;
                else
                    cout << "B wins" << endl; // 이 경우 winner가 뒤집히지 않고 게임을 진행할 수 있음 엥 무조건 이기는거네?
            } // 99 93 -> 93 6 -> 3 4 or 7 4 -> 1 4 -> 0
            else
            {
                euclid(n, k, !winner); // 이 경우는 큰 수에서 자기자신을 뺴야하는 경우만 포함됨
            }
        }
}

long long int gcd(long long int a, long long int b)
{
    long long int mod = a % b;

    while (mod > 0)
    {
        a = b;
        b = mod;
        mod = a % b;
    }

    return b;
}

int main() {

    long long int a_number;
    long long int b_number;
    long long int proposition;

    while(1)
    {
        cin >> a_number >> b_number;

        if (a_number == 0 || b_number == 0) // 종료 조건
        {
            break;
        }

        else
        {
            proposition = gcd(a_number, b_number); // 최대공약수
            euclid(a_number / proposition, b_number / proposition, true); // 유클리드 함수에 a와 b를 최대공약수로 나누고 넣음
        }

    }
    return 0;
}

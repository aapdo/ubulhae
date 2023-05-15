#include <iostream>
#include <vector>

using namespace std;

// 2 3 5 7 등 소수의 제곱들 중, M,m사이에서 저들의 배수가 되는 것들
// 소수를 찾는 것과 비슷하다 하지만 4 9 16 등으로만 나누어지지만 않으면 된다 (소수의 수보다 답이 많을 것임 예를 들어 6은 제곱 ㄴㄴ 수)
// 1, 1000이라면 500이하의 소수의 제곱들이랑만 검증하면 되긴함 그래도 범위가 너무 큼
// 4의 배수중 M에 가장가까운 수의 자료들을 모은다면? 4가있으니 8 12 16 ... 등 만들고 ㅇㅋ ㄱ

int main() {
	
	long long m, M;

	cin >> m >> M;

	long long range = M - m + 1;
	vector<bool> nono(range, true);

	for (long long i = 2; i*i <= M; i++)
	{
		long long num = m / (i * i);
		if (m % (i * i) != 0)
		{
			num++;
		}

		while (num * (i * i) <= M)
		{
			if (nono[num * (i * i) - m] == true)
			{
				nono[num * (i * i) - m] = false;
				--range;
			}
			num++;
		}
	}

	cout << range << endl;

	return 0;

}

/**
* 1번 탑에 있는 모든 원판을 3번으로 옮기기.
 *
 * 1 -> 2로 3번을 거쳐서 n-1개 옮기기
 * 가장 큰걸 3번에 두기
 * 2 -> 1 -> 3으로 n-1개 옮기기
*/


#include <iostream>
using namespace std;
void hanoi(int n, int start, int to, int bypass)
{
    if(n == 1)
        printf("%d %d\n", start, to);
    else
    {
        hanoi(n-1,start,bypass,to);//1 -> 2 로 쭉쭉 옮기고
        printf("%d %d\n",start, to);//옮길때마다 하나씩 찍어주고
        hanoi(n-1,bypass, to,start);//2->3으로 옮기고
    }
}
int main() {
    int num;
    cin >> num;
    cout << (1<<num) -1 << "\n";
    hanoi(num,1,3,2);
}
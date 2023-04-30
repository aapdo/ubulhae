/**
 * 맛의 수치를 오름차순 정렬
 * n 개 치킨 수치 무작위 N/2명의 회원이 차례대로 2개 선택해서 정렬
 * 그 다음 N/4 명이 바로 전 단계 사람이 정렬한 두 개의 그룹을 정렬
 * k명의 회원이 정렬한 후 결과는?
 * N개의 리스트를 N/k 개의 리스트로 분할하고 각 리스트를 sort.
 **/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int k, len, num;
    cin >> len;
    int* list;
    vector<vector<int> > subList;

    list = new int[len];

    for (int i = 0; i < len; ++i) {
        cin >> list[i];
    }
    cin >> k;
    num = len / k;

    vector<int> tmp;
    int cnt = 0;
    for (int i = 0; i < len; ++i) {
        tmp.push_back(list[i]);
        cnt++;
        if (cnt == num) {
            sort(tmp.begin(), tmp.end());
            for (int j = 0; j < tmp.size(); ++j) {
                cout << tmp[j] << " ";
            }
            tmp.clear();
            cnt = 0;
        }
    }

    return 0;
}
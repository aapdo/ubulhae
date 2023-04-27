/**
 * 맛의 수치를 오름차순 정렬
 * n 개 치킨 수치 무작위 N/2명의 회원이 차례대로 2개 선택해서 정렬
 * 그 다음 N/4 명이 바로 전 단계 사람이 정렬한 두 개의 그룹을 정렬
 * k명의 회원이 정렬한 후 결과는?
 * 8/2
 * 4/2
 * 2번
 * 2^2 번
 **/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;


void sort(int arr[], int n, int num){
    int *tmp;
    tmp = new int[2];
    for (int i = 0; i < n/2; ++i) {
    }
}

int* merge(int arr1[], int arr2[]){

}


int main(){
    int n, k, num, tmp;
    int *arr;
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> k;

    num = log2(n/k);

    sort(arr, n, num);


    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }


    return 0;
}

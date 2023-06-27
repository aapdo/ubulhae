#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    int len;
    cin >> len;

    int sequence[len];
    int cur;

    stack<int> myStack;
    int point = 0;

    string outputStr = "";

    bool flag = true;
    for (int i = 0; i < len; ++i) {
        cin >> sequence[i];
    }

    for (int i = 0; i < len; ++i) {
        //cur = 4인데 현재 0이라면
        cur = sequence[i];

        //4번 실행해서 top = 4가 됨.
        for (int j = point; j < cur; ++j) {
            outputStr += "+\n";
            myStack.push(++point);
        }


        if (myStack.top() == cur){
            outputStr += "-\n";
            myStack.pop();
        }else{
            flag = false;
            cout << "NO";
            break;
        }
    }
    if (flag == true) {
        cout << outputStr;
    }

    return 0;
}
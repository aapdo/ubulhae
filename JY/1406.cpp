#include <iostream>
#include <string>
#include <list>
using namespace std;
int main(){
    string str;
    string inputStr1;
    char inputStr2;
    int cursor;
    int cnt;
    cin >> str;
    int strLen = str.size();
    cin >> cnt;
    list<char> myStr;
    for (int i= 0; i < strLen; ++i) {
        myStr.push_back(str[i]);
    }
    list<char>::iterator iter = myStr.end();
    for(int i = 0; i < cnt; i++)
    {
        cin >> inputStr1;

        //커서 왼쪽으로 글자 추가
        if (inputStr1[0] == 'P')
        {
            //abcd
            //abdcd
            cin >> inputStr2;
            myStr.insert(iter, inputStr2);
        }
            //커서 왼쪽으로
        else if (inputStr1[0] == 'L'){
            if(iter != myStr.begin()) iter--;
        }
            //커서 오른쪽으로
        else if (inputStr1[0] == 'D'){
            if(iter != myStr.end()) iter++;

        }
            //커서 왼쪽 지우기
        else if (inputStr1[0] == 'B'){
            //abcd
            if(iter == myStr.begin()) continue;
            iter = myStr.erase(--iter);
        }
    }
    list<char>::iterator end = myStr.end();
    for (auto i = myStr.begin(); i != end; i++) {
        cout << *i;
    }
    return 0;
}
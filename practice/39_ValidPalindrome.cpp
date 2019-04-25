//
// Created by zqn on 2019/4/25.
//

#include <iostream>
#include <string>
using namespace std;

//从两头扫描，遇到非字母数子的跳过。
bool isPalindrome(string s){
    int j = s.size()-1;
    int i = 0;
    while(i < j){
        if(!isalnum(s[i])){
            ++i;
            continue;
        }
        if(!isalnum(s[j])){
            --j;
            continue;
        }
        if(tolower(s[i]) != tolower(s[j]))
            return false;
        i++;
        j--;
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    cout << isPalindrome(s);
}
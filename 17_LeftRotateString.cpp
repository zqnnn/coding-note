//
// Created by zqn on 2019/3/21.
//
#include <string>
#include <iostream>
using namespace std;

string LeftRotateString(string str, int n) {
    string result;
    for(int i = n; i < str.length(); i++){
        result = result + str[i];
    }

    for(int i = 0; i < n; i++){
        result = result + str[i];
    }
    return result;
}

int main(){
    string str = "asdasf123";
    int n = 3;
    cout << LeftRotateString(str, n);
}
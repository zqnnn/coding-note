//
// Created by zqn on 2019/3/21.
//


#include <string>
#include <iostream>
using namespace std;

void reverseWord(string &str, int begin, int end){
    while(end > begin){
        swap(str[begin++], str[end--]);
    }
}

string ReverseSentence(string str) {
    if(str.length() == 0)
        return "";
    reverseWord(str, 0, str.length()-1);
    int i = 0;
    int e , s = 0;
    while(i < str.length()){
        while(i < str.length() && str[i] == ' '){
            i++; //空格跳过
        }
        e = s = i; //记录单词的第一个字符的位置
        while(i < str.length() && str[i] != ' '){
            i++;
            e++;
        }
        reverseWord(str, s, e - 1); //局部翻转
    }
    return str;
}

int main(){
    string str = "asdasf 123";
    cout << ReverseSentence(str);
}
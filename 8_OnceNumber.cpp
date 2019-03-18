//
// Created by zqn on 2019/3/18.
//

//## 题目描述
//
//在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
//
//## 解题思路
//
//我们首先想到的可能就是遍历数组，对每一个字符串再遍历判断是否唯一，这样的时间复杂度为O(n^2)。这显然不是我们想要的。
//
//然后我们可能会想到，为什么不用hash表呢？首先遍历数组建立hash表，key为字符串，value为该字符串出现的次数。然后再遍历hash，找到里面value为1的key就可以了。
//
//C++中，我们可以用数组实现，此时，数组长度设定为256，对应字符串的ASCII码；也可以用map实现。
//Python中，我们可以用字典实现，但是很耗空间。


#include <string>
#include <iostream>
using namespace std;

int FirstNotRepeatingChar(string str) {
    if(str.size() == 0)
        return -1;
    int a[256] = {0};
    for(int i=0; i<str.size(); i++){
        a[(int)str[i]]++;
    }

    for(int i=0; i<str.size(); i++){
        if(a[(int)str[i]] == 1)
            return i;
    }
    return -1;
}

int main(){
    string s = "aaxsxffvdvd";
    cout << FirstNotRepeatingChar(s) << endl;

}
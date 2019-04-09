//
// Created by zqn on 2019/3/14.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution{
public:
    vector<string> Permutation(string str){
        vector<string> result; //创建字符串数组
        int len = str.length();
        if(!len) return result;
        Permutation(result, str, 0, len);
        return result;
    }

    //递归函数
    void Permutation(vector<string>&result, string str, int index, int len){

        //当索引指向字符串尾部时，将str压入数组
        if(index == len){
            result.push_back(str);
            return;
        }
        for(int i = index; i < len; i++){
            if(i!=index && str[i]==str[index])
                continue;
            swap(str[i], str[index]);
            Permutation(result, str, index+1, len);
        }

    }
};

//剑指offer解法
//void Permutation(char* pStr){
//    if(pStr == NULL){
//        return;
//    }
//    Permutation(pStr, pStr);
//}
//
//void Permutation(char* pStr, char* pBegin){
//    if(*pBegin == '\0'){
//        printf("%s\n", pStr);
//    }
//    else {
//        for(char* pCh = pBegin; *pCh != '\0'; ++pCh){
//            char temp = *pCh;
//            *pCh = *pBegin;
//            *pBegin = temp;
//
//            Permutation(pStr, pBegin + 1);
//
//            temp = *pCh;
//            *pCh = *pBegin;
//            *pBegin = temp;
//        }
//
//    }
//}

int main(){
    vector<string> result;
    Solution s;
    result = s.Permutation("sdasdas");

    //迭代器遍历字符串数组
    vector<string>::iterator it = result.begin();
    for(; it != result.end(); it++){
        cout<< *it << endl;
    }

    //下标遍历
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }
}
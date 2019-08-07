//
// Created by zhangqianni on 2019-08-07.
//


#include <vector>
#include <iostream>
using namespace std;



int main(){
    //方法1：已知vecotr长度
    int num;
    cin >> num;

    vector<int> vecNum;
    int temp;
    for (int i = 0; i < num; ++i)
    {
        cin >> temp;
        vecNum.push_back(temp);
    }

    for (vector<int>::iterator itr = vecNum.begin(); itr != vecNum.end(); ++itr)
    {
        cout << *itr << endl;
    }



    //方法2：未知vecotr长度


    vector<int> a;
    int i;

    for(i=0;;i++)
    {   int tem;
        cin >> tem;
        a.push_back(tem);
        if(getchar()=='\n') //遇回车结束
            break;
    }
    for(int j=0;j<i+1;j++)
        cout<<a[j]<<" ";


    return 0;
}
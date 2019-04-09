//
// Created by zqn on 2019/4/9.
//

//n根板凳，ai个人坐在第i根板凳上，现在又来了m个人 ，他们每个人都会从这n根板凳中选择一根坐下
//所有人都坐下后，其中人数最多的为k , 算出最大的k和最小的k

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n; //板凳的个数

    int m;
    cin >> m; //来的人的个数

    vector<int> v;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int min = 0, max = 0;


    sort(v.begin(), v.end());

    max = v[n-1] + m;

    for(int i = 0; i < m; i++){
        v[0]++;
        sort(v.begin(), v.end());

    }
    min = v[n-1];

    cout << min << ' ' << max;


    return 0;
}
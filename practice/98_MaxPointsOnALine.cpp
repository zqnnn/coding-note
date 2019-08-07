//
// Created by zhangqianni on 2019-08-05.
//

//找落在同一条直线上最多的点的个数

#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;


//比较直观的方法是，三层循环，以任意两点划线，判断第三个点是否在这条直线上。
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() < 3) return points.size();
        int max = 0;
        for(int i = 0; i < points.size(); i++){
            for(int j = 0; j < points.size(); j++){
                //固定两个点
                if(i == j) continue;
                int k_cnt = 2; //用于保存和这两个点的斜率相同的点
                int y_cnt = 2; //用于保存y值相同的点（无法计算斜率）

                //计算y值相同的点的个数
                if(points[i][1] == points[j][1]){
                    for(int k = 0; k < points.size(); k++){
                        if(k == i || k == j) continue;
                        if(points[k][1] == points[i][1]) y_cnt++;
                    }
                }

                else{
                    double k_v = double((points[j][0] - points[i][0]))/ double((points[j][1] - points[i][1]));
                    double k2;
                    for(int k = 0; k < points.size(); k++){
                        if(k == i || k == j) continue;
                        if(points[k][1] - points[j][1] != 0) {
                            k2 = double((points[k][0] - points[j][0])) / double((points[k][1] - points[j][1]));
                        }
                        else {
                            k2 = double((points[k][0] - points[i][0])) / double((points[k][1] - points[i][1]));
                        }
                        if(k_v == k2) k_cnt++;
                    }

                }

                if(k_cnt > max) max = k_cnt;
                if(y_cnt > max) max = y_cnt;

            }
        }

        return max;
    }
};



//选定一个点，分别计算其他点和它构成的直线的斜率，斜率相同的点肯定在同一条直线上。
class Solution2{
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() < 3)
            return points.size();
        int max_i = 0;


        for(int i = 0; i < points.size(); i++){
            int duplicate = 0; //记录重合点
            double k = 0.0;
            unordered_map<double, int> map;
            for(int j = 0; j < points.size(); j++){
                if(i == j) continue;
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    duplicate++;
                if(points[i][0] == points[j][0])  k = INT_MAX;
                else{
                     k = double(points[i][0] - points[j][0]) / (points[i][1] - points[j][1]);
                }
                map[k]++;

            }

            if(map.size() == 0){
                max_i = duplicate > max_i ? duplicate : max_i;
            }
            else{
                unordered_map<double, int>::iterator it = map.begin();
                for (; it != map.end(); it++){
                    max_i = max(it->second + duplicate , max_i);
                }
            }
        }
        return max_i;


    }
};


int main(){
    vector<vector<int>> p = {{-4,1},{-7,7},{-1,5},{9,-25}};
    Solution2 s;
    cout << s.maxPoints(p);
}
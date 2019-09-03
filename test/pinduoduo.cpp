//
// Created by zqn on 2019/9/1.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


void sort_v(vector<int> &nums, int n){
    vector<int> odd;
    vector<int> even;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] % 2 == 0){
            even.push_back(nums[i]);
        }
        else{
            odd.push_back(nums[i]);
        }
    }
    sort(even.begin(), even.end(), greater<int>());
    sort(odd.begin(), odd.end(), greater<int>());
    even.insert(even.end(), odd.begin(), odd.end());


    for(int i = 0; i <n-1; i++){
        cout << even[i] << ',';
    }
    cout << even[n-1];
}


int main(){
    string s;
    cin >> s;
    int n = 0;
    vector<int> nums;
    int temp = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] !=  ',' && s[i] != ';'){
            temp = temp * 10 + s[i] - '0';
        }
        if(s[i] == ','){
            nums.push_back(temp);
            temp = 0;
        }
        if(s[i] == ';'){
            nums.push_back(temp);
            while (i+1 < s.size()){
                n = n * 10 + s[i+1] - '0';
                i++;
            }
            break;
        }
    }

    sort_v(nums, n);

}
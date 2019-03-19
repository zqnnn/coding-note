//
// Created by zqn on 2019/3/18.
//
#include <vector>
#include <iostream>
using namespace std;

int findLowK(vector<int> data ,int k, int begin, int end){
    if(begin > end)
        return -1;
    int mid = (begin + end) >> 2;

    if(data[mid] == k){
        if((mid > 0 && data[mid-1] != k) || mid==0)
            return mid;
        else
            end = mid-1;
    }
    else if(data[mid] > k){
        end = mid-1;
    }
    else
        begin = mid+1;
    return findLowK(data, k, begin, end);
}


int findHighK(vector<int> data ,int k, int begin, int end){
    if(begin > end)
        return -1;
    int mid = (begin + end) >> 2;
    if(data[mid] == k){
        if((mid < data.size()-1 && data[mid+1] != k) || mid==data.size()-1)
            return mid;
        else
            begin = mid + 1;
    }
    else if(data[mid] > k){
        end = mid-1;
    }
    else
        begin = mid+1;
    return findHighK(data, k, begin, end);
}



int GetNumberOfK(vector<int> data ,int k) {
    int count = 0;
    int index1 = findLowK(data, k, 0, data.size()-1);
    int index2 = findHighK(data, k, 0, data.size()-1);
    while(index1 != -1 && index2 != -1){
        count = index2 - index1 + 1;
    }
    return count;

}



int main(){
    vector<int> data = {1,2,4,2,3};
    int k =  GetNumberOfK(data, 2);
    cout << k << endl;
}
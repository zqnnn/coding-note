//
// Created by zqn on 2019/3/14.
//


 //数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 // 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 // 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。




#include <vector>
#include <string>
#include <iostream>

using namespace std;


//方法一：先排序，中间的数就是解
//快排
//void quicksort(vector<int> numbers, int low, int high){
//    while(low < high){
//        int i = low;
//        int j = high - 1;
//        int x0 = numbers[i];
//        while(i < j){
//            //从右往左找小于x0的数
//            while(numbers[j] > x0)
//                j--;
//            numbers[i] = numbers[j];
//            while(numbers[i] < x0)
//                i++;
//            numbers[j] = numbers[i];
//        }
//        numbers[i] = x0;
//        quicksort(numbers, low, i-1);
//        quicksort(numbers, i, high);
//    }
//}
//int MoreThanHalfNum_Solution(vector<int> numbers) {
//    vector<int> result = numbers;
//    int len = result.size();
//    quicksort(result, 0, len);
//    int x = result[int(len/2)];
//    return x;
//}


//
//思路二：如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。
//在遍历数组时保存两个值：一是数组中一个数字，一是次数。
// 遍历下一个数字时，若它与之前保存的数字相同，则次数加1，否则次数减1；
// 若次数为0，则保存下一个数字，并将次数置为1。
// 遍历结束后，所保存的数字即为所求。然后再判断它是否符合条件即可。

int MoreThanHalfNum_Solution(vector<int> numbers) {
    if(numbers.empty()) return 0;
    int result = numbers[0];
    int count = 1;
    for(int i = 1; i < numbers.size(); i++){
        if(numbers[i] == result)
            count++;
        else if(count == 0){
            result = numbers[i];
            count = 1;
        }
        else{
            count--;
        }
    }
    // 判断result是否符合条件，即出现次数大于数组长度的一半
    count = 0;
    for(int i=0;i<numbers.size();++i)
    {
        if(numbers[i] == result) ++count;
    }

    return (count > numbers.size()/2) ? result : 0;
}
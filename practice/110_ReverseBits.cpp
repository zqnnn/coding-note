//
// Created by zqn on 2019/8/19.
//

//翻转位

//基本思想就是首先令fool=0，取得n的最后一位与fool相或，这个时候fool里面存的即使n的最后一位，然后将fool左移一位，
// 这时n的最后一位变成了fool的第一位，并且fool的最后一位为0。将n右移一位，
// 这时原来n的倒数第二位就成了现在的倒数第一位，取出这一位，然后与fool相与，这时fool的最后一位存的是n中的倒数第二位……，
// 循环下去直到n的第一位被存到fool的最后一位中。
//
// 当然这种方法的for循环中有很多种实现方法，可以每次右移n，也可以设置一个mask，
// 每次左移mask。mask的作用是取得n的相应位，然后再右移。然后再与fool相与。
// ————————————————

#include <stdint.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
       uint32_t fool = 0;
       for(int i = 0; i < 32; i++){
           fool = (n&0x01) | fool;
           fool = fool << 1;
           n = n >> 1;
       }
        return fool;
    }
};


uint32_t reverse(uint32_t n){
    uint fool = 0;
    for(int i = 0; i < 32; i++){
        if(n & 1 == 1){
            fool = (fool << 1) + 1;
        }
        else{
            fool = fool << 1;
        }
        n = n >> 1;
    }
    return fool;
}

//
// Created by zqn on 2019/3/22.
//

#include <list>
#include <iostream>
using namespace std;

//剑指offer：每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
// HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。
// 然后,他随机指定一个数m,让编号为0的小朋友开始报数。
// 每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,
// 从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,
// 并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)



//方法一 环形链表 普通链表模拟环形链表，当走到end时，跳到begin。时间复杂度是O(mn),空间复杂度O（n）

//int LastRemaining_Solution(int n, int m)
//{
//    if(n < 1 || m < 1)
//        return -1;
//    list<int> numbers;
//    for(int i = 0; i < n; i++){
//        numbers.push_back(i);
//    }
//
//    list<int>::iterator current = numbers.begin();
//    while(numbers.size() > 1){
//        for(int i = 1; i < m; i++){
//            current++;
//            if(current == numbers.end())
//                current = numbers.begin();
//        }
//
//        list<int>::iterator next = ++current;
//        if(next == numbers.end())
//            next = numbers.begin();
//
//        current--;
//        numbers.erase(current); //erase的作用是，使作为参数的迭代器失效，并返回指向该迭代器下一参数的迭代器。
//        current = next;
//    }
//
//    return *(current);
//}



//方法二
//## 解题思路
//如果只求最后一个报数胜利者的话，我们可以用数学归纳法解决该问题，为了讨      论方便，先把问题稍微改变一下，并不影响原意：
// 问题描述：n个人（编号0~(n-1))，从0开始报数，报到(m-1)的退出，剩下的人 继续从0开始报数。求胜利者的编号。
// 我们知道第一个人(编号一定是(m-1)%n) 出列之后，剩下的n-1个人组成了一个新      的约瑟夫环（以编号为k=(m-1)%n的人开始）:
//        k  k+1  k+2  ... n-2, n-1, 0, 1, 2, ... k-2并且从k开始报0。
//现在我们把他们的编号做一下转换：
//k+1   --> 0
//k+2   --> 1
//...
//n-1   --> n-k-2
//0     --> n-k-1
//1     --> n-k
//...
//k-2   --> n-2
//k-1   --> n-1
//变换后就完完全全成为了(n-1)个人报数的子问题，假如我们知道这个子问题的解： 例如x是最终的胜利者，那么根据上面这个表把这个x变回去不刚好就是n个人情 况的解吗？！！变回去的公式很简单，相信大家都可以推出来：x'=(x+k+1)%n。
//然后把k=(m-1)%n带入，就是下面的递推公式了。
//令f[n]表示n个人玩游戏报m退出最后胜利者的编号，最后的结果自然是f[n]。
//递推公式
//f[1]=0;
//f[n]=(f[n-1]+m)%n;  (n>1)
//有了这个公式，我们要做的就是从1-n顺序算出f[i]的数值，最后结果是f[n]。


/**
约瑟夫问题
递推公式
让f[i]为i个人玩游戏报m退出最后的胜利者的编号，最后的结果自然是f[n]
服了
f[1] = 0;
f[i] = (f[i - 1] + m) mod i;

因为递推，所以可以不用保存状态
代码如下

*/
int LastRemaining_Solution(int n, int m){
    if(n < 1 || m < 1)
        return -1;
    int last = 0;
    for(int i = 2; i <= n; ++i)
        last = (last + m) % i;
    return last;
}

int main(){
    int n = 5, m = 3;
    cout << LastRemaining_Solution(n, m);
}
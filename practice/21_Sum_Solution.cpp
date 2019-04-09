//
// Created by zqn on 2019/3/22.
//



//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）

//1. 分析：&& 运算，当前面为假时，后面自动不算。
//利用逻辑与的短路特性实现递归终止。
int Sum_Solution(int n) {
    int ans = n;
    ans && (ans += Sum_Solution(n - 1));
    return ans;
}
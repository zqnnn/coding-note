//
// Created by zhangqianni on 2019-08-07.
//

//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//getMin() -- Retrieve the minimum element in the stack.


//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> Returns -3.
//minStack.pop();
//minStack.top();      --> Returns 0.
//minStack.getMin();   --> Returns -2.

#include <stack>
#include <iostream>
using namespace std;

//这道最小栈跟原来的栈相比就是多了一个功能，可以返回该栈的最小值。使用两个栈来实现，一个栈来按顺序存储push进来的数据，另一个用来存出现过的最小值。代码如下:

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        s.push(x);
        if(s_min.empty() || x <= s_min.top()){
            s_min.push(x);
        }
    }

    void pop() {
        if(s.top() == s_min.top()){
            s_min.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return s_min.top();
    }

private:
    stack<int> s;
    stack<int> s_min;
};


int main(){
    MinStack m;
    m.push(1);
    m.push(3);
    m.push(-2);
    cout << m.getMin();
    m.pop();
    cout << m.getMin();

}
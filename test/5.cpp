#include "bits/stdc++.h"
#include <iostream>
using namespace std;

// 虚函数能在析构函数里面调用吗

class C {
public:
    C() {
        cout << "构造函数 C" << endl;
    }
    ~C() {
        cout << "析构函数 C" << endl;
    }
};

class A {
public:
    A() {
        cout << "构造函数 A" << endl;
    }

    virtual void f() {
        cout << "A::f" << endl;
    }
    ~A() {
        cout << "析构函数 A" << endl;
        f();
    }
};


class B :public A {
public:

    C c;

    B() {
        cout << "构造函数 B" << endl;
    }

    void f() {
        cout << "B::f" << endl;
    }

    ~B() {
        cout << "析构函数 B" << endl;
        f();
    }

};

int main() {
    B *b = new B();
    //A *a = new A();
    delete b;
    system("pause");
    return 0;
}



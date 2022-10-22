本文是笔者在C++学习过程中，对类和对象的总结记录，如有不对以及不足的地方，欢迎大家指正！

文中代码学于黑马。

****
&emsp;&emsp;在C++当中，由于类内权限的限制，使得类内成员得到了隐藏：在类外访问不到类的私有属性。

&emsp;&emsp;为了在类外访问类内的私有属性，C++引进了**友元**（**friend**）机制，在类中指定的友元，就可以访问该类中受保护的资源了。

&emsp;&emsp;需要注意的是，友元是单向的，也不能传递。

友元的实现：
- **全局函数做友元**
- **类做友元**
- **类的成员函数做友元**

代码示例：

```cpp
#include <iostream>
#include <string>
using namespace std;

class House;

// 2、类做友元
class Friend_1{
public:
    Friend_1();
    void visit();

    House *house;
};

// 3、类的成员函数做友元
class Friend_2{
public:
    Friend_2();
    void visit();

    House *house;
};

class House{
    // 1、全局函数做友元
    friend void friendFuncShow(House *house);

    // 2、类做友元
    friend class Friend_1;

    // 3、类的成员函数做友元
    friend void Friend_2::visit();

public:

    House(){
        living_room="客厅";
        bedroom="卧室";
    }

    string living_room;
private:
    string bedroom;
};

// 1、全局函数做友元
void friendFuncShow(House *house){
    cout<<"友元：全局函数 friendFuncShow 正在访问 House 的"<<house->living_room<<endl;
    cout<<"友元：全局函数 friendFuncShow 正在访问 House 的"<<house->bedroom<<endl;
}

void test_1(){
    House house;
    friendFuncShow(&house);
}

// 2、类做友元
Friend_1::Friend_1() {
    house=new House;
}

void Friend_1::visit(){
    cout<<"友元：类 Friend_1 正在访问 House 的"<<house->living_room<<endl;
    cout<<"友元：类 Friend_1 正在访问 House 的"<<house->bedroom<<endl;
}

void test_2(){
    Friend_1 friend1;
    friend1.visit();
}

// 3、类的成员函数做友元
Friend_2::Friend_2() {
    house=new House;
}

void Friend_2::visit(){
    cout<<"友元：成员函数 visit 正在访问 House 的"<<house->living_room<<endl;
    cout<<"友元：成员函数 visit 正在访问 House 的"<<house->bedroom<<endl;
}

void test_3(){
    Friend_2 friend2;
    friend2.visit();
}

int main() {
    test_1();
    test_2();
    test_3();
    return 0;
}
```

运行结果：

![友元](https://img-blog.csdnimg.cn/4678610801554905ad61d6f625d8bfa5.png)

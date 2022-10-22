/**
 * Created by 史进 on 2022/10/20.
 *
 * 友元
 * 1、全局函数做友元
 * 2、类做友元
 * 3、类的成员函数做友元
 *
 */
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
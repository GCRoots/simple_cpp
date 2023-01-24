/**
 * Created by 史进 on 2022/10/16.
 *
 * 1. 成员变量与成员函数分开存储
 * 2. this指针
 *      a. 解决名称冲突
 *      b. 返回对象本身： return *this;
 * 3. 空指针访问成员函数
 * 4. const 修饰成员函数
 *
 */
#include <iostream>
#include <string>
using namespace std;

// 1. 成员变量与成员函数分开存储
class Class_empty{};

class Class_not_static{
    int A;                  // 非静态成员变量：属于对象
};

class Class_all{
    int A;                  // 非静态成员变量：属于对象
    static int B;           // 静态成员变量：不属于对象
    void func(){}           // 非静态成员函数：不属于对象
    static void func2(){}   // 静态成员函数：不属于对象
};
int Class_all::B = 10;

void test_01(){
    Class_empty empty;
    // 空对象占用内存空间大小：1
    cout<< "size of an empty object:" << sizeof (empty) << endl;

    Class_not_static notStatic;
    // 非静态成员变量属于对象,该对象占用的内存大小会随着非静态成员变量的增加而增加
    cout<< "size of a.html not empty object:" << sizeof (notStatic) << endl;

    Class_all all;
    // 成员函数和静态成员变量不属于对象，占用内存的大小与类对象无关
    cout<< "size of a.html not empty object:" << sizeof (all) << endl;
}

// 2. this指针
class Person{
public:
    // a.html. 解决名称冲突
    Person(int age){
        this->age=age;
    }

    // b. 返回对象本身： return *this;
    Person& personAddAge(Person &p){
        this->age += p.age;
        return *this;
    }

    int age;
};

void test_02(){
    Person p(18);
    cout<< "p's age is:" << p.age <<endl;

    Person p2(10);
    // 链式编程思想
    p.personAddAge(p2).personAddAge(p2).personAddAge(p2).personAddAge(p2);
    cout<< "p's age is:" << p.age <<endl;
}

// 3. 空指针访问成员函数
class Person_1{
public:
    void showClassName(){
        cout<<"This is a.html Person_1 class."<<endl;
    }

    void showAge(){
        if (this == NULL){
            cout<<"This object is NULL"<<endl;
            return;
        }
        cout<<"age is:"<<age<<endl;
    }

    int age;
};

void test_03(){
    Person_1 *p = NULL;
    p->showClassName();
    p->showAge();
}

// 4. const 修饰成员函数
class Person_const{
public:
    // 常函数
    void showPerson() const{
        // 常函数中不能对成员变量进行修改，除非成员变量在声明时，用 mutable 关键字修饰。
        // A=100；
        B=200;
    }

    void func(){}

    int A=10;
    mutable int B=20;
};

void test_04(){
    // 常对象
    const Person_const p;
    // 常对象的成员变量是不能修改的，除非成员变量在声明时，用 **mutable** 关键字修饰。
    // p.A=1000;
    p.B=2000;

    // 常对象只能调用常函数。
    // p.func();
    p.showPerson();
}

int main() {
    test_01();
    cout<<"===================="<<endl;

    test_02();
    cout<<"===================="<<endl;

    test_03();
    cout<<"===================="<<endl;

    test_04();
    cout<<"===================="<<endl;

    return 0;
}
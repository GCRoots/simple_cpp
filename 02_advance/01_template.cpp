/**
 * Created by 史进 on 2023/1/23.
 *
 * 模版代码示例
 *
 * 1、函数模板
 *  函数的返回值类型和形参类型可以不指定，从而使函数可以接受或返回多种数据类型的数据
 *  语法：
 *      template<typename T>
 *      函数声明或定义
 *
 *  函数模版的使用：
 *      1、自动类型推导
 *      2、显示指定类型
 *
 *  注意事项：
 *      1、自动类型推导，必须推导出一致的数据类型T，才可以使用
 *      2、模板必须确定出T的类型，才可以使用
 *
 *  普通函数与函数模版的区别：
 *      1、普通函数调用时可以发生自动类型转换/隐式类型转换
 *      2、函数模版调用时，如果利用自动类型推导，不会发生隐式类型转换
 *      3、函数模版调用时，如果利用显示指定类型，可以发生隐式类型转换
 *
 *  普通函数与函数模版的调用规则：
 *      1、优先调用普通函数
 *      2、可以通过空模版参数列表来强制调用函数模版
 *      3、函数模版可以发生重载
 *      4、如果函数模版可以产生更好的匹配，优先调用函数模版
 *
 *  模版的局限性：
 *      在使用自定义数据类型（如类）时，模版的通用型可能不再适用
 *
 * 2、类模版
 *  作用：建立一个通用类，类中成员的数据类型可不设定，而是用一个虚拟的类型来代表
 *
 *  语法：
 *      template<typename T>
 *      类
 *
 *  类模版与函数模版的区别：
 *      1、类模版没有自动类型推导的使用方式
 *      2、类模版在模版参数列表中可以有默认参数
 *
 *  类模版中成员函数创建时机：
 *      1、普通类中的成员函数一开始就创建
 *      2、类模版中的成员函数在调用时才创建
 *
 *  类模版对象做函数参数：
 *      传入方式：
 *      1、传入指定的类型：直接显示对象的数据类型   （常用）
 *      2、参数模版化：将对象的参数变为模版进行传递
 *      3、整个类模版化：将这个对象类型，模版化进行传递
 *
 *  类模版与继承：
 *      当子类继承的父类是一个类模版时，子类在声明时，要指定出父类中的类型
 *      如果不指定，编译器无法给子类分配内存
 *      若是想灵活指定父类中的类型T，子类也需要变成类模版
 *
 *  类模版成员函数类外实现
 *
 *  类模版分文件编写：
 *      问题；类模版中的成员函数的创建时机是在调用阶段，所以分文件编写时会出现链接不到的问题
 *      解决：1、直接包含 .cpp 源文件
 *           2、将声明和实现放在同一个文件中，并更改后缀名为 .hpp
 *
 *  类模版与友元
 *      类模版配合友元的类内实现与类外实现
 *          1、全局函数类内实现：直接在类内声明友元
 *          2、全局函数类内实现：需要提前让编译器知道全局函数的存在
 *
 *
 *
 */
#include <iostream>
using namespace std;

// 1、函数模板
void intSwap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void floatSwap(float &a,float &b){
    float temp = a;
    a = b;
    b = temp;
}

// 用函数模版实现交换函数
template<typename T>    // 声明一个模版，告诉编译器后面的T是一个通用数据类型，不要报错
void mySwap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void func(){
    cout << "func" << endl;
}

void test01(){
    int a = 10;
    int b = 20;
    cout << "a = " << a << ", b = " << b << endl;

    // 利用函数模版进行交换
    // 函数模版的使用：
    // 1、自动类型推导
    mySwap(a, b);
    cout << "a = " << a << ", b = " << b << endl;

    // 2、显示指定类型
    mySwap<int>(a, b);
    cout << "a = " << a << ", b = " << b << endl;

    // 注意事项：
    // 1、自动类型推导，必须推导出一致的数据类型T，才可以使用
    char c = 'a';
    //mySwap(a,c);  // 错误！

    // 2、模板必须确定出T的类型，才可以使用
    func<int>();

}

// 示例：通用数组排序函数
template<typename T>
void mySort(T arr[],int len){
    for (int i = 0; i < len; ++i) {
        int min = i;
        for (int j = i+1; j < len; ++j) {
            if (arr[j] < arr[min]){
                min=j;
            }
        }
        if (min != i){
            T temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

// 通用数组打印函数
template<typename T>
void myPrint(T arr[],int len){
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

void testSort(){
    char chars[] = "lkjhgfdsapoiuytrewqmnbvcxz";
    int num = sizeof(chars)/sizeof(char)-1; // 字符数组长度加结束符
    myPrint(chars,num);
    mySort(chars,num);
    myPrint(chars,num);
}

// 普通函数与函数模版的调用规则：
//  1、优先调用普通函数，即使普通函数仅有声明
//  2、可以通过空模版参数列表来强制调用函数模版
//  3、函数模版可以发生重载
//  4、如果函数模版可以产生更好的匹配，优先调用函数模版

// 普通函数
void testFunc(int a,int b){
    cout << "调用普通函数" << endl;
}

// 函数模版
template<typename T>
void testFunc(T a,T b){
    cout << "调用函数模版" << endl;
}

// 函数模版重载
template<typename T>
void testFunc(T a,T b,T c){
    cout << "调用函数模版 重载" << endl;
}

void test02(){
    int a=10,b=20;
    //  1、优先调用普通函数
    testFunc(a,b);

    //  2、可以通过空模版参数列表来强制调用函数模版
    testFunc<>(a,b);

    //  3、函数模版可以发生重载
    testFunc(a,b,100);

    //  4、如果函数模版可以产生更好的匹配，优先调用函数模版
    char c1='a', c2='b';
    testFunc(c1,c2);
}

// 模版的局限性
template<typename T>
bool isEqual(T &a,T &b){
    return a==b;
}

class Person{
public:
    Person() =default;
    Person(string name,int age):m_name(name),m_age(age){}

    bool operator==(Person &p) const{
        cout << "运算符重载" << endl;
        return this->m_age==p.m_age && this->m_name==p.m_name;
    }

    string m_name;
    int m_age=0;
};

template<>
bool isEqual(Person &p1,Person &p2){
    cout << "函数模版" << endl;
    return p1.m_age==p2.m_age && p1.m_name==p2.m_name;
}

void test03(){
    int a = 10;
    int b = 20;
    cout << (isEqual(a,b)?"a == b":"a != b") << endl;

    Person p1("tom",10);
    Person p2("tom",10);
    cout << (isEqual(p1,p2)?"p1 == p2":"p1 != p2") << endl;
}


// 2、类模版
template<class NameType, class AgeType = int >
class PersonT{
public:
    PersonT(NameType name,AgeType age){
        this->m_name = name;
        this->m_age = age;
    }

    void showPersonT(){
        cout << this->m_name << "'s age is " << this->m_age << "." << endl;
    }

    NameType m_name;
    AgeType m_age;

};

// 类模版与函数模版的区别：
void test04(){
    // 1、类模版没有自动类型推导的使用方式
    // PersonT p1("Alice",11); // 错误
    PersonT<string,int> p1("Alice",11);
    p1.showPersonT();

    // 2、类模版在模版参数列表中可以有默认参数
    PersonT<string> p2("Job",18);
    p2.showPersonT();

}

// 类模版中成员函数创建时机：
class Person1{
public:
    void showPerson1(){
        cout << "show Person1" << endl;
    }
};

class Person2{
public:
    void showPerson2(){
        cout << "show Person2" << endl;
    }
};

template<class T>
class MyClass{
public:

    T obj;

    // 类模版中的成员函数
    void func1(){
        obj.showPerson1();
    }

    void func2(){
        obj.showPerson2();
    }
};

void test05(){
    MyClass<Person1> m1;
    // 类模版中的成员函数在调用时才创建
    m1.func1();
    //m1.func2();
}

// 类模版对象做函数参数：
// 1、传入指定的类型：直接显示对象的数据类型
void printPersonT_01(PersonT<string,int> &p){
    p.showPersonT();
}

// 2、参数模版化：将对象的参数变为模版进行传递
template<class T1,class T2>
void printPersonT_02(PersonT<T1,T2> &p){
    p.showPersonT();
    cout << "T1's type is:" << typeid(T1).name() << endl;
    cout << "T2's type is:" << typeid(T2).name() << endl;
}

// 3、整个类模版化：将这个对象类型，模版化进行传递
template<class T>
void printPersonT_03(T &p){
    p.showPersonT();
    cout << "T's type is:" << typeid(T).name() << endl;
}

void test06(){
    // 1、传入指定的类型：直接显示对象的数据类型
    PersonT<string,int> p1("Alice",10);
    printPersonT_01(p1);

    // 2、参数模版化：将对象的参数变为模版进行传递
    PersonT<string,int> p2("Bob",11);
    printPersonT_02(p2);

    // 3、整个类模版化：将这个对象类型，模版化进行传递
    PersonT<string,int> p3("Justin",13);
    printPersonT_03(p3);
}

// 类模版与继承：
template<class T>
class Base{
public:
    T t;
};

// 当子类继承的父类是一个类模版时，子类在声明时，要指定出父类中的类型
class Son1:public Base<int>{
public:
    Son1(){
        cout << "T's type is:" << typeid(this->t).name() << endl;
    }
};

// 若是想灵活指定父类中的类型T，子类也需要变成类模版
template<class T1,class T2>
class Son2:public Base<T2>{
public:
    Son2(){
        cout << "T1's type is:" << typeid(T1).name() << endl;
        cout << "T2's type is:" << typeid(T2).name() << endl;
    }

    T1 obj;
};

void test07(){
    Son1 son1;
    Son2<int,char> son2;
}

// 类模版成员函数类外实现
template<class NameType, class AgeType = int >
class PersonOut{
public:
    PersonOut(NameType name,AgeType age);

    void showPersonOut();

    NameType m_name;
    AgeType m_age;

};

// 构造函数类外实现
template<class NameType,class AgeType>
PersonOut<NameType,AgeType>::PersonOut(NameType name,AgeType age){
    this->m_name = name;
    this->m_age = age;
}

// 成员函数类外实现
template<class NameType,class AgeType>
void PersonOut<NameType,AgeType>::showPersonOut(){
    cout << this->m_name << "'s age is " << this->m_age << "." << endl;
}

void test08(){
    PersonOut<string> p("Alice",11);
    p.showPersonOut();
}

// 类模版与友元
//  1、全局函数类内实现：直接在类内声明友元
//  2、全局函数类内实现：需要提前让编译器知道全局函数的存在

// 提前让编译器知道Friend类的存在
template<class NameType, class AgeType = int>
class Friend;

// 2、全局函数类内实现
template<class NameType, class AgeType = int >
void printFriend(Friend<NameType,AgeType> f){
    cout << "类外实现：" << f.m_name << "'s age is " << f.m_age << "." << endl;
}

template<class NameType, class AgeType>
class Friend{
    // 1、全局函数类内实现
    friend void showFriend(Friend<NameType,AgeType> f){
        cout << "类内实现：" << f.m_name << "'s age is " << f.m_age << "." << endl;
    }

    // 2、全局函数类内实现：需要提前让编译器知道全局函数的存在
    friend void printFriend<>(Friend<NameType,AgeType> f);

public:
    Friend(NameType name,AgeType age){
        this->m_name = name;
        this->m_age = age;
    }

    NameType m_name;
    AgeType m_age;

};

void test09(){
    // 1、全局函数类内实现
    Friend<string,int> f("Tom",13);
    showFriend(f);
    printFriend(f);

}


int main() {
    std::cout << "Hello, World!" << std::endl;

    test01();

    testSort();

    test02();

    test03();

    test04();

    // 类模版中成员函数创建时机
    test05();

    // 类模版对象做函数参数
    test06();

    // 类模版与继承
    test07();

    // 类模版成员函数类外实现
    test08();

    // 类模版与友元
    test09();

    return 0;
}















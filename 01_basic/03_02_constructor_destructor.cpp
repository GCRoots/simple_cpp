/**
 * Created by 史进 on 2022/9/22.
 *
 * 1.构造函数与析构函数
 *  构造函数：主要用于在创建对象时为对象的成员属性赋值，即给对象分配资源。
 *      语法：类名(){}
 *      构造函数可以有参数，也就是说，可以发生重载。
 *  析构函数：主要用于在对象销毁时释放相应的资源。
 *      语法：~类名(){}
 *      析构函数不可以有参数，所以不能发生重载。
 *      一个类，可以有多个构造函数，但只能有一个析构函数，不同构造函数之间通过参数的个数和类型来区分。
 *  对于C++来说，对象的初始化与销毁是必须的，所以即使我们不提供构造函数与析构函数，编译器也会提供
 *  默认的构造函数与析构函数，并在对象初始化和销毁时由编译器自动调用，不需要手动调用，且只会调用一
 *  次。
 *      编译器提供的构造函数与析构函数是空实现。
 *
 * 2.构造函数的分类与调用
 *  构造函数可以按参数来分类，也可以按类型来进行分类。
 *  按参数：
 *      有参构造
 *      无参构造（默认构造）
 *  按类型：
 *      普通构造
 *      拷贝构造：在创建对象时，是通过同一个类的已创建的对象来对自己进行初始化，
 *          即对原对象进行复制，来初始化本对象。
 *          语法示例：Object(const Object &o){…}
 *
 *  构造函数的调用方式，可以分为以下几类：
 *      括号法：调用默认构造（无参构造）时，不可以加括号，否则编译器会认为这是函数声明。
 *      显示法：匿名对象（只调用构造方法而没有给对象命名），会在当前行执行结束后，立即被
 *          系统回收，即调用析构函数。
 *          同时，不要用拷贝构造函数来初始化匿名函数，否则，在编译器看来这是一个对象声明：
 *          Object(o1); == Object o1;
 *      隐式转换法
 *
 * 3.拷贝函数的调用时机
 *  1. 一个对象需要通过一个已经创建的对象来初始化
 *  2. 一个对象以值传递的方式传入函数体
 *  3. 一个对象以值传递的方式从函数返回
 *
 * 4. 构造函数的调用规则
 *  在默认的情况下，C++编译器会至少给类添加以下三个函数：
 *      1. 默认构造函数：无参，函数体为空
 *      2. 默认析构函数：无参，函数体为空
 *      3. 默认拷贝构造函数：对对象的属性进行简单的值拷贝
 *  而构造函数的调用规则如下所示：
 *      1. 若用户自定义了有参构造函数，那么C++就不会再提供默认无参构造函数，而仅提供默认拷贝
 *          构造函数。
 *      2. 若用户自定义了拷贝构造函数，那么C++就不会再提供其他的构造函数。
 *
 * 5. 深拷贝与浅拷贝
 *  浅拷贝：在对象复制时，仅进行简单的赋值拷贝
 *  深拷贝：在对象复制时，会在堆区重新申请空间，再进行拷贝操作。
 *
 *  在默认拷贝构造函数中，进行的是浅拷贝，而浅拷贝会将新旧对象的指针型成员变量指向同一块内存。
 *  因此在一个对象被销毁（调用析构函数）后，这一块内存就已经被释放了，所以当另一个对象调用析构
 *  函数时，就会造成对同一内存的重复释放，从而引发错误。所以如果有在堆区开辟的属性，就一定要自
 *  定义拷贝构造函数，通过深拷贝来进行拷贝。
 *
 * 6. 初始化列表
 *  C++除了提供传统的构造函数之外，还提供了初始化列表语法，用来初始化属性。
 *  语法：构造函数():属性1(值1),属性2(值2)...{...}
 *
 * 7. 类对象作为类成员
 *  在C++中，一个类的成员可以是另一个类的对象，我们称这种成员为对象成员。
 *  带有对象成员的类，在初始化时，先构造对象成员，再构造自己；
 *  在销毁时，先析构自己，再析构对象成员，两者顺序相反。
 *
 * 8. 静态成员
 *  类的成员变量与成员方法，在前面加上关键字static后。就被称为静态成员。
 *  这两者的访问，都可以通过以下两种方式达成：
 *      通过对象：对象名.静态成员变量名/静态成员函数名
 *      通过类名：类名::静态成员变量名/静态成员函数名
 *  静态成员变量
 *      所有对象共享同一份数据
 *      在编译阶段分配内存
 *      类内声明，类外初始化
 *  静态成员函数
 *      所有对象共享同一个函数
 *      静态成员方法仅能访问静态成员变量。如若不然，某个对象在调用静态成员方法时，
 *    不能确认方法中的普通变量属于哪个对象。
 *
 */
#include <iostream>
#include <string>
using namespace std;

// 1.构造函数与析构函数
class Person_1{
public:
    //构造函数
    Person_1(){
        cout<<"Person_1 构造函数"<<endl;
    }

    //析构函数
    ~Person_1(){
        cout<<"Person_1 析构函数"<<endl;
    }
};

void test_1(){
    //栈区的数据，会在函数调用结束后立即释放
    Person_1 p1;
}

class Person_2{
public:
    //无参构造函数（默认）
    Person_2(){
       cout<<"Person_2 无参构造函数（默认）"<<endl;
    }

    //有参构造函数
    Person_2(int age){
        this->age=age;
        cout<<"Person_2 有参构造函数"<<endl;
    }

    //拷贝构造函数
    Person_2(const Person_2 &p){
        age=p.age;
        cout<<"Person_2 拷贝构造函数"<<endl;
    }

    //析构函数
    ~Person_2(){
        cout<<"Person_2 析构函数"<<endl;
    }

private:
    int age;
};

// 2.构造函数的分类与调用
// 分类
void test_2_1(){
    Person_2 p1;
    Person_2 p2(10);
    Person_2 p3(p2);
}

// 调用
void test_2_2(){
    // 括号法
    Person_2 p1(10);

    // 调用默认构造（无参构造）时，不可以加括号，否则编译器会认为这是函数声明。
    // Person_2 p2();  // Function 'p2' is never used

    // 显示法
    Person_2 p2=Person_2(10);   // 有参
    Person_2 p3=Person_2(p2);       // 拷贝
    // Person_2(10) 单独写即为匿名对象，在当前行执行结束后，立即被释放（析构）

    // 不要用拷贝构造函数来初始化匿名函数，否则，在编译器看来这是一个对象声明
    // Person_2(p4);   // 等价于 Person_2 p4

    // 隐式转换法
    Person_2 p4=10; // 等价于 Person_2 p2=Person_2(10);
    Person_2 p5=p4; // 等价于 Person_2 p3=Person_2(p4);
}

// 3.拷贝函数的调用时机
// 3.1 一个对象需要通过一个已经创建的对象来初始化
void test_3_1(){
    Person_2 p(10); // 无参构造函数
    Person_2 p1(p);     // 调用拷贝构造函数
    Person_2 p2=p;      // 调用拷贝构造函数

    Person_2 p3;
    p3=p;   // 不调用拷贝构造函数，是赋值操作
}
// 3.2 一个对象以值传递的方式传入函数体
void value(Person_2 p){}
void test_3_2(){
    Person_2 p; // 无参构造函数
    value(p);
}
// 3.3 一个对象以值传递的方式从函数返回
Person_2& result(){
    Person_2 p;
    cout<<"result()函数内变量p的地址为：\t\t"<<(int *)&p<<endl;
    return p;
}
void test_3_3(){
    Person_2 p1=result();
    cout<<"result()函数返回的变量p的地址为：\t"<<(int *)&p1<<endl;
}

// 5. 深拷贝与浅拷贝
class Person_3{
public:
    //无参构造函数（默认）
    Person_3(){
        cout<<"Person_3 无参构造函数（默认）"<<endl;
    }

    //有参构造函数
    Person_3(int age,int height){
        this->age=age;
        this->height=new int(height);
        cout<<"Person_3 有参构造函数"<<endl;
    }

    //拷贝构造函数
    Person_3(const Person_3 &p){
        age=p.age;
        //利用深拷贝来在堆区开辟空间，避免利用浅拷贝带来的堆区重复释放问题
        height=new int(*p.height);
        cout<<"Person_3 拷贝构造函数"<<endl;
    }

    //析构函数
    ~Person_3(){
        //释放在堆区开辟的空间
        if(height!=NULL){
            delete height;
        }
        cout<<"Person_3 析构函数"<<endl;
    }

    void show(){
        cout<<"age:"<<age<<",height:"<<*height<<endl;
        cout<<"height变量的地址："<<height<<endl;
    }

private:
    int age=0;
    int *height=0;
};
void test_5(){
    Person_3 p1(22,180);
    Person_3 p2(p1);
    cout<<"p1:"<<endl;
    p1.show();
    cout<<"p2:"<<endl;
    p2.show();
}

// 6. 初始化列表
class Person_4{
public:

    // 初始化列表方式初始化
    Person_4(int a,int b,int c):A(a),B(b),C(c){}

    void show(){
        cout<<"A:"<<A<<",B:"<<B<<",C:"<<C<<endl;
    }

private:
    int A;
    int B;
    int C;

};
void test_6(){
    Person_4 p(1,2,3);
    p.show();
}

// 7. 类对象作为类成员
class Pat{
public:
    Pat(string name){
        this->name=name;
        cout<<"Pat 有参构造函数"<<endl;
    }

    ~Pat(){
        cout<<"Pat 析构函数"<<endl;
    }
private:
    string name;
};
class Person{
public:
    string name;
    Pat pat;

    // 初始化列表传参
    Person(string person,string patname):name(person), pat(patname){
        cout<<"Person 有参构造函数"<<endl;
    }

    ~Person(){
        cout<<"Person 析构函数"<<endl;
    }
};
void test_7(){
    Person p("Alice","cat");
}

// 8. 静态成员
// 静态成员变量
class Person_5{
public:
    static int sA;
};
//类内声明，类外初始化
int Person_5::sA=10;
void test_8_1(){
    Person_5 p1;
    //1. 通过对象访问
    p1.sA=100;
    cout<<"p1.sA="<<p1.sA<<endl;

    Person_5 p2;
    p2.sA=200;  //所有对象共享同一份数据
    cout<<"p1.sA="<<p1.sA<<endl;
    cout<<"p2.sA="<<p2.sA<<endl;

    //2. 通过类名访问
    cout<<"Person_5::sA="<<Person_5::sA<<endl;

}

class Person_6{
public:
    static int sA;

    static void func(){
        cout<<"static void func()"<<endl;
        sA=200;
    }

};
//类内声明，类外初始化
int Person_6::sA=10;
void test_8_2(){
    Person_6 p;
    //1. 通过对象访问
    p.func();
    //2. 通过类名访问
    Person_6::func();
}

int main() {
    //1.构造函数与析构函数
    test_1();
    cout<<"===================="<<endl;

    //2.构造函数的分类与调用
    test_2_1();
    cout<<"===================="<<endl;

    // 3.拷贝函数的调用时机
    // 3.1 一个对象需要通过一个已经创建的对象来初始化
    test_3_1();
    cout<<"===================="<<endl;
    // 3.2 一个对象以值传递的方式传入函数体
    test_3_2();
    cout<<"===================="<<endl;
    // 3.3 一个对象以值传递的方式从函数返回
    test_3_3();
    cout<<"===================="<<endl;

    // 5. 深拷贝与浅拷贝
    test_5();
    cout<<"===================="<<endl;

    // 6. 初始化列表
    test_6();
    cout<<"===================="<<endl;

    // 7. 类对象作为类成员
    test_7();
    cout<<"===================="<<endl;

    // 8. 静态成员
    // 静态成员变量
    test_8_1();
    cout<<"===================="<<endl;
    // 静态成员函数
    test_8_2();

    return 0;
}
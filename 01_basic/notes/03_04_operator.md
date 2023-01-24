本文是笔者在C++学习过程中，对类和对象的总结记录，如有不对以及不足的地方，欢迎大家指正！

****
&emsp;&emsp;什么是运算符重载？运算符重载就是对已有的运算符重新定义，赋予该运算符新的功能，使它能处理不同的数据类型。

### 加号运算符重载：+
通过对加号运算符的重载，实现两个自定义数据类型的相加。

```cpp
#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    // 成员函数 重载加号运算符：+
//    Person operator+(Person &person){
//        return Person(this->A+person.A,this->B+person.B);
//    }

    Person(int A,int B){
        this->A=A;
        this->B=B;
    }

    int getA() const {
        return A;
    }

    int getB() const {
        return B;
    }
    
private:
    int A;
    int B;
};

// 全局函数 重载加号运算符：+
Person operator+(Person &p1,Person &p2){
    return Person(p1.getA()+p2.getA(),p1.getB()+p2.getB());
}

void test_1(){
    Person p1(10,10);
    Person p2(20,20);

    Person p3=p1+p2;

    cout<<"p1.A:"<<p1.getA()<<" p1.B:"<<p1.getB()<<endl;
    cout<<"p2.A:"<<p2.getA()<<" p2.B:"<<p2.getB()<<endl;
    cout<<"p3.A:"<<p3.getA()<<" p3.B:"<<p3.getB()<<endl;
    
}

int main() {
    test_1();
    return 0;
}
```
运行结果：
![1](https://img-blog.csdnimg.cn/c8193135bc234e1691c80c8ba2a01764.png)


****

### 左移运算符重载：<<
通过对左移运算符的重载，实现自定义数据类型的输出。

```cpp
#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    Person(int A,int B){
        this->A=A;
        this->B=B;
    }

    int getA() const {
        return A;
    }

    int getB() const {
        return B;
    }

private:
    int A;
    int B;
};

// 左移运算符重载：<<
ostream& operator<<(ostream &cout,Person &p){
    cout<<"A is:"<<p.getA()<<",B is:"<<p.getB();
    return cout;
}

void test_2(){
    Person p(10,20);
    cout<<p<<"  "<<p<<endl;
}

int main() {
	test_2();
    return 0;
}
```
运行结果：
![2](https://img-blog.csdnimg.cn/6d05d90ef898475e8dc362185e70e3c6.png)



****

### 递增/递减运算符重载：++ / --


```cpp
#include <iostream>
#include <string>
using namespace std;


// 递增/递减运算符重载：++ / --
class MyInteger{
public:
    // 前置递增运算符重载
    MyInteger& operator++(){
        // 先递增
        num++;
        // 再返回
        return *this;
    }

    // 后置递增运算符重载
    MyInteger operator++(int){
        // 先记录要返回的原先值
        MyInteger temp=*this;
        // 再递增
        num++;
        // 最后返回
        return temp;
    }

    // 前置递减运算符重载
    MyInteger& operator--(){
        // 先递减
        num--;
        // 再返回
        return *this;
    }

    // 后置递减运算符重载
    MyInteger operator--(int){
        // 先记录要返回的原先值
        MyInteger temp=*this;
        // 再递减
        num--;
        // 最后返回
        return temp;
    }

    MyInteger(){
        num=0;
    }

    MyInteger(int num){
        this->num=num;
    }

    int getNum() const {
        return num;
    }
    
private:
    int num;
};

// 左移运算符重载：<<
ostream& operator<<(ostream &cout,MyInteger my){
    cout<<my.getNum();
    return cout;
}

void test_3(){
    MyInteger myInteger(10);
    cout<<myInteger<<endl;      // 10
    cout<<++myInteger<<endl;    // 11
    cout<<--myInteger<<endl;    // 10

    cout<<myInteger++<<endl;    // 10
    cout<<myInteger<<endl;      // 11
    cout<<myInteger--<<endl;    // 11
    cout<<myInteger<<endl;      // 10
}

int main() {
	test_3();
    return 0;
}
```

****

### 赋值运算符重载：=
&emsp;&emsp;编译器默认的赋值运算，进行的是简单的**值拷贝**，即**浅拷贝**，如果赋值运算符（=）左右的对象当中存在有**在堆区开辟的属性**，即**指针型成员变量**的话，就需要对赋值运算符进行重载，来进行**深拷贝**。

```cpp
#include <iostream>
#include <string>
using namespace std;

// 赋值运算符重载：=
class Person1{
public:
    void operator=(Person1 &p){
        if (age!=NULL){
            delete age;
            age=NULL;
        }
        age=new int(*p.age);
    }

    Person1(int age){
        //在堆区开辟空间
        cout<<"有参构造函数调用"<<endl;
        this->age=new int(age);
    }

    ~Person1(){
        cout<<"析构函数调用"<<endl;
        if (age!=NULL){
            delete age;
            age=NULL;
        }
    }

    int *getAge() const {
        return age;
    }
private:
    int *age;
};

void test_4(){
    Person1 p1(10);
    Person1 p2(20);
    cout<<"p1 age is:"<<*p1.getAge()<<endl;
    cout<<"p2 age is:"<<*p2.getAge()<<endl;
    p1=p2;
    cout<<"p1 age is:"<<*p1.getAge()<<endl;
}

int main() {
	test_4();
    return 0;
}
```
运行结果：
![4](https://img-blog.csdnimg.cn/d016aaab83a94049b010e075a52bf7bb.png)



****

### 关系运算符重载：==、!= 等
```cpp
#include <iostream>
#include <string>
using namespace std;

// 关系运算符重载：==、!= 等
class Person2{
public:

    bool operator==(Person2 &p){
        if (this->age==p.age && this->name==p.name){
            return true;
        }
        return false;
    }

    bool operator!=(Person2 &p){
        if (this->age!=p.age || this->name!=p.name){
            return false;
        }
        return true;
    }

    Person2(int age,string name){
        this->age=age;
        this->name=name;
    }

private:
    int age;
    string name;
};

void test_5(){
    Person2 p1(10,"Bob");
    Person2 p2(20,"Alice");
    Person2 p3(10,"Bob");

    cout<<((p1==p2)?"true":"false")<<endl;
    cout<<((p1==p3)?"true":"false")<<endl;
}

int main() {
	test_5();
    return 0;
}
```
运行结果：
![5](https://img-blog.csdnimg.cn/0b231c5213ba4b4db89e39d343886621.png)



****

### 函数调用运算符重载：()
由于函数调用运算符重载后的使用与函数调用极为相似，所以在使用时被称为**仿函数**。
```cpp
#include <iostream>
#include <string>
using namespace std;

// 函数调用运算符重载：()
class MyAdd{
public:
    int operator()(int a,int b){
        return a+b;
    }
};

void test_6(){
    MyAdd add;
    cout<<"10+20="<<add(10,20)<<endl;
    // 匿名函数对象，执行完立即释放
    cout<<"10+20="<<MyAdd()(10,20)<<endl;

}

int main() {
	test_6();
    return 0;
}
```
运行结果：
![6](https://img-blog.csdnimg.cn/6e287ebf45044afa95c77a4fc8847ae0.png)


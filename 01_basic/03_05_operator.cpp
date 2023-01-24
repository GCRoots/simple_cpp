/**
 * Created by 史进 on 2022/10/22.
 *
 * 加号运算符重载：+
 * 左移运算符重载：<<
 * 递增/递减运算符重载：++ / --
 * 赋值运算符重载：=
 * 关系运算符重载：==、!= 等
 * 函数调用运算符重载：()
 */
#include <iostream>
#include <string>
using namespace std;

// 加号运算符重载：+
// 左移运算符重载：<<
// 递增/递减运算符重载：++ / --
// 赋值运算符重载：=
// 关系运算符重载：==、!= 等
// 函数调用运算符重载：()

class Person{
public:
    // 成员函数 加号运算符重载：+
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

// 全局函数 加号运算符重载：+
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

// 左移运算符重载：<<
ostream& operator<<(ostream &cout,Person &p){
    cout<<"A is:"<<p.getA()<<",B is:"<<p.getB();
    return cout;
}

void test_2(){
    Person p(10,20);
    cout<<p<<"  "<<p<<endl;
}

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
    test_1();
    cout<<"--------------------"<<endl;
    test_2();
    cout<<"--------------------"<<endl;
    test_3();
    cout<<"--------------------"<<endl;
    test_4();
    cout<<"--------------------"<<endl;
    test_5();
    cout<<"--------------------"<<endl;
    test_6();

    return 0;
}
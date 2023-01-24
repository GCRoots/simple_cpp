/**
 * Created by ubuntu on 2022/9/15.
 *
 * 引用（reference）代码示例
 *
 * 作用：给变量起别名
 * 语法：数据类型 &引用变量名 = 原变量名；
 *
 * 注意事项：
 * 1. 对引用进行操作，实际上就是对被引用的变量进行操作
 * 2. 声明引用时，必须对其进行初始化
 * 3. 引用在初始化之后，不可以再进行修改
 * 4. 引用变量在编译器的底层实现是指针常量，即一个指针指向不可以发生更改的指针，
 *    所以引用占用内存空间的大小，和指针其实是一样的。
 *    但是，和指针不同的是，引用实际上不能算是一个变量，所以对引用变量求地址，与
 *    对实际变量求地址，结果是相同的
 * 5. 不能建立引用的数组，但是，可以建立数组的引用
 *
 * 应用：
 * 1. 引用作为函数参数
 *    注意事项:
 *    1. 不要返回局部变量的引用
 *    2. 函数调用可以作为左值
 *    3. 不要返回函数内部使用 new 分配的内存的引用
 * 2. 引用作为函数返回值
 * 3. 常量引用/常引用
 */
#include <iostream>
#include <string>
using namespace std;

//1. 引用作为函数参数
void func1(int &a,int &b);
//2. 引用作为函数返回值
int& func2(int &a);
//  注意事项
//  1. 不要返回局部变量的引用
int& func2_local();
//  2. 函数调用可以作为左值
int& func2_left();
//  3. 不要返回函数内部使用 new 分配的内存的引用
string& func2_new();
//3. 常量引用/常引用
void func3(const int &a);

int main() {
    //语法：数据类型 &引用变量名 = 原变量名；
    int a=10;
    int &reference_a=a;

    //基础示例
    cout<<"a.html="<<a<<endl; //a.html=10
    cout<<"reference_a="<<reference_a<<endl; //reference_a=10
    a+=10;
    cout<<"a.html="<<a<<endl; //a.html=20
    cout<<"reference_a="<<reference_a<<endl; //reference_a=20
    reference_a+=10;
    cout<<"a.html="<<a<<endl; //a.html=30
    cout<<"reference_a="<<reference_a<<endl; //reference_a=20
    cout<<""<<endl;

    //对引用变量求地址,与对实际变量求地址，结果是相同的
    cout<<"对引用变量求地址"<<endl;
    cout<<"a的地址:\t\t\t\t"<<&a<<endl;
    cout<<"reference_a的地址:\t"<<&reference_a<<endl;
    cout<<""<<endl;

    //不能建立引用的数组，但是，可以建立数组的引用
    int arr[]={0,1,2,3,4};

    //引用的数组
    // int &re_arr=&arr;
    // Non-const lvalue reference to type 'int' cannot bind to
    // a.html temporary of type 'int (*)[5]'
    // 编译错误
    // error: invalid conversion from ‘int (*)[5]’ to ‘int’

    //数组的引用
    int (&re_arr)[5]=arr;

    cout<<"数组的引用"<<endl;
    cout<<"arr:"<<endl;
    for (int i = 0; i < 5; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<""<<endl;

    cout<<"re_arr:"<<endl;
    for (int i = 0; i < 5; ++i) {
        cout<<re_arr[i]<<" ";
    }
    cout<<""<<endl<<endl;

    //引用作为函数参数
    cout<<"引用作为函数参数"<<endl;
    a=10;
    int b=20;
    cout<<"a.html="<<a<<",b="<<b<<endl;
    func1(a,b);
    cout<<"a.html="<<a<<",b="<<b<<endl;
    cout<<""<<endl;

    //引用作为函数返回值
    cout<<"引用作为函数返回值"<<endl;
    b=10;
    cout<<"fun2()前,b="<<b<<endl;
    cout<<"fun2()后,b="<<func2(b)<<endl;
    cout<<""<<endl;

    // 注意事项
    // 1. 不要返回局部变量的引用
    cout<<"1. 不要返回局部变量的引用"<<endl;
    int &ref_locol=func2_local();
//    cout<<"ref_locol="<<ref_locol<<endl;         //编译错误
    cout<<"ref_locol的地址为:"<<&ref_locol<<endl;   //输出地址为0
    cout<<""<<endl;

    // 2. 函数调用可以作为左值
    cout<<"函数调用可以作为左值"<<endl;
    int left=func2_left();
    cout<<"left="<<left<<endl;
    cout<<"func2_left()作为左值，修改为100"<<endl;
    func2_left()=100;
    cout<<"left="<<left<<endl;
    cout<<""<<endl;

    // 3. 不要返回函数内部使用 new 分配的内存的引用
    cout<<"不要返回函数内部使用 new 分配的内存的引用"<<endl;
    string &str=func2_new();    //如果调用后没有用 delete 释放，就会造成内存泄漏
    cout<<"str="<<str<<endl;
    delete &str;                //释放
    cout<<""<<endl;

    //常量引用/常引用
    cout<<"常量引用/常引用"<<endl;
    func3(a);
    cout<<""<<endl;

    return 0;
}

//1. 引用作为函数参数
void func1(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

//2. 引用作为函数返回值
int& func2(int& a){
    a*=a;
    return a;
}

//  注意事项
//  1. 不要返回局部变量的引用
int& func2_local(){
    int a=10;   //栈区，函数调用结束后释放
    return a;   //Reference to stack memory associated
                // with local variable 'a.html' returned
}

//  2. 函数调用可以作为左值
int& func2_left(){
    static int a=10;    //全局区，程序结束后由系统释放
    return a;
}

//  3. 不要返回函数内部使用 new 分配的内存的引用
string& func2_new(){
    string* str=new string("hello world");
    return *str;
}

//常量引用/常引用
void func3(const int &a){
    cout<<"a.html="<<a<<endl;
}
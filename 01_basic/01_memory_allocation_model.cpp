/**
 * Created by ubuntu on 2022/9/8.
 *
 * 内存分区模型代码示例
 *
 * 代码区  存放函数的二进制代码，即CPU执行的机器指令，由操作系统进行管理。
 * 全局区  存放全局变量、静态变量（static，分为全局与局部静态变量）和部分常量（字符串常量和全局常量）。
 * 栈区   由编译器自动分配和释放，存放函数的参数值、局部变量等。
 * 堆区   由程序员进行分配和释放，而如果程序员不释放，则在程序结束运行时，由操作系统来进行回收。
 *       主要利用 new 在堆区开辟内存，由 delete 进行释放。
 *
 */

#include <iostream>
using namespace std;

//全局变量 全局区
int global_a=10;
int global_b=20;

//全局常量 全局区
const int global_const_a=10;
const int global_const_b=20;

//全局静态变量 全局区
static int static_global_a=10;
static int static_global_b=20;

//形参 栈区
void func(int a){

    //局部变量 栈区
    int b=20;

    cout<<"函数func()的形参 a.html 的地址为：\t\t"<< &a <<endl;
    cout<<"函数func()的局部变量 b 的地址为：\t"<< &b <<endl<<endl;
}

int main() {

    cout<<"栈区"<<endl;

    //局部变量 栈区
    int a = 10;
    int b = 20;

    cout<<"局部变量 a.html 的地址为：\t\t\t\t"<< &a <<endl;
    cout<<"局部变量 b 的地址为：\t\t\t\t"<< &b <<endl;

    //局部常量 栈区
    const int const_a=10;
    const int const_b=10;

    cout<<"局部常量 const_a 的地址为：\t\t"<< &const_a <<endl;
    cout<<"局部常量 const_b 的地址为：\t\t"<< &const_b <<endl;

    //形参 栈区
    func(a);


    cout<<"全局区"<<endl;

    cout<<"全局变量 global_a 的地址为：\t\t\t"<< &global_a <<endl;
    cout<<"全局变量 global_b 的地址为：\t\t\t"<< &global_b <<endl;

    cout<<"全局常量 global_const_a 的地址为：\t\t"<< &global_const_a <<endl;
    cout<<"全局常量 global_const_a 的地址为：\t\t"<< &global_const_b <<endl;

    cout<<"全局静态变量 static_global_a 的地址为：\t"<< &static_global_a <<endl;
    cout<<"全局静态变量 static_global_b 的地址为：\t"<< &static_global_b <<endl;

    //局部静态变量 全局区
    static int Static_a=10;
    static int Static_b=20;

    cout<<"局部静态变量 Static_a 的地址为：\t\t"<< &Static_a <<endl;
    cout<<"局部静态变量 Static_b 的地址为：\t\t"<< &Static_b <<endl;

    //字符串常量 全局区
    cout<<"字符串常量的地址为：\t\t\t\t\t"<< &"hello world s1" <<endl;
    cout<<"字符串常量的地址为：\t\t\t\t\t"<< &"hello world s2" <<endl<<endl;


    cout<<"堆区"<<endl;

    //new 堆区
    int* new_a=new int(10);
    int* new_b=new int(20);

    cout<<"堆区变量 new_a 的地址为：\t"<< new_a <<endl;
    cout<<"堆区变量 new_a 的地址为：\t"<< new_b <<endl;

    return 0;
}



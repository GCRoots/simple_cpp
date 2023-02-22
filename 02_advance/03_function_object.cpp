/**
 * Created by 史进 on 2023/2/11.
 *
 * 重载函数调用操作符的类，其对象称为函数对象
 * 因为函数对象在使用其重载的 () 时，行为类似于函数调用，故也称仿函数
 *
 * 函数对象（仿函数）其本质上是一个类，而不是一个函数
 *
 * 特点：
 *  1、函数对象在使用时，可以像普通函数一样调用，可以有参数和返回值
 *  2、函数对象超出普通函数的概念，函数对象可以有自己的状态
 *  3、函数对象可以作为参数传递
 *
 * 谓词：
 *  返回bool类型的仿函数称为谓词
 *
 *  一元谓词：operator()接受一个参数
 *  二元谓词：operator()接受两个参数
 *
 * 内建函数对象：
 *  STL提供了一些函数对象
 *  分类：
 *      1、算术仿函数
 *      2、关系仿函数
 *      3、逻辑仿函数
 *  需引入头文件：#include <functional>
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// 1、函数对象在使用时，可以像普通函数一样调用，可以有参数和返回值
class MyAdd{
public:
    int operator()(int lv,int rv){
        return lv+rv;
    }

};

void test01(){
    MyAdd my;
    cout << my(10,20) << endl;
}

// 2、函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint{
public:
    void operator()(string str){
        cout << str << "\t第" << ++count << "次调用" << endl;
    }
    int count=0;

};

void test02(){
    MyPrint my;
    my("Hello World!");
    my("Hello World!");
    my("Hello World!");
    my("Hello World!");
}

// 3、函数对象可以作为参数传递
void doPrint(MyPrint &myPrint,string str){
    myPrint(str);
}

void test03(){
    MyPrint my;
    doPrint(my,"Hello C++");
}

// 一元谓词：operator()接受一个参数
class GreaterFive{
public:
    bool operator()(int val){
        return val>5;
    }
};

void test04(){
    vector<int> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    // 查找容器中是否有大于五的数
    auto it = find_if(vec.begin(),vec.end(),GreaterFive());
    if (it == vec.end()){
        cout << "未找到" << endl;
    } else{
        cout << "已找到大于五的数：" << *it << endl;
    }
}

// 二元谓词：operator()接受两个参数
class MyCompare{
public:
    bool operator()(int &lv,int &rv){
        return lv>rv;
    }
};

void test05(){
    vector<int> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    for (auto it : vec) {
        cout << it << " ";
    }
    cout << endl;

    sort(vec.begin(),vec.end(),MyCompare());

    for (auto it : vec) {
        cout << it << " ";
    }
    cout << endl;
}

// 1、算术仿函数
void test06(){
    // 加法仿函数 plus
    plus<int> p;
    cout << p(50,10) << endl;

    // 区反仿函数 negate
    negate<int> ne;
    cout << ne(50) << endl;

    // 减法仿函数 minus
    // 乘法仿函数 multiplies
    // 除法仿函数 divides
    // 取模仿函数 modulus
}

// 2、关系仿函数
void test07(){
    // 等于 equal_to  不等于 not_equal_to
    // 大于 greater   大于等于 greater_equal
    // 小于 less      小于等于 less_equal
    vector<int> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    for (auto it : vec) {
        cout << it << " ";
    }
    cout << endl;

    sort(vec.begin(),vec.end(),greater<int>());

    for (auto it : vec) {
        cout << it << " ";
    }
    cout << endl;

}

// 3、逻辑仿函数
void test08(){
    // 逻辑与 logical_and
    // 逻辑或 logical_or
    // 逻辑非 logical_not

    vector<bool> v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);

    for(auto it : v){
        cout << it << " ";
    }
    cout << endl;

    vector<bool> v2;
    v2.resize(v.size());
    transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());

    for(auto it : v2){
        cout << it << " ";
    }
    cout << endl;

}


int main() {
    std::cout << "Hello, World!" << std::endl;
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    test07();
    test08();

    return 0;
}

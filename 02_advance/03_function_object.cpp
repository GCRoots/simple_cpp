/**
 * Created by 史进 on 2023/2/11.
 *
 * 重载函数调用操作符的类，其对象称为函数对象
 * 因为函数对象在使用其重载的 () 时，行为类似于函数调用，故也称仿函数
 *
 * 函数对象（仿函数）其本质上是一个类，而不是一个函数
 *
 */
#include <iostream>
#include <string>

using namespace std;


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

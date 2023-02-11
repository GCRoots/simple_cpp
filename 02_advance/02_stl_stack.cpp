/**
 * Created by 史进 on 2023/1/30.
 *
 * stack 栈：后进先出
 *
 * 不允许有遍历操作
 *
 */
#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 栈的操作
void test01(){
    // 默认构造
    stack<int> s1;

    // 入栈
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << s1.size() << endl;

    // 拷贝构造
    stack<int> s2(s1);
    cout << s2.size() << endl;

    while(!s1.empty()){
        cout << s1.top() << endl;
        s1.pop();
    }
    cout << s1.size() << endl;

}



int main() {
    std::cout << "Hello, World!" << std::endl;
    test01();
    return 0;
}
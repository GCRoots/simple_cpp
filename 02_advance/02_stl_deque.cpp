/**
 * Created by 史进 on 2023/1/29.
 *
 * deque：双端数组
 *
 * deque内部有一个中控器，用来维护多段缓冲区，缓冲区中存放数据
 * 中控器中维护的是每段缓冲区的地址，使得使用deque时像使用一片连续的内存空间
 *
 * deque容器的 迭代器支持随机访问
 *
 */
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

void printDeque(const deque<int> &d){
    for (auto it:d) {
        cout << it << " ";
    }
    cout << endl;
}

// 构造函数
void test01(){
    // 默认构造
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }
    printDeque(d1);

    // 通过迭代器区间构造
    deque<int> d2(d1.begin(),d1.end());
    printDeque(d2);

    // n个elem元素
    deque<int> d3(10,99);
    printDeque(d3);

    // 拷贝构造
    deque<int> d4(d3);
    printDeque(d4);
}

// 赋值操作
void test02(){
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }
    printDeque(d1);

    // operator=
    deque<int> d2 = d1;
    printDeque(d2);

    // assign()：迭代器区间
    deque<int> d3;
    d3.assign(d1.begin(),d1.end());
    printDeque(d3);

    // assign()：n个elem
    deque<int> d4;
    d4.assign(10,99);
    printDeque(d4);
}

// 大小
void test03(){
    deque<int> d1;
    cout << "d1 " << (d1.empty()?"is":"is not") << " empty." << endl;
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }
    printDeque(d1);
    cout << "d1 " << (d1.empty()?"is":"is not") << " empty." << endl;

    cout << "d1's size:" << d1.size() << endl;

    d1.resize(15);
    printDeque(d1);
    cout << "d1's size:" << d1.size() << endl;

    d1.resize(20,100);
    printDeque(d1);
    cout << "d1's size:" << d1.size() << endl;
}

// 插入和删除
void test04(){
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        // 尾插法
        d1.push_back(i);
    }

    printDeque(d1);
    for (int i = 0; i < 10; ++i) {
        // 头插法
        d1.push_front(i*i);
    }
    printDeque(d1);

    // 尾删法
    d1.pop_back();
    printDeque(d1);

    // 头删法
    d1.pop_front();
    printDeque(d1);

    // insert()
    d1.insert(d1.begin(),1000);
    printDeque(d1);

    d1.insert(d1.begin(),2, 9999);
    printDeque(d1);

    deque<int> d2(2,50);
    d1.insert(d1.begin(),d2.begin(),d2.end());
    printDeque(d1);

    // erase()
    d1.erase(d1.begin());
    printDeque(d1);

    d1.erase(d1.begin(),d1.begin()+5);
    printDeque(d1);

    d1.clear();
    printDeque(d1);
}

// 数据存取
void test05(){
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }
    printDeque(d1);

    // at()
    cout << "v1.at(4):" << d1.at(4) << endl;

    // []
    cout << "v1[4]:" << d1[4] << endl;

    // front()
    cout << "v1.front():" << d1.front() << endl;

    // back()
    cout << "v1.back():" << d1.back() << endl;
}

// 排序
void test06(){
    deque<int> d1;
    for (int i = 0; i < 10; ++i) {
        d1.push_back(i);
    }
    for (int i = 0; i < 10; ++i) {
        d1.push_front(i*i);
    }
    printDeque(d1);

    // 支持随机访问迭代器的容器，都可以使用sort算法进行排序
    sort(d1.begin(),d1.end());
    printDeque(d1);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    return 0;
}
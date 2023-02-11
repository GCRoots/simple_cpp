/**
 * Created by 史进 on 2023/1/28.
 *
 * vector容器使用示例
 *
 * vector容器可以动态扩展
 *  开辟更大的空间，将原空间数据拷贝到新空间，再释放原空间
 *
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void myPrint(int val){
    cout << val << " ";
}

// vector容器存放内置数据类型
void test01(){
    vector<int> v;

    // 插入数据
    v.reserve(10);
    for (int i = 0; i < 10; ++i) {
        v.push_back((i+1)*10);
    }

    // 通过迭代器访问数据
    // 1
    auto itBegin = v.begin();
    auto itEnd = v.end();
    while (itBegin != itEnd){
        cout << *itBegin++ << " ";
    }
    cout << endl;

    // 2
    for (auto it = v.begin(); it != v.end() ; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 改进
    for (auto & it : v) {
        cout << it << " ";
    }
    cout << endl;

    // 3 stl遍历算法
    for_each(v.begin(),v.end(), myPrint);
    cout << endl;
}

class Person{
public:
    Person(string name,int age):m_name(name),m_age(age){
        cout << "Person 构造函数调用" << endl;
    }
    void showPerson(){
        cout << "name:" << this->m_name << "\tage:" << this->m_age << endl;
    }

    string m_name;
    int m_age;
};

// vector容器存放自定义数据类型
void test02(){
    vector<Person> v;
    Person p1("A",10);
    Person p2("B",11);
    Person p3("C",13);
    Person p4("D",14);
    Person p5("E",15);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for (auto & it : v){
        it.showPerson();
    }

}

// vector容器存放自定义数据类型指针
void test03(){
    vector<Person*> v;
    Person p1("A",10);
    Person p2("B",11);
    Person p3("C",13);
    Person p4("D",14);
    Person p5("E",15);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for (auto & it : v){
        it->showPerson();
    }

}

// 构造函数
void test_1(){
    // 默认构造
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    for (auto i:v1) {
        cout << i << " ";
    }
    cout << endl;

    // 通过迭代器区间构造
    vector<int> v2(v1.begin(),v1.end());
    for (auto i:v2) {
        cout << i << " ";
    }
    cout << endl;

    // n个elem元素
    vector<int> v3(10,99);
    for (auto i:v3) {
        cout << i << " ";
    }
    cout << endl;

    // 拷贝构造
    vector<int> v4(v3);
    for (auto i:v4) {
        cout << i << " ";
    }
    cout << endl;
}

// 赋值操作
void test_2(){
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    for (auto i:v1) {
        cout << i << " ";
    }
    cout << endl;

    // operator=
    vector<int> v2 = v1;
    for (auto i:v2) {
        cout << i << " ";
    }
    cout << endl;

    // assign()：迭代器区间
    vector<int> v3;
    v3.assign(v1.begin(),v1.end());
    for (auto i:v3) {
        cout << i << " ";
    }
    cout << endl;

    // assign()：n个elem
    vector<int> v4;
    v4.assign(10,99);
    for (auto i:v4) {
        cout << i << " ";
    }
    cout << endl;
}

// 容量和大小
void test_3(){
    vector<int> v1;
    cout << "v1 " << (v1.empty()?"is":"is not") << " empty." << endl;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    for (auto i:v1) {
        cout << i << " ";
    }
    cout << endl;
    cout << "v1 " << (v1.empty()?"is":"is not") << " empty." << endl;

    cout << "v1's capacity:" << v1.capacity() << endl;
    cout << "v1's size:" << v1.size() << endl;

    v1.resize(15);
    for (auto i:v1) {
        cout << i << " ";
    }
    cout << endl;
    cout << "v1 " << (v1.empty()?"is":"is not") << " empty." << endl;

    cout << "v1's capacity:" << v1.capacity() << endl;
    cout << "v1's size:" << v1.size() << endl;


    v1.resize(20,99);
    for (auto i:v1) {
        cout << i << " ";
    }
    cout << endl;
    cout << "v1 " << (v1.empty()?"is":"is not") << " empty." << endl;

    cout << "v1's capacity:" << v1.capacity() << endl;
    cout << "v1's size:" << v1.size() << endl;

    v1.resize(15);
    for (auto i:v1) {
        cout << i << " ";
    }
    cout << endl;
    cout << "v1 " << (v1.empty()?"is":"is not") << " empty." << endl;

    cout << "v1's capacity:" << v1.capacity() << endl;
    cout << "v1's size:" << v1.size() << endl;

}

// 插入和删除
void test_4(){
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        // 尾插法
        v1.push_back(i*10);
    }
    for (auto i:v1) {
        cout << i << " ";
    }
    cout << endl;

    // 尾删法
    v1.pop_back();
    for (auto i:v1) {
        cout << i << " ";
    }
    cout << endl;

    // insert()
    v1.insert(v1.begin(),1000);
    for (auto i:v1) {
        cout << i << " ";
    }
    cout << endl;

    v1.insert(v1.begin(),2,2000);
    for (auto i:v1) {
        cout << i << " ";
    }
    cout << endl;

    // erase()
    v1.erase(v1.begin());
    for (auto i:v1) {
        cout << i << " ";
    }
    cout << endl;

    v1.erase(v1.begin(),v1.end());
//    v1.clear();
    for (auto i:v1) {
        cout << i << " ";
    }
    cout << endl;
}

// 数据存取
void test_5(){
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        // 尾插法
        v1.push_back(i*10);
    }
    for (auto i:v1) {
        cout << i << " ";
    }
    cout << endl;

    // at()
    cout << "v1.at(4):" << v1.at(4) << endl;

    // []
    cout << "v1[4]:" << v1[4] << endl;

    // front()
    cout << "v1.front():" << v1.front() << endl;

    // back()
    cout << "v1.back():" << v1.back() << endl;
}

// 互换容器 swap()
void test_6(){
    cout << "swap()前：" << endl;
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i*10);
    }
    cout << "v1:";
    for (auto i:v1) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> v2;
    for (int i = 0; i < 10; ++i) {
        v2.push_back(i);
    }
    cout << "v2:";
    for (auto i:v2) {
        cout << i << " ";
    }
    cout << endl;

    v1.swap(v2);
    cout << "swap()后：" << endl;
    cout << "v1:";
    for (auto i:v1) {
        cout << i << " ";
    }
    cout << endl;
    cout << "v2:";
    for (auto i:v2) {
        cout << i << " ";
    }
    cout << endl;

    // 实际用途：收缩内存空间
    vector<int> old;
    for (int i = 0; i < 100000; ++i) {
        old.push_back(i);
    }
    cout << "old's capacity:" << old.capacity() << endl;
    cout << "old's size:" << old.size() << endl;

    old.resize(10); // capacity仍然很大
    cout << "old's capacity:" << old.capacity() << endl;
    cout << "old's size:" << old.size() << endl;

    // 利用swap()来收缩容器
    vector<int>(old).swap(old);
    cout << "old's capacity:" << old.capacity() << endl;
    cout << "old's size:" << old.size() << endl;
}

// 预留空间：减少vector容器在动态扩展时的扩展次数
// reserve(int len)：预留len个元素长度，预留位置不初始化，不可访问
void test_7(){
    vector<int> v1;
    int num = 0;
    int *p = nullptr;
    for (int i = 0; i < 10000; ++i) {
        v1.push_back(i);
        if (p!= &v1[0]){
            p = &v1[0];
            ++num;
        }
    }
    cout << "v1动态扩展次数：" << num << endl;

    vector<int> v2;
    // reserve()预留空间
    v2.reserve(100000);

    num = 0;
    p = nullptr;
    for (int i = 0; i < 10000; ++i) {
        v2.push_back(i);
        if (p!= &v2[0]){
            p = &v2[0];
            ++num;
        }
    }
    cout << "v2动态扩展次数：" << num << endl;

}


int main() {
    std::cout << "Hello, World!" << std::endl;
//    test01();
//    test02();
//    test03();

    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    test_7();
    return 0;
}
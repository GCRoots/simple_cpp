/**
 * Created by 史进 on 2023/2/7.
 *
 * 关联式容器：set/multiset
 * 元素在插入时会自动排序
 * 底层结构：二叉树
 *
 * set：不允许有重复的元素
 * multiset：允许有重复的元素
 *
 * set在插入数据时，会返回插入结果，表示是否插入成功
 * multiset则不会检查数据，因此可以插入重复的元素
 *
 */
#include <iostream>
#include <string>
#include <set>

using namespace std;

void printSet(const set<int> &s){
    for (auto it:s) {
        cout << it << " ";
    }
    cout << endl;
}

void printMultiset(const multiset<int> &s){
    for (auto it:s) {
        cout << it << " ";
    }
    cout << endl;
}

// 构造和赋值
void test01(){
    // 默认构造
    set<int> s1;
    for (int i = 10; i > 0 ; --i) {
        s1.insert(i*10);
    }

    // set容器是有序的，且不能插入重复元素
    printSet(s1);   // 10 20 30 40 50 60 70 80 90 100

    // 拷贝构造
    set<int> s2(s1);
    printSet(s2);

    // 赋值
    set<int> s3;
    s3 = s1;
    printSet(s3);
}

// 大小和交换
void test02(){
    set<int> s1;
    for (int i = 10; i > 0 ; --i) {
        s1.insert(i*10);
    }
    cout << "s1: ";
    printSet(s1);

    // 大小
    cout << "s1's size is " << s1.size() << ",";
    cout << "s1 is " << (s1.empty()?"empty.":"not empty.") << endl;

    // 交换
    set<int> s2;
    s1.swap(s2);
    cout << "s1: ";
    printSet(s1);
    cout << "s1's size is " << s1.size() << ",";
    cout << "s1 is " << (s1.empty()?"empty.":"not empty.") << endl;
}

// 插入和删除
void test03(){
    set<int> s1;
    for (int i = 10; i > 0 ; --i) {
        s1.insert(i*10);
    }
    cout << "s1: ";
    printSet(s1);

    // erase()
    s1.erase(s1.begin());
    cout << "s1: ";
    printSet(s1);

    s1.erase(30);
    cout << "s1: ";
    printSet(s1);

    // 清空
//    s1.erase(s1.begin(),s1.end());
    s1.clear();
    cout << "s1: ";
    printSet(s1);
}

// 查找和统计
void test04(){
    set<int> s1;
    for (int i = 10; i > 0 ; --i) {
        s1.insert(i*10);
    }
    cout << "s1: ";
    printSet(s1);

    // 查找：find(key) 返回迭代器（若查找失败，返回set.end()）
    auto pos =  s1.find(30);
    if (pos != s1.end()){
        cout << "找到元素：" << *pos << endl;
    } else{
        cout << "未找到元素" << endl;
    }

    // 统计：count(key)
    auto num = s1.count(30);
    cout << "num = " << num << endl;
}

// set与multiset的区别
void test05(){
    // set在插入数据时，会返回插入结果，表示是否插入成功
    // 返回类型为pair，pair<iterator,bool>
    set<int> s1;
    auto ret = s1.insert(10);
    cout << "第一次插入结果\tfirst:" << *ret.first << "\tsecond:" << ret.second << endl;
    ret = s1.insert(10);
    cout << "第二次插入结果\tfirst:" << *ret.first << "\tsecond:" << ret.second << endl;

    cout << "s1: ";
    printSet(s1);

    // multiset则不会检查数据，因此可以插入重复的元素
    // 返回类型为iterator，即不进行检查
    multiset<int> s2;
    auto ret1 = s2.insert(10);
    cout << "第一次插入结果:" << *ret1 << endl;
    ret1 = s2.insert(10);
    cout << "第二次插入结果:" << *ret1 << endl;

    cout << "s2: ";
    printMultiset(s2);
}

// pair对组
void test06(){
    pair<string,int> person("Tom",10);
    cout << "name:" << person.first << "\tage:" << person.second << endl;

    pair<string,int> person2 = make_pair("Alice",23);
    cout << "name:" << person2.first << "\tage:" << person2.second << endl;
}

// set 排序：使用仿函数，改变排序规则
// 内置类型
class MyCompare{
public:
    bool operator()(int v1,int v2){
        // 降序排列
        return v1>v2;
    }
};

// 内置类型排序
void test07(){
    set<int> s1;
    for (int i = 10; i > 0 ; --i) {
        s1.insert(i*10);
    }
    cout << "s1: ";
    printSet(s1);

    set<int,MyCompare> s2;
    for (int i = 10; i > 0 ; --i) {
        s2.insert(i*10);
    }
    cout << "s2: ";
    for (auto it:s2) {
        cout << it << " ";
    }
    cout << endl;
}

// 自定义类型
class Person{
public:
    Person(string name,int age):m_name(name),m_age(age){}

    string m_name;
    int m_age;
};
class PersonCompare{
public:
    bool operator()(const Person &p1,const Person &p2){
        // 按照年龄降序排序
        return p1.m_age > p2.m_age;
    }
};

// 自定义类型排序
void test08(){
    set<Person,PersonCompare> s;

    Person p1("Alice",24);
    Person p2("Job",21);
    Person p3("Tom",23);
    Person p4("Lucy",24);
    Person p5("Aim",21);

    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    s.insert(p5);

    for(auto au : s){
        cout << "name:" << au.m_name << "\tage:" << au.m_age << endl;
    }
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
    cout << "**************" << endl;
    test08();
    return 0;
}

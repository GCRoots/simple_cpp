/**
 * Created by 史进 on 2023/1/31.
 *
 * list 链表-双向循环链表
 *
 * list迭代器：双向迭代器,不支持随机访问
 *
 * list的插入删除操作，不会影响原有的迭代器，与vector不同
 *
 */
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

void printList(const list<int> &l){
    for (auto it:l) {
        cout << it << " ";
    }
    cout << endl;
}

// 构造函数
void test01(){
    // 默认构造
    list<int> l1;
    for (int i = 0; i < 10; ++i) {
        l1.push_back(i);
    }
    printList(l1);

    // 通过迭代器区间构造
    list<int> l2(l1.begin(),l1.end());
    printList(l2);

    // n个elem元素
    list<int> l3(10,99);
    printList(l3);

    // 拷贝构造
    list<int> l4(l3);
    printList(l4);
}

// 赋值与交换
void test02(){
    list<int> l1;
    for (int i = 0; i < 10; ++i) {
        l1.push_back(i);
    }
    printList(l1);

    // operator=
    list<int> l2 = l1;
    printList(l2);

    // assign()：迭代器区间
    list<int> d3;
    d3.assign(l1.begin(),l1.end());
    printList(d3);

    // assign()：n个elem
    list<int> l4;
    l4.assign(10,99);
    printList(l4);

    // 交换 swap
    cout << "before swap:" << endl;
    cout << "l1:";
    printList(l1);
    cout << "l4:";
    printList(l4);

    l1.swap(l4);

    cout << "after swap:" << endl;
    cout << "l1:";
    printList(l1);
    cout << "l4:";
    printList(l4);
}

// 大小操作
void test03(){
    list<int> l1;
    cout << "l1 " << (l1.empty()?"is":"is not") << " empty." << endl;
    for (int i = 0; i < 10; ++i) {
        l1.push_back(i);
    }
    printList(l1);
    cout << "l1 " << (l1.empty()?"is":"is not") << " empty." << endl;

    cout << "l1's size:" << l1.size() << endl;

    l1.resize(15);
    printList(l1);
    cout << "d1's size:" << l1.size() << endl;

    l1.resize(20,100);
    printList(l1);
    cout << "d1's size:" << l1.size() << endl;
}

// 插入和删除
void test04(){
    list<int> l1;
    for (int i = 0; i < 10; ++i) {
        // 尾插法
        l1.push_back(i);
    }
    // 0 1 2 3 4 5 6 7 8 9
    printList(l1);

    for (int i = 0; i < 10; ++i) {
        // 头插法
        l1.push_front(i*i);
    }
    // 81 64 49 36 25 16 9 4 1 0 0 1 2 3 4 5 6 7 8 9
    printList(l1);

    // 尾删法
    l1.pop_back();
    // 81 64 49 36 25 16 9 4 1 0 0 1 2 3 4 5 6 7 8
    printList(l1);

    // 头删法
    l1.pop_front();
    // 64 49 36 25 16 9 4 1 0 0 1 2 3 4 5 6 7 8
    printList(l1);

    // insert()
    l1.insert(l1.begin(),1000);
    // 1000 64 49 36 25 16 9 4 1 0 0 1 2 3 4 5 6 7 8
    printList(l1);

    l1.insert(l1.begin(),2, 9999);
    // 9999 9999 1000 64 49 36 25 16 9 4 1 0 0 1 2 3 4 5 6 7 8
    printList(l1);

    list<int> l2(2,50);
    l1.insert(l1.begin(),l2.begin(),l2.end());
    // 50 50 9999 9999 1000 64 49 36 25 16 9 4 1 0 0 1 2 3 4 5 6 7 8
    printList(l1);

    // erase()
    l1.erase(l1.begin());
    // 50 9999 9999 1000 64 49 36 25 16 9 4 1 0 0 1 2 3 4 5 6 7 8
    printList(l1);

    l1.erase(++l1.begin());
    // 50 9999 1000 64 49 36 25 16 9 4 1 0 0 1 2 3 4 5 6 7 8
    printList(l1);

    l1.remove(0);
    // 50 9999 1000 64 49 36 25 16 9 4 1 1 2 3 4 5 6 7 8
    printList(l1);

    l1.clear();
    printList(l1);
}

// 数据存取
void test05(){
    list<int> l1;
    for (int i = 0; i < 10; ++i) {
        l1.push_back(i);
    }
    printList(l1);

    cout << "l1.front():" << l1.front() << endl;
    cout << "l1.back():" << l1.back() << endl;
}

// 反转和排序
void test06(){
    list<int> l1;
    for (int i = 0; i < 10; ++i) {
        l1.push_back(i);
    }
    printList(l1);

    // 反转
    l1.reverse();
    printList(l1);

    // 排序
    // 不支持随机访问迭代器的容器，不可以使用标准算法
    l1.sort();
    printList(l1);
}

// 排序案例
class Person{
public:
    Person(string name,int age,int height):m_name(name),m_age(age),m_height(height){};

    void printPerson(){
        cout << "name:" << m_name << "\tage:" << m_age << "\theight:" << m_height<< endl;
    }

    string m_name;
    int m_age;
    int m_height;
};

void printPersons(const list<Person> &p){
    for (auto it:p) {
        it.printPerson();
    }
}

bool person_sort(const Person &pl,const Person &pr){
    // 按照年龄升序
    if (pl.m_age == pr.m_age){
        // 按照身高降序
        return pl.m_height > pr.m_height;
    }
    return pl.m_age < pr.m_age ;

}

void test07(){
    list<Person> persons;
    Person p1("刘备",10,180);
    Person p2("孙权",12,179);
    Person p3("曹操",20,181);
    Person p4("孙膑",20,182);
    Person p5("马超",12,180);
    Person p6("孔融",10,185);

    persons.push_back(p1);
    persons.push_back(p2);
    persons.push_back(p3);
    persons.push_back(p4);
    persons.push_back(p5);
    persons.push_back(p6);

    cout << "排序前：" << endl;
    printPersons(persons);

    cout << "排序后：" << endl;
    persons.sort(person_sort);
    printPersons(persons);



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
    return 0;
}


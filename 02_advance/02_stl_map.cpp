/**
 * Created by 史进 on 2023/2/7.
 *
 * 关联式容器：map/multimap
 *
 * map中所有元素都是pair
 * pair中，第一个元素为key，起到索引作用；第二个元素为value
 * 所有元素都会根据元素的键值（key）自动排序
 *
 * 底层结构：二叉树
 *
 */
#include <iostream>
#include <string>
#include <map>

using namespace std;

void printMap(const map<int,string> &m){
    cout << "{";
    for (auto it = m.begin() ;  it != m.end() ; ) {
        cout << it->first << ":" << it->second;

        if (++it != m.end()){
            cout << ",";
        }
    }
    cout << "}" << endl;
}

void printMultimap(const multimap<int,string> &m){
    cout << "{";
    for (auto it = m.begin() ;  it != m.end() ; ) {
        cout << it->first << ":" << it->second;
        if (++it != m.end()){
            cout << ",";
        }
    }
    cout << "}" << endl;
}

// 构造和赋值
void test01(){
    // 默认构造
    map<int,string> m;
    m.insert(pair<int,string>(1,"A"));
    m.insert(pair<int,string>(2,"B"));
    m.insert(pair<int,string>(3,"C"));
    m.insert(pair<int,string>(4,"D"));
    m.insert(make_pair(5,"E"));
    cout << "m:";
    printMap(m);

    // 拷贝构造
    map<int,string> m2(m);
    cout << "m2:";
    printMap(m2);

    // 赋值
    map<int,string> m3;
    m3=m2;
    cout << "m3:";
    printMap(m3);
}

// 大小和交换
void test02(){
    map<int,string> m;
    m.insert(pair<int,string>(1,"A"));
    m.insert(pair<int,string>(2,"B"));
    m.insert(pair<int,string>(3,"C"));
    m.insert(pair<int,string>(4,"D"));
    m.insert(make_pair(5,"E"));
    cout << "m:";
    printMap(m);

    // 大小
    cout << "m's size is " << m.size() << ",";
    cout << "m is " << (m.empty()?"empty.":"not empty.") << endl;

    // 交换
    map<int,string> m2;
    m.swap(m2);
    cout << "m:";
    printMap(m);
    cout << "m's size is " << m.size() << ",";
    cout << "m is " << (m.empty()?"empty.":"not empty.") << endl;
}

// 插入和删除
void test03(){
    map<int,string> m;
    m.insert(pair<int,string>(1,"A"));
    m.insert(pair<int,string>(2,"B"));
    m.insert(pair<int,string>(3,"C"));
    m.insert(pair<int,string>(4,"D"));
    m.insert(make_pair(5,"E"));
    m.insert(map<int,string>::value_type (6,"F"));
    m[7]="G";   // 不推荐使用

    cout << "m:";
    printMap(m);

    // erase()
    m.erase(m.begin());
    cout << "m:";
    printMap(m);

    m.erase(5);
    cout << "m:";
    printMap(m);


    // 清空
//    m.erase(m.begin(),m.end());
    m.clear();
    cout << "m:";
    printMap(m);
}

// 查找和统计
void test04(){
    map<int,string> m;
    m.insert(pair<int,string>(1,"A"));
    m.insert(pair<int,string>(2,"B"));
    m.insert(pair<int,string>(3,"C"));
    m.insert(pair<int,string>(4,"D"));
    m.insert(make_pair(5,"E"));
    cout << "m:";
    printMap(m);

    // 查找：find(key) 返回迭代器（若查找失败，返回map.end()）
    auto pos =  m.find(3);
    if (pos != m.end()){
        cout << "找到元素：{" << pos->first << ":" << pos->second << "}" << endl;
    } else{
        cout << "未找到元素" << endl;
    }

    // 统计：count(key)
    auto num = m.count(3);
    cout << "num = " << num << endl;
}

// map排序：使用仿函数，改变排序规则
// 内置类型
class MyCompare{
public:
    bool operator()(int v1,int v2) const{
        // 降序排列
        return v1>v2;
    }
};

void test05(){
    map<int,string> m1;
    m1.insert(make_pair(1,"A"));
    m1.insert(make_pair(2,"B"));
    m1.insert(make_pair(3,"C"));
    m1.insert(make_pair(4,"D"));
    m1.insert(make_pair(5,"E"));
    cout << "m1:";
    printMap(m1);

    map<int,string,MyCompare> m2;
    m2.insert(make_pair(1,"A"));
    m2.insert(make_pair(2,"B"));
    m2.insert(make_pair(3,"C"));
    m2.insert(make_pair(4,"D"));
    m2.insert(make_pair(5,"E"));
    cout << "m2:";

    cout << "{";
    for (auto it = m2.begin() ;  it != m2.end() ; ) {
        cout << it->first << ":" << it->second;
        if (++it != m2.end()){
            cout << ",";
        }
    }
    cout << "}" << endl;
}

//
void test06(){

}

//
void test07(){

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

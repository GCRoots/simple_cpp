/**
 * Created by 史进 on 2023/2/11.
 *
 * 常用算法
 *  <algorithm>：最大，涉及到比较、交换、查找、遍历、复制、修改等
 *  <numeric>：体积很小，只包括几个在序列上进行简单数学运算的函数模版
 *  <functional>：定义了一些类模版，用来声明函数对象
 *
 * 1、常用遍历算法
 *  for_each     遍历容器
 *  transform    搬运容器到另一个容器
 *
 * 2、常用查找算法
 *  find：查找元素
 *  find_if：按条件查找元素
 *  adjacent_find：查找相邻重复元素
 *  binary_search：二分查找法，查找指定元素是否存在，要求数据有序
 *      无序序列结果未知
 *  count：统计元素个数
 *  count_if：按条件统计元素个数
 *
 * 3、常用排序算法
 *  sort：对容器内的元素排序
 *  random_shuffle：洗牌，对指定范围内元素随机调整次序
 *  merge：容器元素合并，并存储到另一个容器中，其中，合并的容器必须有序
 *  reverse：反转
 *
 * 4、常用拷贝和替换算法
 *  copy：将容器内指定范围内的元素拷贝到另一容器
 *  replace：将容器内指定范围内的元素修改为新元素
 *  replace_if：将容器内指定范围内，符合条件的元素修改为新元素
 *  swap：互换两个容器的元素
 *
 * 5、常用算术生成算法
 *  accumulate：计算容器元素累计总和
 *  fill：向容器中添加元素
 *
 * 6、常用集合算法
 *  set_intersection：交集
 *  set_union：并集
 *  set_difference：差集
 *
 */
#include <iostream>
#include <string>
#include <vector>

#include <algorithm>
#include <numeric>
#include <functional>

#include <ctime>

using namespace std;

// 1、常用遍历算法
// 普通函数
void print1(int val){
    cout << val << " ";
}

// 仿函数
class print2{
public:
    void operator()(int val){
        cout << val << " ";
    }
};

class Transform{
public:
    int operator()(int val){
        return val*val;
    }
};

void test01(){
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

    // for_each
    for_each(v.begin(),v.end(), print1);
    cout << endl;

    for_each(v.begin(),v.end(), print2());
    cout << endl;

    // transform
    vector<int> v_target;
    // 目标容器需要提前开辟空间
    v_target.resize(v.size());
    transform(v.begin(),v.end(),v_target.begin(), Transform());
    for_each(v_target.begin(),v_target.end(), print1);
    cout << endl;


}

// 2、常用查找算法
class Person{
public:
    Person(string name,int age):m_name(name),m_age(age){}

    bool operator==(const Person& p){
        return this->m_name==p.m_name && this->m_age==p.m_age;
    }

    string m_name;
    int m_age;
};

class GraterFive{
public:
    bool operator()(int val){
        return val>5;
    }
};

class AgeGrater20{
public:
    bool operator()(Person& p){
        return p.m_age>20;
    }
};

void test02(){
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    v.push_back(9);

    // 内置数据类型
    // find
    auto it = find(v.begin(),v.end(),5);
    cout << "find():" << ((it!=v.end())?"已找到"+to_string(*it):"未找到") << endl;

    // find_if
    it = find_if(v.begin(),v.end(),GraterFive());
    cout << "find_if():" << ((it!=v.end()) ? "已找到"+to_string(*it):"未找到") << endl;

    // adjacent_find
    it = adjacent_find(v.begin(),v.end());
    cout << "adjacent_find():" << ((it!=v.end()) ? "已找到"+to_string(*it):"未找到") << endl;

    // binary_search
    bool se = binary_search(v.begin(),v.end(),5);
    cout << "binary_search():" << (se ? "已找到":"未找到") << endl;

    // count
    int num = count(v.begin(),v.end(),9);
    cout << "count() 元素 9 的个数为：" << num << endl;

    // count_if
    num = count_if(v.begin(),v.end(),GraterFive());
    cout << "count_if() 元素大于5的个数为：" << num << endl;


    // 自定义数据类型
    vector<Person> vp;

    Person p1("A",10);
    Person p2("B",20);
    Person p3("C",30);
    Person p4("D",40);
    Person p5("E",50);

    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);
    vp.push_back(p4);
    vp.push_back(p5);

    // find
    auto it_p = find(vp.begin(),vp.end(),Person("A",10));
    cout << "find():" << ((it_p!=vp.end())?"已找到":"未找到") << endl;

    // find_if
    it_p = find_if(vp.begin(),vp.end(),AgeGrater20());
    cout << "find():" << ((it_p!=vp.end())?"已找到":"未找到") << endl;

    // count
    num = count(vp.begin(),vp.end(),Person("A",10));
    cout << "count() 元素 Person(\"A\",10) 的个数为：" << num << endl;

    // count_if
    num = count_if(vp.begin(),vp.end(),AgeGrater20());
    cout << "count_if() 元素中，年龄大于20的个数为：" << num << endl;

}

// 3、常用排序算法
void test03(){
    vector<int> v;
    v.push_back(10);
    v.push_back(90);
    v.push_back(70);
    v.push_back(30);
    v.push_back(50);
    for_each(v.begin(),v.end(), print1);
    cout << endl;


    // sort 升序
    sort(v.begin(),v.end());
    for_each(v.begin(),v.end(), print1);
    cout << endl;

    // sort 降序
    sort(v.begin(),v.end(),greater<int>());
    for_each(v.begin(),v.end(), print1);
    cout << endl;

    // random_shuffle
//    srand((unsigned int)time(NULL));
    random_shuffle(v.begin(),v.end());
    for_each(v.begin(),v.end(), print1);
    cout << endl;

    // merge
    sort(v.begin(),v.end());
    for_each(v.begin(),v.end(), print1);
    cout << endl;

    vector<int> v1;
    v1.push_back(20);
    v1.push_back(100);
    v1.push_back(80);
    v1.push_back(40);
    v1.push_back(60);
    sort(v1.begin(),v1.end());
    for_each(v1.begin(),v1.end(), print1);
    cout << endl;

    vector<int> target;
    target.resize(v.size()+v1.size());
    merge(v.begin(),v.end(),v1.begin(),v1.end(),target.begin());
    for_each(target.begin(),target.end(), print1);
    cout << endl;

    // reverse
    reverse(target.begin(),target.end());
    for_each(target.begin(),target.end(), print1);
    cout << endl;
}

// 4、常用拷贝和替换算法
class ReplaceGreater30{
public:
    bool operator()(int val){
        return val>30;
    }
};

void test04(){
    vector<int> v;
    v.push_back(10);
    v.push_back(70);
    v.push_back(90);
    v.push_back(30);
    v.push_back(50);
    for_each(v.begin(),v.end(), print1);
    cout << endl;

    // copy
    vector<int> v1;
    v1.resize(v.size());
    copy(v.begin(),v.end(),v1.begin());
    for_each(v1.begin(),v1.end(), print1);
    cout << endl;

    // replace
    replace(v.begin(),v.end(),30,300);
    for_each(v.begin(),v.end(), print1);
    cout << endl;

    // replace_if
    replace_if(v.begin(),v.end(),ReplaceGreater30(),30000);
    for_each(v.begin(),v.end(), print1);
    cout << endl;

    // swap
    swap(v,v1);
    for_each(v.begin(),v.end(), print1);
    cout << endl;
    for_each(v1.begin(),v1.end(), print1);
    cout << endl;

    swap(v,v1);

    for_each(v.begin(),v.end(), print1);
    cout << endl;
    for_each(v1.begin(),v1.end(), print1);
    cout << endl;
}

// 5、常用算术生成算法
void test05(){
    vector<int> v;
    v.push_back(10);
    v.push_back(90);
    v.push_back(70);
    v.push_back(30);
    v.push_back(50);
    for_each(v.begin(),v.end(), print1);
    cout << endl;

    // accumulate
    int total = accumulate(v.begin(),v.end(),0);
    cout << "accumulate:" << total << endl;

    // fill
    vector<int> v1;
    v1.resize(10);
    fill(v1.begin(),v1.end(),99);
    for_each(v1.begin(),v1.end(), print1);
    cout << endl;

    fill(v.begin(),v.end(),99);
    for_each(v.begin(),v.end(), print1);
    cout << endl;
}

// 6、常用集合算法
void test06(){
    vector<int> v;
    v.push_back(10);
    v.push_back(90);
    v.push_back(70);
    v.push_back(30);
    v.push_back(50);
    cout << "v:\t";
    for_each(v.begin(),v.end(), print1);
    cout << endl;

    vector<int> v1;
    v1.push_back(10);
    v1.push_back(90);
    v1.push_back(70);
    v1.push_back(40);
    v1.push_back(60);
    cout << "v1:\t";
    for_each(v1.begin(),v1.end(), print1);
    cout << endl;

    // set_intersection：交集
    vector<int> in;
    in.resize(min(v.size(),v1.size()));
    auto inEND = set_intersection(v.begin(),v.end(),v1.begin(),v1.end(),in.begin());
    cout << "交集:";
    for_each(in.begin(),inEND, print1);
    cout << endl;

    // set_union：并集
    vector<int> un;
    un.resize(v.size()+v1.size());
    auto unEND = set_union(v.begin(),v.end(),v1.begin(),v1.end(),un.begin());
    cout << "并集:";
    for_each(un.begin(),unEND, print1);
    cout << endl;

    // set_difference：差集
    vector<int> di;
    di.resize(max(v.size(),v1.size()));
    auto diEND = set_difference(v.begin(),v.end(),v1.begin(),v1.end(),di.begin());
    cout << "v和v1的差集:";
    for_each(di.begin(),diEND, print1);
    cout << endl;
    diEND = set_difference(v1.begin(),v1.end(),v.begin(),v.end(),di.begin());
    cout << "v1和v的差集:";
    for_each(di.begin(),diEND, print1);
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

    return 0;
}

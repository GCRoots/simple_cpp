/**
 * Created by 史进 on 2023/1/28.
 *
 * string 与 char* 的区别：
 *  char* 是一个指针
 *  string 是一个类，类内封装了 char* ，用来管理这个字符串
 *
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// string的构造函数
void test01(){
    // 默认构造：空字符串
    string s1;
    cout << "s1=" << s1 << endl;

    // 使用char*字符串构造
    const char * str = "hello world!";
    string s2(str);
    cout << "s2=" << s2 << endl;

    // 拷贝构造
    string s3(s2);
    cout << "s3=" << s3 << endl;

    // 使用n个字符构造
    string s4(10,'a');
    cout << "s4=" << s4 << endl;
}

// string的赋值
void test02(){
    string s1;
    s1 = "hello world";
    cout << "s1:" << s1 << endl;

    string s2;
    s2 = s1;
    cout << "s2:" << s2 << endl;

    string s3;
    s3 = 'a';
    cout << "s3:" << s3 << endl;

    string s4;
    s4.assign("hello Assign");
    cout << "s4:" << s4 << endl;

    string s5;
    s5.assign("hello Assign",5);
    cout << "s5:" << s5 << endl;

    string s6;
    s6.assign(s5);
    cout << "s6:" << s6 << endl;

    string s7;
    s7.assign(10,'s');
    cout << "s7:" << s7 << endl;
}

// string的拼接
void test03(){
    string s1 = "hello ";
    cout << "s1:" << s1 << endl;

    s1 += "world";
    cout << "s1:" << s1 << endl;

    s1 += '!';
    cout << "s1:" << s1 << endl;

    string s2 = "C++";
    s1 += s2;
    cout << "s1:" << s1 << endl;

    string s3 = "I";
    s3.append(" love");
    cout << "s3:" << s3 << endl;

    s3.append(" game and cook",5);
    cout << "s3:" << s3 << endl;

    string s4 = " LOL DNF";
    s3.append(s4);
    cout << "s3:" << s3 << endl;

    s3.append(s4,4,4);
    cout << "s3:" << s3 << endl;
}

// string的查找和替换
void test04(){
    // 查找 find() rfind()
    string s1 = "abcdebcfg";

    // find() 从左往右查询：2
    int pos = s1.find("bc");
    cout << "The position that 'bc' in " << s1 << "is " << pos+1 << endl;

    // find() 从右往左查询：6
    pos = s1.rfind("bc");
    cout << "The position that 'bc' in " << s1 << "is " << pos+1 << endl;

    // 替换 replace()
    s1.replace(1,3," @@@@@ ");
    cout << "s1 = " << s1 << endl;
}

// string的比较
void test05(){
    // 字符串比较，是按照ASCII码进行比较
    string s1 = "hello";
    string s2 = "hello";

    if (s1.compare(s2) == 0){
        cout << s1 << " == " << s2 << endl;
    } else if (s1.compare(s2) > 0){
        cout << s1 << " > " << s2 << endl;
    } else{
        cout << s1 << " < " << s2 << endl;
    }
}

// string的字符存取
void test06(){
    string s1 = "hello world";
    cout << "s1 = " << s1 << endl;

    // 通过 [] 访问字符
    for (int i = 0; i < s1.size(); ++i) {
        cout << s1[i] << " ";
        s1[i] = s1[i]+1;
    }
    cout << endl;
    cout << "s1 = " << s1 << endl;

    // 通过 at() 访问字符
    for (int i = 0; i < s1.size(); ++i) {
        cout << s1.at(i) << " ";
        s1.at(i) = s1.at(i)-1;
    }
    cout << endl;
    cout << "s1 = " << s1 << endl;
}

// string的插入和删除
void test07(){
    string str = "hello";
    cout << "str = " << str << endl;

    str.insert(0,"$_insert_$");
    cout << "str = " << str << endl;

    str.erase(0,10);
    cout << "str = " << str << endl;
}

// string的子串
void test08(){
    string str = "hello world";
    cout << "str = " << str << endl;

    string sub = str.substr(1,3);
    cout << "sub = " << sub << endl;

    int pos = str.find(" ");
    sub = str.substr(0,pos);
    cout << "sub = " << sub << endl;
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
本文是笔者在C++学习过程中，对类和对象的总结记录，如有不对以及不足的地方，欢迎大家指正！

文中代码学于黑马。

****

# 1. 成员变量与成员函数分开存储

&emsp;&emsp;在C++当中，类的成员变量和成员函数是分开存储的，其中，只有非静态的成员变量才属于类的对象（实例）。

&emsp;&emsp;**对象内存占用**分析：
1. **空对象占用内存为一字节**
   因为C++要求每个类的实例都必须在内存中有唯一的地址，所以C++会给每个空对象分配一字节的空间，用来标识该对象在内存中的地址。
2. **非空对象按其内部成员来划分内存空间**
    - **非静态成员变量**
      非静态成员变量，是属于类的对象的，即保存在对象的内部，因此该对象占用的内存大小会随着非静态成员变量的增加而增加。
    - **静态成员变量**
      静态成员变量，不属于类的对象，保存在对象的外面，因此它占用内存的大小与类对象无关。
    - **成员函数**
      静态成员函数，或者非静态成员函数，都保存在对象的外面，所以它占用内存的大小与类对象无关。

```cpp
#include <iostream>
#include <string>
using namespace std;

// 1. 成员变量与成员函数分开存储
class Class_empty{};

class Class_not_static{
    int A;                  // 非静态成员变量：属于对象
};

class Class_all{
    int A;                  // 非静态成员变量：属于对象
    static int B;           // 静态成员变量：不属于对象
    void func(){}           // 非静态成员函数：不属于对象
    static void func2(){}   // 静态成员函数：不属于对象
};
int Class_all::B = 10;

void test_01(){
    Class_empty empty;
    // 空对象占用内存空间大小：1
    cout<< "size of an empty object:" << sizeof (empty) << endl;

    Class_not_static notStatic;
    // 非静态成员变量属于对象,该对象占用的内存大小会随着非静态成员变量的增加而增加
    cout<< "size of a.html not empty object:" << sizeof (notStatic) << endl;

    Class_all all;
    // 成员函数和静态成员变量不属于对象，占用内存的大小与类对象无关
    cout<< "size of a.html not empty object:" << sizeof (all) << endl;
}


int main() {
    test_01();
    return 0;
}
```

运行结果：
![1. 成员变量与成员函数分开存储](https://img-blog.csdnimg.cn/71890f2559f9462c9f091f21cf3594b4.png)

****

# 2. this指针

&emsp;&emsp;刚才我们讨论了类对象的内存占用问题，其实在C++当中，成员函数是存放在公共的代码段当中的，每一个非静态函数只会产生一个函数实例，也就是说，**同一个类的多个对象其实是共用一个函数实例的**。

&emsp;&emsp;所以我们应该如何区分是哪一个对象调用了这一个公用的函数实例呢？C++当中的**特殊对象指针**——**this指针**，完美解决了这一问题。

&emsp;&emsp;this指针，**指向被调用的成员函数所属的对象**，即在函数运行时调用该函数的对象，在函数中对成员变量的操作，都是通过这一指针来实现的。

&emsp;&emsp;this指针是**隐含于每一个非静态函数内**的，不需要定义，可直接使用。

&emsp;&emsp;那么它隐藏在哪里呢？其实this指针就是成员函数第一个隐含的形参，在对象调用成员函数时，会自动将对象的地址作为实参传入。

&emsp;&emsp;this指针的本质其实是一个**指针常量**，即一个指针指向不可更改的指针。

&emsp;&emsp;用途：

1. **解决名称冲突**：在成员函数的形参和成员变量同名时，可以使用this指针加以区分。
2.  在类的非静态成员函数中**返回对象本身**： **return \*this;**
    ps:this为指向本体对象的指针，***this即为本体对象**。

```cpp
#include <iostream>
#include <string>
using namespace std;

// 2. this指针
class Person{
public:
    // a.html. 解决名称冲突
    Person(int age){
        this->age=age;
    }

    // b. 返回对象本身： return *this;
    Person personAddAge(Person &p){
        this->age += p.age;
        return *this;
    }

    int age;
};

void test_02(){
    Person p(18);
    cout<< "p's age is:" << p.age <<endl;

    Person p2(10);
    // 链式编程思想
    p.personAddAge(p2).personAddAge(p2).personAddAge(p2).personAddAge(p2);
    cout<< "p's age is:" << p.age <<endl;
}

int main() {
	test_02();
    return 0;
}

```

运行结果：

![2. this指针](https://img-blog.csdnimg.cn/bfcdb73127524b28966b2f744cfdc1b7.png)


****

# 3. 空指针调用成员函数

&emsp;&emsp;在成员函数中访问成员变量时，其实会隐含一个this指针，即，**age == this.age**。

&emsp;&emsp;所以，当我们的对象为NULL，即this指针为空指针时，访问成员变量就会报空指针异常。这个问题也很好解决，加一个空指针报错即可：

```cpp
if(this == NULL) return;
```

&emsp;&emsp;那么，空指针是否可以用来调用成员函数而不报错呢？这其实和成员函数中**是否访问了成员变量**有关：若是成员函数中未访问成员变量，那么用空指针调用该成员函数是可行的，并不会报错，可以正常执行；反之则不行。

```cpp
#include <iostream>
#include <string>
using namespace std;

// 3. 空指针访问成员函数
class Person_1{
public:
    void showClassName(){
        cout<<"This is a.html Person_1 class."<<endl;
    }

    void showAge(){
        if (this == NULL){
            cout<<"This object is NULL"<<endl;
            return;
        }
        cout<<"age is:"<<age<<endl;
    }

    int age;
};

void test_03(){
    Person_1 *p = NULL;
    p->showClassName();
    p->showAge();
}

int main() {
	test_03();
    return 0;
}
```

运行结果：

![3. 空指针调用成员函数
](https://img-blog.csdnimg.cn/8e29857f722a4246ac63dc31c4772373.png)



****

# 4. const 修饰成员函数

- **常函数**
  在成员函数后面加 const 关键字修饰，那么该成员函数就变成了一个常函数。
  实质上，**const修饰的是this指针**，让指针指向的值也不可更改。
  在常函数中，**不能对成员变量进行修改**，除非成员变量在声明时，用 **mutable** 关键字修饰。
- **常对象**
  在声明对象前加 const 关键字修饰，那么该对象就成为了一个常对象。
  **常对象的成员变量是不能修改的**，除非成员变量在声明时，用 **mutable** 关键字修饰。
  **常对象只能调用常函数**。

```cpp
#include <iostream>
#include <string>
using namespace std;

// 4. const 修饰成员函数
class Person_const{
public:
    // 常函数
    void showPerson() const{
        // 常函数中不能对成员变量进行修改，除非成员变量在声明时，用 mutable 关键字修饰。
        // A=100；
        B=200;
    }

    void func(){}

    int A=10;
    mutable int B=20;
};

void test_04(){
    // 常对象
    const Person_const p;
    // 常对象的成员变量是不能修改的，除非成员变量在声明时，用 **mutable** 关键字修饰。
    // p.A=1000;
    p.B=2000;

    // 常对象只能调用常函数。
    // p.func();
    p.showPerson();
}
```




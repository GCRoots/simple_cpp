/**
 * Created by 史进 on 2023/1/25.
 */
#ifndef SIMPLE_CPP_01_TEMPLATE_ARRAY_CPP_H
#define SIMPLE_CPP_01_TEMPLATE_ARRAY_CPP_H
#pragma once            // 防止头文件重复包含
#include <iostream>
#include <string>

using namespace std;

template<class T>
class MyArray{
public:

    // 有参构造函数
    MyArray(int capacity){
        cout << "有参构造函数" <<endl;
        this->m_capacity = capacity;
        this->m_size = 0;
        this->p_address = new T[this->m_capacity];
    }

    // 析构函数
    ~MyArray(){
        cout << "析构函数" <<endl;
        if (this->p_address != nullptr){
            delete [] this->p_address;
            this->p_address = nullptr;
        }
    }

    // 拷贝构造函数
    MyArray(const MyArray& arr){
        cout << "拷贝构造函数" <<endl;
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;

        this->p_address = new T[arr.m_capacity];
        for (int i = 0; i < this->m_size; ++i) {
            this->p_address[i] = arr.p_address[i];
        }
    }

    // 运算符重载：operator= 防止浅拷贝问题
    MyArray& operator=(const MyArray& arr){
        cout << "运算符重载：operator=" <<endl;
        // 先判断原先堆区是否有数据，如果有，释放
        if (this->p_address != nullptr){
            delete [] this->p_address;
            this->p_address = nullptr;
            this->m_capacity = 0;
            this->m_size = 0;
        }

        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;

        this->p_address = new T[arr.m_capacity];
        for (int i = 0; i < this->m_size; ++i) {
            this->p_address[i] = arr.p_address[i];
        }

        return *this;
    }

    // 尾插法
    void push_back(const T & val){
        // 判断数组是否有空余
        if (this->m_capacity == this->m_size){
            this->m_capacity *= 2;

            // 重新分配数组空间
            T* temp = this->p_address;
            this->p_address = new T[this->m_capacity];
            for (int i = 0; i < this->m_size; ++i) {
                this->p_address[i] = temp[i];
            }

            // 释放原数组空间
            delete [] temp;
        }

        // 插入数据
        this->p_address[this->m_size++] = val;
    }

    // 尾删法（逻辑上）
    void pop_back(){
        if (this->m_size == 0){
            return;
        }
        this->m_size--;
    }

    // 下标操作
    T& operator[](int index){
        return this->p_address[index];
    }

    // 数组容量查询
    int getCapacity(){
        return this->m_capacity;
    }

    // 数组大小查询
    int getSize(){
        return this->m_size;
    }

    // 内置数据类型可用
    void toString(){
        cout << "MyArray:[";
        for (int i = 0; i < this->m_size; ++i) {
            cout << this->p_address[i] << " ";
        }
        cout << "]" << endl;
    }


private:
    T* p_address;   // 指针指向堆区开辟的真实数组
    int m_capacity{}; // 数组容量
    int m_size{};     // 数组中元素个数


};



#endif //SIMPLE_CPP_01_TEMPLATE_ARRAY_CPP_H

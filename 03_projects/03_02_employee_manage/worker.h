/**
 * Created by 史进 on 2023/1/3.
 */
#ifndef SIMPLE_CPP_WOKER_H
#define SIMPLE_CPP_WOKER_H

#pragma once            // 防止头文件重复包含
#include <iostream>
#include <string>

using namespace std;

// 职工抽象类
class Worker{
public:
    // 显示个人信息
    virtual void showInfo()=0;

    // 获取岗位名称
    virtual string getDeptName()=0;

    // 职工编号
    int m_ID;

    // 职工姓名
    string m_name;

    //部门编号
    int m_DeptID;


};



#endif //SIMPLE_CPP_WOKER_H

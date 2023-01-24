/**
 * Created by 史进 on 2023/1/3.
 */
#ifndef SIMPLE_CPP_BOSS_H
#define SIMPLE_CPP_BOSS_H

#pragma once            // 防止头文件重复包含
#include <iostream>
#include <string>
#include "worker.h"

using namespace std;

class Boss:public Worker{
public:
    // 构造函数
    Boss();
    Boss(int ID,string name,int deptID);

    // 显示个人信息
    virtual void showInfo();

    // 获取岗位名称
    virtual string getDeptName();
};

#endif //SIMPLE_CPP_BOSS_H

/**
 * Created by 史进 on 2022/11/13.
 */
#ifndef SIMPLE_CPP_WORKERMANAGER_H
#define SIMPLE_CPP_WORKERMANAGER_H

#pragma once            // 防止头文件重复包含
#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

//#include "employee.cpp"
//#include "manager.cpp"
//#include "boss.cpp"

using namespace std;

#define FILENAME "/Users/shijin/codes/CLionProjects/simple_cpp/03_projects/03_02_employee_manage/workers_file.txt"

class WorkerManager {
public:
    WorkerManager();            // 构造函数
    static void ShowMenu();     // 菜单展示
    static void ExitSystem();   // 退出系统
    void AddWorker();           // 添加职工
    void Save();                // 保存文件
    int get_WorkersNum();       // 获取文件中的成员个数
    void init_workers();        // 初始化职工
    void ShowWorkers();         // 查看职工信息
    void DelWorker();           // 删除职工信息
    int IsExist(int id);        // 查找职工下标
    void UpdateWorker();        // 修改职工信息
    void FindWorker();          // 查找职工信息
    void SortWorkers();         // 按照编号排序
    void ClearAll();            // 清空文件
    ~WorkerManager();           // 析构函数

private:
    // 职工人数
    int workerNum;
    // 职工数组指针
    Worker **workers;
    // 标志文件是否为空
    bool fileIsEmpty;
};


#endif //SIMPLE_CPP_WORKERMANAGER_H

/**
 * Created by 史进 on 2022/11/13.
 */
#include <iostream>
#include <string>
#include "workerManager.h"
//#include "workerManager.cpp"
#include <unistd.h>
using namespace std;

int main() {
    // 实例化管理者 workerManager 对象
    WorkerManager wm;
    // 流程控制变量
    int choice=0;

    while (true){
        // 菜单展示
        wm.ShowMenu();

        cout << "请输入您的选择：";
        cin >> choice;

        switch (choice) {
            case 0:     // 退出管理系统
                wm.ExitSystem();
                break;
            case 1:     // 增加职工信息
                wm.AddWorker();
                break;
            case 2:     // 显示职工信息
                wm.ShowWorkers();
                break;
            case 3:     // 删除离职职工
                wm.DelWorker();
                break;
            case 4:     // 修改职工信息
                wm.UpdateWorker();
                break;
            case 5:     // 查找职工信息
                wm.FindWorker();
                break;
            case 6:     // 按照编号排序
                wm.SortWorkers();
                break;
            case 7:     // 清空所有文档
                wm.ClearAll();
                break;
            default:
                system("clear");
                break;
        }
    }
    return 0;
}


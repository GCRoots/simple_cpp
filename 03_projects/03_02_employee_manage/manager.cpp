/**
 * Created by 史进 on 2023/1/3.
 */
#include "manager.h"

Manager::Manager()=default;

Manager::Manager(int ID, string name, int deptID) {
    this->m_ID=ID;
    this->m_name=name;
    this->m_DeptID=deptID;
}

void Manager::showInfo() {
    cout << "职工编号：" << this->m_ID
         << "\t\t职工姓名：" << this->m_name
         << "\t\t岗位：" << this->getDeptName()
         << "\t\t岗位职责：完成老板下发任务，下发任务给员工" << endl;
}

string Manager::getDeptName() {
    return string("经理 Manager");
}
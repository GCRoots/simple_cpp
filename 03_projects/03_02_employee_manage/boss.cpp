/**
 * Created by 史进 on 2023/1/3.
 */
#include "boss.h"

Boss::Boss()=default;

Boss::Boss(int ID, string name, int deptID) {
    this->m_ID=ID;
    this->m_name=name;
    this->m_DeptID=deptID;
}

void Boss::showInfo() {
    cout << "职工编号：" << this->m_ID
         << "\t\t职工姓名：" << this->m_name
         << "\t\t岗位：" << this->getDeptName()
         << "\t\t\t岗位职责：下发任务给经理" << endl;
}

string Boss::getDeptName() {
    return string("老板 Boss");
}
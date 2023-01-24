/**
 * Created by 史进 on 2023/1/3.
 */
#include "employee.h"

Employee::Employee()=default;

Employee::Employee(int ID, string name, int deptID) {
    this->m_ID=ID;
    this->m_name=name;
    this->m_DeptID=deptID;
}

void Employee::showInfo() {
    cout << "职工编号：" << this->m_ID
         << "\t\t职工姓名：" << this->m_name
         << "\t\t岗位：" << this->getDeptName()
         << "\t\t岗位职责：完成经理下发任务" << endl;
}

string Employee::getDeptName() {
    return string("职员 Employee");
}




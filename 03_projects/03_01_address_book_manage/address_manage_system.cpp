//
// Created by ubuntu on 2022/9/6.
//

#include <iostream>
#include <string>

using namespace std;

//通讯录最大保存的联系人数量
#define MAX 1000

//联系人结构体
typedef struct{
    string name;    //姓名
    int sex;        //性别 男 1 女 2
    int age;        //年龄
    string phone;   //电话
    string addr;    //地址
}Person;

//通讯录结构体
typedef struct{
    Person persons[MAX];//联系人数组
    int p_size;    //当前联系人数量
}AddressBooks;

//菜单界面
void showMenu();
//1. 添加联系人
void addPerson(AddressBooks *ads);
// 2. 显示联系人
void showPerson(AddressBooks *ads);
// 3. 删除联系人
// 3.1 检测联系人是否存在
int isExist(AddressBooks *ads,string name);
// 3.2 删除指定联系人
void deletePerson(AddressBooks *ads);
// 4. 查找联系人
void findPerson(AddressBooks *ads);
// 5. 修改联系人
void modifyPerson(AddressBooks *ads);
// 6. 清空联系人
void clearPerson(AddressBooks *ads);

int main() {

    cout << "Hello, World!" << endl;

    //初始化通讯录
    AddressBooks ads;
    ads.p_size=0;

    int select=0;
    while (true){
        showMenu();
        cout<<"请选择您要使用的功能：";
        cin>>select;
        switch (select) {
            case 1: // 1. 添加联系人
                addPerson(&ads);
                break;
            case 2: // 2. 显示联系人
                showPerson(&ads);
                break;
            case 3: // 3. 删除联系人
                deletePerson(&ads);
                break;
            case 4: // 4. 查找联系人
                findPerson(&ads);
                break;
            case 5: // 5. 修改联系人
                modifyPerson(&ads);
                break;
            case 6: // 6. 清空联系人
                break;
            case 0: // 0. 退出通讯录
                cout<<"欢迎下次使用"<<endl;
                return 0;
            default:
                cout<<"输入有误，请重新选择您要使用的功能!"<<endl;
                break;
        }

    }

}

//菜单界面
void showMenu(){
    cout<<"********"<<"***********"<<"********"<<endl;
    cout<<"*****"<<"\t1. 添加联系人\t"<<"  *****"<<endl;
    cout<<"*****"<<"\t2. 显示联系人\t"<<"  *****"<<endl;
    cout<<"*****"<<"\t3. 删除联系人\t"<<"  *****"<<endl;
    cout<<"*****"<<"\t4. 查找联系人\t"<<"  *****"<<endl;
    cout<<"*****"<<"\t5. 修改联系人\t"<<"  *****"<<endl;
    cout<<"*****"<<"\t6. 清空联系人\t"<<"  *****"<<endl;
    cout<<"*****"<<"\t0. 退出通讯录\t"<<"  *****"<<endl;
    cout<<"********"<<"***********"<<"********\n\n"<<endl;
}

//1. 添加联系人
void addPerson(AddressBooks *ads){
    if (ads->p_size>=MAX){  //通讯录已满
        cout<<"通讯录已满，无法继续添加！"<<endl;
        return;
    } else{                 //通讯录未满
        //添加联系人
        //姓名
        string name;
        cout<<"请输入联系人的姓名："<<endl;
        cin>>name;
        ads->persons[ads->p_size].name=name;

        //性别 男 1 女 2
        int sex=0;
        cout<<"请输入联系人的性别："<<endl;
        cout<<"1 --- 男"<<endl;
        cout<<"2 --- 女"<<endl;
        while (true){
            cin>>sex;
            //如果输入为0或1，正确，继续执行
            //否则，重新输入
            if (sex==1||sex==2){
                ads->persons[ads->p_size].sex=sex;
                break;
            } else{
                cout<<"输入有误，请重新输入"<<endl;
            }
        }

        //年龄
        int age=0;
        cout<<"请输入联系人的年龄："<<endl;
        while (true){
            cin>>age;
            //如果输入为0至120之间的数，正确，继续执行
            //否则，重新输入
            if (age>0 && age<=120){
                ads->persons[ads->p_size].age=age;
                break;
            } else{
                cout<<"输入有误，请重新输入"<<endl;
            }
        }

        //电话
        string phone;
        cout<<"请输入联系人的电话："<<endl;
        cin>>phone;
        ads->persons[ads->p_size].phone=phone;

        //地址
        string addr;
        cout<<"请输入联系人的地址："<<endl;
        cin>>addr;
        ads->persons[ads->p_size].addr=addr;

        //更新通信录人数
        ads->p_size++;

        cout<<"添加成功"<<endl<<endl;

        //按任意键继续
        //清屏

    }
}

// 2. 显示联系人
void showPerson(AddressBooks *ads){
    //判断通讯录中的人数，如果为0，通讯录为空
    //否则，显示通讯录中的联系人
    if (ads->p_size==0){
        cout<<"通讯录为空"<<endl;
    } else{
        for (int i = 0; i < ads->p_size; i++) {
            cout<<"姓名:"<<ads->persons[i].name<<"\t";
            cout<<"性别:"<<((ads->persons[i].sex==1)?"男":"女")<<"\t";
            cout<<"年龄:"<<ads->persons[i].age<<"\t";
            cout<<"电话:"<<ads->persons[i].phone<<"\t";
            cout<<"地址:"<<ads->persons[i].addr<<endl;
        }
        cout<<"\n\n";
    }
    //按任意键继续
    //清屏

}

// 3. 删除联系人
// 3.1 检测联系人是否存在
int isExist(AddressBooks *ads,string name){
    if (ads->p_size==0)
        return -1;

    for (int i = 0; i < ads->p_size; i++) {
        if (ads->persons[i].name==name){
            return i;
        }
    }

    return -1;  //不存在，返回-1
}

// 3.2 删除指定联系人
void deletePerson(AddressBooks *ads){
    cout<<"请输入要删除的联系人姓名："<<endl;

    string name;
    cin>>name;

    int ret = isExist(ads,name);

    if (ret==-1){
        cout<<"查无此人"<<"\n\n"<<endl;
    } else{
        for (int i = ret; i < ads->p_size; i++) {
            ads->persons[i]=ads->persons[i+1];
        }

        ads->p_size--;

        cout<<"删除成功"<<"\n\n"<<endl;
    }

    //按任意键继续
    //清屏

}

// 4. 查找联系人
void findPerson(AddressBooks *ads) {
    cout << "请输入要查找的联系人姓名：" << endl;

    string name;
    cin >> name;

    int ret = isExist(ads,name);

    if (ret==-1){
        cout<<"查无此人"<<"\n\n"<<endl;
    } else{
        cout<<"姓名:"<<ads->persons[ret].name<<"\t";
        cout<<"性别:"<<((ads->persons[ret].sex==1)?"男":"女")<<"\t";
        cout<<"年龄:"<<ads->persons[ret].age<<"\t";
        cout<<"电话:"<<ads->persons[ret].phone<<"\t";
        cout<<"地址:"<<ads->persons[ret].addr<<"\n\n"<<endl;
    }

    //按任意键继续
    //清屏

}

// 5. 修改联系人
void modifyPerson(AddressBooks *ads){
    cout << "请输入要修改的联系人姓名：" << endl;

    string name;
    cin >> name;

    int ret = isExist(ads,name);

    if (ret==-1){
        cout<<"查无此人"<<"\n\n"<<endl;
    } else{
        //修改联系人
        //姓名
        cout<<"请输入联系人的姓名："<<endl;
        cin>>name;
        ads->persons[ret].name=name;

        //性别 男 1 女 2
        int sex=0;
        cout<<"请输入联系人的性别："<<endl;
        cout<<"1 --- 男"<<endl;
        cout<<"2 --- 女"<<endl;
        while (true){
            cin>>sex;
            //如果输入为0或1，正确，继续执行
            //否则，重新输入
            if (sex==1||sex==2){
                ads->persons[ret].sex=sex;
                break;
            } else{
                cout<<"输入有误，请重新输入"<<endl;
            }
        }

        //年龄
        int age=0;
        cout<<"请输入联系人的年龄："<<endl;
        while (true){
            cin>>age;
            //如果输入为0至120之间的数，正确，继续执行
            //否则，重新输入
            if (age>0 && age<=120){
                ads->persons[ret].age=age;
                break;
            } else{
                cout<<"输入有误，请重新输入"<<endl;
            }
        }

        //电话
        string phone;
        cout<<"请输入联系人的电话："<<endl;
        cin>>phone;
        ads->persons[ret].phone=phone;

        //地址
        string addr;
        cout<<"请输入联系人的地址："<<endl;
        cin>>addr;
        ads->persons[ret].addr=addr;

        cout<<"添加成功"<<endl<<endl;

    }

    //按任意键继续
    //清屏

}

// 6. 清空联系人
void clearPerson(AddressBooks *ads){
    //逻辑清空
    if (ads->p_size==0) return;

    ads->p_size=0;

    cout<<"通讯录已清空"<<"\n\n"<<endl;

    //按任意键继续
    //清屏
}
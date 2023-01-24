/**
 * Created by 史进 on 2022/11/13.
 */
#include "workerManager.h"

// 构造函数
WorkerManager::WorkerManager():workerNum(0),workers(nullptr),fileIsEmpty(false) {
    cout<<"初始化"<<endl;

    ifstream ifs(FILENAME,ios::in);

    // 1、文件不存在
    if (!ifs.is_open()){
        cout << "文件不存在" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        cout << this->workerNum << " " << this->workers << " " <<this->fileIsEmpty << endl;
        return;
    }

    // 2、文件存在，且为空
    char ch;
    ifs >> ch;
    if (ifs.eof()){
        cout << "文件存在，且为空" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        cout << this->workerNum << " " << this->workers << " " <<this->fileIsEmpty << endl;
        return;
    }

    // 3、文件存在
    int num = this->get_WorkersNum();
    cout << "当前职工人数为：" << num << endl;
    this->workerNum=num;
    // 开辟空间，并初始化职工信息
    this->workers=new Worker*[this->workerNum];
    this->init_workers();

    cout << this->workerNum << " " << this->workers << " " <<this->fileIsEmpty << endl;


}

// 菜单展示
void WorkerManager::ShowMenu() {
    cout<<"**************************************************"<<endl;
    cout<<"********** 欢迎使用职工管理系统！   ******************"<<endl;
    cout<<"**********    0 退出管理系统    ********************"<<endl;
    cout<<"**********    1 增加职工信息    ********************"<<endl;
    cout<<"**********    2 显示职工信息    ********************"<<endl;
    cout<<"**********    3 删除离职职工    ********************"<<endl;
    cout<<"**********    4 修改职工信息    ********************"<<endl;
    cout<<"**********    5 查找职工信息    ********************"<<endl;
    cout<<"**********    6 按照编号排序    ********************"<<endl;
    cout<<"**********    7 清空所有文档    ********************"<<endl;
    cout<<"**************************************************"<<endl;
    cout<<endl;
}

// 退出系统
void WorkerManager::ExitSystem() {
    cout << "欢迎下次使用" << endl;
//    pause();
    exit(0);
}

// 添加职工
void WorkerManager::AddWorker(){
    cout << "请输入要添加的职工数量：";

    int addNum = 0;
    cin >> addNum;

    if (addNum){    // 添加
        // 计算添加后空间大小
        int newSize = this->workerNum + addNum;

        // 开辟新空间
        auto newWorkers = new Worker* [newSize];

        // 将原来数据拷贝到新空间
        if (this->workers){
            for(int i=0;i<this->workerNum;++i){
                newWorkers[i] = this->workers[i];
            }
        }

        // 添加新数据
        for(int i=0;i<addNum;++i){
            int id;         // 职工编号
            string name;    // 职工姓名
            int dept;       // 职工部门

            cout << "请输入第 " << i+1 << " 个新职工的编号：";
            cin >> id;
            cout << "请输入第 " << i+1 << " 个新职工的姓名：";
            cin >> name;
            cout << "请选择第 " << i+1 << " 个新职工的岗位：\n"
                 << "\t 1、普通职工\n"
                 << "\t 2、经理\n"
                 << "\t 3、老板" << endl;
            cin >> dept;

            Worker *worker = nullptr;
            switch (dept) {
                case 1:
                    worker = new Employee(id,name,1);
                    break;
                case 2:
                    worker = new Manager(id,name,2);
                    break;
                case 3:
                    worker = new Boss(id,name,3);
                    break;
                default:
                    cout << "输入有误，该职工信息添加失败！！！" << endl;
                    break;
            }

            newWorkers[this->workerNum++] = worker;
        }

        delete [] this->workers;
        this->workers = newWorkers;
        if (this->workerNum>0)
            this->fileIsEmpty= false;

        // 将数据写入文件中
        this->Save();

        cout << "成功添加 " << addNum << " 名新职工\n\n" << endl;

    } else{
        cout << "输入有误\n\n" << endl;
    }

    system("clear");

}

// 保存文件
void WorkerManager::Save() {
    ofstream ofs;
    ofs.open(FILENAME,ios::out);

    if (ofs){
        for (int i = 0; i < this->workerNum; ++i) {
            cout << this->workers[i]->m_ID << " "
                 << this->workers[i]->m_name << " "
                 << this->workers[i]->m_DeptID <<endl;

            ofs << this->workers[i]->m_ID << " "
                << this->workers[i]->m_name << " "
                << this->workers[i]->m_DeptID <<endl;
        }

        ofs.close();
    }

}

// 获取文件中的成员个数
int WorkerManager::get_WorkersNum(){
    ifstream ifs(FILENAME,ios::in);
    int id;
    string name;
    int dept;

    int num=0;
    while (ifs>>id && ifs>>name && ifs>>dept){
        ++num;
    }

    ifs.close();
    return num;
}

// 初始化职工
void WorkerManager::init_workers(){
    ifstream ifs(FILENAME,ios::in);

    int id;
    string name;
    int dept;

    int index=0;
    while (ifs>>id && ifs>>name && ifs>>dept){
        Worker *worker = nullptr;
        if (dept == 1){
            worker=new Employee(id,name,dept);
        } else if (dept == 2){
            worker=new Manager(id,name,dept);
        } else{
            worker=new Boss(id,name,dept);
        }
        this->workers[index]=worker;
        ++index;

    }

    ifs.close();
}

// 查看职工信息
void WorkerManager::ShowWorkers(){
    if (this->fileIsEmpty){
        cout << "文件不存在或者文件为空！！！" << endl;
    } else{
        for (int i = 0; i < this->workerNum; ++i) {
            this->workers[i]->showInfo();
        }
    }
    cout << "\n\n" << endl;
}

// 删除职工信息
void WorkerManager::DelWorker(){
    if (this->fileIsEmpty){
        cout << "文件不存在或者文件为空！！！" << endl;
    } else{
        cout << "请输入想要删除的职工编号：";
        int id=0;
        cin >> id;
        int index = this->IsExist(id);

        // 职工存在，开始删除
        if (index != -1){

            delete this->workers[index];
            this->workers[index]= nullptr;

            for (int i = index; i < this->workerNum-1; ++i) {
                // 数组向前移动
                this->workers[i]= this->workers[i+1];
            }

            delete this->workers[this->workerNum-1];
            this->workers[this->workerNum-1] = nullptr;

            if ((--this->workerNum)==0)
                this->fileIsEmpty= true;

            this->Save();
            cout << "删除成功！！！\n\n" << endl;

        } else{     // 职工不存在
            cout << "删除失败，该职工不存在！！！\n\n" << endl;
        }

    }
}

// 查找职工下标
int WorkerManager::IsExist(int id){
    int index = -1;
    for (int i = 0; i < this->workerNum; ++i) {
        if (this->workers[i]->m_ID == id){
            index=i;
            break;
        }
    }
    return index;
}

// 修改职工信息
void WorkerManager::UpdateWorker(){
    if (this->fileIsEmpty){
        cout << "文件不存在或者文件为空！！！" << endl;
    } else{
        cout << "请输入要修改的职工编号：";
        int id=0;
        cin >> id;
        int index = this->IsExist(id);

        // 职工存在，开始删除
        if (index != -1){
            delete this->workers[index];

            string name;
            int dept;

            cout << "请输入修改后的职工姓名：";
            cin >> name;
            cout << "请选择修改后的职工岗位：\n"
                 << "\t 1、普通职工\n"
                 << "\t 2、经理\n"
                 << "\t 3、老板" << endl;
            cin >> dept;

            Worker *worker = nullptr;
            switch (dept) {
                case 1:
                    worker = new Employee(id,name,1);
                    break;
                case 2:
                    worker = new Manager(id,name,2);
                    break;
                case 3:
                    worker = new Boss(id,name,3);
                    break;
                default:
                    cout << "输入有误，该职工信息添加失败！！！" << endl;
                    break;
            }

            this->workers[index] = worker;
            this->Save();

            cout << "修改成功\n\n" << endl;

        } else{     // 职工不存在
            cout << "修改失败，该职工不存在！！！\n\n" << endl;
        }
    }
}

// 查找职工信息
void WorkerManager::FindWorker(){
    if (this->fileIsEmpty){
        cout << "文件不存在或者文件为空！！！" << endl;
    } else{
        cout << "请选择要查询的方式：\n"
             << "\t1、按职工编号查询\n"
             << "\t2、按职工姓名查询" << endl;
        int select =0;
        cin >> select;

        if (select==1){ // 按职工编号查询，职工编号唯一
            cout << "请输入要查询的职工编号：";
            int id=0;
            cin >> id;
            int index = this->IsExist(id);

            // 职工存在
            if (index != -1){
                cout << "查询成功，该职工信息如下：" << endl;
                cout << "\t";
                this->workers[index]->showInfo();
            } else{
                cout << "欲查询职工不存在！！" << endl;
            }
        } else if (select==2){  // 按职工姓名查询，职工姓名不唯一
            cout << "请输入要查询的职工姓名：";
            string name;
            cin >> name;

            // 判断标志
            bool flag = false;
            for (int i = 0; i < this->workerNum; ++i) {
                if (this->workers[i]->m_name == name){
                    if (!flag){
                        flag= true;
                        cout << "查询成功，查询职工信息如下：" << endl;
                    }
                    cout << "\t";
                    this->workers[i]->showInfo();

                }
            }

            if (!flag){
                cout << "欲查询职工不存在！！" << endl;
            }
        } else{
            cout << "输入选项有误！！" << endl;
        }
    }

    cout << "\n\n" << endl;

}

// 按照编号排序
void WorkerManager::SortWorkers(){
    if (this->fileIsEmpty){
        cout << "文件不存在或者文件为空！！！" << endl;
    } else{
        cout << "请选择要排序的方式：\n"
             << "\t1、按职工编号升序排序\n"
             << "\t2、按职工编号降序排序" << endl;
        int select =0;
        cin >> select;

        if (select==1){         // 升序
            for (int i = 0; i < this->workerNum; ++i) {
                int min = i;
                for (int j = i+1; j < this->workerNum; ++j) {
                    if (this->workers[j]->m_ID < this->workers[min]->m_ID){
                        min = j;
                    }
                }
                if (min!=i){
                    Worker *temp= this->workers[min];
                    this->workers[min]=this->workers[i];
                    this->workers[i]=temp;
                }
            }

            this->Save();
            cout << "排序成功，排序后结果为：" << endl;
            this->ShowWorkers();

        }
        else if (select==2) {   // 降序
            for (int i = 0; i < this->workerNum; ++i) {
                int max = i;
                for (int j = i+1; j < this->workerNum; ++j) {
                    if (this->workers[j]->m_ID > this->workers[max]->m_ID){
                        max = j;
                    }
                }
                if (max!=i){
                    Worker *temp= this->workers[max];
                    this->workers[max]=this->workers[i];
                    this->workers[i]=temp;
                }
            }

            this->Save();
            cout << "排序成功，排序后结果为：" << endl;
            this->ShowWorkers();

        }else{
            cout << "输入选项有误！！" << endl;
        }

    }

    cout << "\n\n" << endl;

}

// 清空文件
void WorkerManager::ClearAll(){
    if (this->fileIsEmpty){
        cout << "文件不存在或者文件为空！！！" << endl;
        return;
    }

    cout << "确认要清空文件吗？\n"
         << "\t1、是\n"
         << "\t2、否" << endl;
    int select =0;
    cin >> select;

    if (select == 1){
        ofstream ofs(FILENAME,ios::trunc);
        ofs.close();
        this->fileIsEmpty= true;

        if (this->workers != nullptr){
            for (int i = 0; i < this->workerNum; ++i) {
                if (this->workers[i] != nullptr){
                    delete this->workers[i];
                    this->workers[i] = nullptr;
                }
            }

            delete [] this->workers;
            this->workers= nullptr;
            this->workerNum=0;

            cout << "清空成功！！！" << endl;
        }

    }

    cout << "\n\n" << endl;

}

// 析构函数
WorkerManager::~WorkerManager() {
    cout<<"析构"<<endl;
    if (this->workers != nullptr){
        for (int i = 0; i < this->workerNum; ++i) {
            if (this->workers[i] != nullptr){
                delete this->workers[i];
                this->workers[i] = nullptr;
            }
        }

        delete [] this->workers;
        this->workers= nullptr;
        this->workerNum=0;
    }
}




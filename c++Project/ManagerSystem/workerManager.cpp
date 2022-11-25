//
// Created by lenovo on 2022/9/29.
//
//
// Created by lenovo on 2022/9/29.
//

#ifndef MAIN_CPP_WORKERMANAGER_H
#define MAIN_CPP_WORKERMANAGER_H

#endif //MAIN_CPP_WORKERMANAGER_H

#include "workerManager.h"

WorkerManager::WorkerManager() {
    //文件不能存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);//读文件

    //1、文件不存在
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        //初始化属性
        //初始化记录人数
        this->m_EmpNum = 0;
        //初始化数据指针
        this->m_EmpArray = NULL;
        //初始化文件是否为空
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    //2、文件存在，数据为空
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        //文件为空
        cout << "文件为空" << endl;
        //初始化属性
        //初始化记录人数
        this->m_EmpNum = 0;
        //初始化数据指针
        this->m_EmpArray = NULL;
        //初始化文件是否为空
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    //3、文件存在，并且记录数据
    int num = this->get_EmpNum();
    cout << "职工人数：" << num << endl;
    this->m_EmpNum = num;

    //开辟空间，将文件中的数据存放到数组中
    this->m_EmpArray=new Worker*[this->m_EmpNum];
    this->init_Emp();


    //测试代码
//    for(int i=0;i<this->m_EmpNum;i++)
//    {
//        cout<<"职工编号："<<this->m_EmpArray[i]->m_Id
//        <<"姓名："<<this->m_EmpArray[i]->m_Name
//        <<"部门："<<this->m_EmpArray[i]->m_DeptId<<endl;
//    }

}


//展示菜单
void WorkerManager::Show_Menu()
{
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}
//退出系统
void WorkerManager::ExitSystem()
{
    cout<<"欢迎下次使用！"<<endl;
    exit(0);
}
//添加职工
void WorkerManager::Add_Emp() {
    cout<<"请输入添加职工的数量；"<<endl;
    int addNum=0;//保存用户的输入数量
    cin>>addNum;
    if(addNum>0)
    {
        //添加
        //计算添加新的空间大小
        int newSize=this->m_EmpNum+addNum;//新空间大小=原来记录人数+新增加人数
        //开辟空间
        Worker **newSpace=new Worker*[newSize];
        //将原来空间下的数据，拷贝到新的空间下
        if(this->m_EmpArray!=NULL)
        {
            for(int i=0;i<this->m_EmpNum;i++)
            {
                newSpace[i]=this->m_EmpArray[i];
            }
        }
        //添加新数据
        for(int i=0;i<addNum;i++)
        {
            int id;//职工编号
            string name;//职工姓名
            int dSelect;//部门选择
            cout<<"请输入第"<<i+1<<"个新员工编号："<<endl;
            cin>>id;
            cout<<"请输入第"<<i+1<<"个新员工姓名："<<endl;
            cin>>name;
            cout<<"请选择该职工的岗位："<<endl;
            cout<<"1、普工职工"<<endl;
            cout<<"2、经理"<<endl;
            cout<<"3、老板"<<endl;
            cin>>dSelect;
            Worker *worker=NULL;
            switch (dSelect) {
                case 1:
                    worker=new Employee(id,name,1);
                    break;
                case 2:
                    worker=new Manager(id,name,2);
                    break;
                case 3:
                    worker=new Boss(id,name,3);
                    break;
                default:
                    break;
            }
            //将创建职工指针，保存到数组中
            newSpace[this->m_EmpNum+i]=worker;

        }

        //释放原有空间
        delete[] this->m_EmpArray;
        //更改新空间的指向
        this->m_EmpArray=newSpace;
        //更新新职工人数
        this->m_EmpNum=newSize;
        //更新职工不为空的标志
        this->m_FileIsEmpty= false;
        //提示添加成功
        cout<<"成功添加"<<addNum<<"名新员工"<<endl;
        //保存数据到文件中
        this->save();
    }else
    {
        cout<<"输入数据有误"<<endl;
    }
    //按任意键后 清屏返回到上级目录
    system("pause");
    system("cls");
}

//保存文件
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out);//输出方式打开文件--类似于写文件
    //将每个人的数据写入到文件中
    for(int i=0;i<this->m_EmpNum;i++)
    {
        ofs<<this->m_EmpArray[i]->m_Id<<" "
           <<this->m_EmpArray[i]->m_Name<<" "
           <<this->m_EmpArray[i]->m_DeptId<<endl;
    }
    ofs.close();
}

int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        //记录人数
        num++;
    }
    ifs.close();
    if(num>0)
    {
        this->m_FileIsEmpty= false;
    }
    return num;
}

//初始化员工
void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker * worker = NULL;
        //根据不同的部门Id创建不同对象
        if (dId == 1)  // 1普通员工
        {
            worker = new Employee(id, name, dId);
        }
        else if (dId == 2) //2经理
        {
            worker = new Manager(id, name, dId);
        }
        else //总裁
        {
            worker = new Boss(id, name, dId);
        }
        //存放在数组中
        this->m_EmpArray[index] = worker;
        index++;
    }
}
//显示职工
void WorkerManager::show_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        for (int i = 0; i <this->m_EmpNum; i++)
        {
            //利用多态调用接口
            this->m_EmpArray[i]->showInfo();
        }
    }

    system("pause");
    system("cls");
}

//删除职工
void WorkerManager::Del_Emp() {
    if(this->m_FileIsEmpty)
    {
        cout<<"文件不存在，或者记录为空"<<endl;
    }else
    {
        //按照职工编号删除
        cout<<"请输入想要删除职工编号："<<endl;
        int id=0;
        cin>>id;
        int index=this->IsExist(id);
        if(index!=-1)//说明职工存在，并且要删除掉index位置
        {

            for(int i=index;i<this->m_EmpNum-1;i++)
            {
                //数据前移
                this->m_EmpArray[i]=this->m_EmpArray[i+1];
            }
            this->m_EmpNum--;//更新一下数组中记录的人员个数
            //数据同步更新到文件中
            this->save();
            cout<<"删除成功"<<endl;
        }else
        {
            cout<<"删除失败，未找到该职工"<<endl;
        }
    }
    //按任意健清屏
    system("pause");
    system("cls");
}

//判断职工是否存在， 如果存在返回职工所处的位置，不返回则返回-1
int WorkerManager::IsExist(int id) {
    int index=-1;
    for(int i=0;i<this->m_EmpNum;i++)
    {
        if(this->m_EmpArray[i]->m_Id==id)
        {
            //找到职工
            index=i;\
            break;
        }
    }
    return index;
}

//修改职工
void WorkerManager::Mod_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"文件不存在，或者记录为空"<<endl;
    }else
    {
        cout<<"请输入修改职工的编号："<<endl;
        int id;
        cin>>id;
        int ret=this->IsExist(id);
        if(ret!=-1)
        {
            //查找到编号的职工
            delete this->m_EmpArray[ret];

            int newId=0;
            string newName="";
            int dSelect=0;
            cout<<"查到："<<id<<"号职工，请输入新职工编号："<<endl;
            cin>>newId;
            cout<<"请输入新姓名："<<endl;
            cin>>newName;
            cout<<"请输入岗位："<<endl;
            cout<<"1、普通职工："<<endl;
            cout<<"2、经理："<<endl;
            cout<<"3、老板："<<endl;
            cin>>dSelect;
            Worker *worker=NULL;
            switch (dSelect) {
                case 1:
                    worker=new Employee(newId,newName,dSelect);
                    break;
                case 2:
                    worker=new Manager(newId,newName,dSelect);
                    break;
                case 3:
                    worker=new Boss(newId,newName,dSelect);
                    break;
            }
            //更新数据到数组中
            this->m_EmpArray[ret]=worker;
            cout<<"修改成功"<<endl;
            //保存到文件中
            this->save();
        }else
        {
            cout<<"修改失败，查无此人！"<<endl;
        }
    }
    system("pause");
    system("cls");
}
//查找职工
void WorkerManager::Find_Emp() {
    if(this->m_FileIsEmpty)
    {
        cout<<"文件不存在或者记录为空"<<endl;

    }else
    {
        cout<<"请输入查找方式："<<endl;
        cout<<"1、按照志工编号查找"<<endl;
        cout<<"2、按照职工的姓名查找"<<endl;
        int select=0;
        cin>>select;
        if(select==1)
        {
            //按照编号查找
            int id;
            cout<<"请输入查找的职工编号："<<endl;
            cin>>id;
           int ret= IsExist(id);
            if(ret!=-1)
            {
                //找到职工
                cout<<"查找成功，该职工的信息如下："<<endl;
                this->m_EmpArray[ret]->showInfo();

            }else
            {
                cout<<"查找失败，查无此人！"<<endl;
            }
        }else if(select==2)
        {
            //按照姓名查找
            string name;
            cout<<"请输入查找的姓名："<<endl;
            cin>>name;
            //加入判断是否查到的标志
            bool flag= false;//默认未找到

            for(int i=0;i<this->m_EmpNum;i++)
            {
                if(this->m_EmpArray[i]->m_Name==name)
                {
                    cout<<"查找成功，职工编号为："
                    <<this->m_EmpArray[i]->m_Id
                    <<"号职工信息如下："<<endl;
                    flag==true;
                    //调用显示职工信息的接口
                    this->m_EmpArray[i]->showInfo();
                }
            }
            if(flag==false)
            {
                cout<<"查找失败，查无此人！"<<endl;
            }

        }
        else{
             cout<<"输入选项有误！"<<endl;
        }

    }
    //按任意键清屏
    system("pause");
    system("cls");
}
//按照职工编号排序
void WorkerManager::Sort_Emp() {
    if (this->m_FileIsEmpty)
    {
        cout<<"文件不存在或者记录为空！"<<endl;
        system("pause");
        system("cls");
    }else
    {
        cout<<"请选择排序的方式："<<endl;
        cout<<"1、按照职工编号升序排名："<<endl;
        cout<<"2、按照职工编号降序排名："<<endl;
        int select=0;
        cin>>select;
        for(int i=0;i<this->m_EmpNum;i++)
        {
            int minOrMax=i;//声明最小值或者最大值下标
            for(int j=i+1;j< this->m_EmpNum;j++)
            {
                if(select==1)//升序
                {
                    if(this->m_EmpArray[minOrMax]->m_Id>this->m_EmpArray[j]->m_Id)
                    {
                        minOrMax=j;
                    }
                }else
                {
                    //降序
                    if(this->m_EmpArray[minOrMax]->m_Id<this->m_EmpArray[j]->m_Id)
                    {
                        minOrMax=j;
                    }
                }
            }
            //判断一开始认定最小值或最大值，是不是计算的最小值或最大值，如果不是，交换数据
            if(i!=minOrMax)
            {
                Worker *temp=this->m_EmpArray[i];
                this->m_EmpArray[i]=this->m_EmpArray[minOrMax];
                this->m_EmpArray[minOrMax]=temp;
            }
        }
        cout<<"排序成功！排序后的结果为："<<endl;
        this->save();//排序后结果保存到文件中
        this->show_Emp();//展示所有的职工
    }
}
//清空文件
void WorkerManager:: Clean_File(){
    cout<<"确定清空？"<<endl;
    cout<<"1、确定"<<endl;
    cout<<"2、返回"<<endl;
    int select=0;
    cin>>select;
    if(select==1)
    {
        //清空文件
        ofstream ofs(FILENAME,ios::trunc);//删除文件后，再重新创建
        ofs.close();
        if(this->m_EmpArray!=NULL)
        {
            //删除堆区的每个职工对象
            for(int i=0;i<this->m_EmpNum;i++)
            {
                delete this->m_EmpArray[i];
                this->m_EmpArray[i]=NULL;
            }
            //删除堆区的数据指针
            delete [] this->m_EmpArray;
            this->m_EmpArray=NULL;
            this->m_EmpNum=0;
            this->m_FileIsEmpty= true;
        }
        cout<<"清空成功！"<<endl;
    }
    system("pause");
    system("cls");
}

WorkerManager::~WorkerManager() {
    if(this->m_EmpArray!=NULL)
    {
        delete [] this->m_EmpArray;
        this->m_EmpArray=NULL;
    }
}



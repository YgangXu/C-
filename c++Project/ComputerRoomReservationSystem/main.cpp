#include <iostream>
using namespace std;
#include <fstream>
#include "identity.h"
#include "string"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

//进入学生子菜单界面
void studentMenu(Identity*&student)
{
    while(true)
    {
        //调用学生子菜单
        student->operMenu();//多态中的接口是相同的,但不同的对象调用会显示不同结果
        Student *stu=(Student*)student;
        int select=0;
        cin>>select;
        if(select==1)
        {
            //申请预约
            stu->applyOrder();
        }else if(select==2)
        {
            //查看自身预约
            stu->showMyOrder();
        }else if(select==3)
        {
            //查看所有人预约
            stu->showAllOrder();
        }else if(select==4)
        {
            //取消预约
            stu->cancelOrder();
        }else
        {
            //注销登录
            delete student;
            cout<<"注销成功"<<endl;
            system("pause");
            system("cls");
            return ;
        }
    }
}
//进入教师子系统菜单界面
void teacherMenu(Identity * &teacher)
{
    while (true)
    {
        //教师菜单
        teacher->operMenu();

        Teacher* tea = (Teacher*)teacher;
        int select = 0;

        cin >> select;

        if (select == 1)
        {
            //查看所有预约
            tea->showAllOrder();
        }
        else if (select == 2)
        {
            //审核预约
            tea->validOrder();
        }
        else
        {
            delete teacher;
            cout << "注销成功" << endl;
            system("pause");
            system("cls");
            return;
        }

    }
}


//进入管理员的子系统界面

void managerMenu(Identity * &manager)
{
    while(true)
    {
        //调用管理员子菜单
        manager->operMenu();//父类指针只能调用公共接口
        //将父类指针 转化为子类指针，调用子类里其他接口
        //多态就是有个公共接口，然后派生的不同对象可以调用属于自己的接口
        Manager*man=(Manager*)manager;
        int select=0;
        cin>>select;
        if(select==1)//添加账号
        {
            cout<<"添加账号"<<endl;
            man->addPerson();

        }else if(select==2)//查看账号
        {
            cout<<"查看账号"<<endl;
            man->showPerson();
        }else if(select==3)//查看机房
        {
            cout<<"查看机房"<<endl;
            man->showComputer();
        }else if(select==4)//清空预约
        {
            cout<<"清空预约"<<endl;
            man->cleanFile();
        }else
        {
            //注销模块
            delete manager;//销毁掉堆区对象
            cout<<"注销成功！"<<endl;
            system("pause");
            system("cls");
//            return;
        }
    }

}

//创建一个全局函数
//登录功能  参数1 操作文件名 参数2 操作身份类型
void LoginIn(string fileName,int type)
{
    //父类指针 用于指向子类对象
    Identity * person=NULL;
    //读文件
    ifstream ifs;
    ifs.open(fileName,ios::in);
    //判断文件是否存在
    if(!ifs.is_open())
    {
        cout<<"文件不存在"<<endl;
        ifs.close();
        return;
    }

    //准备接受用户信息
    int id=0;
    string name;
    string pwd;
    //判断身份
    if(type==1)//学生省份
    {
        cout<<"请输入你的学号："<<endl;
        cin>>id;

    }else if(type==2)
    {
        cout<<"请输入你的职工号："<<endl;
        cin>>id;
    }
        cout<<"请输入用户名："<<endl;
        cin>>name;
        cout<<"请输入密码："<<endl;
        cin>>pwd;

    if(type==1)
    {
        //学生身份验证
        int fId;//从文件中读取的id号
        string fName;//从文件中获取的姓名
        string fPwd;//从文件中获取密码
        while(ifs>>fId&&ifs>>fName&&ifs>>fPwd)//ifs把文见内容依次读到fId，fname，fPwd中， 遇见空格读一个
        {
            //与用户输入的信息做对比
            if(fId==id&&fName==name&&fPwd==pwd)
            {
                cout<<"学生验证登录成功！"<<endl;
                system("pause");
                system("cls");
                person=new Student(id,name,pwd);
                //进入到学生身份的子菜单
                studentMenu(person);
                return;
            }
        }

    }else if(type==2)
    {
        //教师身份验证
        int fId;//从文件中读取的id号
        string fName;//从文件中获取的姓名
        string fPwd;//从文件中获取密码
        while(ifs>>fId&&ifs>>fName&&ifs>>fPwd)//ifs把文见内容依次读到fId，fname，fPwd中， 遇见空格读一个
        {
            //与用户输入的信息做对比
            if(fId==id&&fName==name&&fPwd==pwd)
            {
                cout<<"老师验证登录成功！"<<endl;
                system("pause");
                system("cls");
                person=new Teacher(id,name,pwd);
                //进入到学生身份的子菜单
                teacherMenu(person);
                return;

            }
        }

    }else if(type==3)
    {
        //管理员身份验证
        string fName;//从文件中获取的姓名
        string fPwd;//从文件中获取密码
        while(ifs>>fName&&ifs>>fPwd)//ifs把文见内容依次读到fId，fname，fPwd中， 遇见空格读一个
        {
            //与用户输入的信息做对比
            if(fName==name&&fPwd==pwd)
            {
                cout<<"管理员验证登录成功！"<<endl;
                system("pause");
                system("cls");
                person=new Manager(name,pwd);
                managerMenu(person);

                return;
            }
        }
    }
    cout<<"验证登录失败！"<<endl;
    system("pause");
    system("cls");
    return;
}



int main() {
    system("chcp 65001");

    int select=0;//用于用户的选择
    while(true)
    {
        cout << "======================  欢迎来到传智播客机房预约系统  ====================="
             << endl;
        cout << endl << "请输入您的身份" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.学生代表             |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.老    师            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.管 理 员            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.退    出            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "输入您的选择: ";

        cin>>select;//接受用户的选择

        switch (select) //根据用户的选择实现不同的接口
        {
            case 1://学生身份
                LoginIn(STUDENT_FILE,1);
                break;
            case 2://老师身份
                LoginIn(TEACHER_FILE,2);
                break;
            case 3://管理员身份
                LoginIn(ADMIN_FILE,3);
                break;
            case 0://退出系统
                cout<<"欢迎下一次使用！"<<endl;
                system("pause");
                return 0;
                break;
            default:
                cout<<"输入有误，请重新选择!"<<endl;
                system("pause");
                system("cls");
                break;


        }

    }


    system("pause");

    return 0;
}
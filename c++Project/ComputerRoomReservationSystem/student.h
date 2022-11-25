//
// Created by lenovo on 2022/10/13.
//

#ifndef COMPUTERROOMRESERVATIONSYSTEM_STUDENT_H
#define COMPUTERROOMRESERVATIONSYSTEM_STUDENT_H

#endif //COMPUTERROOMRESERVATIONSYSTEM_STUDENT_H
#pragma once
#include <iostream>
#include <vector>

using namespace std;
#include "identity.h"
#include "computerRoom.h"
#include <fstream>
#include "globalFile.h"
#include "orderFile.h"

//学生类
class Student:public Identity
{
public:
    //默认构造
    Student();
    //有参构造 参数：学号 姓名 密码
    Student(int id,string name,string pwd);
    //菜单界面
    virtual void operMenu();

    //申请预约
    void applyOrder();

    //查看自身预约
    void showMyOrder();
    //查看所有人预约
    void showAllOrder();
    //取消预约
    void cancelOrder();

    //机房容器
    vector<ComputerRoom>vCom;


    //学生学号
    int m_Id;

};
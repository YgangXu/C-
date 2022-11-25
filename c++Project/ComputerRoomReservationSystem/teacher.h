//
// Created by lenovo on 2022/10/13.
//

#ifndef COMPUTERROOMRESERVATIONSYSTEM_TEACHER_H
#define COMPUTERROOMRESERVATIONSYSTEM_TEACHER_H

#endif //COMPUTERROOMRESERVATIONSYSTEM_TEACHER_H
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "identity.h"
#include "orderFile.h"

class Teacher :public Identity
{
public:

    //默认构造
    Teacher();

    //有参构造 (职工编号，姓名，密码)
    Teacher(int empId, string name, string pwd);

    //菜单界面
    virtual void operMenu();

    //查看所有预约
    void showAllOrder();

    //审核预约
    void validOrder();

    int m_EmpId; //教师编号

};
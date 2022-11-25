//
// Created by lenovo on 2022/9/29.
//

#ifndef MAIN_CPP_WORKER_H
#define MAIN_CPP_WORKER_H

#endif //MAIN_CPP_WORKER_H
#pragma once
#include <iostream>
using namespace std;
#include <string>

//职工抽象类
class Worker
{
public:
    //显示个人信息
    virtual void showInfo()=0;
    //获取岗位名称
    virtual string getDeptName()=0;

    //职工编号
    int m_Id;
    //职工姓名
    string m_Name;
    //部门编号
    int m_DeptId;
};
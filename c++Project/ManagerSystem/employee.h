//
// Created by lenovo on 2022/9/29.
//

#ifndef MAIN_CPP_EMPLOYEE_H
#define MAIN_CPP_EMPLOYEE_H

#endif //MAIN_CPP_EMPLOYEE_H
//普工职工文件
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
class Employee:public Worker
{
public:
    //构造含函数
    Employee(int id,string name,int dId);
    //显示个人信息
    virtual void showInfo();
    //获取岗位名称
    virtual string getDeptName();
};
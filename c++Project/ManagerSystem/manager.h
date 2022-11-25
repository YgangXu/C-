//
// Created by lenovo on 2022/10/8.
//

#ifndef MAIN_CPP_MANAGER_H
#define MAIN_CPP_MANAGER_H

#endif //MAIN_CPP_MANAGER_H
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
//经理类
class Manager:public Worker
{
public:
    //构造函数
    Manager(int id,string name,int dId);
    //显示个人信息
    virtual void showInfo();
    //获取岗位名称
    virtual string getDeptName();
};
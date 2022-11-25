//
// Created by lenovo on 2022/10/8.
//

#ifndef MAIN_CPP_BOSS_H
#define MAIN_CPP_BOSS_H

#endif //MAIN_CPP_BOSS_H

#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
//经理类
class Boss:public Worker
{
public:
    //构造函数
    Boss(int id,string name,int dId);
    //显示个人信息
    virtual void showInfo();
    //获取岗位名称
    virtual string getDeptName();
};
//
// Created by lenovo on 2022/9/29.
//

#ifndef MAIN_CPP_EMPLOYEE_H
#define MAIN_CPP_EMPLOYEE_H

#endif //MAIN_CPP_EMPLOYEE_H
//�չ�ְ���ļ�
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
class Employee:public Worker
{
public:
    //���캬����
    Employee(int id,string name,int dId);
    //��ʾ������Ϣ
    virtual void showInfo();
    //��ȡ��λ����
    virtual string getDeptName();
};
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

//ְ��������
class Worker
{
public:
    //��ʾ������Ϣ
    virtual void showInfo()=0;
    //��ȡ��λ����
    virtual string getDeptName()=0;

    //ְ�����
    int m_Id;
    //ְ������
    string m_Name;
    //���ű��
    int m_DeptId;
};
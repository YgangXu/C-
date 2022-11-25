//
// Created by lenovo on 2022/10/14.
//

#ifndef COMPUTERROOMRESERVATIONSYSTEM_ORDERFILE_H
#define COMPUTERROOMRESERVATIONSYSTEM_ORDERFILE_H

#endif //COMPUTERROOMRESERVATIONSYSTEM_ORDERFILE_H
#pragma once
#include <iostream>
using namespace std;
#include "globalFile.h"
#include "fstream"
#include <map>

class OrderFile
{
public:
    //构造函数
    OrderFile();
    //更新预约记录
    void updateOrder();
    //记录预约条数
    int m_Size;
    //记录所有预约信息的容器 key 记录条数 value集体的记录信息
    map<int,map<string,string>>m_orderData;


};
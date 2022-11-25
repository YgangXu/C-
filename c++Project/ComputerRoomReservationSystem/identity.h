//
// Created by lenovo on 2022/10/12.
//

#ifndef COMPUTERROOMRESERVATIONSYSTEM_IDENTITY_H
#define COMPUTERROOMRESERVATIONSYSTEM_IDENTITY_H

#endif //COMPUTERROOMRESERVATIONSYSTEM_IDENTITY_H
#pragma once//防止头文件重复包含
#include <iostream>

using namespace std;
//身份抽象基类
class Identity
{
public:

    //操作菜单 纯虚函数（为后面多态做准备）
    virtual void operMenu()=0;

    //用户名
    string m_Name;
    //密码
    string m_Pwd;

};

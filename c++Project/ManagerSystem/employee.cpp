//
// Created by lenovo on 2022/9/29.
//
#include "employee.h"
//���캬����
Employee::Employee(int id,string name,int dId)
{
    this->m_Id=id;
    this->m_Name=name;
    this->m_DeptId=dId;
}
//��ʾ������Ϣ
void Employee::showInfo()
{
    cout<<"ְ����ţ�"<<this->m_Id
        <<"\tְ��������"<<this->m_Name
        <<"\t��λ��"<<this->getDeptName()
        <<"\t��λְ����ɾ�����������"<<endl;
}
//��ȡ��λ����
string Employee::getDeptName()
{
    return string("Ա��");
}
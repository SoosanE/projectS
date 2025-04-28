//���� #7, 12221487, ������
//BestFriend.cpp
#include <iostream>
#include<string>
using namespace std;
#include "BestFriend.h"
//������
BestFriend::BestFriend(const string& n, int a, float g, const string& p, int year, const string& rel) : Friend(n, a, g, p), relationship(rel) //�θ� Ŭ������ ������ ȣ��
{ //string ��ü�� has-a�ϴ� ����(2�� �ݺ� ����)
	setfromYear(year);
	//setrelationship(rel);
	bestFriendCount++; //��ü���� +1
}
BestFriend::~BestFriend() { //�Ҹ���
	bestFriendCount--; //��ü -1
}
BestFriend::BestFriend(const BestFriend& bf) //���������
{//��ӹ��� set �� get �Լ� �̿��ϱ�
    getAge();
    getName();
    getGPA();
    getPnumber();
    fromYear = bf.fromYear;
    relationship = bf.relationship;
	bestFriendCount++;
}

void BestFriend::setfromYear(int year) { //set�Լ� ����
	fromYear = year;
}
int BestFriend::getfromYear() const { //get �Լ� ����
	return fromYear;
}
void BestFriend::setrelationship(const string& rel) {
	relationship = rel;
}
string BestFriend::getrelationship() const{
	return relationship;
}

int BestFriend::bestFriendCount = 0;
int BestFriend::getBestFriendCount() { //��ü ���� count
	return bestFriendCount;
}

const BestFriend& BestFriend::operator=(const BestFriend& bf) { //����������
    if (this != &bf) {
        Friend::operator=(bf); //Friend Ŭ���� ���� ������ ȣ��
        fromYear = bf.fromYear; //BestFriend Ŭ������ ��� ����
        relationship = bf.relationship;
    }
    return *this;
}

ostream& operator<<(ostream& out, const BestFriend& bf) {//��� ������ �����ε� ����
    //Friend Ŭ�����κ��� ��ӹ��� ����� ���   
    out << "Name: " << bf.getName() << endl;
    out << "Age: " << bf.getAge() << endl;
    out << "GPA: " << bf.getGPA() << endl;
    out << "Phone Number: " << bf.getPnumber() << endl;
    for (int i = 0; i < bf.getAge(); i++) { //���̿� ���� ���� �׷��� ���
        out << '*';
    }
    out << endl;
    out <<"From " << bf.fromYear << endl; //BestFriend Ŭ������ ��� ���
    out << "In relation "<<bf.relationship << endl;
    return out;
}

istream& operator>>(istream& in, BestFriend& bf) { //�Է� ������ �����ε� ����
    //Friend Ŭ�����κ��� ��ӹ��� ����� �Է�
    string name, pnumber;
    int age;
    float gpa;
    in >> name >> age >> gpa >> pnumber;
    bf.setName(name);
    bf.setAge(age);
    bf.setGPA(gpa);
    bf.setPnumber(pnumber);
    in >> bf.fromYear >> bf.relationship; //BestFriend Ŭ������ ����� �Է�
    return in;
}//��ӹ��� set,get�Լ��� �̿��ؼ� ������ �����ε� ������ Ȱ��

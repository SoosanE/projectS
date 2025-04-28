#pragma once
//���� #7, 12221487, ������
//BestFriend.h
#include <iostream>
#include<string>
using namespace std;
#include "Friend.h" //Friend Ŭ�����κ��� ���
class BestFriend : public Friend //������ Friend Ŭ�����κ��� public ���
{
private:
	int fromYear; //�� �⵵����
	string relationship; //���� ����
	static int bestFriendCount; //������ �� ������ �����ϴ� Ŭ���� ���� 
public:
	BestFriend(const string& n = "", int a = 0, float g = 0.0, const string& p = "",int year=0, const string& rel=""); //������
	~BestFriend(); //�Ҹ���
	BestFriend(const BestFriend& bf); //���������
	
	void setfromYear(int); //set �Լ�
	int getfromYear() const; //get �Լ�
	void setrelationship(const string&);
	string getrelationship()const;
	static int getBestFriendCount(); //Ŭ���� ���� �׼��� �Լ�
	
	const BestFriend& operator=(const BestFriend& bf); //���� ������ �����ε�
	friend ostream& operator<<(ostream& out, const BestFriend& bf); //��� ������ �����ε�
	friend istream& operator>>(istream& in, BestFriend& bf); //�Է� ������ �����ε�
};
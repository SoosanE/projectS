//���� #7, 12221487, ������
//Friend.h
#pragma once
#include <string>
using namespace std;

//Friend class definition
class Friend {
private: //member variable
	string name;
	int age;
	float gpa;
	string pnumber;

	char* bar; //���� ���� �׷����� ���� ������ ����
	static int count; //��ü�� ���� ����

public: //member function
	Friend(const string& n = "", int a = 0, float g = 0.0, const string& p = ""); //constructor
	Friend(const Friend& c);//���� ������
	void setName(const string&); //function that sets the student's name
	string getName()const;//function that gets the student's name
	void setAge(int);
	int getAge() const;
	void setAgeGraph(int);
	void setGPA(float);
	float getGPA()const;
	void setPnumber(const string&);
	string getPnumber()const;
	const Friend& operator=(const Friend& a); //���������� �����ε�
	friend ostream& operator<<(ostream& out, const Friend& a); //��� ������ �����ε�
	friend istream& operator>>(istream& in, Friend& a); //�Է� ������ �����ε�
	~Friend(); //�Ҹ���
	static int getCount(); //��ü ���� ī��Ʈ
};

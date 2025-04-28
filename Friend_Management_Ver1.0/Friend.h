//과제 #7, 12221487, 엄수산
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

	char* bar; //나이 막대 그래프를 위한 포인터 변수
	static int count; //객체의 개수 세기

public: //member function
	Friend(const string& n = "", int a = 0, float g = 0.0, const string& p = ""); //constructor
	Friend(const Friend& c);//복사 생성자
	void setName(const string&); //function that sets the student's name
	string getName()const;//function that gets the student's name
	void setAge(int);
	int getAge() const;
	void setAgeGraph(int);
	void setGPA(float);
	float getGPA()const;
	void setPnumber(const string&);
	string getPnumber()const;
	const Friend& operator=(const Friend& a); //배정연산자 오버로딩
	friend ostream& operator<<(ostream& out, const Friend& a); //출력 연산자 오버로딩
	friend istream& operator>>(istream& in, Friend& a); //입력 연산자 오버로딩
	~Friend(); //소멸자
	static int getCount(); //객체 개수 카운트
};

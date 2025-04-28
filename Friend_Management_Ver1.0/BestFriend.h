#pragma once
//과제 #7, 12221487, 엄수산
//BestFriend.h
#include <iostream>
#include<string>
using namespace std;
#include "Friend.h" //Friend 클래스로부터 상속
class BestFriend : public Friend //기존의 Friend 클래스로부터 public 상속
{
private:
	int fromYear; //몇 년도부터
	string relationship; //베프 관계
	static int bestFriendCount; //베프가 몇 명인지 저장하는 클래스 변수 
public:
	BestFriend(const string& n = "", int a = 0, float g = 0.0, const string& p = "",int year=0, const string& rel=""); //생성자
	~BestFriend(); //소멸자
	BestFriend(const BestFriend& bf); //복사생성자
	
	void setfromYear(int); //set 함수
	int getfromYear() const; //get 함수
	void setrelationship(const string&);
	string getrelationship()const;
	static int getBestFriendCount(); //클래스 변수 액세스 함수
	
	const BestFriend& operator=(const BestFriend& bf); //배정 연산자 오버로딩
	friend ostream& operator<<(ostream& out, const BestFriend& bf); //출력 연산자 오버로딩
	friend istream& operator>>(istream& in, BestFriend& bf); //입력 연산자 오버로딩
};
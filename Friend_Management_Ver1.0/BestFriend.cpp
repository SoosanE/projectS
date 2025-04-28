//과제 #7, 12221487, 엄수산
//BestFriend.cpp
#include <iostream>
#include<string>
using namespace std;
#include "BestFriend.h"
//생성자
BestFriend::BestFriend(const string& n, int a, float g, const string& p, int year, const string& rel) : Friend(n, a, g, p), relationship(rel) //부모 클래스의 생성자 호출
{ //string 객체를 has-a하는 관계(2번 반복 방지)
	setfromYear(year);
	//setrelationship(rel);
	bestFriendCount++; //객체개수 +1
}
BestFriend::~BestFriend() { //소멸자
	bestFriendCount--; //객체 -1
}
BestFriend::BestFriend(const BestFriend& bf) //복사생성자
{//상속받은 set 과 get 함수 이용하기
    getAge();
    getName();
    getGPA();
    getPnumber();
    fromYear = bf.fromYear;
    relationship = bf.relationship;
	bestFriendCount++;
}

void BestFriend::setfromYear(int year) { //set함수 구현
	fromYear = year;
}
int BestFriend::getfromYear() const { //get 함수 구현
	return fromYear;
}
void BestFriend::setrelationship(const string& rel) {
	relationship = rel;
}
string BestFriend::getrelationship() const{
	return relationship;
}

int BestFriend::bestFriendCount = 0;
int BestFriend::getBestFriendCount() { //객체 개수 count
	return bestFriendCount;
}

const BestFriend& BestFriend::operator=(const BestFriend& bf) { //배정연산자
    if (this != &bf) {
        Friend::operator=(bf); //Friend 클래스 배정 연산자 호출
        fromYear = bf.fromYear; //BestFriend 클래스의 멤버 복사
        relationship = bf.relationship;
    }
    return *this;
}

ostream& operator<<(ostream& out, const BestFriend& bf) {//출력 연산자 오버로딩 구현
    //Friend 클래스로부터 상속받은 멤버들 출력   
    out << "Name: " << bf.getName() << endl;
    out << "Age: " << bf.getAge() << endl;
    out << "GPA: " << bf.getGPA() << endl;
    out << "Phone Number: " << bf.getPnumber() << endl;
    for (int i = 0; i < bf.getAge(); i++) { //나이에 따른 막대 그래프 출력
        out << '*';
    }
    out << endl;
    out <<"From " << bf.fromYear << endl; //BestFriend 클래스의 멤버 출력
    out << "In relation "<<bf.relationship << endl;
    return out;
}

istream& operator>>(istream& in, BestFriend& bf) { //입력 연산자 오버로딩 구현
    //Friend 클래스로부터 상속받은 멤버들 입력
    string name, pnumber;
    int age;
    float gpa;
    in >> name >> age >> gpa >> pnumber;
    bf.setName(name);
    bf.setAge(age);
    bf.setGPA(gpa);
    bf.setPnumber(pnumber);
    in >> bf.fromYear >> bf.relationship; //BestFriend 클래스의 멤버들 입력
    return in;
}//상속받은 set,get함수를 이용해서 연산자 오버로딩 구현에 활용

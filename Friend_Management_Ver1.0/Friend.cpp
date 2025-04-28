//과제 #7, 12221487, 엄수산
//Friend.cpp
#include <iostream>
#include<string>
using namespace std;
#include "Friend.h" //헤더파일과 연동, can access the class name "Friend"

int Friend::count = 0;
int Friend::getCount() { //count 반환
	return count;
}

Friend::Friend(const string& n, int a, float g, const string& p):name(n),pnumber(p) { //생성자, string 객체를 has-a하는 관계
	//setName(n); //유효성검사
	setAge(a);
	setGPA(g);
	//setPnumber(p);
	setAgeGraph(a);
	count++;
}
Friend::~Friend() { //소멸자
	delete[] bar; //메모리 반환
	count--;
}
Friend::Friend(const Friend& c) { //복사 생성자 //age만큼의 공간을 잡고 deep copy
	name = c.name;
	age = c.age;
	gpa = c.gpa;
	pnumber = c.pnumber;
	bar = new char[age + 1];
	for (int i = 0; i <= age; i++) { //deep copy
		bar[i] = c.bar[i];
	}
	count++;
}
void Friend::setName(const string& n) { //modifies private data
	name = (n.length() >= 1 && n.length() <= 10) ? n : "xxx"; //유효성 검사
}
string Friend::getName() const{ //access private data
	return name;
}
void Friend::setAge(int a) { //age유효성검사 
	if (a >= 3 && a <= 40) { //age 유효성 검사를 통과하면
		age = a;
		setAgeGraph(a); //나이에 따른 막대그래프 
	}
	else {
		//cout << "유효한 나이 범위는 20살에서 30살입니다\n";
	}
}
void Friend::setAgeGraph(int a) { //for loop를 돌려 나이만큼 *출력 
	age = a;
	bar = new char[age + 1];
	for (int i = 0; i < age; i++) {
		bar[i] = '*';
	}
	bar[age] = '\0';
}
int Friend::getAge() const {
	return age;
}

void Friend::setGPA(float g) {
	gpa = (g >= 0.0 && g <= 4.5) ? g : 0; //유효성 검사
}
float Friend::getGPA() const{
	return gpa;
}
void Friend::setPnumber(const string& p) {
	pnumber = (p.length() >= 1 && p.length() <= 11) ? p : "010_0000_0000"; //유효성 검사
}
string Friend::getPnumber() const{
	return pnumber;
}
const Friend& Friend::operator=(const Friend& a) { //배정 연산자
	if (this != &a) { //중복 방지
		delete[] bar;
		age = a.age; //멤버 변수 복사
		name = a.name;
		gpa = a.gpa;
		pnumber = a.pnumber;
		bar = new char[age + 1]; //메모리 할당 및 내용물 복사
		for (int i = 0; i <= age; i++)
			bar[i] = a.bar[i];
	}
	return *this;
}
ostream& operator<<(ostream& out, const Friend& copied) { //출력 연산자 오버로딩
	out << copied.name << " "; //Friend 클래스 멤버 변수 출력
	out << copied.age << " ";
	out << copied.gpa << " ";
	out << copied.pnumber << endl;
	for (int i = 0; i < copied.age; i++) { //나이에 따른 막대 그래프 출력
		out << copied.bar[i];
	}
	out << endl;
	return out;
}
istream& operator>>(istream& in, Friend& copied) { //입력 연산자 오버로딩
	string n; //멤벼 변수 입력
	int ag;
	float g;
	string p;
	in >> n >> ag >> g >> p;
	copied.setName(n);
	copied.setAge(ag);
	copied.setGPA(g);
	copied.setPnumber(p);
	return in;
}